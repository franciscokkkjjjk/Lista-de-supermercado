#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM_MAX_STR 254 

void adicionaItensNaLista(char **lista, int linha, char *string){
        register int i;
        for(i = 0; i < strlen(string); ++i)
            lista[linha][i] = string[i];
}

void inicializar(char **matriz, int linha, int coluna) {
    register int i, j;
    for(i = 0; i < linha; i++)
        for(j = 0; j < coluna; ++j)
            matriz[i][j] = '\0';
}

int main(void) {
    char **listaDeSupermercado, sair, *auxiliar;
    int i, j, quantidadeLista, tamanho;
    do {
        printf("Qunatos itens deseja colocar na lista? ");
        scanf("%i", &tamanho);
        
        listaDeSupermercado = (char**)malloc(sizeof(char*)*tamanho);
        for(i = 0; i < tamanho; ++i) 
            listaDeSupermercado[i] = (char*)malloc(sizeof(char*)*TAM_MAX_STR);
        
        auxiliar = (char*)malloc(sizeof(char)*TAM_MAX_STR);
        
        inicializar(listaDeSupermercado, tamanho, TAM_MAX_STR);

        for(i = 0; i < tamanho; ++i) {
            printf("Qual o %03d item? ", i+1);
            scanf("%s", auxiliar);
            adicionaItensNaLista(listaDeSupermercado, i, auxiliar);
        }

        for(i = 0; i < tamanho; i++){
            for(j = 0; j < strlen(listaDeSupermercado[i]); ++j) 
                printf("%c", listaDeSupermercado[i][j]);
            printf("\n");
        }
        
        printf("Deseja sair do programa (s/n)? ");
        scanf("%*c%c", &sair);
    } while (sair != 'S' && sair != 's');      
    return 0;
}