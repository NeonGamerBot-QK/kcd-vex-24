#include "main.h"
#include "auton/DriveTrain.hpp"
#include "intake/intake.h"
#include "outtake/Outtake.hpp"
#include <iostream>
pros::Motor right_mtr(1);
int autonMode = -1;
void resetAuton() {
   StopIntake();
   brake();
   StopOuttake();
    pros::delay(20);
}
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
pros::delay(1500);
    brake();
MoveRight();
pros::delay(500);
    brake();
    MoveOuttake();
    pros::delay(1000);
resetAuton();
    // brake();
} else if(autonMode == 1){
    std::cout << "Blue" << std::endl;

 moveForward();
pros::delay(1500);
    brake();
MoveLeft();
pros::delay(500);
    brake();
    MoveOuttake();
    pros::delay(1000);
resetAuton();
}  else {
    brake();
}
pros::delay(500);
 std::cout << "AutonMode: " << autonMode << std::endl;
}




void setAutonMode(int mode) {
    autonMode = mode;
}