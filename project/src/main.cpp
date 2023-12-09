#include "main.h"
#include "screen/info.hpp"
#include "screen/images.hpp"
#include "screen/logs.hpp"
#include "auton/auton.hpp"
#include "screen/auton_select.hpp"
#include "outtake/Outtake.hpp"
// #include "test.cpp"
// #include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/impl/chassis/controller/chassisControllerBuilder.hpp"
#include "../include/pros/misc.h"
#include "intake/intake.h"
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
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		// pros::lcd::set_text(2, "I was pressed!");
		// TestFunc();
	} else {
		// pros::lcd::clear_line(2);
		// StopTestFunc();
	}
}
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
	// pros::lcd::initialize();
	DinitializeInformation();
	DinitializeField();
	DinitializeAutonSelect();
	std::cout << "\x1B[2J\x1B[H";
	 std::cout << R"(

.dP"Y8    db       db    88  88 88 88     
`Ybo."   dPYb     dPYb   88  88 88 88     
o.`Y8b  dP__Yb   dP__Yb  888888 88 88  .o 
8bodP' dP""""Yb dP""""Yb 88  88 88 88ood8 
       
)" << '\n';
std::cout << "\033[1;33mMade by saahil (saahild.com) and ran in Pros\033[00m";

	// DautonSelectTask();
	// runAuton();
	// DLogsTask(); //currently broken
	//   display::initializeAutonSelect();
	    // display::initializeField();
//   display::initializeInformation();
	// pros::lcd::set_text(1, "[init]");
	// pros::lcd::set_text_color(COLOR_GREEN_YELLOW);
	// pros::lcd::set_text(2, "made by saahil (https://saahild.com)");
	// pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
		// pros::lcd::set_text(1, "[disabled]");
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
		// pros::lcd::set_text(1, "[init comp]");
}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *bb
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
		// pros::lcd::set_text(1, "[autonomous]");
		runAuton();
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
	pros::Motor left_mtr(1); // right
	pros::Motor left_mtr2(3); //left
	pros::Motor right_mtr(2); // right 
	pros::Motor right_mtr2(4); //left
	

	while (true) {
		pros::lcd::print(0, "%d %d %d", (pros::lcd::read_buttons() & LCD_BTN_LEFT) >> 2,
		                 (pros::lcd::read_buttons() & LCD_BTN_CENTER) >> 1,
		                 (pros::lcd::read_buttons() & LCD_BTN_RIGHT) >> 0);
		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);
		// std::cout << left_mtr.get_position() << std::endl;
		// std::cout << 'test log' << std::endl;
	// left_mtr.set_encoder_units(0);
	// left_mtr.set_position
		// chassis.moveRaw(left)
		// chassis->getModel()->tank(left,right);
		// chassis->getModel()->arcade(left,right);
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A) && master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			master.rumble(". - .");	
			autonomous();
			master.rumble("-");	
		}
		 if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A) || master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
if (master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
			 ReverseIntake();
		}
		if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
			Moveintake();
			MoveOuttake();
		}
		} else {
			// StopIn
			StopIntake();
			StopOuttake();
		}
		// if(master.get_digital(pros::E_CONTROLLER_DIGITAL_X)) {
		// 	MoveOuttake();
		// } else {
		// 	StopOuttake();
		// }
		left_mtr = left;
		left_mtr2 = left;
		right_mtr = -right;
		right_mtr2 = -right;
		
		// // x = 
		// DAppendLogs("for loop thiing"); //broken below
		// DAppendLogs("for loop thiing2");
		// DAppendLogs("for loop thiing3");
		// DAppendLogs("for loop thiing4");
		
		pros::delay(10);
	}
}
