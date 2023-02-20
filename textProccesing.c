/*
 * זיהוי שורה
 * טיפול בפסיקים בין מילים
 *
 *
 * */
#include "data.h"

void scanLine(FILE* source, char* destination){
    char delim[6] = " \n\t";
    char st[81];
    char* p;
    char ch;
    int i=0;
    resetStr(st);
    ch = fgetc(source);
    while(ch!=10 && ch!=0 && ch!=-1){
        st[i]=ch;
        ch = fgetc(source);
        i++;
    }
    st[i]=10;
    strcpy(destination, st);
}
void printMcr(Mcr* mcr, Vars* vars){
    fprintRange(vars->file2, vars->file1, mcr->start, mcr->end);
}
void fprintRange(FILE* destination, FILE* source, int from, int until){
    int currentPointer = ftell(source);
    int i=from;
    fseek(source, from, 0);
    while(i<until-2){
        fputc(fgetc(source), destination);
        i++;
    }
    fseek(source, currentPointer, 0);

}
void stringOfIndex(FILE* source, int index, char* destination){
    int currInd = ftell(source);
    fseek(source, index, 0);
    fgets(destination, MAX_LABEL_SIZE, source);
    fseek(source, currInd, 0);
}