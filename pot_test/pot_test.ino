int valPin=4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(valPin);
  Serial.println(val);
  delay(1000);
}
