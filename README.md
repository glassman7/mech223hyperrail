# HyperRail Ultrasonic Sensor Implementation Concept (Group C5)
**Group Members**:<br/>Yeshun Ma (glassman7), Bryden Kinsella, Wojtek Sobczyk, Jordan Garrison, Akhil Prabhu, Marc Vanderbanck, Audrey Alianto

**Build Status**: Indeterminate

## Directory
1. [Key Features](#keyfeat)
2. [Outstanding TODO's](#todo)
3. [Brief Code Rundown](#briefrun)
4. [Modifiable Constants](#modif)
5. [Final Remarks](#fin)

The following code pertains to the autonomous functionality of the hyperrail train design.

  - Senses the opening of the starting gate
  - Only starts moving when gate is opened
  - Will stop moving when the round has been completed

***
### Key Features <a name="keyfeat"></a>

  - Utilizes a ultrasonic sensor to detect the starting gate
  - Takes in account of systematic error from train placement on track relative to gate and sensitivity of sensor to noise


### Outstanding TODO's <a name="todo"></a>
  - Modify the constants with additional experimentation
  - Review the code for logical errors and bugs
  - Expand on the moveTrain function

Extra batteries are permitted to power the Arduino, as they do not contribute to the direct acceleration of the device, as quoted from the HyperRail Competition PDF:

> Energy from additional batteries
is permitted provided the energy is not used to drive (accelerate) the vehicle (i.e. power
for control electronics, actuators that do not provide propulsion and other circuits will not
count towards energy used).

*Much of the code presented in this repository is subject to change with more prototyping.  Refer to the commit history for revision changes*

### Brief Code Rundown <a name="briefrun"></a>

The purpose of this software repo is to automate the starting behavior of the train.

* Do not start the train until the gate is opened.
* Constantly check if the gate has been opened, only then will the code proceed to the superloop for which more complex automated code will be executed for the actual round.
* This check is done by utilizing the ultrasonic sensor.
* Once the starting gate has been opened, we execute the code for the round.
* An additional check in the superloop will be made to check if the train has already completed the round.  *It is possible that this function may be omitted for simplicity*


### Modifiable Constants <a name="modif"></a>
Significant changes were made to the implementation of the code.  To be updated.

### Final Remarks <a name="fin"></a>
Feel free to update this README should substantial changes to the functionality of this code be made, which will most likely happen with the course of the HyperRail project.


[Additional information for Repo Sketch A](https://github.com/glassman7/mech223hyperrail/blob/master/sketch_jan09a/README.md)

[Additional information for Repo Sketch B](https://github.com/glassman7/mech223hyperrail/blob/master/sketch_jan09b/README.md)
