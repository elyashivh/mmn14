#include "globals.h"

void get_line_info(char *file_name);

int check_line_type(char *curr_line, char *temp_word, Label *label_table, int *lable_counter, int ic, int dc);

void errors_list(int error_num);

boolean comment_or_empty(char* line);

boolean is_label(char* word);

boolean new_label(char* label, Label *lable_table, int *label_num);

void enter_new_label(char *label_name, int address, Label *label_table, int label_num);

boolean is_directive(char *word);

boolean decode_directive(char* line, int dc);






