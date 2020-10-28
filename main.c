/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: aleff
 *
 * Created on October 7, 2020, 9:09 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "atracadouro.h"

/*
 * Declarando as funcoes que serao usadas 
 */
//funcao principal do programa a qual chamara as outras funcoes que gastam
//uma unidade de tempo, incrementara o tempo em seu fim
void passaTempo(int *tempoPassado, int *navioCod, int *conteinerCod, struct atracadouro *atc[]);

//funcao que gera de 0 a 3 navios e 4 a 16 conteineres por navio e empilha eles
//nas respectivias pilhas de cada um, retorna o numero de navios gerados
int geraNavioConteiner(int *navioCod, int *conteinerCod, struct atracadouro *atc[]);

//Recebe os navios da funcao geraNavioConteiner e os enfilera nas filas dos 4
//atracadouros
void enfileiraNavio(struct navio nav, struct atracadouro *atc[]);

//funcao que desempilha um conteiner dos primeiros navios
//de cada uma das 4 filas
void desempilhaConteiner(struct atracadouro *atc[]);

//funcao que verifica se o primeiro navio da fila esta vazio, caso sim
//desemfileira ele
void desenfileiraNavios(struct atracadouro *atc[]);

//funcao para printar a quantidade de navios gerados
void mostraResultado(struct atracadouro * atc[], int qtdNavGerados, int tempoPassado);

//funcao para causar delay na programacao caso o usuario escolha passar um tempo
//maior que 1 no programa de uma vez soh, funcao necessaria para que a geracao
//aleatoria de navios e conteineres nao seja a mesma nos calculos
void delay();

int main(int argc, char** argv) {
    //Criando os atracadouros
    struct atracadouro atc1;
    struct atracadouro atc2;
    struct atracadouro atc3;
    struct atracadouro atc4;

    //setando o atributo pilhaDesempilhando para -1, para nao referenciar 
    //uma pilha por acidente em tempo de execussao
    atc1.pilhaDesempilhando = -1;
    atc2.pilhaDesempilhando = -1;
    atc3.pilhaDesempilhando = -1;
    atc4.pilhaDesempilhando = -1;

    //setando o atributo para 0, para poder ser usado
    atc1.carro = 0;
    atc2.carro = 0;
    atc3.carro = 0;
    atc4.carro = 0;

    //setando o atributo qtdViagem para 0
    atc1.qtdViagem = 0;
    atc2.qtdViagem = 0;
    atc3.qtdViagem = 0;
    atc4.qtdViagem = 0;

    //Inicializando filas
    atc1.fi = criaFila();
    atc2.fi = criaFila();
    atc3.fi = criaFila();
    atc4.fi = criaFila();

    //Inicializando pilhas Do atracadouro 1
    atc1.pi[0] = criaPilha();
    atc1.pi[1] = criaPilha();
    atc1.pi[2] = criaPilha();
    atc1.pi[3] = criaPilha();
    atc1.pi[4] = criaPilha();

    //Inicializando pilhas Do atracadouro 2
    atc2.pi[0] = criaPilha();
    atc2.pi[1] = criaPilha();
    atc2.pi[2] = criaPilha();
    atc2.pi[3] = criaPilha();
    atc2.pi[4] = criaPilha();

    //Inicializando pilhas Do atracadouro 3
    atc3.pi[0] = criaPilha();
    atc3.pi[1] = criaPilha();
    atc3.pi[2] = criaPilha();
    atc3.pi[3] = criaPilha();
    atc3.pi[4] = criaPilha();

    //Inicializando pilhas Do atracadouro 4
    atc4.pi[0] = criaPilha();
    atc4.pi[1] = criaPilha();
    atc4.pi[2] = criaPilha();
    atc4.pi[3] = criaPilha();
    atc4.pi[4] = criaPilha();

    //variavel q servira como autoincremento para o id de conteiners
    int conteinerCod = 1;
    //variavel q servira como autoincremento para o id de navios
    int navioCod = 1;
    //variavel q servira como autoincremento para o tempo que passou desde
    //o inicio do programa
    int tempoPassado = 0;

    //criando um vetor de ponteiro atracadouro para referencia-los nas demais 
    //funcoes do programa
    struct atracadouro * atc[4];
    atc[0] = &atc1;
    atc[1] = &atc2;
    atc[2] = &atc3;
    atc[3] = &atc4;

    //Menu do programa
    int input = -1;
    while (input != 0) {
        printf("Digite de 1 a 100 para avancar o tempo ou 0 para parar o programa \n");
        scanf("%d", &input);
        if (input == 1) {
            passaTempo(&tempoPassado, &navioCod, &conteinerCod, atc);
        } else if (input > 1 && input <= 100) {
            for (int i = 0; i < input; i++) {
                passaTempo(&tempoPassado, &navioCod, &conteinerCod, atc);
                delay();
            }
        } else if (input == 0) {
            printf("Programa finalizado");
        } else {
            printf("Entrada invalida\n");
        }
    }
    return (EXIT_SUCCESS);
}

void mostraResultado(struct atracadouro * atc[], int qtdNavGerados, int tempoPassado) {
    printf("///////////////////////////////// RELATORIO /////////////////////////////////");
    printf("\nTempo passado desde o inicio do programa: %d", tempoPassado);
    printf("\nNumero de Navios que chegaram nesse momento: %d", qtdNavGerados);

    int tamFila = 0, qtdCont = 0, pilhaDesem = 0;
    //trocar pra 4 ou pra observar a fila
    for (int i = 0; i < 4; i++) {
        printf("\n============================ ATRACADOURO %d ============================", i + 1);
        printf("\n=============== FILA ===============");
        tamFila = tamanhoFila(atc[i]->fi);
        printf("\nNumero de navios na fila: %d", tamFila);
        if (tamFila > 0) {
            listarNavios(atc[i]->fi, tamanhoFila(atc[i]->fi));
        }
        printf("\n============= TRAVESSAS =============");
        //trocar pra 5 ou 2 para observar o carro 
        for (int j = 0; j < 5; j++) {
            printf("\n==============================");
            printf("\nTravessa numero: %d", j + 1);
            qtdCont = tamanhoPilha(atc[i]->pi[j]);
            printf("\nQuantidades de conteineres: %d", qtdCont);
            if (qtdCont > 0) {
                if(qtdCont==5){
                    printf("\nStatus: Cheia");
                }else{
                    printf("\nStatus: Empilhando");
                }      
            } else if (atc[i]->pilhaDesempilhando == j) {
                printf("\nStatus: Desempilhando");
                pilhaDesem = j + 1;
            } else {
                printf("\nStatus: Disponivel");
            }
            printf("\n==============================");
        }
        printf("\n=========== Straddle Carrier ===========");
        if (atc[i]->pilhaDesempilhando >= 0) {
            printf("\nStatus: Desempilhando a Travessa %d", pilhaDesem);
        } else {
            printf("\nStatus: Inativo");
        }
        printf("\nQuantidade de viagens: %d", atc[i]->qtdViagem);
    }

    printf("\n//////////////////////////// FIM RELATORIO ////////////////////////////");

    printf("\n");

}

int geraNavioConteiner(int *navioCod, int *conteinerCod, struct atracadouro * atc[]) {
    // seed for random generator 
    srand(time(NULL));

    //variaveis auxiliares para numeros aleatorios de navios
    int lower = 0, upper = 3, count = 1;
    //Numero aleatorio auxiliar para definir a quantidade de navios
    int randonNumberNav = (rand() % (upper - lower + 1)) + lower;
    //Numero aleatorio auxiliar para definir a quantidade de conteineres de 
    //um navio, varia de 4 a 16
    int randonNumberConteiner = 0;
    // printf("Numero de navios gerados %d \n", randonNumberNav);
    for (int i = 0; i < randonNumberNav; i++) {
        //Criando um navio
        struct navio n;
        n.id = (*navioCod);
        //incrementando o Codigo do navio
        (*navioCod)++;
        n.tempoDeEspera = 0;

        //variaveis auxiliares para numeros aleatorios do conteiner
        lower = 4, upper = 16, count = 1;
        //gerando o numero de conteineres do navio i
        randonNumberConteiner = (rand() % (upper - lower + 1)) + lower;

        //Struct Auxiliar 
        struct conteiner ct;
        //recebe o valor da quantidade de conteineres do navio
        n.qtdConteiner = randonNumberConteiner;

        n.pi[0] = criaPilha();
        n.pi[1] = criaPilha();
        n.pi[2] = criaPilha();
        n.pi[3] = criaPilha();

        // printf("Numero de conteineres no navio %d : %d \n", n.id, randonNumberConteiner);

        //Empilhando os conteineres nas 4 pilhas do navio
        for (int j = 0; j < randonNumberConteiner; j++) {
            ct.id = (*conteinerCod);
            if (j < 4) {
                insereConteiner(n.pi[0], ct);
            } else if (j >= 4 && j < 8) {
                insereConteiner(n.pi[1], ct);
            } else if (j >= 8 && j < 12) {
                insereConteiner(n.pi[2], ct);
            } else if (j >= 12 && j < 16) {
                insereConteiner(n.pi[3], ct);
            }
            (*conteinerCod)++;
        }
        enfileiraNavio(n, atc);
    }
    return randonNumberNav;
}

void enfileiraNavio(struct navio nav, struct atracadouro * atc[]) {
    //inserindo o navio gerado na fila do atracadouro que possui
    //menos navios enfileirados
    //poxa, acho q dava pra ter feito dentro de um for e guardado a menor fila
    //e dpois inserir :/
    if (tamanhoFila(atc[0]->fi) == 0) {
        insereFila(atc[0]->fi, nav);
    } else if (tamanhoFila(atc[1]->fi) == 0) {
        insereFila(atc[1]->fi, nav);
    } else if (tamanhoFila(atc[2]->fi) == 0) {
        insereFila(atc[2]->fi, nav);
    } else if (tamanhoFila(atc[3]->fi) == 0) {
        insereFila(atc[3]->fi, nav);
    } else if (tamanhoFila(atc[0]->fi) <= tamanhoFila(atc[1]->fi)) {
        if (tamanhoFila(atc[0]->fi) <= tamanhoFila(atc[2]->fi)) {
            if (tamanhoFila(atc[0]->fi) <= tamanhoFila(atc[3]->fi)) {
                insereFila(atc[0]->fi, nav);
            } else {
                insereFila(atc[3]->fi, nav);
            }
        } else if (tamanhoFila(atc[2]->fi) <= tamanhoFila(atc[3]->fi)) {
            insereFila(atc[2]->fi, nav);
        } else {
            insereFila(atc[3]->fi, nav);
        }
    } else if (tamanhoFila(atc[1]->fi) <= tamanhoFila(atc[2]->fi)) {
        if (tamanhoFila(atc[1]->fi) <= tamanhoFila(atc[3]->fi)) {
            insereFila(atc[1]->fi, nav);
        } else {
            insereFila(atc[3]->fi, nav);
        }
    } else if (tamanhoFila(atc[2]->fi) <= tamanhoFila(atc[3]->fi)) {
        insereFila(atc[2]->fi, nav);
    } else {
        insereFila(atc[3]->fi, nav);
    }
}

void desempilhaConteiner(struct atracadouro * atc[]) {
    //aux pra guardar a posicao da primeira prilha com menos de 5 conteineres
    //tam guarda o tamnho da pilha do navio
    int aux = -1, tam = 0;
    //laco que passa por todos atracadouros, por todas as travesas de cada um
    //e por todas as pilhas do primeiro navio de cada atracadouro
    //caso encontre uma travessa valida para empilhar para o laco, caso encontre
    //uma pilha no navio valida para desempilhar, realizada a passagem do 
    //conteiner, do navio para a travessa.
    for (int i = 0; i < 4; i++) {
        //verificar tam da fila
        if (tamanhoFila(atc[i]->fi) > 0) {
            for (int j = 0; j < 5; j++) {
                if (tamanhoPilha(atc[i]->pi[j]) < 5) {
                    if (j != atc[i]->pilhaDesempilhando) {
                        aux = j;
                        break;
                    }
                }
            }
            for (int k = 0; k < 4; k++) {
                //verificando se existe conteiner na pilha do navio
                tam = tamanhoPilha(atc[i]->fi->inicio->navios.pi[k]);
                //Verificando se existe uma pilha valida para empilhar
                if (tam > 0 && aux >= 0) {
                    insereConteiner(atc[i]->pi[aux], atc[i]->fi->inicio->navios.pi[k]->topo->dados);
                    retiraConteiner(atc[i]->fi->inicio->navios.pi[k]);
                    atc[i]->fi->inicio->navios.qtdConteiner--;
                    break;
                }

            }

        }
        //setando aux para -1 denovo
        aux = -1;
    }
    //Depois que cada grua ja empilhou um conteiner em seu respectivo 
    //atracadouro verifica se alguma travessa esta cheia, se sim, sera 
    //desempilhada.
    for (int i = 0; i < 4; i++) {
        //verificando se o carro esta disponivel
        if (atc[i]->carro == 0) {
            for (int j = 0; j < 5; j++) {
                //verificando se alguma travessa esta cheia
                if (tamanhoPilha(atc[i]->pi[j]) == 5) {
                    //printf("\nCarro retirando uma travessa\n");
                    //desempilhando a travessa
                    for (int k = 0; k < 5; k++) {
                        retiraConteiner(atc[i]->pi[j]);
                    }
                    //Guardando o valor da pilha que esta sendo desempilhada
                    atc[i]->pilhaDesempilhando = j;
                    //Setando o valor do carro como -2 para ele nao ser usado 
                    //por 2 tiks de tempo
                    atc[i]->carro = -2;
                    //somando +1 na quantidade de viagens feitas pelo carro
                    atc[i]->qtdViagem++;
                    break;
                }
            }
        } else {
            //se o carro n esta disponivel soma 1 em seu atributo, representa 
            //a passagem de um tik de tempo
            atc[i]->carro = atc[i]->carro + 1;
            //Caso o carro voltou nesse tempo, seta o pilhaDesempilhando para
            //-1 para liberar o uso da travessa
            if (atc[i]->carro == 0) {
                atc[i]->pilhaDesempilhando = -1;
            }
        }
    }

}

void desenfileiraNavios(struct atracadouro * atc[]) {
    //variavel auxiliar para saber se todas as pilhass do navio estao vazias
    //caso tenha valor 4 o navio sera desenfileirado
    int contaPilha = 0;
    for (int i = 0; i < 4; i++) {
        if (tamanhoFila(atc[i]->fi) > 0) {
            for (int j = 0; j < 4; j++) {
                if (tamanhoPilha(atc[i]->fi->inicio->navios.pi[j]) == 0) {
                    contaPilha++;
                }
            }
            if (contaPilha == 4) {
                //printf("\nChegou no retira Fila\n");
                retiraFila(atc[i]->fi);
            }
            contaPilha = 0;
            //neste ponto a fila do atracadouro i ja teve o navio vazio retirado
            //caso houvesse algum, sendo assim, todos os demais navio passarao pelo
            //menos mais um tik de tempo na fila, entao chama-se a funcao 
            //incrementaTempoNavios
            if (tamanhoFila(atc[i]->fi) > 0) {
                incrementaTempoNavios(atc[i]->fi->inicio, atc[i]->fi->final->navios.id);
            }
        }
    }
}

void passaTempo(int *tempoPassado, int *navioCod, int *conteinerCod, struct atracadouro * atc[]) {
    int qtdNav = 0;
    //Gerando navios
    //limitando o numero de navios por fila em 5, 
    //para nao ocorrer engarrafamento
    if (tamanhoFila(atc[0]->fi) <= 5 && tamanhoFila(atc[1]->fi) <= 5
            && tamanhoFila(atc[2]->fi) <= 5 && tamanhoFila(atc[3]->fi) <= 5) {
        qtdNav = geraNavioConteiner(navioCod, conteinerCod, atc);
    } else {
        printf("Numero de navios muito grande, nenhum navio foi gerado no tempo %d \n\n", *tempoPassado);
    }

    //Desempilhando conteineres
    desempilhaConteiner(atc);

    //verificando se algum navio esta vazio e defenfileira-o
    desenfileiraNavios(atc);

    //incrementando o tempo global
    (*tempoPassado)++;

    mostraResultado(atc, qtdNav, *tempoPassado);
}

void delay() {
    srand(time(NULL));

    //variaveis auxiliares para numeros aleatorios de navios
    int lower = 100, upper = 300, count = 30;
    //Numero aleatorio auxiliar para definir a quantidade de navios
    int randonDelay = (rand() % (upper - lower + 1)) + lower;

    // Converting time into milli_seconds 
    int milli_seconds = randonDelay;

    // Storing start time 
    clock_t start_time = clock();

    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds)
        ;
} 