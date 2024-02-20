#include <stdio.h>
#include <ncurses.h>

void openDisplay(void);

void closeDisplay(void);

void displayLetter(char letter, int xOffset, int yOffset);
void displayDot(char x, char y, int on);

void clearDisplay(void);

void openInput(void);

int checkInput(int delay);