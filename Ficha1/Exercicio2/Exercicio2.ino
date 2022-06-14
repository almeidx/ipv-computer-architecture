int duration = 3000;
int amount = 0;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(duration);
  digitalWrite(13, LOW);
  delay(duration);

  if (duration > 500) {
    duration -= 500;
  } else {
    amount++;
    if (amount == 3) {
      duration = 3000;
      amount = 0;
    }
  }
}
