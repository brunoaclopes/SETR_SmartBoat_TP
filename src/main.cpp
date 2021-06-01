#include "systems.h"

void setup() {

	Serial.begin(9600); // Initialize the Serial monitor with a 9600 baud rate

    xTaskCreate(        // Creation of task A - this task is responsable to run the System A
    systemA             //      This System A controls the light system of the boat.
    ,  "SystemA"
    ,  128              // - Stack size for the task
    ,  NULL
    ,  3                // - Priority of the task
    ,  NULL );

    xTaskCreate(        // Creation of task B - this task is responsable to run the System B
    systemB             //      This System B controls the climatisation of the boat.
    ,  "SystemB"
    ,  400              // - Stack size for the task
    ,  NULL
    ,  2                // - Priority of the task
    ,  NULL );


    xTaskCreate(        // Creation of task C - this task is responsable to run the System C
    systemC             //      This System C controls the servo motor that's responsable to control the mast position.
    ,  "SystemC"
    ,  128              // - Stack size for the task
    ,  NULL
    ,  1                // - Priority of the task
    ,  NULL );


    xTaskCreate(        // Creation of task D - this task is responsable to run the System D
    systemD             //      This System D controls the alarm system of the boat.
    ,  "SystemD"
    ,  128              // - Stack size for the task
    ,  NULL
    ,  4                // - Priority of the task
    ,  NULL );

    
    // Serial.println(uxTaskGetStackHighWaterMark(NULL));   // - This command analyzes the available stack memory on a FreeRTOS Tasks
}

void loop() {}          // As I'm using the FreeRTOS Multitasking to execute the systems, the loop function isn't necessary