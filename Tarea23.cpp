#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main (void)
{
  int i,j,dominante=0,c=1;
  int arr[5][5];
  int n=4;

  arr[0][0]=1;
  arr[0][1]=10;
  arr[0][2]=2;
  arr[0][3]=300;

  arr[1][0]=1;
  arr[1][1]=10;
  arr[1][2]=4;
  arr[1][3]=5;

  arr[2][0]=3;
  arr[2][1]=9;
  arr[2][2]=2;
  arr[2][3]=1;

  arr[3][0]=3;
  arr[3][1]=9;
  arr[3][2]=2;
  arr[3][3]=2;


  printf("\nImprimiendo la matriz:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d \t",arr[i][j]);
    }
    printf("\n");
  }


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
        printf("%i \t",arr[i][j]);
      }
    }
    printf("\n");
  }

  //Comparando diagonal
  int ren;

  for(i=0;i<n;i++)
  {
    ren=0;
    for(j=0;j<n;j++)
    {
      if (i!=j)
      {
        ren= ren + arr[i][j];

      }
    }

    if(ren>arr[i][i])
    {
      printf("\nRenglon %i NO es dominante.\n",i);
    }
    else
    {
      printf("\nRenglon %i SI es dominante.\n",i);
    }

  }

  int renc, renc2,b,aux;

  //Combirtiendola en diagonal Dominante
  for(i=0;i<n;i++)
  {
    renc=0;
    for(j=0;j<n;j++)
    {
      if (i!=j)
      {
        renc= renc + arr[i][j];
      }
    }

    b=0;
    if(renc>arr[i][i])//El renglon no cumple así que se cambia orden
    {
      for(int l=0;l<n;l++)//Este for solo es para que se repitan las lineas la n cantidad de veces.
      {//Aquí se hacen todas las posibles combinaciones para ver cual digito es el que iria en la diagonal
        renc2=0;
        aux=0;
        for(int k=0;k<n;k++)
        {
          if(k!=b)
            renc2= renc2 + arr[i][k];
        }

        if(arr[i][b]>renc2)
        {
          aux=arr[i][i];
          arr[i][i]=arr[i][b];
          arr[i][b]=aux;
          printf("\n Se cambió el renglon %i.\n",i);
        }

        if(b==n)
        {
          printf("\nNo hay forma de acomodar el renglón %i para que sea dominante.\n",i);
        }
        b++;
      }
    }

  }

  printf("\nImprimiendo la matriz nueva:\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("%d \t",arr[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}
