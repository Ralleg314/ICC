#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.141592653589793

void dif_dividides(double*,double*,int);
double aval(double*,double*,int,double);
double f(double);


int main(void){
	int i, n;
	double *x, *y, step;
	printf("Introdueix la dimensio: ");
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
	printf("Pol: %e\nf(t): %e\n", aval(x,y,n,x[0]), f(x[0]));
	return 0;
}

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

double f(double x){
	return exp(sin(x)+cos(x));
}
