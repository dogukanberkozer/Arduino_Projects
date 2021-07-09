#include <Wire.h> // required libraries
#include <LiquidCrystal_I2C.h>

#define Button 8 // button gidital pwm is 8

int TIME_SCREEN_CLOCK = 2000;
int TIME_SCREEN_INFO = 1000;
String TIME_STRING = "2021.05.01 - 14:34:56";

bool isEnglish = true;

LiquidCrystal_I2C LCD(0x27, 16, 2); // LCD with LiquidCrystal_I2C library

void setup() {
  pinMode(Button, INPUT); // button as input
  
  LCD.init(); // initializing LCD screen
  LCD.backlight(); // opening ground light of the LCD screen

  int hour = TIME_STRING.substring(13, 15).toInt(); // split the TIME_STRING variable
  int minute = TIME_STRING.substring(16, 18).toInt();
  int second = TIME_STRING.substring(19, 21).toInt();
  int year = TIME_STRING.substring(0, 4).toInt();
  int month = TIME_STRING.substring(5, 7).toInt();
  int day = TIME_STRING.substring(8, 10).toInt();
}

void loop() {

  if(isEnglish == true){
    
    englishClock();
    delay(TIME_SCREEN_CLOCK);
    /*second += 2; if second is 60 or high, must to update current time
    if(second > 59){
      second = second % 60;
      updateTime();
    }*/

    englishInfo();
    delay(TIME_SCREEN_INFO);
    /*second += 1; if second is 60 or high, must to update current time
    if(second > 59){
      second = second % 60;
      updateTime();
    }*/
    
  } else{

    turkishClock();
    delay(TIME_SCREEN_CLOCK);
    /*second += 2; if second is 60 or high, must to update current time
    if(second > 59){
      second = second % 60;
      updateTime();
    }*/

    turkishInfo();
    delay(TIME_SCREEN_INFO);
    /*second += 1; if second is 60 or high, must to update current time
    if(second > 59){
      second = second % 60;
      updateTime();
    }*/
  }

  if(digitalRead(Button) == 1){
    if(isEnglish == true){
      isEnglish = false;
    }else{
      isEnglish = true;
    }
  }
}

void englishClock(){ // english clock screen
    LCD.setCursor(0,0); // start to write from 1st row - 1st column
    LCD.print("02:34:56 PM  ENG");
  
    LCD.setCursor(0,1); // start to write from 2nd row - 1st column
    LCD.print("01.05.2020   SAT");
}

void turkishClock(){ // turkish clock screen
    LCD.setCursor(0,0); // start to write from 1st row - 1st column
    LCD.print("14:34:56     TUR");
  
    LCD.setCursor(0,1); // start to write from 2nd row - 1st column
    LCD.print("01.05.2020   CMT");
}


void englishInfo(){ // english info screen
    LCD.setCursor(0,0); // start to write from 1st row - 1st column
    LCD.print("HH:MM:SS 12H LNG");
  
    LCD.setCursor(0,1); // start to write from 2nd row - 1st column
    LCD.print("DD.MM.YYYY   DOW");
}

void turkishInfo(){ // turkish info screen
    LCD.setCursor(0,0); // start to write from 1st row - 1st column
    LCD.print("SA:DA:SN 24H DIL");
  
    LCD.setCursor(0,1); // start to write from 2nd row - 1st column
    LCD.print("GG.AA.YYYY   GUN");
}

void updateTime(int minute, int hour, int day, int month, int year){ // if second is higher than 59, time will updated
  minute++;
  
  if(minute > 59){ // if minute is 60, then minute must be 0 and hour increases 1
    minute = 0;
    hour++;
    
    if(hour > 23){ // if hour is 24, then hour must be 0 and day increases 1
      hour = 0;
      day++;
      
      if(day > 30){ // if day is 31, then day must be 0 and month increases 1
        day = 0;
        month++;
        
        if(month > 12){ // if month is 13, then month must be 0 and year increases 1
          month = 0;
          year++;
        }
      }
    }
  }
}

/*REFERENCES
 * https://maker.robotistan.com/arduino-ile-buton-ve-led-uygulamasi/
 * https://www.youtube.com/watch?v=l0QvSxzHtvk
 * https://www.youtube.com/watch?v=EPhRzlJW7Eg
 */
