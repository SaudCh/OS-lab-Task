// find largest number among three numbers

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1, num2, num3;

	printf("Enter the first number: ");
	scanf("%d", &num1);
	printf("Enter the first number: ");
	scanf("%d", &num2);
	printf("Enter the first number: ");
	scanf("%d", &num3);

	if (num1 > num2 && num1 > num3)
		printf("%d is greater", num1);
	else if (num2 > num1 && num2 > num3)
		printf("%d is greater", num2);
	else if (num3 > num2 && num3 > num1)
		printf("%d is greater", num3);

	return 0;
}