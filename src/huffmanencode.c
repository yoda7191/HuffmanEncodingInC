#include <stdlib.h>
#include <stdio.h>

struct huffmanTree 
{
    char character;
    int frequency;

    huffmanTree *left; 
    huffmanTree *right;

    huffmanTree(char data, int frequency)
    {
        left=NULL;
        right=NULL;
        
        this->data = data;
        this->frequency = frequency;
    }
};

int calculateFrequencyOfLetters(FILE* inputFile);

int huffmanEncode(FILE* inputFile, FILE* outputFile, FILE* treeFile)
{
    if(calculateFrequencyOfLetters(inputFile))
    {
        fprintf(stderr, "\n Error calculating freuqncies\n");
        return 1;
    }
    return 0;
}

int calculateFrequencyOfLetters(FILE* inputFile)
{   
    int tempFrequencyArray[128] = {0}, i;
    while(fgetc(inputFile) != EOF)
    {
            
    }
}