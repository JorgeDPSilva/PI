#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//1
int main(){
	int max=0,i=0;
	
	scanf("%d",&i);

	while (i!=0){
		if (i>max) max=i;
		scanf("%d",&i);
	}
	printf( "O maximo é: %d\n",max);

return 0;
}


//2
int main(){
double media=0;
int i=0,soma=0,total=0;
	
	scanf("%d",&i);

	while (i!=0){
		soma+=i;
		total+=1;
		
		scanf("%d",&i);
	}
	media=(double) soma/total;
	printf("A media é: %f\n",media);

return 0;
}


//3
int main(){
	int max=0,i=0,max2=0;
	
	scanf("%d",&i);

	while (i!=0){
		if (i>max){											
			max2=max; max=i;
		}
		else 
			if (i>max2 && max>max2) {
				max2=i;
			}
		scanf("%d",&i);

	}
	printf("O segundo maximo é: %d\n",max2);
return 0;
}


//4 
int bitsUm (unsigned int n){
    int total=0;
    while (n != 0){
        if (n%2 == 1)
        {
            total=total+1;
            n = n/2;
        }
        else
            n=n/2;
   } 
return total;
}

//5 
int trailingZ (unsigned int n) {
   int i,conta=0;
	for (i = 0; n % 2 == 0; i++){
		conta++;
		n = n/2;
	}
return conta;
}

//6 
int qDig(unsigned int n){
int res=1;
	while (n> 0) {
		res++;
		n=n/10;
	}
	return res;
}


//7 
char *mystrcat(char s1[], char s2[]){
int i,j;
    for (i=0;s1[i];i++);
    for (j=0;s2[j];j++){
        s1[i++] = s2[j];
    }
    s1[i] = '\0';
    return s1;

}

//8 
char *mystrcpy(char s1[],  char s2[]){
   int i;
   for (i=0;s2[i];i++){
       s1[i]=s2[i];
   }
   s1[i]='\0'; 
     return s1;
}

//9 
int mystrcmp(char s1[], char s2[]){
    int i;
    for (i = 0; s1[i] == s2[i] && s1[i]; i++);
    return s1[i]-s2[i];
}


//10 
char *mystrstr (char s1[], char s2[]){
    int i,j;
    j = 0;
    for (i = 0; s1[i] && s2[j]; ++i)
    {
        if (s1[i] == s2[j]) ++j;
        else j = 0;
    }
    if (s2[j] == '\0') return s1 + (i-j);
        else return NULL;
}


//11 
void strrev (char s[]){
    int i,j;
    char guarda;
    for(i=0;s[i];i++);//percorrer até ao final
    i--;
    for(j=0;j<i;j++){
        guarda=s[j];
        s[j]=s[i];
        s[i]=guarda;
        i--;
    }
}


//12 
int vogais (char c){
   int i;
   char vogais[10]={'a','e','i','o','u','A','E','I','O','U'};
    for(i=0;i<10;i++){
        if (c==vogais[i]) return 1;
     }
  return 0;
    }

void strnoV (char t[]){
   int j,r;
   for (j=0;t[j];j++){
        if (vogais(t[j]))  {
        for (r=j;t[r];r++){
        t[r]=t[r+1];}
        j--;//porque se for vogal vai ter que ficar na mesma posicao para analisar a nova letra que pusemos lá
    }   
}
       
   }


//13 
void truncW (char t[], int n){
    int i,j,k=0;
    for(i=0;t[i];i++){
        if (isspace (t[i])) k=0;
        else if (k<n) k++;
        else { 
            for(j=i;t[j];j++){
            t[j]=t[j+1];}
            i--;
        }
}
}
//14 
int conta(char a,char s[]){
    int conta1=0,i;
    for (i=0;s[i];i++){
    if (s[i]==a) conta1= conta1+1;}
    return conta1;
}

char charMaisfreq (char s[]) {
  int i,max=0,conta1=0;
  char a;
    for(i=0;s[i];i++){
      max=conta(s[i],s);
      if (conta1<max) {conta1=max;a=s[i];}
        }
return a;
    
}


//15 
int iguaisConsecutivos (char s[]) {
    int max=1,resultado=0,i;
     for (i = 0; s[i]; i++){
        if (s[i]==s[i+1]) max=max+1;
       
  else if (max>resultado) {resultado=max;max=1;}
}
    return resultado;
}

//16 
int antes (char *s,int a,int b){
	int encontrado=0;
	while(a<b && !encontrado){
		if (s[a]==s[b]) encontrado=1; a++;
	}
return encontrado;
}

int difConsecutivos(char s[]){
	int conta=0,i=0,j,max=0;
	if(s[i]=='\n') return 1;
	while(s[i]){
	    j=i;
	        while(s[j] && !antes(s,i,j)){
			    conta++;j++;
		    
	}
	if (s[j]){
		if(conta>max) max=conta;conta=0;}
            i++;
    }
return max;
}

//17 
int maiorPrefixo (char s1 [], char s2 []) {
    int i;
    for(i=0;s1[i] && s2[i] && s1[i]==s2[i];i++);
    return i;
}


//18 
int maiorSufixo(char s1[], char s2[])
{
	int i1 = strlen(s1) - 1, i2 = strlen(s2) - 1, soma = 0;
	while (i1 >= 0 && i2 >= 0 && s1[i1] == s2[i2])
	{
		i1--;
		i2--;
		soma++;
	}
	return soma;
}

//19 
int sufPref (char s1[], char s2[]) {
    int i, j=0, contador = 0;
    for (i = 0; s1[i]; i++) {
        if (s1[i] == s2[j]) {
            contador++;
            j++;
        } else {
            contador = 0;
            j = 0;
        }
    }
    return contador;
}



//20 
int contaPal(char s[]){
    int i, conta=0;
    for (i = 0; s[i]; i++)
    {
        if (!isspace(s[i]) && s[i + 1]=='\0')//para contar a ultima palavra      
            conta=conta+1;
        
        else if (!isspace(s[i]) && isspace(s[i + 1]))//para contar quando passa de uma para a outra
            conta=conta+1;
    }
    return conta;
}


//21 
int contaVogais (char s[]){
    int i, conta=0;
    for (i = 0; s[i]; i++){
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') conta++;
    }
    return conta;
}

//22 
int contida (char a[], char b[]) {
    int i,j,flag=1;
    for(i=0;a[i] && flag;i++){
        flag=0;
        for(j=0;b[j];j++){
            if (a[i] == b[j]) flag=1;
        }
    }
    return flag;
}

//23 
int palindroma (char s[]){
	int i = 0, j = strlen(s) - 1;
	while (i < j)
	{if (s[i] != s[j])return 0;i++;j--;}
	return 1;
}

//24 
int remRep (char texto []) {
    int i,j;
    for(i=0;texto[i];i++){
        if(texto[i]==texto[i+1]){
    for(j=i;texto[j];j++){
        texto[j]=texto[j+1];}
    i--;
    }
 }
return strlen(texto);
}
//25 
int limpaEspacos (char texto[]) {
    int i=0,j=0;
    for(;texto[i];i++){
        if (isspace(texto[i]) && isspace(texto[i+1])){
            for (j=i;texto[j];j++){
                texto[j]=texto[j+1];
            }
            i=i-1;
        }
    }
    return strlen(texto);
}

//26 
void insere (int s[], int N, int x){
    int i,j=N;
    while(s[j - 1] > x && j > 0){
        s[j] = s[j - 1];
        j--;
    }
    s[j] = x;
}

//27 
  void merge(int r [], int a[], int b[], int na, int nb)
{
  int ia = 0, ib = 0, ir = 0;
  while (ia < na && ib < nb)
    if (a[ia] < b[ib])
      r[ir++] = a[ia++];
    else
      r[ir++] = b[ib++];
  while (ia < na)
    r[ir++] = a[ia++];
  while (ib < nb)
    r[ir++] = b[ib++];
}


//28 
int crescente (int a[], int i, int j){
      for(i=0;i<j;i++){
           if(a[i] > a[i+1])
           return 0;
           }
       return 1;
   }

//29 
int retiraNeg (int v[], int N){
    int i, w = 0;

    for (i = 0; i < N; i++)
        if (v[i] > 0) v[w++] = v[i];
    
    return w;
}

//30 
int menosFreq (int v[], int N){
    int i, conta, min, elem;
    conta = 1;
    elem = v[0];
    for (i = 0; i < N; i++){
        if (v[i] == v[i + 1])
            conta ++;
        else {
            if (conta < min){
                min = conta;
                elem = v[i];
            }
            conta = 1;
        }
    }
    return elem;
}

//31 
int maisFreq (int v[], int N){
    int i, conta, max, elem;
    max = 0;
    conta = 1;
    elem = v[0];
       
    for (i = 0; i < N; i++){
        if (v[i] == v[i + 1]){
            conta++;
            if (conta > max){
                max = conta;
                elem = v[i];
            }
       }    
        else conta = 1;    
    }
    return elem;
}

//32 
int maxCresc (int v[], int N) {
       int i,conta=1,max=0;
       for(i=0;i<N;i++){
           if(v[i]<= v[i+1]){ 
               conta++;
           if(conta>max) max=conta;
           }
           else conta=1;
       }
       return max;
   }

//33  
int elimRep (int v[], int n) {
      int i,j,k;
      for(i=0;i<n;i++){
          for(j=i+1;j<n;j++){
              if(v[i]==v[j]){
         for(k=j;k<n;k++){
             v[k]=v[k+1];
         }
          
             j--;
             n--;                  
              }
        }
      }
   return n;
   }


//34 
int elimRepOrd(int v[], int N){
  int final = 0,i;
  for ( i = 0; i < N; ++i)
    if (i==0 || v[i] != v[i-1])
      v[final++] = v[i];
  return final;
}

//35 
int comunsOrd(int a[], int na, int b[], int nb)
{
    int ra=0, rb=0, comuns=0;
    while (ra < na && rb < nb)
        if (a[ra] > b[rb])
            rb=rb+1;
else if (a[ra] == b[rb]){
            ra=ra+1;
            rb=rb+1;
            comuns=comuns+1;
        }
else ra=ra+1;
return comuns;
}

//36 
int comuns(int a[], int na, int b[], int nb){
    int ra=0, rb=0, comuns=0,encontrado=0;
    while(ra<na){
            rb=0;	//para voltar ao inicio de rb;
            encontrado=0;
        while (rb<nb && !encontrado){
            if (a[ra] == b[rb])  {comuns++; encontrado=1;}
    else rb++;
        } 
    ra++;
}
    return comuns;
    }

//37 
int minInd (int v[], int n) {
int i,indice=0,elemento=v[0];
  for(i=1;i<n;i++){
       if(v[i]<elemento){
           elemento=v[i];
           indice=i;
       }
  }
return indice;
}



//38 
void somasAc (int v[], int Ac [], int N){
    int i,k=0;
     for (i=0;i<N;i++){
        k=k+v[i];
        Ac[i]=k;
        }
 }


//39 
int triSup(int N, float m[N][N]){
	int l,c;
	for (l = 0; l < N; l++)
		for (c = 0; c < l; c++)
			if (m[l][c] != 0) return 0;
	return 1;
}


//40 
 void transposta (int N, float m [N][N]) {
   int guarda,l,c;
    for (l=0;l<N;l++)
        for(c=l;c<N ;c++){
            guarda=m[l][c];
            m[l][c]=m[c][l];
            m[c][l]=guarda;
        } 
}

//41 
void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int l,c;
    for (l=0; l<N; l++)
        for (c=0; c<M; c++)
            a[l][c] =a[l][c]+ b[l][c];
}

//42 
   int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
        for(i=0; i<N; i++)
            r[i] = (v1[i] || v2[i]);
    return 0;
}

//43 
 int intersectSet(int N, int v1[N], int v2[N], int r[N]){
 int i;
    for (i = 0; i < N; i++)
        r[i] = (v1[i] && v2[i]);
    return 0;
}

//44 
int min(int x,int y){
    if(x<y) return x;
    else return y;
}
int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
       int i;
       for(i=0;i<N;i++)
       r[i]=min(v1[i],v2[i]);
   }

//45 
int max(int x,int y){
	if (x>y) return x;
	else return y;
}

int unionMSet(int N, int v1[N], int v2[N], int r[N]){
	int i;
	 for (i=0;i<N;i++)
	 	r[i]=max(v1[i],v2[i]);
}

//46
int cardinalMSet(int N, int v[N])
{
	int i,soma = 0;
	for (i = 0; i < N; i++)
		soma =soma+ v[i];
	return soma;
}

//47 
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {int x, y;} Posicao;


Posicao posFinal(Posicao inicial, Movimento mov[], int N){
 int i;
    for(i = 0; i < N; i++)
        if (mov[i] == Norte) 
            	inicial.y++;
        
        else if(mov[i] == Sul)
            	inicial.y--;
        
        else if(mov[i] == Este)
           		inicial.x++;
        
		else inicial.x--;
    return inicial;
}
//48 
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {int x, y;} Posicao;

int caminho(Posicao inicial, Posicao final, Movimento mov[], int N){
int i=0;
	while (inicial.x != final.x || inicial.y != final.y)
	{ 
		if (i==N) return -1;
		if (inicial.x<final.x) {mov[i]=Este;i++;inicial.x++;}
		else if (inicial.x>final.x) {mov[i]=Oeste;i++;inicial.x--;}
		else if (inicial.y<final.y) {mov[i]=Norte;i++;inicial.y++;}
		else if(inicial.y>final.y) {mov[i]=Sul;i++;inicial.y--;}
}
return i;
}

//49 
typedef struct posicao {int x, y;} Posicao;

int maiscentral (Posicao pos[], int N) {

int menor= abs (pos[0].x) +abs (pos[0].y);
int indice=0,i,guarda;
    for(i=1;i<N;i++){
    guarda=abs (pos[i].x) + abs (pos[i].y);
    if (guarda<menor) {menor=guarda;indice=i;}
    }
return indice;
}

//50 
typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {int x, y;} Posicao;

int vizinhos(Posicao p, Posicao pos[], int N)
{
    int i,soma=0;
    for(i=0; i<N; i++)
    {
        if (p.x == pos[i].x)
            if (p.y == pos[i].y + 1 || p.y == pos[i].y -1)
                soma=soma+1;
            else;
        
        else if(p.y == pos[i].y)
            if (p.x == pos[i].x + 1 || p.x == pos[i].x - 1)
                soma=soma+1;
    }
    return soma;
}






