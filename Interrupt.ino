const int pirPin = 2;  // Connect the output pin of the PIR sensor to digital pin 2
const int buzzerPin = 9; // Connect the positive (longer) leg of the buzzer to digital pin 9

volatile int pirState = LOW;  // Initialize pirState to LOW

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  // Attach interrupt to the PIR sensor pin
  attachInterrupt(digitalPinToInterrupt(pirPin), motionDetected, CHANGE);
}

void loop() {
  // Your main loop code can be empty or handle other tasks
  Serial.println("WELCOME TO INTERRUPT PROGRAM");
  delay(300);
}

void motionDetected() {
  pirState = digitalRead(pirPin);

  if (pirState == HIGH) {
    Serial.println("Motion detected!");

    // Turn on the buzzer when motion is detected
    digitalWrite(buzzerPin, HIGH);
    delay(20000); // Buzzer on for 500 milliseconds
    digitalWrite(buzzerPin, LOW);
  } else {
    // Turn off the buzzer when no motion is detected
    digitalWrite(buzzerPin, LOW);
  }
}
