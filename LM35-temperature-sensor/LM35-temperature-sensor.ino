void setup() {
  Serial.begin(9600);
}
void loop() {
  int rawData = analogRead(A0);
  float vcc = 5.0;
  float voltage = rawData * (vcc / 1024.0);
  float temperature = voltage * 100;
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  delay(500);
  if (temperature < 22) {
    digitalWrite(10, HIGH);
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
  } else if (temperature >= 22 && temperature <= 25) {
    digitalWrite(6, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
  } else {
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(10, LOW);
  }
}