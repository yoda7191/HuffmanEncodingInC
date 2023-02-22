#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffmanencode.h"

int main(int argc, char ** argv)
{
    FILE *readFilePtr;
    FILE *writeFilePtr;

    if(argc < 1)
    {
        printf("Nie podano nazw pliku wejściowego\n");
        return -1;
    } 

    readFilePtr = fopen(argv[0], "r");

    if(readFilePtr == NULL)
        printf("Błąd otwierania pliku wejściowego\n");

    if(argc > 1)
    {
        strcat(argv[1], ".huffman");
        writeFilePtr = fopen(argv[1], "w");
    }

    if(writeFilePtr == NULL)
        writeFilePtr = fopen("../output.huffman", "w");

    encode(readFilePtr, writeFilePtr);

    return 0;
}