#include <iostream>
#include <string>
#include <vector>

#include "task.h"
#include "task_manager.h"
#include "utils.h"

void test_task() {
    Task task(1, "Task to do list");
    std:: cout << task.getDetails() << std::endl;
    task.markComplete();
    std::cout << task.getDetails() << std::endl << "Task completed lol this is a test" << std::endl;
}


int main (){
    test_task();
}