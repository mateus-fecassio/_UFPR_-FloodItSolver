#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "floodit.h"

//------------------------------------------ESTRUTURAS DE DADOS
typedef struct State {
    int color;
    int distance;
    struct State *prev;
} State;

typedef struct StateQueue {
    struct State *top;
} StateQueue;
//------------------------------------------


//------------------------------------------PROTÓTIPOS DE FUNÇÕES
State *create_state(int color);
void push(StateQueue *queue, State *s);
State *pop(StateQueue *queue);
//------------------------------------------

#endif