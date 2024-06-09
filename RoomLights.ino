#include <AccelStepper.h>

// Define pins for the ultrasonic sensor
const int TRIG_PIN = 6;
const int ECHO_PIN = 7;

// Define step motor constant
#define MotorInterfaceType 4

const int NEUTRAL_POS = 0;
const int ON_POS = 75;
const int OFF_POS = -175;

// Pins entered in sequence IN1-IN3-IN2-IN4 for proper step sequence
AccelStepper lightSwitchStepper(MotorInterfaceType, 8, 10, 9, 11);

const int DOOR_WIDTH_CM = 75;

long sound_travel_duration;
int distance_cm;
bool lightsOn;



void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lightsOn = false;

  // set the maximum speed, acceleration factor, initial speed
	lightSwitchStepper.setMaxSpeed(1000.0);
	lightSwitchStepper.setAcceleration(50.0);
	lightSwitchStepper.setSpeed(200);
}

void loop() {
  if(getDistanceCM() < DOOR_WIDTH_CM && !(lightsOn)){
    turnLightsOn();
  }
  delay(500);
}

int getDistanceCM(){
  // Clear the trigPin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Set the TRIG_PIN to HIGH for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the ECHO_PIN, returns the sound wave travel time in microseconds
  sound_travel_duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance in centimeters
  distance_cm = sound_travel_duration * 0.034 / 2;

  return distance_cm;
}

void turnLightsOn(){
  gotoPos(ON_POS);
  gotoPos(NEUTRAL_POS);
  lightsOn = true;
}

void turnLightsOff(){
  gotoPos(OFF_POS);
  gotoPos(NEUTRAL_POS);
  lightsOn = false;
}

void gotoPos(int targetPos){
  lightSwitchStepper.moveTo(targetPos);

  while(lightSwitchStepper.distanceToGo() != 0){
    // Move the motor one step
	  lightSwitchStepper.run();
  }
}