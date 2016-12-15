/*COGNOM1:Bergantiños 
COGNOM2: Yeste
NOM: Angel
DNI: 46722842K*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"prac2funs.h"

#define PI 3.141592653589793

double f(double);

int main(void){
	int i, n;
	double *x, *y, step, t, fx, px, er;
	scanf("%d",&n);
	x=(double*)malloc((n+1)*sizeof(double));
	y=(double*)malloc((n+1)*sizeof(double));
	if(x==NULL || y==NULL){
		return 1;
	}
	step=2*PI/n;
	for(i=0;i<=n;i++){
		x[i]=0+i*step;
		y[i]=f(x[i]);
	}
	dif_dividides(x,y,n);
	step=2*PI/1000;
	for(i=0;i<1000;i++){
		t=i*step;
		fx=f(t);
		px=aval(x,y,n,t);
		er=(px-fx)/fx;
		printf("%e %e %e %e\n", t,fx,px,er);
	}
	return 0;
}

double f(double x){
	return exp(sin(x)+cos(x));
}
