# FLOODIT SOLVER

## COMO UTILIZAR
make
./floodit < entrada.txt 

formato da entrada:
n_linhas n_colunas n_cores
mapa


ou ./execute.sh, que irá ler os arquivos da pasta input, rodar o algoritmo e verificar se a solução é satisfeita

## O QUE É JOGO
- o que precisa ser feito no jogo
- o jogo é np difícil a partir de 3 cores (A game where the minimum number of flooding operations is NP-hard for a number of colors >= 3.)
https://arxiv.org/pdf/1001.4420.pdf

https://github.com/ricatosin/flooditsolver
https://github.com/almeidaraul/floodit-solver/blob/main/leiame.txt
https://github.com/Laionluis/Floodit-Solver-in-C/blob/master/leiame.txt

## DESCRIÇÃO DA IMPLEMENTAÇÃO REALIZADA
se assemelha ao BUSCA GULOSA DE MELHOR ESCOLHA (Greedy Best-First Search): 
três estruturas de dados (mapa, solução e a fila)
herística na função count_color_region baseada em contar quantas regiões foram pintadas por uma determinada cor e sempre pegar a cor que pinta mais como sendo parte da solução




## AUTORES
- Anna Caroline Bozzi (GRR2017 ---COMPLETAR);
- Mateus Felipe de Cássio Ferreira (GRR20176123).

#### DISCIPLINA: CI209 - Inteligência Artificial
- Orientador: Fabiano Silva