#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sinais.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int data_available = 0;

void *producer(void *arg) {
    while (1) {
        sleep(1);
        pthread_mutex_lock(&mutex);
        data_available = 1;
        printf("Produtor: dado disponivel\n");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(2);
    }
}

void *consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (data_available == 0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Consumidor: dado consumido\n");
        data_available = 0;
        pthread_mutex_unlock(&mutex);
    }
}

void execute_sinais() {
    pthread_t prod, cons;
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
}
