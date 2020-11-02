// #include <atmel_start.h>
#include <stdio.h>
#include "lookup.h"



int main(void)
{
	/* Initializes MCU, drivers and middleware */
	// atmel_start_init();

	create_table();
	printf("Encoded value of A: %s\n", getEncoded("A"));
	printf("Decoded value of .-: %s\n", getDecoded(".-"));


	/* Replace the code below with your application code */


}
