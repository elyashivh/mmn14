#include "globals.h"

#include <stdio.h>



/*שגיאות אפשריות:
 * פעולה שאינה קיימת
 * מס' אופרנים שגוי
 * סוג אופרנד שאינו מתאים לפעולה
 * שם אוגר לא קיים
 * כל סמל מוגדר רק פעם אחת*/

#include "firs_pass.h"

void get_line_info(char file_name)
{
    int ic = IC_ADDRESS;   /**/
     int dc = 0;
     int l = 0;
     int line_counter = 0;
     boolean error = FALSE;
     char curr_line[MAX_LINE_LEN];
     char *temp_word;
     char s[2] = " ";
     int num_of_labels = 0; /* Number of labels */
     table label_table[num_of labels]; /*להוסיף מס' תוויות*/
    

     /*open file after pre-assmembler process*/
    if (file = fopen(file, "r") == NULL)
    {
        errors_list(0);
    }

    /*read the first line from the file and start the first pass*/
    do
    {
        fgets(curr_line, MAX_LINE_LEN, file);
        curr_line[strlen(curr_line)-2]= '\0';
        line_counter++;
        temp_word = strtok(curr_line, s);

        /*check the line type -  if empty or comment continue to the next line*/
        if (is_empty(curr_line) || is_comment(curr_line))
        {
            continue;    
        }
        /*check if the new line contain a label, and if it is new one*/
        else if(is_label(temp_word))
        {
            if (new_label(temp_word, label_table.label, /*מס שיצייין את המיקום בטבלת התוויות*/))
            {
                /*לעדכן מס תוויות*/
                enter_new_lable(temp_word, ic+dc, label_table.label, /*מס שיצייין את המיקום בטבלת התוויות*/)
            }
            else
            {
                /*להעלות שגיאה על תווית כפולה*/
            }
        }
        else if(is_directive(temp_word))
        {
            decod_directive(curr_line);
        }
        /*לחשוב אם באמת צריך את הבדיקה הזאת- כי זאת האופציה האחרונה והיא עיקר העבודה */
        else if (is_command(temp_word))
        {
            decod_command(curr_line);
        }
        


    } while (fgets(curr_line, MAX_LINE_LEN, file) != NULL);
    
}/*end of get_file_info*/


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


boolean is_comment(char* line)
{
    if (line[0] == ';')
        return TRUE;
    return FALSE;
}

boolean is_empty (char* line)
{
    
}

boolean is_label(char* word)
{
    int len = strlen(word);
    if(word[len-1] == ':')
        return TRUE;
    return FALSE;
}

boolean new_lebal(char* label, table *lable_table, int lebal_num)
{

}

void enter_new_lable(char* lable_name, int adress, table *lable_table, int label_num)
{
    lable_table[label_num]->name = lable_name;
    lable_table[label_num]->adress = adress;
}

boolean is_directive(char* word)
{
    int len = strlen(word);
    if(word[len-1] == '.')
        return TRUE;
    return FALSE;
}

boolean is_command(char* word)
{

}

void decode_directive(char* line)
{

}

void decode_command(char* word)
{

}

boolean decode_line(char* line)
{

}
