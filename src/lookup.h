#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 2

typedef struct {
	char* encoded;
	char* decoded;
} translation;

translation* get_table();

void create_table();

char* getEncoded(char* dec);

char* getDecoded(char* enc);