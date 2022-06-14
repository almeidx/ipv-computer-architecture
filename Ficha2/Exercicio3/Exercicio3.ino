#define GREEN_LED 10
#define YELLOW_LED 11
#define RED_LED 12
#define PEDESTRIAN_GREEN_LED 6
#define PEDESTRIAN_RED_LED 7
#define BUTTON 2

#define GREEN_DELAY 11000
#define YELLOW_DELAY 4000
#define RED_DELAY 7000

int current = RED_LED;
volatile int state = LOW;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  pinMode(PEDESTRIAN_GREEN_LED, OUTPUT);
  pinMode(PEDESTRIAN_RED_LED, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON), toggle, CHANGE);
}

void toggle() {
  state = !state;
}

void blink(int led) {
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(led, HIGH);
  delay(500);
}

void loop() {
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(PEDESTRIAN_RED_LED, HIGH);

  int tempo = 0;
  while (state == LOW && tempo < 10000) {
    delay(10);
    tempo += 10; 
  }

  blink(GREEN_LED);
  digitalWrite(GREEN_LED, LOW);

  blink(YELLOW_LED);
  blink(YELLOW_LED);
  digitalWrite(YELLOW_LED, LOW);

  digitalWrite(RED_LED, HIGH);

  blink(PEDESTRIAN_RED_LED);
  digitalWrite(PEDESTRIAN_RED_LED, LOW);

  digitalWrite(PEDESTRIAN_GREEN_LED, HIGH);

  delay(RED_DELAY - 2000);

  blink(PEDESTRIAN_GREEN_LED);
  digitalWrite(PEDESTRIAN_GREEN_LED, LOW);

  digitalWrite(PEDESTRIAN_RED_LED, HIGH);

  blink(RED_LED);
  digitalWrite(RED_LED, LOW);

  state = LOW;
}
