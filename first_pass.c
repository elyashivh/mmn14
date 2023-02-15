#include "globals.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*שגיאות אפשריות:
 * פעולה שאינה קיימת
 * מס' אופרנים שגוי
 * סוג אופרנד שאינו מתאים לפעולה
 * שם אוגר לא קיים
 * כל סמל מוגדר רק פעם אחת*/

#include "firs_pass.h"

void get_line_info(char *file_name)
{
    FILE *file;
    int ic = IC_ADDRESS;   /**/
    int dc = 0;
    int l = 0;
    int line_counter = 0;
    int label_counter = 0;
    int line_type;
    boolean correct = TRUE;
    char curr_line[MAX_LINE_LEN];

    table *label_table = malloc(1 * sizeof (table));
    if(!label_table)
    {
        /*להעלות שגיאה*/
    }

     /*open file after pre-assmembler process*/
    if ((file = fopen(file_name, "r") == NULL))
    {
        /*להעלות שגיאה*/
    }
    
    /*read the first line from the file and start the first pass*/
    do
    {
        fgets(curr_line, MAX_LINE_LEN, file);
        curr_line[strlen(curr_line)-2]= '\0';
        line_counter++;
        
        line_type = check_line_type(curr_line, temp_word);
        if (line_type == 0 || line_type == 1)
            continue;
        else if (line_type == 2)
        {
            decod_directive(curr_line, dc);
        }
        else
        {
            decod_command(curr_line, ic, l);
        }


    } while (fgets(curr_line, MAX_LINE_LEN, file) != NULL);
    
}/*end of get_file_info*/


int check_line_type(char *curr_line, char *temp_word, table *label_table, int *lable_counter)
{
    int result;
    /*check the line type -  if empty or comment continue to the next line*/
    if (comment_or_empty(curr_line))
    {
        result = 0;
    }
    /*check if the new line contain a label, and if it is new one*/
    else if(is_label(temp_word))
    {
        result = 1;
        if (new_label(temp_word, label_table->label, /*מס שיצייין את המיקום בטבלת התוויות*/))
        {
            lable_counter++;
            enter_new_lable(temp_word, ic+dc, label_table, /*מס שיצייין את המיקום בטבלת התוויות*/)
        }
        else
        {
            /*להעלות שגיאה על תווית כפולה*/
        }
    }
    return result;
}

void errors_list(int error_num)
{
    switch (error_num)
    {
    case 0/* constant-expression */:
        printf("Error: problem with oppening file\n");  /*open file is failed*/
        break;
    
    default:
        break;
    }
}


boolean comment_or_empty(char* line)
{
    if (line[0] == ';' || strcmp(line, "  \n") == 0)
        return TRUE;
    return FALSE;
}

boolean is_label(char* word)
{
    int len = strlen(word);
    if(word[len-1] == ':')
        return TRUE;
    return FALSE;
}

boolean new_label(char* label, table *lable_table, int *label_num)
{
    int i;
    boolean result = TRUE;
    for (i = 0; i <= label_num; i++)
    {
        if (lable_table[i].label != label)
            i++;
        else
        {
            result = FALSE;
            break;
        }
    }
    return result;

}

void enter_new_lable(char* lable_name, int adress, table *lable_table, int label_num)
{
    table *new_table = realloc(lable_table, label_num * sizeof(table));
    if (!new_table)
    {
        /*להעלות שגיאה*/
    }
    lable_table = new_table;
    lable_table[label_num].name = lable_name;
    lable_table[label_num].address = adress;
}

boolean is_directive(char *word)
{
    if(word[1] == '.')
        return TRUE;
    return FALSE;
}


boolean decode_directive(char* line, int dc)
{
    boolean result;
    char directicve_type;
    char *temp_word;
    temp_word +=2;
    while (temp_word)
    {
        /*instruct type is data*/
        if (strcmp(temp_word, "d") == 0)
        {
            temp_word += 3;

        }
    }



}

boolean decode_command(char* word)
{

}

boolean decode_line(char* line)
{

}

