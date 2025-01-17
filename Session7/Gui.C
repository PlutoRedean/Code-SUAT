#include <ncurses.h>
#include "Gui.h"
#include <cstring>
using namespace std;

void Gui::init() {
    initscr();                  /* Start curses mode              */
    refresh();                  /* Print it on to the real screen */
    win = stdscr;
    refresh();
    curs_set(0);
    wrefresh(win);
    noecho();
    cbreak();
    keypad(win, true);
    nodelay(win, true);
    flushinp();
    for (int i = 0; i < 20; i++) {
        mvaddch(i, 4, '|');
        mvaddch(i, 66, '|');
    }
}

int Gui::get() {
    int c = wgetch(win);
    flushinp();
    return c;
}

void Gui::paintat(size_t rw, size_t cl, char c) {
    mvwaddch(win, rw, cl, c);
    wrefresh(win);
    return;
}

void Gui::printMsg(int row, int col, char* prompt, int v) {
    mvwprintw(win, row, col, prompt);
    char s[32];
    sprintf(s, "%d", v);
    mvwprintw(win, row, col+strlen(prompt)+1, s);
}

void Gui::clear() {
    werase(win);
    for (int i = 0; i < 20; i++) {
        mvaddch(i, 4, '|');
        mvaddch(i, 66, '|');
    }

}
