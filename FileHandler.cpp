#include "ptasksystem.h"

#include <algorithm> 
#include <iostream>
#include <fstream>
#include <string>



void FileHandler:: writeTasksIntoFile(const std::vector<Task>& theAddedTask) {


std::ofstream file("database.txt");

if (file.is_open())
{
    /* code */
for (const auto& currentTask:theAddedTask)
{

file<<currentTask.name<<"\n";
file<<currentTask.assignedProject->name<<"\n";
file<<currentTask.assignedUser->name<<"\n";
file<<currentTask.description<<"\n";
file<<currentTask.category<<"\n";
file<<currentTask.label<<"\n";
file<<currentTask.time<<"\n";
file<<currentTask.status<<"\n";


    /* code */
}
file.close();

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif


std::cout<<"Task info written into the file.";


}



}

void FileHandler::addTaskAndHandleFiles(std::vector<Project>& projects, std::vector<User>& users, std::vector<Task>& theTasks) {
    std::string taskName, taskDesc, userName, projectName, category, label, day;
    int userId;
    std::string statusy ="UF";
    Project* project;
    User* user;

    std::string userROLE = "nothing";
    

    // Get task information from the user
    std::cout << "Enter task name: ";
    std::cin.ignore(); // Ignore newline in buffer
    std::getline(std::cin, taskName);

    // Ensure the first letter of the task name is capitalized
    if (!taskName.empty()) {
        taskName[0] = std::toupper(taskName[0]);
    }

    std::cout << "Enter task description: ";
    std::getline(std::cin, taskDesc);

    // Get user information for assigning the task
    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);
    
  

User newUser(userName,userROLE,0);


    // Get project information for the task
    std::cout << "Enter project name for the task: ";
    std::cin.ignore(); // Ignore newline in buffer
    std::getline(std::cin, projectName);

  std::cout << "Categorize Your Task (Work-Gym etc.) ";
    std::cin.ignore(); // Ignore newline in buffer
    std::getline(std::cin, category);


  std::cout << "Label your tasks(URGENT-HIGH ETC.): ";
    std::cin.ignore(); // Ignore newline in buffer
    std::getline(std::cin, label);



  std::cout << "Give a day: ";
    std::cin.ignore(); // Ignore newline in buffer
    std::getline(std::cin, day);



    Project newProject(projectName);

    Task newTask(taskName, taskDesc,category,day,label, &newUser, &newProject,statusy);

    theTasks.push_back(newTask);
users.push_back(newUser);
projects.push_back(newProject);
    writeTasksIntoFile(theTasks);


    
}


void FileHandler::addTasksAndHandleFilesVersionTwo(std::vector<Project>& projects, std::vector<User>& users, std::vector<Task>& theTasks) {
    std::string taskName, projectName, userName, taskDesc, taskCatg, taskLabel, taskDay, taskStatus;

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    // Get task information from the user
    std::cout << "Enter Task Name: ";
    std::getline(std::cin, taskName);

    std::cout << "Enter Assigned Project Name: ";
    std::getline(std::cin, projectName);

    std::cout << "Enter Assigned User Name: ";
    std::getline(std::cin, userName);

    std::cout << "Enter Task Description: ";
    std::getline(std::cin, taskDesc);

    std::cout << "Enter Task Category: ";
    std::getline(std::cin, taskCatg);

    std::cout << "Enter Task Label: ";
    std::getline(std::cin, taskLabel);

    std::cout << "Enter Task Day: ";
    std::getline(std::cin, taskDay);

    std::cout << "Enter Task Status: ";
    std::getline(std::cin, taskStatus);

    // Create and add the task to theTasks vector
    User* tempUser = new User("Mohd", "temp", 0);
    Project* tempProject = new Project("temp");
    Task newTask(taskName, taskDesc, taskCatg, taskDay, taskLabel, tempUser, tempProject, taskStatus);
    theTasks.push_back(newTask);

    // Find the corresponding project in the projects vector
    Project* assignedProject = nullptr;
    for (auto& project : projects) {
        if (project.getName() == projectName) {
            assignedProject = &project;
            break;
        }
    }

    // If project not found, create a new project and add it to the projects vector
    if (!assignedProject) {
        Project newProject(projectName);
        projects.push_back(newProject);
        assignedProject = &projects.back();
    }

    // Assign the task to the project and the user
    assignedProject->addTask(&theTasks.back());
    //tempUser->assignTask(&theTasks.back());

    // Write the task information to the file
    writeTasksIntoFile(theTasks);
}



void FileHandler::addTasksAndHandleFilesVersionThree(std::vector<Project>& projects, std::vector<User>& users, std::vector<Task>& theTasks) {
    Task newTask("", "", "", "", "", nullptr, nullptr, "UF"); // Default task with empty values

    // Get task information from the user
    std::cout << "Enter Task Name: ";
    std::getline(std::cin, newTask.name);

    // Ensure the first letter of the task name is capitalized
    if (!newTask.name.empty()) {
        newTask.name[0] = std::toupper(newTask.name[0]);
    }

    std::cout << "Enter Assigned Project Name: ";
    std::getline(std::cin, newTask.assignedProject->name);

    std::cout << "Enter Assigned User Name: ";
    std::getline(std::cin, newTask.assignedUser->name);

    std::cout << "Enter Task Description: ";
    std::getline(std::cin, newTask.description);

    std::cout << "Enter Task Category: ";
    std::getline(std::cin, newTask.category);

    std::cout << "Enter Task Label: ";
    std::getline(std::cin, newTask.label);

    std::cout << "Enter Task Day: ";
    std::getline(std::cin, newTask.time);

    // Temporary assignment for user (Role: "temp", ID: 0)
    User tempUser("temp", "temp", 0);
    users.push_back(tempUser);

    // Create and add the task to theTasks vector
    theTasks.push_back(newTask);
    theTasks.back().assignedUser = &tempUser; // Assign user to the task

    // Find the corresponding project in the projects vector
    Project* assignedProject = nullptr;
    for (auto& project : projects) {
        if (project.getName() == newTask.assignedProject->name) {
            assignedProject = &project;
            break;
        }
    }

    // If the project is not found, create a new project and add it to the projects vector
    if (!assignedProject) {
        Project newProject(newTask.assignedProject->name);
        projects.push_back(newProject);
        assignedProject = &projects.back();
    }

    // Assign the task to the project
    assignedProject->addTask(&theTasks.back());

    // Write the task information to the file
    writeTasksIntoFile(theTasks);
}





void FileHandler::readTasksFromFile(std::vector<Task>& theTasks, std::vector<User>& theUsers, std::vector<Project>& theProjects) {
    int tempId= 012;
    std::string tempRole = "nothing";
    
    std::ifstream file("database.txt");

    if (file.is_open()) {
        std::string taskName, projectName, userName,category,label,day, taskDescription, statusStrg;
        


        while (std::getline(file, taskName)) {
            std::getline(file, projectName);
            std::getline(file, userName);
            std::getline(file,taskDescription);
            std::getline(file,category);
            std::getline(file,label);
            std::getline(file,statusStrg);

User* newUser = new User(userName,tempRole,tempId);
Project* newProject = new Project(projectName);
            // Assuming you have constructors that take these parameters
            Task newTask(taskName,taskDescription,category,day,label,new User(userName,tempRole,tempId), new Project(projectName),statusStrg);
            theTasks.push_back(newTask);
            theUsers.push_back(*newUser);
            theProjects.push_back(*newProject);


delete newUser;
    delete newProject;

        }

        file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
}


void FileHandler::deleteTask(std::vector<Task>& theTasks) {
    std::string taskNameToDelete;
    std::cout << "Enter the name of the task to delete: ";
    std::getline(std::cin, taskNameToDelete);

    auto it = std::find_if(theTasks.begin(), theTasks.end(),
                           [&taskNameToDelete](const Task& task) {
                               return task.getName() == taskNameToDelete;
                           });

    if (it != theTasks.end()) {
        std::cout << "Task found: " << it->getName() << std::endl; // Verify the found task name
        theTasks.erase(it);
        writeTasksIntoFile(theTasks);
        std::cout << "Task '" << taskNameToDelete << "' deleted successfully." << std::endl;
    } else {
        std::cout << "Task '" << taskNameToDelete << "' not found." << std::endl;
    }
}



void FileHandler::updateFileWithTasks(const std::vector<Task>& tasks) {
    std::ofstream file("database.txt");
    if (file.is_open()) {
        for (const Task& task : tasks) {
            file << task.name << "\n";
            file << task.assignedProject->name << "\n";
            file << task.assignedUser->name << "\n";
            file<<task.description<< "\n";
            file<<task.category<< "\n";
            file<<task.label<< "\n";
            file<<task.time<< "\n";
            file<<task.status<< "\n";
            // Add other task details as needed, like description, category, priority, etc.
        }
        file.close();
        std::cout << "Tasks updated in the file." << std::endl;
    } else {
        std::cout << "Unable to open file to update tasks." << std::endl;
    }
}



void FileHandler::updateTaskInfo(std::vector<Task>& tasks) {
    std::string taskName;
    std::string newStatus;
    std::cout << "Enter the name of the task to update: ";
    std::cin.ignore(); // Ignore newline in buffer
    std::getline(std::cin, taskName);

    bool found = false;
    for (Task& task : tasks) {
        if (task.getName() == taskName) {
            found = true;
        
              
            std::cout << "Enter new task name (or leave empty to keep unchanged): ";
            std::string newName;
            std::getline(std::cin, newName);
            if (!newName.empty()) {
                task.name = newName;
            }

            std::cout << "Enter new task description (or leave empty to keep unchanged): "; /// there is a note here 
            std::string newDesc;
            std::getline(std::cin, newDesc);
            if (!newDesc.empty()) {
                task.description = newDesc;
            }


                std::cout << "Enter new task category (or leave empty to keep unchanged): ";
            std::string newCatg;
            std::getline(std::cin, newCatg);
            if (!newDesc.empty()) {
                task.category = newCatg;
            }

 std::cout << "Enter new task Status (F-UF) (or leave empty to keep unchanged): ";
            std::string theNewStatus;
            std::getline(std::cin, theNewStatus);
            if (!newDesc.empty()) {
                task.status = theNewStatus;
            }




    std::cout << "Enter new task label (or leave empty to keep unchanged): ";
            std::string newLabel;
            std::getline(std::cin, newLabel);
            if (!newDesc.empty()) {
                task.label = newLabel;
            }


            std::cout << "Assign this task to a different user (yes/no)? ";
            std::string response;
            std::getline(std::cin, response);
            if (response == "yes") {
                std::cout << "Enter new user name: ";
                std::string userName;
                std::getline(std::cin, userName);
                // Assuming a function exists to find a user by name in the users vector
                // You might need to implement a similar function in your code
            

              
                    task.assignedUser->name = userName;
                
            }

            std::cout << "Change the project for this task (yes/no)? ";
            std::getline(std::cin, response);
            if (response == "yes") {
                std::cout << "Enter new project name: ";
                std::string projectName;
                std::getline(std::cin, projectName);
 
              

              
                    task.assignedProject->name=projectName;
                 
            }

            // Update the file with the modified tasks
            updateFileWithTasks(tasks);
            std::cout << "Task information updated successfully." << std::endl;
            break; // Once found and updated, exit the loop
        }
    }

    if (!found) {
        std::cout << "Task not found." << std::endl;
    }
}






void FileHandler::UpdateTaskStatus(std::vector<Task>& tasks) {
    std::string taskName;
    std::cout << "Enter the name of the task to update: ";
    std::cin.ignore(); // Ignore newline in buffer
    std::getline(std::cin, taskName);

    bool found = false;
    for (Task& task : tasks) {
        if (task.getName() == taskName) {
            found = true;
        
                std::cout << "Enter new task status (or leave empty to keep unchanged): ";
            std::string newStatus;
            std::getline(std::cin, newStatus);
            if (!newStatus.empty()) {
                task.status = newStatus;
            }
            
          

            // Update the file with the modified tasks
            updateFileWithTasks(tasks);
            std::cout << "Task information updated successfully." << std::endl;
            break; // Once found and updated, exit the loop
        }
    }

    if (!found) {
        std::cout << "Task not found." << std::endl;
    }
}

















void FileHandler::fullSystemReport(std::vector<Task>& chosenTasks, std::vector<User>& chosenUsers, std::vector<Project>& chosenProjects) {
    int taskCounter = 0;
    int userCounter = 0;
    int projectCounter = 0;

    for (Task& task : chosenTasks) {
        taskCounter++;
    }

    for (User& user : chosenUsers) {
        userCounter++;
    }

    for (Project& project : chosenProjects) {
        projectCounter++;
    }


    std::cout << "=== SYSTEM USAGE REPORT ===" << std::endl;
    std::cout << "NUMBER OF TASKS AVAILABLE IN SYSTEM: " << taskCounter << std::endl;
    std::cout << "NUMBER OF USERS IN SYSTEM: " << userCounter << std::endl;
    std::cout << "NUMBER OF PROJECTS IN SYSTEM: " << projectCounter << std::endl;
}



void FileHandler:: newUser(std::vector<User>&theUsers){


std::string userName;
int userIdrr;
std::string empRole;


std::cout << "=== NEW USER REGISTRATION FORM ===" << std::endl;
std::cout << "=== ENTER USER NAME :" << std::endl;
std::getline(std::cin, userName);



bool validUserId = false;
while (!validUserId)
{
std::cout << "=== CREATE USER ID   :" << std::endl;
std::cin >> userIdrr;

bool userIdTaken = false;

for(const User& user: theUsers) {

if (user.userID==userIdrr)
{
    userIdTaken = true;
    break;
    /* code */
}

if (!userIdTaken) 
{
    validUserId = true;
    /* code */
} else
{
    
        std::cout << "This ID is already taken. Please choose another." << std::endl;
            // Clear input buffer and ignore any remaining characters
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    /* code */
}
   std::cin.ignore();



}
    /* code */

}

std::cout << "=== ENTER EMPLOYEE ROLE:" << std::endl;
std::getline(std::cin,empRole);


User* newUser = new User(userName,empRole,userIdrr);
theUsers.push_back(*newUser);




}





 void FileHandler:: getTasks(const std::vector<Task>& tasks, const std::string& projectName) {
    std::cout << "Welcome to Project: " << projectName << std::endl;
    std::cout << "Tasks assigned to project " << projectName << ":" << std::endl;

    for (const Task& theTask : tasks) {
        if (theTask.assignedProject != nullptr && theTask.assignedProject->name == projectName) {
            std::cout << "====" << std::endl;
            std::cout << "Task name: " << theTask.name << std::endl;
            if (theTask.assignedUser != nullptr) {
                std::cout << "User assigned: " << theTask.assignedUser->name << std::endl;
            }
            std::cout << "Category: " << theTask.category << std::endl;
            std::cout << "====" << std::endl;
        }
    }
}




void FileHandler::findTaskByName(std::vector<Task>& task, std::vector<User>& theUserList, std::vector<Project>& theProjList) {
    std::string projName;

    std::cout << "=== FIND TASK BY PROJECT NAME ===" << std::endl;

    bool projectFound = false;

    while (!projectFound) {
        std::cout << "Enter Project Name to find tasks: ";
        std::getline(std::cin, projName);

        for (const Project& project : theProjList) {
            if (project.getName() == projName) {
              getTasks(task,projName);
                }
                break;
            }
        

        if (!projectFound) {
            std::cout << "Project not found! Try again." << std::endl;
        }
    }

    std::cout << "Project Found Successfully!" << std::endl;
    // Clear input buffer
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

}

    /* code */






