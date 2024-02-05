#include "arbin.h"



ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

int altura (ABin a) {
    int esq,dir,alt = 0;

    if (a != NULL) {
        esq = 1+altura(a->esq);
        dir = 1+altura(a->dir);
        if (esq > dir) alt = esq;
        else alt = dir;
        }
return alt;
    }

int nFolhas (ABin a) {
    if(a==NULL) return 0;
    
    // para ver se só tem raiz
    if(a->esq==NULL && a->dir==NULL) return 1;

    return nFolhas(a->esq) + nFolhas(a->dir);
}

ABin maisEsquerda (ABin a){
     while(a && a->esq){
        a=a->esq;
    }
    return a;
}


void imprimeNivel (ABin a, int l){
    if (a != NULL){
    if(l == 0){ 
        printf("%d",a->valor);
    }else{
        if(a->esq != NULL)  imprimeNivel(a->esq,l-1);
        if(a->dir != NULL)  imprimeNivel(a->dir,l-1);
    }
}
}

int procuraE (ABin a, int x){
    if (a == NULL) return 0;
    
    if(a->valor == x) return 1;
    
    while(a){
    int ae = procuraE(a->esq,x);
    int ad = procuraE(a->dir,x);
    }

return ae || ad ;
}

    
struct nodo *procura (ABin a, int x){
    if (a == NULL) {
        return NULL;
    }
    else if (a-> valor == x) {
        return a;
    }
    else if (x < a->valor) {
        return procura(a->esq, x);
    }
    else{
        return procura(a->dir, x);
    }
    
}
        


int nivel (ABin a, int x){
    int i= 0;

    while(a != NULL){
        if(a-> valor == x){ 
            return i;
        }
        else if(a-> valor < x) { 
            a=a->dir;
        }
        else {
            a=a->esq;
        }
        i++;
    }
    return -1;   
}

// se for == ao valor da raiz chama recursivamente a subarvore esquerda
void imprimeAte(ABin a, int x) {
    if (a == NULL) {
        return;
    }
    
    imprimeAte(a->esq,x);
    if (a->valor < x) {
        printf("%d ", a->valor);
        imprimeAte(a->dir, x);
    }
    
}
