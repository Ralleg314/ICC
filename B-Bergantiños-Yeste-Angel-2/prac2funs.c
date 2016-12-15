#include<stdio.h>
#include"prac2funs.h"

void dif_dividides(double *x,double *y, int n){
	int i, j;
	for(i=1; i<=n;i++){
		for(j=n;j>=i;j--){
			y[j]=(y[j]-y[j-1])/(x[j]-x[j-i]);
		}
	}
}

double aval(double *x, double *c, int n, double t){
	int i,j;
	double sol=0,r;
	for(i=0;i<n+1;i++){
		r=1;
		for(j=0;j<i;j++){
			r*=(t-x[j]);
		}
		sol+=c[i]*r;
	}
	return sol;	
}
