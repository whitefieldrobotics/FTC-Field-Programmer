 /*

  FTC Field Programmer

  This device is designed to help any and all FTC programmers. This device can test servos as well as help you program them. 

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
Servo inputServo;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

const int buttonLeft = 8;     // the number of the pushbutton pin
const int buttonRight = 9;     // the number of the pushbutton pin
const int ok = 13;     // the number of the pushbutton pin
const int cancel = 7;     // the number of the pushbutton pin



int pos = 0;
int menu = 1;
int about =1;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
   myservo.attach(6);  // attaches the servo on pin 9 to the servo object
   inputServo.attach(10);  // attaches the servo on pin 9 to the servo object
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(ok, INPUT);
  pinMode(cancel, INPUT);


  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Field Programmer ");
  lcd.setCursor(0, 1);
  lcd.print("1.3 By:Team#4444");

  delay(2500);
  lcd.setCursor(0, 0);
  lcd.print("Press any button");  

  Serial.begin(9600);
}

void loop() {


  
while (digitalRead(buttonLeft) != HIGH & digitalRead(buttonRight) != HIGH & digitalRead(ok) != HIGH & digitalRead(cancel) != HIGH){ 

}
lcd.clear();
delay(200);
while (digitalRead(ok) == LOW){
  if (menu < 1){
    menu = menu +1;
  }
  if (menu > 6){
    menu = menu -1;
  }

  if (digitalRead(buttonLeft) == HIGH){
    menu = menu -1;
    delay(150);
  }
  if (digitalRead(buttonRight) == HIGH){
    menu = menu +1;
    delay(150);
  }

  if (menu ==1){
     lcd.setCursor(0, 0);
     lcd.print("Program Select:");
     lcd.setCursor(15, 0);
     lcd.print(menu);
     lcd.setCursor(0, 1);
     lcd.print("AngleConverter");
  }else{
    if (menu == 2){
     lcd.setCursor(0, 0);
     lcd.print("Program Select:");
     lcd.setCursor(15, 0);
     lcd.print(menu);
     lcd.setCursor(0, 1);
     lcd.print("SweepTest       ");
    }else{
      if (menu == 3){
     lcd.setCursor(0, 0);
     lcd.print("Program Select:");
     lcd.setCursor(15, 0);
     lcd.print(menu);
     lcd.setCursor(0, 1);
     lcd.print("AttachmentTester");
      }else{
       if (menu == 4){
     lcd.setCursor(0, 0);
     lcd.print("Program Select:");
     lcd.setCursor(15, 0);
     lcd.print(menu);
     lcd.setCursor(0, 1);
     lcd.print("MonitorInput    ");
       }else{
       if (menu == 5){
     lcd.setCursor(0, 0);
     lcd.print("Program Select:");
     lcd.setCursor(15, 0);
     lcd.print(menu);
     lcd.setCursor(0, 1);
     lcd.print("MirrorInput     ");
       }else{
       if(menu == 6){
     lcd.setCursor(0, 0);
     lcd.print("Program Select:");
     lcd.setCursor(15, 0);
     lcd.print(menu);
     lcd.setCursor(0, 1);
     lcd.print("About           ");
       }
       }
       }
      }
    }
  }  
}

delay(100);

if(menu ==1){
  AngleFinder();
}
if(menu ==2){
  SweepTest();
}
if(menu == 3){
  AttachmentTester();
}
if(menu ==4){
  MonitorInput();
}
if(menu == 5){
  MirrorInput();
}
if (menu == 6){
  About();
}


}
   void About(){
    lcd.clear();
    while (digitalRead(cancel)==LOW){
       if(digitalRead(buttonLeft)== HIGH &digitalRead(ok)== HIGH & digitalRead(buttonRight)== HIGH ){
         lcd.setCursor(0,0);
         lcd.print("Homecoming?     ");
         lcd.setCursor(0,1);
         lcd.print("                ");
       }

         Serial.print("here");
         lcd.setCursor(0,0);
         lcd.print("HardwareSoftware");
         lcd.setCursor(0,1);
         lcd.print("SV1.3 HV1.0     ");
         delay(2000);
         lcd.setCursor(0,0);
         lcd.print("Author          ");
         lcd.setCursor(0,1);
         lcd.print("Simon Mcnutt    ");
         delay(3000);
         lcd.setCursor(0,0);
         lcd.print("Team Info");
         lcd.setCursor(0,1);
         lcd.print("Robocats #4444  ");
         delay(3000);
     }
   }

   void AngleFinder(){
    pos =90;
    lcd.clear();
        while (digitalRead(cancel) == LOW){
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
   }

   void SweepTest(){
    lcd.clear();
    while (digitalRead(cancel) == LOW){
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
}

   void AttachmentTester(){
    int test = 0;
    lcd.clear();
    pos = 90;
    while (digitalRead(cancel)== LOW ){
      while (digitalRead(ok) == LOW& test == 0   ){

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
      lcd.print("ChooseStartValue");
      lcd.setCursor(0,1);
      lcd.print("Value:1        ");
      myservo.write(pos);
      delay(50);
        
      }
    }
    test = 1;
    delay(300);

      while (digitalRead(ok) == LOW & test == 1){

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
      lcd.print("ChooseStartValue");
      lcd.setCursor(0,1);
      lcd.print("Value:2        ");
      myservo.write(pos);
      delay(50);
       
      
    }
    test = 2;   

    lcd.clear();
    lcd.print("lol");
   }

   void MonitorInput(){
    lcd.clear();
    int inputValue = 0;
    while (digitalRead(cancel)==LOW){

      inputValue = inputServo.read();
      
      lcd.setCursor(0, 0);
      lcd.print("Angle Value=");
      lcd.setCursor(12, 0);
      lcd.print(inputValue);
      lcd.setCursor(0,1);
      lcd.print("FTC Value=");
      lcd.setCursor(10,1);
      lcd.print(((-1.0/180)*inputValue)+1);
      delay(50);

    }
   }

    void MirrorInput(){
    lcd.clear();
    while (digitalRead(cancel)==LOW){
      
    }
   }


