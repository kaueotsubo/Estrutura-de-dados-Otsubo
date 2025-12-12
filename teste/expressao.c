#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct No{
    char c;
    struct No *prox;
}No;


typedef struct{
    No *topo;
}Pilha;

Pilha *criar_pilha(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int is_empty(Pilha *p){
    if(p->topo == NULL) return 1;
    return 0;
}

void push(Pilha *p, char c){
    No *novo = (No*)malloc(sizeof(No));
    novo->c = c;
    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha *p, char c){
    if(p->topo != NULL && p->topo->c == c){
        No *aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
        return 1;
    }
    return 0;    
}

int verificar(char expressao[],Pilha * p){
    int i;
    for(i=0; i<strlen(expressao); i++){
        if(expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{'){
            push(p, expressao[i]);
        }
        else if(expressao[i] == ')'){
            if(pop(p, '(') == 0) return 0;
        }
        else if (expressao[i] == ']'){
            if (pop(p, '[') == 0) return 0;
        }
        else if (expressao[i] == '}'){
            if (pop(p, '{') == 0) return 0;
        }
    }
    return is_empty(p);
}

void clear(Pilha *p){
    No *aux = p->topo;
    while (p->topo != NULL){
        p->topo = aux->prox;
        free(aux);
    }
}

int main(){
    char expressao[500];
    Pilha *p = criar_pilha();
    printf("Escreva uma expressao numerica(Sem espaco): \n");
    scanf("%s", expressao);
    if(verificar(expressao, p)) printf("A expressao esta balanceada\n");
    else printf("Nao esta balanceada\n");

    clear(p);

    free(p);
    return 0;
}