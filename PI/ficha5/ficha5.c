#include <stdio.h>
#include <math.h>

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;


int nota (Aluno a){
    // 80% do teste, 20% dos mini testes
    int nota=0,total=0,final=0;
    float k=0;
    //nota do teste
    k=a.teste * 0.80;
    for(int i= 0;i<6;i++){
        if(a.miniT[i] == 0) total+=0;
        else if(a.minT[i] == 1 ) total+=10;
        else if(a.minT[i] == 2) total+=20;
    }
    if (total<5) return 0;
    final= total*0.20 + k;
    if (final<=9) return 0;
    return round(final);
}


int procuraNum (int num, Aluno t[], int N){
     int i;
     for ( i = 0; i < N; i++){
        if(num == t[i].numero) return i;
    }
    return -1;
}


int swap_aluno ( Aluno *x ,Aluno *y){
    Aluno=temp;
    temp= *x;
    *x = *y;
    *y = temp;
}



void ordenaPorNum (Aluno t [] , int N) {
    for(int i=0; i< N ; i++){
        for(int j=0;j<N-i-1;j++){
            if (t[j].numero > t[j+1].numero) swap_aluno(&t[j], &t[j+1]);
        }
    }
}



