#include <Servo.h>
Servo myServo;

// define the input and output pins of all connected components
const int piezo = A0;
const int switchPin = 2;
const int redLED = 5;
const int yellowLED = 4;
const int greenLED = 3;
const int servoPin = 9;

// define variables for the values delivered by the piezo and switch button
int knockValue;
int switchValue;

// define threshold values for knock sound
const int quietKnock = 20;
const int loudKnock = 200;

boolean locked = false;
int numberOfKnocks = 0;
const int necessaryNumberOfKnocks = 4;



void setup() {
  myServo.attach(servoPin); // define connection of servo

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(switchPin, INPUT);

  Serial.begin(9600); // initialize serial monitor

  digitalWrite(greenLED, HIGH); // turn on the green LED to signal status "unlocked"
  myServo.write(0); // set the servo to position zero
  Serial.println("The box is unlocked!"); // send text to serial monitor and start new line
}



void loop() {
  if (locked == false) {
    switchValue = digitalRead(switchPin); // read the button
    if (switchValue == HIGH) { // check, if the button is pressed
      locked = true; // change status to locked
      digitalWrite(greenLED, LOW);  // turn off green LED
      digitalWrite(redLED, HIGH); // turn on red LED to signal status "locked"
      myServo.write(90); // turn the servo to 90 degrees position to lock
      Serial.println("The box is locked now!"); // send the text to serial monitor and start new line
      delay(1000); // wait for 1000 ms
    }
  }

  if (locked == true) {
    knockValue = analogRead(piezo); // read the piezo input

    if (numberOfKnocks < necessaryNumberOfKnocks && knockValue > 0) {
      if (checkForKnock(knockValue) == true) {
        numberOfKnocks++;
      }
      Serial.print(necessaryNumberOfKnocks - numberOfKnocks); // display missing number of knocks
      Serial.println(" more knocks to go"); // send the text to the serial monitor and start new line
    }

    if (numberOfKnocks >= necessaryNumberOfKnocks) {
      numberOfKnocks = 0; // reset the counter
      locked = false; // set status to "unlocked"
      myServo.write(0); // move servo to zero position to unlock
      delay(100); // wait for 100 ms
      digitalWrite(greenLED, HIGH); // turn on green LED to signal status "unlocked"
      digitalWrite(redLED, LOW); // turn off red LED
      Serial.println("The box is unlocked!"); // send the text to the serial monitor and start new line
    }
  }
}



// define the custom function checkForKnock
boolean checkForKnock(int value) {
  if (value > quietKnock && value < loudKnock) { // check, if the value is between the threshold values and thus valid

    Serial.print("Valid knock of value ");
    Serial.println(value); // print the knock value in the Serial monitor
    digitalWrite(yellowLED, HIGH); // turn on yellow LED to indicate valid knock
    delay(100);
    digitalWrite(yellowLED, LOW); // turn off yellow lED
    return true; // function returns true for valid knock
  }

  else {
    Serial.print("Invalid knock value ");
    Serial.println(value); // print the knock value in the Serial monitor
    return false; // function returns false for invalid knock
  }
}
