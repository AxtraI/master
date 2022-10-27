#define btn_pin 5
#define led_pin 10

bool led_state = false;
int current, previous;
int power = 255;
bool step = false;

void setup(){
  pinMode(led_pin, OUTPUT);
  pinMode(btn_pin, INPUT);
  Serial.begin(9600);
}

void loop(){
  current = digitalRead(btn_pin);
  if (current != previous){
    current = digitalRead(btn_pin);
    long pressed = millis();
    while (digitalRead(btn_pin)){
      if (millis() - pressed >= 500 && led_state){
        while (digitalRead(btn_pin)){
          if (step){
            power = min(power + 1, 255);
          }
          else{
            power = max(power - 1, 0);
          }
          analogWrite(led_pin, power);
          delay(10);
        }
        step = !step;
      }
      delay(10);
    }
    if (millis() - pressed < 500){
      if (current){
          led_state = !led_state;
      }
      if (led_state){
        analogWrite(led_pin, power);
      }
      else{
        analogWrite(led_pin, 0);
      }
    }
  }
  previous = current;
}
