// Find the factorial of a number

#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int num,fact;
	printf("Enter the number: ");
	scanf("%d",&num);
	
	fact = 1;
	if(num>1){
		for(int i = num;i>1;i--){
			fact = fact*i;
		}
	}else if(num == 1|| num == 0){
		fact = 1;
	}else{
		printf("Enter the positive Number");
	}
	
	
	printf("The factorial of %d is %d\n",num,fact);
	return 0;
}