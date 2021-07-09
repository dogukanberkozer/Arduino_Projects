#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define TIME_LED_COUNTER 500
#define TIME_LED_SLIDER 250
#define Button 8

void setup() {
  // put your setup code here, to run once:
  
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);

  pinMode(Button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(Button) == 1){
    digitalWrite(pin2,LOW); // 0 - 0000
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,LOW); // 1 - 0001
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,HIGH);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,LOW); // 2 - 0010
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,LOW); // 3 - 0011
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,HIGH);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,LOW); // 4 - 0100
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,LOW); // 5 - 0101
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,HIGH);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,LOW); // 6 - 0110
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,LOW); // 7 - 0111
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,HIGH);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,HIGH); // 8 - 1000
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,HIGH); // 9 - 1001
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,HIGH);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,HIGH); // 10 - 1010
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,HIGH); // 11 - 1011
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,HIGH);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,HIGH); // 12 - 1100
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,HIGH); // 13 - 1101
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,HIGH);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,HIGH); // 14 - 1110
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_COUNTER);
    
    digitalWrite(pin2,HIGH); // 15 - 1111
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,HIGH);
    delay(TIME_LED_COUNTER);
  }
  else{
    digitalWrite(pin2,LOW); // X X O X
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_SLIDER);
  
    digitalWrite(pin2,LOW); // X O X X
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_SLIDER);
  
    digitalWrite(pin2,HIGH); // O X X X
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_SLIDER);
  
    digitalWrite(pin2,LOW); // X O X X
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_SLIDER);
  
    digitalWrite(pin2,LOW); // X X O X
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    digitalWrite(pin5,LOW);
    delay(TIME_LED_SLIDER);
  
    digitalWrite(pin2,LOW); // X X X O
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    digitalWrite(pin5,HIGH);
    delay(TIME_LED_SLIDER);
  }
}
