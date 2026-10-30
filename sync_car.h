#define SYNC_CAR_H

#include <pthread.h>

typedef struct station{
    int waiting;
    int free_seats;
    int boarding;

    pthread_cond_t is_full;
    pthread_cond_t arrived;
    pthread_mutex_t lock;
} station;

void station_init(station * station);
void station_load_car(station *station, int count);
void station_wait_for_car(station *station);