void followLine()
{
  if (analogRead(IR_SENSORS[7]) > BlackValue || analogRead(IR_SENSORS[6]) > BlackValue || analogRead(IR_SENSORS[7]) > BlackValue && analogRead(IR_SENSORS[0]) < BlackValue)
  {
    motorTurnLeft(245); 
  }
  else if (analogRead(IR_SENSORS[3]) > BlackValue || analogRead(IR_SENSORS[4]) > BlackValue)
  {
    motorForward(210);
  }
  else if (analogRead(IR_SENSORS[5]) > BlackValue || analogRead(IR_SENSORS[6]) > BlackValue)
  {
    motorTurnLeft(200);
  }
  else if (analogRead(IR_SENSORS[0]) > BlackValue || analogRead(IR_SENSORS[1]) > BlackValue || analogRead(IR_SENSORS[0]) > BlackValue && analogRead(IR_SENSORS[7]) < BlackValue)
  {
    motorTurnRight(200);
  }
  else if (analogRead(IR_SENSORS[8]) < BlackValue)
  {
    motorTurnRight(245);
  }
}
