#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "leitores_escritores.h"

pthread_mutex_t resource_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t reader_count_mutex = PTHREAD_MUTEX_INITIALIZER;
int reader_count = 0;
int shared_data = 0;

void *reader(void *arg) {
    int id = *(int *)arg;
    while (1) {
        pthread_mutex_lock(&reader_count_mutex);
        reader_count++;
        if (reader_count == 1) {
            pthread_mutex_lock(&resource_mutex);
        }
        pthread_mutex_unlock(&reader_count_mutex);

        printf("Leitor %d leu o valor %d\n", id, shared_data);
        sleep(1);

        pthread_mutex_lock(&reader_count_mutex);
        reader_count--;
        if (reader_count == 0) {
            pthread_mutex_unlock(&resource_mutex);
        }
        pthread_mutex_unlock(&reader_count_mutex);

        sleep(rand() % 3);
    }
}

void *writer(void *arg) {
    int id = *(int *)arg;
    while (1) {
        pthread_mutex_lock(&resource_mutex);
        shared_data++;
        printf("Escritor %d escreveu o valor %d\n", id, shared_data);
        pthread_mutex_unlock(&resource_mutex);

        sleep(rand() % 3);
    }
}

void execute_leitores_escritores() {
    pthread_t readers[5], writers[2];
    int ids[5];
    for (int i = 0; i < 5; i++) {
        ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &ids[i]);
    }
    for (int i = 0; i < 2; i++) {
        ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &ids[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 2; i++) {
        pthread_join(writers[i], NULL);
    }
}
