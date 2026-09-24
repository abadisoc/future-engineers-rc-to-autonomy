/*
  Three HC-SR04 sensor diagnostic for an Arduino Uno.

  This is a sensor-only prototype. It does not move a car, command a motor,
  or prove competition performance. Connect the Uno by USB while all drive
  and steering electronics remain disconnected. Pin assignments are from
  the team's shared wiring conversation; verify against the real wiring.

  Output at 115200 baud:
  ms,left_cm,front_cm,right_cm
  1234,42.1,INVALID,31.7

  An invalid/no echo is never reported as a long clear distance.
*/

struct RangeSensor {
  const byte triggerPin;
  const byte echoPin;
};

const RangeSensor LEFT = {2, 3};
const RangeSensor FRONT = {6, 7};
const RangeSensor RIGHT = {A0, A1};

// 25 ms is sufficient for roughly 400 cm round-trip travel; INVALID on timeout.
const unsigned long ECHO_TIMEOUT_US = 25000UL;
// Pause between separate transducers to reduce acoustic cross talk.
const unsigned long INTER_SENSOR_PAUSE_MS = 30UL;
const float MIN_VALID_CM = 2.0f;
const float MAX_VALID_CM = 400.0f;

void initSensor(const RangeSensor& sensor) {
  pinMode(sensor.triggerPin, OUTPUT);
  digitalWrite(sensor.triggerPin, LOW);
  pinMode(sensor.echoPin, INPUT);
}

float readCm(const RangeSensor& sensor) {
  // Ensure a clean trigger pulse as specified for HC-SR04 modules.
  digitalWrite(sensor.triggerPin, LOW);
  delayMicroseconds(3);
  digitalWrite(sensor.triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensor.triggerPin, LOW);

  const unsigned long pulseWidthUs =
      pulseIn(sensor.echoPin, HIGH, ECHO_TIMEOUT_US);
  if (pulseWidthUs == 0UL) {
    return -1.0f;
  }
  // Speed of sound is approximately 0.0343 cm/us near 20 C.
  // Divide by two for the outward and return path.
  const float cm = pulseWidthUs * 0.0343f / 2.0f;
  if (cm < MIN_VALID_CM || cm > MAX_VALID_CM) {
    return -1.0f;
  }
  return cm;
}

void printCmOrInvalid(float cm) {
  if (cm < 0.0f) {
    Serial.print(F("INVALID"));
  } else {
    Serial.print(cm, 1);
  }
}

void setup() {
  initSensor(LEFT);
  initSensor(FRONT);
  initSensor(RIGHT);
  Serial.begin(115200);
  Serial.println(F("ms,left_cm,front_cm,right_cm"));
}

void loop() {
  const unsigned long startedMs = millis();
  const float leftCm = readCm(LEFT);
  delay(INTER_SENSOR_PAUSE_MS);
  const float frontCm = readCm(FRONT);
  delay(INTER_SENSOR_PAUSE_MS);
  const float rightCm = readCm(RIGHT);
  delay(INTER_SENSOR_PAUSE_MS);

  Serial.print(startedMs);
  Serial.print(',');
  printCmOrInvalid(leftCm);
  Serial.print(',');
  printCmOrInvalid(frontCm);
  Serial.print(',');
  printCmOrInvalid(rightCm);
  Serial.println();
}
