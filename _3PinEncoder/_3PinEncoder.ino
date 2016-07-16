const int encoderPinA = 4;
const int encoderPinB = 2;

int angle = 0;

int encoderPos = 0;
int encoderStepsPerRevolution = 16;

boolean encoderALast = LOW; //remembers the previous state of the encoder pin A

void setup() {
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  digitalWrite(encoderPinA, HIGH);
  digitalWrite(encoderPinB, HIGH);
  Serial.begin(9600);
}

void loop() {
  boolean encoderA = digitalRead(encoderPinA);

  if ((encoderALast == HIGH) && (encoderA == LOW))
  {
    if (digitalRead(encoderPinB) == LOW)
    {
      encoderPos--;
    }
    else
    {
      encoderPos++;
    }
    angle = (encoderPos % encoderStepsPerRevolution) * 360 / encoderStepsPerRevolution;
    Serial.print(encoderPos);
    Serial.print(" ");
    Serial.println(angle);
  }
  encoderALast = encoderA;
}
