#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float TempC; //Temperature in C
float TempF; //Temperature in F

// This sketch reds the temperature reading from a 9701 temperature sensor,
// converts the reading to degrees C, converts degrees C to degrees F, and 
// prints the degrees F on a 16 x 2 LCD (Hitachi HD44780).
// If you would prefer a printout in degrees C, then the sketch csn be modified
// to do such very easily.

//The circuit:
// * LCD RS pin to digital pin 12
// * LCD Enable pin to digital pin 11
// * LCD D4 pin to digital pin 5
// * LCD D5 pin to digital pin 4
// * LCD D6 pin to digital pin 3
// * LCD D7 pin to digital pin 2
// * LCD R/W pin to ground
// * LCD VSS pin to ground
// * LCD VCC pin to 5V
// * 10K resistor:
// * ends to +5V and ground
// * wiper to LCD VO pin (pin 3)

void setup() {

lcd.begin(16, 2);
Serial.begin(9600);

}

void loop() {

TempC = analogRead(0) / 204.6; //Pin 0 is the sensor indication-voltage pin.
TempC = TempC - 0.49;
TempC = TempC / 0.0189;  //TempC is now an accurate temp in Celsius
// The "-0.49" is different from the 9701 datasheet.  However, it seemed more accurate.
// The "0.0189" is is different from the 9701 datasheet, but seemed more accurate.

TempF = (9.0/5.0)*TempC + 32.0;

lcd.setCursor(0,0);
lcd.print(TempF);

Serial.println(TempF);
delay(1000);
}
