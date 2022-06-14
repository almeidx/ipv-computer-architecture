int _step = 1, amount = 0;

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  amount++;

  digitalWrite(13, HIGH);
  delay(_step == 2 ? 1300 : 500);
  digitalWrite(13, LOW);
  delay(300);

  if (amount == 3) {
    amount = 0;

    if (_step == 3) {
      _step = 1;
      delay(5000); // Esperar 5 segundos por cada SOS
    } else {
      _step++;
    }
  }
}
