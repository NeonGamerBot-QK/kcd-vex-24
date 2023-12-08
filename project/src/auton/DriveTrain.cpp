#include "main.h"
// MOTORS


void drive(int left, int right) {
   pros::Motor left_mtr(1); // right
	pros::Motor left_mtr2(3); //left
	pros::Motor right_mtr(2); // right 
	pros::Motor right_mtr2(4); //left
	
    	left_mtr = left;
		left_mtr2 = left;
		right_mtr = right;
		right_mtr2 = right;
}
void moveForward() {
    drive(127,-127);
}
void moveBack() {
    drive(-127,127);
}
void MoveRight() {
    drive(0,-127);
}
void MoveLeft() {
    drive(127,0);
}
void Spin() {
    drive(127,127);
}
void SpinOtherWay() {
    drive(-127,-127);
}
void brake() {
    pros::Motor left_mtr(3); // right
    pros::Motor left_mtr2(4); //left
    pros::Motor right_mtr(1); // right 
    pros::Motor right_mtr2(2); //left
    left_mtr.brake();
    right_mtr.brake();
    left_mtr2.brake();
    right_mtr2.brake();
}