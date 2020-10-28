/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   navio.h
 * Author: aleff
 *
 * Created on October 7, 2020, 9:10 AM
 */

#ifndef NAVIO_H
#define NAVIO_H
#include "conteiner.h"

#ifdef __cplusplus
extern "C" {
#endif

    /*Struct feita para representar um navio
    o vetor conteiner contem ponteiros que apontam para as pilhas
    onde se encontram os conteineres.*/
    struct navio {
        int id;
        //vetor de ponteiro q aponta pra pilha de struct de conteiner
        Pilha *pi[4];
        int tempoDeEspera;
        int qtdConteiner;
    };

    typedef struct fila Fila;

    struct fila {
        struct elemento2 *inicio;
        struct elemento2 * final;
    };

    struct elemento2 {
        struct navio navios;
        struct elemento2 *prox;
    };

    typedef struct elemento2 Elem2;

    Fila* criaFila();

    int insereFila(Fila* fi, struct navio nav);

    int retiraFila(Fila* fi);

    int tamanhoFila(Fila* fi);

    //incrementa em 1 o atributo de navio tempoDeEspera
    //Struct elemento representa uma posicao da fila, atraves dela e possivel 
    //acessar o proximo elemento da fila, assim essa funcao tem carater recursivo
    //enquanto o id do barco na struct elemento for diferente do int cod passado
    //a funcao incrementara o atributo e sera chamada novamente passando como 
    //referencia o proximo elemento da fila, o int cod tem q ser o id do codigo do 
    //ultimo navio da fila, atribuido pelo fila.final.
    void incrementaTempoNavios(struct elemento2* elem2, int cod);

    void listarNavios(Fila *fi, int tam);

#ifdef __cplusplus
}
#endif

#endif /* NAVIO_H */

