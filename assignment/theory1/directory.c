// Exercise 2: Write a program to illustrate “ls” command using system calls 
// 1. Start. 
// 2. Open directory using opendir( ) system call. 
// 3. Read the directory using readdir( ) system call. 
// 4. Print dp.name and dp.inode . 
// 5. Repeat above step until end of directory. 
// 6. End 

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(){
	DIR *dir;
	struct dirent *sd;
	
	dir = opendir(".");
	
	if(dir == NULL){
		printf("Error");
		exit(1);
	}
	
	while((sd = readdir(dir)) != NULL ){
		printf("%s	%lu \n",sd->d_name,sd->d_ino);
	}
	
	return 0;
}