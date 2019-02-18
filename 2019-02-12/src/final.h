#ifndef info1final

#include<stdio.h> 
#include<signal.h>
#include <stdlib.h> // exit()
#include<stdio.h> // printf()
#include <sys/types.h> // pid_t
#include <unistd.h> // fork()
#include <sys/wait.h> // waitpid(), WIFEXITED, WEXITSTATUS

// Para manejar el timeout de los procesos hijos voy a 
// utilizar un time(), si por algun motivo no se pudiera
// podria utilizarse un contador "casero" poniendo un sleep
// en el main, es menos prolijo y exacto pero funcionaría
#include <time.h> // time()

//
void handler(int);

//
void proceso_nuevo();
void procesos_control();




#define MAX_PROCESSES 100
#define TIMEOUT 10

pid_t pids_activos[MAX_PROCESSES];
int   pids_startedat[MAX_PROCESSES];

pid_t ppid, pid, child;

#endif
