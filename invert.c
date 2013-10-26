#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(int argc, char *argv[]){
	
	
	int i;
	int j;
	
	
	for (i=argc-1;i>0;i--){
		for (j=strlen(argv[i])-1;j>=0;j--){
			printf("%c",argv[i][j]);
		}
		printf(" ");
	}
	
	printf("\n");
	
	
	return 0;
}
