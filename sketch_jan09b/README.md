# Arduino Ultrasonic Sensor Test
Performed on January 10, 2019<br />

Sketch B Code:<Br />
 https://github.com/glassman7/mech223hyperrail/blob/master/sketch_jan09b/sketch_jan09b.ino" 

## Purpose
To determine the effectiveness of the ultrasonic sensor in terms of sensing fluctuations in distances corresponding to the opening of the mechanical gate.

## Procedure
1. Connect the ultrasonic sensor to a breadboard
2. Connect the Trigger and Echo pins of the sensor to pins 9 and 10 on the Arduino respectively<br/>
The ultrasonic sensor will be on the breadboard, and to achieve this, we used multiple wires of differing color
2. Place sensor (using the edge of the circular features as a datum) within a known vicinity (5 cm in our case) of an obstruction, in our case, we used my hand to act as an obstruction
3. Connect arduino to the computer
4. Upload the code ```sketch_jan09b.ino``` to the Arduino through the Arduino IDE on the computer
5. Open the Serial Monitor feature to determine the distances, comment on the signal consistency with what was expected
6. Quickly remove the obstruction, and comment on what is observed
6. Make additional comments on any extra observations

## Results
The following data was obtained and organized to describe crucial features of this experiment.<Br/>
Gate opened denotes whether the obstruction was in front of the sensor or removed.  Average signal was taken by taking the mode, as the mode was vastly prevalent in the large stream (about several hundred) of measurements.  Signal range was determined by taking the largest signal found from reading the Serial Monitor and subtracting it from the smallest signal.

| Gate Opened? | Average Signal (cm) | Signal Range (cm) | Mode (cm) |
|--------------|---------------------|-------------------|-----------|
| No           | 5                   | 5                 | 5         |
| Yes          | 40                  | 2921              | 40        |


### Procedural Issues
The OS used to run this was Linux, and upon uploading the code to the Arduino, an error was encountered in the IDE claiming insufficient priviledges. <Br />
This issue was bypassed by running ```> sudo chmod a+rw /dev/ttyACM0``` in a terminal.  Depending on which port used, ```ACM0``` may be different.

### Observations
#### Before Gate Opening
From the tabulated data, it was found that the data was largely consistent for when the gate was closed.  However, this data was not consistent throughout, as evidenced from the range.  An additional observation was made that this fluctuation would happen near the start.  It was concluded from this that should this sensor be implemented into the train design, a stabilization function be run before using any of the signals to ensure the data is stabilized before being used.




#### After Gate Opening
A larger fluctuation was observed when the gate was opened.  This was consistent with what was expected, due to the fact that the sensor would be reading the environment of the test room, which was not relatively flat like that of the obstruction.  Since the purpose of the selection for this sensor was due to the fact that the indicator to which the gate would open was from a large spike in signal, this observation did not impede the function.  It was later observed that the signal also stabilized to another value, however, this was most likely due to the fact that the environment became more constant, as evidenced below:

![alt text](https://cdn.discordapp.com/attachments/510705698326315026/533338919157366784/50020070_503666710041303_696482595482894336_n.png "Logo Title Text 1")
