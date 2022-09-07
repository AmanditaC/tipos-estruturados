//Defina estruturas para representar retângulos (dadas a base e a altura) e círculos (dado o raio), e
//implemente as funções a seguir:

//a) Dado um círculo, crie e retorne o maior retângulo circunscrito de altura h. Considere que h é menor do
//que o diâmetro do círculo.
//Protótipo: Ret* ret_circunscrito(Circ* c, float h);

//b) Dado um retângulo, crie e retorne o maior círculo interno ao retângulo.
//Protótipo: Circ* circ_interno(Ret* r);

#include <stdio.h>//Biliotecas
#include <stdlib.h>
#include <math.h>

typedef struct circulo{//Declarando uma estrutura
    float base;
    float altura;
}Circ;//Renomeando a estrutura

typedef struct retangulo{//Declarando uma estrutura
    float raio;
}Ret;//Renomeando a estrutura

Ret* ret_circuscrito(Circ* c, float h);//Protótipo da segunda e terceira função 

Circ* circ_interno(Ret* r);

int main(){//Função principal

    Circ *c = malloc(sizeof(Circ));//Alocando c dinâmicamente

    Ret *r = ret_circunscrito(c, 3);//Alocando r dinâmicamente

    float h;//Declarando variável

    ret_circuscrito(&c, h);//Chamando a segunda e terceira função
    circ_interno(&r);

    r->raio=5;//Atribuindo um valor para o raio

    printf("Base: %f \n", c->base);//Mostrando o resultado da base e altura
    printf("Altura: %f\n", &c->altura);

    free(c);//Liberando a memória da alocação feita anteriormente
    free(r);

    return 0;

}

Ret* ret_circuscrito(Circ* c, float h){//Função secundária


    Ret* r = malloc(sizeof(Ret));//Alocando r dinâmicamente

    c->base = 2 * sqrt(pow(r->raio, 2) - pow(h, 2));//Equação para o retângulo circuscrito

    c->altura = h;//Atribuindo o valor de h a altura
}

Circ* circ_interno(Ret* r){//Terceira função

    Circ* c = malloc (sizeof(Circ));//Alocando c dinâmicamente

    r->raio = sqrt(pow(c->base, 2) + pow(c->altura, 2)) / 2;//Equação para o circulo inteiro

    return c;//Retornando c
}