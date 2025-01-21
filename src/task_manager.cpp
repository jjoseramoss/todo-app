#include "task_manager.h"
#include <iostream>
#include <algorithm>

void addTask(std::vector<Task>& tasks, int& nextId) {
    std::string desc;
    std::cout << "Enter task description: ";
    std::cin.ignore();
    std::getline(std::cin, desc);
    tasks.emplace_back(nextId++, desc);
}

void viewTasks(const std::vector<Task>& tasks){
    if(tasks.empty()){
        std::cout << "No tasks to display\n";
        return;
    }
    for(const auto& task : tasks){
        std::cout <<task.getDetails() << '\n';
    }
}

void completeTask(std::vector<Task>& tasks, int taskId){
    for(auto& task : tasks){
        if(task.getId() == taskId){
            task.markComplete();
            std::cout << "Task marked as complete\n";
            return;
        }
    }
    std::cout << "Task not found\n";

}

void deleteTask(std::vector<Task>& tasks, int taskId){
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
        [taskId](const Task& task){return task.getId() == taskId; }),
        tasks.end());
    std::cout << "Task deleted\n";
}