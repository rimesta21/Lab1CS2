#include <stdio.h>
#include <pthread.h>


int counter;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void *thread_func(void* tn)
{
    int i, temp;

    for (i = 0; i < 100000; i++) 
        temp++;

    pthread_mutex_lock(&mutex);
    counter += temp;
    pthread_mutex_unlock(&mutex);

    return NULL;

}



int main()

{     

    int i, N=4;

    pthread_t t[N];
    pthread_mutex_init(&mutex, NULL);

    for (i = 0; i < N; i++)     

        pthread_create(&t[i], NULL, thread_func, NULL);

    for (i = 0; i < N; i++)     

        pthread_join(t[i], NULL);

    printf("%d\n", counter);

    pthread_mutex_destroy(&mutex);

    return 0;

}