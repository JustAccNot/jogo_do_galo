#include <stdio.h>

int tablength;
char jogadores[2] = {'X', 'O'};

void printtabuleiro(char tabuleiro[tablength][tablength]) {
    int i, j;

    for (i = 0; i < tablength; i++) {
        for(j = 0; j < tablength; j++) 
            printf("%c", tabuleiro[i][j]);
        printf("\n");
    }
}

int check_jogadas(char tabuleiro[tablength][tablength]) {
    int i, j, count = 0;

    // Verificar jogadas disponiveis 
    for (i = 0; i < tablength; i++) {
        for(j = 0; j < tablength; j++) 
            if(tabuleiro[i][j] == '.')
                return 0; 
    }

    return 1;

}

int check_vencedor(char tabuleiro[tablength][tablength], int jogador) {
    int i, j, count = 0;

    // Verificar Linha 
    for (i = 0; i < tablength; i++) {
        for(j = 0; j < tablength; j++) 
            if(tabuleiro[i][j] == jogadores[jogador])
                count ++;
        if(count == tablength)
            return 1;
        else
            count = 0;
    }

    count = 0;
    // Verificar Coluna 
    for (i = 0; i < tablength; i++) {
        for(j = 0; j < tablength; j++) 
            if(tabuleiro[j][i] == jogadores[jogador])
                count ++;
        if(count == tablength)
            return 1;
        else
            count = 0;
    }
    
    count = 0;
    // Verificar Diagonais 
    for (i = 0, j = 0; i < tablength; i++, j++)
        if(tabuleiro[i][j] == jogadores[jogador])
            count ++;

    if (count == tablength)
        return 1;

    count = 0;
    for (i = 0, j = tablength - 1; i < tablength; i++, j--)
        if(tabuleiro[i][j] == jogadores[jogador])
            count ++;

    if (count == tablength)
        return 1;

    return 0;
}

int main () {

    int i, j;    
    int l, c;
    int jogador;

    printf("Dimensão tabuleiro: ");
    scanf("%d", &tablength);
    while (getchar() != '\n');
    printf("Primeiro a jogar (1: X || 2: O): ");
    scanf("%d", &jogador);
    jogador--;

    char tabuleiro[tablength][tablength];
    
    for (i = 0; i < tablength; i++)
        for(j = 0; j < tablength; j++)
            tabuleiro[i][j] = '.';


    printtabuleiro(tabuleiro);

    while (1) {
        printf("Jogador %c\n", jogadores[jogador]);
        printf("Linha: ");
        scanf("%d", &l);
        printf("Coluna: ");
        scanf("%d", &c);

        if(l < 1 || l > tablength || c < 1 || c > tablength || tabuleiro[l-1][c-1] == 'X' || tabuleiro[l-1][c-1] == 'O') {
            printf("Coordenada inválida | Já está preenchida\n");
            continue;
        }

        tabuleiro[l-1][c-1] = jogadores[jogador];
        
        printtabuleiro(tabuleiro);

        if(check_vencedor(tabuleiro, jogador) == 1) {
            printf("Ganhou %c\n", jogadores[jogador]);
            break;
        } else if (check_jogadas(tabuleiro) == 1) {
            printf("Empate\n");
            break;
        }

        jogador = !jogador;
    }
}