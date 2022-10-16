#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void myturn()
{
    int i=-1;
    while(1)
    {
        printf("myturn ----> %d\n", ++i);
        sleep(1);
    }
}

void *yourturn(void *arg2)
{
    int i=0;
    while(1)
    {
        printf("yourturn --> %d\n", ++i);
        sleep(2);
    }
}

int main()
{
    pthread_t newthread;
    pthread_create(&newthread, NULL, yourturn, NULL);
    myturn();
    return(0);
}