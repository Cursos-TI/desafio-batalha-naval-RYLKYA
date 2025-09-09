#include <stdio.h>

#define TAM 10
#define NAVIO 3
#define TAM_NAVIO 3

// Inicializar tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Verificar se pode posicionar navio
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int k = 0; k < TAM_NAVIO; k++) {
        int i = linha, j = coluna;
        if (orientacao == 0) j += k;              // horizontal
        else if (orientacao == 1) i += k;         // vertical
        else if (orientacao == 2) { i += k; j += k; }   // diagonal ↘
        else if (orientacao == 3) { i += k; j -= k; }   // diagonal ↙

        if (i < 0 || i >= TAM || j < 0 || j >= TAM) return 0;
        if (tabuleiro[i][j] != 0) return 0;
    }
    return 1;
}

// Posicionar navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int orientacao) {
    for (int k = 0; k < TAM_NAVIO; k++) {
        if (orientacao == 0) tabuleiro[linha][coluna + k] = NAVIO;       // horizontal
        else if (orientacao == 1) tabuleiro[linha + k][coluna] = NAVIO;  // vertical
        else if (orientacao == 2) tabuleiro[linha + k][coluna + k] = NAVIO; // diagonal ↘
        else if (orientacao == 3) tabuleiro[linha + k][coluna - k] = NAVIO; // diagonal ↙
    }
}

// Exibir tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("    ");
    for (int j = 1; j <= TAM; j++) {
        printf("%2d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf(" %c ", 'A' + i);
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    // Coordenadas escolhidas manualmente
    int linha1 = 2, coluna1 = 4; // horizontal
    int linha2 = 6, coluna2 = 7; // vertical
    int linha3 = 0, coluna3 = 0; // diagonal ↘
    int linha4 = 0, coluna4 = 9; // diagonal ↙

    if (podePosicionar(tabuleiro, linha1, coluna1, 0)) posicionarNavio(tabuleiro, linha1, coluna1, 0);
    if (podePosicionar(tabuleiro, linha2, coluna2, 1)) posicionarNavio(tabuleiro, linha2, coluna2, 1);
    if (podePosicionar(tabuleiro, linha3, coluna3, 2)) posicionarNavio(tabuleiro, linha3, coluna3, 2);
    if (podePosicionar(tabuleiro, linha4, coluna4, 3)) posicionarNavio(tabuleiro, linha4, coluna4, 3);

    // Exibir resultado
    exibirTabuleiro(tabuleiro);

    return 0;
}