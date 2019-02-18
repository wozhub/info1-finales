#include "final.h"

void handler(int sig) { 
    // Estoy en una interrupción, el código que ejecute tiene que ser lo
    // más breve posible!
    //
    printf("Recibí señal: %d\n", sig);
	
	// Busco un "slot" vacio
	proceso_nuevo();
}

