
int melody[] = {
    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_D5, NOTE_E5, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
    NOTE_C5, NOTE_A4, NOTE_B4, REST,

    NOTE_A4, NOTE_A4,
    // Repeat of first part
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, REST,
    NOTE_A4, NOTE_G4, NOTE_A4, REST,

    NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, REST,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, REST,
    NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, REST,

    NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, REST,
    NOTE_D5, NOTE_E5, NOTE_A4, REST,
    NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, REST,
    NOTE_C5, NOTE_A4, NOTE_B4, REST,
    // End of Repeat

    NOTE_E5, REST, REST, NOTE_F5, REST, REST,
    NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
    NOTE_D5, REST, REST, NOTE_C5, REST, REST,
    NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4,

    NOTE_E5, REST, REST, NOTE_F5, REST, REST,
    NOTE_E5, NOTE_E5, REST, NOTE_G5, REST, NOTE_E5, NOTE_D5, REST, REST,
    NOTE_D5, REST, REST, NOTE_C5, REST, REST,
    NOTE_B4, NOTE_C5, REST, NOTE_B4, REST, NOTE_A4};

int durations[] = {
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 8, 4, 8,

    8, 8, 4, 8, 8,
    4, 8, 4, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 4,

    4, 8,
    // Repeat of First Part
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8,

    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 8, 8,
    8, 8, 8, 4, 8,

    8, 8, 4, 8, 8,
    4, 8, 4, 8,
    8, 8, 4, 8, 8,
    8, 8, 4, 4,
    // End of Repeat

    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 8, 8, 8, 4,
    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 2,

    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 8, 8, 8, 4,
    4, 8, 4, 4, 8, 4,
    8, 8, 8, 8, 8, 2};
uint32_t noteToColor(int noteFrequency)
{
  // Implement the logic to map note frequencies to colors
  // Example:
  if (noteFrequency < 400)
    return pixels.Color(0, 0, 255); // Blue for lower frequencies
  else if (noteFrequency < 800)
    return pixels.Color(0, 255, 0); // Green for mid frequencies
  else
    return pixels.Color(255, 0, 0); // Red for higher frequencies
}
uint32_t Wheel(byte WheelPos)
{
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85)
  {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170)
  {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
void followLine()
{
  if (analogRead(IR_SENSORS[7]) > BlackValue)
  {
    motorForward(210);
    delay(300);
    if (analogRead(IR_SENSORS[2]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue)
    {
      motorStop();
      motorBackward(255);
      delay(375);
      motorStop();
      for (int i = 0; i < 10; i++)
      {
        servo(GRIPPER_OPEN);
        delay(100);
      }
      motorBackward(255);
      delay(1500);
      motorRightBackwards(255);
      delay(625);
      motorStop();
      while (true)
      {
        int size = sizeof(durations) / sizeof(int);

        for (int note = 0; note < size; note++)
        {
          int duration = 1000 / durations[note];
          tone(BUZZER_PIN, melody[note], duration);

          // Light up the corresponding pixel for the note
          int pixelIndex = note % NUMPIXELS; // Ensure the pixel index wraps around if there are more notes than pixels
          uint32_t color = Wheel(note % 255);
          pixels.setPixelColor(pixelIndex, color);
          pixels.show(); // Update the display to show the change

          // Optionally, you can turn off the previous pixel to create a "moving light" effect
          int previousPixelIndex = (note - 1) % NUMPIXELS;
          if (previousPixelIndex < 0)
            previousPixelIndex += NUMPIXELS; // Correct negative index
          pixels.setPixelColor(previousPixelIndex, pixels.Color(0, 0, 0));

          int pauseBetweenNotes = duration * 1.30;
          delay(pauseBetweenNotes);
          noTone(BUZZER_PIN);
        }

        // Turn off all pixels at the end of the melody
        for (int i = 0; i < NUMPIXELS; i++)
        {
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        }
        pixels.show();

        // Add a short delay before repeating the melody
        delay(1000);
      }
      return;
    }
    motorTurnLeft(225);
    delay(500);
    while (true)
    {
      delay(1);
      if (analogRead(IR_SENSORS[4]) > BlackValue || analogRead(IR_SENSORS[3]) > BlackValue || analogRead(IR_SENSORS[2]) > BlackValue)
      {
        break;
      }
    }
    motorStop();
  }
  else if (analogRead(IR_SENSORS[3]) > BlackValue || analogRead(IR_SENSORS[4]) > BlackValue)
  {
    motorForward(250);
  }
  else if (analogRead(IR_SENSORS[5]) > BlackValue || analogRead(IR_SENSORS[6]) > BlackValue)
  {
    motorTurnLeft(200);
  }
  //|| analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[7]) < BlackValue
  else if (analogRead(IR_SENSORS[0]) > BlackValue || analogRead(IR_SENSORS[1]) > BlackValue || analogRead(IR_SENSORS[2]) > BlackValue)
  {
    motorTurnRight(200);
  }
  else if (analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[7]) < BlackValue)
  {
    motorTurnRight(200);
    while (true)
    {
      delay(1);
      if (analogRead(IR_SENSORS[7]) > BlackValue || analogRead(IR_SENSORS[6]) > BlackValue || analogRead(IR_SENSORS[3]) > BlackValue || analogRead(IR_SENSORS[4]) > BlackValue || analogRead(IR_SENSORS[5]) > BlackValue || analogRead(IR_SENSORS[0]) > BlackValue || analogRead(IR_SENSORS[1]) > BlackValue)
      {
        break;
      }
    }
    motorStop();
  }
  else
  {
    motorForward(210);
  }
}
