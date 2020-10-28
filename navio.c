#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "navio.h"

Fila* criaFila() {
    Fila* fi = (Fila*) malloc(sizeof (Fila));
    if (fi != NULL) {
        fi->final = NULL;
        fi->inicio = NULL;
    }
    return fi;
}

int insereFila(Fila* fi, struct navio nav) {
    if (fi == NULL) return 0;
    Elem2 *no = (Elem2*) malloc(sizeof (Elem2));
    if (no == NULL)return 0;
    no->navios = nav;
    no->prox = NULL;
    if (fi->final == NULL)
        fi->inicio = no;
    else
        fi->final->prox = no;
    fi->final = no;
    return 1;
}

int retiraFila(Fila* fi) {
    if (fi == NULL) return 0;
    if (fi->inicio == NULL)
        return 0;
    Elem2 *no = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if (fi->inicio == NULL)
        fi->final = NULL;
    free(no);
    return 1;
}

int tamanhoFila(Fila* fi) {
    if (fi == NULL) return 0;
    int cont = 0;
    Elem2* no = fi->inicio;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

//essa ficou boa hein :)
//funcao recursiva que percorre a fila de navio incrementado a variavel tempo
//enquanto o id do navio for diferente de cod, que eh o id do ultimo elemento da fila
void incrementaTempoNavios(struct elemento2* elem2, int cod) {
    //Incrementando o tempo do navio
    elem2->navios.tempoDeEspera++;
    if (elem2->navios.id != cod) {
        incrementaTempoNavios(elem2->prox, cod);
    }
}

//essa funcao esta teoricamente errada, n devia ter print aki, deveria estar 
//retornando o elemento e printando no main, faltou tempo pra polir :/
void listarNavios(Fila *fi, int tam) {
    int posFila = 1;
    Elem2 *no = fi->inicio;
    int i;
    for (i = 0; i < tam; i++) {
        printf("\n============== NAVIO %d ==============", posFila);
        printf("\nID do navio: %d", no->navios.id);
        printf("\nQuantidade de conteiner: %d", no->navios.qtdConteiner);
        printf("\nTempo esperado ate o momento: %d", no->navios.tempoDeEspera);
        no = no->prox;
        posFila++;
    }
    free(no);
}