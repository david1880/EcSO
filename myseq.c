#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[]){
	
	switch (argc) {
		case 1:{
			puts("Uso");
			break;
		}
		case 2:{
			int num= atoi(argv[1]);
			int i;
			for(i=1;i<=num;i++){
				printf("%d\n",i);
			}
			break;
		}
		case 3:{
			int ini= atoi(argv[1]);
			int fin= atoi(argv[2]);
			int i;
			for(i=ini;i<=fin;i++){
				printf("%d\n",i);
			}
			break;
		}
		case 4:{
			int ini= atoi(argv[1]);
			int inc= atoi(argv[2]);
			int fin= atoi(argv[3]);
			int i;
			for(i=ini;i<=fin;i+=inc){
				printf("%d\n",i);
			}
			break;
		}
	}
	
	
	
	
	
	return 0;
}
