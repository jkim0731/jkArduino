#include<Servo.h>
#include <Math.h>
Servo servocontrol;
const int inputpin = 13;
int i;
int pulse;                           // Initilize an int to store the value of one pulse(HIGH == 1; LOW == 0)
int state = 0;
int bitnum = 8;
int bitcode[8];                      // Initialize an int array to store the values of 8 pulses

int pulsetime = 41;                  // Initialize the pulse duration, it tells arduino how long to wait
// until the next pulse come
int Msteps = 0;                      // Initialize an int to offer the micro stepper options about what
// degree to go
int jitterSteps;
int Mdif = 8;
//int MdelayT = 3500;

void setup() {
  // put your setup code here, to run once:
  pinMode (inputpin, INPUT);
  servocontrol.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  pulse = digitalRead(inputpin);
  if (pulse == HIGH)
  {
    state = 1;
  }
  else
  {
    state = 0;
  }


  if (state == 1)
  {

    delay(pulsetime);
    for (i = 0; i < bitnum; i = i + 1)
    {
      pulse = digitalRead(inputpin);
      if (pulse == HIGH)
      {
        bitcode[i] = 1;

      }
      else
      {
        bitcode[i] = 0;

      }
      delay(pulsetime);
      //      Serial.print(bitcode[i], BIN);
    }
    //    Serial.println('\n');


    Msteps = 0;                                  // Transfer the 8 bit code to a integer
    for (i = 0; i < bitnum; i = i + 1)
    {
      Msteps = bitcode[i] * (pow(2, i) + 0.1) + Msteps;
      //      Serial.print(Msteps);
      //      Serial.println('\n');
    }
    //    Serial.print(Msteps);


    //    jitterSteps = random(0, 180);
    //    Serial.println(jitterSteps);
    //    servocontrol.write(jitterSteps + Mdif);
    //    delay(100);
    servocontrol.write(Msteps + Mdif);
    delay(3500);
    servocontrol.write(90 + Mdif);

  }
  else
  {
    return;
  }




}
