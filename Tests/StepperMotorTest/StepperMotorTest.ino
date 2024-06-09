// Include the AccelStepper Library
#include <AccelStepper.h>

// Define step constant
#define MotorInterfaceType 4

const int NEUTRAL_POS = 0;
const int ON_POS = 75;
const int OFF_POS = -175;

// Creates an instance
// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
AccelStepper myStepper(MotorInterfaceType, 8, 10, 9, 11);

void setup() {
	// set the maximum speed, acceleration factor, initial speed
	myStepper.setMaxSpeed(1000.0);
	myStepper.setAcceleration(50.0);
	myStepper.setSpeed(200);
}

void loop() {
  delay(5000);
  gotoPos(ON_POS);
  gotoPos(NEUTRAL_POS);
  delay(1000);
  gotoPos(OFF_POS);
  gotoPos(NEUTRAL_POS);
  delay(5000);
}

void gotoPos(int targetPos){
  myStepper.moveTo(targetPos);

  while(myStepper.distanceToGo() != 0){
    // Move the motor one step
	  myStepper.run();
  }
}