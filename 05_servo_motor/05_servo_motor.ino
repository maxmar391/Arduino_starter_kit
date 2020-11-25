#include <Servo.h> // load servo library
Servo myServo;

int const potPin = A0; // define the input pin from the potentiometer
int potValue; // define the potentiometer value
int angle; // define the motor value



void setup() {
  // put your setup code here, to run once:
  myServo.attach(9); // define the output pin for the servo motor

  Serial.begin(9600); // send to serial window with 9600 baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin); // read value from potentiometer
  angle = map(potValue, 0, 1023, 0, 179); // compute the angle value from the potentiometer value
  myServo.write(angle); // send the angle to the servo motor to move the motor
  delay(15); // short dealy to let the motor move to its position

  Serial.print("Poti: "); // print the potentiometer value and the angle in the serial window
  Serial.print(potValue);
  Serial.print("\t Angle: ");
  Serial.print(angle);
  Serial.println();
}
