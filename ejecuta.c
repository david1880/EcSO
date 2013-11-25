#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
	int pid;
	int status;

	pid=fork();

	if (pid==0){
		execvp(argv[1],argv+1);
		exit(-1);
	}else{
		wait(&status);
		if (WIFEXITED(status)!=0){
			if (WEXITSTATUS(status)!=0){
				printf("Termino con errores\n");
			}else{
				printf("correcto\n");
			}
		}else{
			printf("terminado a capon\n");
		}
		
	}


	return 0;
}