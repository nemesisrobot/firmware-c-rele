#include "configuracao.h"

#include <avr/io.h>
#include <util/delay.h>

#include "rele.h"
#include "serial_tx.h"
#include "serial_rx.h"
int main(){
    int status_rele;
    char comando;

    //inicializando controle do rele e comunicação serial tx
    inicializa_configuracao_rele();
    inicializa_serial_tx();
    inicializa_serial_rx();
    while(1){
        comando = pegacomando();

        if(comando=='A'){
            _delay_ms(2000);
            controle_rele(&status_rele, 1);
            status_atual_rele(&status_rele);
        }

        if(comando=='B'){
            _delay_ms(2000);
            controle_rele(&status_rele, 0);
            status_atual_rele(&status_rele);
        }
    }

    return 1;
}