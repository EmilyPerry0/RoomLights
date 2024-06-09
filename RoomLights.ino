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
bool lightsOn;
//this is so the ultrasonic sensor only samples every 500 ms
int loopCount;

const int BUTTON_PIN = 5;
int buttonState = 0;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lightsOn = false;
  loopCount = 0;

  // set the maximum speed, acceleration factor, initial speed
	lightSwitchStepper.setMaxSpeed(1000.0);
	lightSwitchStepper.setAcceleration(50.0);
	lightSwitchStepper.setSpeed(200);

  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  if(loopCount == 10){
    if(getDistanceCM() < DOOR_WIDTH_CM && !(lightsOn)){
      turnLightsOn();
    }
    loopCount = 0;
  }else{
    loopCount++;
  }
  

  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON_PIN);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH
  // so turn off the lights
  if (buttonState == HIGH && lightsOn) {
    turnLightsOff();
  }
  delay(50);
}

int getDistanceCM(){
  int distance_cm = 0;
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
  delay(5000);
}

void gotoPos(int targetPos){
  lightSwitchStepper.moveTo(targetPos);

  while(lightSwitchStepper.distanceToGo() != 0){
    // Move the motor one step
	  lightSwitchStepper.run();
  }
}