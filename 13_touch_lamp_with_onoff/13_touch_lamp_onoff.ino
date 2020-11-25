#include <CapacitiveSensor.h>
CapacitiveSensor cap = CapacitiveSensor(4, 2); // create capacitive sensor as object connected between pin 4 and 2

int threshold = 500; // threshold for sensor input
long sensorValue = 0;
long previousSensorValue = 0;
boolean ledState = LOW;

const int ledPin = 12; // pin number of connected LED



void setup() {
  Serial.begin(9600); // start the serial monitor with 9600 BAUD
  pinMode(ledPin, OUTPUT); // define the pin connected to the LED as output
}



void loop() {
  sensorValue = cap.capacitiveSensor(30); // sample the sensor 30 times
  Serial.println(sensorValue); // display the sensorValue in the serial monitor

  if (sensorValue > previousSensorValue + threshold) { // check if the sensor value is different from before
    ledState = !ledState; // switch on or off the LED
    digitalWrite(ledPin, ledState);
  }

  previousSensorValue = sensorValue; // save the current sensor value for the next loop
  delay(50);
}
