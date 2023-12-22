# Servo driver for Pixy 1 and 2

## Pixy servo library
In general, the options related to the configuration of servos and also to the settings of the Pan/Till demo program used to follow the object are the same for versions 1 and 2, so they will be described together.

### Servo tab configuration
After connecting the camcorder to the computer and launching the PixyMon program, you can find the *servos* tab in the configuration window. It contains the available settings for servos. Different brands of RC-servos tend to require different timings, which can lead to the servos moving more or less than desired or that they are capable of. This dialog can help address these differences. **The values shown in the image are the default values.**

<center><img src="confg_win.png" alt="Configuration window" width="350" /></center>

- S0 lower limit: This parameter sets the lower limit of servo 0.
- S0 upper limit: This parameter sets the upper limit of servo 0.
- S1 lower limit: This parameter sets the lower limit of servo 1.
- S1 lower limit: This parameter sets the upper limit of servo 1.
- Servo frequency: measured in Hz, this parameter sets the frequency of the PWM signal that controls both servos.

Note: the lower limit values control how far clockwise the servos move, with more negative being farther clockwise. The upper limit values control how far counter-clockwise the servos move, with more positive being farther counter-clockwise.

You can test the limits by issuing servo move commands from the console window. You can bring up the console window by selecting Console in the View menu. Hit the stop button and type in the following commands:

- “rcs_setPos 0 0” moves servo 0 to its clockwise limit
- “rcs_setPos 0 1000” moves servo 0 to its counter-clockwise limit
- “rcs_setPos 1 0” moves servo 0 to its clockwise limit
- “rcs_setPos 1 1000” moves servo 0 to its counter-clockwise limit

<center><b>Information above are copied form pixy documentation</b></center>

Pixy2 documentation can be find [HERE][1]


>The settings we can find in PixyMon allow us to adjust the range in which the servo is controlled. The minimum value is mapped to zero and the maximum value is mapped to 1000. Therefore, you can adjust the range according to your requirements, and setting the servos is always done in the range from 0 to 1000. The position of the servos can be changed using the **setServos** function implemented in the PixyCam2 driver, which sends a command to override the servo to the appropriate position. Therefore, the middle position is a position of 500, the minimum extreme position is 0 and the maximum position is 1000.

## Servo library 

* Servo library that can be used for gimbal is localized in PM2_Drivers library [HERE][2]
* Documentation is under this [LINK][3]

s
[1]: https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:pixymon_index
[2]: https://github.com/pichim/pm2_drivers
[3]: https://github.com/pichim/PM2_PES_Board_Example/blob/dev/markdown/servo.md

# Pixy driver - the most important informations

### After writing driver and testing
Observations:
- The quality of the information you get depends on how much of a distinctive object you are observing - it depends on the settings so it is worth teaching the pix before testing.
- In the current state, the pixy receives (analyzes) information at a specific constant! frequency of 60Hz
- if nothing works, just rebuild the whole program

Problems:

- It happens, rarely, that pixy sends messages with incorrect checksum which results in the message not being analyzed
- During testing, it is important to watch the diode, in case the pixy sees an object, it lights up in the color of that object. If the diode is not lit then the pixy does not follow the object. What is very important! The problem that appeared before was characterized by the fact that the diode was lit - the pixy saw the object, and yet did not follow it - this means that there is a problem with the information being sent
- In case of inactivity, the pixy returns to the initial position after some time, this is a behavior of unknown origin - in my opinion it is an internal behavior of the pixy, independent of the code 