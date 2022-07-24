// write a program for n number of fan processes

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int inp;
	int j = 0;
	
	printf("Enter the Number: ");
	scanf("%d",&inp);
	
	for(int i=0;i<inp;i++)
	{
		if(fork() == 0)
		{
			printf("my id is %d and my parent id is %d j = %d\n ",getpid(),getppid(),j);

			exit(0);
		}

    	wait(NULL);
		j++;
	
	}
	
}