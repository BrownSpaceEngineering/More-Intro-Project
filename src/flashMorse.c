#include "flashMorse.h"


void flashMorse(char * enc) {
    REG_PORT_DIR1 |= (1<<30);
    // s_print_init();
    int i = 0;
    //'Y'  "-.--";
    while(enc[i] != '\0') {
        if (enc[i] == '-'){
            // Turn led on
            REG_PORT_OUT1 &= ~(1<<30);
            // Delay for 1.5 seconds
            delay_ms(1500);
            // Turn led off
            REG_PORT_OUT1 |= (1<<30);
            // Delay for .5 seconds
            delay_ms(500);

        } else if (enc[i] == '.'){
            REG_PORT_OUT1 &= ~(1<<30);
            // Delay for .5 seconds
            delay_ms(500);
            // Turn led off
            REG_PORT_OUT1 |= (1<<30);
            // Delay for .5 seconds
            delay_ms(500);
        } else {
            s_print("Something went very wrong");
        }
        i++;
    }
}

/* Set pin PB30 to output */ 
// REG_PORT_DIR1 |= (1<<30);







	/* Make it blink! */
	// while (1) {
        // turn led on
		// REG_PORT_OUT1 &= ~(1<<30);
		// delay_ms(1000);
        // turn led off
		// REG_PORT_OUT1 |= (1<<30);
		// delay_ms(1000);


	// }