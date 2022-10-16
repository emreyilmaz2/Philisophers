#include <stdio.h>
#include <limits.h>
#include <pthread.h>
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *epilogue(void *ptr)
{
    pthread_mutex_lock(&lock);
    for(int a=0; a<INT_MAX/2; a++)
    {
        int *temp = (int *)ptr;
        (*temp)++;
    }
    pthread_mutex_unlock(&lock);
    return(NULL);
}

int main()
{
    int i = 0;
    pthread_t new;
    pthread_create(&new, NULL, epilogue, &i);
    epilogue(&i);
    pthread_join(new, NULL);
    printf("Done : %d\n", i);
    return(0);
}