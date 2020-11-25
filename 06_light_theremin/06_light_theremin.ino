int sensorValue; // define the variable to store the sensor's output value
int sensorLow = 1023; // define the high and low limits of the sensor
int sensorHigh = 0;
int pitch; // define the variable to store the output value for the speaker

const int indicatorPin = 13; // define indicator for completion of sensor calibration (built-in LED on pin 13)
const int speakerPin = 8; // define the pin of the speaker
const int sensorPin = A0; // define the pin reading the sensor's value

// *******************************************************************
void setup() {
  // put your setup code here, to run once:
  pinMode(indicatorPin, OUTPUT); // define pin 13 as output to drive the built-in LED
  digitalWrite(indicatorPin, HIGH); // turn on LED

  // calibration of sensor
  while (millis() < 5000) { // while loop for 5 s
    sensorValue = analogRead(sensorPin); // read the sensor's output value

    if (sensorValue > sensorHigh) { // compare the sensor's value to the current limits and adjust if different
      sensorHigh = sensorValue;
    }

    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  digitalWrite(indicatorPin, LOW); // turn off the built-in LED to signal completion of calibration
}

// ******************************************************************* 
void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin); // read the sensor's output value

  pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000); // map the input values of the sensor to the possible output values for the speaker

  tone(speakerPin, pitch, 20); // send output value to the speaker pin, with pitch as frequency and 20 ms duration

  delay(10); // wait for 10 ms to give the tone some time to play
}
