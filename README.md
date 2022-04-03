#FLOODIT SOLVER
## COMO UTILIZAR
make ./floodit < entrada.txt
formato de entrada: n_linhas n_colunas n_cores mapa
ou ./execute.sh, irá ler os arquivos da pasta input, rodar o solução e verificar se está satisfeito
## O QUE É JOGO
Esse é um jogo de estratégia, onde o objetivo é ir escolhendo as cores, conforme acha que o tabuleiro se inundará mais rápido (menos etapas possíveis).
É considerado um jogo  np difícil a partir de 3 núcleos (Um jogo onde o número mínimo de operações de inundação é NP-difícil para um número de cores >= 3.) 
 
## DESCRIÇÃO DA IMPLEMENTAÇÃO REALIZADA
Sua implementação consiste em 3 estruturas de dados dados:
matriz representando a instância inicial;
matriz auxiliar para o teste das soluções;
e uma fila para o controle de cores.

A heurística aplicada se assemelha ao algoritmo de Busca Gulosa de Melhor Escolha, implementado na função count_color_region. Dada a cor escolhida para iniciar, ele conta quantas regiões foram pintadas com essa cor, e assim, quando todas as cores são testadas ele pega a que apresentar a maior contagem, e altera o mapa original.
Adicionando essa cor como parte da solução, e assim serão sucessivos passos até que tenhamos a inundação completa do mapa e a cor solução.
## AUTORES
Anna Caroline Bozzi (GRR20173532);
Mateus Felipe de Cássio Ferreira (GRR20176123).
## DISCIPLINA: CI209 - Inteligência Artificial
Orientador: Fabiano Silva

