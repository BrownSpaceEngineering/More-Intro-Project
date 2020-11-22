#include "serial_print.h"

struct io_descriptor *io;

void s_print_init(){
	usart_sync_get_io_descriptor(&USART_0, &io);
	usart_sync_enable(&USART_0);
}

// char* itoa(int i){
    
// }

void s_print(char* buf)
{
    char* s;
    for(s=buf; *s; ++s);
    unsigned int size = (unsigned int)(s - buf);

	io_write(io, (uint8_t *)buf, size);
}