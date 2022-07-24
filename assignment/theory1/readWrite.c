// Exercise 1: Write a C program to illustrate the mv command using system Calls

// 1. Open one existed file and one new open file using open( ) system call
// 2. Read the contents from keyboard using read( )
// 3. Write these contents into file using write()
// 4. Repeat 2,3 steps until eof
// 5. Close 2 file using fclose( ) system call
// 6. Delete existed file using using unlink( ) system.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd1, fd2;
	char out;

	fd1 = open("existing.txt", O_RDONLY);
	fd2 = open("new.txt", O_WRONLY);

	if (fd1 != -1 && fd2 != -1)
	{

		while (read(fd1, &out, 1) != 0)
		{
			write(fd2, &out, 1);
			printf("%c", out);
		}
		close(fd1);
		close(fd2);
	}
	else
	{
		printf("Error Opening the File");
	}
	unlink("existing.txt");

	return 0;
}