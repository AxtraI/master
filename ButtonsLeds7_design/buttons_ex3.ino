#define btn_pin 12
#define AA 4
#define BB 5
#define CC 6
#define DD 7
#define EE 8
#define FF 9
#define GG 10
#define Dot 11

void turnoff()
{
  digitalWrite(AA, LOW);
  digitalWrite(BB, LOW);
  digitalWrite(CC, LOW);
  digitalWrite(DD, LOW);
  digitalWrite(EE, LOW);
  digitalWrite(FF, LOW);
  digitalWrite(GG, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(btn_pin, INPUT);
  pinMode(AA, OUTPUT);
  pinMode(BB, OUTPUT);
  pinMode(CC, OUTPUT);
  pinMode(DD, OUTPUT);
  pinMode(EE, OUTPUT);
  pinMode(FF, OUTPUT);
  pinMode(GG, OUTPUT);
  pinMode(Dot, OUTPUT);
}

bool val1 = 1;
bool val2 = 1;

int count = 0;
int time = 0;

void loop() {
  val1 = val2;
  val2 = digitalRead(btn_pin);
  delay(100);
  if (val2 == 0 && val1 == 1)
  {
    count++;
  }
  if (val2 == 1 && val1 == 1)
  {
    time++;
    Serial.println(time / 3);
    delay(1000);
  }

  if (val2 == 0 && val1 == 0)
  {
    if (time / 3 == 0)
    {
      turnoff();
      digitalWrite(AA, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, HIGH);
      digitalWrite(EE, HIGH);
      digitalWrite(FF, HIGH);
    }
    else if (time / 3 == 1)
    {
      turnoff();
      digitalWrite(BB, HIGH);
      digitalWrite(CC, HIGH);
    }
    else if (time / 3 == 2)
    {
      turnoff();
      digitalWrite(AA, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(GG, HIGH);
      digitalWrite(EE, HIGH);
      digitalWrite(DD, HIGH);
    }
    else if (time / 3 == 3)
    {
      turnoff();
      digitalWrite(AA, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(GG, HIGH);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, HIGH);
    }
    else if (time / 3 == 4)
    {
      turnoff();
      digitalWrite(FF, HIGH);
      digitalWrite(GG, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, HIGH);
    }
    else if (time / 3 == 5)
    {
      turnoff();
      digitalWrite(AA, HIGH);
      digitalWrite(FF, HIGH);
      digitalWrite(GG, HIGH);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, HIGH);
    }
    else if (time / 3 == 6)
    {
      turnoff();
      digitalWrite(AA, HIGH);
      digitalWrite(FF, HIGH);
      digitalWrite(EE, HIGH);
      digitalWrite(DD, HIGH);
      digitalWrite(CC, HIGH);
      digitalWrite(GG, HIGH);
    }
    else if (time / 3 == 7)
    {
      turnoff();
      digitalWrite(AA, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, HIGH);
    }
    else if (time / 3 == 8)
    {
      turnoff();
      digitalWrite(AA, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, HIGH);
      digitalWrite(EE, HIGH);
      digitalWrite(FF, HIGH);
      digitalWrite(GG, HIGH);
    }
    else if (time / 3 == 9)
    {
      turnoff();
      digitalWrite(AA, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, HIGH);
      digitalWrite(GG, HIGH);
      digitalWrite(FF, HIGH);
    }
    else
    {
      turnoff();
      digitalWrite(AA, HIGH);
      digitalWrite(BB, HIGH);
      digitalWrite(CC, HIGH);
      digitalWrite(DD, HIGH);
      digitalWrite(EE, HIGH);
      digitalWrite(GG, HIGH);
      digitalWrite(FF, HIGH);
    }
  }
}
