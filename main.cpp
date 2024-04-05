// Grupo de placa 2824
// Integrantes 
        
        // Zambrana Erwin 94999
        // de la Torre Angel


#include "mbed.h"
#include "arm_book_lib.h"
#include <cstdio>

int main()
{  
    // Erwin:
    // Se crea un objeto llamado gasDetector() de clase DigitalIn, que inicializa el pind D2 como entrada.
    // Al hacer step into en DigitalIn me lleva al archivo DigitalIn.h donde esta definido
    // la el constructor de la clase DigitalIn(PinName pin) en que se le pasa un nombre de
    // un pin de la placa nucleo que se lo quiere configurar como entrada.
    // Luego al hacer step into a la función gpio_init_in(&gpio, pin) que esta dentro del constructor
    // mencionado DigitalIn(PinName pin), me lleva al archivo mbed_gpio.c donde
    // esta definido la función 
    // void gpio_init_in(gpio_t *gpio, PinName pin) que recibe una direccion de memoria
    // de donde esta ubicado el registro para configurar el pin del micro que corresponde
    // al pin D2 de la placa de desarrollo.
    // Luego dentro de la funcion gpio_init_in() se hace step into
    // en la función gpio_init_in_ex(gpio, pin, PullDefault) en que se le pasa
    // la direccion de memoria para controlar el periferico gpio, el numero de pin
    // que queremos configurar como entrada y el modo de configurarcion de pullup o pulldown
    // en este caso se le pasa el pullup por defecto.
    // La funcion gpio_init_in_ex se encuentra en el mismo archivo mbed_gpio.c
    // en el que llama a la funcion _gpio_init_in(gpio, pin, mode) que al hacer
    // step into, se ve que se inicializa el pin de interes
    // con gpio_init(gpio, pin) y que con
    // gpio_dir(gpio, PIN_INPUT); mediante el registro gpio, se configura el puerto gpio como
    // como entrada
    //     gpio_mode(gpio, mode); se configura el puerto  si se comporta con pull up o no
    // Dentro de gpio_init() que esta en gpio_api.c
    // se puede ver que configura al objeto gpio_t que corresponde como configurar al
    // puerto gpio con el pin de interes como salida
    // a ese objeto gpio_t tiene como campos de configuracion
    // mask, puerto, ll_pin, reg_in, reg_set
        // Fill GPIO object structure for future use
    // obj->mask    = gpio_set(pin);
    // obj->gpio    = gpio;
    // obj->ll_pin  = ll_pin_defines[STM_PIN(obj->pin)];
    // obj->reg_in  = &gpio->IDR;
    // obj->reg_set = &gpio->BSRR;
    // Luego dentro de la función gpio_set() se utilizan
    // la función gpio_map donde se mete mas a bajo nivel como es la configuración de los pines
    // en multiples modos de funcionamiento excedente a lo que se quiere
    // Luego de hacer tanto step into se llega un punto donde directamente se modifican los
    // registros a nivel assembly para configurar la salida D2 como salida que implica
    // indexar el puerto y el pin del micro que corresponde al pin D2 de la placa nucleo
    DigitalIn gasDetector(D2);   
    
    // Erwin
     // Se crea un objeto llamado alarmLed() de clase DigitalOut, que inicializa el LED1 como salida
     // en el que esta conectado el led1 que está integrado en la placa nucleo.
     // Al entrar en esta función con step into por el mismo proceso que se paso por
     // DigitalIn, en el proceso de inicializacion solo que se configura el pin LED1 como salida
     // en que las funciones detras del constructor DigitalOut se encargan de
     // configurar al pin de interes que prende el el LED1 que asocia al pin
     // del microcontrolador
    DigitalOut alarmLed(LED1);
    
    // Erwin
    //  Se habilita la resistencia PullDown en el Objeto gasDetector.
    // Se utiliza el metodo mode() de la clase para configurar el pin de salida
    // con pulldown. Al hacer varios step into, se utlizan funciones de bajo nivel para configurar
    // el pin de salida con pull down
    gasDetector.mode(PullDown);
    
    // se inicializa la variable alarmLed como apagado.
    // que setea el pin de salida donde el led 1 con 1 en 
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