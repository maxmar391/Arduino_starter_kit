#include <Servo.h> // load servo library
Servo myServo;

int const tempPin = A1; // define the input pin from the temperature sensor
int tempValue; // define the sensor value
float angle; // define the motor value
float voltage;
float temperature;



void setup() {
  // put your setup code here, to run once:
  myServo.attach(9); // define the output pin for the servo motor

  Serial.begin(9600); // send to serial window with 9600 baud rate
}

void loop() {
  // put your main code here, to run repeatedly:
  tempValue = analogRead(tempPin); // read value from the temperature sensor
  voltage = (tempValue / 1024.0) * 5.0; // compute the voltage from the input value
  temperature = (voltage - 0.5) * 100; // compute the actual temperature from the voltage

  angle = temperature * 2; // compute the angle value from the sensor value
  myServo.write(angle); // send the angle to the servo motor to move the motor
  delay(15); // short dealy to let the motor move to its position

  Serial.print("Sensor: "); // print the sensor value and the angle in the serial window
  Serial.print(tempValue);
  Serial.print("\t Angle: ");
  Serial.print(angle);
  Serial.println();
}
