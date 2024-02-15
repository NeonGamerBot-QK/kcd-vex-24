#include "main.h"
#include "auton/Catapult.hpp"
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
    // red side, push matchload into goal then get one of the balls on the field into the goal  - 15s
   moveForward();
   pros::delay(2000);
//    brake();
//    moveBack();
//    MoveLeft();
//    pros::delay(1500);
//    brake();
// moveForward();
// pros::delay(1700);
// brake();
// MoveLeft();
// pros::delay(800);
// brake();
// moveForward();
// pros::delay(400);
// MoveLeft();
// pros::delay(600);
// brake();
// moveForward();
// pros::delay(700);
brake();
// done (this is the first edit)
// moveForward();
// pros::delay(1500);
//     brake();
// MoveRight();
// pros::delay(500);
//     brake();
//     MoveOuttake();
//     pros::delay(1000);
resetAuton();
    // brake();
} else if(autonMode == 1){
    std::cout << "Blue" << std::endl;
 CForward();
    pros::delay(1200);
    Cstop();
    moveForward();
    pros::delay(800);
    brake();
    MoveRight();
    pros::delay(800);
    brake();
    moveForward();
    pros::delay(500);
    brake();
resetAuton();
} else if (autonMode == 2) {
// Skills :)
moveBack();
pros::delay(500);
brake();
CForward();
pros::delay(50000);
Cstop();
MoveRight();
brake();
pros::delay(500);
brake();
moveForward();
pros::delay(1500);
MoveLeft();
Moveintake();
pros::delay(2500);
brake();
StopIntake();
}
 else {
    brake();
}
pros::delay(500);
 std::cout << "AutonMode: " << autonMode << std::endl;
}




void setAutonMode(int mode) {
    autonMode = mode;
}