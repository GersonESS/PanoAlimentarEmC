#include <stdio.h>
#include <string.h>

// Definição da estrutura Alimento
typedef struct {
    char nomeAlim[51];
    float qtdAli;
    char undAli[4];
    float kcalAli;
} Alimento;

// Função para preencher os dados de um Alimento
void preencherAlimento(Alimento *alim) {
    printf("Digite o nome do alimento: ");
    fgets(alim->nomeAlim, 51, stdin);
    alim->nomeAlim[strcspn(alim->nomeAlim, "\n")] = 0; // Remove newline

    printf("Digite a quantidade do alimento: ");
    scanf("%f", &alim->qtdAli);
    getchar(); // Limpa o buffer do teclado

    printf("Digite a unidade do alimento (ex: kg, g, ml): ");
    fgets(alim->undAli, 4, stdin);
    alim->undAli[strcspn(alim->undAli, "\n")] = 0; // Remove newline

    printf("Digite as calorias do alimento: ");
    scanf("%f", &alim->kcalAli);
    getchar(); // Limpa o buffer do teclado
}

// Função para imprimir os dados de um Alimento
void imprimirAlimento(Alimento alim) {
    printf("\nNome do Alimento: %s\n", alim.nomeAlim);
    printf("Quantidade: %.2f\n", alim.qtdAli);
    printf("Unidade: %s\n", alim.undAli);
    printf("Calorias: %.2f kcal\n", alim.kcalAli);
}

// Função para imprimir os dados do alimento em arquivos CSV e TXT
void imprimirPlanoAlimentar(Alimento alim) {
    // Abrir o arquivo CSV para escrita
    FILE *csvFile = fopen("saida.csv", "w");
    if (csvFile == NULL) {
        printf("Erro ao abrir o arquivo saida.csv\n");
        return;
    }

    // Escrever os dados no arquivo CSV
    fprintf(csvFile, "Nome do Alimento,Quantidade,Unidade,Calorias\n");
    fprintf(csvFile, "%s,%.2f,%s,%.2f\n", alim.nomeAlim, alim.qtdAli, alim.undAli, alim.kcalAli);

    // Fechar o arquivo CSV
    fclose(csvFile);

    // Abrir o arquivo TXT para escrita
    FILE *txtFile = fopen("saida.txt", "w");
    if (txtFile == NULL) {
        printf("Erro ao abrir o arquivo saida.txt\n");
        return;
    }

    // Escrever os dados no arquivo TXT
    fprintf(txtFile, "Nome do Alimento: %s\n", alim.nomeAlim);
    fprintf(txtFile, "Quantidade: %.2f\n", alim.qtdAli);
    fprintf(txtFile, "Unidade: %s\n", alim.undAli);
    fprintf(txtFile, "Calorias: %.2f kcal\n", alim.kcalAli);

    // Fechar o arquivo TXT
    fclose(txtFile);

    printf("Dados gravados com sucesso em saida.csv e saida.txt\n");
}

int main() {
    Alimento meuAlim;

    // Preenche os dados do alimento
    preencherAlimento(&meuAlim);

    // Imprime os dados do alimento na tela
    imprimirAlimento(meuAlim);

    // Imprime os dados do alimento em arquivos CSV e TXT
    imprimirPlanoAlimentar(meuAlim);

    return 0;
}
