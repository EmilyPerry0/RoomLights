#include <Servo.h>
const int SERVO_PIN = 11;

const int SWITCH_ON_ANGLE = 280;
const int SWITCH_OFF_ANGLE = 80;

Servo testServo;

void setup() {
  testServo.attach(SERVO_PIN);
}

void loop() {
  // testServo.write(SWITCH_ON_ANGLE);
  // delay(3000);
  // testServo.write(180);
  // delay(5000);
  // testServo.write(SWITCH_OFF_ANGLE);
  // delay(3000);
  // testServo.write(180);
  // delay(5000);
  testServo.write(0);
  delay(1000);
  for(int i = 0; i <270; i++){
    testServo.write(i);
    delay(7);
  }
}
