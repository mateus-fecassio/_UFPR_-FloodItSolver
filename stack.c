#include <stdlib.h>
#include "stack.h"
#include "floodit.h"

State* create_state(int color) {
    State *new = (State*) malloc(sizeof(State));
    new->color = color;
    new->distance = 0;
    new->prev = NULL;    

    return new;
}

void push(StateQueue *queue, State *s) {    
    if(!queue->top) {
        s->prev = NULL;
    } else {
        s->prev = queue->top;
    }
    queue->top = s;
}

State* pop(StateQueue *queue) {
    if (!queue->top) {
        return NULL;
    }

    State *aux = queue->top;
    queue->top = queue->top->prev;

    State *r = create_state(aux->color);

    free(aux);

    return r;
}