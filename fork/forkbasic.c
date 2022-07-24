//fork basic program
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>

int main(){

	int id = fork();

	if(id == -1){
		printf("Fork Failed");
		exit(1);
	}
	
	if(id == 0)
	printf("I am child, my id is %d and my parent id is %d \n",getpid(),getppid());
	else
	printf("I am Parent, my id is %d and my child id is %d\n",getpid(),id);
		
	
	return 0;
}
