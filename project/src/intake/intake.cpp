#include "main.h"
pros::Motor intake_mtr (6);
void Moveintake() {
intake_mtr = -127;
}
void ReverseIntake() {
    intake_mtr = -127;
}
void StopIntake() {
intake_mtr.brake();
}