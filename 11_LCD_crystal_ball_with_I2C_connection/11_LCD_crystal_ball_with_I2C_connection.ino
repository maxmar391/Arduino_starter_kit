#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int switchPin = 6;
int switchState = 0;
int previousSwitchState = 0;
int reply;



void setup() {
  pinMode(switchPin, INPUT); // define the pin connected to the switch as input

  lcd.init(); // initialize the LCD
  lcd.backlight(); // turn on the backlight

  lcd.setCursor(0, 0); // jump to the beginning of the first row of the LCD
  lcd.print("Frag' die"); // print the given text in the first row of the LCD
  lcd.setCursor(0, 1); // jump to the beginning of the next row
  lcd.print("Kristallkugel!"); // print the given text in the second row of the LCD
}



void loop() {
  delay(2000); // wait for 2 s

  reply = random(9); // generate random number (0 to 8) and store in the variable "reply"

  lcd.clear(); // clear the LCD
  lcd.setCursor(0, 0); // jump to the beginning of the first row of the LCD
  lcd.print("Die Kugel sagt:"); // print the given text
  lcd.setCursor(0, 1); // jump to the beginning of the second row of the LCD

  switch (reply) { // print the given text depending of the random number in the variable reply
    case 0:
      lcd.print("Ja");
      break;

    case 1:
      lcd.print("Wahrscheinlich");
      break;

    case 2:
      lcd.print("Sicher");
      break;

    case 3:
      lcd.print("gute Aussichten");
      break;

    case 4:
      lcd.print("Unsicher");
      break;

    case 5:
      lcd.print("Frag' nochmal");
      break;

    case 6:
      lcd.print("Zweifelhaft");
      break;

    case 7:
      lcd.print("Nein");
      break;

    case 8:
      lcd.print("Warte ab");
      break;
  }
}
