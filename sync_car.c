#include <stdio.h>
#include <pthread.h>

const int MAX_SEATS = 100;

typedef struct station{
    int waiting;
    int free_seats;
    int boarding;

    pthread_cond_t is_full;
    pthread_cond_t arrived;
    pthread_mutex_t lock;
} station;

void station_init(station * station){
    station->waiting = 0;
    station->free_seats = MAX_SEATS;
    station->boarding = 0;

    pthread_cond_init(&station->is_full, NULL);
    pthread_cond_init(&station->arrived, NULL);
    pthread_mutex_init(&station->lock, NULL);
}

//void station_load_car(station *station, int count)

//void station_wait_for_car(station *station)

//void station_on_board(station *station)

/* informacoes relevantes:
total de assentos que cada vagao pode ter (MAX_SEATS) - 
qtd de assentos ainda disponiveis no vagao (free_seats)
quantos passageiros estao esperando na estacao (waiting)
quantos passageiros estao embarcando (boarding)


pthread mutex:
init -> inicializa (em station_init)
lock -> trava (nas secoes criticas)
unlock -> destrava (nas secoes criticas, dps das operacoes)

variaveis de condicao:
is_full
arrived
*/ 
