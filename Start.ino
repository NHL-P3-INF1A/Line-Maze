
void start() {

 startCountdown();

  // Start moving forward
 motorForward(255);

  // Wait until all sensors detect black (outline of parking lot)
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue)) {}

  // Wait until all sensors detect white
  while (!(analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[1]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[6]) < BlackValue)) {}

  // Wait until all sensors detect black again
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue)) {}
  
  // Wait until all sensors detect white
  while (!(analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[1]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[6]) < BlackValue)) {}

  // Wait until all sensors detect black againx
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue)) {}

  // Wait until only the middle two sensors detect white (vertical black line)
  while (!(analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue)) {}

  // Wait until all sensors detect black again (black box)
  while (!(analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[1]) > BlackValue && analogRead(IR_SENSORS[3]) > BlackValue && analogRead(IR_SENSORS[4]) > BlackValue && analogRead(IR_SENSORS[5]) > BlackValue && analogRead(IR_SENSORS[6]) > BlackValue)) {}

  // Wait until all sensors detect white
  while (!(analogRead(IR_SENSORS[0]) < BlackValue && analogRead(IR_SENSORS[1]) < BlackValue && analogRead(IR_SENSORS[3]) < BlackValue && analogRead(IR_SENSORS[4]) < BlackValue && analogRead(IR_SENSORS[5]) < BlackValue && analogRead(IR_SENSORS[6]) < BlackValue)) {}


  // Stop the motors
  motorStop();

    for(int i = 0; i < 100; i++){
      delay(10);
      servo(GRIPPER_CLOSED);
    }
    motorTurnLeft(200);
  delay(300);
  while(true){
    if(analogRead(IR_SENSORS[4]) > BlackValue){
      break;
    }
  }


  // Move a bit forward
  motorForward(255);
  deactivateTurnSignals();

  delay(500); // Adjust this delay to move a bit forward

  // Stop the motors before starting to follow the line
  motorStop();



}


void startCountdown(){
  for (int i = 0; i < 5; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  int LED_ON_DURATION = 500;
  
  for (int i = 4; i >= 0; i--) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    
    delay(LED_ON_DURATION);

  }


}

void policeSiren() {
  int SIREN_DURATION = 150;
  uint32_t redColor = pixels.Color(0, 0, 255);
  uint32_t blueColor = pixels.Color(0, 255, 0);

   for (int i = 0; i < 5; i++) {
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
