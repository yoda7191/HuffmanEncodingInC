#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "huffmanencode.h"

char *help = "'tis will be a help line";

int main(int argc, char **argv)
{
    int opt;
    char *inputFileName = NULL;
    char *treeFileName = NULL;
    char *outputFileName = NULL;
    char *progType = NULL;
    char *progName = argv[0];

    while ((opt = getopt(argc, argv, "c:d:r:s:t:h")) != -1)
    {
        switch (opt)
        {
        case 'c':
            progType = "Compress";
            break;
        case 'd':
            progType = "Decompress";
            break;
        case 'r':
            inputFileName = optarg;
            break;
        case 's':
            outputFileName = optarg;
            break;
        case 't':
            treeFileName = optarg;
            break;
        default:
            fprintf(stderr, help, progName);
            exit(EXIT_FAILURE);
        }
    }

    if (optind < argc)
    {
        fprintf(stderr, "\n Bad parameters!\n");
        for (; optind < argc; optind++)
            fprintf(stderr, "\t\"%s\"\n", argv[optind]);
        fprintf(stderr, "\n");
        fprintf(stderr, help, progName);
        exit(EXIT_FAILURE);
    }

    if (inputFileName == NULL)
    {
        fprintf(stderr, "\n No input file given!\n");
        exit(EXIT_FAILURE);
    }

    if (progType == "Decompress" && treeFileName == NULL)
    {
        fprintf(stderr, "\n No tree file given!\n");
        exit(EXIT_FAILURE);
    }

    if (treeFileName == NULL)
    {
        treeFileName == "tree";
    }

    if (outputFileName == NULL)
    {
        outputFileName = "output.huffman";
    }

    if (inputFileName != NULL)
    {
        FILE *outputFilePtr = fopen(outputFileName, "w");
        FILE *inputFilePtr = fopen(inputFileName, "r");
        FILE *treeFilePtr = fopen(treeFileName, "rw");

        if(inputFilePtr == NULL)
        {
            fprintf(stderr, "\n Problem reading input file\n");
            exit(EXIT_FAILURE);
        }
        if(outputFilePtr == NULL)
        {
            fprintf(stderr, "\n Problem opening output file\n");
            exit(EXIT_FAILURE);
        }
        if(treeFilePtr == NULL)
        {
            fprintf(stderr, "\n Problem opening tree file\n");
            exit(EXIT_FAILURE);
        }

        if(progType == "Compress")
        {
            if(huffmanEncode(inputFilePtr, outputFilePtr, treeFilePtr))
            {
                fprintf(stderr, "\n Problem encoding file \n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return 0;
}