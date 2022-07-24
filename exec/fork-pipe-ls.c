// Develop a C program that creates four child processes. Each of which does exactly one of the following (10)
// a) Child I creates a text file using cat command.
// b) Child 2 list down the content of current working directory.
// c) Child 3 creates a new directory using mkdir command
// d) Child 4 removes the directory that child 3 has created.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
int main()
{
	pid_t childpid;
	int i;

	for (i = 0; i < 4; i++)
	{
		childpid = fork();
		if (childpid == -1)
		{
			printf("Failed to fork!");
		}

		if (childpid == 0)
		{

			if (i == 0)
			{
				printf("I am Child %d", i + 1);
				execl("/bin/sh", "sh", "-c", "/bin/cat > test.txt", NULL);
			}

			else if (i == 1)
			{
				printf("I am Child %d", i + 1);
				DIR *dir;
				struct dirent *rd;
				dir = opendir(".");

				if (dir == NULL)
				{
					printf("Error opening directory!");
					exit(0);
				}

				while ((rd = readdir(dir)) != NULL)
				{
					printf(">> %s\t\n", rd->d_name);
				}

				closedir(dir);
			}

			else if (i == 2)
			{
				printf("I am Child %d", i + 1);
				execl("/bin/sh", "sh", "-c", "/bin/mkdir", "dir", NULL);
			}

			else if (i == 3)
			{
				printf("I am Child %d", i + 1);
				execl("/bin/sh", "sh", "-c", "/bin/rmdir", "dir", NULL);
			}
		}
		wait(NULL);
	}
}