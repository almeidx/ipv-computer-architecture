#include <Servo.h>

#define SERVO_PIN 11
#define BUTTON_INCREASE 3
#define BUTTON_DECREASE 2

Servo servo;

volatile float _speed = 0;

const int delays[] = {1000, 750, 500, 400};

void setup(){
  servo.attach(SERVO_PIN);

  attachInterrupt(digitalPinToInterrupt(BUTTON_INCREASE), increase, CHANGE);
  attachInterrupt(digitalPinToInterrupt(BUTTON_DECREASE), decrease, CHANGE);
}

void increase() {
  if (_speed != 4.0f) _speed += 0.5f;
}

void decrease() {
  if (_speed != 0.0f) _speed -= 0.5f;
}

void loop() {
  servo.write(0);

  if (_speed == 0) return;

  int x = delays[(int)ceilf(_speed) - 1];

  delay(x);

  servo.write(180);
  delay(x);
}
