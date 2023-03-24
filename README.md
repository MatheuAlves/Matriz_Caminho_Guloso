# Matriz_Caminho_Guloso
[![Build Status](https://img.shields.io/badge/C%2B%2B-Language-green)](https://travis-ci.org/joemccann/dillinger)

>Status: Finalizado
## Algoritmo Guloso
Algoritmo que tenta resolver o problema fazendo a escolha localmente ótima em cada fase com a esperança de encontrar um ótimo global.

## Exercício proposto

Programa que soma os maiores valores do caminho de uma matriz quadrada caminhando por K matrizes quadradas de tamanho NxN de inteiros, iniciando da posição 0,0, e indo para o próximo maior número que esteja a direita, a esquerda, abaixo ou em alguma das duas diagonais para baixo da posição testada, desde que essa posição ainda não tenha sido acessada. Somente na última linha tem um comportamento diferente, pois sempre andará para a direita até o fim da matriz.

## Inicialização:
O programa começa com uma matriz sendo gerada pelo código: 
***https://github.com/mpiress/GenerateDataToMatrix*** que sempre irá criar um arquivo de nome ***input.data***, podendo alterar o tamanho do **N** e de **K** explicados na seção **Exercício proposto**.

## Lógica:
Começando pelo constructor da classe **Matriz** que recebe o nome do arquivo e é responsável por chamar as futuras funções do código.
Ele começa abrindo o arquivo, e em seguida recebe primeiro o tamanho das matrizes que estão na primeira linha do arquivo. Depois é declarada e chamada a função ***'lerMatriz()'*** onde será lida a matriz e chamada a função ***'caminharMatriz()'*** enquanto o arquivo estiver aberto.

A função ***caminharMatriz()*** irá testar os possíveis casos:
<br>
****x representa a posição atual e os quadrados coloridos as possiveis posições que serão testadas***

### **Caso 1** 
+ ##### Primeira coluna:
<p align="center">
  <img src="img/PosicaoPrimeiraColuna.png" width="150" title="Primeira Coluna">
</p>
Nesse caso é impossível retornar para qualquer posição à esquerda, já que estamos na primeira coluna.

### **Caso 2** 
+ ##### Última coluna:
<p align="center">
  <img src="img/PosicaoUltimaColuna.png" width="150" title="Última Coluna">
</p>
Nesse caso é impossível avançar para qualquer posição à direita, já que estamos na última coluna.

### **Caso 3** 
+ ##### Última linha:
<p align="center">
  <img src="img/PosicaoUltimaLinha.png" width="150" title="Última Linha">
</p>
Sempre que x estiver na última linha a próxima posição será à direita até alcançar a última posição da matriz.

### **Caso 4** 
+ ##### Todas as posições possíveis:
<p align="center">
  <img src="img/PosicoesPossiveis.png" width="150" title="Posições Possíveis">
</p>
Nesse caso deve caminhar para a direita, para baixo, diagonal inferior direita, diagonal inferior esquerda, ou esquerda, nessa mesma ordem escrita.

***Lembrando que caso tenham dois ou mais inteiros de mesmo valor a prioridade é a direita!**

## Finalização:
+ ##### Em seguida será impresso na tela a matriz pela função ***imprimirMatriz()***:
<p align="center">
  <img src="img/imagemMatriz.png" width="250" title="Matriz Impressa">
</p>

+ ##### o caminho percorrido: 
<p align="center">
  <img src="img/imagemCaminhoPercorrido.png" width="250" title="Caminho Percorrido"><br>
 *Onde '#' representa as posições que o código passou.
</p>


+ ##### o caminho por onde passou:
<p align="center">
  <img src="img/imagemCaminho.png" width="150" title="Caminho">
</p>

+ ##### e a soma do caminho da matriz:
<p align="center">
  <img src="img/imagemSomaMatriz.png" width="150" title="Soma">
</p>

+ ##### A cada matriz passada ela retornará o valor da soma para a variável ***somaTotal*** que ao final de tudo imprimirá o valor de todas as somas:
<p align="center">
  <img src="img/imagemSomaTotal.png" width="150" title="Soma Total">
</p>