#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 719

char* getDecTable();

void create_table();

char* getEncoded(char dec);

char getDecoded(char* enc);

unsigned hashEnc(char* s);



