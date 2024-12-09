#include <AFMotor.h>

AF_DCMotor motor(4);
AF_DCMotor motor1(3);
AF_DCMotor motor2(2);
AF_DCMotor motor3(1);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  motor.setSpeed(200);
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor.run(FORWARD);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  delay(200);
  motor.run(RELEASE);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  delay(100);
}
