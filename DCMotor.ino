const int btnPin = 2; // number of the pushbutton pin
int btnState = 0; // to read the pushbutton status

int ENA = 5; // ENA pin on the motor driver is connected to 5th pin of the arduino uno
int in1 = 6; // IN1, IN2 pins on the driver are wired to pin 6 and 7 on arduino 
int in2 = 7;
int speedDC; // this variable is speed of the dc motor

void setup() { // references of input and outputs in the system
  
  pinMode(btnPin, INPUT); // initialize the pushbutton pin as input
  
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);    
}

void loop() {

  btnState = digitalRead(btnPin); // reading state of the pushbutton value
  
  digitalWrite(in1, LOW); // to change direction
  digitalWrite(in2, HIGH);
  
  speedDC= analogRead(A5); // to change speed, left pin of the potentiometer is wired to A5 on arduino
  speedDC = speedDC * 0.2492668622; // calibrate the value from potentiometer

  if (btnState == HIGH) { // if the pushbutton is pressed, the buttonState is HIGH
    speedDC = speedDC * -1; // change the direction of the DC motor
  }
  
  analogWrite(ENA, speedDC); // injecting to the DC motor
}

// REFERENCES
// https://www.arduino.cc/en/tutorial/pushbutton
// https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
// https://www.youtube.com/watch?v=OjRtGEwQDYg
// https://kodlabafra.org/2019/04/26/arduino-ile-l298n-motor-surucu-kullanimi/#:~:text=L298N%20arduino%20kullanarak%20motor%20h%C4%B1z,arduino%20PWM%20pinlerinden%20birine%20ba%C4%9Flanmal%C4%B1d%C4%B1r.
