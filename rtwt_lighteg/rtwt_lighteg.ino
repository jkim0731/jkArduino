int festoPin = 5;
int laserAOM = 7;
float Angle;
char buf[5];

int trialtype; // 1 & 2 normal right and left. 3 & 4 protraction right and left. 5 & 6 retraction right and left.
int theta_go; // angle for go position
int theta_nogo; // angle for no-go position
int theta_temp[3]; // temporary array of theta position, including 2 step history angles
int condition_flag = 0; // flag for condition met

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); // Opens serial port 0, sets data rate to 115,200 bps
Serial1.begin(250000); // Opens serial port 1 (19), sets data rate to 250,000 bps
pinMode(festoPin, INPUT);
pinMode(laserAOM, OUTPUT);
}

void loop() 
{
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

