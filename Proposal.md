# **Project Proposal - Luxo Jr**
## **An Interactive Motion-Tracking Desk Lamp**

I will be designing and building an animated desk lamp inspired by the Pixar Luxo Jr. opening scene. I aim to recreate the lamp's expressive motion and sense of creativity using sensors to detect motion and servo-driven joints to adjust position and orientation.

## Functional Description
When powered on, the lamp will remain in a neutral resting pose. Upon detecting motion or an object within its field of view, the lamp will:
- Rotate or tilt its head toward the detected object
- Adjust arm joints to “lean” or follow motion
- Maintain smooth, natural movements to mimic animated behavior

## **Course Labs Incorporated**
1. **CAD and Parametric Design + Intermediate 3D Printing**
The main body, joints and arms of the lamp will be created using CAD for easy design and dimensioning
2. **Reverse Engineering**
As this project is inspired by an animated character, this build will attempt to reverse engineer the design of the original
3. **Sensors**
A motion sensor will be used to detect objects in front of the lamp to follow
4. **Actuators**
Servo motors will be used to power movement of the joints at the head and base
5. **Embedded Systems**
A microcontroller will be used to receive input from the sensors and to control output of the servos

## System Architecture
- **Input:** Motion sensor or camera detects object position or movement
- **Processing:** Arduino interprets sensor data and computes joint angles
- **Output:** Servo motors adjust lamp posture and orientation
- **Feedback:** Continuous sensor updates allow responsive, dynamic motion

## **Materials**
| Item | Purpose | Price |
| ------ | ------ | ------ |
| Arduino Uno       | Microcontroller       | N/A       |
| Micro Servo Motors (x3)       | Joint and head movement       | $15.00       |
| Sensors / PixyMon Camera       | Motion Tracking      | $80.00       |
| LED + Resistors       | Lamp bulb       | N/A       |
| 3D Printing Filament       | Body / Structure      | N/A       |

