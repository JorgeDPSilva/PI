#include <stdio.h>

typedef struct lligada {
int valor;
struct lligada *prox;
} *LInt;

typedef struct nodo {
int valor;
struct nodo *esq, *dir;
} *ABin;


 
//1 
int length (LInt l){
    int comprimento;
    for(comprimento=0;l;comprimento++){
        l=l->prox;
    }
    return comprimento;
}


//2 
void freeL (LInt l){
	LInt temp;
	while(l){
		temp = l;
        l= l->prox;
        free(l);
    }
}

//3 ja esta 3)
void imprimeL (LInt l){
    while (l){
        printf ("%d\n",l->valor);
        l=l->prox;
    }
}


//4 ja esta 4)
LInt reverseL (LInt l){
    LInt l1,l2= NULL;
    while(l){
        l1=l->prox; //aponta para o proximo sem ser a cabeça
        l->prox=l2; // aponta para NULL
        l2=l; // cabeça da lista inicial
        l=l1; // l sem a cabeça
    }
    return l2;
}


//5 ja esta 5)
void insertOrd (LInt *l, int x){
    LInt new;
    while(*l  && (*l)->valor<x){
        l=(&(*l)->prox);
    }
        
    new=newLInt (x,*l);
    *l=new;
}

//6 ja esta 6)
int removeOneOrd (LInt *l, int x){
    LInt aux;
    while(*l && (*l)->valor!=x){
        l=&(*l)->prox;
    }
    if(*l){
        aux=(*l)->prox;
        free(*l);
        *l=aux;
        return 0;
    }
    return 1;
}

//7 ja esta
void merge (LInt *r, LInt l1, LInt l2){
     while(l1 && l2){
        if(l1->valor <= l2->valor){
            *r = l1;
            l1 = l1->prox;
        }else{
            *r = l2;
            l2 = l2->prox;
        }
        r = &((*r)->prox);
    }
    if(l1) *r = l1;
    else *r = l2;
}

//8 ja esta  8)
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    while(l){
        if(l->valor < x){
        (*mx)=l;
        mx=(&(*mx)->prox);
        }
        else{
        (*Mx)=l;
        Mx=(&(*Mx)->prox);
        }
        l=l->prox;
    }
    *mx=NULL;
    *Mx=NULL;
}


//9 ja esta
LInt parteAmeio (LInt *l) {
    int x = 0;
    LInt aux = *l;
    LInt res = 0;

        while (aux) {
        x++;
        aux = aux->prox;
    } 
    

    for (x /= 2 ; x > 0 ; x--) {
        
        if (!res) aux = res = *l;
        else aux = aux->prox = *l;
        
        *l = (*l)->prox;
        aux->prox = 0;
    }


    return res;
}

//10 ja esta
int removeAll (LInt *l, int x){
    int contador = 0;
    LInt l1= NULL;
    while(*l){
        if((*l)-> valor != x){
            l = &((*l)->prox);    
        }
        else {
            l1 = (*l)->prox;
            free(*l);
            *l = l1;
            contador++;
        } 
    }
    return contador;
}


//11 ja esta
int removeDups (LInt *l){
    int c = 0;
    
    for(; *l; l = &((*l)->prox)){
        c += removeAll(&(*l)->prox, (*l)->valor);
    }
    
    return c;
}

//12 ja esta 
int removeMaiorL (LInt *l){
    int max = maximo(l);
    
    while((*l)->valor != max) l = &(*l)->prox;
    
    LInt temp = (*l)->prox;
    free(*l);
    *l = temp;
    
    return max;
}
        



//13 ja esta
void init (LInt *l) {
    while ((*l)->prox) {
        l = &(*l)->prox;
    }
    free(*l);
    *l = NULL;
    } 

//14 ja esta
void appendL (LInt *l, int x){
    while(*l){
        l=&((*l)->prox);}
    *l=(LInt)malloc(sizeof(struct lligada));
    (*l)->valor=x;
    (*l)->prox=NULL;
}

//15  
void concatL (LInt *a, LInt b){
    while(*a) 
    a = &(*a)->prox;
    *a = b;
}

//16 ja esta
LInt cloneL(LInt l){
    LInt r;
    if (l == NULL)
        r = NULL;
    else
    {
        r = malloc(sizeof(LInt));
        r->valor = l->valor;
        r->prox = cloneL(l->prox);
    }
    return r;
}
//17 ja esta
LInt cloneRev (LInt l){
    LInt nova=NULL,aux2=NULL;
    while(l){
    aux2=nova;
    nova=(LInt)malloc(sizeof(struct lligada));
    nova->valor=l->valor;
    nova->prox=aux2;// vai ser null ou seja o elemento que metemos em primeiro de l vai passar para ultimo
    l=l->prox;
    }
return nova;
}

//18 ja esta
int maximo (LInt l){
    int max;
    while(l){
        if(l->valor > max){ 
            max=l->valor;}
    l=l->prox;
    }
    return max;
}

//19 ja esta
int take (int n, LInt *l){
    int c = 0;
    while(*l && n > 0) {
        l = &(*l)->prox;
        n--; c++;
    }
    freeL(*l);
    *l = NULL;
    return c;
}


//20 ja esta
int drop (int n, LInt *l) {
    int res = n;

    while (n>0 && *l) {

        *l = (*l)->prox;
        n--;

    }

    return res-n;
}

//21 ja esta
LInt NForward (LInt l, int N) {

    while (N != 0) {
        l = l->prox;
        N--;
    }

    return l;
}
//22 ja esta
int listToArray (LInt l, int v[], int N){
    int i;
    for(i=0;i<N && l;i++){
        v[i]=l->valor;
        l=l->prox;
    }
    return i;
}

//23 ja esta
LInt arrayToList (int v[], int N) {
    LInt res = NULL; 
    if (N>0) {
    
        res = malloc (sizeof(struct lligada));
        res->valor = v[0];
    
        res->prox = (arrayToList(v+1,N-1));

    }
 return res;
}

//24 ja esta
LInt somasAcL (LInt l) {
    LInt r, *e=&r;
    int somas=0;
    while(l){
        (*e)=malloc (sizeof (struct lligada));
        somas+=l->valor;
        (*e)->valor=somas;
        l=l->prox;
        e=&((*e)->prox);
    }
    *e=NULL;
    return r;
}



//25 ja esta
void remreps (LInt l){
    LInt p, pt;
    while(l)
    {   
        p = l->prox;
        while(p && l->valor == p->valor){
            pt = p->prox;
            free(p);
            p = pt;
        }
        l->prox = p;
        l = l->prox;
    }
}

//26 ja esta
LInt rotateL(LInt l){
    LInt fst=l;
    if (l && l->prox){
        while (l->prox)
            l = l->prox;
            l->prox = fst;
            l = fst->prox;
            fst->prox = NULL;
        
    }
    return l;
}

//27 ja esta
LInt parte(LInt l) {
    if (l == NULL || l->prox == NULL) {
        // Se a lista estiver vazia ou tiver apenas um elemento, não há nada para dividir
        return NULL;
    }
    
    LInt even = l->prox; // Cabeça da lista dos elementos das posições pares (índices 1, 3, 5, ...)
    LInt odd = l; // Cabeça da lista dos elementos das posições ímpares (índices 0, 2, 4, ...)
    
    LInt evenHead = even; // Ponteiro auxiliar para manter a referência ao início da lista dos elementos das posições pares
    
    while (odd != NULL && even != NULL && odd->prox != NULL && even->prox != NULL) {
        odd->prox = even->prox;
        odd = odd->prox;
        even->prox = odd->prox;
        even = even->prox;
    }
    
    odd->prox = NULL; // Finaliza a lista dos elementos das posições ímpares
    
    return evenHead; // Retorna a lista dos elementos das posições pares
}

//28 ja esta
int altura (ABin a) {
    int esq,dir,alt = 0;

    if (a) {
        esq = 1+altura(a->esq);
        dir = 1+altura(a->dir);
        if (esq > dir) alt = esq;
        else alt = dir;
        }
return alt;
    }

//29 ja esta
ABin cloneAB (ABin a) {
    ABin clone;
    if(a==NULL) clone=NULL;
    else{
        clone=(ABin)malloc (sizeof(struct nodo));
        clone->valor = a->valor;
        clone->esq=cloneAB(a->esq);
        clone->dir=cloneAB(a->dir);
    }
    return clone;
}

//30 ja esta
void mirror (ABin *a) {
    ABin b;
    if(*a!=NULL){
        b=(*a)->esq; // guarda a parte esquerda no b
        (*a)->esq=(*a)->dir; // esquerda igual a direita
        (*a)->dir=b; // parte direita vai ser igual agora a b que esta guardada a esquerda
        
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
}

//31 ja esta
void inorder (ABin a, LInt *l) {

    if (a) {

        inorder(a->esq,l);

        while (*l) {
            l = &(*l)->prox;
        }

        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        l = &(*l)->prox;

        inorder(a->dir,l);

    }

    else *l = NULL;

}

//32 ja esta
void preorder (ABin a, LInt * l) {
    
    if(a) {

    *l = malloc(sizeof(struct lligada));
    (*l)->valor = a->valor;
    l = &(*l)->prox;

    preorder(a->esq,l);
    while (*l) {
        l = &(*l)->prox;
    }
    preorder(a->dir,l);

    }
    
    else *l = NULL;

}
//33 ja esta
void posorder (ABin a, LInt *l) {

    if (a) {
        
        posorder(a->esq,l);
        
        while (*l) {
            l = &(*l)->prox;
        }
        
        posorder(a->dir,l);
        
        while (*l) {
            l = &(*l)->prox;
        }
        
        *l = malloc(sizeof(struct lligada));
        (*l)->valor = a->valor;
        (*l)->prox = NULL;

        
    }

    else *l = NULL;

}

//34 ja esta
int depth (ABin a, int x) {
    int res = -1,esq,dir;

    if (a) {

        if (x == a->valor) res = 1;

        else {
            esq = depth(a->esq,x);
            dir = depth(a->dir,x);

            if (esq < 0 && dir < 0) res = -1;
            else if (esq < 0) res = 1+dir;
            else if (dir < 0) res = 1+esq;

            else if (esq < dir) res = 1+esq;
            else res = 1+dir;
        }
    }
    return res;
}

//35 ja esta
int freeAB (ABin a) {
    int i=0;
    if(a){
        i=i+freeAB(a->esq);
        i=i+freeAB(a->dir);
        free(a);
        i++;
    }
    return i;
}


//36 ja esta
 int pruneAB (ABin *a, int l) {
     int i=0;
     if(*a){
         i+=pruneAB(&((*a)->esq),l-1);
         i+=pruneAB(&((*a)->dir),l-1);
         if(l<=0){
             free(*a);
             *a=0;
             i++;
         }
     }
     return i;
 }
//37 ja esta
int iguaisAB (ABin a, ABin b) {
    if(a!=NULL && b!=NULL){
        if((a->valor==b->valor) && iguaisAB(a->esq,b->esq) && iguaisAB(a->dir,b->dir))return 1 ;
    }
    if(a==NULL && b==NULL){
        return 1;
    }
    return 0;
}

//38 ja esta
LInt nivelL (ABin a, int n) {
    LInt b,res = NULL;
if (a) {
        if (n==1) {
res = malloc(sizeof(struct lligada));
            res->valor = a->valor;
            res->prox = NULL;
}
else {
res = b = nivelL(a->esq,n-1);
            while (b && b->prox) {
            b = b->prox;
}            
if (b) b->prox = nivelL(a->dir,n-1);
            else res = nivelL(a->dir,n-1);
        }
}
return res;
}


//39 ja esta
int nivelV (ABin a, int n, int v[]) {
    int i=0;
    if(a){
        if(n==1){
            v[i]=a->valor;
            i++;
        }
        else{
            i=nivelV(a->esq,n-1,v);
            i+=nivelV(a->dir,n-1,v+i);
        }
    }
    return i;
}

//40 ja esta
int dumpAbin (ABin a, int v[], int N) {
    int i=0;
    if(a){
    if(i<N){
        i+=dumpAbin(a->esq,v,N);
    }
    if(N-i>0){
        v[i++]=a->valor;
        i+=dumpAbin(a->dir,v+i,N-i);
    }
    }
    return i;
}


//41 ja esta
ABin somasAcA (ABin a) {
    ABin res = NULL,aux;
    int soma = 0;

    if (a) {

        res = malloc(sizeof(struct nodo));
        res->esq = somasAcA(a->esq);
        res->dir = somasAcA(a->dir);
        res->valor = a->valor;

        if (res->esq) res->valor += res->esq->valor;
        

        if (res->dir) res->valor += res->dir->valor;

    }

    return res;
}


//42 ja esta
int contaFolhas (ABin a) {
    if(a==NULL)return 0;
    int i=0;
    if(a->esq==NULL && a->dir==NULL)i=1;
    i=i+contaFolhas(a->esq);
    i=i+contaFolhas(a->dir);
    return i;
}


//43 ja esta
ABin cloneMirror (ABin a) {
    ABin b,esq,dir;
    if(a==NULL) b=NULL;
    else{
    b=(ABin)malloc(sizeof(struct nodo));
    b->valor=a->valor;
    esq=cloneMirror(a->esq);
    dir=cloneMirror(a->dir);
    b->esq=dir;
    b->dir=esq;
    }
    return b;
}
//44 ja esta
int addOrd (ABin *a, int x) { // 10 em 10
       
    while (*a)
    {
        if (x == (*a)->valor) return 1;
        if (x > (*a)->valor) a = &((*a)->dir);
        
        else a = &((*a)->esq);
    }
    
    (*a) = malloc(sizeof (struct nodo));
    (*a)->valor= x;
    (*a)->esq=NULL;
    (*a)->dir=NULL;

    
    return 0;
}



//45 ja esta
int lookupAB (ABin a, int x) {
    while(a){
        if(x==a->valor) return 1;
        else if(x>a->valor){
            a=a->dir;
        }
            else{
                a=a->esq;
            }
}
return 0;
}
//46 ja esta
int depthOrd (ABin a, int x) {
    int res=1;
    while(a) {
        if (x== a->valor)return res;

        if(x> a->valor) {
            a=a->dir;
            res++;}

        else {
            a= a->esq;
            res++;}


    }
    return -1;
}

//47 ja esta
int maiorAB (ABin a) {
    while(a && a->dir){
        a=a->dir;
    }
    return a->valor;
}

//48 ja esta
void removeMaiorA (ABin *a) {
    while(*a && (*a)->dir){
        a=&((*a)->dir);
    }
    (*a)=(*a)->esq;
}


//49 ja esta
int quantosMaiores (ABin a, int x) {
    int i=0;
    if(a==NULL) return 0;
        if(a->valor>x){
            i++;
            }
        i=i+quantosMaiores(a->esq,x);
        i=i+quantosMaiores(a->dir,x);
        return i;
}

//50 ja esta
void listToBTree (LInt l, ABin *a) {
    while(l){
        (*a) = malloc(sizeof(struct nodo));
        (*a)->valor = l->valor;
        (*a)->esq = NULL;
        a = &((*a)->dir);
        l = l->prox;
    }
}

//51 ja esta
int menor(ABin a , int x){
     int r=0;
     if(a==NULL) r=1;
     else if(a->valor<x && menor(a->esq,x) && menor(a->dir,x)) r=1;
     return r;
 }
 
 int maior(ABin a , int x){
     int r=0;
     if(a==NULL) r=1;
     else if(a->valor>x && maior(a->esq,x) && maior(a->dir,x)) r=1;
     return r;
 }
 
 
 
int deProcura (ABin a) {
    int r=0;
    if(a==NULL)r=1;
    else if(menor(a->esq,a->valor)&& maior(a->dir,a->valor) && deProcura(a->esq) && deProcura(a->dir)){
        r=1;
    }
    return r;
}

