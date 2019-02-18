#include "final.h"

int main() {
	printf("%d: Iniciando proceso padre.", ppid);

    ppid = getpid();
    pid = ppid;

    // Probando la transmisión FIFO < EOF
    fifo_transmitir();

    exit(0);
    // EOF

    // Defino la señal que voy a esperar y la función para tratarla
    signal(SIGUSR1, handler); 

    while (1) {
        if (ppid == pid) {
            procesos_control();
        } else {
            // Si el pid y el ppid difieren, estoy en un children.
            // Hay varias formas de implementar eso, me pareció la más simple
            printf("%d: Entrando (c)\n", getpid());
            int countdown=20;
            while (countdown > 0) { 
                //printf("%d: %d...\n", getpid(), countdown); 
                countdown--;
                sleep(1);
            }
            printf("%d: Saliendo OK (c)\n", getpid());
            _exit(0);
        } 
        sleep(2);
    } 
    return 0; 
}
