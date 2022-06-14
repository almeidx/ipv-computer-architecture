#define GREEN_LED A2
#define YELLOW_LED A1
#define RED_LED A0
#define PEDESTRIAN_GREEN_LED A4
#define PEDESTRIAN_RED_LED A3

#define BUTTON 2

#define GREEN_DELAY 11000
#define YELLOW_DELAY 4000
#define RED_DELAY 7000

#define MIDDLE_LIGHT 9
#define DOT_LIGHT 8
#define BOTTOM_RIGHT_LIGHT 7
#define TOP_RIGHT_LIGHT 6
#define TOP_LIGHT 5
#define TOP_LEFT_LIGHT 4
#define BOTTOM_LEFT_LIGHT 3
#define BOTTOM_LIGHT A5

volatile int state = LOW;

int lights[7][8] = {
// o estado de cada led, para cada numero
//A5, 3, 4, 5, 6, 7, 8, 9
  {0, 0, 0, 0, 1, 1, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 0, 1}, // 2
  {1, 0, 0, 1, 1, 1, 0, 1}, // 3
  {0, 0, 1, 0, 1, 1, 0, 1}, // 4
  {1, 0, 1, 1, 0, 1, 0, 1}, // 5
  {1, 1, 1, 1, 0, 1, 0, 1}, // 6
  {0, 0, 0, 1, 1, 1, 0, 0}  // 7
};

void setup() {
  pinMode(MIDDLE_LIGHT, OUTPUT);
  pinMode(DOT_LIGHT, OUTPUT);
  pinMode(BOTTOM_RIGHT_LIGHT, OUTPUT);
  pinMode(TOP_RIGHT_LIGHT, OUTPUT);
  pinMode(TOP_LIGHT, OUTPUT);
  pinMode(TOP_LEFT_LIGHT, OUTPUT);
  pinMode(BOTTOM_LEFT_LIGHT, OUTPUT);
  pinMode(BOTTOM_LIGHT, OUTPUT);

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

void displayNumber(int i) {
  int j = 6 - i;
  digitalWrite(BOTTOM_LIGHT, lights[j][0]);
  digitalWrite(BOTTOM_LEFT_LIGHT, lights[j][1]);
  digitalWrite(TOP_LEFT_LIGHT, lights[j][2]);
  digitalWrite(TOP_LIGHT, lights[j][3]);
  digitalWrite(TOP_RIGHT_LIGHT, lights[j][4]);
  digitalWrite(BOTTOM_RIGHT_LIGHT, lights[j][5]);
  digitalWrite(DOT_LIGHT, lights[j][6]);
  digitalWrite(MIDDLE_LIGHT, lights[j][7]);
}

void displayDigitalWrite(int _s) {
  digitalWrite(BOTTOM_LIGHT, _s);
  digitalWrite(BOTTOM_LEFT_LIGHT, _s);
  digitalWrite(TOP_LEFT_LIGHT, _s);
  digitalWrite(TOP_LIGHT, _s);
  digitalWrite(TOP_RIGHT_LIGHT, _s);
  digitalWrite(BOTTOM_RIGHT_LIGHT, _s);
  digitalWrite(DOT_LIGHT, _s);
  digitalWrite(MIDDLE_LIGHT, _s);
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

  for (int i = 0; i < 7; i++) {
    if (i >= 5) {
      displayNumber(i);
      delay(500);
      displayDigitalWrite(LOW);
      digitalWrite(PEDESTRIAN_GREEN_LED, LOW);
      delay(500);
      displayNumber(i);
      digitalWrite(PEDESTRIAN_GREEN_LED, HIGH);
    } else {
      displayNumber(i);
      delay(1000);
    }
  }

  displayDigitalWrite(LOW);
  digitalWrite(PEDESTRIAN_GREEN_LED, LOW);

  digitalWrite(PEDESTRIAN_RED_LED, HIGH);

  blink(RED_LED);
  digitalWrite(RED_LED, LOW);

  state = LOW;
}
