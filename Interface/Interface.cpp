#include "Interface.h"
#include <ncurses.h>

void Interface::run() {
    ToDo list;
    initscr();              // Start ncurses mode
    noecho();               // Don't echo keypresses
    cbreak();               // Disable line buffering
    curs_set(1);            // Show cursor

    int ch;
    char input[100];
    bool running = true;

    while (running) {
        clear();
        mvprintw(0, 0, "=== To-Do List ===");
        for (int i = 0; i < list.getSize(); ++i) {
            mvprintw(i + 2, 2, "%d. %s", i + 1, list.getItem(i).c_str());
        }

        mvprintw(list.getSize() + 4, 0, "a - Add | e - Edit | d - Delete | q - Quit");
        refresh();

        ch = getch();

        if (ch == 'a') {
            echo();
            mvprintw(list.getSize() + 6, 0, "Enter new item: ");
            getstr(input);
            list.addItem(input);
            noecho();
        }
        else if (ch == 'd') {
            echo();
            int index;
            mvprintw(list.getSize() + 6, 0, "Enter item number to delete: ");
            scanw("%d", &index);
            list.removeItem(index - 1);
            noecho();
        }
        else if (ch == 'e') {
            echo();
            int index;
            char input[100];
        
            mvprintw(list.getSize() + 6, 0, "Enter item number to edit: ");
            scanw("%d", &index);
            getch(); // consume newline
        
            mvprintw(list.getSize() + 7, 0, "Enter edited item: ");
            getstr(input);
            list.editItem(index - 1, input);
            noecho();
        }
        else if (ch == 'q') {
            running = false;
        }
    }

    endwin(); // End ncurses mode
}
