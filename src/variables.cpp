#include "variables.h"

//SystemA ------------------------

// Pins for system A
int ledPin = 12;
int ldrPin = A0;

// system variables
int lightVal = 0;
int ledVal;

//SystemB ------------------------

// Pins for system B
LiquidCrystal lcd(2,3,4,5,6,7);
int ledRedPin = 22;
int ledGreenPin = 23;
int dht11Pin = 25;
DHT dht(dht11Pin, DHT11);
int fanPin = 24;

// system variables
float tempC;
bool fanState = false;

//SystemC ------------------------

// Pins for system C
int receiver_pin = 9;
int servoPin = 10;

// system variables
Servo servo;
int c_angle = 0;
int t_angle = 0;
int direction = 1;
unsigned long int value;

//SystemD ------------------------

// Pins for system D
int ledAlarmPin = 26;
int buttonAlarmPin = 18;
int piezoBuzzerPin = 28;
int pirSensorPin = 11;

// system variables
float sinVal;
int toneVal;