// #include <cstddef>
#include "main.h"
// #include <string>
#include "pros/misc.h"
#include "pros/misc.hpp"
// std::string logs [2] = {"Volvo", "BMW"};
std::vector<std::string> logs = {"Logs started"};
lv_obj_t *logsLabel = lv_label_create(lv_scr_act(), NULL);
unsigned int arr_length = 0;
void DLogsSystem() {
    while (true) {
    //     for (auto i : logs) {
    //     // std::cout << i << ' ';
    // }
     std::string text =logs[0] + "\n"+ logs[1];
                    //    "Turret Target: " + std::to_string(target) + "\n" +
                    //    "Flywheel Target: " + std::to_string(speed) + "\n";

    // put the information in the text area
    lv_label_set_text(logsLabel, text.c_str());
    pros::delay(20);
    }
}


// append to the logs
void DAppendLogs(std::string s) {
    //  std::cout << "CALLED " << "func DAppendLogs" << '\n';
    // std::cout << "CALLED " << s << '\n';
    // std::cout << s << '\n';
    //  std::cout << 'CALLED ' << arr_length << '\n';
    //   std::cout << 'CALLED ' << logs << '\n';
   if (arr_length < 2) {
     logs[arr_length++] = s;
     std::cout << s << '\n';
   } else {
    logs.push_back(logs[1]);
    logs.push_back(logs[2]);
    logs.push_back(s);
    arr_length = 0;
   }
}

void DLogsTask() {
    lv_obj_set_pos(logsLabel, 205, 115);
    pros::Task fieldTask(DLogsSystem);
}
//TODO: UNFINISHED - still todo
