// Initialization of constant parameters pertaining to train and start gate
// distance, subject to change.
const int GATEDIST = 400;
const int GATEDISTERROR = 40;

// Initialization of constant parameters pertaining to duration of the triggers
// of the ultrasonic sensor.
// As of now, triggers are 10 microseconds long and 2 microseconds apart.
const int TRIGDURATION = 10;
const int RESTDURATION = 2;


// Arduino Pins initialization
const int testPin = 8;
const int trigPin = 9;
const int echoPin = 10;


// Time for members to place and position the train from the starting gate
// Subject to change.
const int DELAYTIME = 5000;


// SensorOne (ultrasonic sensor) sensitivity and signal value variables
const int senstivity = 300;
int sensorOneSignal;

// Duration and distance for sensorOne
// Duration is in microseconds, hence a large value is expected.  Long keyword assigned.
long  duration;
int   distance;

// Boolean Variables
bool  completed = false;  // Has the train already completed the round?
bool  inMotion = false;   // Has the gate already opened and the train is moving?

void setup() {
  // sleeps the program to give us time to place train on track
  // if sensor is outside the range, and it isnt already in motion begin moving to position train on the track
  delay(DELAYTIME);

  // Ultrasonic pin declaration
  pinMode(trigPin, INPUT);
  pinMode(echoPin, OUTPUT);

  // Data stream between arduino and computer, limited due to demand from ultrasonic sensor
  Serial.begin(9600);

  // PRE-MOTION PHASE CHECK
  // reads sensor input at least once from program runtime
  // if train is in the range, set inMotion to true (train is now going to move)
  // and break from the checking phase
  // THE PROGRAM WILL NOT CONTINUE TO THE SUPERLOOP UNTIL THE GATE HAS BEEN OPENED
  do {
    sensorOneSignal = computeDistance();
    if (!sensitivityCheck(sensorOneSignal, senstivity)) {
      inMotion = true;
    }
  } while (!inMotion);
}

void loop() {
  // If the round has not been completed yet, execute round code
  if (!completed)
    moveTrain();
}

// FUNCTION:  Returns the computed distance of the obstruction to the ultrasonic
//            sensor in metres as a positive integer
int computeDistance() {
  // Ultrasonic sensor will fire 10 microsecond triggers 2 microseconds apart

  // Trigger is set to low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(RESTDURATION);
  // 2 microsecond delay between triggers
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(TRIGDURATION);
  // Ultrasonic sensor will fire the trigger for 10 microseconds

  // Trigger pin will be terminated so the signal can be properly received
  // in the echo pin
  digitalWrite(trigPin, LOW);

  return ((pulseIn(echoPin, HIGH))*0.034/2);
}



// ASSUME:    Signal has sensitivity, and distance between gate and train has
//            ERROR, signal is within range if the two range bands overlap
// FUNCTION:  Returns true if signal is within the GATEDIST range taking in account of
//            sensitivity, false otherwise.
// PARAMETERS:
//            signal: analog input from sensorOne
//            sens: sensitivity of the signal
//
// CASE 1:    Signal lowerbound overlaps GATEDIST band
// CASE 2:    Signal upperbound overlaps GATEDIST band
bool sensitivityCheck(int signal, int sens) {
  return (
    ((signal - sens) <= (GATEDIST + GATEDISTERROR)) ||   // CASE 1
    ((signal + sens) >= (GATEDIST - GATEDISTERROR))      // CASE 2
  );
}


// Indicates that the gate has been opened and the sensor has detected it
void moveTrain() {
  digitalWrite(testPin, HIGH);
}
