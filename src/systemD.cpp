#include "systems.h"

void alarmInterrupt();
void blink();

void systemD(void *pvParameters)
{
    (void)pvParameters;             	    // FreeRTOS task parameter

    pinMode(pirSensorPin, INPUT);           // Set the PIR sensor pin mode to INPUT
    pinMode(buttonAlarmPin, INPUT);         // Set the Button pin mode to INPUT
    pinMode(ledAlarmPin, OUTPUT);           // Set the LED pin mode to OUTPUT
    pinMode(piezoBuzzerPin, OUTPUT);        // Set the Buzzer pin mode to OUTPUT
    vTaskDelay(5000 / portTICK_PERIOD_MS);  // Wait 5s to start the system

    while (true)
    {
        long int performanceTime = millis();    // Get machine time for performance measure reasons
        if (digitalRead(pirSensorPin))          // If the PIR sensor detects movement start the alarm sequence
        {
            long long int time = millis();      // Get machine time to count the 10s alarm
            do
            {   
                blink();                                    // Blink the LED
                for (int x = 0; x < 180; x++)               // Sound the Alarm on the Buzzer
                {
                    sinVal = (sin(x * (3.1412 / 180)));
                    toneVal = 1000 + (int(sinVal * 2000));
                    tone(piezoBuzzerPin, toneVal);
                }
            } while ((!digitalRead(buttonAlarmPin))&&((millis() - time) <= 10000)); // The alarm cycle is repeated until the button isn't pressed and the 10s isn't timed out
            Serial.println((String)(millis() - performanceTime) + " ms");           // Write the sequence performance timestamp 
            alarmInterrupt();                                                       // Calls interrupt function
        }
        else vTaskDelay(200 / portTICK_PERIOD_MS);                                  // Wait 200ms until sensor readings
    }
}

void alarmInterrupt()   // This function stops the Buzzer and wait 10s until the system can restart it's flow
{
    noTone(piezoBuzzerPin);
    vTaskDelay(10000 / portTICK_PERIOD_MS);
}

void blink()            // This funtion blinks the LED
{
    digitalWrite(ledAlarmPin, HIGH);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(ledAlarmPin, LOW);
    vTaskDelay(100 / portTICK_PERIOD_MS);
}