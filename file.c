#include "btcc.h"

FILE* fp;

// thank you to https://www.programiz.com/c-programming/c-file-input-output 
// for the write/read code

// reads files
void inpOpen (char *filename)
{
    fp = fopen(filename, "r"); // read mode

    if (fp == NULL)
    {
        btccErr("Read error while opening the file %s", filename);
        btccExit(1, __LINE__);
    }

    inp();
    inpPos.h = -1;
    inpPos.line = 0;

}
void inpClose ()
{
    fclose(fp);
}

char inp ()
{
    inpT = inpN; 
    inpPos.h++;
    if ((inpN = fgetc(fp)) == EOF)
        inpN = '\0';
    if (inpT == '\n')
        inpPos.line++;
    return inpT;
}

bool inpCT (char expect)
{
    if (inpT == expect)
        return true;
    return false;
}

bool inpCN (char expect)
{
    if (inpN == expect)
        return true;
    return false;
}

// write files
void inpOutput (char *toFilename)
{
    fp = fopen(toFilename, "w"); // write mode

    if(fp == NULL)
    {
        btccErr("Write error while opening the file %s", toFilename);
        btccExit(1, __LINE__);
    }

    fclose(fp);
}
