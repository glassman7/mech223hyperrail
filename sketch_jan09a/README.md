# Arduino Ultrasonic Sensor Implementation Test
Performed on January 10, 2019<br />

Sketch A Code:<Br />
https://github.com/glassman7/mech223hyperrail/blob/master/sketch_jan09a/sketch_jan09a.ino"

## Purpose
To test the functionality of a boolean controlled gate sensing algorithm utilizing the ultrasonic sensor.  The algorithm will be used for the train.

To model the autonomous behavior of the train, the algorithm was designed to keep the train stationary behind a mechanical gate, and will only begin operation when the gate has been opened.  As a focused prototype, the physical model to test this algorithm utilized several LED's to denote states of the train.

* A blue LED constantly in the `HIGH` position with the other LED's off is expected to denote the train in the stationary stage
* A blinking green LED and a statically `HIGH` red LED denotes the train in the "round operation" stage, essentially meaning the train will begin operation
* It is expected that the second stage continue even when the obstruction be returned, as it would not be meaningful resource-wise to have the algorithm constantly check for obstruction distance once the round has started

## Procedure
1. Connect the ultrasonic sensor to a breadboard
2. Connect the Trigger and Echo pins of the sensor to pins 9 and 10 on the Arduino respectively<br/>
The ultrasonic sensor will be on the breadboard, and to achieve this, we used multiple wires of differing color
3. Connect a red LED to pin 6, blue LED to pin 7 and a green LED to pin 8
2. Place sensor (using the edge of the circular features as a datum) within a known vicinity (5 cm in our case) of an obstruction, in our case, we used my hand to act as an obstruction
3. Connect arduino to the computer
4. Upload the code ```sketch_jan09a.ino``` to the Arduino through the Arduino IDE on the computer
5. Observe the LED pattern when the obstruction is blocking the sensor, quickly remove the obstruction, and observe the LED pattern.  Return the obstruction to block the sensor once more and observe the LED pattern.
6. Comment on findings

## Results
The following data was obtained and organized to describe crucial features of this experiment.<Br/>
The state of the Gate denotes the stage of experimentation.
* Obstructing represents the stage when the sensor is first obstructed by the obstruction (measuring tape)
* Removed represents the stage when the obstruction has been first removed from the Sensor
* Returned represents the stage when the obstruction is returned to verify that the autonomous sensing behavior of the algorithm does not continue even after the train has begun the round


| Gate State  | Red LED Behavior | Blue LED Behavior | Green LED Behavior |
|-------------|------------------|-------------------|--------------------|
| Obstructing | Off              | On                | Off                |
| Removed     | On               | Off               | Blinking           |
| Returned    | On               | Off               | Blinking           |


### Procedural Issues
The OS used to run this was Linux, and upon uploading the code to the Arduino, an error was encountered in the IDE claiming insufficient priviledges. <Br />
This issue was bypassed by running ```> sudo chmod a+rw /dev/ttyACM0``` in a terminal.  Depending on which port used, ```ACM0``` may be different.

### Observations
#### Before Gate Opening
From the tabulated data, it was found that the data was largely consistent for when the gate was closed.  The blue LED was consistently lit up, denoting the following code being executed in the superloop.

```c
if (testFunction() < 10) {
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, HIGH);
}
```

In considering this behavior alongside what was expected, the sensor provided a signal of less than 10 cm, which was consistent with expectation, as the obstruction was ~5 cm from the sensor.

#### After Gate Opening
Upon gate opening, it is expected that the train begin operation, and commence into the second stage outlined in the Purpose section of this report.  This behavior was characterized as follows:

``` c
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

```

A red LED would be turned on to denote that the sensor indeed detected that the gate changed the moment the gate has opened, and the train would not be in the operations stage.

A blinking green LED implemented in the second `else` statement denotes the operations stage, essentially once the algorithm has detected that the boolean for `notStarted` was assigned a value of `false`.

What was observed was that both the red LED and green LED began their respective LED patterns.  In other words, the algorithm and implementation was capable of detecting the opening of the gate as well as maintaining this detection some time after the gate had opened.

#### Possible Obstructions during the round
When the train is running the round, there will be cases where it may run into obstructions, such as other team members, spectators, or other gates along the trail.  It is crucial that the algorithm not continue checking once the round has started, as it could potentially lead to the motor turning off during the round, as well as unnecessary resource allocation.

It was observed that the LED pattern was the same as that when the obstruction was removed. This was consistent with expectation.
