#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

#define VIBRATION_SENSOR_PIN 7
#define SMOKE_SENSOR_PIN A0           // Analog pin for smoke sensor
#define GREEN_LED_PIN 6
#define RED_LED_PIN 4
#define BUZZER_PIN 5

LiquidCrystal_I2C lcd(0x27, 20, 4);    // I2C LCD
SoftwareSerial mp3Serial(10, 11);      // DFPlayer Mini: RX = 10, TX = 11
DFRobotDFPlayerMini mp3;

bool earthquakeAlerted = false;
bool smokeAlerted = false;

void setup() {
  pinMode(VIBRATION_SENSOR_PIN, INPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.init();
  lcd.backlight();

  digitalWrite(GREEN_LED_PIN, HIGH);
  digitalWrite(RED_LED_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.setCursor(0, 0);
  lcd.print("System Ready...");

  mp3Serial.begin(9600);
  if (!mp3.begin(mp3Serial)) {
    lcd.setCursor(0, 1);
    lcd.print("MP3 Error!");
    while (1);  // Halt if MP3 init fails
  }
  mp3.volume(30);  // Set volume (0-30)
}

void loop() {
  int vibration = digitalRead(VIBRATION_SENSOR_PIN);
  int smokeValue = analogRead(SMOKE_SENSOR_PIN);
  int smokeThreshold = 300;  // You may adjust this based on your sensor

  // ----- Earthquake Detected -----
  if (vibration == HIGH && !earthquakeAlerted) {
    earthquakeAlerted = true;  // Mark earthquake as alerted to avoid repeats
    smokeAlerted = false;      // Reset smoke alert flag

    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Detected Quakes");

    delay(3000);
    digitalWrite(BUZZER_PIN, LOW);

    delay(1000);
    mp3.play(2);  // Earthquake alert sound
    delay(9000);
    mp3.stop();

    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("System Monitoring...");
  }
  else if (vibration == LOW) {
    earthquakeAlerted = false;  // Reset flag when vibration stops
  }

  // ----- Smoke Detected -----
  if (smokeValue > smokeThreshold && !smokeAlerted) {
    smokeAlerted = true;       // Mark smoke as alerted to avoid repeats
    earthquakeAlerted = false; // Reset earthquake alert flag

    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Smoke Alert!");
    lcd.setCursor(0, 1);
    lcd.print("Value: ");
    lcd.print(smokeValue);

    delay(3000);
    digitalWrite(BUZZER_PIN, LOW);

    delay(1000);
    mp3.play(1);  // Smoke alert sound (optional)
    delay(7000);
    mp3.stop();

    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("System Monitoring...");
  }
  else if (smokeValue <= smokeThreshold) {
    smokeAlerted = false;  // Reset flag when smoke goes below threshold
  }

  delay(200);  // Small delay to reduce flickering
}
