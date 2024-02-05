#include <stdio.h>


int main (int argc, char *argv[]){
FILE *input;
Dicionario d1;
int r=0, count=0;
initDic(&d1);
char word[100];
if (argc==1) input=stdin;
else input=fopen(argv[1],"r");
if (input==NULL) r=1;
else {
while ((fscanf(input,"%s",word)==1))
acrescenta(&d1,word);
count ++;
fclose (input);
printf ("%s %d",maisFreq(d1,&count),count);
}
return r;
}


typedef struct entrada{
char *palavra;
int ocorr;
struct entrada *prox;
} *Palavras;



typedef Palavras Dicionario;


//1
void initDic (Dicionario *d){
	*d=NULL;
}

int acrescenta (Dicionario *d, char *pal){
	
}







char *maisFreq (Dicionario d, int *c){
	int maior=0;char *palavra;
	while(d){
	if(d->ocorr>maior){
		maior=d->ocorr;
		palavra=d->palavra;
					}
		d=d->prox;
		}
	*c=maior;
	return palavra;
}


















