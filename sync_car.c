#include <stdio.h>
#include <pthread.h>

#include "sync_car.h"

void station_init(station * station){
    station->waiting = 0;
    station->free_seats = 0;
    station->boarding = 0;

    pthread_cond_init(&station->is_full, NULL);
    pthread_cond_init(&station->arrived, NULL);
    pthread_mutex_init(&station->lock, NULL);
}

void station_load_car(station *station, int count){
    pthread_mutex_lock(&station->lock);

    station->free_seats = count;
    pthread_cond_broadcast(&station->arrived);
    while(station->boarding > 0 || (station->waiting > 0 && station->free_seats > 0)){
        pthread_cond_wait(&station->is_full, &station->lock);
    }
    station->free_seats = 0;
    pthread_mutex_unlock(&station->lock);
}

void station_wait_for_car(station *station){
    pthread_mutex_lock(&station->lock);

    station->waiting ++;
    while(station->free_seats == 0){
        pthread_cond_wait(&station->arrived, &station->lock);
    }
    station->waiting --;
    station->free_seats --;
    station->boarding ++;
    pthread_mutex_unlock(&station->lock);
}

void station_on_board(station *station){
    pthread_mutex_lock(&station->lock);
    
    station->boarding--;
    pthread_cond_signal(&station->is_full);

    pthread_mutex_unlock(&station->lock);
}