#define TONE_PIN 9
#define PING_PIN 5
#define ECHO_PIN 4

#define FAR_LED 1
#define MID_LED 2
#define CLOSE_LED 3

#define FREQUENCY 4000

void setup() {
  pinMode(PING_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(FAR_LED, OUTPUT);
  pinMode(MID_LED, OUTPUT);
  pinMode(CLOSE_LED, OUTPUT);
}

void beep(int dur) {
  tone(TONE_PIN, FREQUENCY);
  delay(dur);
  noTone(TONE_PIN);
  delay(dur);
}

void displayLeds(int farState, int midState, int closeState) {
  digitalWrite(FAR_LED, farState);
  digitalWrite(MID_LED, midState);
  digitalWrite(CLOSE_LED, closeState);
}

void loop() {
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(PING_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  long cm = microsecondsToCm(duration);

  if (cm < 30) {
    if (cm > 15) {
      displayLeds(HIGH, LOW, LOW);
    } else if (cm > 7) {
      displayLeds(HIGH, HIGH, LOW);
    } else {
      displayLeds(HIGH, HIGH, HIGH);
    }

    if (cm < 7) {
      tone(TONE_PIN, FREQUENCY);
    } else {
      beep(map(cm, 2, 30, 50, 500));
    }
  } else {
    displayLeds(LOW, LOW, LOW);
    noTone(TONE_PIN);
  }
}

long microsecondsToCm(long microseconds) {
  return microseconds / 29 / 2;
}
