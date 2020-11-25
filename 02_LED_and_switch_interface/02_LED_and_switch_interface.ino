int switchState = 0;

void setup() {
  pinMode(5, OUTPUT); // define pin 5 as output
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, INPUT); // define pin 2 as input
}

void loop() {
  switchState = digitalRead(2); // check voltage on pin 2

  if (switchState == LOW) { // if the button is NOT pressed
    digitalWrite(5, HIGH); // green LED on
    digitalWrite(4, LOW); // yellow LED off
    digitalWrite(3, LOW); // red LED off
  }

  else { // if the button is pressed
    digitalWrite(5, LOW); // green LED off
    digitalWrite(4, LOW); // yellow LED off
    digitalWrite(3, HIGH); // red LED on

    delay(500); // wait for 500 ms

    digitalWrite(5, LOW); // green LED on
    digitalWrite(4, HIGH); // yellow LED off
    digitalWrite(3, LOW); // red LED off

    delay(500); // wait for 500 ms
  }

} // go back to beginning of the loop
