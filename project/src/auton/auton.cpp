#include "main.h"
#include "auton/DriveTrain.hpp"
#include "intake/intake.h"
pros::Motor right_mtr(1);
int autonMode = -1;
void runAuton() {
// right_mtr = 127;
// pros::delay(500);
// right_mtr.brake();
moveForward();
pros::delay(1500);
brake();
Spin();
pros::delay(2500);
brake();
SpinOtherWay();
pros::delay(2500);
brake();
Moveintake();
pros::delay(1500);
StopIntake();
}


void resetAuton() {
    right_mtr.brake();
    pros::delay(20);
}

void setAutonMode(int mode) {
    autonMode = mode;
}