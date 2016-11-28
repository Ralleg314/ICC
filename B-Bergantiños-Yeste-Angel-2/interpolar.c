#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void dif_dividides(double*,double*,int);
double aval(double*,double*,int,double);
double f(double);


int main(void){
	int i, n;
	double *x, *y;
	printf("Introdueix la dimensio: ");
	scanf("%d",&n);
	x=(double*)malloc((n+1)*sizeof(double));
	y=(double*)malloc((n+1)*sizeof(double));
	if(x==NULL || y==NULL){
		return 1;
	}
	for(i=0;i<=n;i++){
		scanf("%lf", &x[i]);
		y[i]=f(x[i]);
	}
	dif_dividides(x,y,n);
	printf("%e\n", aval(x,y,n,x[0]));
	return 0;
}

void dif_dividides(double *x,double *y, int n){
	int i, j;
	for(i=1; i<=n;i++){
		for(j=n;j>=i;j--){
			y[j]=(y[j]-y[j-1])/(x[j]-x[j-i]);
		}
		printf("%e", y[i]);
	}
	printf("\n");
}

double aval(double *x, double *c, int n, double t){
	int i,j;
	double sol,r;
	for(i=n;i>=0;i--){
		r=1;
		for(j=0;j<i;j++){
			r*=(t-x[i]);
		}
		sol+=c[i]*r;
	}
	return sol;	
}

double f(double x){
	return exp(sin(x)+cos(x));
}
