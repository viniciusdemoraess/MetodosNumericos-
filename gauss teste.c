#include <stdio.h>
#include <stdlib.h>
#define N 3 //O numero de equações (linhas do sistema linear)

void main (){
    int i, j, k;
    float fator, soma;
    float X[N];

    // Valores pré definidos
    float M[N][N+1] = {{4, 1, 2, 7},{1, 7, 3, 19},{3, 2, 10, 71}};


    //Caso queira incluir os dados na matriz
    /*
    float a11, a12, a13, b1, a21, a22, a23, b2, a31, a32, a33, b3;
    float M[N][N+1] = {{a11,a12,a31,b1},{a21,a22,a23,b2},{a31,a32,a33,b3}};

    for(i = 0; i<N; i++){
      for(j = 0; j<=N; j++){
        printf("\n Atribua valores a matriz: ");
        scanf("%f", &M[i][j]);
      }
      printf("\n");
    }
    */

    //Mostra na tela a matriz inicial
    for(i = 0; i<N; i++){
        for(j = 0; j<=N; j++){
            printf("|%.3f|", M[i][j]);
        }
        printf("\n");
    }

    // Eliminação progressiva
    for(k = 0; k<N-1; k++){ // Laço exterior se refere a coluna pivô que se altera. (linha pivo ou equacao pivô = equacao referencial para as eliminações)
        for(i = (k+1); i<N; i++){ // Este laço se refere as linhas que sofrerão as eliminações, que sempre iniciarão na linha seguinte da linha pivô
            fator = M[i][k] / M[k][k]; // Fator de correção que será multiplicada pela linha pivô
            for(j=0; j<=N; j++){//laço interno se refere a cada coluna da linha que sofrerão modificações da linha i
                M[i][j] = M[i][j] - fator*M[k][j];
            }
        }
    }

    X[N-1] = M[N-1][N] / M[N-1][N-1]; // Primeria variavel que obtamos
    
    //Mostra a matriz depois da eliminação progressiva
    printf("\n");
    for(i = 0; i<N; i++){
        for(j = 0; j<=N; j++){
            printf("|%.3f|", M[i][j]);
        }
        printf("\n");
    }

    // Substituição progressiva
    for(i=N-2; i>=0; i--){  //Laço exterior se refere a linha que receberá os valores das variaveis já encontradas para descobrirmos as outras. Ela se inicia na penúltima linha e vai ate a primeira
        soma = 0;
        for(j=(i+1); j<N; j++){     //Laço interno se refere as colunas da linha i
            soma = soma + M[i][j]*X[j]; // soma todos os numeros da linha que ja tem o valor de x
        }
        X[i] = (M[i][N] - soma)/M[i][i]; // Calcula o x da coluna i
    }

    printf("\nResultado: " );
    for(i=0; i<N; i++)
         printf("\nX%d = %f\n", i+1, X[i]);

}

/*

Resultado da base do alg:
X1 = 3.000000

X2 = -2.500000

X3 = 7.000000

Resultado:

{4, 1, 2, 7},
{1, 7, 3, 19},
{3, 2, 10, 71}

X1 = -2.059908

X2 = -0.327189

X3 = 7.783411

*/
