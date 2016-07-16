/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

#define BUTTON_PIN        3  // Button
#define DELAY            200  // Delay per loop in ms

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  digitalWrite(BUTTON_PIN, HIGH); // pull-up
}

// the loop function runs over and over again forever
void loop() {
  int button_pressed = !digitalRead(BUTTON_PIN);
  if (button_pressed){
    digitalWrite(13, HIGH);
    Serial.println("ON");
  } else {
    Serial.println("OFF");
    digitalWrite(13, LOW);
  }
  delay(DELAY);     
}
