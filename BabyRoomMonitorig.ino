#include <DHT.h> // DHT11 library

int DhtPin = 2; // DigitalPin2 as DHT11 sensor signal pin
DHT Dht(DhtPin, DHT11); // DHT object is created as named Dht

String TIME_STRING = "2021.05.01 - 14:34:56";

void setup() {
  // put your setup code here, to run once:
  Dht.begin();
  Serial.begin(9600); // starts serial communication

  int hour = TIME_STRING.substring(13, 15).toInt(); // split the TIME_STRING variable
  int minute = TIME_STRING.substring(16, 18).toInt();
  int second = TIME_STRING.substring(19, 21).toInt();
}

void loop() {
  // put your main code here, to run repeatedly:
  float Humidity = Dht.readHumidity(); // gets humidity value
  float Temperature = Dht.readTemperature();  // gets temperature value
  int Light = analogRead(A0); // to read light sensor signal

  Serial.print("  Date: 03.06.2021  -  Hour: ");
  //Serial.print(hour);
  Serial.print(":");
  //Serial.print(minute);
  Serial.print("  Light: ");
  Serial.print(Light);
  Serial.print("  -  Temperature: ");
  Serial.print(Temperature);
  Serial.print("°C  -  Humidity: ");
  Serial.print(Humidity);
  Serial.println("%");

  if(Light > 375){ // when light is day
    
    Serial.print("  Day  -  ");
    
    if(Temperature < 30){ // under 30 is cold in day
      Serial.print("Cold  -  ");
    }else if(Temperature >= 30 && Temperature < 40){ // between 30-40 is optimal temperature in day
      Serial.print("Optimal temperature  -  ");
    }else{
      Serial.print("Hot  -  "); // higher than 40 is high temperature in day
    }

    if(Humidity > 48){  // higher than 48 is high umidity
      Serial.println("High humidity");
    }else if(Humidity <= 48 && Humidity > 33){ // between 48-33 is optimal umidity in day
      Serial.println("Optimal humidity");
    }else{
      Serial.println("Low humidity"); // under 33 is low humidity in day
    }
    
  }else{ // when light is low it means at night
    
    Serial.print("  Night  -  ");

    if(Temperature < 29){ // under 29 is cold at night
      Serial.print("Cold  -  ");
    }else if(Temperature >= 29 && Temperature < 38){ // between 29-39 is optimal temp at night
      Serial.print("Optimal temperature  -  ");
    }else{
      Serial.print("Hot  -  "); // higher than 38 is hot temp
    }

    if(Humidity > 45){ //hiher than 45 is high humidity at night
      Serial.println("High humidity");
    }else if(Humidity <= 45 && Humidity > 30){
      Serial.println("Optimal humidity"); // between 45-30 is optimal humidity at night
    }else{
      Serial.println("Low humidity"); // under 30 is low humidity at night
    }
    
  }
  
  delay(3000);
  /*second += 3; // to update time
  if(second > 59){
    updateTime();
  }*/
}

void updateTime(int minute, int hour){ // if second is higher than 59, time will updated
  minute++;
  
  if(minute > 59){ // if minute is 60, then minute must be 0 and hour increases 1
    minute = 0;
    hour++;
    
    if(hour > 23){ // if hour is 24, then hour must be 0 and day increases 1
      hour = 0;
    }
  }
}

/*REFERENCES
 * https://maker.robotistan.com/arduino-ldr-devresi/
 * https://maker.robotistan.com/arduino-dersleri-7-analog-girisler/
 * https://www.youtube.com/watch?v=YzZLZOHe37Y
 */
