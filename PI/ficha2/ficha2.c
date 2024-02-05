#include <stdio.h>

//ex1
float multInt (int n,float m){
float r;
if (n>0) {
for (r=0;(n>0);n--)
	r=r+m;
}
 else for (r=0;(n<0);n++)
	r=r-m;
{printf("%f \n",r);return r;}
}

//ex2
float multInt2 (int n,float m){
float r;
r=0;
if (n>0)
while (n!=0) {
	n=n/2 ; m=m*2;
	if (n%2!=0) 
	r=r+m;
}
else r=r-m; //nas linhas impar quando o n<0 
{printf("%f \n",r);return r;}
} 

//ex3
int mdc(int a,int b){
int i,divisor;
for (i=1;(i<=a)&&(i<=b);i++){
if((a%i==0) && (b%i==0)) 
divisor=i;
{printf("MDC: %d\n",divisor);return divisor;}
}
}


//ex4
int mdc1 (int a,int b){ 
if (a==b)
		{printf("MDC: %d\n",a);return a;}
	else if (a>b)
		return mdc(a-b,b);
	 else return mdc(a,b-a);
}

//ex5
int mdc2(int a,int b){
int resto;
while (b != 0){
	resto = a%b;//resto da divisao de a por b até ser 0 para acabar o ciclo	
	a=b; 
	b=resto;
				}
{printf ("MDC: %d\n",a);return a;}
}





int main () {
//multInt(-2,2);
//multInt2(2,-2);
mdc (2,10);
//mdc1(2,10);
//mdc2(120,16);
return 0;
}