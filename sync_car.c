#include <stdio.h>
#include <pthread.h>

const int MAX_SEATS = 100;

typedef struct station{
    int arrived;
    int waiting;
    int free_seats;
    int is_full;
    int boarding;

    pthread_mutex_t lock;
} station;

void station_init(station * station){
    station->arrived = 0;
    station->waiting = 0;
    station->free_seats = MAX_SEATS;
    station->is_full = 0;
    station->boarding = 0;

    pthread_mutex_init(&station->lock, NULL);
}

//void station_load_car(station *station, int count)

//void station_wait_for_car(station *station)

//void station_on_board(station *station)


int main(){

    return;
}

/* informacoes relevantes:
total de assentos que cada vagao pode ter (MAX_SEATS) - 
qtd de assentos ainda disponiveis no vagao (free_seats)
se tem algum trem na estacao (arrived)
quantos passageiros estao esperando na estacao (waiting)
quantos passageiros estao embarcando (boarding)
*/ 
