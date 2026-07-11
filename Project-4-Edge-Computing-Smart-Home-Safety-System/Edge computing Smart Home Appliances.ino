#define PIR_PIN 27
#define GREEN_LED 18
#define RED_LED 19
#define BUZZER 23
#define GAS_SENSOR 34

volatile bool motionDetected = false;

void IRAM_ATTR motionISR() {
  motionDetected = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  attachInterrupt(
    digitalPinToInterrupt(PIR_PIN),
    motionISR,
    RISING
  );

  Serial.println("Smart Home Safety System Started");
}

void loop() {

  int gasValue = analogRead(GAS_SENSOR);

  // Emergency Override
  if (gasValue > 2500) {

    Serial.println("================================");
    Serial.println("GAS LEAK DETECTED");
    Serial.println("EMERGENCY MODE ACTIVATED");
    Serial.println("================================");

    digitalWrite(GREEN_LED, LOW);

    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);

    delay(300);

    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);

    delay(300);

    return;
  }

  // Motion Lighting Logic
  if (motionDetected) {

    Serial.println("Motion Detected");
    Serial.println("Smart Light ON");

    digitalWrite(GREEN_LED, HIGH);

    delay(3000);

    digitalWrite(GREEN_LED, LOW);

    motionDetected = false;
  }
}
