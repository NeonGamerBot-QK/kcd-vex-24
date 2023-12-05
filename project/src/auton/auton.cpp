#include "main.h"
#include "auton/DriveTrain.hpp"
#include "intake/intake.h"
#include <iostream>
pros::Motor right_mtr(1);
int autonMode = -1;
void runAuton() {
// right_mtr = 127;
// pros::delay(500);
// right_mtr.brake();
// moveForward();
// pros::delay(1500);
// brake();
// Spin();
// pros::delay(2500);
// brake();
// SpinOtherWay();
// pros::delay(2500);
// brake();
// Moveintake();
// pros::delay(1500);
// StopIntake();
if (autonMode == -1) {
    std::cout << "No Side Selected or Changed at all!!" << std::endl;

    Spin();
    pros::delay(500);
    brake();
} else if(autonMode == 0) {
    std::cout << "Red" << std::endl;

moveForward();
pros::delay(500);
    brake();
} else if(autonMode == 1){
    std::cout << "Blue" << std::endl;

   moveBack();
    pros::delay(500);
    brake();
} else if(autonMode == 2){
    std::cout << "Skills" << std::endl;

    MoveRight();
    pros::delay(500);
    brake();
} else {
    brake();
}
pros::delay(500);
 std::cout << "AutonMode: " << autonMode << std::endl;
}


void resetAuton() {
   StopIntake();
   brake();
    pros::delay(20);
}

void setAutonMode(int mode) {
    autonMode = mode;
}