#define PIN_IN_A 0
#define PIN_IN_B 0
#define PIN_EN 0

#define MAX_VALUE 255

void setup() {
    pinMode(PIN_IN_A, OUTPUT);
    pinMode(PIN_IN_B, OUTPUT);
    pinMode(PIN_EN, OUTPUT);

    digitalWrite(PIN_IN_A, LOW);
    digitalWrite(PIN_IN_B, LOW);
    digitalWrite(PIN_EN, LOW);
}

void loop() {
    // rotate (1/4)
    analogWrite(PIN_EN, MAX_VALUE / 4);
    digitalWrite(PIN_IN_A, HIGH);
    digitalWrite(PIN_IN_B, LOW);
    delay(2000);

    // rotate (1/2)
    analogWrite(PIN_EN, MAX_VALUE / 2);
    digitalWrite(PIN_IN_A, HIGH);
    digitalWrite(PIN_IN_B, LOW);
    delay(2000);

    // rotate (full)
    analogWrite(PIN_EN, MAX_VALUE);
    digitalWrite(PIN_IN_A, HIGH);
    digitalWrite(PIN_IN_B, LOW);
    delay(2000);

    // stop
    digitalWrite(PIN_EN, LOW);
    delay(2000);

    // change direction

    // rotate (1/4)
    analogWrite(PIN_EN, MAX_VALUE / 4);
    digitalWrite(PIN_IN_A, LOW);
    digitalWrite(PIN_IN_B, HIGH);
    delay(2000);

    // rotate (1/2)
    analogWrite(PIN_EN, MAX_VALUE / 2);
    digitalWrite(PIN_IN_A, LOW);
    digitalWrite(PIN_IN_B, HIGH);
    delay(2000);

    // rotate (full)
    analogWrite(PIN_EN, MAX_VALUE);
    digitalWrite(PIN_IN_A, LOW);
    digitalWrite(PIN_IN_B, HIGH);
    delay(2000);

    // stop
    digitalWrite(PIN_EN, LOW);
    delay(2000);
}
