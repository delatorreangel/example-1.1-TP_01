// Grupo de placa 2824
// Integrantes 
        
        // Zambrana Erwin
        // de la Torre Angel


#include "mbed.h"
#include "arm_book_lib.h"
#include <cstdio>

int main()
{  
    // Se crea un objeto llamado gasDetector() de clase DigitalIn, que inicializa el pind D2 como entrada.
    DigitalIn gasDetector(D2);   
    
     // Se crea un objeto llamado alarmLed() de clase DigitalOut, que inicializa el LED1 como salida
     // en el que esta conectado el led1 que está integrado en la placa nucleo.
    DigitalOut alarmLed(LED1);
    
    //  Se habilita la resistencia PullDown en el Objeto gasDetector.
    gasDetector.mode(PullDown);
    
    // se inicializa la variable alarmLed como apagado.
    alarmLed = OFF;

    while (true) { 
        printf("%s\n","Hola mundo!");  // Escribimos Hola mundo en el puerto Com3, con 9600 br/s
        if ( gasDetector == ON ) {
            alarmLed = ON;
        }
        
        if ( gasDetector == OFF ) {
            alarmLed = OFF;
        }
    }
}