#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>

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

	//printf("Digite um numero para R1: ");
 	//scanf("%f",&x);
	 srand(time (NULL));       //função para os números aleatorios
	 x=rand()%22080 +(-10);    //usei como parametro o primeiro intervalo que encontrou raiz
 	 //x=rand();               //mas caso não queira usar o intervalo específico acima, usa essa linha
	 printf("valor de x: %.f \n", x);
 	//printf("Digite um numero para R2: ");
  	//scanf("%f",&y);
	y=rand()%350+(-10);
	//y=rand();
	printf("valor de y: %.f \n", y);
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
	}else{        //bolzano
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


/* HISTÓRICO DE TESTES
 
   X       Y        RESISTENCIA      PRECISÃO
22070      340       483,3051        0.0000063144
1472       172       240,4426        0.0000063461
8976       286       470.1402        0.0000064912           
26988      48        629,8417        0.0000096906 
1472       172       381.7183        0.0000079948                            
28000	   22486	 659,0326        0.0000092613
28620	   299	     577,9081        0.0000105614
29238	   132		 588,6627        0.0000103684			    





*/