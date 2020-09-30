#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

#include "WinUtils.h"
#include "PokeUtils.h"

char* Types[] = {"Erba", "Buio", "Terra", "Lotta", "Acqua", "Fuoco", "Psico", "Drago", "Roccia", "Veleno", "Spettro", "Acciaio", "Elettro", "Volante", "Normale", "Follet.", "Ghiaccio", "Coleott.", "-----"};
int nTypes = 19;

void SubtitlePreset(char* MainString, char* SubString){
    system("CLS");
    puts(title);
    PrintColoredString(line, 0xB);
    PrintColoredString(MainString, 0xE);
    printf(SubString);
    PrintColoredString(line, 0xB);
}

void PokemonInitialization(Pokemon *pokemon){
    //Simple, initialize the Pokemon Struct to avoid errors
    pokemon->PkNumber = 0;
    strcpy(pokemon->PkName, "-----");
    pokemon->PkHP = 0;
    strcpy(pokemon->PkDesc, "\t----------------------------------------------------------------");
    strcpy(pokemon->pkType.Type[1], "-----");
    strcpy(pokemon->pkType.Type[2], "-----");
    strcpy(pokemon->pkMoves.Move[1], "-----");
    pokemon->pkMoves.ATK[1] = 0;
    strcpy(pokemon->pkMoves.Move[2], "-----");
    pokemon->pkMoves.ATK[2] = 0;
    strcpy(pokemon->pkMoves.Move[3], "-----");
    pokemon->pkMoves.ATK[3] = 0;
}

void LoadPokedex(Pokemon pokedex[], FILE * PokedexFile){
    int i = 0;

    PokedexFile = fopen("PokedexFile.txt","r"); //Opening the file in "read-mode" only

    rewind(PokedexFile);    //Small precaution, restart the search from the start

    while(!feof(PokedexFile)){
        fscanf(PokedexFile, "%d", &pokedex[i].PkNumber);
        fscanf(PokedexFile, "%s", pokedex[i].PkName);
        fscanf(PokedexFile, "%d", &pokedex[i].PkHP);
        fscanf(PokedexFile, "%s", pokedex[i].PkDesc);
        fscanf(PokedexFile, "%s", pokedex[i].pkType.Type[0]);
        fscanf(PokedexFile, "%s", pokedex[i].pkType.Type[1]);
        fscanf(PokedexFile, "%s", pokedex[i].pkMoves.Move[0]);
        fscanf(PokedexFile, "%d", &pokedex[i].pkMoves.ATK[0]);
        fscanf(PokedexFile, "%s", pokedex[i].pkMoves.Move[1]);
        fscanf(PokedexFile, "%d", &pokedex[i].pkMoves.ATK[1]);
        fscanf(PokedexFile, "%s", pokedex[i].pkMoves.Move[2]);
        fscanf(PokedexFile, "%d", &pokedex[i].pkMoves.ATK[2]);
        i++;
    }

    fclose(PokedexFile);
}

void PokedexInitialization(Pokemon pokedex[], FILE * PokedexFile){

    int i;
    char input;

    SubtitlePreset("\t\t\t  POKEDEX INITIALIZATION\n\n", "\t\t - Vuoi Creare un Nuovo file? N/S per Scegliere -\n\n");

    printf("\t\t\t\tCHOOSE > ");
    scanf("%c", &input);

    for (i = 0; i != PokedexLenght; i++){
        PokemonInitialization(&pokedex[i]); //Using a for cycle to fill the empty Pokedex Slots
    }

    if (input == 'S'){

        PokedexFile = fopen("PokedexFile.txt","w"); //Create a new file, even if there's already in the main directory
        if (PokedexFile != NULL) fclose(PokedexFile);

    } else if (input == 'N'){

        PokedexFile = fopen("PokedexFile.txt", "r");
        if (PokedexFile == NULL){

            fclose(PokedexFile);

            while(1){   //Avoiding to enter in the Main Menu without the file, Avoiding the Basics Error Handlers

                SubtitlePreset("\t\t\t     NO FILE IS FOUND\n\n", "\t- Provare a controllare se il file e' presente nella Directory -\n\n");
                printf("\t\t Chudere il Programma con l'apposita 'X'\n\t\t    ");
                system("PAUSE");
            }
        }
    }
}

void WeaknessFinder(char* String, PokeWeak *pokeWeak){

    char* type = String;

    if (!strcmp(type, "Lotta")){
        strcpy(pokeWeak->Weak[0], "Volante");
        strcpy(pokeWeak->Weak[1], "Psico");
        strcpy(pokeWeak->Weak[2], "Follet.");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Volante")){
        strcpy(pokeWeak->Weak[0], "Rocccia");
        strcpy(pokeWeak->Weak[1], "Elettro");
        strcpy(pokeWeak->Weak[2], "Ghiaccio");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Veleno")){
        strcpy(pokeWeak->Weak[0], "Roccia");
        strcpy(pokeWeak->Weak[1], "Psico");
        strcpy(pokeWeak->Weak[2], "-----");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Terra")){
        strcpy(pokeWeak->Weak[0], "Acqua");
        strcpy(pokeWeak->Weak[1], "Erba");
        strcpy(pokeWeak->Weak[2], "Ghiaccio");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Roccia")){
        strcpy(pokeWeak->Weak[0], "Lotta");
        strcpy(pokeWeak->Weak[1], "Terra");
        strcpy(pokeWeak->Weak[2], "Acciaio");
        strcpy(pokeWeak->Weak[3], "Acqua");
        strcpy(pokeWeak->Weak[4], "Erba");
    } else if (!strcmp(type, "Coleot.")){
        strcpy(pokeWeak->Weak[0], "Acqua");
        strcpy(pokeWeak->Weak[1], "Erba");
        strcpy(pokeWeak->Weak[2], "Ghiaccio");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Spettro")){
        strcpy(pokeWeak->Weak[0], "Spettro");
        strcpy(pokeWeak->Weak[1], "Buio");
        strcpy(pokeWeak->Weak[2], "-----");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Acciaio")){
        strcpy(pokeWeak->Weak[0], "Lotta");
        strcpy(pokeWeak->Weak[1], "Terra");
        strcpy(pokeWeak->Weak[2], "Fuoco");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Fuoco")){
        strcpy(pokeWeak->Weak[0], "Terra");
        strcpy(pokeWeak->Weak[1], "Roccia");
        strcpy(pokeWeak->Weak[2], "Acqua");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Acqua")){
        strcpy(pokeWeak->Weak[0], "Erba");
        strcpy(pokeWeak->Weak[1], "Elettro");
        strcpy(pokeWeak->Weak[2], "-----");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Erba")){
        strcpy(pokeWeak->Weak[0], "Volante");
        strcpy(pokeWeak->Weak[1], "Veleno");
        strcpy(pokeWeak->Weak[2], "Coleot.");
        strcpy(pokeWeak->Weak[3], "Fuoco");
        strcpy(pokeWeak->Weak[4], "Ghiaccio");
    } else if (!strcmp(type, "Elettro")){
        strcpy(pokeWeak->Weak[0], "Terra");
        strcpy(pokeWeak->Weak[1], "-----");
        strcpy(pokeWeak->Weak[2], "-----");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Psico")){
        strcpy(pokeWeak->Weak[0], "Coleot.");
        strcpy(pokeWeak->Weak[1], "Spettro");
        strcpy(pokeWeak->Weak[2], "Buio");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Ghiaccio")){
        strcpy(pokeWeak->Weak[0], "Lotta");
        strcpy(pokeWeak->Weak[1], "Roccia");
        strcpy(pokeWeak->Weak[2], "Acciaio");
        strcpy(pokeWeak->Weak[3], "Fuoco");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Drago")){
        strcpy(pokeWeak->Weak[0], "Ghiaccio");
        strcpy(pokeWeak->Weak[1], "Drago");
        strcpy(pokeWeak->Weak[2], "Follet.");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Buio")){
        strcpy(pokeWeak->Weak[0], "Lotta");
        strcpy(pokeWeak->Weak[1], "Follet.");
        strcpy(pokeWeak->Weak[2], "Coleot.");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Follet.")){
        strcpy(pokeWeak->Weak[0], "Acciaio");
        strcpy(pokeWeak->Weak[1], "Veleno");
        strcpy(pokeWeak->Weak[2], "-----");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "Normale")){
        strcpy(pokeWeak->Weak[0], "Lotta");
        strcpy(pokeWeak->Weak[1], "-----");
        strcpy(pokeWeak->Weak[2], "-----");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    } else if (!strcmp(type, "-----")){
        strcpy(pokeWeak->Weak[0], "-----");
        strcpy(pokeWeak->Weak[1], "-----");
        strcpy(pokeWeak->Weak[2], "-----");
        strcpy(pokeWeak->Weak[3], "-----");
        strcpy(pokeWeak->Weak[4], "-----");
    }
}

void PokemonInfoTable(Pokemon pokemon, PokeWeak pokeWeak[]){

    WeaknessFinder(pokemon.pkType.Type[0], &pokeWeak[0]);
    WeaknessFinder(pokemon.pkType.Type[1], &pokeWeak[1]);
    printf(" [-]---------------[-]\t#%d | %s \n", pokemon.PkNumber, pokemon.PkName);
    printf("  |                 |\n");
    printf("  |                 |\tHP: %d | TOT. ATK %d \n", pokemon.PkHP, pokemon.pkMoves.ATK[0]+pokemon.pkMoves.ATK[1]+pokemon.pkMoves.ATK[2]);
    printf("  |                 |\n");
    printf("  |                 |\tTIPO 1: %s\t\t\tTIPO 2: %s\n", pokemon.pkType.Type[0], pokemon.pkType.Type[1]);
    printf("  |                 |\t DEBOLE A:\t\t\t DEBOLE A:\n");
    printf("  |                 |\t  > %s\t\t\t  > %s\n", pokeWeak[0].Weak[0], pokeWeak[1].Weak[0]);
    printf("  |                 |\t  > %s\t\t\t  > %s\n", pokeWeak[0].Weak[1], pokeWeak[1].Weak[1]);
    printf("  |                 |\t  > %s\t\t\t  > %s\n", pokeWeak[0].Weak[2], pokeWeak[1].Weak[2]);
    printf("  |                 |\t  > %s\t\t\t  > %s\n", pokeWeak[0].Weak[3], pokeWeak[1].Weak[3]);
    printf(" [-]---------------[-]\t  > %s\t\t\t  > %s\n\n", pokeWeak[0].Weak[4], pokeWeak[1].Weak[4]);
    printf("\t\t\t       | DESCRIZIONE |\n\n"); PrintRemoveChar(pokemon.PkDesc, '_'); printf("\n\n");
    printf("\t\t\t\t| ATTACCHI: |\n\n");
    printf("\t\t\t > ATK. 1: "); PrintRemoveChar(pokemon.pkMoves.Move[0], '_'); printf(" - %d \n", pokemon.pkMoves.ATK[0]);
    printf("\t\t\t > ATK. 2: "); PrintRemoveChar(pokemon.pkMoves.Move[1], '_'); printf(" - %d \n", pokemon.pkMoves.ATK[1]);
    printf("\t\t\t > ATK. 3: "); PrintRemoveChar(pokemon.pkMoves.Move[2], '_'); printf(" - %d \n\n", pokemon.pkMoves.ATK[2]);
    PrintColoredString(line, 0xB);
}

void PrintPokedex(Pokemon pokedex[], PokeWeak pokeWeak[]){
    int i = 0;
    char input;

    while(1){

        SubtitlePreset("\t\t\t    POKEDEX INFORMATION\n\n", "\t- Premere W/A/S/D per Navigare nel Menu, BACKSPACE per Uscire -\n\n");
        PokemonInfoTable(pokedex[i], pokeWeak);

        input = getch();    //Same concept of the Menu
        switch(input){
            case 'a':
                i--;
                break;
            case 'd':
                i++;
                break;
            case 'w':
                i+=10;
                break;
            case 's':
                i-=10;
                break;
            case '\b':
                break;
        } if (i > PokedexLenght) i = 0;
          if (i < 0) i = PokedexLenght;
          if (input == '\b') break;
    }
}

void SeekPokemon(Pokemon pokedex[], PokeWeak pokeWeak[]){

    char name[PkNameLenght];
    int i;

    SubtitlePreset("\t\t\t      POKEMON INFORMATION\n\n", "\t\t  - Inserire il NOME del Pokemon da cercare -\n\n");

    printf("NOME > ");   //Taking the Pokemon name
    gets(name);

    system("CLS");

    for (i = 0; i != PokedexLenght; i++){
        if (!strcmp(pokedex[i].PkName, name)) { //Comparing the two strings
            SubtitlePreset("\t\t\t      POKEMON INFORMATION\n\n", "\t\t  - Inserire il NOME del Pokemon da cercare -\n\n");
            PokemonInfoTable(pokedex[i], pokeWeak);
        }
    }

    system("PAUSE");
}

void savePokemon(Pokemon *pokemon, FILE * PokedexFile){

    PokedexFile = fopen("PokedexFile.txt","a"); //Opening the file in "Append-mode", and save the pokemon in a new line

    fprintf(PokedexFile, "%d %s %d %s %s %s %s %d %s %d %s %d \n", pokemon->PkNumber, pokemon->PkName, pokemon->PkHP, pokemon->PkDesc, pokemon->pkType.Type[0], pokemon->pkType.Type[1], pokemon->pkMoves.Move[0], pokemon->pkMoves.ATK[0], pokemon->pkMoves.Move[1], pokemon->pkMoves.ATK[1], pokemon->pkMoves.Move[2], pokemon->pkMoves.ATK[2]);

    fclose(PokedexFile);
}

void RemoveCard(Pokemon pokedex[], FILE * PokedexFile){
    char name[PkNameLenght];
    int i;

    SubtitlePreset("\t\t\t\tREMOVE POKEMON\n\n", "\t\t - Inserire il NOME del Pokemon da rimuovere -\n\n");

    fflush(stdin);
    printf("NOME > ");   //Taking the Pokemon name
    gets(name);

    PokedexFile = fopen("PokedexFile.txt", "w");
    fclose(PokedexFile);

    for (i = 0; i != PokedexLenght; i++){
        if (strcmp(pokedex[i].PkName, name) && pokedex[i].PkNumber != 0) { //Objective: Print only the NON SELECTED Pokemon
            savePokemon(&pokedex[i], PokedexFile);
        }

        PokemonInitialization(&pokedex[i]); //Clean the array from the already printed pokemon
    }
}

void InsertCard(Pokemon *pokemon, FILE * PokedexFile){
    //Easy peasy, enter the required pokemon info

    SubtitlePreset("\t\t\t\tINSERT POKEMON\n\n", "\t\t     - Inserire le informazioni richeste. -\n\n");

    char DescCache[PkDescLenght];
    char Move1Cache[PkMoveLenght];
    char Move2Cache[PkMoveLenght];
    char Move3Cache[PkMoveLenght];

    fflush(stdin);
    printf("ID > ");
    scanf("%d", &pokemon->PkNumber);

    fflush(stdin);
    printf("NOME > ");
    gets(pokemon->PkName);

    fflush(stdin);
    printf("HP > ");
    scanf("%d", &pokemon->PkHP);

    fflush(stdin);
    printf("DESCRIZIONE > ");

    strcpy(pokemon->PkDesc, SaveWithChar(gets(DescCache), '_'));

    strcpy(pokemon->pkType.Type[0], TabScroller(Types, nTypes, "TIPO1"));

    strcpy(pokemon->pkType.Type[1], TabScroller(Types, nTypes, "TIPO2"));

    fflush(stdin);
    printf("MOSSA #1 > ");

    strcpy(pokemon->pkMoves.Move[0], SaveWithChar(gets(Move1Cache), '_'));

    fflush(stdin);
    printf("ATK MOSSA #1 > ");
    scanf("%d", &pokemon->pkMoves.ATK[0]);

    fflush(stdin);
    printf("MOSSA #2 > ");

    strcpy(pokemon->pkMoves.Move[1], SaveWithChar(gets(Move2Cache), '_'));

    fflush(stdin);
    printf("ATK MOSSA #2 > ");
    scanf("%d", &pokemon->pkMoves.ATK[1]);

    fflush(stdin);
    printf("MOSSA #3 > ");

    strcpy(pokemon->pkMoves.Move[2], SaveWithChar(gets(Move3Cache), '_'));

    fflush(stdin);
    printf("ATK MOSSA #3 > ");
    scanf("%d", &pokemon->pkMoves.ATK[2]);

    savePokemon(pokemon, PokedexFile);   //Save the pokemon, go to reference

    PrintColoredString(line, 0xB);
    PrintColoredString("\t\t\t\tINSERIMENTO COMPLETATO\n\n", 0xE);
    PrintColoredString(line, 0xB);

    printf("\n\t\t");
    system("PAUSE");
}

int IDSort(const void* pokemon1, const void* pokemon2){

    if (((Pokemon*)pokemon1)->PkNumber > ((Pokemon*)pokemon2)->PkNumber){
        return 1;
    }

    if (((Pokemon*)pokemon1)->PkNumber < ((Pokemon*)pokemon2)->PkNumber){
        return -1;
    }

    return 0;
}

int NAMESort(const void *pokemon1, const void* pokemon2){
    return strcmp(((Pokemon*)pokemon1)->PkName, ((Pokemon*)pokemon2)->PkName);
}

int HPSort(const void *pokemon1, const void *pokemon2){

    if (((Pokemon*)pokemon1)->PkHP > ((Pokemon*)pokemon2)->PkHP){
        return 1;
    }

    if (((Pokemon*)pokemon1)->PkHP < ((Pokemon*)pokemon2)->PkHP){
        return -1;
    }

    return 0;
}

int ATKSort(const void *pokemon1, const void *pokemon2){
    int ATKPokemon1 = ((Pokemon*)pokemon1)->pkMoves.ATK[0] + ((Pokemon*)pokemon1)->pkMoves.ATK[1] + ((Pokemon*)pokemon1)->pkMoves.ATK[2];
    int ATKPokemon2 = ((Pokemon*)pokemon2)->pkMoves.ATK[0] + ((Pokemon*)pokemon2)->pkMoves.ATK[1] + ((Pokemon*)pokemon2)->pkMoves.ATK[2];

    if (ATKPokemon1 > ATKPokemon2){
        return 1;
    }

    if (ATKPokemon1 < ATKPokemon2){
        return -1;
    }

    return 0;
}
