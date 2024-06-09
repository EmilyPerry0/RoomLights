#include <Servo.h>

// Define pins for the ultrasonic sensor
const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int SERVO_PIN = 11;

const int DOOR_WIDTH_CM = 75;
long sound_travel_duration;
int distance_cm;
Servo lightSwitchServo;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lightSwitchServo.attach(SERVO_PIN);
}

void loop() {
  // if(getDistanceCM() < DOOR_WIDTH_CM){
  //   //check to see if lights are on or off
  //   //turn lights on if they're off
  // }
  turnLightsOn();
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
  
}
