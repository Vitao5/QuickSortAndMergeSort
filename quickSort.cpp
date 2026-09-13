#include <algorithm>
#include <iostream>
#include <vector>

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int partition(vector<int>& vetorItems, int left, int right) {
    int pivot = vetorItems[right];

    // indica o fim da região dos elementos menores ou iguais ao pivô
    int i = left - 1;

    for (int j = left; j < right; j++) {

        // se o elemento na posição j for menor ou igual ao pivô
        if (vetorItems[j] <= pivot) {

            // avança i para a próxima posição da região dos menores ou iguais ao pivô
            i++;

            // coloca o elemento na região da esquerda
            swap(vetorItems[i], vetorItems[j]);
        }
    }

    // coloca o pivô entre os elementos menores e maiores
    swap(vetorItems[i + 1], vetorItems[right]);

    // retorna a posição onde o pivô foi colocado
    return i + 1;
}

void quickSort(vector<int>& vetorItems, int left, int right){

    // condição de parada: se o subvetor tiver um ou nenhum elemento,
    // não há mais nada para ordenar
    if(left >= right){
        return;
    }

    // particiona o subvetor e retorna a posição do pivô
    int pivo = partition(vetorItems, left, right);

    // ordenação do lado esquerdo
    quickSort(vetorItems, left, pivo - 1);

    // ordenação do lado direito
    quickSort(vetorItems, pivo + 1, right);
}

int main() {
    IOFAST();

    //passando o vetor
    vector <int> vetorItems = {12,9,13,73,77,70,66,42};
    quickSort(vetorItems, 0, vetorItems.size()-1);

    for (int i = 0; i < vetorItems.size(); i++) {
        cout << vetorItems[i] << " ";
    }

    return 0;
}