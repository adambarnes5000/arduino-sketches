 
 int encoder0PinA = 3;
 int encoder0PinB = 4;
 int encoder0Pos = 0;
 int encoder0PinALast = LOW;
 int n = LOW;
 int redPin = 10;
 int greenPin = 9;
 int bluePin = 11;
 int potPin = 4;
 int lastVal = 0;
  
 void setup() { 
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
   Serial.begin (9600);
   setColor(0, 0, 0); 
 } 

 void loop() { 
  int val = analogRead(potPin); 
  
   n = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
     } else {
       encoder0Pos++;
     }
     setColorByNo(abs(encoder0Pos % 7),val/4);
     Serial.print ("/");
   } 
   encoder0PinALast = n;
 } 

void setColorByNo(int c, int val){
  Serial.print (c);
  Serial.print ("/");
  Serial.print (val);
  Serial.print ("/");
  if (c==0){
    setColor(0, 0, 0); 
  }
  if (c==1){
    setColor(val, 0, 0); 
  }
  if (c==2){
    setColor(0, val, 0); 
  }
  if (c==3){
    setColor(0, 0, val); 
  }
  if (c==4){
    setColor(val, val, 0); 
  }
  if (c==5){
    setColor(val, 0, val); 
  }
  if (c==6){
    setColor(0, val, val); 
  }
}

 void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
