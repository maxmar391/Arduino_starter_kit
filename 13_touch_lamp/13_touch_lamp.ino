#include <CapacitiveSensor.h>
CapacitiveSensor cap = CapacitiveSensor(4, 2); // create capacitive sensor as object connected between pin 4 and 2

int threshold = 1000;
long sensorValue;

const int ledPin = 12;



void setup() {
  Serial.begin(9600); // start the serial monitor with 9600 BAUD
  pinMode(ledPin, OUTPUT); // define the pin connected to the LED as output
}



void loop() {
  sensorValue = cap.capacitiveSensor(30); // sample the sensor 30 times
  Serial.println(sensorValue); // display the sensorValue in the serial monitor

  if (sensorValue > threshold) { // check if the touch sensor was activated
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  delay(10);
}
