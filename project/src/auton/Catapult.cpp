#include "main.h"
pros::Motor out2(10);
void CForward() {
out2 = 127;
}

void CBackwards() {
    out2 = -127;
}
void Cstop() {
    out2 = 0;
}