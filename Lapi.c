#include<stdio.h>
#include<math.h>
#define nb 2

void Jacobi(float tab[][nb],int ligne,float X[],int ligneX,float B[],int ligneb)
{
    float D[nb][nb]={0};
    float E[nb][nb]={0};
    float H[nb][nb]={0}; //D^(-1)*(E+F)
    float C[nb]={1,1,1}; //D^(-1)*B
    float Bi[nb]={0};
    float temp[nb]={0};
    float temp2[nb]={0};
    float temp3[nb]={0};
    int i,j;
    float f,g; //f est la valeur de la norme de X a K iteration et g a K+1
    g=normeVecteur(B,nb);
    f=0;
        printf("matrice D: \n");
        afficheM(D,nb);
    for(i=0;i<nb;i++) //on va utilisér Bi=-B pour le calcule des normes
    {
        Bi[i]=(-1)*B[i];
    }
    printf("matrice -B: \n");
    afficheMC(Bi,nb);
    for(i=0;i<nb;i++)
    {
        for(j=0;j<nb;j++)
        {
            if(i==j)
            {
                D[i][j]=1/tab[i][j];
            }
            else
            {
                E[i][j]=tab[i][j]*(-1);
            }

        }

    }//les deux matrice obtenue par sont D^(-1) et (E+F)
        printf("matrice D: \n");
        afficheM(D,nb);
        printf("matrice E((D+F): \n");
        afficheM(E,nb);
    Multm(D,nb,E,nb,H,nb);
    Mult(D,nb,B,nb,C,nb);
    while(f<g)
    {
        Mult(H,nb,X,nb,temp,nb);
        sommeM(temp,nb,C,nb,X,nb); //on determine ici une autre valeur de x.
        printf("je suis passer la !\n");
        f=g;
        Mult(tab,nb,X,nb,temp2,nb);
        sommeM(temp2,nb,Bi,nb,temp3,nb);
        g=normeVecteur(temp3,nb);
    }

}

int normeVecteur(float b[], int a)
{
    int i;
    float x=0;
    for(i=0;i<nb;i++)
    {
        x=x+ b[i]*b[i];
    }
    return sqrtf(x);
}
void Multm(float mat1[][nb],int n,float mat2[][nb],int m,float mul[][nb],int lignec)
{
	int i;
	int j;
	int k;
	for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++)
    {
      mul[i][j]=0;
      for(k = 0; k < m; k++)
      {
        mul[i][j] += mat1[i][k] * mat2[k][j];
      }
    }
  }
}




void Mult(float mat1[][nb],int n,float mat2[],int m,float mul[],int lignec)
{
	int i;
	int j;
	int k;
	for(i = 0; i < n; i++)
  {
    for(j = 0; j < m; j++)
    {
      mul[j]=0;
      for(k = 0; k < m; k++)
      {
        mul[j] = mul[j]+ mat1[i][k] * mat2[k];
      }
    }
  }
}

void sommeM(float mat1[],int n, float mat2[],int a,float s[],int b)
{
    int k;
    for(k=0;k<n;k++)
    {
        s[k]=0;
        s[k]=mat1[k]+mat2[k];
    }
}

void afficheM( float Mat1[][nb], int ligne)
{
    int i,j;
    for(i=0;i<nb;i++)
    {
        for(j=0;j<nb;j++)
        {
            printf("%f"    ,Mat1[i][j]);

        }
        printf("\n");
    }

}

void afficheMC( float Mat1[], int ligne)
{
    int i,j;
    for(i=0;i<nb;i++)
    {
            printf("%f\n"    ,Mat1[i]);
    }

}

int main()
    {

        float tab[2][2]={{1,0},{0,1}};
        float taba[2][2]={{1,0},{6,2}};
        float b[nb]={1,8};
        float x[nb]={1,1};
        Jacobi(tab,nb,x,nb,b,nb);
        afficheMC(x,nb);
        return 0;

    }
