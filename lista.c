//Implementação do TAD

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// Criar lista vazia
Lista* criarLista() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;
    return l;
}

// Inserir no início
void inserirInicio(Lista *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->ant = NULL;
    novo->prox = l->inicio;

    if (l->inicio != NULL)
        l->inicio->ant = novo;
    else
        l->fim = novo; // Lista estava vazia

    l->inicio = novo;
    l->tamanho++;
}

// Inserir no fim
void inserirFim(Lista *l, int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = l->fim;

    if (l->fim != NULL)
        l->fim->prox = novo;
    else
        l->inicio = novo; // lista vazia

    l->fim = novo;
    l->tamanho++;
}

// Remover do início
int removerInicio(Lista *l, int *removido) {
    if (l->inicio == NULL) return 0;

    No *aux = l->inicio;
    *removido = aux->valor;

    l->inicio = aux->prox;
    if (l->inicio != NULL)
        l->inicio->ant = NULL;
    else
        l->fim = NULL;

    free(aux);
    l->tamanho--;
    return 1;
}

// Remover do fim
int removerFim(Lista *l, int *removido) {
    if (l->fim == NULL) return 0;

    No *aux = l->fim;
    *removido = aux->valor;

    l->fim = aux->ant;
    if (l->fim != NULL)
        l->fim->prox = NULL;
    else
        l->inicio = NULL;

    free(aux);
    l->tamanho--;
    return 1;
}

// Buscar por valor
No* buscarPorValor(Lista *l, int valor) {
    No *aux = l->inicio;
    while (aux != NULL) {
        if (aux->valor == valor)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

// Buscar por posição (0 a tamanho-1)
No* buscarPorPosicao(Lista *l, int pos) {
    if (pos < 0 || pos >= l->tamanho) return NULL;

    No *aux = l->inicio;
    int i = 0;
    while (aux != NULL && i < pos) {
        aux = aux->prox;
        i++;
    }
    return aux;
}

// Destruir lista
void destruirLista(Lista *l) {
    No *aux = l->inicio;
    while (aux != NULL) {
        No *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(l);
}

// Apenas para testes
void imprimirLista(Lista *l) {
    No *aux = l->inicio;
    printf("Lista: ");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}
