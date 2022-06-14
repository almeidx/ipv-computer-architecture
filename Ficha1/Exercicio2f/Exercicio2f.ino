int amount = 0;
int letter = 1;
int _delay;

#define LONG_DELAY 1300
#define SHORT_DELAY 500

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  amount++;

  switch (letter) {
    case 1: // o
    case 8:
      if (amount == 1 || amount == 2 || amount == 3) _delay = LONG_DELAY;
      break;
    case 2: // l
      if (amount == 1 || amount == 3 || amount == 4) _delay = SHORT_DELAY;
      else if (amount == 2) _delay = LONG_DELAY;
      break;
    case 3: // a
      if (amount == 1) _delay = SHORT_DELAY;
      else if (amount == 2) _delay = LONG_DELAY;
      break;
    case 4: // m
      if (amount == 1 || amount == 2) _delay = LONG_DELAY;
      break;
    case 5: // u
      if (amount == 1 || amount == 2) _delay = SHORT_DELAY;
      else if (amount == 3) _delay = LONG_DELAY;
      break;
    case 6: // n
      if (amount == 1) _delay = LONG_DELAY;
      else if (amount == 2) _delay = SHORT_DELAY;
      break;
    case 7: // d
      if (amount == 1) _delay = LONG_DELAY;
      else if (amount == 2 || amount == 3) _delay = SHORT_DELAY;
      break;
  }

  if (_delay == -1) {
    if (letter == 8) {
      letter = 1;
      delay(3000); // Esperar 3 segundos por palavra
    } else {
      letter++;
    }

    amount = 0;
    return;
  }

  digitalWrite(13, HIGH);
  delay(_delay);
  digitalWrite(13, LOW);
  delay(300);

  _delay = -1;
}
