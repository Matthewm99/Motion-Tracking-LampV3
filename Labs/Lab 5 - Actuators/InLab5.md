# Lab 5: Actuators

## Description
Capture photos/videos/gifs of your in lab work and submit along with a brief writeup (5-10 bullet points) of the process. Document as a markdown file on Gitlab. Your documentation should include:

The goal of this lab was to control motors using an Arduino Uno. Functions were implemented to control the position of a hobby servo, the speed of a continuous rotation hobby servo and the rotation of a stepper motor.

### Position Hobby Servo
- Input an angle from the serial monitor to move the servo to the corresponding position.

![alt text](Images/position_hobby.jpeg)
Above: Position Hobby Servo Setup

![alt text](Images/position_hobby.MOV)
Above: Position Hobby Servo in action (takes angle as input, moves the corresponding angle)

![alt text](Images/position_hobby_code.jpeg)

### Continuous Rotation Servo
- This servo receives a speed as a percentage from the serial monitor and then outputs a spin of the motor at the corresponding speed.
- Eg. 5% should equate to a 5 percent of the motors max speed in the clockwise direction, whereas -5% should equate to a 5 percent counterclockwise rotation.

![alt text](Images/continuous_hobby.MOV)
Above: Continuous Hobby Servo in action (takes percentage as input, moves the corresponding percentage. Positive = Clockwise, Negative = Counterclockwise)




