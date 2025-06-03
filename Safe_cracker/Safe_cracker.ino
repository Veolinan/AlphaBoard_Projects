const int pot1 = A1;
const int pot2 = A2;
const int greenLED = 11;
const int redLED = 13;
const int orangeLED = 12;
const int buzzer = 9;
const int submitButton = A5;

const int combo1 = 450;
const int combo2 = 850;
const int tolerance = 30;

bool lastButtonState = HIGH;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(orangeLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(submitButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int potValue1 = analogRead(pot1);
  int potValue2 = analogRead(pot2);
  bool buttonState = digitalRead(submitButton);

  Serial.print("POT1: "); Serial.print(potValue1);
  Serial.print(" | POT2: "); Serial.println(potValue2);

  // Check for button press (rising edge)
  if (lastButtonState == HIGH && buttonState == LOW) {
    bool pass = isWithin(potValue1, combo1, tolerance) &&
                isWithin(potValue2, combo2, tolerance);
    if (pass) {
      successSequence();
    } else {
      failSequence();
    }
  }

  lastButtonState = buttonState;
  delay(50); // Debounce
}

bool isWithin(int value, int target, int tol) {
  return value >= (target - tol) && value <= (target + tol);
}

void successSequence() {
  Serial.println("✅ UNLOCKED!");
  for (int i = 0; i < 2; i++) {
    digitalWrite(greenLED, HIGH);
    tone(buzzer, 1000); delay(150);
    digitalWrite(greenLED, LOW);
    noTone(buzzer); delay(150);
  }
}

void failSequence() {
  Serial.println("❌ WRONG COMBINATION");

  digitalWrite(redLED, HIGH);
  tone(buzzer, 300); // Continuous tone
  delay(1000);       // 1 second long buzz
  digitalWrite(redLED, LOW);
  noTone(buzzer);
}
