const int BUTTON_PIN = 5;
int buttonState = 0;


void setup(){
  pinMode(BUTTON_PIN, INPUT);
   Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON_PIN);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    Serial.println("Button Pressed!");
  } else {
    Serial.println("Button NOT Pressed :(");
  }
  delay(50);
}