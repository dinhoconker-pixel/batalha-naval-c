
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5
#define NAVIOS 3

void inicializar(char tab[TAM][TAM]) {
    for(int i=0;i<TAM;i++)
        for(int j=0;j<TAM;j++)
            tab[i][j] = '~';
}

void mostrar(char tab[TAM][TAM]) {
    printf("\n  ");
    for(int i=0;i<TAM;i++) printf("%d ", i);
    printf("\n");
    for(int i=0;i<TAM;i++) {
        printf("%d ", i);
        for(int j=0;j<TAM;j++)
            printf("%c ", tab[i][j]);
        printf("\n");
    }
}

int main() {
    char tab[TAM][TAM];
    int navios = NAVIOS;
    int x, y;

    srand(time(NULL));
    inicializar(tab);

    // Posiciona navios
    for(int i=0;i<NAVIOS;i++) {
        int r = rand() % TAM;
        int c = rand() % TAM;
        if(tab[r][c] == 'N') i--;
        else tab[r][c] = 'N';
    }

    printf("=== JOGO BATALHA NAVAL ===\n");

    while(navios > 0) {
        mostrar(tab);
        printf("Digite linha e coluna: ");
        scanf("%d %d", &x, &y);

        if(x < 0 || x >= TAM || y < 0 || y >= TAM) {
            printf("Posicao invalida!\n");
            continue;
        }

        if(tab[x][y] == 'N') {
            printf("Acertou um navio!\n");
            tab[x][y] = 'X';
            navios--;
        } else if(tab[x][y] == '~') {
            printf("Agua!\n");
            tab[x][y] = 'O';
        } else {
            printf("Posicao ja escolhida!\n");
        }
    }

    printf("\nParabens! Voce afundou todos os navios!\n");
    return 0;
}
