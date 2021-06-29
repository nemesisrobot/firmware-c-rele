#include "configuracao.h"
#include <avr/io.h>
#include "serial_rx.h"

void inicializa_serial_rx(void){

    //configurando porta serial
    UBRR0H = (BRC >> 8);
    UBRR0L = BRC;

    //Habilitando a comunicação serial
    UCSR0B = (1 << RXEN0);

    //habilitando paridade
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

char pegacomando(void){
    char comando = UDR0;
    return comando;
}

