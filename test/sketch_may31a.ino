int ledAlarmPin = 26;
int buttonAlarmPin = 18;
int piezoBuzzerPin = 28;
int pirSensorPin = 11;

float sinVal;
int toneVal;
bool interrupted = false;

void alarmInterrupt();
void blink();


void setup() {Serial.begin(9600);
  pinMode(pirSensorPin, INPUT);
  pinMode(buttonAlarmPin, INPUT);
  pinMode(ledAlarmPin, OUTPUT);
  pinMode(piezoBuzzerPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonAlarmPin), alarmInterrupt, RISING);
  delay(5000);
}

void loop() {
  long int performanceTime = millis();
  if (digitalRead(pirSensorPin))
  {
    long long int time = millis();
    do
    {   
      blink();
      for (int x = 0; x < 180; x++)
      {
        sinVal = (sin(x * (3.1412 / 180)));
        toneVal = 1000 + (int(sinVal * 2000));
        tone(piezoBuzzerPin, toneVal);
      }
      if (interrupted) {
        interrupted ^= true;
        break;
      }
    } while ((millis() - time) <= 10000);
    Serial.println((String)(millis() - performanceTime) + " ms");
    noTone(piezoBuzzerPin);
    delay(10000);
  }
  else delay(200);
}

void alarmInterrupt()
{
  interrupted ^= true;
}

void blink()
{
    digitalWrite(ledAlarmPin, HIGH);
    delay(100);
    digitalWrite(ledAlarmPin, LOW);
    delay(100);
}
