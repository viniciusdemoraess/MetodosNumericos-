#include<stdio.h>
#include<stdlib.h>
#include <math.h>

float L = 5 ,C = 0.0001 ,t =0.05 ; 

//calcula o valor da equacao
float CalculaQ(float R){
	return ((exp(-1*((R*t)/(2L)))*cos((sqrt(1/(L*C) - pow((R/2l),2)))*t)) - 0.01); 
}

int main (){
	int i, j; 
	float Xr=0,x=0,y=0, pr = 0.001, result = 0;

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
		while( pr > 0.0001){
			Xr = (x + y)/2;
			result = CalculaQ(x) * CalculaQ(Xr);
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
			pr = y - x;
			if(pr < 0){
				pr = -pr;
			}			
		}
	}
	
	printf("Valor da Resistencia: %.4f \n" ,Xr);
	return 0 ;
}
