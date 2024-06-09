// Define pins for the ultrasonic sensor
const int trigPin = 6;
const int echoPin = 7;

// Variable to store the duration of the pulse
long duration;

// Variable to store the distance
int distance;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set the trigger pin as an output
  pinMode(trigPin, OUTPUT);

  // Set the echo pin as an input
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Wait for a short period before the next measurement
  delay(1000); // 1 second
}
