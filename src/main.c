// #include <atmel_start.h>
#include <stdio.h>
#include "lookup.h"



int main(void)
{
	/* Initializes MCU, drivers and middleware */
	// atmel_start_init();

	//Initialize lookup table
	create_table();

	translation* t = get_table();
	
	//Test statements
	for (int i = 0; i < TABLE_SIZE; i ++){
		printf("Encoded value of %s: %s\n\n", t[i].decoded, getEncoded(t[i].decoded));
		printf("Decoded value of %s: %s\n", t[i].encoded, getDecoded(t[i].encoded));
		printf("----------------------------\n");
	}


	/* Replace the code below with your application code */


}
