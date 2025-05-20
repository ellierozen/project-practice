#ifndef TASK_H
#define TASK_H

#include <string>

using namespace std;


class Task{
    private:
        string taskName;
        string className;
        int priority;
        int progress;
        int dueDate;


    public:
        void setTaskName(const string&);
        string getTaskName();
        void setDueDate(int);
        int getDueDate();
        void setClassName(const string&);
        string getClassName();
        void setPriorityNum(int);
        int getPriorityNum();

        void setSortType(const string&);
        void changeProgress(int);
        void markComplete();
        void editTask(const string&);


};
#endif