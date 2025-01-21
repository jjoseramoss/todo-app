#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
private:
    int id;
    std::string description;
    bool completed;
public:
    Task(int id, const std::string& desc);
    void markComplete();
    std::string getDetails() const;
    int getId() const;
};

#endif // TASK_H