#include <atmel_start.h>
// #include <stdio.h>
#include "dictionary.h"
#include "driver_examples.h"
#include "serial_print.h"
#include "string.h"


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	//Initialize lookup table
	create_table();

	//USART_0_example();

	s_print_init();

	// s_print("Hello World!");




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


	// int j = 0;
	// for (int i = 0; i < TABLE_SIZE; i++){
	// 	if(decT[i] != 0){
	// 		printf("Decoded: %c\n", decT[i]);
	// 		j++;
	// 	}
	// }
	// printf("Total count: %d\n", j);

	int j = 0;
	for (int i = 0; i < TABLE_SIZE; i++){
		if(decT[i] != 0){
			s_print("Decoded:");
			s_print("\r\n");
			s_print(decT[i]);
			s_print("\r\n");
			j++;
		}
	}
	s_print("Total count:");
	// s_print(j);
	s_print("\r\n");


	// printf("5: %u\n", hashEnc("....."));

	// Test statements
	// for (int i = 0; i < TABLE_SIZE; i ++){
	// 	printf("Encoded value of %s: %s\n\n", t[i].decoded, getEncoded(t[i].decoded));
	// 	printf("Decoded value of %s: %s\n", t[i].encoded, getDecoded(t[i].encoded));
	// 	printf("----------------------------\n");
	// }

	


	/* Replace the code below with your application code */

	while(1){
		
	}


}
