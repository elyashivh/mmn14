#include "globals.h"
#include "firs_pass.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/*שגיאות אפשריות:
 * פעולה שאינה קיימת
 * מס' אופרנים שגוי
 * סוג אופרנד שאינו מתאים לפעולה
 * שם אוגר לא קיים
 * כל סמל מוגדר רק פעם אחת*/



void get_line_info(char *file_name)
{
    FILE *file;
    int ic = IC_ADDRESS;                            /*instruction counter*/
    int dc = 0;                                     /*data counter*/
    int l = 0;                                      /*word length*/
    int line_counter = 0;
    int label_counter = 0;
    int line_type;
    boolean correct = TRUE;                         /*false while problem pounded, go head the next line*/
    char curr_line[MAX_LINE_LEN];
    Label *label_tabel;
    /*pointer fot the first char in the line*/

    label_tabel = (Label*)malloc(1 * sizeof (Label));        /*initialize the Label table*/
    if(!label_tabel)
    {
        /*להעלות שגיאה*/
    }

     /*open file after pre-assmembler process*/
    if (!(file = fopen(file_name, "r")))
    {
        /*להעלות שגיאה*/
    }
    printf("file is opened\n");
    /*read the first line from the file and start the first pass*/
    do
    {
        fgets(curr_line, MAX_LINE_LEN, file);
        curr_line[strlen(curr_line)-2]= '\0';
        line_counter++;
        
        line_type = check_line_type(curr_line, curr_line, label_tabel, &label_counter, ic, dc);
        if (line_type == 0 || line_type == 1)
            continue;
        else if (line_type == 2)
        {
            /*decod_directive(curr_line, dc);*/
        }
        else
        {
            /*decod_command(curr_line, ic, l);*/
        }


    } while (fgets(curr_line, MAX_LINE_LEN, file) != NULL);
    
}/*end of get_file_info*/


int check_line_type(char *curr_line, char *temp_word, Label *label_table, int *lable_counter, int ic, int dc)
{
    int result = 0;
    /*check the line type -  if empty or comment continue to the next line*/
    if (comment_or_empty(curr_line))
    {
        result = 0;
    }
    /*check if the new line contain a Label, and if it is new one*/
    else if(is_label(temp_word))
    {
        result = 1;
        if (new_label(temp_word, label_table, lable_counter))
        {
            lable_counter++;
            //enter_new_label(temp_word, ic+dc, label_table, lable_counter);
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

/*פונקציה תקינה*/
boolean comment_or_empty(char* line)
{
    if (line[0] == ';' || isspace(*line))
        return TRUE;
    return FALSE;
}
/*פונקציה תקינה*/
boolean is_label(char* word)
{
    int len = (int)strlen(word);
    if(word[len-1] == ':')
        return TRUE;
    return FALSE;
}

boolean new_label(char* label, Label *lable_table, int *label_num)
{
    int i;
    boolean result = TRUE;
    for (i = 0; i <= *label_num; i++)
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

void enter_new_label(char *label_name, int address, Label *label_table, int label_num)
{
    Label *new_table = realloc(label_table, label_num * sizeof(Label));
    if (!new_table)
    {
        /*להעלות שגיאה*/
    }
    label_table = new_table;
    memcpy(label_table[label_num].label, label_name, strlen(label_name)+1);
    label_table[label_num].address = address;
}

/*פונקציה תקינה*/
boolean is_directive(char *word)
{
    if(word[0] == '.')
        return TRUE;
    return FALSE;
}


boolean decode_directive(char* line, int dc, Label *lable_table, /*מצביע לטבלת קידוד*/)
{
    boolean result;
    char directicve_type;
    char *temp_word = line;
    temp_word +=2;
    /*instruct type is data*/
    if (strcmp(temp_word, "d") == 0)
    {
        char comma[1] = ",";
        boolean is_comma = TRUE;
        temp_word += 3;
        while (temp_word)
        {
            if (isspace(*temp_word))
                temp_word++;
            else if (strcmp(temp_word, comma) == 0 && is_comma)
            {
                /*להעלות שגיאה על פסיק כפול*/
            }
            else if (strcmp(temp_word, comma) == 0)
            {
                is_comma = TRUE;
                temp_word++;
            }
            else if(isdigit(*temp_word))
            {
                /*לקודד את המספר לבינארי ולהכניס אותו לטבלת קידוד */
                dc++;
                is_comma = FALSE;
            }

        }
    }
    else if (strcmp(temp_word, "s") == 0)
    {
        int len;
        temp_word += 7;
        len = (int)strlen(temp_word + 1);
        char str[len];
        int i;
        for (i = 0; i < len - 1; i++)
        {
            str[i] = *temp_word;
            dc++;
            temp_word++;
        }
        str[i+1] = '\0';
    }

}

boolean decode_command(char* word, int ic, Label *lable_table, /*מצביע לטבלת קידוד*/)
{

}



