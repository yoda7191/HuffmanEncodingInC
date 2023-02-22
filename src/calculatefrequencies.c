#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffmantree.h"

typedef struct treeNode_t
{
    struct treeNode_t *left, *right;
    int freq;
    char c;
};

void calculateFrequencies(FILE *readFile, int *freqArray[128])
{
    char c;

    while((c=fgetc(readFile)) != EOF)
        freqArray[(int)c]++;

    for(int i = 0; i < 128; i++)
    {
        if(freqArray[i])
        {
            //create nodes
        }
    }
}

struct node* createNewNode(int freq, char c, node a, node b)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    
    node->freq = freq;
    node->c = c;

    node->left = NULL;
    node->right = NULL;

    return node;
}

node removeNode()
{

}

void insertNode()
{

}

void insertNodeIntoTree ()