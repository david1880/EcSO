#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int pid;

int main(int argc, char *argv[])
{
	
	int p1[2],p2[2];
	char buf[1024];
	pipe(p1);
	pipe(p2);
	pid = fork();

	if (pid<0){
		fprintf(stderr, "El fork falló\n");
	}else if (pid==0){
		//hijo
		close(p1[1]); 	//cierro la entrada de p1
		close(p2[0]);	//cierro la salida de p2

		while(1){
			read(p1[0],buf,1024);
			int i;
			int a=strlen(buf);
			for (i=0; i<a; i++){
				buf[i]=toupper(buf[i]);
			}
			write(p2[1],buf,1024);
		}
		exit(0);

	}else{
		//padre
		close(p1[0]);	// cierro la salida de p1
		close(p2[1]);	// cierro la entrada de p2
		while(fgets(buf,1024,stdin)){
			write(p1[1],buf,1024);
			read(p2[0],buf,1024);
			printf("%s\n", buf);
			fflush(stdin);
		}
		fflush(NULL);
		kill(pid,SIGUSR1);
	}






	return 0;
}