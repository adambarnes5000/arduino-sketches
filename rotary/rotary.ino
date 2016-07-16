 int val; 
 int encoder0PinA = 3;
 int encoder0PinB = 4;
 int encoder0Pos = 0;
 int encoder0PinALast = LOW;
 int n = LOW;
 int redPin = 10;
 int greenPin = 9;
 int bluePin = 11;
 int potPin = 4;
  
 void setup() { 
   pinMode (encoder0PinA,INPUT);
   pinMode (encoder0PinB,INPUT);
   pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
   Serial.begin (9600);
   setColorByNo(0);
   
 } 

 void loop() { 
   n = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
     } else {
       encoder0Pos++;
     }
     setColorByNo(abs(encoder0Pos % 7));
     Serial.print ("/");
   } 
   encoder0PinALast = n;
 } 

void setColorByNo(int c){
  Serial.print (c);
  Serial.print ("/");
  if (c==0){
    setColor(255, 255, 255); 
  }
  if (c==1){
    setColor(255, 0, 0); 
  }
  if (c==2){
    setColor(0, 255, 0); 
  }
  if (c==3){
    setColor(0, 0, 255); 
  }
  if (c==4){
    setColor(255, 255, 0); 
  }
  if (c==5){
    setColor(255, 0, 255); 
  }
  if (c==6){
    setColor(0, 255, 255); 
  }
}

 void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
