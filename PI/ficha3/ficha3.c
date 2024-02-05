#include <stdio.h>

//ex1 a)
/*int x [15] = {1, 2, 3, 4, 5,
6, 7, 8, 9,10,
11,12,13,14,15};
int *y, *z, i;
y = x; z = x+3;
for (i=0; (i<5); i++) {
printf ("%d %d %d\n",
x[i], *y, *z);
y = y+1; z = z+2;
}//tabela do caderno*/


//ex 1 b)
/*int main () {
int i, j, *a, *b;
i=3; j=5;
a = &i; b = &j;
i++;
j = i + *b;
b = a;
j = j + *b;
printf ("%d\n", j);
return 0;
}//retorna 13 
*/

//ex 2
 void swapM (int *x, int *y){
 int resultado;
 			resultado=*x;
 			*x=*y;
 			*y=resultado;
}

//ex 3
void swap (int v[], int i, int j){
int troca1;
	troca1=v[i];
	v[i]=v[j];
	v[j]=troca1;
}

//ex 4
int soma (int v[], int N){
int i;
int soma =0;
for(i=0;i<N;i++) {
soma=soma+v[i];
}
return soma;
}

// ex 4 recursiva
int soma1 (int v[],int N){
int soma=0;
if (N == 0) return 0;
	else return  v[0] + (soma1 (v++,(N-1)));
}

//ex 5
int maximum (int v[], int N, int *m){
int max=v[0];
if (N>0){
while (N>0){
	if (max<v[N-1]) max=v[N-1];
	N--;
}
*m=max;
return 0;
}
else return 1;
}

//ex 6
void quadrados (int q[], int N){
int i;
for (i=0;i<N;i++){
q[i]=[i]*[i];
}
}


int main(){
int q[10]={1,2,3,4,5,6,7,8,9,10};
//int v[10]={3};
//soma1(v,10);
//maximum (v,10,3);
quadrados(q,f10);
return 0;
}






















