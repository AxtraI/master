//1st ino file
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
  void setup() {
  Serial.begin(9600);
  while (!Serial) { }
  Serial.println("Goodnight PC!");
  mySerial.begin(9600);
  mySerial.println("Hello, dude?");
}
void loop() {
  if (mySerial.available())
   Serial.write(mySerial.read());
  if (Serial.available())
   mySerial.write(Serial.read());
}

//2nd ino file

#include <SoftwareSerial.h>

byte numbers[] = {
  0b11101110,  //0
  0b10100000,  //1
  0b11001101,  //2
  0b11101001,  //3
  0b10100011,  //4
  0b01101011,  //5
  0b01101111,  //6
  0b11100000,  //7
  0b11101111,  //8
  0b11101011,  //9
  0b11100111,  //A
  0b00101111,  //B
  0b01001110,  //C
  0b10101101,  //D
  0b01001111,  //E
  0b01000111   //F 
};

SoftwareSerial mySerial(2, 3);

void dataDisplay(int num){
  
  for (int i = 0; i < 8; i++){
    digitalWrite(13 - i, (num >> i) & 1);
    
  }
}

void setup() {
  
  Serial.begin(9600);
  mySerial.begin(9600);
  for (int i = 6; i <= 13; i++){
    pinMode(i, OUTPUT);
    
  }
}

void loop() {
  
  if (Serial.available() >= 1){
    int position = 0;
    byte data = Serial.read();
    if (data >= '0' && data <= '9'){
      position = data - '0';
    }
    if (data >= 'A' && data <= 'F'){
      position = data - 'A' + 10;
    }
    dataDisplay(numbers[position]);
    delay(50);
    if (Serial.available() >= 1){
      while (Serial.available() >= 1){
        mySerial.write(Serial.read());
      }
    } else{
      mySerial.write(byte(0));
      
    }
  }
}


//3rd ino file

#define CLOCK_PIN 2
#define RESET_PIN 3

String show_number = "";
int position = 0;
long prev = 0;

void resetNumber()
{
  digitalWrite(RESET_PIN, HIGH);
  digitalWrite(RESET_PIN, LOW);
}

void showNumber(int n)
{
  resetNumber();
  for (byte i=0; i < n; i++) {
    digitalWrite(CLOCK_PIN, HIGH);
    digitalWrite(CLOCK_PIN, LOW);
  }
}

void setup(){
  pinMode(RESET_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  resetNumber();
  Serial.begin(9600);
}

void loop(){
  if (Serial.available()){
    show_number = "";
    position = 0;
    while (Serial.available()){
      show_number += char(Serial.read());
      delay(50);
    }
  }
  while (millis() - prev >= 1000){
    prev = millis();
    if (position == 0){
      position++;
      if (show_number.length() > 2){
        resetNumber();
        break;
      }
    }
    int show = (show_number[position - 1] - '0') * 10 + show_number[position] - '0';
    showNumber(show);
    position++;
    position %= show_number.length();
  }
}
