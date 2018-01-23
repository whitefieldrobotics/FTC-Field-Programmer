/*

  FTC Field Programmer

  This device is designed to help any and all FTC programmers. THis device can test servos as well as help you program them. 

  -By: Simon McNutt

   if you have any questions please contact me at simon.mcnutt@students.whitefield.org
  
 
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
 * Left button to pin 8
 * Right button to pin 9
 * OK button to pin 13
 * Cancel button to pin 7
 * Servo Output to pin 6
 * servo Input to pin 10
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
  lcd.print("Servo Programmer V1.2");
  lcd.setCursor(0, 1);
  lcd.print("1.1 By:Team#4444");

  delay(2500);
  lcd.setCursor(0, 0);
  lcd.print("Press any button");  

  Serial.begin(9600);
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
      if (digitalRead(buttonLeft) == HIGH){
        pos = pos+1;
        lcd.clear();
      }
      if (digitalRead(buttonRight) == HIGH){
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
      lcd.print("Starting Value?");

      lcd.setCursor(0,1);
      lcd.print("FTC Value=");
      lcd.setCursor(10,1);
      lcd.print(((-1.0/180)*pos)+1);


      myservo.write(pos);
      delay(50);
    }

delay (500);
    
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
      Serial.println(pos);
      
    }
    flag=3;
  }
}

