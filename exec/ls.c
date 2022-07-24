// execl command to list files in a directory
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main (){
	
	printf("Before Exec Command");
	
	char *binaryPath = "/bin/ls";
	char *arg1 = "-lh";
	char *arg2 = "../basic/even";
	
	execl(binaryPath,binaryPath, arg1,arg2,NULL);
	
	
	printf("Before Exec Command");
	
	return 0;
}