#include <algorithm>
#include <iostream>
#include <vector>

#define IOFAST() ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

void merge(vector<int>& vetorItems, int left, int meio, int right) {

    // cria vetores temporários para as duas partes
    vector<int> esquerda(vetorItems.begin() + left, vetorItems.begin() + meio + 1);
    vector<int> direita(vetorItems.begin() + meio + 1, vetorItems.begin() + right + 1);

    int i = 0;
    int j = 0;
    int k = left;

    // compara os elementos das duas partes
    while (i < esquerda.size() && j < direita.size()) {

        if (esquerda[i] <= direita[j]) {
            vetorItems[k] = esquerda[i];
            i++;
        } else {
            vetorItems[k] = direita[j];
            j++;
        }

        k++;
    }

    // adiciona os elementos restantes da esquerda
    while (i < esquerda.size()) {
        vetorItems[k] = esquerda[i];
        i++;
        k++;
    }

    // adiciona os elementos restantes da direita
    while (j < direita.size()) {
        vetorItems[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& vetorItems, int left, int right) {

    // condição de parada
    if (left >= right) {
        return;
    }

    int meio = left + (right - left) / 2;

    // ordenação do lado esquerdo
    mergeSort(vetorItems, left, meio);

    // ordenação do lado direito
    mergeSort(vetorItems, meio + 1, right);

    // junta as duas partes ordenadas
    merge(vetorItems, left, meio, right);
}

int main() {
    IOFAST();

    // vetor que será ordenado
    vector<int> vetorItems = {12, 9, 13, 73, 77, 70, 66, 42};

    mergeSort(vetorItems, 0, vetorItems.size() - 1);

    for (int i = 0; i < vetorItems.size(); i++) {
        cout << vetorItems[i] << " ";
    }

    return 0;
}