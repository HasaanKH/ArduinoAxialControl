#include <Servo.h>

#define joystick 0
#define servoPin 2
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
  myServo.write(0); //center
  pinMode(joystick, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int Vx = analogRead(joystick);
  MoveServo(Vx);
}

void MoveServo(int Vx) {
  float displacement = 180.0/1024.0 * Vx;
  if(Vx <= 480)
  {
    Serial.println(displacement);
    myServo.write((int)displacement);
  }
  else if (Vx >= 520)
  {
    Serial.println(displacement);
    myServo.write(0 + (int)displacement);
  }
  else{
    myServo.write(90);
  }

}
