const int sensorPin = A0;
const float baselineTemp = 22.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);// open serial port with 9600 baud rate

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) { // for loop, looping through all used pins 2-4
    pinMode(pinNumber, OUTPUT); // define used pins 2-4 as output
    digitalWrite(pinNumber, LOW); // set used pins 2-4 to low
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  // sensor output value computations
  int sensorValue = analogRead(sensorPin); // get sensor value from used analog pin

  float sensorVoltage = (sensorValue / 1024.0) * 5.0; // calculate the sensor's actual output voltage

  float sensorTemp = (sensorVoltage - 0.5) * 100; // calculate the temperature, sensor has 0.5 V offset



  //output in the serial window
  Serial.print("Sensor Value: "); // print the given text
  Serial.print(sensorValue); // print the current sensor value

  Serial.print("; Volts: ");
  Serial.print(sensorVoltage); // print the current sensor output voltage

  Serial.print("; Temperature: ");
  Serial.print(sensorTemp); // print the measured temperature
  Serial.print(" °C");

  Serial.println(); // create new line



  if (sensorTemp < baselineTemp) {
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, LOW);
  }
  else if (sensorTemp >= baselineTemp && sensorTemp < (baselineTemp + 3) ) {
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    digitalWrite(2, HIGH);
  }
  else if (sensorTemp >= (baselineTemp + 3) && sensorTemp < (baselineTemp + 6) ) {
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }
  else if (sensorTemp >= (baselineTemp + 6) ) {
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(2, HIGH);
  }

  delay(1);

}
