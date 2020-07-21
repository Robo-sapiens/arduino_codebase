#include <Servo.h>

#define PIN_SRV 0

#define MIN_POSITION 0
#define MAX_POSITION 180

Servo servo;

void setup() {
    servo.attach(PIN_SRV);
}

void loop() {
    // Set to min position
    servo.write(MIN_POSITION);

    // Wait for 2 seconds
    delay(2000);

    // Set to max position
    servo.write(MAX_POSITION);

    // Wait for 2 seconds
    delay(2000);
}
