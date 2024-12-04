#include <Wire.h>
#include <AFMotor.h>
#define SRigthEcho A0
#define SRigthTrig A1
#define SforEcho A2
#define SforTrig A3
#define SLeftEcho A4
#define SLeftTrig A5


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {
	// Set all the motor control pins to outputs

	pinMode(SRigthTrig, OUTPUT);
  pinMode(SforTrig, OUTPUT);
  pinMode(SLeftTrig, OUTPUT);
  //Set the Echo pins as input pins
  pinMode(SRigthEcho, INPUT);
  pinMode(SforEcho, INPUT);
  pinMode(SLeftEcho, INPUT);
 
	// Turn off motors - Initial state
  Serial.begin(9600);
  motor1.setSpeed(0);
motor1.setSpeed(0); 
motor1.run(RELEASE);
motor2.run(RELEASE);
delay(1000);
}

void loop() {

int frontSensor = sensorFront();
if(frontSensor > 30){//constant
  int leftSensor = sensorLeft();
int rightSensor = sensorRight();
if(leftSensor>rightSensor){//left, right
  left();
  }
  else if(rightSensor>leftSensor){
    softright();
  }
  else{
    forward();
    
  }
 
}
 else{
  hardright();
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
// This function lets you control spinning direction of motors
void softright() {
motor1.setSpeed(0);
motor2.setSpeed(200); 
motor1.run(RELEASE);
motor2.run(FORWARD);
}
void hardright() {
motor1.setSpeed(255);
motor2.setSpeed(255); 
motor1.run(BACKWARD);
motor2.run(FORWARD);
}
void Stop() {
motor1.setSpeed(0);
motor2.setSpeed(0); 
motor1.run(RELEASE);
motor2.run(RELEASE);
}
void left() {
motor1.setSpeed(200);
motor2.setSpeed(0); 
motor1.run(FORWARD);
motor2.run(RELEASE);
}
void forward(){
motor1.setSpeed(200);
motor2.setSpeed(200); 
motor1.run(FORWARD);
motor2.run(FORWARD);
}
void backward(){
motor1.setSpeed(150);
motor2.setSpeed(150); 
motor1.run(BACKWARD);
motor2.run(BACKWARD);
}