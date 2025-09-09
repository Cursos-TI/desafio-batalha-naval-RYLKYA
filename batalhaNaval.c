#include <stdio.h>

int main() {
    int tabuleiro[10][10];
    int navio1[3] = {3, 3, 3}; // navio horizontal
    int navio2[3] = {3, 3, 3}; // navio vertical
    int i, j;

    // Inicializar o tabuleiro com água (0)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais dos navios (pode mudar se quiser)
    int linha1 = 2, coluna1 = 4; // navio horizontal
    int linha2 = 6, coluna2 = 7; // navio vertical

    // Posicionar navio1 (horizontal)
    for (j = 0; j < 3; j++) {
        tabuleiro[linha1][coluna1 + j] = navio1[j];
    }

    // Posicionar navio2 (vertical)
    for (i = 0; i < 3; i++) {
        tabuleiro[linha2 + i][coluna2] = navio2[i];
    }

    // Cabeçalho com números
    printf("    ");
    for (j = 1; j <= 10; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    // Exibir o tabuleiro com letras na vertical
    for (i = 0; i < 10; i++) {
        printf(" %c ", 'A' + i); // imprime letra da linha
        for (j = 0; j < 10; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}