#include <Servo.h>

#define SERVO_PIN 6
#define TRIG_PIN 9
#define ECHO_PIN 10

Servo radarServo;

float getDistance() {

  long duration;
  float distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);

  distance = duration * 0.0343 / 2;

  return distance;
}

void setup() {

  Serial.begin(9600);

  radarServo.attach(SERVO_PIN);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {

  for (int angle = 0; angle <= 180; angle++) {

    radarServo.write(angle);
    delay(20);

    float distance = getDistance();

    // Structured radar output
    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }

  for (int angle = 180; angle >= 0; angle--) {

    radarServo.write(angle);
    delay(20);

    float distance = getDistance();

    Serial.print(angle);
    Serial.print(",");
    Serial.println(distance);
  }
}