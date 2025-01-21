#include <iostream>
#include <string>
#include <vector>

#include "task.h"
#include "task_manager.h"
#include "utils.h"



int main (){
    std::cout << "Welcome to the To-Do List App!\n";
    std::vector<Task> tasks;
    int nextId = 1;
    int choice;

    while(true){
        showMenu();
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                addTask(tasks, nextId);
                break;

            case 2:
                viewTasks(tasks);
                break;

            case 3:
                int completeId;
                std::cout << "Enter task id to mark as complete: ";
                std::cin >> completeId;
                completeTask(tasks, completeId);
                break;

            case 4:
                int deleteId;
                std::cout <<"Enter task id to delete: ";
                std::cin >> deleteId;
                deleteTask(tasks, deleteId);
                break;

            case 5:
                std::cout << "Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        std::cout << '\n';
    }
    
    return 0;
}