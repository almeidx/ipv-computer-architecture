#define LDR A0
#define LED 13

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int light_level = analogRead(LDR);

  Serial.print("Light level: ");
  Serial.println(light_level);

  if (light_level > 950) {
    digitalWrite(LED, HIGH);
  } else {
    analogWrite(LED, LOW);
  }

  delay(5000);
}
