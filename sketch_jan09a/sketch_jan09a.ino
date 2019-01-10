const int GATEDIST = 400;
const int GATEDISTERROR = 40;

const int testPin = 8;
const int trigPin = 9;
const int echoPin = 10;


const int DELAYTIME = 5000;

int   sensorOne = 1;
int   senstivity = 300;
int   sensorOneSignal;

long  duration;
int   distance;

bool  inMotion = false;

void setup() {
  // put your setup code here, to run once:

  // sleeps the program to give us time to place train on track
  // if sensor is outside the range, and it isnt already in motion begin moving to position train on the track
  delay(DELAYTIME);
  pinMode(sensorOne, INPUT);

  // Ultrasonic initialization
  pinMode(trigPin, INPUT);
  pinMode(echoPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  // PRE-MOTION PHASE CHECK
  // reads sensor input at least once from program runtime
  // if train is in the range, set inMotion to true (train is now going to move)
  // and break from the checking phase
  do {
    sensorOneSignal = computeDistance();
    if (!sensitivityCheck(sensorOneSignal, senstivity)) {
      inMotion = true;
    }
  } while (!inMotion);


  // IN MOTION PHASE
  moveTrain();
}


int computeDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  return ((pulseIn(echoPin, HIGH))*0.034/2);
}



// ASSUME:  signal has sensitivity, and distance between gate and train has
//          ERROR, signal is within range if the two range bands overlaps

// FUNCTION: Returns true if signal is within the GATEDIST range taking in account of
// sensitivity, false otherwise.

// signal: analog input from sensorOne
// sens: sensitivity of the signal

// CASE 1: signal lowerbound overlaps GATEDIST band
// CASE 2: signal upperbound overlaps GATEDIST band
bool sensitivityCheck(int signal, int sens) {
  return (
    ((signal - sens) <= (GATEDIST + GATEDISTERROR)) ||   // CASE 1
    ((signal + sens) >= (GATEDIST - GATEDISTERROR))      // CASE 2
  );
}


// Moves the move
// TODO: Complete the implementation
void moveTrain() {
  digitalWrite(testPin, HIGH);
}
