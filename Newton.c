//Metodo de Newton
//metodo aberto->recebe a aproximação inicial
//método iterativo para encontrar a raiz da função


#include<stdio.h>
#include<stdlib.h>
#include <math.h>

double f(double x){
    return (pow(x,3)-9*x +3);
}
double df(double x){
    float h=0.000000001;
    return (f(x+h)-f(x))/h;   /* essa é uma função que calcula a derivada.*/
} 

int main (){
    double tol=0.0001, imax=20;
    double x,x1,fx,fx1,a;
    int i=0;
    printf("digite a aproximacao inicial: ");
    scanf("%lf",&x1);

    printf("iteracao     x(i)                    f(x) \n\n");
   do{
        x=x1;             //torna x igual ao ultimo valor calculado de x1
        fx=f(x);            
        fx1=df(x);
        x1=x-(fx/fx1);         //aqui acontece o método propriamente dito


        printf("%d\t  %.9lf\t\t   %.20lf\t\t \n",i,x,fx);
        i++;

    } while (fabs(fx)>=tol);   //ponto de parada
    
    printf("\n Raiz da equacao: %.9lf",x1);

    return 0;
}
