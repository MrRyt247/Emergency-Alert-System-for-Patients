#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const int WARD_1_BTN = 7;
const int WARD_2_BTN = 6;
const int WARD_3_BTN = 5;
const int WARD_4_BTN = 4;
const int BUZZER_PIN = 2;

void setup()
{
  // Initialize buttons as input with internal pull-up resistors
  pinMode(WARD_1_BTN, INPUT_PULLUP);
  pinMode(WARD_2_BTN, INPUT_PULLUP);
  pinMode(WARD_3_BTN, INPUT_PULLUP);
  pinMode(WARD_4_BTN, INPUT_PULLUP);
  
  // Initialize buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Emergency Alert");
  lcd.setCursor(0, 1);
  lcd.print("System Ready");
  
  delay(2000);
  lcd.clear();
}

void loop() {
  // Check each ward's emergency button
  if (digitalRead(WARD_1_BTN) == LOW) {
    triggerEmergencyAlert("WARD 1");
  }
  
  if (digitalRead(WARD_2_BTN) == LOW) {
    triggerEmergencyAlert("WARD 2");
  }
  
  if (digitalRead(WARD_3_BTN) == LOW) {
    triggerEmergencyAlert("WARD 3");
  }
  if (digitalRead(WARD_4_BTN) == LOW) {
    triggerEmergencyAlert("WARD 4");
  }
  
  delay(200); // Debounce delay
}

void triggerEmergencyAlert(String ward) {
  // Clear LCD and display emergency message
  lcd.clear();
  lcd.print("EMERGENCY ALERT!");
  lcd.setCursor(0, 1);
  lcd.print(ward);
  
  // Sound buzzer with alternating tones
  for (int i = 0; i < 5; i++) {
    tone(BUZZER_PIN, 1000); // High tone
    delay(500);
    tone(BUZZER_PIN, 500);  // Low tone
    delay(500);
  }
  
  noTone(BUZZER_PIN);
}