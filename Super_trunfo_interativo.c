#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta do Super Trunfo
typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;

// Função para calcular a densidade demográfica
double calcular_densidade(int populacao, float area) {
    if (area == 0) return 0;
    return populacao / area;
}

// Função para exibir o menu e retornar a escolha do usuário
int exibir_menu() {
    int opcao;
    printf("\n=== SUPER TRUNFO - MENU DE COMPARACAO ===\n");
    printf("1. Populacao\n");
    printf("2. Area\n");
    printf("3. PIB\n");
    printf("4. Pontos Turisticos\n");
    printf("5. Densidade Demografica\n");
    printf("Escolha o atributo para comparar (1-5): ");
    scanf("%d", &opcao);
    return opcao;
}

// Função para comparar os atributos e exibir o resultado
void comparar_cartas(Carta c1, Carta c2, int atributo) {
    printf("\nComparando: %s x %s\n", c1.nome, c2.nome);
    switch (atributo) {
        case 1: // Populacao
            printf("Populacao: %d x %d\n", c1.populacao, c2.populacao);
            if (c1.populacao > c2.populacao) {
                printf("%s venceu!\n", c1.nome);
            } else if (c1.populacao < c2.populacao) {
                printf("%s venceu!\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2: // Area
            printf("Area: %.2f x %.2f\n", c1.area, c2.area);
            if (c1.area > c2.area) {
                printf("%s venceu!\n", c1.nome);
            } else if (c1.area < c2.area) {
                printf("%s venceu!\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3: // PIB
            printf("PIB: %.2f x %.2f\n", c1.pib, c2.pib);
            if (c1.pib > c2.pib) {
                printf("%s venceu!\n", c1.nome);
            } else if (c1.pib < c2.pib) {
                printf("%s venceu!\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 4: // Pontos Turisticos
            printf("Pontos Turisticos: %d x %d\n", c1.pontos_turisticos, c2.pontos_turisticos);
            if (c1.pontos_turisticos > c2.pontos_turisticos) {
                printf("%s venceu!\n", c1.nome);
            } else if (c1.pontos_turisticos < c2.pontos_turisticos) {
                printf("%s venceu!\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 5: // Densidade Demografica (menor vence)
            printf("Densidade Demografica: %.2f x %.2f\n", c1.densidade_demografica, c2.densidade_demografica);
            if (c1.densidade_demografica < c2.densidade_demografica) {
                printf("%s venceu!\n", c1.nome);
            } else if (c1.densidade_demografica > c2.densidade_demografica) {
                printf("%s venceu!\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Opcao invalida!\n");
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 214000000, 8515767.0, 1868000000000.0, 15, 0};
    Carta carta2 = {"Argentina", 45380000, 2780400.0, 487200000000.0, 8, 0};

    // Calcular densidade demográfica
    carta1.densidade_demografica = calcular_densidade(carta1.populacao, carta1.area);
    carta2.densidade_demografica = calcular_densidade(carta2.populacao, carta2.area);

    int opcao = exibir_menu();
    comparar_cartas(carta1, carta2, opcao);

    return 0;
}