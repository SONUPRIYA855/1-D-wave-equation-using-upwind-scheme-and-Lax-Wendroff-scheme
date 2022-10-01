#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int i,j,m,k;
float u[201][5],u10[201][5],u25[201][5],u40[201][5],l[5],temp[201][5];
FILE *fp1,*fp2,*fp3,*fp4,*fp5;
fp1=fopen("G1.txt","w");
fp2=fopen("G2.txt","w");
fp3=fopen("G3.txt","w");
fp4=fopen("G4.txt","w");
fp5=fopen("G5.txt","w"); l[0]=0.2;l[1]=0.8;l[2]=0.9;l[3]=1.0;l[4]=1.1;
for(k=0;k<5;k++)
{
for(i=0;i<=200;i++)
{
if(i<=100)
u[i][k]=0;
else
u[i][k]=1;
temp[i][k]=u[i][k];
}
for(m=1;m<=40;m++)
{
for(i=1;i<=200;i++)
{
u[i][k]=temp[i][k]-(0.5*l[k]*(temp[i+1][k]-temp[i- 1][k]))+(0.5*l[k]*l[k]*(temp[i+1][k]-(2*temp[i][k])+temp[i-1][k]));
if(m==10)
{
u10[i][k]=u[i][k];
}
else if(m==25)
{
u25[i][k]=u[i][k];
}
else if(m==40)
{
u40[i][k]=u[i][k];
}
}
for(i=1;i<=200;i++)
temp[i][k]=u[i][k];
}
}
for(i=0;i<201;i++)
{
fprintf(fp1,"%d\t%f\t%f\t%f \n",i,u10[i][0],u25[i][0],u40[i][0]);
fprintf(fp2,"%d\t%f\t%f\t%f \n",i,u10[i][1],u25[i][1],u40[i][1]);
fprintf(fp3,"%d\t%f\t%f\t%f \n",i,u10[i][2],u25[i][2],u40[i][2]);
fprintf(fp4,"%d\t%f\t%f\t%f \n",i,u10[i][3],u25[i][3],u40[i][3]);
fprintf(fp5,"%d\t%f\t%f\t%f \n",i,u10[i][4],u25[i][4],u40[i][4]);
}
fclose(fp1); fclose(fp2); fclose(fp3); fclose(fp4); fclose(fp5); return 0;
}
