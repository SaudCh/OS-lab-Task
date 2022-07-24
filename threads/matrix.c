//write a program to multiply two matrices using threads without thread join
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define size 3

int mat[size][size] = {{1,2,3},{1,2,3},{1,2,3}};
int res[size][size];
//no of rows
int ind = 2;
pthread_t tid[3];

void* multiple(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();

    for(int i = 0;i<size;i++){
        for(int j = 0;j<size;j++){
            res[ind][i] += mat[ind][j] * mat[j][i];
        }
    }

    ind--;

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;

    while(i < 3)
    {
        err = pthread_create(&(tid[i]), NULL, &multiple, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");

        i++;
    }

    sleep(5);

    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            printf("%d\t",res[j][k]);
        }
        printf("\n");
    }

    return 0;
}