# Final Informática 1 - UTN FRBA - 2019 02 12
## Consigna

La consigna del exámen es programar en C una aplicación que reciba una señal, cree un proceso hijo, y este transmita un archivo a traves de un socket o named-fifo.

- Señal a recibir: **SIGUSR1**
- Archivo a transmitir: **/etc/final/informatica1.dat**
- Información para la transferencia: **/etc/final/info_data**
  - Transferencia via socket: en el archivo **info_data** se encontrarán la dirección IP y el puerto destino (siempre en TCP/IP)
  - Transferencia via named-fifo: en el archivo **info_data** se encontrará el nombre de la named-fifo a utilizar para la transferencia, el cual ya debería estar creado y con los permisos de acceso correspondientes.

### Protocolo para la transferencia

Primero enviar un bloque de 4 bytes indicando la cantidad de bytes del archivo, y luego transferir el archivo.
Por cuestiones de diseño, el proceso hijo posee un acceso muy limitado a memoria, teniendo disponible solo **MAX_BTX** bytes para almacenar información del archivo a transferir. Justifique su criterio para seleccionar el tipo de memoria dónde almacenar los datos.

### Comunicación proceso hijo-padre

El proceso hijo debe comunicar al proceso padre el resultado de la transferencia, debiendo informar como mínimo si la transferencia se realizó correctamente o hubo algún error en el proceso. Se debe tener en cuenta que pueden estar corriendo al mismo tiempo varios procesos hijos.
El procedimiento a utilizar queda a su criterio, debiendo explicitar el mecanismo seleccionado.

### Gestión de procesos hijos

La aplicación debe estar preparada para gestionar al menos 100 procesos hijos a la vez. El proceso padre informará por pantalla cada vez que se lanza un proceso hijo (clonado), y cada vez que recibe el resultado desde un proceso hijo, indicando el resultado del mismo.
Si un proceso hijo demora más de 10 minutos en informar el resultado de la transferencia, el proceso padre debe dar por terminado el proceso, finalizando la ejecución del proceso hijo e informando por pantalla el suceso.
