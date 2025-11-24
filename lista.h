//Interface do TAD

#ifndef LISTA_H
#define LISTA_H

// Estrutura do nó
typedef struct No {
    int valor;
    struct No *ant;
    struct No *prox;
} No;

// Estrutura da lista
typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Lista;

// ---- Operações ----
Lista* criarLista();
void destruirLista(Lista *l);

void inserirInicio(Lista *l, int valor);
void inserirFim(Lista *l, int valor);

int removerInicio(Lista *l, int *removido);
int removerFim(Lista *l, int *removido);

No* buscarPorValor(Lista *l, int valor);
No* buscarPorPosicao(Lista *l, int pos);

void imprimirLista(Lista *l);

#endif
