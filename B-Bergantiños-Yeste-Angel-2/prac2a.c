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
	/*Allocate memory for both vectors*/
	x=(double*)malloc((n+1)*sizeof(double));
	y=(double*)malloc((n+1)*sizeof(double));
	/*If there wasn't enough memory for the vectors, the program stops*/
	if(x==NULL || y==NULL){
		return 1;
	}
	/*We need n+1 points, so we divide our interval in equidistant steps*/
	step=2*PI/n;
	/*Calculate every value of x and its f(x)*/
	for(i=0;i<=n;i++){
		x[i]=0+i*step;
		y[i]=f(x[i]);
	}
	/*Generates the interpolation polynomial*/
	dif_dividides(x,y,n);
	/*Now we calculate the aproximated value of a thousand values in between 0 and 2PI*/
	step=2*PI/999;
	for(i=0;i<=999;i++){
		t=i*step;
		fx=f(t);
		px=aval(x,y,n,t);
		er=(px-fx)/fx;
		printf("%e %e %e %e\n", t,fx,px,er);
	}
	/*Free memory used for x and y to avoid memory leaks*/
	free(x);
	free(y);
	return 0;
}

double f(double x){
	return exp(sin(x)+cos(x));
}
