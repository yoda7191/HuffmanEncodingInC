#ifndef _IMPORTFILE_H
#define _IMPORTFILE_H

#include "stdio.h"

typedef struct treeNode_t
{
    struct treeNode_t *left, *right;
    int freq;
    char c;
} *node;

void calculateFrequencies(FILE *readFile, int *freqArrayPointer[128]);

#endif  