#include <Adafruit_NeoPixel.h>
#include "pitches.h"

// NeoPixel setup
#define NEOPIXEL_PIN 4      // Pin die verbonden is met de NeoPixels
#define NUMPIXELS 4         // Aantal NeoPixels
#define GRIPPER_PIN 6       // servo pin
#define GRIPPER_OPEN 2000   // pulse length servo open
#define GRIPPER_CLOSED 1000 // pulse length servo closed
#define SERVO_INTERVAL 20   // time between pulse
#define GRIPPER_TOGGLE 1000 // toggle gripper every second
#define BUZZER_PIN 13
Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

const int motorA1 = 9;
const int motorA2 = 3;
const int motorB1 = 10;
const int motorB2 = 11;
const int motorB2_afwijking = 4; // Compensatie voor eventuele afwijking in motor B2

const int IR_SENSORS[] = {A0, A1, A2, A3, A4, A5, A6, A7};

const int AFSTAND_ECHO = 2;
const int AFSTAND_TRIGGER = 7;

const int BlackValue = 850; // Drempelwaarde voor zwartdetectie door de lijnsensoren

float duration_us;

unsigned long timerGripper = 0;

void setup()
{
  Serial.begin(9600); // Start de serial monitor

  pinMode(GRIPPER_PIN, OUTPUT);
  digitalWrite(GRIPPER_PIN, LOW);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(IR_SENSORS[0], INPUT);
  pinMode(IR_SENSORS[1], INPUT);
  pinMode(IR_SENSORS[2], INPUT);
  pinMode(IR_SENSORS[3], INPUT);
  pinMode(IR_SENSORS[4], INPUT);
  pinMode(IR_SENSORS[5], INPUT);
  pinMode(IR_SENSORS[6], INPUT);
  pinMode(IR_SENSORS[7], INPUT);
  pinMode(AFSTAND_ECHO, INPUT);
  pinMode(AFSTAND_TRIGGER, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pixels.begin(); // Start de NeoPixel LED's

  getDistanceCM();
  while (getDistanceCM() > 24)
  {
    for (int i = 0; i < 100; i++)
    {
      delay(10);
      servo(GRIPPER_OPEN);
    }

    policeSiren();

    motorStop();
  }

  start();
}
void loop()
{
  frontLights();
  followLine();
}
