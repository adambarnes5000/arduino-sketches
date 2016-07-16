int potPin = 4;

void setup() {
  
  Serial.begin (9600);
}

void loop() {
 int val = analogRead(potPin); 
 Serial.print (val);
 Serial.print ('/');
  delay(1000);
}
