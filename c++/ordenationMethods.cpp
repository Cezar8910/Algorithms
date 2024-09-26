
#include <iostream>
#include <vector>
using namespace std;
#define TAM 11

int heapSort()
{

}

int mergeSort()
{

}

int quickSort()
{

}

int bubbleSort()
{
int lista[TAM] = {1,5,7,0,4,8,9,6,4,7,10};
int i, j, aux;

//Bubble sort(péssimo método de ordenação)
cout << "Bubble Sort:" << endl;
for(i = 0; i < TAM; i++)
{
    for(j = i+1; j < TAM; j++)
    {
        if(lista[i] > lista[j])
        {
            aux = lista[i];
            lista[i] = lista[j];
            lista[j] = aux;
        }
    }
cout << "Elemento: " << lista[i] << endl;
}
}

int main()
{
bubbleSort();
heapSort();
mergeSort();
quickSort();

return 0;

}