#include <stdio.h>
#include <math.h>
#define ERROR 0.001
#define N 3

void main (){
 int i, j;

    float A[N][N]   = {{10, -1, 1},
                       {1, -10, -1},
                       {1, 1, -5}};

    float b[N][1]  = {{-2},
                      {2},
                      {4}};

    float x[N][1] = {{0},
                     {0},
                     {0}};

    float xAntigo[N][1] = {{0},
                          {0},
                          {0}};

    float xError[N][1] = {{0},
                        {0},
                        {0}};

    int erro = 0;

    do {
        for (i = 0; i < N; i++) {
            float s = 0;

            for (j = 0; j < N; j++) {
                if (j != i)
                    s = s + A[i][j]*x[j][0];
            }
            x[i][0] = ((b[i][0] - s)/ A[i][i]);
        }
        //criterio da convergencia
        for (i = 0; i<N; i++){
            xError[i][0] = (fabs((x[i][0]- xAntigo[i][0]) / x[i][0])) * 100;
            if (xError[i][0] >= ERROR){
                erro = 1;//erro como uma questão de parada
            }else{
                erro = 0;
            }
            xAntigo[i][0] = x[i][0];
        }

        printf("\n");

        for (i = 0; i <N; i++){
           printf("X%i = %f\t |Er| = %f\n",i+1, x[i][0], xError[i][0]);
        }

    } while (erro != 0);

}
