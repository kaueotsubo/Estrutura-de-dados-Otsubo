#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Livro{
    char titulo[100];
    char autor[50];
    int ano;
}Livro;

typedef struct No{
    Livro livro;
    struct No *prox;
}No;

typedef struct Pilha{
    No *topo;
}Pilha;

Pilha *criar_pilha(){
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

Livro criar_livro(char titulo[], char autor[], int ano){
    Livro novo;
    strcpy(novo.titulo, titulo);
    strcpy(novo.autor, autor);
    novo.ano = ano;
    return novo;
}

void imprimir(Pilha *p){
    No *aux = p->topo;
    while (aux != NULL){
        printf("Titulo: %s, de %s, publicado em %d\n", aux->livro.titulo, aux->livro.autor, aux->livro.ano);
        if(aux->prox != NULL){
            printf("\t\t||\n");
            printf("\t\t\\/\n");
        }
        aux = aux->prox;
    } 
}

void empilhar(Pilha *p, Livro l){
    No *novo = (No*)malloc(sizeof(No));
    novo->livro = l;
    novo->prox = p->topo;
    p->topo = novo;
}

void desempilhar(Pilha *p){
    No *aux = p->topo;
    p->topo = p->topo->prox;
    free(aux);
}

int ehvazia(Pilha *p){
    if(p->topo == NULL) return 1;
    return 0;
}

int tamanho(Pilha *p){
    int cont = 0;
    No *aux = p->topo;
    
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int main(){
    Pilha *pilha = criar_pilha();
    Livro livro = criar_livro("Olhos Prateados", "scott cawthon", 2016);
    empilhar(pilha, livro);
    livro = criar_livro("codigo da vinci", "Dan Brown", 2003);
    empilhar(pilha, livro);
    livro = criar_livro("O hobbit", "j.r.r tolkien", 1937);
    empilhar(pilha, livro);

    imprimir(pilha);

    printf("\nApos desmpilhar:\n");
    desempilhar(pilha);
    imprimir(pilha);

    printf("%d", tamanho(pilha));
    return 0;
}
