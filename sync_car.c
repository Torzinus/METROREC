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
    pthread_mutex_unlock(&station->lock);
}

//void station_on_board(station *station)

/* 
pthread mutex:
init -> inicializa (em station_init)
lock -> trava (nas secoes criticas)
unlock -> destrava (nas secoes criticas, dps das operacoes)

variaveis de condicao:
is_full
arrived

station_load_car
o trem chega na estacao
acorda as threads dos passageiros para que eles subam no trem
espera as condicoes para partir (nao tem ninguem esperando, nao tem ninguem entrando, nao tem assentos livres)

station_wait_for_car
o passageiro chega na estacao
espera o trem chegar (arrived) e station_load_car
verifica se tem assentos livres (free_seats > 0)

station_on_board 
e executada quando o passageiro embarca
boarding ++
*/ 
