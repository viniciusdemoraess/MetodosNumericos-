#include<stdio.h>
#include<stdlib.h>
#include <math.h>

float L = 5 ,C = 0.0001 ,t =0.05 ; 

//calcula o valor da equacao
float CalculaQ(float R){
	float raiz = 0, expoente = 0;
	expoente = -1*((R*t)/(2*L));
	raiz = (sqrt(1/(L*C)) - pow(R/(2*L),2) )*t;
	return (exp(expoente)*cos(raiz) - 0.01); 
}

int main (){
	float Xr=0,x=0,y=0, pr = 0, result = 0, Xr2=0;

	printf("Digite um numero para R1: ");
 	scanf("%f",&x);
 	printf("Digite um numero para R2: ");
  	scanf("%f",&y);
	if(CalculaQ(x) * CalculaQ(y) == 0){
		if(CalculaQ(x) == 0){
			printf("Raiz encontrada: %.4f", x);
		}else{
			if(CalculaQ(y) == 0){
				printf("Raiz encontrada: %.4f", y);
			}else{
				printf("Raiz encontrada: %.4f e %.4f", x, y);
			}
		}	
		exit(1);
	}else if(CalculaQ(x) * CalculaQ(y) > 0){
		printf("Raiz nao esta nesse intervalo, tente novamente" );
		exit(1);
	}else{
		do{
			Xr = (x + y)/2;
			result = CalculaQ(x) * CalculaQ(Xr);
			printf(" Result = %f\n", result);
			printf("Xr = %f || Precisao = %.10f  \n",Xr, pr);
			if(result < 0){
				y = Xr;
			}
			if(result > 0){
				x = Xr;
			}
			if(result == 0){
				printf("Raiz encontrada: %.4f", Xr);
				exit(1);
			}
			pr = fabs((Xr-Xr2)/Xr)*100; 
			Xr2 = Xr;		
		}while( pr >= 0.000000001);
	}	
	printf("Valor da Resistencia: %.4f \n" ,Xr);
	return 0 ;
}
