#include <Wire.h> 
//#include <LiquidCrystal_I2C.h>
int rainsense= A0;  // analog sensor input pin 0
int ldrPin = A1; 
int buzzerout= 10;  // digital output pin 10 - buzzer output
int countval= 0;  // counter value starting from 0 and goes up by 1 every second
int ledout= 11; // digital output pin 11 - led output



//Definitions



void setup() {

   Serial.begin(9600);
   pinMode(buzzerout, OUTPUT);
   pinMode(ledout, OUTPUT); 
    pinMode(ldrPin, OUTPUT); 
   pinMode(rainsense, INPUT);
   
  //motor driver controls
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);


  //Setup the LCD Display
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);

  

}

void loop() {

   //Read the data from the 
   int rainSenseReading = analogRead(rainsense);
   int ldrStatus = analogRead(ldrPin); //saving the analog values received from LDR

   Serial.println(rainSenseReading);  // serial monitoring message 
   Serial.println(ldrStatus);  // serial monitoring message 



    if(rainSenseReading <450){
//
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Raning!");

        //Rotate motor anticlockwise
          digitalWrite(4, HIGH);
          delay(1000);
          digitalWrite(4, LOW);

          digitalWrite(buzzerout, HIGH);  // turn off buzzer 
      
      }
      else if((rainSenseReading > 450) or (ldrStatus > 600)){

            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Sunny!");

            
            digitalWrite(5, HIGH);
            delay(1000);
            digitalWrite(5, LOW);

                digitalWrite(buzzerout, LOW);  // turn off buzzer 
        }
        else if(ldrStatus < 600){
             lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Evening!");

          digitalWrite(4, HIGH);
          delay(1000);
          digitalWrite(4, LOW);
          
          }
}
