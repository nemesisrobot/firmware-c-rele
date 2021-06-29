#include "configuracao.h"
#include <avr/io.h>
#include <util/delay.h>
#include "serial_tx.h"



//método para inicializar TX
void inicializa_serial_tx(void){
    

    //configurando porta serial
    UBRR0H = (BRC >> 8);
    UBRR0L = BRC;

    //Habilitando a comunicação serial
    UCSR0B = (1 << TXEN0);

    //habilitando paridade
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

}


//Método para imprimir status rele
void status_atual_rele(int* status_rele){

    if((*status_rele)==0){
        UDR0='D';
    }

    if((*status_rele)==1){
        UDR0='A';
    }
    _delay_ms(TEMPOESPERA);
    UDR0='\r';
    _delay_ms(TEMPOESPERA);
    UDR0='\n';
}