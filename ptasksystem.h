#ifndef PTASKSYSTEM_H
#define PTASKSYSTEM_H

#include <iostream>
#include <vector>
#include <string>

class User;
class Task;
class Project;
class User
{
private:
   
    std::vector<Project *> projects;
    std::vector<Task *> tasks;

public:


 std::string name;
    int userID;
std::string hisRole;
    User(std::string userName, std::string userRole, int id) : name(userName), hisRole(userRole),userID(id)  {}

    void assignProject(Project *project)
    {
        projects.push_back(project);
    }

    const std::vector<Project *> getProjects() const
    {
        return projects;
    }

    std::vector<Task *> getTasks()
    {
        return tasks;
    }

    void assignTask(Task *task)
    {
        tasks.push_back(task);
    }

    // Getters for user properties
    std::string getName() const { return name; }
    int getUserId() const { return userID; }
    // Other getters related to projects, tasks, etc.
};
class Project
{
private:
   
    

public:


std::vector<Task *> tasks;
    std::vector<User *> users;
 std::string name;
    std::string description;

    Project(std::string projectName) : name(projectName) {}

    void addTask(Task *newTask)
    {
        tasks.push_back(newTask);
    }

    void addUser(User *newUser)
    {
        users.push_back(newUser);
        newUser->assignProject(this);
    }





    // Getters for project properties
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }
    // Other getters related to tasks, users, etc.
};


class Task
{




public:
    std::string name;
    std::string description;
    std::string category;
    std::string time;
    std::string label;
    std::string status;

    User *assignedUser;
    Project *assignedProject;
   Task(std::string taskName, std::string taskDesc, std::string taskCatg, std::string taskTime,std::string taskLabel, User* user, Project* project, std::string theStatus)
    {
this->name= taskName;
this->description= taskDesc;
this->category= taskCatg;
this->time = taskTime;
this->label = taskLabel;
this->status = theStatus;


assignedUser = user ? user : new User("temp", "temp", 0);
    assignedProject = project ? project : new Project("temp");

    }


    void assignUser(User *user)
    {
        assignedUser = user;
        user->assignTask(this);
    }

    void setName(const std::string &newName)
    {
        name = newName;
    }

    std::vector<Project *> assignedProjects;

   

    std::string getAssignedProject() const
    {
        return assignedProject->getName();
    }

    void setDescription(const std::string &newDesc)
    {
        description = newDesc;
    }

    // Getters for task properties
    std::string getName() const { return name; }
    std::string getDescription() const { return description; }

    std::string getUserName() const
    {

        return assignedUser->getName();
    }
    // Other getters for category, priority, etc.
};



class FileHandler
{
public:
    /*static void writeTaskIntoFile(const std::string& filename, const Task& task);
    static void rewriteTaskIntoFile(const std::string& filename, const std::vector<Task>& tasks);
    static std::vector<Task> loadTasksFromFile(const std::string& filename);*/

  void writeTasksIntoFile(const std::vector<Task>& theAddedTask);
  void addTasksAndHandleFilesVersionTwo(std::vector<Project>& projects, std::vector<User>& users, std::vector<Task>& theTasks);
void addTaskAndHandleFiles(std::vector<Project>& projects,std::vector<User>& users,std::vector<Task>& theTasks);
void readTasksFromFile(std::vector<Task>& theTasks, std::vector<User>& theUsers, std::vector<Project>& theProjects);
void deleteTask(std::vector<Task>& theTasks);
void updateFileWithTasks(const std::vector<Task>& tasks);
void updateTaskInfo(std::vector<Task>& tasks);
void fullSystemReport(std::vector<Task>& chosenTasks, std::vector<User>& chosenUsers, std::vector<Project>& chosenProjects);
void newUser(std::vector<User>&theUsers);
void findTaskByName(std::vector<Task>& task, std::vector<User>& theUserList, std::vector<Project>& theProjList);
void getTasks(const std::vector<Task>& tasks, const std::string& projectName);
void UpdateTaskStatus(std::vector<Task>& tasks);
void addTasksAndHandleFilesVersionThree(std::vector<Project>& projects, std::vector<User>& users, std::vector<Task>& theTasks);
};

#endif /* PTASKSYSTEM_H */
