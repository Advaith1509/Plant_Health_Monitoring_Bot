//installing the Adafruit library
#include <AFMotor.h>

//defining pins and variables
#define left A5
#define right A0

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}


void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));
  
  Serial.println(digitalRead(right));

  //line detected by both
  if(digitalRead(left)==1 && digitalRead(right)==1){
    //Forward
    motor1.run(FORWARD);
    motor1.setSpeed(75);
    motor2.run(FORWARD);
    motor2.setSpeed(75);
    motor3.run(FORWARD);
    motor3.setSpeed(75);
    motor4.run(FORWARD);
    motor4.setSpeed(75);
  }


  //line detected by left sensor
  else if(digitalRead(left)==1 && !digitalRead(right)==1){
    //turn left
    motor1.run(FORWARD);
    motor1.setSpeed(70);
    motor2.run(FORWARD);
    motor2.setSpeed(70);
   /* motor3.run(BACKWARD);
    motor3.setSpeed(150);
    motor4.run(BACKWARD);
    motor4.setSpeed(150);*/
    motor3.run(FORWARD);
    motor3.setSpeed(70);
    motor4.run(FORWARD);
    motor4.setSpeed(70);
   
    
  }


  //line detected by right sensor
  else if(!digitalRead(left)==1 && digitalRead(right)==1){
    //turn right
    motor1.run(FORWARD);
    motor1.setSpeed(70);
    motor2.run(FORWARD);
    motor2.setSpeed(70);
   /* motor1.run(BACKWARD);
    motor1.setSpeed(100);
    motor2.run(BACKWARD);
    motor2.setSpeed(100);*/
    motor3.run(FORWARD);
    motor3.setSpeed(70);
    motor4.run(FORWARD);
    motor4.setSpeed(70);
   
  }


  //line detected by none
  else if(!digitalRead(left)==1 && !digitalRead(right)==1){
    //stop
   /*motor1.run(RELEASE);
    motor1.setSpeed(0);
    motor2.run(RELEASE);
    motor2.setSpeed(0);
    motor3.run(RELEASE);
    motor3.setSpeed(0);
    motor4.run(RELEASE);
    motor4.setSpeed(0);*/

    delay(10000);
   
  }
  
} 
