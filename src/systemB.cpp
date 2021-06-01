#include "systems.h"

void systemB( void *pvParameters )
{
    (void)pvParameters;             // FreeRTOS task parameter

    lcd.begin(16, 2);               // Begin the 16x2 LCD
    lcd.setCursor(5, 0);            // Set LCD cursor to 5, 0
    lcd.print("Fan OFF");           // Write Fan OFF on the LCD
    pinMode(ledRedPin, OUTPUT);     // Set red LED pin mode to OUTPUT
    pinMode(ledGreenPin, OUTPUT);   // Set green LED pin mode to OUTPUT
    pinMode(fanPin, OUTPUT);        // Set Fan pin mode to OUTPUT
    dht.begin();                    // Begin the DHT11 sensor
    
    while (true)                    // This infinite cycle will run the system on loop
    {
        lcd.setCursor(0, 1);            // Set LCD cursor to 0, 1
        lcd.print("Temp:");             // Write Temp: on the LCD

        tempC = dht.readTemperature();  // Read Temperature from the DHT11 sensor
        lcd.setCursor(6, 1);            // Set LCD cursor to 6, 1
        lcd.print(tempC, 1);            // Write the readed temperature on the LCD
        lcd.print("'C");                // Write the celsius unit on the LCD

        lcd.setCursor(5, 0);            // Set LCD cursor to 5, 0
        if (tempC >= 24)                // If the temperature is above 24 degrees the fan state variable will be set to true and the fan state will be updated on the LCD
        {
            fanState = true;
            lcd.print("Fan ON ");
        }
        else if (tempC <= 19)           // If the temperature is bellow 19 degrees the fan state variable will be set to false and the fan state will be updated on the LCD
        {
            fanState = false;
            lcd.print("Fan OFF");
        }

        digitalWrite(ledRedPin, fanState);      // Update the red LED state according to the fan state
        digitalWrite(ledGreenPin, !fanState);   // Update the green LED state according to the fan state

        digitalWrite(fanPin, fanState);         // Update the Fan state according to the fan state variable

        vTaskDelay(1500 / portTICK_PERIOD_MS);  // Wait 1.5 second until the next iteration
    }
}