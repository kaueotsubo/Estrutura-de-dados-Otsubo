#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Pessoa{
    char nome[50];
    int idade;
}Pessoa;

typedef struct No {
    Pessoa pessoa;
    struct No *prox;    
}No;

typedef struct {
    No *inicio;
    No *fim;
}Fila;

Fila *criar_fila(){
    Fila *f =(Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

Pessoa criar_pessoa(char nome[], int idade){
    Pessoa nova;
    strcpy(nova.nome, nome);
    nova.idade = idade;
    return nova;
}

void enfileirar(Fila *f, Pessoa p){
    No *novo = (No*)malloc(sizeof(No));
    novo->pessoa = p;
    novo->prox = NULL;
    
    if(f->inicio == NULL){
        f->inicio = novo;
    }
    else{
        f->fim->prox = novo;    
    }
    f->fim = novo;
}

void imprimir(Fila *f){
    No *aux = f->inicio;
    while (aux != NULL){
        printf("{Nome: %s, %d anos} ", aux->pessoa.nome, aux->pessoa.idade);
        aux = aux->prox;    
        if(aux != NULL){
            printf(" -> ");
        }
    }
    printf("\n");
}

void desenfileirar(Fila *f){
    if (f->inicio != NULL){
        No *aux = f->inicio;
        f->inicio = f->inicio->prox;
        free(aux);
        if(f->inicio == NULL){
            f->fim = NULL;
        }
    }    
}

int ehvazia(Fila *f){
    if(f->inicio == NULL) return 1;
    else return 0;
}

int tamanho(Fila *f){
    int cont = 0;
    No *aux = f->inicio;
    
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void limpar(Fila *f){
    No *aux = f->inicio;
    while (aux != NULL){
        aux = aux->prox;
       desenfileirar(f);
    }
    
}

int main(){
    Fila *fila = criar_fila();
    Pessoa p = criar_pessoa("Flaco Lopez", 25);
    enfileirar(fila, p);
    p = criar_pessoa("Vitor Roque", 20);
    enfileirar(fila, p);
    p = criar_pessoa("Carlos Miguel", 27);
    enfileirar(fila, p);
    p = criar_pessoa("Ana Luiza", 19);
    enfileirar(fila, p);
    p = criar_pessoa("Abel Ferreira", 45);
    enfileirar(fila, p);
    p = criar_pessoa("Gustavo Gomez", 32);
    enfileirar(fila, p);
    imprimir(fila);
    printf("\nApos desenfileirar:\n\n");
    limpar(fila);
    imprimir(fila);
    printf("%d", tamanho(fila));
    return 0;
}