#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"prac2funs.h"

double datajuliana(int,int,int);

int main(void){
	int i=0,j, n[4]={6,9,12,15};
	double *temps, *x, *y, *z,*subt,*subv,test=2462225.5;
	FILE *fin;
	fin=fopen("dades_apophis.dat","r");
	if(fin==NULL){
		return 1;
	}
	temps=(double*)malloc(414*sizeof(double));
	x=(double*)malloc(414*sizeof(double));
	y=(double*)malloc(414*sizeof(double));
	z=(double*)malloc(414*sizeof(double));
	if(x==NULL || y==NULL || z==NULL || temps==NULL){
		return 2;
	}
	do{
		fscanf(fin,"%lf %lf %lf %lf", &temps[i], &x[i], &y[i], &z[i]);
		i++;
	}while(!feof(fin));
	for(i=0;i<4;i++){
		subt=(double*)malloc((n[i]+1)*sizeof(double));
		subv=(double*)malloc((n[i]+1)*sizeof(double));
		for(j=413;j>=413-n[i];j--){
			subt[n[i]-(413-j)]=temps[j];
			subv[n[i]-(413-j)]=x[j];
			printf("%e %e %e %e\n",temps[j],x[j],y[j],z[j]);
		}
		printf("n=%d\n",n[i]);
		for(j=0;j<=n[i];j++){
			printf("t[%2d]=%.1f x[%2d]=%+.8e\n",j,subt[j],j,subv[j]);
		}
		dif_dividides(subt,subv,n[i]);
		printf("**********************\n");
		printf("Els coeficients del polinomi de grau %d per x(t) son\n",n[i]);
		for(j=0;j<=n[i];j++){
			printf("dd[%2d]=%+.8e\n",j,subv[j]);
		}
		printf("n=%d x(2462225.5)=%+.8e\n",n[i],aval(subt,subv,n[i],test));
		printf("**********************\n");
		free(subt);
		free(subv);
	}	
	return 0;
}

double datajuliana(int dia,int mes,int any){
	int a,m,y;
	double D;
	a=(14-mes)/12;
	m=mes-12*a-3;
	y=any+4800-a;
	D=dia+(153.*m+2.)/5.+365.*y+(y/4.)-(y/100.)+(y/400.)-32045;
	return D;
}
