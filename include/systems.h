#pragma once

#include <Arduino.h>            // Arduino library is necessary on a C++ Arduino project
#include <Arduino_FreeRTOS.h>   // FreeRTOS library to make multitasking possible

// Include variables header
#include "variables.h"

// Signture of the systems
void systemA( void *pvParameters );
void systemB( void *pvParameters );
void systemC( void *pvParameters );
void systemD( void *pvParameters );