#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"prac2funs.h"

#define PI 3.141592653589793

double f(double);

int main(void){
	int i, n;
	double *temps, *x, *y, *z;
	char
	FILE *fin;
	fin=fopen("dades_apophis.dat","r");
	if(fin==NULL){
		return 1;
	}
	x=(double*)malloc((n+1)*sizeof(double));
	y=(double*)malloc((n+1)*sizeof(double));
	z=(double*)malloc((n+1)*sizeof(double));
	if(x==NULL || y==NULL || z==NULL){
		return 2;
	}
	while(EOF
	dif_dividides(x,y,n);
	
	return 0;
}

double f(double x){
	return exp(sin(x)+cos(x));
}
