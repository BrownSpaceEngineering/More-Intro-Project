#include "lookup.h"

translation lookup[TABLE_SIZE];

void create_table(){
	lookup[0].decoded = "A";
	lookup[0].encoded = ".-";

	lookup[1].decoded = "B";
	lookup[1].encoded = "-...";
}

char* getEncoded(char* dec){
	for (int i = 0; i < TABLE_SIZE; i++){
		if(lookup[i].decoded == dec){
			return lookup[i].encoded;
		}
	}
	return "Not Found";
}

char* getDecoded(char* enc){
	for (int i = 0; i < TABLE_SIZE; i++){
		if(strcmp(enc, lookup[i].encoded) == 0){
			return lookup[i].decoded;
		}
	}
	return "Not Found";
}