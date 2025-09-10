#include <stdio.h>

#define TAM 10
#define H 5   // tamanho da matriz de habilidade

// Função para inicializar o tabuleiro com 0
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("   ");
    for (int j = 0; j < TAM; j++) {
        printf("%2d ", j+1);
    }
    printf("\n");

    for (int i = 0; i < TAM; i++) {
        printf("%2c ", 'A' + i); 
        for (int j = 0; j < TAM; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Posiciona manualmente alguns navios
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio horizontal (linha 2, col 2 até col 4)
    for (int j = 2; j < 5; j++) {
        tabuleiro[2][j] = 3;
    }
    // Navio vertical (linha 5 até 7, col 7)
    for (int i = 5; i < 8; i++) {
        tabuleiro[i][7] = 3;
    }
    // Navio diagonal principal (3 células)
    for (int d = 0; d < 3; d++) {
        tabuleiro[6+d][1+d] = 3;
    }
    // Navio diagonal secundária (3 células)
    for (int d = 0; d < 3; d++) {
        tabuleiro[1+d][8-d] = 3;
    }
}

// Gera matriz de cone 5x5
void gerarCone(int matriz[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            matriz[i][j] = 0;
            if (j >= H/2 - i && j <= H/2 + i && i < H) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Gera matriz de cruz 5x5
void gerarCruz(int matriz[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (i == H/2 || j == H/2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera matriz de octaedro (losango) 5x5
void gerarOctaedro(int matriz[H][H]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (abs(i - H/2) + abs(j - H/2) <= H/2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Sobrepõe matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[H][H], int origemLinha, int origemColuna) {
    int offset = H / 2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (habilidade[i][j] == 1) {
                int linha = origemLinha + (i - offset);
                int coluna = origemColuna + (j - offset);

                if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                    if (tabuleiro[linha][coluna] == 0) {
                        tabuleiro[linha][coluna] = 5; // marca área de efeito
                    }
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[H][H], cruz[H][H], octaedro[H][H];

    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);

    // Gerar habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicar habilidades em pontos específicos
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 8, 8);

    // Exibir tabuleiro final
    exibirTabuleiro(tabuleiro);

    return 0;
}