void setup() {
  // put your setup code here, to run once:
 // put your setup code here, to run once:
Serial.begin(115200); // Opens serial port 0, sets data rate to 115,200 bps
Serial1.begin(250000); // Opens serial port 0, sets data rate to 250,000 bps
float festoPin = 5;
float laserAOM = 7;
int oddLoop = 1;
pinMode(festoPin, INPUT);
pinMode(laserAOM, OUTPUT);
}
}

void loop() {
  // put your main code here, to run repeatedly:
float Angle;
float theta1;
float theta2;
float Direction;
char buf[5];
int oddLoop
if (Serial1.available()>4) 
 // If serial buffer has 5 or more bytes then read 5 bytes
 {      
 Serial1.readBytes(buf, 5);
 if(buf[0]>0)
  // If whisker found, compute whisker angle
  {
  // Convert receive data to fixed point signed number (16 bit word length and 8 bit integer length)
  Angle = (float)buf[1] + (float)((unsigned char)buf[2])/255;
  Serial.println(Angle);
  }
 }
// Put conditionals here for AOM, angle cutoff at whatever you want it to be
if (oddLoop == 1) {
  oddLoop = 0;
  theta1 = Angle;
  else 
  theta2 = Angle;
}
if (oddLoop == 1) {
  
if (Angle > 180 && digitalRead(festoPin) == HIGH) { 
 digitalWrite(laserAOM, HIGH);
}
}
