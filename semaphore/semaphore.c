//intializing semaphore using sem_init()
#include <stdio.h>
#include <semaphore.h>

int sem_init(sem_t *sem, int pshared, unsigned int value);

int main()
{
    sem_t sem;
    int pshared;
    int ret;
    int value;

    pshared = 0;
    value = 1;

    ret = sem_init(&sem, pshared, value);

    if(ret == 0)
        printf("\nSemaphore Initialize Successfully\n");
    else
        printf("\nErorr\n");

}