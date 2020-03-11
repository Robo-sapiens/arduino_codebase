// Engine pins
#define PIN_IN_A 26
#define PIN_IN_B 24
#define PIN_EN 4

// Encoder pins
#define PIN_PHASE_A 18
#define PIN_PHASE_B 19

#define MAX_PWM 255

long encTick = 0;

bool sigA = false;
bool sigB = false;

void setup() {
    // Set up engine
    pinMode(PIN_IN_A, OUTPUT);
    pinMode(PIN_IN_B, OUTPUT);
    pinMode(PIN_EN, OUTPUT);

    digitalWrite(PIN_IN_A, HIGH);
    digitalWrite(PIN_IN_B, LOW);
    analogWrite(PIN_EN, MAX_PWM / 2);

    // Set up encoder
    pinMode(PIN_PHASE_A, INPUT);
    pinMode(PIN_PHASE_B, INPUT);

    attachInterrupt(digitalPinToInterrupt(PIN_PHASE_A), intAsub, CHANGE);
    attachInterrupt(digitalPinToInterrupt(PIN_PHASE_B), intBsub, CHANGE);

    Serial.begin(9600);
}

void intAsub() {
    sigA = digitalRead(PIN_PHASE_A);
    if (sigB != sigA) {
        encTick++;
    } else {
        encTick--;
    }
}

void intBsub() {
    sigA = digitalRead(PIN_PHASE_B);
    if (sigA == sigB) {
        encTick++;
    } else {
        encTick--;
    }
}

void loop() {
    Serial.println(encTick);
}
