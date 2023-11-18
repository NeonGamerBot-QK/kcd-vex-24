#include "main.h"
pros::Motor right_mtr(1);
int autonMode = -1;
void runAuton() {
right_mtr = 127;
pros::delay(500);
right_mtr.brake();
}


void resetAuton() {
    right_mtr.brake();
    pros::delay(20);
}

void setAutonMode(int mode) {
    autonMode = mode;
}