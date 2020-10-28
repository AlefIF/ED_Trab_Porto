/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   filaAtracamento.h
 * Author: aleff
 *
 * Created on October 15, 2020, 11:53 AM
 */

#ifndef FILAATRACAMENTO_H
#define FILAATRACAMENTO_H
#include "navio.h"
#ifdef __cplusplus
extern "C" {
#endif

    struct atracadouro {
        int id;
        //variavel q controla o carro que dessempilha travessas
        int carro;
        //variavel q conta quantas vezes o carro foi usado
        int qtdViagem;
        //variavel q indica qual pilha esta desempilhando
        int pilhaDesempilhando;
        //vetor de ponteiro q aponta pra pilha de struct de conteiner
        Pilha *pi[5];
        //Ponteiro de fila de navios
        Fila *fi;
    };



#ifdef __cplusplus
}
#endif

#endif /* FILAATRACAMENTO_H */

