# Lab 3: Sensors

## Description
For the third in-lab assignment, we were tasked with getting the readings out of 3 different sensors.
- 1 sensor must be analog, and 1 must be digital
- Sensing must be more complex than button presses
- Must be able to explain what sensor does, physical quantity measured and application

## Colour Sensor
Guide followed: https://learn.adafruit.com/adafruit-color-sensors/overview

- The TCS34725 RGB Sensor is a digital sensor that can sense RGB and clear light.
- It measures the intensity of red, green, blue and overall light levels.
- We connected the sensor to the Arduino Uno using wires, following guide linked in the Lab PDF.
- Adjustments were made to the sample code provided to align with the wiring and pins we arranged. Specifically, Analog Pin 2 was used instead of Digital Pin 4.
- Real-time measurements were observed through the Serial Monitor as we placed differently coloured objects in front of the sensor.
- Potential applications include object identification and colour sorting robots.

![alt text](Images/coloursensor.jpeg)
Colour Sensor Setup - Red wire placed in front of the sensor

![alt text](Images/coloursensorcode.jpeg)
Colour Sensor Code - Red wire placed in front of the sensor. Accounted for in the RGB and Color Temp values.

![alt text](Images/coloursensornone.jpeg)
Colour Sensor Setup - Nothing placed in front of the sensor

![alt text](Images/coloursensorcode.jpeg)
Colour Sensor Code - Nothing placed in front of the sensor. Accounted for in the RGB and Color Temp values.

## Light Dependent Resistor

- The Light Dependent Resistor is an analog sensor that shows a change in resistance when the level of illumination changes.
- We connected the sensor to the Arduino Uno using wires, following the guide image in the Lab PDF. See below:

![alt text](Images/ldrsetup.png)

- Additionally, an LED was connected to the system to visualize the output.
- We moved our hands over the sensor to vary the illumination levels.

![alt text](Images/ldr.jpeg)

![alt text](Images/ldrhand.jpeg)
Above: hand being placed over the resistor

![alt text](Images/ldrhandoveroutput.jpeg)
Above: serial monitor when hand placed over resistor

![alt text](Images/ldrregularoutput.jpeg)
Above: serial monitor when hand removed from over resistor

- Potential applications could include automated lighting systems that turn on at night and off during the daytime, as well as brightness control on electronic devices.

## Temperature and Humidity Sensor
Guide followed: https://learn.adafruit.com/dht

- The temperature and humidity sensor is a digital sensor that can measure temperature and humidity.
- The sensor measures temperature (in °C) using a thermistor, which changes resistance with temperature.
- The sensor also measures Humidity (as a percentage) using a moisture-sensitive component that detects water vapor in the air.
- We connected the sensor to the Arduino Uno using wires, comparing against the guide, although our sensor was different.
- Potential applications include indoor climate monitoring (rooms, greenhouses, etc.) and weather monitoring systems.

![alt text](Images/tempsensor.jpeg)
Above: Temperature and Humidity Sensor setup

![alt text](Images/tempsensorcode.jpeg)
Above: Variance of humidity and temperature as we touch and release our finger from the sensor (humidity increases as we bring our fingers closer).

![alt text](Images/tempsensorcode2.jpeg)
Above: Finger fully away from sensor, humitiy drops signifiantly.