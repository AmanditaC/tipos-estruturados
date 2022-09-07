//Escreva um programa em C que manipula dados de um conjunto de alunos da disciplina de Estrutura de
//Dados e Programação da UFERSA Pau dos Ferros. Para representar um aluno são necessárias as seguintes
//informações: matrícula (inteiro), nome (80 caracteres), turma (caractere), três notas (reais em um vetor) e uma
//média (real). Seu programa deve levar em consideração que é ofertado um número máximo de vagas para a
//disciplina. Sabendo dessas informações, faça o que se pede nos itens a seguir:

//a) Implemente uma função que recebe os dados de um aluno e o matricula na disciplina, caso haja vaga
//disponível. Protótipo: void matricula(int n,Aluno** alunos);

//b) Implemente uma função que lança as notas e calcula a média dos alunos da disciplina. Protótipo: void
//lanca_notas(int n, Aluno** alunos);

//c) Implemente uma função que imprime os dados de todos os alunos da disciplina. Protótipo: void
//imprime_tudo(int n, Aluno** alunos);

//d) Implemente uma função que imprime os dados de todos os alunos de uma turma. Protótipo: void
//imprime_turma(int n, Aluno** alunos, char turma);

//e) Implemente uma função que imprime os alunos aprovados de uma determinada turma. Para ser
//aprovado, o aluno deve ter média maior que ou igual a 7,0. Protótipo: void imprime_turma_aprovados(int n,
//Aluno**alunos, char turma);
//Sugestões: i) Use um vetor de ponteiros para estrutura; ii) Use uma constante simbólica para representar o número 
//máximo de alunos. Iii) Antes de manipular o vetor de ponteiros, inicialize cada um de seus elementos com NULL 
//(você pode escrever uma função para isso).

//OBS.: Os exercícios apresentados sugerem a implementação de diferentes funções. Sendo assim, o programador
//deve escrever um programa (função main) para testar sua implementação.

#include <stdio.h>//Bibliotecas
#include <stdlib.h>
#include <string.h>

typedef struct alunos{//Declaração da estrutura

    int matricula;//Declarando as variáveis
    char nome[80];
    char turma[80];
    float nota[3];
    float media;
}Alunos;//Renomeando a estrutura

void matricula(int n, Alunos **alunos){//funcao secundaria
    int i=0;        //declarando contador
    
    if(i<n){
        alunos[i]=(Alunos*)malloc(n*sizeof(Alunos));//Armazenando dados informados com malloc
        if(alunos[i] == NULL){//um erro para acessar o endereço
            printf("MEMORIA CHEIA \n");
            exit(1);//encerra o programa
        }
        else {//preencher campos pedidos ao usuario
            printf("Informe sua  matricula: \n");
            scanf("%d", &alunos[i]->matricula);
            printf("Informe a turma: \n");
            scanf("%c", &alunos[i]->turma);
            printf("Informe o nome: \n ");
            scanf("%80[^\n]", &alunos[i]->nome);
            alunos[i]->nota[0]=0;// nota 1 guardada em nota[0]
            alunos[i]->nota[1]=0;// nota 2 guardada em nota[1]
            alunos[i]->nota[2]=0;// nota 3 guardada em nota[2]
            alunos[i]->media=0;// notas guardadas na estrutura que são recebidas em media
            i++;
        }
    }else{
        printf("NAO HA VAGAS");
    }
}

void lanca_notas(int n, Alunos **alunos){//Terceira função
    int i;//Declarando contador
    
    for(i=0;i<n;i++){
        if(alunos[i]!=NULL){//um erro para acessar um endereço
            printf("Aluno %d\n", i+1); //Informa o número do aluno
            printf("Informe a primeira nota:\n");//Pedindo 1° nota do aluno
            scanf("%f", &alunos[i]->nota[0]);//guardando e lendo valor informado pelo usuario
            printf("Informe a segunda nota:\n");//Pedindo 2° nota do aluno
            scanf("%f", &alunos[i]->nota[1]);//Lendo e armazenando valor informado pelo usuario
            printf("Informe a terceira nota:\n");//Pedindo 3° nota do aluno
            scanf("%f", &alunos[i]->nota[2]);//guardando e lendo valor informado pelo usuario
            
            alunos[i]->media=(alunos[i]->nota[0] + alunos[i]->nota[1] + alunos[i]->nota[2])/3;
                //fazendo media aritmedica das notas do aluno
            printf("Media: %.2f \n", alunos[i]->media);//Mostrando o resultado da mdia do aluno
        }
    } 
}

void imprime_tudo(int n, Alunos **alunos){//Quarta função
    int i;//Declarando contador
    for(i=0; i<n; i++){
        if(alunos[i]!= NULL){//um erro para acessar um endereço
            printf("\n Matricula:  %d \n", alunos[i]->matricula ); //Mostrando matricula
            printf("Nome: %s \n", alunos[i]->nome);//Mostrando nome
            printf("Turma: %s \n", alunos[i]->turma);//Mostrando turma turma          
        }
    }
}

void imprime_turma(int n, Alunos **alunos, char turma){//Quinta função
    int i;//Declarando contador
    for(i=0; i<n; i++){
        if(alunos[i]!= NULL){//um erro para acessar um endereço
        printf("\n Matricula:  %d \n", alunos[i]->matricula );//Mostrando matricula
        printf("Nome: %s \n", alunos[i]->nome);//Mostrando nome
        printf("Turma: %s \n", alunos[i]->turma);//Mostrando turma       
        }
    }
}

void imprime_turma_aprovados(int n,Alunos **alunos, char turma){//Sexta função
    int i;//Declarando contador
    
    for(i=0;i<n;i++){//Laço para encontrar medias maior ou igual a 7
        if(alunos[i]!=NULL && alunos[i]->turma==turma){
           if(alunos[i]->media>=7){//Medias maior ou igual que 7
                printf("\n Matricula:  %d \n", alunos[i]->matricula);//Mostrando dados do alunos com media maior ou igual 7
                printf("Nome: %s \n", alunos[i]->nome);
                printf("Media: %f \n, APROVADO \n", alunos[i]->media);
           }
        }
    }
}

int main(void){//Funcao principal
    int n=10;//Número maximo de alunos na turma
    Alunos *alunos[n];//Chamando struct 
    
    matricula(n,alunos);//Chamando funcao matricula 
    lanca_notas(n,alunos);//Chamando funcaolancar notas 
    imprime_tudo(n,alunos);//Chamando funcao imprime_tudo 
    imprime_turma(n,alunos, 'a');//Chamando funcao imprime_turma 
    imprime_turma_aprovados(n,alunos, 'a');//Chamando funcao imprime_turma_aprovados 
}