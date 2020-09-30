#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

void StartAnimation(char* str, int millis){
    int i;
    for(i = 0; str[i] != '\0'; i++){
        putchar(str[i]);
        Sleep(millis);
    }
    printf("\n");
}

void ChangeColor(short color){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

void PrintColoredString(char* String, short color){
    ChangeColor(0x00|color);
    printf(String);
    ChangeColor(0x00|0x0F);
}

void getXY(int* x, int* y) {
   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);  //Cursor "Entity"
   CONSOLE_SCREEN_BUFFER_INFO bufferInfo;       //initializing a variable for the info of the Window
   GetConsoleScreenBufferInfo(h, &bufferInfo);  //Get the info of the Window Screen
   *x=bufferInfo.dwCursorPosition.X;            //XPos of the cursor
   *y=bufferInfo.dwCursorPosition.Y;            //YPos of the cursor
}

void gotoXY(int XPos, int YPos) {
   COORD coord; //Vector2 Struct
   coord.X = XPos; coord.Y = YPos;  //Setting the coordinates
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); //Go to the Coordinates
}

char* TabScroller(char* Array[], int ArraySize, char* FunctionName){

    int i;
    char input;

    while(1){
        printf("%s (Tab per cambiare) > %s   ", FunctionName, Array[i]); //Every cycle scroll the given Array

        while ((input = getch()) != EOF) {
            if (input == '\t'){ //"Tab" ey to switch
                printf("\r");
                i++;
                break;
            } else if (input == '\r') {
                printf("\n");   //"Enter" key to confirm the Choose
                return Array[i];
            }
        } if (i == ArraySize) i = 0; //Handler for resetting the Array Scroller
    }
}

void PrintRemoveChar(char* String, char CharToRemove){
    int i = 0;

    while(i != strlen(String)){
        if (String[i] == CharToRemove){
            printf(" ");
        } else {
            printf("%c", String[i]);
        }
        i++;
    }
}

char* SaveWithChar(char* String, char CharToAdd){
    int i = 0;

    while(i != strlen(String)){
        if (String[i] == ' '){
            String[i] = CharToAdd;
        }
        i++;
    }

    return String;
}