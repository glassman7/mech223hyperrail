const GATEDIST = 400;
const GATEDISTERROR = 10;

const DELAYTIME = 5000;

int sensorOne = 1;
int senstivity = 300;

bool inMotion = false;

void setup() {
  // put your setup code here, to run once:
  delay(DELAYTIME);
  pinMode(sensorOne, INPUT);
}

void loop() {

  // put your main code here, to run repeatedly:
  sensorOneSignal = analogRead(sensorOne);

  // if sensor is outside the range, begin moving
  if (!(sensitivityCheck(sensorOneSignal, senstivity) || inMotion)) {
    moveTrain();
  }
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
  )
}


// Moves the move
// TODO: Complete the implementation
void moveTrain() {
  // STUB
  return;
}
