float getDistanceCM() {
  digitalWrite(AFSTAND_TRIGGER, LOW);
  delayMicroseconds(2);
  digitalWrite(AFSTAND_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(AFSTAND_TRIGGER, LOW);

  long duration = pulseIn(AFSTAND_ECHO, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
}
