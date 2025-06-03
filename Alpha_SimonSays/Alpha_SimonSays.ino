const int greenLED = 11;
const int redLED = 13;
const int buzzer = 9;

const int buttonGreen = A5;
const int buttonRed = A4;

const int sequenceLength = 3;
int sequence[sequenceLength];
int currentLevel = 1;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(buttonGreen, INPUT_PULLUP);
  pinMode(buttonRed, INPUT_PULLUP);

  Serial.begin(9600);

  randomSeed(analogRead(A0)); // Noise for randomness
  generateSequence();
  introSequence();
}

void loop() {
  // Play current sequence
  for (int i = 0; i < currentLevel; i++) {
    playLED(sequence[i]);
    delay(300);
  }

  // Get player input and check
  for (int i = 0; i < currentLevel; i++) {
    int playerInput = getPlayerInput();
    if (playerInput != sequence[i]) {
      failSequence();
      currentLevel = 1;
      delay(1000);
      return;
    }
  }

  successBeep();
  currentLevel++;
  if (currentLevel > sequenceLength) {
    winSequence();
    currentLevel = 1;
  }

  delay(1000); // Pause before next round
}

void generateSequence() {
  for (int i = 0; i < sequenceLength; i++) {
    sequence[i] = random(0, 2); // 0 = green, 1 = red
  }
}

void playLED(int color) {
  int ledPin = (color == 0) ? greenLED : redLED;
  int toneFreq = (color == 0) ? 1000 : 500;

  digitalWrite(ledPin, HIGH);
  tone(buzzer, toneFreq);
  delay(300);
  digitalWrite(ledPin, LOW);
  noTone(buzzer);
}

int getPlayerInput() {
  while (true) {
    if (digitalRead(buttonGreen) == HIGH) {
      waitRelease(buttonGreen);
      playLED(0); // feedback
      return 0;
    }
    if (digitalRead(buttonRed) == HIGH) {
      waitRelease(buttonRed);
      playLED(1); // feedback
      return 1;
    }
  }
}

void waitRelease(int pin) {
  while (digitalRead(pin) == HIGH);
  delay(100); // debounce
}

void introSequence() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, HIGH);
    tone(buzzer, 800); delay(200);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    noTone(buzzer); delay(200);
  }
}

void failSequence() {
  Serial.println("❌ WRONG SEQUENCE");
  for (int i = 0; i < 3; i++) {
    digitalWrite(redLED, HIGH);
    tone(buzzer, 300); delay(150);
    digitalWrite(redLED, LOW);
    noTone(buzzer); delay(150);
  }
}

void successBeep() {
  tone(buzzer, 1200); delay(150);
  noTone(buzzer); delay(100);
  tone(buzzer, 1500); delay(150);
  noTone(buzzer);
}

void winSequence() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(greenLED, HIGH);
    tone(buzzer, 1000); delay(100);
    digitalWrite(greenLED, LOW);
    noTone(buzzer); delay(100);
  }
  Serial.println("🏆 YOU WIN!");
}
