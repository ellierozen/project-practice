#include "ToDo.h"
#include <iostream>


void ToDo::addItem(const string& item){
    items.push_back(item);
}

void ToDo::removeItem(int item){
    for(int i = 0; i < items.size(); i++){
        if (i = item){
            items.erase(items.begin() + i);
        }
        else{
            cout << "item doesn't exist" << endl;
        }
    }
}

void ToDo::editItem(int index, const string& newItem) {
    if (index >= 0 && index < items.size()) {
        items[index] = newItem;
    }
}

string ToDo::getItem(int index) const{
    if (index >= 0 && index < items.size()) {
        return items[index];
    }
    return "";
}

void ToDo::displayItems() const{
    for (int i = 0; i < items.size(); ++i) {
        cout << i + 1 << ". " << items[i] << endl;
    }
}

int ToDo::getSize() const {
    return items.size();
}