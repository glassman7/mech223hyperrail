const int trigPin = 9;
const int echoPin = 10;

const int greenPin = 6;
const int bluePin = 7;
const int redPin = 8;

long duration;
int distance;

bool notStarted = true;


void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  Serial.begin(9600);

  digitalWrite(bluePin, HIGH);
  normalize();
}

void loop() {
  // put your main code here, to run repeatedly:

  // Pulse is 2 microseconds apart with width 10 micrseconds
 
    if (notStarted) {
      if (testFunction() < 10) {
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, HIGH);10
      } else {
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin, HIGH);
      notStarted = false;
      }
    } else {
      digitalWrite(greenPin, HIGH);
      delay(1000);
      digitalWrite(greenPin, LOW);
      delay(1000);    
    }
  
}

int testFunction() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;

  Serial.println(distance);

  return distance;
}

void normalize() {
  while(testFunction() < 6 && testFunction() > 4) {}  
}
