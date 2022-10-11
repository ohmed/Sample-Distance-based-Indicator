
//define variables
#define trigerPin 12
#define echoPin 13
#define ledPin 2
#define speakerPin 10
#define pitch 262

double duration, distance;

void setup() {
  //setup for Sensor
  Serial.begin(9600);
  pinMode(trigerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //setup for LED
  pinMode(ledPin, OUTPUT);

  //setup for Speaker
  pinMode(speakerPin, OUTPUT);

}

void loop() {
  //looping sensor (Create sound wave)
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPin, LOW);
  delayMicroseconds(2);

  //get duration
  duration = pulseIn(echoPin,HIGH);

  //calculate distance
  distance = (duration/2) * 0.0343;

  //consider maximum width of the door = 200 cm
  if(distance<200){
    digitalWrite(ledPin, HIGH);
    tone(speakerPin, pitch);
    delay(300);

    digitalWrite(ledPin, LOW);
    noTone(speakerPin);
    delay(300);
  }else{
    digitalWrite(ledPin, LOW);
    noTone(speakerPin);
  }
}
