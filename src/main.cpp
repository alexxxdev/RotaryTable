#include <AccelStepper.h>
#include <Arduino.h>
#include <GyverButton.h>

AccelStepper stepper(AccelStepper::HALF4WIRE, 8, 10, 9, 11);

GButton button1(2, HIGH_PULL, NORM_OPEN);  // <<
GButton button2(3, HIGH_PULL, NORM_OPEN);  // ||
GButton button3(4, HIGH_PULL, NORM_OPEN);  // >>

int dir = 1;

#define speedMotor A1

void setup() {
    stepper.setMaxSpeed(1023);
    stepper.setAcceleration(100);
}

void loop() {
    button1.tick();
    button2.tick();
    button3.tick();
    int speed = map(analogRead(speedMotor), 0, 4096, 0, 1023);

    if (button1.hasClicks()) {
        dir = 1;
    }
    if (button3.hasClicks()) {
        dir = -1;
    }
    if (button2.hasClicks()) {
        dir = 0;
    }
    stepper.setSpeed(speed * dir);
    stepper.runSpeed();
}