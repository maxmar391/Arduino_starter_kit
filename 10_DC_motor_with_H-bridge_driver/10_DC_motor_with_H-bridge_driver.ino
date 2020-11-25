const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onoffSwitchPin = 5;
const int potiPin = A0;

int onoffState = 0;
int previousonoffState = 0;
int directionState = 0;
int previousDirectionState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;



void setup() {
  pinMode(directionSwitchPin, INPUT); // define pins connected to switches as input
  pinMode(onoffSwitchPin, INPUT);

  pinMode(controlPin1, OUTPUT); // define pins connected to H-bridge as output
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  analogWrite(enablePin, 0);
}

void loop() {
  onoffState = digitalRead(onoffSwitchPin); // read the switch state
  delay(1);

  directionState = digitalRead(directionSwitchPin); // read the direction state
  delay(1);

  motorSpeed = analogRead(potiPin) / 4; // read the motor speed from the potentiometer pin

  if (onoffState != previousonoffState) {
    if (onoffState == HIGH) {
      motorEnabled = !motorEnabled; // if the switch is pressed, turn on the motor
    }
  }

  if (directionState != previousDirectionState) {
    if (directionState == HIGH) {
      motorDirection = !motorDirection; // if the direction switch is pressed, reverse the motor direction
    }
  }

  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }


  if (motorEnabled == 1) { // if the motor was enabled, send the motor speed
    analogWrite(enablePin, motorSpeed);
  }
  else { // if the motor is disabled, set the speed to zero
    analogWrite(enablePin, 0);
  }


  previousDirectionState = directionState; // save the current direction state for the next loop
  previousonoffState = onoffState; // save the current switch state for the next loop

}
