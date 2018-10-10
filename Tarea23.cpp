#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int i,j;

void ImprimeMat(float arr[20][20],int n)
{
  printf("\nImprimiendo la matriz:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%f \t",arr[i][j]);
    }
    printf("\n");
  }
}

void ImprimeDiago(float arr[20][20],int n)
{
  //Imprimiendo la diagonal principal
  printf("\nImprimiendo la diagonal principal:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if (i!=j)
      {
        printf(" \t");
      }
      else
      {
        printf("%f \t",arr[i][j]);
      }
    }
    printf("\n");
  }
}

void ComparaDiago(float arr[20][20], int n, int op)
{
  //Comparando diagonal
  float ren;

  for(i=0;i<n;i++)
  {
    ren=0;
    for(j=0;j<n;j++)
    {
      if (i!=j)
      {
        ren= ren + abs(arr[i][j]);

      }
    }

    if(ren>abs(arr[i][i]))
    {
      if(op==1)
      {
        printf("\nLa matriz NO es dominante.\n");
        printf("\nSe tratara de mover la matriz.\n");
      }
      else
      {
        printf("\nLa matriz NO se pudo acomodar para volverla dominante.\n");
      }
      i=n;
      j=n;
    }

  }
}

void AcomodandoMatriz(float arr[20][20],int n)
{
  float renc, renc2,aux;
  int b,r=0;

  //Combirtiendola en diagonal Dominante
  for(i=0;i<n;i++)
  {
    renc=0;
    for(j=0;j<n;j++)
    {
      if (i!=j)
      {
        renc= renc + abs(arr[i][j]);
      }
    }

    b=0;
    r=i;
    if(renc>abs(arr[i][i]))//El renglon no cumple así que se cambia orden
    {
      for(int l=0;l<n;l++)//Este for solo es para que se repitan las lineas la n cantidad de veces.
      {//Aquí se hacen todas las posibles combinaciones para ver cual digito es el que iria en la diagonal
        renc2=0;
        aux=0;
        for(int k=0;k<n;k++)
        {
          if(k!=b)
            renc2= renc2 + abs(arr[i][k]);
        }

        if(abs(arr[i][b])>renc2)
        {
          for(i=0;i<n;i++)
          {
	           aux=arr[i][r];
	           arr[i][r]=arr[i][b];
	           arr[i][b]=aux;
          }
        }
        b++;

      }

    }

  }

  //Comparando de nuevo:
  ComparaDiago(arr,n,2);
}


int main (void)
{
  int dominante=0,c=1;
  float arr[20][20];
  int n=2;
  arr[0][0]=1;
  arr[0][1]=2;

  arr[1][0]=1;
  arr[1][1]=20;

  /*
  arr[0][0]=4;
  arr[0][1]=10;
  arr[0][2]=3;

  arr[1][0]=8;
  arr[1][1]=1;
  arr[1][2]=1;

  arr[2][0]=3;
  arr[2][1]=1;
  arr[2][2]=11;*/
  ImprimeMat(arr,n);
  ImprimeDiago(arr,n);

  ComparaDiago(arr,n,1);


  /////////////////
  AcomodandoMatriz(arr, n);

  ImprimeMat(arr,n);

return 0;
}
