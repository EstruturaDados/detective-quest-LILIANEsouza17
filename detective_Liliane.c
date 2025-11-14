#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Detective Quest -  Mapa da mansão usando Arvore Binaria

//estrutura de uma sala(nó da arvore)
typedef struct Sala {
    char nome[50];
    struct Sala *esq; // caminho para a esquerda
    struct Sala *dir; // caminho para a direita

} Sala;

//Funçao criarSala - criar dinamicamente um nó (sala) da arvore
Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    if (nova == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esq = NULL;
    nova->dir = NULL;
    return nova;
}

// função explorarSalas() - jogador navega pela arvore da mansao 'e' = esquerda, 'd' = direita, 's' = sair

void explorarSalas(Sala *raiz) {
    Sala *atual = raiz;
    char opcao;
    printf("\n===EXPLORANDO A MANSÃO!===\n");

    while(atual != NULL) {
        printf("\nVocê está em: **%s**\n", atual->nome);
        //se for nó folha não há caminho
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Você chegou a um cômodo sem saídas. Exploração encerrada!\n");
            return;

        }
        printf("Escolha seu caminho:\n");
        if (atual->esq != NULL)
        printf(" (e) Ir para a esquerda → %s\n", atual->esq->nome);
        if (atual->dir != NULL)
        printf(" (d) Ir para a direita → %s\n", atual->dir->nome);
        printf(" (s) Sair da investigação\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' || opcao == 'E') {
            if (atual->esq != NULL)
               atual = atual->esq;
               else
                   printf("\nNão existe sala á esquerda!\n");

        }else if (opcao =='d' || opcao == 'D') {
            if (atual->dir != NULL)
                atual = atual->dir;
                else
                  printf("\nNão existe sala á direita!\n");

        }else if (opcao == 's' || opcao == 'S') {
            printf("\nExploração encerrada pelo jogador.\n");
            return;
        } else {
            printf("Opção inválida!\n");
        }
    }
}
//funçao principal - monta a mansão manualmente e inicia exploração

int main() {
    printf("\n====DETECTIVE QUEST - MAPA DA MANSÃO===\n");

    //criando cômodos (nós)

    Sala *hall      = criarSala("HALL DE ENTRADA");
    Sala *salaEstar = criarSala("SALA DE ESTAR");
    Sala *biblioteca = criarSala("BIBLIOTECA");
    Sala *cozinha    = criarSala("COZINHA");
    Sala *jardim     = criarSala("JARDIM");
    Sala *porao      = criarSala("PORÃO");

    // MONTANDO O MAPA DA MANSÃO(ARVORE BINARIA FIXA)
    //                HALL
    //        /                      /
    //    SALA ESTAR                BIBLIOTECA
    //      /      /                  /      /
    //   COZINHA   JARDIM          PORÃO     NULL

    hall->esq = salaEstar;
    hall->dir = biblioteca;

    salaEstar->esq = cozinha;
    salaEstar->dir = jardim;

    biblioteca->esq = porao;

    //inicia a exploracao
    explorarSalas(hall);

    return 0;

}