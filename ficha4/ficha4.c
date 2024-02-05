#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef  int bool;
#define TRUE 1
#define FALSE 0



//ex 1
bool emaiuscula(char c){
	if ('A'<=c<='Z') return TRUE;
	else return FALSE;
}


int minusculas (char s[]){
	int i;
	int soma=0;
	for (i=0;s[i]!='\0';i++){
		if (emaiuscula(s[i])){
			s[i]=s[i]+32;
			soma=soma+1;
		}
}
return soma;
}


//ex 2
int contalinhas (char s[]){
	int soma=1;
	for (int i=0;s[i]=='\0';i++)
	if (s[i]=='\n'){
	soma=soma+1;}	
return soma;
}

//ex 3
int contaPal(char s[])
{
    int i, conta;
    conta = 0;
    for (i = 0; s[i]; i++)
    {
        if (!isspace(s[i]) && s[i + 1]=='/0')//só para contar a ultima
            conta=conta+1;
        
        else if (!isspace(s[i]) && isspace(s[i + 1]))
            conta=conta+1;
    }
    return conta;
}

//ex 4
int procura (char *p, char *ps[], int N){
	int i;
	for(i=0;i<N;i++){
		if(strcmp(p,ps[i])==0)
			i=i+N;
	}
return i-N;
}

//ex 5
int procura (char *p, char *ps[], int N){
	int i,found=-1;
	for(i=0;i<N && (found <=0);i++){
		found=strcmp(p,ps[i]);
	}
return (found==0?i:-1);
}

//ex 7
int zeros (int N, int M, int m [N][M]){
	int l,c,nzeros=0;
	for(l=0;l<N;l++){
		for(c=0;c<M,c++){
			if (m[l][c]==0) nzeros=nzeros+1;
		}
}
return nzeros;
}
//ex8
void identidade (int N, int m[N][N]){
	int l,c;
	for(l=0;l<N,l++){
		for(c=0;c<N,c++){
			if (l==c) m[l][c]==1;
		else m[l][c]==0;
						}
					}
}









int main (){
return 0;	
}