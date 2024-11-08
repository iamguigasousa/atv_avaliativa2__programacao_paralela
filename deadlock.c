#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "deadlock.h"

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void *thread1_func(void *arg) {
    pthread_mutex_lock(&mutex1);
    printf("Thread 1: possui mutex1, esperando por mutex2\n");
    sleep(1);
    pthread_mutex_lock(&mutex2);
    printf("Thread 1: possui mutex1 e mutex2\n");

    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

void *thread2_func(void *arg) {
    pthread_mutex_lock(&mutex2);
    printf("Thread 2: possui mutex2, esperando por mutex1\n");
    sleep(1);
    pthread_mutex_lock(&mutex1);
    printf("Thread 2: possui mutex1 e mutex2\n");

    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    return NULL;
}

void execute_deadlock() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}
