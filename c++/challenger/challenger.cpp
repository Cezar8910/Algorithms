/* ******************************************************************************************************
DESAFIO 3 - ALGORITMOS E ESTRUTURAS DE DADOS
QUESTÃO 2 - 29/08/2024

ALUNOS: ARTHUR DE LIMA PINHEIRO ALVES
        CEZAR DE AGUIAR GALVÃO
        EDUARDO ALVES PINTO VILAR DE OLIVEIRA
        PEDRO HENRIQUE ANDRADE DA SILVA
******************************************************************************************************* */

#include <iostream>

using namespace std;

struct posicao
{
    int valor;
    posicao *prox;

    posicao(int valor) : valor(valor), prox(nullptr) {}
};

class Fila
{
public:
    posicao *inicio;
    posicao *fim;

    Fila() : inicio(nullptr), fim(nullptr) {}

    void adiciona(int v)
    {
        posicao *novo = new posicao(v);
        if (!inicio)
        {
            inicio = novo;
            fim = novo;
        }
        else
        {
            fim->prox = novo;
            fim = novo;
        }
    }

    void retira()
    {
        if (inicio)
        {
            posicao *atual = inicio;
            inicio = inicio->prox;
            delete atual;
            if (!inicio) // Caso a fila fique vazia
            {
                fim = nullptr;
            }
        }
    }

    bool vazia()
    {
        return inicio == nullptr;
    }
};

class Grafo
{
private:
    Fila filaexec;

public:
    int **matriz;
    bool *visitado;
    int *pais;
    int vertices;

    Grafo(int v) : vertices(v)
    {
        matriz = new int *[vertices];
        pais = new int[vertices];
        visitado = new bool[vertices];
        for (int i = 0; i < vertices; i++)
        {
            matriz[i] = new int[vertices];
            visitado[i] = false;
            pais[i] = -1;
        }

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                matriz[i][j] = 0;
            }
        }
    }

    void adiciona(int inicio, int fim)
    {
        matriz[inicio][fim] = 1;
    }

    bool bfsFunction(int inicio, int fim)
    {
        filaexec.adiciona(inicio);
        visitado[inicio] = true;

        while (!filaexec.vazia())
        {
            int aux = filaexec.inicio->valor;
            filaexec.retira();

            if (aux == fim)
            {
                return true; // Caminho encontrado
            }

            for (int i = 0; i < vertices; i++)
            {
                if (matriz[aux][i] == 1 && !visitado[i])
                {
                    filaexec.adiciona(i);
                    visitado[i] = true;
                    pais[i] = aux;
                }
            }
        }
        return false; // Caminho não encontrado
    }

    void imprimeCaminho(int inicio, int fim)
    {
        if (!visitado[fim])
        {
            cout << "Nenhum caminho encontrado de " << inicio << " a " << fim << endl;
            return;
        }

        int caminho[vertices];
        int indice = 0;
        int atual = fim;

        while (atual != -1)
        {
            caminho[indice++] = atual;
            atual = pais[atual];
        }

        for (int i = indice - 1; i >= 0; i--)
        {
            cout << caminho[i] << " ";
        }
        cout << endl;
    }

    void deleta()
    {
        for (int i = 0; i < vertices; i++)
        {
            delete[] matriz[i];
        }
        delete[] matriz;
        delete[] visitado;
        delete[] pais;
    }
};

int main()
{
    int vertices;
    int arestas;
    cin >> vertices >> arestas;
    Grafo grafo(vertices);

    int grafoA;
    int grafoB;

    for (int i = 0; i < arestas; i++)
    {
        cin >> grafoA >> grafoB;
        grafo.adiciona(grafoA, grafoB);
    }

    int inicio;
    int fim;
    cin >> inicio >> fim;

    if (grafo.bfsFunction(inicio, fim))
    {
        grafo.imprimeCaminho(inicio, fim);
    }
    else
    {
        cout << "Nenhum caminho encontrado de " << inicio << " a " << fim << endl;
    }

    grafo.deleta();

    return 0;
}
