#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Matriz {
    private:
        vector<vector<int>> matriz;
    public:
        Matriz(string nomeArquivo);
        ~Matriz();
        void lerMatriz(ifstream& arquivo, int tamanho);
        void imprimirMatriz();
        int caminharMatriz();
        void imprimirSoma(int soma);
    };
    
#endif

