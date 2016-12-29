/* Test code for RT Whisker Tracker Arduino stuff */
  int fakeSerial = 4;
  int festoPin = 2;
  int laserAOM = 7;
void setup() { 
  //Pin settings
  pinMode(fakeSerial, INPUT);
  pinMode(festoPin, INPUT);
  pinMode(laserAOM, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  if (digitalRead(fakeSerial) == HIGH && digitalRead(festoPin) == HIGH){
    digitalWrite(laserAOM, HIGH);
  } else {
    digitalWrite(laserAOM, LOW);
  }
  //Next part is purely an output test
  digitalWrite(13, HIGH); 
}
  
  
