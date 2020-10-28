#include <stdio.h>
#include <stdlib.h>
#include "conteiner.h"

//Pilha de conteiner

Pilha* criaPilha() {
    Pilha* pi = (Pilha*) malloc(sizeof (Pilha));
    if (pi != NULL) {
        pi->topo = NULL;
    }
    return pi;
}

int insereConteiner(Pilha* pi, struct conteiner ct) {
    if (pi == NULL) return 0;
    Elem* no = (Elem*) malloc(sizeof (Elem));
    if (no == NULL) return 0;
    no->dados = ct;
    no->prox = pi->topo;
    pi->topo = no;
    return 1;
}

int retiraConteiner(Pilha* pi) {
    if (pi == NULL)return 0;
    if (pi->topo == NULL) return 0;
    Elem *no = pi->topo;
    pi->topo = no->prox;
    int conteinerCod = no->dados.id;
    free(no);
    return conteinerCod;
}

int tamanhoPilha(Pilha* pi) {
    if (pi == NULL) return 0;
    int cont = 0;
    Elem* no = pi->topo;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}



