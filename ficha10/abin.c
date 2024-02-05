#include "abin.h"

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


// Questão 1
ABin removeMenor (ABin *a){
    // caso base 
    if ((*a) == NULL) return NULL;

    ABin ant = NULL, cursor = *a;

    while (cursor->esq != NULL) {
        ant = cursor;
        cursor = cursor->esq;
    }

    if (ant == NULL) {
        (*a) = cursor->dir;
    } else {
        ant->esq = cursor->dir;
    }

    return cursor;
}

// exercicio 2
void removeRaiz(ABin *a) {
    if (*a == NULL) return;

    if ((*a)->esq == NULL) {
        ABin temp = (*a)->dir;
        free(*a);
        (*a) = temp;
    } else {
        ABin ant = NULL, cursor = *a;

        while(cursor->dir != NULL) {
            ant = cursor;
            cursor = cursor->dir;
        }

        free(*a);

        if (ant == NULL) {
            (*a) = cursor->dir;
        } else {
            ant->dir = cursor->esq;
        }
    }
}

// exercicio 3
int removeElem (ABin *a, int x){
   if (*a == NULL) {
        return -1;
    }

    if ((*a)->valor == x) {
        // Caso base: o elemento é a raiz da árvore
        ABin nodoRemovido = *a;
        *a = NULL;  
        free(nodoRemovido);  
        return 0; 
    }

    // Procura o elemento na subárvore esquerda
    if (removeElem(&(*a)->esq, x) == 0) {
        return 0;  // Elemento removido com sucesso na subárvore esquerda
    }

    // Procura o elemento na subárvore direita
    if (removeElem(&(*a)->dir, x) == 0) {
        return 0; 
    }
    
    return -1;
}