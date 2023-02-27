#define PIN0 11
#define PIN1 10

void setup() {
  Serial.begin(9600);
  pinMode(PIN0, OUTPUT);
  pinMode(PIN1, OUTPUT);
}

void switch_motor(bool vector = 0, int speed = 255){
  if (vector){
    analogWrite(PIN0, speed);
  }
  else if (!vector){
    analogWrite(PIN1, speed);
  }
}
void loop() {
  switch_motor(1, 255);
  digitalWrite(11, LOW); 
  delay(1000);
  digitalWrite(11, HIGH); 
  switch_motor(0, 200);
  delay(1000);
}
