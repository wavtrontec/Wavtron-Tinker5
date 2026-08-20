/*
 * Wavtron Tinker 5 — Blink Example
 * Blinks the onboard USRLED (PB1)
 */

void setup() {
  pinMode(PB1, OUTPUT);
}

void loop() {
  digitalWrite(PB1, HIGH);
  delay(500);
  digitalWrite(PB1, LOW);
  delay(500);
}
