#include <stdio.h>
#include <curses.h>

typedef struct Pacman{
    int x;       // パックマンのx座標
    int y;       // パックマンのy座標
    char direction; // パックマンの向き（'u': 上, 'd': 下, 'l': 左, 'r': 右）
} ;

int main() {
    Pacman pacman;
    pacman.x = 10;
    pacman.y = 10;
    pacman.direction = 'r';

    initscr();
    start_color();
    cbreak();             
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    init_pair(1, COLOR_YELLOW, COLOR_BLACK);

    while (1) {
        clear();  

        attron(COLOR_PAIR(1));
        mvaddch(pacman.y, pacman.x, 'C');
        attroff(COLOR_PAIR(1));

        int op = getch();

        switch (op) {
        case ERR:
            break;
        case KEY_UP:
            pacman.direction = 'u';
            pacman.y--;
            break;
        case KEY_DOWN:
            pacman.direction = 'd';
            pacman.y++;
            break;
        case KEY_LEFT:
            pacman.direction = 'l';
            pacman.x--;
            break;
        case KEY_RIGHT:
            pacman.direction = 'r';
            pacman.x++;
            break;
        case '\n':
            endwin();
            return 0;

        }

        refresh();  // 画面を更新する
    }

    endwin();  // cursesの終了処理

    return 0;
}




