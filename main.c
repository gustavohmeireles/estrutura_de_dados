//Exemplo de uso

#include <stdio.h>
#include "lista.h"

int main() {
    Lista *l = criarLista();

    inserirInicio(l, 10);
    inserirInicio(l, 20);
    inserirFim(l, 30);
    inserirFim(l, 40);

    imprimirLista(l);

    int removido;
    removerInicio(l, &removido);
    printf("Removido do inicio: %d\n", removido);

    removerFim(l, &removido);
    printf("Removido do fim: %d\n", removido);

    imprimirLista(l);

    No *busca = buscarPorValor(l, 30);
    if (busca) printf("Valor 30 encontrado: %d\n", busca->valor);

    busca = buscarPorPosicao(l, 1);
    if (busca) printf("Elemento na posicao 1: %d\n", busca->valor);

    destruirLista(l);

    return 0;
}
