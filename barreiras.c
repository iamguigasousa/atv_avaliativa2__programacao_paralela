#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "barreiras.h"

#define NUM_THREADS 5
pthread_barrier_t barrier;

void *worker(void *arg) {
    int id = *(int *)arg;
    printf("Thread %d: Antes da barreira\n", id);

    pthread_barrier_wait(&barrier);

    printf("Thread %d: Apos a barreira\n", id);
    return NULL;
}

void execute_barreiras() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    pthread_barrier_init(&barrier, NULL, NUM_THREADS);

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_barrier_destroy(&barrier);
}
