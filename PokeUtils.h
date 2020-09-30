#define PokedexLenght 151
#define PkMoveLenght 50
#define PkTypeLenght 50
#define PkNameLenght 50
#define PkDescLenght 1000

#define line "--------------------------------------------------------------------------------\n\n"
#define title "\t\t _____   ____  _  ________ _____  ________   __\n\t\t|  __ \\ / __ \\| |/ /  ____|  __ \\|  ____\\ \\ / /\n\t\t| |__) | |  | | ' /| |__  | |  | | |__   \\ V / \n\t\t|  ___/| |  | |  < |  __| | |  | |  __|   > <  \n\t\t| |    | |__| | . \\| |____| |__| | |____ / . \\ \n\t\t|_|     \\____/|_|\\_\\______|_____/|______/_/ \\_\\\n\0"

typedef struct moves {
    char Move[3][PkMoveLenght];
    int ATK[3];
} PkMoves;

typedef struct types {
    char Type[2][PkTypeLenght];
} PkType;

typedef struct data{
    int PkNumber;
    char PkName[PkNameLenght];
    int PkHP;
    char PkDesc[PkDescLenght];
    PkType pkType;
    PkMoves pkMoves;
} Pokemon;

typedef struct weakness{
    char Weak[5][PkTypeLenght];
} PokeWeak;

void SubtitlePreset(char* MainString, char* SubString);
int IDSort(const void* pokemon1, const void* pokemon2);
int NAMESort(const void *pokemon1, const void* pokemon2);
int HPSort(const void *pokemon1, const void *pokemon2);
int ATKSort(const void *pokemon1, const void *pokemon2);
void PokedexInitialization(Pokemon pokedex[], FILE * PokedexFile);
void WeaknessFinder(char* String, PokeWeak *pokeWeak);
void PokemonInitialization(Pokemon *pokemon);
void PrintPokedex(Pokemon pokedex[], PokeWeak pokeWeak[]);
void LoadPokedex(Pokemon pokedex[], FILE * PokedexFile);
void SeekPokemon(Pokemon pokedex[], PokeWeak pokeWeak[]);
void RemoveCard(Pokemon pokedex[], FILE * PokedexFile);
void savePokemon(Pokemon *pokemon, FILE * PokedexFile);
void InsertCard(Pokemon *pokemon, FILE * PokedexFile);
void PokemonInfoTable(Pokemon pokemon, PokeWeak pokeWeak[]);
