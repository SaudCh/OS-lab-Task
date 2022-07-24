//producer and consumer problem using semaphore
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
 
#define MaxItems 5 
#define BufferSize 5 


sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;


void *producer(void *pno)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); 
        sem_wait(&empty); 
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)pno),buffer[in],in);
        in = (in+1)%BufferSize;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}

void *consumer(void *cno)
{   
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out]; 
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)cno),item, out);
        out = (out+1)%BufferSize; 
        pthread_mutex_unlock(&mutex);
        sem_post(&empty); 
    }
}

int main()
{   

    pthread_t pro,con; 
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty,0,BufferSize); 
    sem_init(&full,0,0); 

    int a = 1;
    pthread_create(&pro, NULL, (void *)producer, (void *)&a);
    pthread_create(&con, NULL, (void *)consumer, (void *)&a);

    pthread_join(pro, NULL);
    pthread_join(con, NULL);
    

    return 0;
    
}