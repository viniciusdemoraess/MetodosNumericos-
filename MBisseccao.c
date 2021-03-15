#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include<time.h>

//calcula o valor da equacao
float CalculaQ(float R){
	float raiz = 0, expoente = 0;
	expoente = -1*(R*0.005);
	raiz = (sqrt(2000 - 0.01*pow(R,2))*0.05);
	return (exp(expoente)*cos(raiz) - 0.01); 
}

int main (){
	float Xr=0,x=0,y=0, er = 0, pr = 0.000001, result = 0, Xr2=0;
	int i=1;

	printf("Digite um numero para R1: ");
 	scanf("%f",&x);
	 //srand(time (NULL));       //função para os números aleatorios
	 //x=rand()%22080 +(-10);    //usei como parametro o primeiro intervalo que encontrou raiz
 	// x=rand();               //mas caso não queira usar o intervalo específico acima, usa essa linha
	// printf("valor de x: %.f \n", x);
 	printf("Digite um numero para R2: ");
  	scanf("%f",&y);
	//y=rand()%350+(-10);
	//y=rand();
	//printf("valor de y: %.f \n", y);


	/*if(CalculaQ(x) * CalculaQ(y) == 0){ 
		if(CalculaQ(x) == 0){
			printf("Raiz encontrada: %.4f", x);
		}else{
			if(CalculaQ(y) == 0){
				printf("Raiz encontrada: %.4f", y);
			}else{
				printf("Raiz encontrada: %.4f e %.4f", x, y);
			}
		}	
		exit(1); */
	if(CalculaQ(x) * CalculaQ(y) >= 0)
	{
		printf("Raiz nao esta nesse intervalo, tente novamente" );
		exit(1); 
	}else {        //bolzano
		printf("\n INTERACAO\t\tX\t\tY\t\tXR\t\tPRECISAO\n");
		do{
			
			Xr = (x + y)/2;
			result = CalculaQ(x) * CalculaQ(Xr);
			//printf(" Result = %f\n", result);
			//printf("Xr = %f || Precisao = %.10f  \n",Xr, pr);
			
			printf("%d \t\t%f\t%f\t%.4f\t%.10f\n",i,x,y,Xr,result);
			if(result < 0){
				y = Xr;
			}
			if(result > 0){
				x = Xr;
			}
			/*if(result == 0){
				printf("Raiz encontrada: %.4f", Xr);
				exit(1);
			} */
			//calculo do erro 
			er = fabs((Xr-Xr2)/Xr)*100; 
			Xr2 = Xr;
			i++;
			//condicao de parada: tanto o erro, quanto o valor de x e y na equacao tem q se aproximar da precisao estabellecida 
		}while(  er >= pr|| CalculaQ(x)>= pr || CalculaQ(y)>= pr );   //alterei para 6 zeros de precisão, antes estava 0,00000000001
	}	
	printf("Valor da Resistencia: %.4f \n" ,Xr);
	return 0 ;
}


/* HISTÓRICO DE TESTES
 
   X       Y        RESISTENCIA      PRECISÃO
22070      340       483,3051        0.0000063144
1472       172       240,4426        0.0000063461
1470       170       780,8721        0,0000078163
8976       286       470.1402        0.0000064912           
26988      48        629,8417        0.0000096906 
1472       172       381.7183        0.0000079948                            
28000	   22486	 659,0326        0.0000092613
28620	   299	     577,9081        0.0000105614
29238	   132		 588,6627        0.0000103684			    


30876      79         483,305054     
*/