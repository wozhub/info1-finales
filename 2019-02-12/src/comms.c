#include "final.h"

// FIFO
//void fifo_transmitir(char* origen, char* destino) {
void fifo_transmitir() {

    FILE* fd_in = fopen("/tmp/info1.dat", "r");
    FILE* fd_out = fopen("/tmp/info1.fifo", "w");
    
    // Primero obtengo el tamaño del archivo y lo transmito
    fseek(fd_in, 0, SEEK_END);
    int filesize = ftell(fd_in); 
    fseek(fd_in, 0, SEEK_SET);
    printf("El archivo pesa %d bytes\n", filesize);
    fwrite(&filesize, sizeof(int), 1, fd_out); // sizeof(int) == 4 bytes



    fclose(fd_in);
    fclose(fd_out);
}
