#include <stdio.h>


typedef struct slist *LInt;
typedef struct slist {
int valor;
LInt prox;
} Nodo;


void showList (LInt l){
	while (l!=NULL){
	l=l->prox;
	printf("%d\n",l->valor);
	}
}





//1 a)
Lint insere (Nodo x){
	LInt a=malloc (sizeof(Nodo));
	LInt b=malloc (sizeof(Nodo));
	LInt c=malloc (sizeof(Nodo));
	a-> valor=10;a->prox=b;
	b-> valor=5;b->prox=c;
	c-> valor=15;c->prox=NULL;
	showList(a);
}	

//1 b) i)
LInt cons (LInt l, int x) {
	LInt res;
	res=malloc(sizeof(Nodo)),
	res->valor=x;
	res->prox=l;
	return res;
}

//1 b) ii)
LInt tail (LInt l){
	LInt res;
	res=l->prox;
	free(l);		// desaloca memoria 
	return res;
}

//1 b) iii)
LInt init (LInt l){
	LInt aux;
	LInt ant;
	ant=l;
	aux=l;
	while(aux->prox!=NULL){
		ant=aux;
		aux=aux->prox;
	}
ant->prox=NULL;	
free(aux);
return l;
}

//1 b) iv
LInt snoc (LInt l, int x){
	LInt res=l;LInt a;
	a=malloc(sizeof(Nodo));
	a->valor=x;
	while(res->prox!=NULL){
	res=res->prox;
}
res->prox=a; //mete o valor de x depois de percorrer a lista;
a->prox=NULL;
}
return l;

//1 b) v
LInt concat (LInt a, LInt b){
	LInt aux=a;
	if(!a) return b;
	else{
		while(a->prox) a=a->prox;
	a->prox=b;
	}
return aux;
}

//2
typedef Struct Aluno{
	char Nome[61];
	char numero[7]
	float nota;
}Aluno;

typedef struct turma *Lturma;
typedef struct turma{
	Aluno aluno;
	Lturma prox;
}Turma;


int main (){
	Aluno 
	a1={"Joao","a22222",15.5};
	a2={"Ana","a32532",14.3};
	a3={"Filipe","a44751",12.7}
	LTurma t1;
	t1=cons(cons (cons(t1,a3),a2),a1);
	showTurma(t1);
}


void showList (LTurma t){
	while (t!=NULL){
	t=t.prox;
	printf("%s %s %f \n",t->açimp.nome,t->aluno.numero,t->aluno.nota);
	}
}






