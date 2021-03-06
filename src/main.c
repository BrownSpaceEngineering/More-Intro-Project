#include <atmel_start.h>
// #include <stdio.h>
#include "dictionary.h"
#include "driver_examples.h"
#include "serial_print.h"
#include "string.h"
#include "serial_read.h"
#include "flashMorse.h"


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	// delay_ms(5000);

	//Initialize lookup table
	create_table();

	// Initialize serial print
	// s_print_init();
	s_read_init();

	//get local reference to decoded table
	char** decT = getDecTable(); 


	// printf("Encoded value of A: %s\n", getEncoded('A'));
	s_print("Encoded value of A:");
	s_print("\r\n");
	s_print(getEncoded('A'));
	s_print("\r\n");
	// printf("Encoded value of B: %s\n", getEncoded('B'));
	s_print("Encoded value of B:");
	s_print("\r\n");
	s_print(getEncoded('B'));
	s_print("\r\n");


	int totalCount = 0;
	for (int i = 0; i < TABLE_SIZE; i++){
		if(decT[i] != 0){
			// s_print("Decoded: ");
			// s_print(decT[i]);
			// s_print("\r\n");
			// s_print("Encoded: ");
			// s_print(getEncoded(*decT[i]));
			// s_print("\r\n\r\n");
			totalCount++;
		}
	}

	s_print("Total count:");
	char int_buf[100];
	s_print(itoa(totalCount, int_buf, 10));
	s_print("\r\n");


	// initialize serial read
	// s_read_init();


	while(1){
		char r[2];
		r[0] = s_read();
		r[1] = '\0';

		s_print("\r\n");
		s_print("Successfully read: ");
		s_print(r);
		s_print("\r\n");
		s_print("Encoded value of ");
		s_print(r);
		s_print(": ");
		char *enc = getEncoded(r[0]);
		s_print(enc);
		s_print("\r\n");
		// Flash lights
		flashMorse(enc);


	}


}
