#include "main.h"
// #include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/impl/chassis/controller/chassisControllerBuilder.hpp"
// USE https://okapilib.github.io/OkapiLib/md_docs_tutorials_walkthrough_clawbot.html
// #include <iostream>
// #include <fstream> 
// ofstream MyFile("filename.txt");
// #include <CkHttp.h>
// #include <CkJsonObject.h>
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
// void on_center_button() {
// 	static bool pressed = false;
// 	pressed = !pressed;
// 	if (pressed) {
// 		pros::lcd::set_text(2, "I was pressed!");
// 	} else {
// 		pros::lcd::clear_line(2);
// 	}
// }
// std::shared_ptr<okapi::ChassisController> chassis = okapi::ChassisControllerBuilder()
//     .withMotors(
//         {3,4}, // Left motors are 1 & 2 (reversed)
//         {1,2}    // Right motors are 3 & 4
//     )
// 	.build();
/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "[init]");

	// pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
		pros::lcd::set_text(1, "[disabled]");
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
		pros::lcd::set_text(1, "[init comp]");
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
		pros::lcd::set_text(1, "[autonomous]");
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	pros::Motor left_mtr(1);
	pros::Motor left_mtr2(2);
	pros::Motor left_mtr3(3);
	pros::Motor right_mtr(4);
	pros::Motor right_mtr2(5);
	pros::Motor right_mtr3(6);
 

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);
		// chassis.moveRaw(left)
		// chassis->getModel()->tank(left,right);
		// chassis->getModel()->arcade(left,right);
		left_mtr = left;
		left_mtr2 = left;
		left_mtr3 = left;
		right_mtr = right;
		right_mtr2 = right;
		right_mtr3 = right;

		pros::delay(10);
	}
}
