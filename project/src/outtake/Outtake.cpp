#include "main.h"
pros::Motor outtake1(7);
pros::Motor outtake2(8);
void MoveOuttake() {
outtake1 = 127;
outtake2 = -127;
}

void StopOuttake() {
    outtake1.brake();
    outtake2.brake();
}