#ifndef TODO_H
#define TODO_H

#include <string>
#include <vector>

using namespace std;

class ToDo{
    private:
        vector<string> items;

    public:
        void addItem(const string&);
        void removeItem(int);
        void editItem(int index, const string& newItem);
        string getItem(int) const;
        void displayItems() const;
        int getSize() const;
};
#endif