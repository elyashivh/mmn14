
#include "firs_pass.h"


#include <stdio.h>

static boolean make_process(char* argv[]);

int main(int argc, char* argv[]) {
     /*int i;

    for (i = 0; i < argc; i++)
    {
        make_process(argv[i]);
    }*/
     char* file_name = argv[1];
     get_line_info(file_name);

}


static boolean make_process(char* argv[])
{
    FILE* file;
    /*חלק של קדם אסמבלר*/




     /*חלק של מעבר ראשון*/
     int ic = IC_ADDRESS;   /**/
     int dc = 0;
     int l = 0;
     int line_counter = 0;
     boolean error = FALSE;
     char temp_line[MAX_LINE_LEN];
     

     
}

