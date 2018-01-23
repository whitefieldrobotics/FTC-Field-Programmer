/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

const int buttonLeft = 8;     // the number of the pushbutton pin
const int buttonRight = 9;     // the number of the pushbutton pin
const int ok = 13;     // the number of the pushbutton pin


int pos = 0;
int flag =3;
int flag2 =0;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
   myservo.attach(6);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(ok, INPUT);


  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Servo Programmer V1.1");
  lcd.setCursor(0, 1);
  lcd.print("1.1 By:Team#4444");

  delay(2500);
  lcd.setCursor(0, 0);
  lcd.print("Press any button");



  
}

void loop() {


  
while (digitalRead(buttonLeft) != HIGH & digitalRead(buttonRight) != HIGH & digitalRead(ok) != HIGH ){ 
}
  lcd.clear();
   lcd.setCursor(0, 0);
  lcd.print("Program Select:");
  lcd.setCursor(0, 1);
  lcd.print("#1AngleConverter");
  delay(500);

  while (digitalRead(ok) == LOW){
    if (digitalRead(buttonRight)){
     flag = 2;
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Program Select:");
     lcd.setCursor(0, 1);
     lcd.print("#2SweepTest");
    }
    if (digitalRead(buttonLeft)){
      flag = 3;
     lcd.clear();
     lcd.setCursor(0, 0);
     lcd.print("Program Select:");
     lcd.setCursor(0, 1);
     lcd.print("#1AngleConverter");
    }
  }

  delay(500);

  if (flag == 2){
    lcd.clear();
    while (digitalRead(ok) == LOW){
      if(digitalRead(buttonRight) == HIGH){
        pos = 180;
      }
      if(digitalRead(buttonLeft) == HIGH){
        pos = 0;        
      }
     myservo.write(pos);
     lcd.setCursor(0, 0);
     lcd.print("Position is at:");
     lcd.setCursor(0, 1);
     if (pos > 90){
     lcd.print("max");
     }else{
     lcd.print("min");
     }


    }
    flag = 3;
  }
  
  if (flag == 3){
    lcd.clear();
    while (digitalRead(ok) == LOW){
      if (digitalRead(buttonRight) == HIGH){
        pos = pos+1;
        lcd.clear();
      }
      if (digitalRead(buttonLeft) == HIGH){
        pos = pos-1;
        lcd.clear();
      }

      if (pos > 180){
        pos = pos -1;
      }

      if (pos < 0){
        pos = pos +1;
      }

      lcd.setCursor(0, 0);
      lcd.print("Angle Value=");
      lcd.setCursor(12, 0);
      lcd.print(pos);

      lcd.setCursor(0,1);
      lcd.print("FTC Value=");
      lcd.setCursor(10,1);
      lcd.print(((-1.0/180)*pos)+1);


      myservo.write(pos);
      delay(50);
    }
    flag=3;
  }
}

