#include <stdio.h>
#include "scroll.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdint.h>

#define WHITE 1
#define BLACK 2

#define OFF 3
#define ON 4
#define TEXT 3

void draw_grid(uint16_t pixels[8][8]) {
    for(int y=0; y<8; y++) {
        move(y,0);
        for(int x=0; x<8; x++) {
            if(pixels[7-x][y]) {
                attron(COLOR_PAIR(pixels[7-x][y]));
                addch('#');
                attroff(COLOR_PAIR(pixels[7-x][y]));
           } else { 
                addch(' ');
           }
        }
    }
    refresh(); 
}

void fill_pixels(uint16_t pixels[8][8], uint16_t color) {
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            pixels[i][j] = color;
        }
    }
}

void openDisplay(void){
    uint16_t pixel[8][8];
    initscr();
    start_color();
    init_pair(ON, COLOR_WHITE, COLOR_WHITE);
    init_pair(OFF, COLOR_BLACK, COLOR_BLACK);
    init_pair(TEXT, COLOR_WHITE, COLOR_BLACK);
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    fill_pixels(pixel, BLACK);
}

/*
int lastx = -1, lasty = -1, laston = -1;
void displayDot(char x, char y, int on){
    if(x==lastx && y==lasty && on==laston){
        return;
    }
    attron(COLOR_PAIR(OFF));
    mvaddch(lasty, lastx, ' ');
    if(on){
        attron(COLOR_PAIR(ON));
        mvaddch(y,x,' ');
    }
    lastx = x;
    lasty = y;
}
*/
void displayLetter(char letter, int xOffset, int yOffset){
    uint16_t pixel[8][8];
    attron(COLOR_PAIR(ON));
    if(letter == 'A'){
        fill_pixels(pixel, BLACK);
        init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
        attron(COLOR_PAIR(ON));
        pixel[(7+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(6+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(5+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(4+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(3+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(2+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(0+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(1+yOffset)%8]=WHITE;
    
        pixel[(7+xOffset)%8][(2+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(3+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(5+yOffset)%8]=WHITE;
        pixel[(6+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(5+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(4+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(3+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(2+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(0+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(0+xOffset)%8][(1+yOffset)%8]=WHITE;
        pixel[(0+xOffset)%8][(2+yOffset)%8]=WHITE;
        pixel[(0+xOffset)%8][(3+yOffset)%8]=WHITE;
        pixel[(0+xOffset)%8][(5+yOffset)%8]=WHITE;
    
        pixel[(7+xOffset)%8][(6+yOffset)%8]=WHITE;
        pixel[(0+xOffset)%8][(6+yOffset)%8]=WHITE;
    } 
    if(letter == 'V'){
    //V
        fill_pixels(pixel, BLACK);
        attron(COLOR_PAIR(ON));
        pixel[(7+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(1+yOffset)%8]=WHITE;
        pixel[(6+xOffset)%8][(2+yOffset)%8]=WHITE;
        pixel[(5+xOffset)%8][(3+yOffset)%8]=WHITE;
        pixel[(4+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(4+xOffset)%8][(5+yOffset)%8]=WHITE;
        pixel[(4+xOffset)%8][(5+yOffset)%8]=WHITE;
        pixel[(3+xOffset)%8][(5+yOffset)%8]=WHITE;
        pixel[(3+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(2+xOffset)%8][(3+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(2+yOffset)%8]=WHITE;
        pixel[(0+xOffset)%8][(1+yOffset)%8]=WHITE;
        pixel[(0+xOffset)%8][(0+yOffset)%8]=WHITE;
    }
    if(letter == 'J'){
    //J Letter      
        fill_pixels(pixel, BLACK);
        attron(COLOR_PAIR(ON));
        pixel[(1+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(1+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(2+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(3+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(5+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(6+yOffset)%8]=WHITE;

        pixel[(7+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(5+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(6+yOffset)%8]=WHITE;

        pixel[(6+xOffset)%8][(7+yOffset)%8]=WHITE;
        pixel[(5+xOffset)%8][(7+yOffset)%8]=WHITE;
        pixel[(4+xOffset)%8][(7+yOffset)%8]=WHITE;
        pixel[(3+xOffset)%8][(7+yOffset)%8]=WHITE;
        pixel[(2+xOffset)%8][(7+yOffset)%8]=WHITE;
    } 
    if(letter == 'O'){
    //O Letter
        fill_pixels(pixel, BLACK);
        attron(COLOR_PAIR(ON));
        pixel[(6+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(5+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(4+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(3+xOffset)%8][(0+yOffset)%8]=WHITE;
        pixel[(2+xOffset)%8][(0+yOffset)%8]=WHITE;

        pixel[(7+xOffset)%8][(1+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(2+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(3+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(5+yOffset)%8]=WHITE;
        pixel[(7+xOffset)%8][(6+yOffset)%8]=WHITE;

        pixel[(1+xOffset)%8][(1+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(2+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(3+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(4+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(5+yOffset)%8]=WHITE;
        pixel[(1+xOffset)%8][(6+yOffset)%8]=WHITE;

        pixel[(6+xOffset)%8][(7+yOffset)%8]=WHITE;
        pixel[(5+xOffset)%8][(7+yOffset)%8]=WHITE;
        pixel[(4+xOffset)%8][(7+yOffset)%8]=WHITE;
        pixel[(3+xOffset)%8][(7+yOffset)%8]=WHITE;
        pixel[(2+xOffset)%8][(7+yOffset)%8]=WHITE;
    }
    draw_grid(pixel);
    refresh();
}

void closeDisplay(void){
    endwin();
}

void clearDisplay(void){
    uint16_t pixel[8][8];
    attron(COLOR_PAIR(BLACK));
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            pixel[i][j] = BLACK;
        }
    }
}