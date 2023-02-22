#ifndef _HUFFMANENCODE_H
#define _HUFFMANENCODE_H

#include "stdio.h";

typedef struct treeNode_t
{
    struct treeNode_t *left, *right;
    int freq;
    char c;
};

void encode(FILE* readFile, FILE* wrtieFile);

#endif