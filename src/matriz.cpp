#include "matriz.h"

// Construtor
Matriz::Matriz(string nomeArquivo) 
{
    // Abrir arquivo
    ifstream arquivo(nomeArquivo);

    // Testar se está aberto
    if(arquivo.is_open()) {
        
        // Receber o tamanho em string
        string aux;
        getline(arquivo, aux);
        string tam = aux.substr(0, aux.find(' '));

        // Converter a string para um inteiro
        int tamanho = stoi(tam); 
        
        // Declarar a matriz como um vetor de vetores
        matriz = vector<vector<int>>(tamanho, vector<int>(tamanho));
        
        // Ler os valores da matriz do arquivo
        lerMatriz(arquivo, tamanho);
        
        // Fechar o arquivo
        arquivo.close();
    } 
    else 
    {
        cout << "Erro ao abrir arquivo" << endl;
    }
}

// Destrutor
Matriz::~Matriz() {}

// Função para ler a matriz do arquivo
void Matriz::lerMatriz(ifstream& arquivo, int tamanho) 
{   
    int linha = 0;
    int somaTotal= 0;

    while (!arquivo.eof())
    {
        int i = linha;
        for (i = 0; i < tamanho; i++) 
        {
            for (int j = 0; j < tamanho; j++) 
            {
                arquivo >> matriz[i][j];
            }
            linha++;
        }
        if(!arquivo.eof())
        {
            // Imprimir a matriz
            imprimirMatriz();

            // Caminhar pela matriz e somar total
            somaTotal = caminharMatriz() + somaTotal;
        }
    }
    imprimirSoma(somaTotal);
}

// Função para imprimir a matriz
void Matriz::imprimirMatriz() 
{
    cout << "##############################################################" << endl;
    cout << "Matriz:" << endl;
    int tam = matriz.size();
    for (int i = 0; i < tam; i++) 
    {
        for (int j = 0; j < tam; j++) 
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "##############################################################" << endl;
    cout << endl;
}

// Função para caminhar pela matriz
int Matriz::caminharMatriz() 
{

    // Criar matriz auxiliar para representar o caminho percorrido
    vector<vector<char>> caminho(matriz.size(), vector<char>(matriz.size(), ' '));

    // Iniciar na posição (0, 0)
    int i = 0, j = 0;
    int tam = matriz.size();

    // Preencher matriz auxiliar com 0
    for (int i = 0; i < tam; i++) 
    {
        for (int j = 0; j < tam; j++) {
            caminho[i][j] = '0';
        }
    }
    cout << "##############################################################" << endl;
    cout << "Caminho:" << endl;
    cout << endl;
    
    // Percorrer a matriz até chegar ao último elemento
    while (i != tam-1 || j != tam-1) 
    {
        // Marcar posição atual com '#'
        caminho[i][j] = '#';
        int max_valor = -1;
        int prox_i = i;
        int prox_j = j+1;
        cout << matriz[i][j] << "-";

        // Verificar se é a ultima linha
        if (i == tam-1)
        {
            j++;
        }
        else
        {
            // Verificar se pode avançar para a direita
            if (j < tam-1 && caminho[i][j+1] != '#') 
            {
                if (matriz[i][j+1] > max_valor) 
                {
                    max_valor = matriz[i][j+1];
                    prox_i = i;
                    prox_j = j+1;
                }
            }

            // Verificar se pode avançar para baixo
            if (i < tam-1 && caminho[i+1][j] != '#') 
            {
                if (matriz[i+1][j] > max_valor) 
                {
                    max_valor = matriz[i+1][j];
                    prox_i = i+1;
                    prox_j = j;
                }
            }

            // Verificar se pode avançar para baixo e para a direita
            if (i < tam-1 && j < tam-1 && caminho[i+1][j+1] != '#') 
            {
                if (matriz[i+1][j+1] > max_valor) 
                {
                    max_valor = matriz[i+1][j+1];
                    prox_i = i+1;
                    prox_j = j+1;
                }
            }

            // Verificar se pode avançar para baixo e para a esquerda
            if (i < tam-1 && j > 0 && caminho[i+1][j-1] != '#') 
            {
                if (matriz[i+1][j-1] > max_valor) 
                {
                    max_valor = matriz[i+1][j-1];
                    prox_i = i+1;
                    prox_j = j-1;
                }
            }

            // Verificar se pode retroceder para a coluna anterior
            if (j > 0 && caminho[i][j-1] != '#') 
            {
                if (matriz[i][j-1] > max_valor) 
                {
                    max_valor = matriz[i][j-1];
                    prox_i = i;
                    prox_j = j-1;
                }
            }
        }

        // Atualizar a posição atual para a posição com maior valor
        i = prox_i;
        j = prox_j;
    }

    // Imprimir ultimo elemento
    cout << matriz[i][j] << endl;
    cout << endl;
    cout << "##############################################################" << endl;
    cout << endl;
    
    // Marcar última posição com '#'
    caminho[i][j] = '#';

    // Imprimir caminho
    int soma = 0;
    cout << "##############################################################" << endl;
    cout << "Caminho por onde passou:" << endl;
    cout << endl;

    for (int i = 0; i < tam; i++) 
    {
        for (int j = 0; j < tam; j++) 
        {
            cout << caminho[i][j] << "\t";
            if(caminho[i][j] == '#')
            {
                soma+=matriz[i][j];
            }
        }
        cout << endl;
    }


    // imprime um espaço
    cout << endl;
    cout << "fim do caminho" << endl;
    cout << "##############################################################" << endl;
    cout << endl;
    cout << "##############################################################" << endl;
    cout << "soma da matriz = "; 
    cout << soma << endl;
    cout << "##############################################################" << endl;

    return soma;
}

// Imprime soma final
void Matriz::imprimirSoma(int soma) {
    cout << "##############################################################" << endl;
    cout << "A Soma total é:"; 
    cout << soma << endl;
    cout << "##############################################################" << endl;
} 