// #include <atmel_start.h>
#include <stdio.h>
#include <string.h>



#define TABLE_SIZE 2
typedef struct {
	char* encoded;
	char* decoded;
} translation;

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




int main(void)
{
	/* Initializes MCU, drivers and middleware */
	// atmel_start_init();

	create_table();
	printf("Encoded value of A: %s\n", getEncoded("A"));
	printf("Decoded value of .-: %s\n", getDecoded(".-"));


	/* Replace the code below with your application code */


}
