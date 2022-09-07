//Crie um tipo estruturado para armazenar dados de um ingresso. Uma estrutura deste tipo possui os
//seguintes campos: preço, local e atração. 

#include <stdio.h>//Declarando bibliotecas
#include <stdlib.h>

typedef struct ingresso {//Declarando e renomeando a estrutura

    float preco;//Declarando as variáveis
    char local[100];
    char atracao[100];

}ingresso;//Novo nome da estrutura

//a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e
//preencha seus campos com valores fornecidos pelo usuário via teclado. Protótipo: void
//preenche(Ingresso* i);

void preenche(ingresso *i){//Primeira função onde pede para preencher as variáveis

    printf("Informe a atracao:\n");//Pdedindo o nome da atração
    scanf("%[^\n]", &i->atracao);//Lendo e armazenando na variável atração

    printf("Informe o local:\n");//Pdedindo o nome do local
    scanf("%[^\n]", &i->local);//Lendo e armazenando na variável local

    printf("Informe o preco do ingresso:\n");//Pedindo o valor do ingresso
    scanf("%f", &i->preco);//Lendo e armazenando na variável preço 

    system("cls");//Limpando as informações anteriores
}

//b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e imprima
//os valores dos seus campos. Protótipo: void imprime(Ingresso* i);

void imprime(ingresso *i){//Segunda função onde imprime as informações anteriores

    printf("Atracao: %s\nLocal: %s\nPreco: %.2f\n", i->atracao, i->local, i->preco);//Imprimindo as informações guardadas na função anterior

    system("cls");//Apaando logo em seguidda
}

//c) Escreva uma função que receba, como parâmetros, o endereço de uma estrutura do tipo Ingresso e um
//novo valor de preço e atualize o preço do ingresso para o novo valor. Protótipo: void
//altera_preco(Ingresso* i, float valor);

void altera_peco(ingresso* i, float valor){//Terceira função onde vai fazer a alteração do preço

    printf("Informe um novo valor para o preco: \n");//Pedindo um novo valor para o preço
    scanf("%f", &valor);//Lendo e armazenando do novo valor

    i->preco = valor;//Fazendo a alteração na variável preço

    system("cls");//Apagando logo em seguida
}


//d) Escreva uma função que receba, como parâmetros, um vetor de ingressos e o tamanho do vetor e
//imprima os eventos de ingresso mais barato e mais caro. Protótipo: void imprime_menor_maior_preco(int
//n, Ingresso* vet);

void imprime_menor_maior_preco(int n, ingresso* vet){//Quarta função onde vai saber o maior e o mendor preço
    
    ingresso *mais_barato, *mais_caro, valor;//Declarando as variáveis
    int i;

    printf("Informe um tamanho para o vetor:\n");//Pedindo o tamanho do vetor
    scanf("%i", &n);

    system("cls");//Apagando informações anteriores

    vet = (ingresso*) malloc (n * sizeof (ingresso));//Libreando espaço na memória

    mais_barato = vet;//Mais barato vai receber o vetor
    mais_caro = vet;//Mais caro vai receber o vetor

    for(i=0; i<n; i++){//Laço para saber o mais barato
        if(mais_barato > vet+i){//Se mais barato for maior que o vetor 
            mais_barato = vet +i;//Mais barato vai receber o vetor
            printf("Mais barato : %.2f\n", mais_barato);//Mostrando o mais barato
        }
        else(mais_caro < vet + i);{//se não
            mais_caro = vet+i;//Mais caro vai receber o vetor
            printf("Mais caro : %.2f", mais_caro);
        }
    }

    free(vet);//Liberando o vetor

}

//e) Escreva uma função main para testar as funções anteriores.

int main(){//Função principal

    ingresso *i, *vet;//Declarando variáveis
    float valor;
    int n;

    preenche(&i);//Chamando as funções anteriores
    imprime(&i);
    altera_peco(&i, valor);
    imprime_menor_maior_preco(n, &vet);

    return 0;
}
