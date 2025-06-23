#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *vetor = NULL;
int tamanho = 0;

void criaHeap(int *vetor, int i, int final) {
    int temp = vetor[i];
    int j = i * 2 + 1;

    while (j <= final)
    {
        if (j < final && vetor[j] < vetor[j+1])
        {
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

void heapSort(int *vetor, int tamanho) {
    int temp;
    //fazendo o max heap
    for (int i = (tamanho -1 ) / 2; i >= 0; i--)
    {
        criaHeap(vetor, i, tamanho - 1);
    }   

    printf("\n=== apos heap maximo ===\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    
    for (int i = tamanho - 1; i >= 1; i--)
    {
        temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        criaHeap(vetor, 0, i - 1);
    }
}

void inicializaVetor(int novoTamanho) {
    if (vetor != NULL) {
        free(vetor);
    }
    vetor = (int*) malloc(novoTamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    tamanho = novoTamanho;
    printf("Vetor inicializado com tamanho %d.\n", tamanho);
}

void aleatorizaVetor() {
    if (vetor == NULL) {
        printf("Vetor não foi inicializado ainda!\n");
        return;
    }
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }
    printf("Vetor preenchido com valores aleatórios.\n");
}

void imprimeVetor() {
    if (vetor == NULL) {
        printf("Vetor não foi inicializado ainda!\n");
        return;
    }
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int opcao;
    int novoTamanho;

    while (1)
    {
        printf("\n\n====== Heap Sort Simulator ======\n");
        printf("1 - inicializa tamanho do vetor\n");
        printf("2 - aleatoriza o vetor\n");
        printf("3 - printa o vetor\n");
        printf("4 - aplicar heap sort\n");
        printf("0 - sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Digite o tamanho do vetor: ");
            scanf("%d", &novoTamanho);
            inicializaVetor(novoTamanho);
            break;

        case 2:
            aleatorizaVetor();
            break;

        case 3:
            imprimeVetor();
            break;

        case 4:
            if (vetor == NULL) {
                printf("Vetor não foi inicializado ainda!\n");
            } else {
                heapSort(vetor, tamanho);
                printf("Heap Sort aplicado com sucesso.\n");
            }
            break;

        case 0:
            printf("Encerrando o programa...\n");
            if (vetor != NULL) free(vetor);
            exit(0);

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    
    return 0;
}
