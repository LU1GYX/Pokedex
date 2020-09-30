#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "WinUtils.h"
#include "PokeUtils.h"

int main(){
    Pokemon pokemon;
    Pokemon pokedex[151];
    PokeWeak pokeWeak[2];

    FILE * PokedexFile; //Inizialization of the Pokedex File

    int x0, y0, x, y, i;
    char in1, in2;

    //Initialization of Pokemon Variable, Pokedex File and XYPos for Interactive Menu

    system("mode 80, 45"); //Setting up custom CMD Window width/height

    StartAnimation(title, 5); //Title Animation + Song
    Beep(470, 100); Beep(470, 100); Beep(470, 100); Beep(660, 500); //Beep Boop, beep Boop?
    PokedexInitialization(pokedex, PokedexFile);
    PokemonInitialization(&pokemon);
    LoadPokedex(pokedex, PokedexFile);

    getXY(&x0, &y0);
    x = x0 + 24;
    y = y0;

    while(1){

        SubtitlePreset("\t\t\t\t     MENU\n\n","\t\t    - Premere W o S per Navigare nel Menu -\n\t\t- INVIO per Selezionare, BACKSPACE per Uscire -\n\n");
        printf("\t\t\t  Visualizza il Pokedex.\n");
        printf("\t\t\t  Visualizza le Info di un Pokemon.\n");
        printf("\t\t\t  Inserisci un nuovo Pokemon nel Pokedex.\n");
        printf("\t\t\t  Rimuovi un Pokemon nel Pokedex.\n");
        printf("\t\t\t  Riordina il Pokedex\n");
        printf("\t\t\t  Ricarica il Pokedex\n\n");
        PrintColoredString(line, 0xB);


        gotoXY(x, y);
        in1 = getch();
        switch(in1){  //Main(z) Menu Commands
            case 'w':
                gotoXY(x, y--);
                break;
            case 's':
                gotoXY(x, y++);
                break;
            case '\b':  //Exit Condition
                system("CLS");
                puts(title);
                PrintColoredString(line, 0xB);
                StartAnimation("\t\t\t      See you Next Time!\n", 10); //Welcome to osu!
                PrintColoredString(line, 0xB);
                Beep(470, 100);
                Beep(360, 100);
                Beep(250, 100);
                return 0;
            case '\r':  //Main(z) menu Conditions
                switch (y){
                    case 16:
                        PrintPokedex(pokedex, pokeWeak);
                        system("CLS");
                        break;
                    case 17:
                        SeekPokemon(pokedex, pokeWeak);
                        system("CLS");
                        break;
                    case 18:
                        InsertCard(&pokemon, PokedexFile);
                        LoadPokedex(pokedex, PokedexFile);
                        system("CLS");
                        break;
                    case 19:
                        RemoveCard(pokedex, PokedexFile);
                        LoadPokedex(pokedex, PokedexFile);
                        system("CLS");
                        break;
                    case 20:
                        SubtitlePreset("\t\t\t      SORTING POKEDEX\n\n", "\t       - Selezionare in che ordine si vuole il Pokedex -\n\t\t- INVIO per Selezionare, BACKSPACE per Uscire -\n\n");
                        printf("\t\t\t  NUMERO\n");
                        printf("\t\t\t  NOME\n");
                        printf("\t\t\t  HP\n");
                        printf("\t\t\t  ATTACCO (Totale)\n\n");
                        PrintColoredString(line, 0xB);
                            
                        y = 16;

                        while(1){

                            gotoXY(x, y);
                            in2 = getch();
                            switch(in2){
                                case 'w':
                                    gotoXY(x, y--);
                                    break;
                                case 's':
                                    gotoXY(x, y++);
                                    break;
                                case '\b':  //Exit Condition
                                    break;
                                case '\r':
                                    PokedexFile = fopen("PokedexFile.txt", "w");
                                    fclose(PokedexFile);
                                    switch (y){
                                        case 16:
                                            for (i = 0; i != PokedexLenght; i++) {
                                                if (pokedex[i].PkNumber != 0){
                                                    qsort(pokedex, PokedexLenght, sizeof(Pokemon), IDSort);
                                                    savePokemon(&pokedex[i], PokedexFile);
                                                }
                                            }
                                            break;
                                        case 17:
                                            for (i = 0; i != PokedexLenght; i++) {
                                                if (pokedex[i].PkNumber != 0){
                                                    qsort(pokedex, PokedexLenght, sizeof(Pokemon), NAMESort);
                                                    savePokemon(&pokedex[i], PokedexFile);
                                                }
                                            }
                                            break;
                                        case 18:
                                            for (i = 0; i != PokedexLenght; i++) {
                                                if (pokedex[i].PkNumber != 0){
                                                    qsort(pokedex, PokedexLenght, sizeof(Pokemon), HPSort);
                                                    savePokemon(&pokedex[i], PokedexFile);
                                                }
                                            }
                                            break;
                                        case 19:
                                            for (i = 0; i != PokedexLenght; i++) {
                                                if (pokedex[i].PkNumber != 0){
                                                    qsort(pokedex, PokedexLenght, sizeof(Pokemon), ATKSort);
                                                    savePokemon(&pokedex[i], PokedexFile);
                                                }
                                            }
                                            break;
                                    } break;
                            } 

                            if (y > 19) y = 16;
                            if (y < 16) y = 19;
                        }
                        system("CLS");
                        break;
                    case 21: //Seventh: Reload Pokedex
                        LoadPokedex(pokedex, PokedexFile);
                        system("CLS");
                        break;
                }
        }

        if (y > 21) y = 16;     //Avoiding exiting the menu layer
        if (y < 16) y = 21;

    }
}
