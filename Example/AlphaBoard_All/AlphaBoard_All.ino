// Update pin numbers as per your board's wiring
const int led1 = 11;
const int led2 = 12;
const int led3 = 13;
const int buzzer = 9;
const int pot1 = A2;
const int pot2 = A1;
const int tempSensor = A3;
const int lightSensor = A0;
const int button1 = A4;
const int button2 = A5;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop() {
  // Blink LEDs
  digitalWrite(led1, HIGH); delay(100);
  digitalWrite(led2, HIGH); delay(100);
  digitalWrite(led3, HIGH); delay(100);
  digitalWrite(led1, LOW); delay(100);
  digitalWrite(led2, LOW); delay(100);
  digitalWrite(led3, LOW); delay(100);

  // Potentiometers
  int potValue1 = analogRead(pot1);
  int potValue2 = analogRead(pot2);

  // Sensors
  int tempValue = analogRead(tempSensor);
  int lightValue = analogRead(lightSensor);

  // Buttons
  bool btn1Pressed = digitalRead(button1) == LOW;
  bool btn2Pressed = digitalRead(button2) == LOW;

  // Output sensor data
  Serial.print("POT1: "); Serial.print(potValue1);
  Serial.print(" | POT2: "); Serial.print(potValue2);
  Serial.print(" | Temp: "); Serial.print(tempValue);
  Serial.print(" | Light: "); Serial.print(lightValue);
  Serial.print(" | BTN1: "); Serial.print(btn1Pressed);
  Serial.print(" | BTN2: "); Serial.println(btn2Pressed);

  // Buzzer on button1
  if (btn1Pressed) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  delay(500);
}
