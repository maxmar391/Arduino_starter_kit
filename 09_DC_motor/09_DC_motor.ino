const int switchPin = 2;
const int motorPin = 9;
int switchState = 0;



void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  digitalWrite(motorPin, LOW);
}



void loop() {
  switchState = digitalRead(switchPin); // read the current switch state

  if (switchState == HIGH) { // if the switch is pushed, turn on the motor
    digitalWrite(motorPin, HIGH);
  }

  else { // if the switch is not pushed, keep the motor turned off
    digitalWrite(motorPin, LOW);
  }
}
