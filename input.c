#include <ncurses.h>
#include <stdio.h>
#include <unistd.h> //for usleep, I think this has something to do with delay??

#define OFF 1
#define ON 2
#define TEXT 3

void openInput(void){
    //prepare to read keys??
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
}

int x,y;
int run;
int enter;
int letter;

int checkInput(int delay){
    int ch = getch();
    if(ch == '\n'|| ch == '\r' || ch == KEY_ENTER){
        enter++;
        if(enter == 1){
            letter = 'V'; 
        }
        else if(enter == 2){
            letter = 'J';
        }
        else if(enter == 3){
            letter = 'O';
        }
        else if(enter == 4){
            run = 0;
        }
        return 5;
    } 
    else if(ch == KEY_LEFT) {
        return 1;
    }
    else if(ch == KEY_RIGHT) {
        return 2;
    } 
    else if(ch == KEY_UP) {
        return 3;
    } 
    else if(ch == KEY_DOWN) {
        return 4;
    }
    usleep(delay);
}  
void closeInput(void){
    //does nothing but must be present
}