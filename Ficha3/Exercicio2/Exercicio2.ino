#include <LiquidCrystal.h>

#include <stdio.h>
#include <stdlib.h>

#define LDR A0
#define MAX_MEASUREMENTS 20

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int *measurements, *arr, _size, timePassed;

void setup() {
  lcd.begin(16, 2);

  measurements = (int *)malloc(MAX_MEASUREMENTS * sizeof(int));
  arr = (int *)malloc(3 * sizeof(int));
  _size = timePassed = 0;
}

void populateMeasurements() {
  int _min, _max, sum;
  _min = _max = sum = measurements[0];

  for (int i = 1; i < _size; i++) {
    if (measurements[i] < _min) {
      _min = measurements[i];
    } else if (measurements[i] > _max) {
      _max = measurements[i];
    }
    sum += measurements[i];
  }

  arr[0] = _min;
  arr[1] = _max;
  arr[2] = (int)(sum / _size);
}

void loop() {
  if (timePassed >= 15000) {
    lcd.clear();

    populateMeasurements();

    lcd.setCursor(0, 0);
    lcd.print("min:");
    lcd.print(arr[0]);
    lcd.print(" max:");
    lcd.print(arr[1]);

    lcd.setCursor(0, 1);
    lcd.print("mean:");
    lcd.print(arr[2]);

    timePassed = _size = 0;
  } else {
    if (_size <= MAX_MEASUREMENTS) {
      int light_level = analogRead(LDR);
      measurements[_size++] = light_level;
    }

    delay(500);
    timePassed += 500;
  }
}
