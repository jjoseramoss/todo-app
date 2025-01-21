#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H


#include <vector>
#include "task.h"

void addTask(std::vector<Task>& tasks, int& nextId);
void viewTasks(const std::vector<Task>& tasks);
void completeTask(std::vector<Task>& tasks, int taskId);
void deleteTask(std::vector<Task>& tasks, int taskId);

#endif // TASK_MANAGER_H