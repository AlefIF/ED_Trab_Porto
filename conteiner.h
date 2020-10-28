/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   conteiner.h
 * Author: aleff
 *
 * Created on October 10, 2020, 9:02 AM
 */

#ifndef CONTEINER_H
#define CONTEINER_H

#ifdef __cplusplus
extern "C" {
#endif

    //Struct que representa um conteiner
    struct conteiner {
        int id;
    };

    ///////////////////////////////////////////////////////////////////////////
    //Funcoes da pilha de conteiners no navio
    ///////////////////////////////////////////////////////////////////////////

    struct elemento {
        struct conteiner dados;
        struct elemento *prox;
    } elemento;
    typedef struct elemento Elem;

    //Pilha que representa a pilha de conteineres nas travesas

    typedef struct Pilha {
        struct elemento *topo;
    } Pilha;

    //Metodo que aloca uma posicao de memoria do tamanho da struct conteiner
    //Serve para inicializar a pilha
    Pilha* criaPilha();

    //Metodo que insere um conteiner no topo da pilha
    int insereConteiner(Pilha* pi, struct conteiner ct);

    //Metodo que retira um conteiner da pilha de conteineres e retorna
    //o codigo do conteiner retirado
    int retiraConteiner(Pilha* pi);

    //Verifica se a  pilha esta cheia(conferir argumentos, max 5 navios)
    int tamanhoPilha(Pilha* pi);


#ifdef __cplusplus
}
#endif

#endif /* CONTEINER_H */

