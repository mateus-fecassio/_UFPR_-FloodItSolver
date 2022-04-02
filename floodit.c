/*

--- AUTORES: 
- Anna Caroline Bozzi;
- Mateus Felipe de Cássio Ferreira;

--- GRR: 
- 2017
- 20176123

--- DISCIPLINA: CI209 - Inteligência Artificial
- Orientador: Fabiano Silva

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "floodit.h"
#include "stack.h"

#define SOLUTION_SIZE 2000




//------------------------------------------FUNÇÕES IMPLEMENTADAS
int** allocate_matrix(int rows, int cols) {
    int **matrix = (int**) malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; ++i){
        matrix[i] = (int*) calloc(cols, sizeof(int));
    }
    return matrix;
} //OK

int** copy_matrix(int **matrix, Game *g) {
    // int** matrix = allocate_matrix(g->lines, g->columns);

	for (int i = 0; i < g->lines; ++i) {
		memcpy(matrix[i], g->map[i], (g->columns*sizeof(int)));
	}
    return matrix;
} //OK

Game read_g(FILE *file) {
	Game game_instance;

	fscanf(file, "%d %d %d\n", &(game_instance.lines), &(game_instance.columns), &(game_instance.colors));

	game_instance.map = allocate_matrix(game_instance.lines, game_instance.columns);

	int i;
	int j;
	for (i = 0; i < game_instance.lines; ++i) {
		game_instance.map[i] = (int*) calloc(game_instance.columns, sizeof(int));
		for (j = 0; j < game_instance.columns; ++j) {
			fscanf(file, "%d", &(game_instance.map[i][j]));
		}
	}
	return game_instance;
} //OK

Solution init_solution(void) {
	Solution game_solution;

	game_solution.steps = 0;
	game_solution.sequence = (int*) calloc (SOLUTION_SIZE, sizeof(int));
	return game_solution;
} //OK

void print_map(Game *g) {
	int i, j;

	printf("%d %d %d\n", g->lines, g->columns, g->colors);
	for(i = 0; i < g->lines; ++i) {
		for(j = 0; j < g->columns; ++j) {
			printf("%d ", g->map[i][j]);
		}
		printf("\n");
	}
} //OK

void print_matrix(int **matrix, int lines, int columns) {
	int i, j;

	for(i = 0; i < lines; ++i) {
		for(j = 0; j < columns; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
} //OK

void print_array(int *array, int size) {
	int i;

	for(i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
} //OK

void floodFill(int **m, int rows, int cols, int r, int c, int init_c, int color) {
    m[r][c] = color;
    if (r < rows - 1 && m[r + 1][c] == init_c){
        floodFill(m, rows, cols, r + 1, c, init_c, color);
    }
    if (c < cols - 1 && m[r][c + 1] == init_c){
        floodFill(m, rows, cols, r, c + 1, init_c, color);
    }
    if (r > 0 && m[r - 1][c] == init_c){
        floodFill(m, rows, cols, r - 1, c, init_c, color);
    }
    if (c > 0 && m[r][c - 1] == init_c){
        floodFill(m, rows, cols, r, c - 1, init_c, color);
    }
} //OK


int is_solved(int **m, int r, int c) {
    int first_c = m[0][0];
	int sum = 0;
	int result = r*c*first_c;

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            sum += m[i][j];
        }
    }

	if (sum != result)
		return 0;
    return 1;    
}


void print_solution(Solution *s) {
    printf("%d\n", s->steps);
    for (int i = 0; i < s->steps; ++i) {
        printf("%d ", s->sequence[i]);
    }
    printf("\n");
}


int count_color_region(int **m, int rows, int cols)
{
    int first_c = m[0][0];
    int total = 0;

    int i, j;
    for (i = 0; i < rows; ++i) {
        for (j = 0; (m[i][j] == first_c && j < cols); ++j) {
            total++;
        }
        if (i + 1 < rows && m[i+1][0] != first_c && m[i+1][1] != first_c) {
            break;
        }
    }
    return total;
}

//------------------------------------------



//------------------------------------------MAIN
int main(void){
	FILE *file_input = stdin;
    if (!file_input){
        fprintf(stderr, "File not found. Finishing program.\n");
        exit(-1);
    }

	int max, color = 0;
	Game game_instance = read_g(file_input);
	Solution game_solution = init_solution();
	// print_map(&game_instance);

	StateQueue *queue = (StateQueue*) malloc(sizeof(StateQueue));
    queue->top = NULL;

    State *new = create_state(game_instance.map[0][0]);
    push(queue, new);

	int **m_aux = allocate_matrix(game_instance.lines, game_instance.columns);
	while ((queue->top) && (game_solution.steps < SOLUTION_SIZE)) {
		State *current = pop(queue);

		int current_c = current->color;
		State **frontier = (State**) malloc((game_instance.colors - 1) * sizeof(State*));
        
		int f_pos = 0;
		for (int i = 1; i <= game_instance.colors; ++i) {
			if (i == current_c)
            {
                continue;
            }
			frontier[f_pos] = create_state(i);

			m_aux = copy_matrix(m_aux, &game_instance);
			floodFill(m_aux, game_instance.lines, game_instance.columns, 0, 0, m_aux[0][0], i);
			if (is_solved(m_aux, game_instance.lines, game_instance.columns)) {
                game_solution.sequence[game_solution.steps++] = i;
                print_solution(&game_solution);

                return 0;
            }
			frontier[f_pos]->distance = count_color_region(m_aux, game_instance.lines, game_instance.columns);
			f_pos++;
		}
		
		max = frontier[0]->distance;
        color = frontier[0]->color;
        for (int i = 1; i < game_instance.colors - 1; ++i){
            if (frontier[i]->distance > max){
                max = frontier[i]->distance;
                color = frontier[i]->color;
            }
        }

		State *new = create_state(color);
        push(queue, new);

		floodFill(game_instance.map, game_instance.lines, game_instance.columns, 0, 0, game_instance.map[0][0], color);
		game_solution.sequence[game_solution.steps++] = color;
    }
	print_solution(&game_solution);
	return 0;
}

//------------------------------------------