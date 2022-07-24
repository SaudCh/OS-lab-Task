// write a program to find even and odd numbers

#include <stdio.h>

int main()
{

	int num;
	printf("Enter any Number");
	scanf("%d", &num);

	if (num % 2 == 0)
		printf("Even");
	else
		printf("Odd");

	return 0;
}
