#include "systems.h"

void systemA( void *pvParameters )
{
    (void)pvParameters;         // FreeRTOS task parameter

    pinMode(ledPin, OUTPUT);    // Set LED pin mode to OUTPUT

    while (true)                // This infinite cycle will run the system on loop
    {
        lightVal = analogRead(ldrPin);                  // Read light values from the sensor

        if (lightVal >= 800)                            // If the sensor value is higher or equal to 800 the light of the boat will be set to 255
        {
            ledVal = 255;
        }
        else if (lightVal >= 500 && lightVal < 800)     // If the sensor value is between 500 and 800 the light of the boat will be set to 128
        {
            ledVal = 128;
        }
        else if (lightVal >= 200 && lightVal < 500)     // If the sensor value is between 200 and 500 the light of the boat will be set to 64
        {
            ledVal = 64;
        }
        else                                            // If the sensor value is less than 200 the light of the boat will turn off.
        {
            ledVal = 0;
        }
        analogWrite(ledPin, ledVal);                                            // Write desired intensity on the LED
        Serial.println("\nLDR is reading: " + (String)lightVal);                // Write LDR readed intensity on the Serial monitor
        Serial.println("LED voltage(v): " + (String)(ledVal * 5.0 / 255));      // Write LED output intensity on the Serial monitor
        vTaskDelay(1000 / portTICK_PERIOD_MS);                                  // Wait 1 second until the next iteration
    }
}