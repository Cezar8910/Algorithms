#include <iostream>
#include <list>

using namespace std;

int main()
{

    list<int> lista;
    int tam = 10;
    list<int>::iterator it; // Ponteiro para a lista

    for (int i = 0; i < tam; i++)
    {
        lista.push_front(i);
    }

    it = lista.begin();   // Ponteiro para o inicio da lista
    advance(it, 5);       // Avança 5 posições
    lista.insert(it, 10); // insere um elemento na posicao 5

    lista.remove(2); // Remove um elemento especifico

    lista.sort(); // Ordena a lista

    lista.reverse(); // Inverte a lista

    cout << "Tamanho da lista: " << lista.size() << endl
         << endl;

    tam = lista.size();
    for (int i = 0; i < tam; i++)
    {
        cout << lista.front() << endl;
        lista.pop_front();
    }

    cout << "Tamanho da lista: " << lista.size() << endl;

    return 0;
}