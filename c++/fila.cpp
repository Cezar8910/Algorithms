#include <iostream>
#include <queue>

using namespace std;

int main()
{
    /* atribuções utilizadas:
     empty
     size
     front
     baxk
     push
     pop    
    */

    queue<string> fila;
    fila.push("primeiro");
    fila.push("segundo");
    fila.push("terceiro");

    while (!fila.empty())
    {
        cout << "Elemento da frente: " << fila.front() << endl;
        cout << "Elemento de tras: " << fila.back() << endl;
        cout << "Tamanho da fila: " << fila.size() << endl;
        fila.pop();
    }


    return 0;
}