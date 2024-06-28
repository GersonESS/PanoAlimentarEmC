#include <stdio.h>

// Função para trocar dois elementos de posição
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Função para realizar o Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // Um a um, move o limite do subarray não ordenado
    for (i = 0; i < n-1; i++) {
        // Encontra o menor elemento no subarray não ordenado
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Troca o menor elemento encontrado com o primeiro elemento
        swap(&arr[min_idx], &arr[i]);
    }
}

// Função para imprimir um array
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array original: \n");
    printArray(arr, n);

    selectionSort(arr, n);
    
    printf("\nArray ordenado: \n");
    printArray(arr, n);
    
    return 0;
}
