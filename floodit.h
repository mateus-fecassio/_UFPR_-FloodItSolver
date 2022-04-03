#ifndef _FLOODIT_H
#define _FLOODIT_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//------------------------------------------ESTRUTURAS DE DADOS
typedef struct {
	int lines, columns, colors;
	int **map;
} Game;


typedef struct {
    int steps;
	int *sequence;
} Solution;
//------------------------------------------


//------------------------------------------PROTÓTIPOS DE FUNÇÕES
int** allocate_matrix(int rows, int cols);
int** copy_matrix(int **matrix, Game *g);
void print_map(Game *g);
void print_matrix(int **matrix, int lines, int columns);
void print_array(int *array, int size);
void print_solution(Solution *s);


Game read_g(FILE *file);
Solution init_solution(void);


void floodFill(int **m, int rows, int cols, int r, int c, int init_c, int color);
int is_solved(int **m, int r, int c);
int count_color_region(int **m, int rows, int cols);
//------------------------------------------

#endif