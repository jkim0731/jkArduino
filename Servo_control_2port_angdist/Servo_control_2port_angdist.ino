#include<Servo.h>
#include <Math.h>
Servo servocontrol;
const int servoinput = 13;
const int piezoinput = 12;

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
int MdelayT = 5000;
int sound;

void setup() {
  // put your setup code here, to run once:
  pinMode(servoinput, INPUT);
  pinMode(piezoinput, INPUT);
  servocontrol.attach(10);  
}

void loop() {
  // put your main code here, to run repeatedly:

  sound = digitalRead(piezoinput);
  if (sound == HIGH)
  {
    tone(7,3000);
  }
  else
  {
    noTone(7);
  }
  
  pulse = digitalRead(servoinput);
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
      pulse = digitalRead(servoinput);
      if (pulse == HIGH)
      {
        bitcode[i] = 1;
      }
      else
      {
        bitcode[i] = 0;
      }
      delay(pulsetime);
    }

    Msteps = 0;                                  // Transfer the 8 bit code to a integer
    for (i = 0; i < bitnum; i = i + 1)
    {
      Msteps = bitcode[i] * (pow(2, i) + 0.1) + Msteps;
    }

    jitterSteps = random(45, 135);
    servocontrol.write(jitterSteps + Mdif);
    delay(300);
    servocontrol.write(Msteps + Mdif);
//    delay(MdelayT);
//    servocontrol.write(90 + Mdif);
  }
  else
  {
    return;
  }
}
