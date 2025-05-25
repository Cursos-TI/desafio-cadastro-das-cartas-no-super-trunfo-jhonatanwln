#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char estado;                  
    char codigo[4];              
    char nomeCidade[50];         
    int populacao;              
    float area;                 
    float pib;                  
    int pontosTuristicos;       
} CartaSuperTrunfo;

// Função para substituir vírgula por ponto
void substituirVirgulaPorPonto(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == ',') {
            str[i] = '.';
        }
    }
}

// Função para ler os dados da carta
void lerCarta(CartaSuperTrunfo *carta, int numero) {
    char pibStr[20];

    printf("=== Inserindo dados da Carta %d ===\n", numero);
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", carta->nomeCidade);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB: ");
    scanf("%s", pibStr);
    substituirVirgulaPorPonto(pibStr);
    carta->pib = atof(pibStr);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    printf("\n");
}

// Função para exibir os dados da carta com PIB formatado
void exibirCarta(CartaSuperTrunfo carta, int numero) {
    printf("=== Carta %d ===\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código da Carta: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);

    // Exibir PIB com vírgula como separador decimal
    char pibFormatado[20];
    snprintf(pibFormatado, sizeof(pibFormatado), "%.2f", carta.pib);
    for (int i = 0; pibFormatado[i]; i++) {
        if (pibFormatado[i] == '.') {
            pibFormatado[i] = ',';
            break;
        }
    }
    printf("PIB: %s bilhões de reais\n", pibFormatado);

    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("\n");
}

int main() {
    CartaSuperTrunfo carta1, carta2;

    lerCarta(&carta1, 1);
    lerCarta(&carta2, 2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0;
}
