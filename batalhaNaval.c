#include <stdio.h>

// Definicoes de constantes para o tabuleiro
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int linha, coluna, k;

    // --- 1. Inicialização do Tabuleiro (Água = 0) ---
    // Usa loops aninhados para percorrer a matriz e preencher todas as posições com 0.
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = VALOR_AGUA;
        }
    }
    
    // --- 2. Coordenadas Iniciais dos Navios (Definidas no código) ---
    
    // Navio 1: Horizontal (Tamanho 3)
    int navio1_linha = 1; 
    int navio1_coluna = 1; 
    int navio1_valido = 1; // Flag para indicar se o navio pode ser posicionado

    // Navio 2: Vertical (Tamanho 3)
    int navio2_linha = 5; 
    int navio2_coluna = 3; 
    int navio2_valido = 1; // Flag para indicar se o navio pode ser posicionado

    // -------------------------------------------------------------------
    // --- 3. Posicionamento e Validação do Navio 1 (Horizontal) ---
    
    // Validação de Limites: Verifica se o navio ultrapassa a borda direita.
    if (navio1_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("ERRO: Navio 1 (Horizontal) fora dos limites do tabuleiro!\n");
        navio1_valido = 0;
    }

    // Posicionamento (se for válido)
    if (navio1_valido) {
        // Como este é o primeiro navio, a sobreposição so precisa checar
        // se a area esta preenchida com AGUA (VALOR_AGUA), o que e garantido
        // pela inicializacao do tabuleiro.
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            tabuleiro[navio1_linha][navio1_coluna + k] = VALOR_NAVIO;
        }
    }

    // -------------------------------------------------------------------
    // --- 4. Posicionamento e Validação do Navio 2 (Vertical) ---
    
    // Validação de Limites: Verifica se o navio ultrapassa a borda inferior.
    if (navio2_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("ERRO: Navio 2 (Vertical) fora dos limites do tabuleiro!\n");
        navio2_valido = 0;
    }

    // Validação de Sobreposição (Simplificada):
    if (navio2_valido) {
        // Percorre as posicoes que o Navio 2 ocuparia
        for (k = 0; k < TAMANHO_NAVIO; k++) {
            // Se encontrar o valor de Navio (3) ou qualquer coisa diferente de AGUA (0)
            if (tabuleiro[navio2_linha + k][navio2_coluna] != VALOR_AGUA) {
                printf("ERRO: Navio 2 (Vertical) se sobrepoe a outro navio!\n");
                navio2_valido = 0;
                break; // Interrompe o loop apos encontrar a sobreposicao
            }
        }

        // Posicionamento: Se a posicao for válida e nao houver sobreposição, insere o navio (valor 3)
        if (navio2_valido) {
            for (k = 0; k < TAMANHO_NAVIO; k++) {
                tabuleiro[navio2_linha + k][navio2_coluna] = VALOR_NAVIO;
            }
        }
    }

    // -------------------------------------------------------------------
    // --- 5. Exibição do Tabuleiro ---
    
    printf("\n\n======================================\n");
    printf("--- Tabuleiro de Batalha Naval (10x10) ---\n");
    printf("0 = Agua, 3 = Navio Posicionado\n");
    printf("======================================\n");

    // Imprimir índices de coluna (0 a 9)
    printf("   "); 
    for(coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
        printf(" %d ", coluna);
    }
    printf("\n");
    
    // Imprimir linha separadora
    printf("---");
    for(coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
        printf("---");
    }
    printf("\n");
    
    // Usa loops aninhados para imprimir a matriz
    for (linha = 0; linha < TAMANHO_TABULEIRO; linha++) {
        printf("%d |", linha); // Imprimir índice da linha
        for (coluna = 0; coluna < TAMANHO_TABULEIRO; coluna++) {
            printf(" %d ", tabuleiro[linha][coluna]);
        }
        printf("|\n");
    }

    return 0;
}
