#include "final.h"

void proceso_nuevo() {
	int i;
	for (i=0; i < MAX_PROCESSES; i++) {
		if (pids_activos[i] == 0) {
			pids_activos[i] = fork();
			if (pids_activos[i] == 0) {
				// Hijo
				pid = getpid();
			} else {
				// Padre
				pids_startedat[i] = (int) time(NULL);
				printf("%d --> %d\n", ppid, child);
			}
			return;
		}
	}

	printf("No encontró ningun slot vacío\n");
}

void procesos_control() {
    // printf("%d: Controlando procesos hijos\n", ppid);
    int i, status, activos = 0;

    for (i=0; i < MAX_PROCESSES; i++) {
        if (pids_activos[i] != 0) {
			activos+=1;
			pid_t test = waitpid(pids_activos[i], &status, WNOHANG);
			if (test == 0) {
				// El proceso sigue corriendo, reviso si no hay que terminarlo

				if ( time(NULL) - pids_startedat[i] > TIMEOUT ) {
					printf("%d: Matando proceso", pids_activos[i]);
					if ( kill(pids_activos[i], SIGKILL) == 0 ) {
						printf("%d: Muerto", pids_activos[i]);
						pids_activos[i] = 0;
					}
				}
			} else if ( test == pids_activos[i] && WIFEXITED(status) ) {
				// El proceso terminó

				printf("ppid: %d exit status = %d\n",  pids_activos[i], WEXITSTATUS(status));
				pids_activos[i] = 0;
			} else {
				// El proceso no terminó bien

				printf("%d: Algo falló", test);
				pids_activos[i] = 0;
			}
        }
    }

	if (activos != 0) {
		printf("Proceso(s) activos: %d\n", activos);
	}
}

