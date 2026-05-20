#include <Servo.h>
Servo radarServo;
void setup() {radarServo.attach(6);
  // Servo signal wire on pin 6

}

void loop() {
  // Move from 0 to 180 degrees 
  for (int pos = 0; pos<= 180; pos++){radarServo.write(pos);
  delay(15);
  }

  // Move back from 180 to 0 degrees
  for (int pos = 180; pos >=0; pos--) {radarServo.write(pos);
  delay(15);
   }
}