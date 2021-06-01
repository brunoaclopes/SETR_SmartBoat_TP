#pragma once

#include <LiquidCrystal.h>  // LCD library
#include <Servo.h>          // Servo library
#include <IRremote.h>       // IR sensor library
#include "DHT.h"            // DHT sensor library

//SystemA ------------------------

// Pins for system A
extern int ledPin;
extern int ldrPin;

// system variables
extern int lightVal;
extern int ledVal;

//SystemB ------------------------

// Pins for system B
extern LiquidCrystal lcd;
extern int ledRedPin;
extern int ledGreenPin;
extern int dht11Pin;
extern DHT dht;
extern int fanPin;

// system variables
extern float tempC;
extern bool fanState;

//SystemC ------------------------

// Remote codes
#define code1 4077715200
#define code2 3877175040
#define code0 3910598400

// Pins for system C
extern int receiver_pin;
extern int servoPin;

// system variables
extern Servo servo;
extern int c_angle;
extern int t_angle;
extern int direction;
extern unsigned long int value;

//SystemD ------------------------

// Pins for system D
extern int ledAlarmPin;
extern int buttonAlarmPin;
extern int piezoBuzzerPin;
extern int pirSensorPin;

// system variables
extern float sinVal;
extern int toneVal;