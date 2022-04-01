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


//------------------------------------------ESTRUTURAS DE DADOS
// typedef struct{
// 	int color;
// 	//int checked;
// 	//int list;
// } board_game;


typedef struct {
	int lines, columns, colors;
	int **map;
	int **visited;
} game;


typedef struct {
    int size;
	int *solucao;
} solution;
//------------------------------------------


//------------------------------------------PROTÓTIPOS DE FUNÇÕES
game read_g();
//------------------------------------------



//------------------------------------------FUNÇÕES IMPLEMENTADAS
game read_g() {
	game game_instance;

	scanf("%d", &(game_instance.lines));
	scanf("%d", &(game_instance.columns));
	scanf("%d", &(game_instance.colors));

	game_instance.map = malloc(sizeof(int) * game_instance.lines);
	game_instance.visited = malloc(sizeof(int) * game_instance.lines);
	int i;
	int j;
	for (i = 0; i < game_instance.lines; ++i) {
		game_instance.map[i] = malloc(sizeof(int) * game_instance.columns);
		game_instance.visited[i] = malloc(sizeof(int) * game_instance.columns);
		for (j = 0; j < game_instance.columns; ++j) {
			scanf("%d", &(game_instance.map[i][j]));
			game_instance.visited[i][j] = 0;
		}
	}
	return game_instance;
}

void mostra_mapa(game *g) {
	
}
//------------------------------------------



//------------------------------------------MAIN
int main(){

	game game_instance = read_g();
}

//------------------------------------------