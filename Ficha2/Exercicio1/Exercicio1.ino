#define GREEN_LED 10
#define YELLOW_LED 11
#define RED_LED 12

#define GREEN_DELAY 11000
#define YELLOW_DELAY 4000
#define RED_DELAY 7000

int current = RED_LED;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  int _delay;

  switch (current) {
    case GREEN_LED:
      current = YELLOW_LED;
      _delay = YELLOW_DELAY;
      break;
    case YELLOW_LED:
      current = RED_LED;
      _delay = RED_DELAY;
      break;
    case RED_LED:
      current = GREEN_LED;
      _delay = GREEN_DELAY;
      break;
  }

  digitalWrite(current, HIGH);
  delay(_delay);
  digitalWrite(current, LOW);
}
