#FLOODIT SOLVER
## COMO UTILIZAR
Para compilar: make 

Para executar : ./floodit < entrada.txt

Ou ainda há um script ./execute.sh, que irá ler os arquivos da pasta input, rodar a solução, e verificar se satisfaz a instância do jogo.

Arquivo de entrada: Número de linhas(n_linhas), número de colunas(n_colunas), número de cores(n_cores), e por fim o mapa mapa. A dimensão do mapa é limitado em 1000 linhas x 1000 colunas.

## O QUE É JOGO
Esse é um jogo de estratégia, onde o objetivo é ir escolhendo as cores, conforme acha que o tabuleiro se inundará mais rápido (menos etapas possíveis).

É considerado um jogo  np difícil a partir de 3 núcleos (Um jogo onde o número mínimo de operações de inundação é NP-difícil para um número de cores >= 3.) 
 
## DESCRIÇÃO DA IMPLEMENTAÇÃO REALIZADA
Sua implementação consiste em 3 estruturas de dados dados:
 -matriz representando a instância inicial;
 -matriz auxiliar para o teste das soluções;
 -e uma fila para o controle de cores.

A heurística aplicada se assemelha ao algoritmo de Busca Gulosa de Melhor Escolha: para uma instância inicial testa-se todas as opções, escolhendo a que apresenta melhor desempenho (solução em menos passos). Essa heurística é iimplementada na função count_color_region principalmente. Dada a cor escolhida para iniciar, ele conta quantas regiões foram pintadas com essa cor, e assim, quando todas as cores são testadas ele pega a que apresentar a maior contagem, e altera no mapa original. Ou seja, a cor que apresentou mais vizinhos do estado atual, seja ele inicial ou não.
Adiciona-se essa cor como parte da solução, e assim serão sucessivos passos até que tenhamos a inundação completa do mapa e a cor solução.
Foi restringido a 3.000 passos o máximo para retornar uma possível solução.

## AUTORES
Anna Caroline Bozzi (GRR20173532);
Mateus Felipe de Cássio Ferreira (GRR20176123).
## DISCIPLINA: CI209 - Inteligência Artificial
Orientador: Fabiano Silva

