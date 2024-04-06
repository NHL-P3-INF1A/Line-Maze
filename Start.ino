

void start()
{

  startCountdown();

  // Start moving forward
  motorForward(255);

  // Wait until all sensors detect black (outline of parking lot)
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue))
  {
  }

  // Wait until all sensors detect white
  while (!(analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[1]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[6]) < BlackValue))
  {
  }

  // Wait until all sensors detect black again
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue))
  {
  }

  // Wait until all sensors detect white
  while (!(analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[1]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[6]) < BlackValue))
  {
  }

  // Wait until all sensors detect black againx
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue))
  {
  }

  // Wait until only the middle two sensors detect white (vertical black line)
  while (!(analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue))
  {
  }

  // Wait until all sensors detect black again (black box)
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue))
  {
  }

  // Wait until all sensors detect white
  while (!(analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[1]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[6]) < BlackValue))
  {
  }

  motorStop();

  for (int i = 0; i < 100; i++)
  {
    delay(10);
    servo(GRIPPER_CLOSED);
  }
  motorTurnLeft(200);
  delay(300);
  while (true)
  {
    if (analogRead(IR_SENSORS[4]) > BlackValue)
    {
      break;
    }
  }

  motorForward(255);
  deactivateTurnSignals();

  delay(500);

  motorStop();
}

void startCountdown()
{
  for (int i = 0; i < 5; i++)
  {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();

  int LED_ON_DURATION = 450;
  int countdownToneFrequency = 400;
  int countdownToneDuration = LED_ON_DURATION;
  int pauseDuration = 150; // Duration of pause between tones

  for (int i = 4; i >= 0; i--)
  {
    tone(13, countdownToneFrequency, countdownToneDuration); // Start playing the tone
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));        // Turn on the LED
    pixels.show();                                           // Update the LED strip to show the change

    delay(LED_ON_DURATION); // Wait for the LED to be on for the duration

    noTone(13);           // Stop the tone
    delay(pauseDuration); // Short pause before the next tone and LED
  }

  // Generate a random delay between 1 and 3 seconds for the final light off
  long finalDelay = random(500, 2001); // random(min, max) generates a number between min and max-1
  delay(finalDelay);                   // Apply the random delay

  int finalToneFrequency = 1000;
  tone(13, finalToneFrequency, 1000); // Play the final tone for 1 second
  delay(1000);
}

void policeSiren()
{
  int SIREN_DURATION = 150;
  uint32_t redColor = pixels.Color(0, 0, 255);
  uint32_t blueColor = pixels.Color(0, 255, 0);

  for (int i = 0; i < 5; i++)
  {
    pixels.setPixelColor(0, i % 2 == 0 ? redColor : blueColor);
    pixels.setPixelColor(1, i % 2 == 0 ? blueColor : redColor);
    pixels.setPixelColor(2, i % 2 == 0 ? blueColor : redColor);
    pixels.setPixelColor(3, i % 2 == 0 ? redColor : blueColor);

    pixels.show();
    delay(SIREN_DURATION);

    pixels.setPixelColor(0, i % 2 == 0 ? blueColor : redColor);
    pixels.setPixelColor(2, i % 2 == 0 ? redColor : blueColor);
    pixels.setPixelColor(1, i % 2 == 0 ? redColor : blueColor);
    pixels.setPixelColor(3, i % 2 == 0 ? blueColor : redColor);

    pixels.show();
  }
}
