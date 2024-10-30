#include <Arduino.h>
#include <Servo.h>

/*
PWM pins Arduino Nano 
Pin 3 (PWM)
Pin 5 (PWM)
Pin 6 (PWM)
Pin 9 (PWM)
Pin 10 (PWM)
Pin 11 (PWM)
*/

//Instances
Servo leftArm;
Servo rightArm;

//Pin Definitions
const int pinLeftArm = 9;
const int pinRightArm = 10;

//Interval Position Definitions
const long MIN_POSITION = 0;
const long MAX_POSITION = 181;

//Interval Delay Definitions
const long MIN_DELAY = 1000;
const long MAX_DELAY = 5000;

void setup() 
{
  // Serial.begin(9600);
  leftArm.attach(pinLeftArm);
  rightArm.attach(pinRightArm);

  randomSeed(analogRead(0));

  leftArm.write(0);
  rightArm.write(0);
  delay(3000);
}

void loop() 
{
  leftArm.write(static_cast<int>(random(MIN_POSITION, MAX_POSITION)));
  rightArm.write(static_cast<int>(random(MIN_POSITION, MAX_POSITION)));
  // Serial.println(static_cast<int>(random(MIN_POSITION, MAX_POSITION)));
  // Serial.println(static_cast<int>(random(MIN_POSITION, MAX_POSITION)));
  delay(static_cast<unsigned long>(random(MIN_DELAY, MAX_DELAY)));
}
