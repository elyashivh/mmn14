#include <stdlib.h>
#include <stdio.h>

#define IC_ADDRESS 100
#define MAX_LINE_LEN 82

typedef enum {
    FALSE,
    TRUE
} boolean;

enum opcode {
    /*instructions with 2 operands */
    mov, cmp, add, sub, nit, clr, lea,
    /*instructions with 1 operand */
    inc, dec, jmp, bne, red, prn, jsr,
    /*instructions without operand */
    rts, stop};

enum registers {r0, r1, r2, r3, r4, r5, r6, r7};

enum adressing_methods {immediate, direct, jump, direct_register};

enum direcive_type {
    data,
    string, 
    entry, 
    externy };


typedef struct {
    char label[82];
    signed int address;
} table;

/*סוגי משפטים*/
typedef enum {
    empty,
    comment,
    directive,
    command
    } sentence_type;

/*שומר מידע על הנתונים שהשורה מכילה*/
typedef struct {
    int line_adress;
    sentence_type sentence;
    directive_type curr_dire_type;
    int opcode;
    boolean currect;
} line_info;

typedef struct {
    char* name;
    int start; //The number of the character from which the label content begins
    int end; //Same as above
    boolean external; //Sign if the label is from an external file
}Label;
