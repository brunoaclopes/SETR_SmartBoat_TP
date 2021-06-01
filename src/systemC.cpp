#include "systems.h"

void interrupt();

void systemC(void *pvParameters)
{
	(void)pvParameters;             	// FreeRTOS task parameter

	IrReceiver.begin(receiver_pin, 1);	// Begin the IR sensor
	servo.attach(servoPin);				// Attach the servo motor
	servo.write(c_angle);				// Set servo to default position

	while (true)						// This infinite cycle will run the system on loop
	{
		if (IrReceiver.decode())		// This condition verifies if there's a new value readed on the IR sensor
		{
			value = IrReceiver.decodedIRData.decodedRawData;	// Store readed value on a variable
			switch (value)
			{
			case code0:					// In case the button 0 is pressed on the remote, the servo will go to the 90 degrees position
				t_angle = 90;
				break;
			case code1:					// In case the button 1 is pressed on the remote, the servo will go to the 0 degrees position
				t_angle = 0;
				break;
			case code2:					// In case the button 0 is pressed on the remote, the interrupt function will be called
				interrupt();
				break;
			}

			if (t_angle < c_angle) { direction = -1; }	// This condition determines the rotation direction of the servo
			else direction = 1;

			IrReceiver.resume();
		}
		if (c_angle != t_angle)							// This if statement updates the current angle of the servo and sets the servo according to the target position
		{
			c_angle += direction * 1;
			servo.write(c_angle);
			vTaskDelay(20 / portTICK_PERIOD_MS);		// This delay makes the servo move slower
		}
	}
}

void interrupt()	// When this interrupt function is called the servo is detached and attached after 10s, the target position is also updated to prevent the servo from start moving after the interrupt
{
	servo.detach();
	vTaskDelay(10000 / portTICK_PERIOD_MS);
	servo.attach(servoPin);
	t_angle = c_angle;
}
