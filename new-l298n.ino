int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;
#define SRigthEcho A0
#define SRigthTrig A1
#define SforEcho A2
#define SforTrig A3
#define SLeftEcho A4
#define SLeftTrig A5

void setup() {
  // put your setup code here, to run once:
	pinMode(SRigthTrig, OUTPUT);
  pinMode(SforTrig, OUTPUT);
  pinMode(SLeftTrig, OUTPUT);
  //Set the Echo pins as input pins
  pinMode(SRigthEcho, INPUT);
  pinMode(SforEcho, INPUT);
  pinMode(SLeftEcho, INPUT);
  //set motor A pins RIGHT motor
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //set motor B pins LEFT motor
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);


}

void loop() {

int frontSensor = sensorFront();
if(frontSensor > 30){//constant
  int leftSensor = sensorLeft();
int rightSensor = sensorRight();
if(leftSensor>rightSensor){//left, right
  softLeft();
  }
  else if(rightSensor>leftSensor){
    softRight();
  }
  else{
    forward();
    
  }
 
}
 else{
  Stop();
     /*
     Stop();
     int leftSensor = sensorLeft();
     int rightSensor = sensorRight();
          Serial.print("left:");

     Serial.println(leftSensor);
     Serial.print("right:");
     Serial.println(rightSensor);
     if(leftSensor>rightSensor){//left, right
        left();
        delay(1000);
      }
      else{
        right();
        delay(1000);

        }*/
  }
}
void softRight() {
digitalWrite(enA, 30);
digitalWrite(enB, 20);

  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
void softLeft() {
digitalWrite(enA, 20);
digitalWrite(enB, 30);

  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
void hardRight() {
digitalWrite(enA, 0);
digitalWrite(enB, 200);

  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
void Stop() {
digitalWrite(enA, 0);
digitalWrite(enB, 0);

  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
}

void forward(){
digitalWrite(enA, 10);
digitalWrite(enB, 10);

  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
void backward(){
digitalWrite(enA, 200);
digitalWrite(enB, 200);

  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
	digitalWrite(in3, LOW);
	digitalWrite(in4, HIGH);
}

int sensorLeft() {
  //pulse output
  digitalWrite(SLeftTrig, LOW);
  delayMicroseconds(4);
  digitalWrite(SLeftTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(SLeftTrig, LOW);

  long t = pulseIn(SLeftEcho, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}
int sensorFront(){
   //pulse output
  digitalWrite(SforTrig, LOW);
  delayMicroseconds(4);
  digitalWrite(SforTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(SforTrig, LOW);

  long t = pulseIn(SforEcho, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}
int sensorRight(){
   //pulse output
  digitalWrite(SRigthTrig, LOW);
  delayMicroseconds(4);
  digitalWrite(SRigthTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(SRigthTrig, LOW);

  long t = pulseIn(SRigthEcho, HIGH);//Get the pulse
  int cm = t / 29 / 2; //Convert time to the distance
  return cm; // Return the values from the sensor
}