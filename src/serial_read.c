#include "serial_read.h"


struct io_descriptor *io;

void s_read_init(){
	usart_sync_get_io_descriptor(&USART_0, &io);
	usart_sync_enable(&USART_0);
}

char s_read()
{
    char buf[1];
    while(io_read(io, (uint8_t *)buf, 1) == 0){
    }

    return buf[0];
}