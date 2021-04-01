//Metodo de Newton
//metodo aberto->recebe a aproximação inicial
//método iterativo para encontrar a raiz da função


#include<stdio.h>
#include<stdlib.h>
#include <math.h>

double f(double x){
    //return (pow(x,4)-2*pow(x,3)+ 4*x-16);          //isso tudo de função foram testes para tentar compreender e ver se funcionava
    //return 3*x + sin(x)-pow(2.71828,x);
    //return x*log10(x)-1.2;
    return (pow(x,3)-9*x +3);
}
double df(double x){
    // return (4*pow(x,3)-6*pow(x,2)+4);
    // return 3.0 + cos(x)-pow(2.71828,x);
    //return log10(x) + 0.43429;
    float h=0.000000001;
    return (f(x+h)-f(x))/h;   /* essa é uma função que calcula a derivada.
                                 LEIA COM A VOZ DO WILLIAM : "isso é conceito de calculo 1" */
} 

int main (){
    double tol=0.0001, imax=20;
    double x,x1,fx,fx1,a;
    //tentei usar float, mas não deu, talvez seja por conta da precisão
    int i=0;
    printf("digite a aproximacao inicial: ");
    scanf("%lf",&x1);
    //assim que se faz o scanf para varivel double, com esse lf e na impressão também se usa

    printf("iteracao     x(i)                 x(i+1)                 f(x) \n\n");
   do{
        x=x1;             //torna x igual ao ultimo valor calculado de x1
        fx=f(x);            
        fx1=df(x);
        x1=x-(fx/fx1);         //aqui acontece o método propriamente dito


       // a=(fabs(x1-x)) isto é visualmente esta representação-> |x(i+1)-x(i)|. Ainda estou tentando entender para que serve

        printf("%d\t  %.9lf\t\t  %.9lf\t\t  %.20lf\t\t \n",i,x,x1,fx);
        i++;

    } while (fabs(x1-x)>=tol);       /*em alguns exemplos que peguei estava apenas fabs(x1) o que eu entendi o motivo.
                                       porém ainda sigo tentando entender o pq que tem que ser fabs(x1-x).
                                       Se nao estiver fabs(x1-x) dá loop infinito e apenas fabs(x1)*/
    
    printf("\n Raiz da equacao: %.9lf",x1);

    return 0;
}
