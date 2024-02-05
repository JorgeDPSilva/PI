#include <stdio.h>

//1.1
void ex1 () {
int x,y;
x = 3 ; y=x+1;
x= x*y ; y = x+y;
printf ("%d %d\n",x,y);
}
/* o x começa com o valor inicial 3 , no y soma o x e guarda na variavel y o valor(3+1=4),depois ao guarda na variavel x o valor anterior do x vezes 
y(3x4=12) e na variavel y soma o valor do x(12) mais o anterior do y que é 4 ou seja 16.*/

//1.2
void ex2 () {
int x , y;
x = 0;
printf ("%d %d\n",x,y);	
}
/* no y dá um numero 32766 que guarda sempre lixo nessa variavel */ 

//1.3
void ex3 () {
char a,b,c;
a = 'A' ; b = ' ' ; c = '0';
printf ("%c %d\n",a,a);//vai retornar 'A' 65 
a= a+1 ; c= c+2 ;
printf ("%c %d %c %d\n",a,a,c,c);//vai retornar B 66 e 2 50
c=a+b;
printf("%c %d\n",c,c);// vai retornar 'b' 98
}

//1.4
void ex4 () {
int x ,y ;
x=200 ; y=100;
x=x+y ; y=x-y ; x=x-y;
printf ("%c %d\n",x,y); // vai retornar x=100 y=200
}


//1.5
void ex5 () {
int x,y;
x=100 ; y=28;
x+= y ; y-=x ;//x=128 y=-100
printf("%d %d\n",x++,y++);//x=129 y=-99
printf("%d %d\n",x,y);
}

//2a)
void ex2a () {
int x,y;
x=3 ; y=5 ;
if(x>y)
y=6;
printf ("%d %d\n",x,y);//x=3 y=5
}

//2b)
void ex2b () {
int x,y;
x=y=0;
while (x != 11) {
x=x+1 ;y=y+x;	
}
printf("%d %d\n",x,y);//x=11 y=66 (0+1,1+2,2+3,3+4,4+5....10+11)
}

//2c)
void ex2c () {
int x ,y ;
x=y=0;
while (x != 11){
x=x+2 ; y=y+x;	
}
printf ("%d %d\n",x,y);//ciclo nunca para porque x nunca vai ser 11 para parar o ciclo
}

//2d)
void ex2d (){
int i ;
for (i=0;(i<20);i++)
if (i%2 == 0) putchar ('_');
else putchar ('#');// os pares mete o char '_' os impares '#' porque o resto da divisao dos pares da 0
}

//2e)
void ex2e () {
char i , j;
	for (i='a';(i != 'h');i++) {
		for (j=i ; (j != 'h');j++)
		putchar (j);
		putchar ('\n');	
		}
} //abcdefg bcdefg cdefg defg efg fg g

//2f)
void ex2f (int n) {
while (n>0) {
	if (n%2 == 0) putchar ('0');
	else putchar ('1');
	n=n/2;
}	
putchar ('\n');
}
//int main () {
//int i ;
//for ( i =0;( i <16) ; i ++)
//f ( i ) ;
//return 0;
//}

 
//2#
void f () {
	int x,k;
	printf ("Escolha a dimensao do quadrado:\n");
	scanf("%d",&k);
	for(x=1 ; (x<(k*k)+1) ; x++)
		if (x%k == 0) {putchar('#');putchar ('\n');}
			else putchar ('#');
		}
//3#
void f3 () {
	int x,k;
	printf ("Escolha a dimensao do quadrado:\n");
	scanf("%d",&k);
	for(x=1; (x<(k*k)+1) ; x++)
		  if (x%2 == 0) //se for para mete-se underscore
		  	if(x%k == 0 ) {putchar('_'); putchar ('\n');}
		 		else putchar ('_');
	else if (x%k == 0 ){ putchar ('#');putchar ('\n');}
		else putchar ('#');
	}

//4#
void f4 (int n) {
	int x,y;
	for (x=1; x<=n; x++) {
		for (y=x; y!=0; y--)
			putchar('#');
		putchar ('\n');
};
	for (x=n; (x!=0); x--) {
		for(y=1; (y!=x) ; y++)
			putchar ('#');
     	putchar('\n');
		}
}










int main () {
//ex1 () ;
//ex2 () ;
//ex3 () ;
//ex4 () ;
//ex5 () ;
//ex2a () ;
//ex2b () ;
//ex2c () ;
//ex2d () ;
//ex2e () ;
//int i;
//for (i=0;(i<16);i++)
//ex2f (i);
f ();
//f3();
//f4(5);
return 0;
}
