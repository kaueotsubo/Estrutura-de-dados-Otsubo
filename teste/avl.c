#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
    int altura;
    
}No;

No *criar_arvore(){
    return NULL;
}

No *criar_no(int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    novo->altura = 0;
    return novo;
}

int calcular_altura(No *no){
    if(no == NULL) return -1;
    return no->altura;
}

void atualizar_altura(No *no){
    no->altura = 1 + (int)fmax(calcular_altura(no->esq), calcular_altura(no->dir));
}

int calcular_fb(No *no){
    return calcular_altura(no->esq) - calcular_altura(no->dir);
}

No *rotacao_direita(No *y){
    No *x = y->esq;
    No *t2 = x->dir;
    x->dir = y;
    y->esq = t2;
    atualizar_altura(x);
    atualizar_altura(y);
    return x;
}

No *rotacao_esquerda(No *x){
    No *y = x->dir;
    No *t2 = y->esq;
    y->esq = x;
    x->dir = t2;
    atualizar_altura(x);
    atualizar_altura(y);
    return y;
}

No *inserir_no(No *atual, int valor){
    //caso base
    if (atual == NULL) return criar_no(valor);

    //caso complexo
    if(valor < atual->valor) atual->esq = inserir_no(atual->esq, valor);
    else if (valor > atual->valor) atual->dir = inserir_no(atual->dir, valor);
    else return atual;

    atualizar_altura(atual);
    int fb = calcular_fb(atual);
    if(fb > 1 && valor < atual->esq->valor) return rotacao_direita(atual);
    if(fb > 1 && valor > atual->esq->valor) {
        atual->esq = rotacao_esquerda(atual->esq);
        return rotacao_direita(atual);
    }
}

void imprimir(No *atual, int nivel){
    if(atual != NULL){
        imprimir(atual->dir, nivel+1);
        int i;
        for(i = 0; i <= nivel; i++)printf("\t");
        printf("%d\n", atual->valor);
        imprimir(atual->esq, nivel+1);
    }
}

int main(){
    No *raiz = criar_arvore();
    raiz = inserir_no(raiz, 10);
    raiz = inserir_no(raiz, 20);
    raiz = inserir_no(raiz, 25);
    raiz = inserir_no(raiz, 30);
    raiz = inserir_no(raiz, 35);
    raiz = inserir_no(raiz, 40);
    raiz = inserir_no(raiz, 45);
    raiz = inserir_no(raiz, 50);

    imprimir(raiz, 0);
    
    return 0;
}