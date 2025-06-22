#include <stdio.h>
#include <stdlib.h>

void criaHeap(int *vetor, int i, int final) {
    int temp = vetor[i];
    int j = i * 2 + 1;
    while (j <= final)
    {
        if (j < final && vetor[j] < vetor[j + 1]) {
            j = j + 1;
        }
        if (temp < vetor[j])
        {
            vetor[i] = vetor[j];
            i = j;
            j = 2 * i + 1;
        } else {
            j = final + 1;
        }
    }
    vetor[i] = temp;
}

void HeapSort(int *vetor, int tamanho){
    int temp;

    for (int i = (tamanho - 1)/2; i >= 0; i--)
    {
        criaHeap(vetor, i, tamanho - 1);
    }

    for (int i = tamanho - 1; i >= 1; i--)
    {
        temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        criaHeap(vetor, 0, i - 1);
    }
}

int main(int argc, char const *argv[])
{
    int vetorTeste[] = {7, 3, 6, 1, 9, 4, 2, 8, 10};
    int tamanho = 9;

    printf("Antes: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d, ", vetorTeste[i]);
    }
    printf("\n");

    HeapSort(vetorTeste, tamanho);

    printf("Depois do heap: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d, ", vetorTeste[i]);
    }   
    printf("\n");

    return 0;
}
