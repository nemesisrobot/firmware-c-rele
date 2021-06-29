#include "configuracao.h"
#include <avr/io.h>
#include "rele.h"


//método que seta porta digita 13 como saida
void inicializa_configuracao_rele(void){
    DDRB |= (1 << DDB5);
}

//método para acionar rele
void aciona_rele(){
    PORTB |= (1 << PORTB5);
}

//método desativa rele
void desativa_rele(){
    PORTB &=~ (1 << PORTB5);
}

//metodo para controlar as operações 
void controle_rele(int* status_rele, int acao){
    if(acao == 0){
        (*status_rele)=0;
        desativa_rele();
    }

    if(acao == 1){
        (*status_rele)=1;
        aciona_rele();
    }
}