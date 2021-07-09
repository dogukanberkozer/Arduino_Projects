#define buzzerPin 8 // digital pin of buzzer
#define trigPin 7 // digital pins of ultrasonic sensor
#define echoPin 6

#include <Wire.h> // required libraries for LCD screen
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C LCD(0x27, 16, 2); // LCD with LiquidCrystal_I2C library
 
void setup() {
  pinMode(echoPin, INPUT); // echo pin of the sensor as input
  pinMode(trigPin, OUTPUT); // trig pin of the sensor as output
  pinMode(buzzerPin, OUTPUT); // buzzer is output too

  LCD.init(); // initializing LCD screen
  LCD.backlight(); // opening ground light of the LCD screen

  Serial.begin(9600); // for serial port screen to start communication
}

void loop() {
  int distance = calculateDistance(); // to get distance sensor value
  buzz(distance * 4); // sound frequency
  
  Serial.print("Date: 14.6.2021  -  Distance: "); // to print serial port
  Serial.print(distance);
  Serial.println(" cm.");

  if(distance > 100) // if distance is bigger than 100 cm
  {
    LCD.setCursor(0,0); // start to write from 1st row - 1st column
    LCD.print("Distance > 1 m  ");
    LCD.setCursor(0,1); // start to write from 2nd row - 1st column
    LCD.print("         Too Far");
    Serial.println("It is too far.");
  }else if(distance <= 100 && distance >= 51) // if distance is between 51-100 cm
  {
    LCD.setCursor(0,0); // start to write from 1st row - 1st column
    LCD.print("Distance51-100cm");
    LCD.setCursor(0,1); // start to write from 2nd row - 1st column
    LCD.print("             Far");
    Serial.println("It is far.");
  }else if(distance <= 50 && distance >= 21) // if distance is between 21-50 cm
  {
    LCD.setCursor(0,0); // start to write from 1st row - 1st column
    LCD.print("Distance 21-50cm");
    LCD.setCursor(0,1); // start to write from 2nd row - 1st column
    LCD.print("           Close");
    Serial.println("It is close.");
  }else if(distance <= 20 && distance >= 5) // if distance is between 5-20 cm
  {
    LCD.setCursor(0,0); // start to write from 1st row - 1st column
    LCD.print("Distance 5-20cm ");
    LCD.setCursor(0,1); // start to write from 2nd row - 1st column
    LCD.print("       Too Close");
    Serial.println("It is too close.");
  }else  // if distance is lower than 5 cm
  {
    LCD.setCursor(0,0); // start to write from 1st row - 1st column
    LCD.print("Distance < 5 cm ");
    LCD.setCursor(0,1); // start to write from 2nd row - 1st column
    LCD.print("         Crashed");
    Serial.println("It is crashed.");
  }
}

int calculateDistance()
{
  long duration, distance; // to get calculate distance

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2; // speed of the sound
  delay(50);

  return distance;
}

int buzz(int x)
{
  tone(buzzerPin, 440); // 440 is tune of the sound, it could be changed
  delay(x);
  noTone(buzzerPin); // to shutdown buzzer sound
  delay(x);
}

/*
 * REFERENCES
 * https://www.youtube.com/watch?v=l0QvSxzHtvk
 * https://maker.robotistan.com/arduino-ile-basit-park-sensoru-yapimi/
 * https://www.hobidevre.com/330r-1watt#:~:text=Turuncu%20-%20Turuncu%20-%20Kahverengi%20-%20Alt%C4%B1n
 */
