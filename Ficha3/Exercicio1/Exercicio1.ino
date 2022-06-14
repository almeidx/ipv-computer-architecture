#define LDR A0
#define LED 6

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int light_level = analogRead(LDR);

  Serial.print("Light level: ");
  Serial.print(light_level);

  int intensity = max(map(light_level, 700, 926, 255, 0), 0);
  analogWrite(LED, intensity);

  Serial.print(" | Intensity: ");
  Serial.println(intensity);

  delay(100);
}
