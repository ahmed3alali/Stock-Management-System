#include <iostream>
#include <vector>
#include "ptasksystem.h" // Include your header file
#include "FileHandler.cpp"
class TaskManagementUI {
public: 



    void displayMenu() {
          std::cout<< "===== Task Management System =====" << std::endl;
          std::cout<<"1.Add Task for Your Project" << std::endl;
          std::cout<<"2.Delete Task"<<std::endl;
          std::cout<<"3.Update Task" << std::endl;
          std::cout<<"4.Short Usage Reprt "<< std::endl;
          std::cout<<"5.New User Registration" << std::endl;
          std::cout<<"6.Tasks Search Engine By Name|"<<std::endl;
          std::cout<<"7.Finished Tasks"<<std::endl;
          std::cout<<"8.Un-Finished Tasks"<<std::endl;
          std::cout<<"9.Fast Task STATUS Update !!"<<std::endl;
          std::cout<<"10.User Report By ID  !!"<<std::endl;
          std::cout<<"11.!! Delete A User  !!"<<std::endl;
          std::cout<<"12 EXIT"<<std::endl;

        std::cout << "Enter your choice: "; // I am going to enter onI am going to 
    
    // lets go to the nextoflf,g
    }

   

FileHandler c;




    void start() {
        std::vector<Project> projects; // Empty vector of projects
        std::vector<User> users;
          std::vector<Task> tasks;
        std::string nameToDlete; // Empty vector of users

c.readTasksFromFile(tasks,users,projects);


        int choice;
        while (true) {
            displayMenu();
            std::cin >> choice;
            std::cin.ignore(); // Clear the input buffer

            switch (choice) {
                case 1:
                  //c.addTaskAndHandleFiles(projects,users,tasks);
                 
                  c.addTasksAndHandleFilesVersionTwo(projects,users,tasks);

                    break;
                case 2:
                c.deleteTask(tasks);
                    //std::cout << "Exiting..." << std::endl;
                    break;

                    case 3:
                c.updateTaskInfo(tasks);
                break;
                case 4:
                c.fullSystemReport(tasks,users,projects);
                break;

                case 5:
                c.newUser(users);
                break;

                case 6:
                c.findTaskByName(tasks,users,projects);
                break;

                case 9:
                c.UpdateTaskStatus(tasks);
                break;
                

    
    
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
};

int main() {
  
    // Instantiate the UI and start the program
    
    TaskManagementUI ui;
    ui.start();

    return 0;
}
