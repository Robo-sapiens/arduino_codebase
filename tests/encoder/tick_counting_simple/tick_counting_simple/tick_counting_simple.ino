// Engine pins
#define PIN_IN_A 0
#define PIN_IN_B 0
#define PIN_EN 0

// Encoder pins
#define PIN_PHASE_A 0
#define PIN_PHASE_B 0

// Signal pins
#define PIN_SIG_A 0
#define PIN_SIG_B 0

#define MAX_PWM 255

long encA = 0;
long encB = 0;

void setup() {
    pinMode(PIN_IN_A, OUTPUT);
    pinMode(PIN_IN_B, OUTPUT);
    pinMode(PIN_EN, OUTPUT);

    digitalWrite(PIN_IN_A, HIGH);
    digitalWrite(PIN_IN_B, LOW);
    analogWrite(PIN_EN, MAX_PWM / 4);

    pinMode(PIN_PHASE_A, INPUT);
    pinMode(PIN_PHASE_B, INPUT);

    pinMode(PIN_SIG_A, INPUT);
    pinMode(PIN_SIG_B, INPUT);

    attachInterrupt(digitalPinToInterrupt(PIN_PHASE_A), EncA, RISING);
    attachInterrupt(digitalPinToInterrupt(PIN_PHASE_B), EncB, RISING);

    Serial.begin(9600);
}

void EncA() {
    if ( digitalRead(PIN_SIG_A) ) {
        encA++;
    } else {
        encA--;
    }
}

void EncB() {
    if ( digitalRead(PIN_SIG_A) ) {
        encB--;
    } else {
        encB++;
    }
}

void loop() {
    Serial.print(encA);
    Serial.print("\t");
    Serial.print(encB);
    Serial.print("\n");
}
