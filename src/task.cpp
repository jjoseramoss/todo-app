#include "task.h"

Task::Task(int id, const std::string& desc) : id(id), description(desc), completed(false) {}

void Task::markComplete() {
    completed = true;
}

std::string Task::getDetails() const {
    return std::to_string(id) + ". " + description + (completed ? " [Completed]" : "");
}

int Task::getId() const {
    return id;
}