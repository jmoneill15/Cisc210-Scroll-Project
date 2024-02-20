#include <stdio.h>
#include "scroll.h"
#include <ncurses.h>
#include <unistd.h>
void handler(unsigned int code);

//global variables
int run = 1;
char letter = 'A';
float ySpeed = 0.0, xSpeed = 0.0;
int enter = 0;
int x,y;
int xOffset = 0;
int main(void){
    
    openDisplay();
    openInput();
    int x = 0, y = 0;    
    while(run == 1){
        xSpeed = xSpeed + x/100.0;
        ySpeed = ySpeed + y/100.0;
        if(checkInput(1000) == 1){                
            x--;
            if(x<0){
                x = 7;
            }
        }
        else if (checkInput(1000) == 2){
            x++;
            if(x>7){
                x = 0;
            }
        }
        else if(checkInput(1000) == 3){
            y--;
            if(y<0){
                y = 7;
            }
        }
        else if(checkInput(1000) == 4){
            y++;
            if(y>7){
                y = 0;
            }
        }
        //checkInput(5000);
        displayLetter(letter, xSpeed, ySpeed);
    
    //add the else if (checkinput(
    }
    clearDisplay();
    closeDisplay();
    return 0;
}