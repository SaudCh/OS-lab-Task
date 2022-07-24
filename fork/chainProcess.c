//write a function for chain processing using fork()

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	int choice;
	
	printf("Enter Number: ");
	scanf("%d",&choice);
	
	int q;
	
	for(int i = 0;i<choice;i++){
		q = fork();
	
	if(q<0){
		printf("Error");
	}else if(q==0){

		printf("I am child and my id is %d and my parent id is %d \n",getpid(),getppid());
	}else if(q>0){
        
		printf("I am parent and my id is %d and my child id is %d \n",getpid(),q);
	}
	
	}
	return 0;
}