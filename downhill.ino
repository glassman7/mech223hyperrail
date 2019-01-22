//Transistor 'Base' pin or input pin of motor driver ic to Arduino PWM Digital Pin 3
const int motor1Pin = 10;
const int motor2Pin = 9;

int Speed; //Variable to store Speed, by defaul 0 PWM
int flag;
boolean finishedHill = false;


void setup()
{
  pinMode(motor1Pin, OUTPUT); //Set pin 3 as an OUTPUT
  pinMode(motor2Pin, OUTPUT); //Set pin 5 as an OUTPUT
    

  Serial.begin(9600); //Init serial communication
    //Print a message:
  //Serial.println("Give a number from 50 to 255."); //Why minimun value 50? Because with values below 50 the motor doesn't spin 😉
  //Serial.println(""); //Blank line
  
}

void loop()
{ 
  if (!finishedHill) {
    delay(1500);      // 1.5 seconds of delay first
    
    setMotors(50);  // Set motors to low power
    delay(5000);    // 5 seconds later, set the motors to high power
    setMotors(250); 

    finishedHill = true;  // Motors will be high power from now on
  }      
}

void setMotors(int power) 
{
    analogWrite(motor1Pin, power);
    analogWrite(motor2Pin, power);
}
