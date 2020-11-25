const int switchPin = 8; // pin connected to tilt switch

unsigned long previousTime = 0; // variable to hold the time
unsigned long currentTime = 0; // variable to hold time

int switchState = 0;
int previousSwitchState = 0;

int LEDPin = 2; // pin connected to first LED

long interval = 120000; // time interval of turning on the LEDs in milliseconds


void setup() {
  // put your setup code here, to run once:
  for (int x = 2; x <= 7; x++) { // go through all LED pins
    pinMode(x, OUTPUT); // declare LED pins as output to control the LEDs
  }

  pinMode(switchPin, INPUT); // declare switch pin as input to read switch signal
}




void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis(); // assign currentTime by runtime function millis()

  if (currentTime - previousTime > interval) { // count time with time variables
    previousTime = currentTime;

    digitalWrite(LEDPin, HIGH); // turn on the currently selected LED
    LEDPin++; // switch to next LED

    if (LEDPin == 7) {

    }
  }

  switchState = digitalRead(switchPin); // read out the status of the tilt switch

  if (switchState != previousSwitchState) { // check for change of switch state, that is tilting
    for (int x = 2; x < 8; x++) { // go through all LED pins
      digitalWrite(x, LOW); // turn off all LEDs
    }

    LEDPin = 2; // set LED counter back to first LED connected at pin 2
    previousTime = currentTime; //
  }

  previousSwitchState = switchState;

}
