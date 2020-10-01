# Pokedex
A simple Project about an interactive Pokedex. Done this for a School Project and developed in about 2 weeks of time. Works with a simple .TXT file formatted in a specific way.

# Disclamer
This isn't finished, it can be optimized in many ways and all the text is in *ITALIAN*.

# Installation

You need:
* **gcc/gnu C compiler**

To compile the project, you have two ways:
* **Code::Blocks Project**
* **Via Command Line** (CMD is Fine)

## Code::Blocks
The first one is the simplest. Open the project in a new Instance of Code::Blocks and compile it with the in-built Option.

## Command Line
For the second one, you need to move in the root of the downloaded directory and write the following command:

```
gcc -g main.c PokeUtils.c WinUtils.c -o Pokedex
```

And you've done. **MAKE A BACKUP OF THE "PokedexFile.TXT"! OR YOU CAN LOSE IT!**

# Formatting

Like i said before, the .TXT have a specific format to follow for the correct working of the program. Is the following:

```
[ID][NAME][HP][DESCRIPTION][TYPE1][TYPE2][MOVE1][ATKMOVE1][MOVE2][ATKMOVE2][MOVE3][ATKMOVE3]
```

If you use the in-built function to add a pokemon, the program will format it in this way.

If, however, want to format manually, follow the above, but without the **[]**, separated with **SPACE** and the [DESCRIPTION] elements **MUST** be joined with the **_**
