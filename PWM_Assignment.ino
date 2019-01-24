#include <Servo.h>
//I'm not going to make changes in the code, but just the file
Servo name_servo;

void setup() 
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
  name_servo.attach(3);


  //name_servo.write(0);
}

void loop() 
{
  int voltage_value = analogRead(A0);
  delay(1);

  voltage_value = constrain(voltage_value, 5, 1023);
  int level = map(voltage_value, 5, 1023, 5, 255);

  //Serial.println(level);
  
  analogWrite(5, level);
  delay(10);


  level = map(voltage_value, 0, 1023, 0, 360);
  name_servo.write(level);
  
}
