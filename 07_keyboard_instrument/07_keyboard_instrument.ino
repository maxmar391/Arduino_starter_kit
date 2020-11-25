int notes[] = {262, 294, 330, 349}; // set the frequencies for the tones to be played

int keyValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  keyValue = analogRead(A0); // read the voltage from analog input A0 and store it in the variable keyValue
  Serial.print(keyValue); // write keyValue in the serial window
  Serial.println(); // new line in serial window

  // check the value at the analog input and decide which tone to play based on the voltage input
  if (keyValue == 1023) {
    tone(8, notes[0]);
  }
  else if (keyValue <= 1010 && keyValue >= 990) {
    tone(8, notes[1]);
  }
  else if (keyValue <= 515 && keyValue >= 505) {
    tone(8, notes[2]);
  }
  else if (keyValue <= 10 && keyValue >= 5) {
    tone(8, notes[3]);
  }
  else {
    noTone(8);
  }
  delay(10);
}
