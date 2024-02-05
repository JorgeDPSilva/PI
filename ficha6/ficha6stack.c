#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"



void SinitStack (SStack s){
	s->sp=0;
}

int  SisEmpty (SStack s){
	return s->sp==0;
}

int  Spush (SStack s, int x){
    if(s->sp == Max) return 1;
    // dava s->sp++ para incrementar em vez da linha a seguir
    s-> values[s->sp] = x;
    s->sp++;

return 0;
}


int  Spop (SStack s, int *x) {
	if(s->sp == 0) return 1;
    // ou s->values[--s->sp] pq o sp esta sempre no indice à frente 
    s->sp--;   
    *x = s->values[s->sp];
    
return 0;
}

int  Stop (SStack s, int *x) {
	 if(s->sp== 0) return 1;
    // quer ir buscar o anterior que é sempre o do topo 
    *x = s->values[s->sp-1];

return 0;
    
}


void ShowSStack (SStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}

// Stacks with dynamic arrays

int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}

void DinitStack (DStack s) {
    s->sp=0;
    s->size=MAX;
    
    //falta verificar se o malloc consegue criar espaço no computador
    s-> values = malloc(sizeof(int) * s->size);
	
}

int  DisEmpty (DStack s) {
	return s->sp == 0;
}

int  Dpush (DStack s, int x){
	if(s->sp == s->size){
	    if(NULL == (s->values = realloc(s->values, sizeof(int) * 2 * s->size))){
	        return 1;
	    }
	    s->size *= 2;
	}
	s->values[s->sp]=x;
	s->sp++;
return 0;
}

int  Dpop (DStack s, int *x){
    if(s->sp == 0){
        return 1;
    }
    
    s->sp--;
    *x= s->values[s->sp];
    
	
	return 0;
}

int  Dtop (DStack s, int *x){
	if(s->sp == 0) return 1;
    // ou s->values[--s->sp] pq o sp esta sempre no indice à frente 
    s->sp--;   
    *x = s->values[s->sp];
    
return 0;
}



