public class SelectionSort {

    // Função para realizar o Selection Sort
    public static void selectionSort(int arr[]) {
        int n = arr.length;

        // Um a um, move o limite do subarray não ordenado
        for (int i = 0; i < n - 1; i++) {
            // Encontra o menor elemento no subarray não ordenado
            int min_idx = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // Troca o menor elemento encontrado com o primeiro elemento
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }

    // Função para imprimir um array
    public static void printArray(int arr[]) {
        int n = arr.length;
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    public static void main(String args[]) {
        int arr[] = {64, 25, 12, 22, 11};

        System.out.println("Array original:");
        printArray(arr);

        selectionSort(arr);

        System.out.println("Array ordenado:");
        printArray(arr);
    }
}
