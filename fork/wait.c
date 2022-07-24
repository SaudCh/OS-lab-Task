// use of wait command to wait for child process to finish

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int n;
	int id = fork();

	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}

	wait(NULL);

	for (int i = n; i < n + 5; i++)
		printf("%d ", i);

	return 0;
}
