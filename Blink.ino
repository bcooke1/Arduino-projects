

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(10, HIGH);
  delay(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);  // turn the LED off by making the voltage LOW
  digitalWrite(10, LOW);
  delay(10);                       // wait for a second

  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(11, HIGH);
  delay(100);                       // wait for a second
  digitalWrite(12, LOW);  // turn the LED off by making the voltage LOW
  digitalWrite(11, LOW);
  delay(10);                       // wait for a second

}
