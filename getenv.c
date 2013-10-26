#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[]){
	
	
	char *nombre;
	nombre=getenv(argv[1]);
	
	printf("%s\n",nombre);
	return 0;
	
	
}
