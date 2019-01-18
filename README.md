# Don't kill your plants!

**Author(s)**: Natasha Stallsmith and Tirtha Subedi

**Google Document**: https://docs.google.com/document/d/16PQsD9lrPFoG10iWvd56AJSm8ZgAgtpKkd_IgjPh894/edit?usp=sharing

---
## Purpose

We all love plants, we all need plants, and in fact, studies have shown that having plants around can help reduce stress. At the same time, however, indoor plants can be hard to take care of because it requires us remembering to water them which another task on top of all of the tasks we have to do. Not only that, but we have to remember when was the last time we watered them so as not to overwater them. Our hope is that though this project we can making caring for a plant much easier by creating an embedded system which measures the water density in your plants soil and lets you know (by a little light) when it is time to water your plant again.

## Initial Design Plan

**Hardware:**
- LEDs: Red and Green
- Soil moisture sensor
- Arduino metro
- Breadboard 
- Wires
  
*Need: interaction of parts/diagram*

Here is the location for the project diagram: 
 file:///home/rajsubedi/Pictures/project12.jpeg
  
  
**Code:**

We will start with the AnalogReadSerial example code.

Setup:
- Declare variable for input pin connected to sensor
- Declare variable for output pin connected to sensor
- Declare variable for Red and Green pins

Loop:
- Take reading from sensor
- Use if statements to determine if the moisture level is below the desired level
- If the moisture level is too low, turn on Red LED
- If the moisture level is above the cutoff, turn on Green LED

## Files

- README (you are here): Documentation of our project.
- LICENSE: Licensing info.

## Summary

## Instructions
   - First of all, Make sure all the parts and wires are connected and connect arduino metro to power supplier or to the laptop
   - Use the Soil moisture sensor to measure the moisture of soil (in our case it will be soil port)
   - Then LED light will light up determinding wheather the soil moisture is good or not, if it is good then Green LED will
     light up and if it's not then Red LED will light up.

## Errors and Constraints

## Reflection

## References

- https://www.instructables.com/id/Arduino-Soil-Moisture-Sensor/ - Instructions for connecting soil moisture sensor to Arduino Uno.
- https://learn.sparkfun.com/tutorials/soil-moisture-sensor-hookup-guide/all - Another instruction, this one explains how the values read from the sensor will differ according to the amount of power supplied to it.


## Final Self-Evaluations

### Ideation, Brainstorming, Design:

*Natasha:*

*Tirtha:*

### Code creation: 

*Natasha:*

*Tirtha:*

### Documentation creation:

*Natasha:*

*Tirtha:*

### Teamwork & Participation:

*Natasha:*

*Tirtha:*
