int helmetSensor = 2;
int alcoholSensor = A0;
int relay = 7;
int buzzer = 8;

void setup() {
  pinMode(helmetSensor, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int helmet = digitalRead(helmetSensor);
  int alcohol = analogRead(alcoholSensor);

  Serial.print("Helmet: ");
  Serial.print(helmet);
  Serial.print("  Alcohol: ");
  Serial.println(alcohol);

  if (helmet == HIGH && alcohol < 400) { // Safe condition
    digitalWrite(relay, HIGH);   // Engine ON
    digitalWrite(buzzer, LOW);
  } else {
    digitalWrite(relay, LOW);    // Engine OFF
    digitalWrite(buzzer, HIGH);
  }

  delay(500);
}
