#include<Servo.h>
Servo servotest;
int pos = 45;
int Mdif = -8;

void setup() {
  // put your setup code here, to run once:
  servotest.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:

  servotest.write(45+ Mdif);
  delay(3000000);

  //servotest.write(90 + Mdif);
  delay(3000);
}
