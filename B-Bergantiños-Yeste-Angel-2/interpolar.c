#include<stdio.h>
#include<stdlib.h>

void dif_dividides(double*,double*,int);
double aval(double*,double*,int,double);
double f(double);


int main(void){

	return 0;
}

void dif_dividides(double *x,double *y, int n){
	int i, j;
	for(i=1; i<n;i++){
		for(j=i;j<n;j++){
			y[j]=(y[j]-y[j-1])/(x[j]-x[j-i]);
		}
	}
}

double aval(double *x, double *c, int n, double t){
	double 
	
}
