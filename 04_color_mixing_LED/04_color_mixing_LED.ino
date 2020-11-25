const int redLED = 11; // define the outputs for LED
const int greenLED = 10;
const int blueLED = 9;

const int redSensor = A0; // define the inputs from photo resistors
const int greenSensor = A1;
const int blueSensor = A2;

int redLEDValue = 0; // define the default value for LED
int greenLEDValue = 0;
int blueLEDValue = 0;

int redSensorValue = 0; // define the default value for photo resistors
int greenSensorValue = 0;
int blueSensorValue = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // send data to serial window with baud rate of 9600

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorValue = analogRead(redSensor); // read voltage values from photo resistors from the analog input pins
  delay(5); // wait 5 ms to safely let the ADC finish the conversion
  greenSensorValue = analogRead(greenSensor);
  delay(5);
  blueSensorValue = analogRead(blueSensor);
  delay(5);

  redLEDValue = redSensorValue / 4; // compute the output values for the LED, input is between 0 and 1023, the output only between 0 and 255, therefore division by 4 necessary
  greenLEDValue = greenSensorValue / 4;
  blueLEDValue = blueSensorValue / 4;

  Serial.print("Sensor Input Values: \t Red:"); // print all sensor input values in serial window
  Serial.print(redSensorValue);
  Serial.print("\t Green:");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue:");
  Serial.print(blueSensorValue);

  Serial.print("LED Output Values: \t Red:"); // print all LED output values in serial window
  Serial.print(redLEDValue);
  Serial.print("\t Green:");
  Serial.print(greenLEDValue);
  Serial.print("\t Blue:");
  Serial.print(blueLEDValue);

  Serial.println();

  analogWrite(redLED, redLEDValue);
  analogWrite(greenLED, greenLEDValue);
  analogWrite(blueLED, blueLEDValue);

}
