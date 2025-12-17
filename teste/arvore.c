#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
}No;

No *criar_arvore(){
    return NULL;
}

No *criar_no(int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No *inserir_no(No *atual, int valor){
    //caso base
    if (atual == NULL) return criar_no(valor);

    //caso complexo
    if(valor < atual->valor){
        atual->esq = inserir_no(atual->esq, valor);
    }else atual->dir = inserir_no(atual->dir, valor);
    return atual;
}

void imprimir(No *atual){
    if(atual != NULL){
        imprimir(atual->dir);
        printf("%d\n", atual->valor);
        imprimir(atual->esq);
    }
}

int buscar(No *atual, int valor){
    if(atual == NULL) return 0;
    if(valor == atual->valor) return 1;
    if(valor < atual->valor) return buscar(atual->esq, valor);
    return buscar(atual->dir, valor);
}

No *remover_no(No *atual, int valor){
    if(atual == NULL) return NULL;
    if(valor < atual->valor) atual->esq = remover_no(atual->esq, valor);
    else if (valor > atual->valor) atual->dir = remover_no(atual->dir, valor);
    else{
        //encontrei o valor que quero remover
        if (atual->esq == NULL && atual->dir == NULL){
            free(atual);
            return NULL;
        }else if(atual->esq == NULL ){
            No *aux = atual->dir;
            free(atual);
            return aux;
        }else if(atual->dir == NULL){
            No *aux = atual->esq;
            free(atual);
            return aux;
        }
        
        
    }
    
}
int main(){
    No *raiz = criar_arvore();
    raiz = inserir_no(raiz, 10);
    raiz = inserir_no(raiz, 20);
    raiz = inserir_no(raiz, 5);
    raiz = inserir_no(raiz, 30);
    raiz = inserir_no(raiz, 40);
    raiz = inserir_no(raiz, 2);
    raiz = inserir_no(raiz, 7);
    raiz = inserir_no(raiz, 6);

    imprimir(raiz);
    printf("\n%d ", buscar(raiz, 5));
    return 0;
}