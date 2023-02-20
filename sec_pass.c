//
// Created by user on 13/02/2023.
//
#include "data.h"
#include "globals.h"
void get_line_info(char file_name);
void encodeLabel(FILE* source, char* codeLine, Label* labels);
int numFromChar(char* num);

void sec_encoder(FILE* source, int **code, Label* labels){
    int i=0;
    int codeLines = 50; //נניח שיש 50 שורות בטבלה
    while(i < codeLines){
        if(code[i][0] == NULL)
            encodeLabel(source, code[i], labels); //להוסיף בדיקת שגיאה
        else
            i++;
    }
}
void encodeLabel(FILE* source, char* codeLine, Label* labels){
    int fromIndex = numFromChar(codeLine+1);
    char* label;
    stringOfIndex(source, fromIndex, label);
    addressOfLabel(labels, label);
    /*
     * איך שומרים את הקוד מכונה? בטבלה שבה בכל שורה יש 16 סיביות? בטבלה רגילה של תווים? של אינטים?
     * */

}
//מקבל מחרוזת שמאותחלת במספרים כערך מספרי ולא כתו למשל:
//s[i] = 3
//ולא s[i] = '3'
int numFromChar(char* num){
    int result=0, i=0, length = strlen(num);
    char c[length];
    strcpy(c, num);
    for(; i<length; i++)
        c[i] += 48;
    result = atoi(c);
    return result;
}

int addressOfLabel(Label* labels, Label label){ //להוסיף טיפול בשגיאה
    return  0;
}