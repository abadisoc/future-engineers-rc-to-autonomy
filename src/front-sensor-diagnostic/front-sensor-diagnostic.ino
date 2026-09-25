/*
  Front HC-SR04 diagnostic — Arduino Uno.
  SENSOR ONLY: no motor or steering commands.

  Expected wiring from the team's earlier plan:
    VCC  -> Uno 5V
    GND  -> Uno GND (shared via breadboard negative rail is fine)
    TRIG -> Uno D6
    ECHO -> Uno D7

  Check the actual car: if TRIG/ECHO are on different pins, change
  TRIG_PIN and ECHO_PIN below before uploading.

  Serial Monitor: 115200 baud.
  The built-in LED lights when an object is closer than 25 cm OR when
  the reading is invalid. This LED is only a bench-test indicator.
*/

const byte TRIG_PIN = 6;
const byte ECHO_PIN = 7;
const float LED_THRESHOLD_CM = 25.0f;
const unsigned long ECHO_TIMEOUT_US = 25000UL;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);  // Treat startup as unknown/stop.
  Serial.begin(115200);
  Serial.println(F("ms,front_cm,indicator"));
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  const unsigned long echoUs = pulseIn(ECHO_PIN, HIGH, ECHO_TIMEOUT_US);
  const float cm = echoUs * 0.0343f / 2.0f;
  const bool valid = echoUs != 0UL && cm >= 2.0f && cm <= 400.0f;
  const bool lightLed = !valid || cm < LED_THRESHOLD_CM;
  digitalWrite(LED_BUILTIN, lightLed ? HIGH : LOW);

  Serial.print(millis());
  Serial.print(',');
  if (valid) {
    Serial.print(cm, 1);
  } else {
    Serial.print(F("INVALID"));
  }
  Serial.print(',');
  Serial.println(lightLed ? F("ON") : F("OFF"));

  delay(100);  // At least 60 ms between HC-SR04 triggers.
}
