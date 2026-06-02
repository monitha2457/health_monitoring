#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define BUZZER_PIN 15

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  dht.begin();

  lcd.init();
  lcd.backlight();

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  randomSeed(analogRead(0));

  lcd.setCursor(0, 0);
  lcd.print("Health Monitor");
  lcd.setCursor(0, 1);
  lcd.print("Starting...");
  delay(2000);

  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature();

  int heartRate = random(70, 91);  // 70-90 BPM
  int spo2 = random(95, 101);      // 95-100 %

  if (isnan(temp)) {
    Serial.println("DHT Error!");

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error");
    delay(2000);
    return;
  }

  bool alert = false;

  if (heartRate > 100 || spo2 < 95 || temp > 37.5) {
    alert = true;
  }

  Serial.println("===== HEALTH DATA =====");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");

  Serial.print("Heart Rate: ");
  Serial.print(heartRate);
  Serial.println(" BPM");

  Serial.print("SpO2: ");
  Serial.print(spo2);
  Serial.println(" %");

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("H:");
  lcd.print(heartRate);
  lcd.print(" S:");
  lcd.print(spo2);

  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temp, 1);
  lcd.print((char)223);
  lcd.print("C ");

  if (alert) {
    lcd.print("ALRT");

    tone(BUZZER_PIN, 1000);
    delay(500);
    noTone(BUZZER_PIN);
  } else {
    lcd.print("OK");
    noTone(BUZZER_PIN);
  }

  delay(3000);
}
