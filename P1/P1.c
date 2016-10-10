#include<stdio.h>
#include<stdlib.h>
int resoltrisup(int, double**, double*, double*, double);
int main(void){
	int n, i, j;
	double tol=1.0E-3;	
	double **A, *b, *x;
	printf("Doneu la dimensio de la matriu, n = \n");
	scanf("%d", &n);
	A = (double**)malloc(n*sizeof(double*));
	if( A == NULL ){
		printf("No hi ha prou memoria");
		return 1;
	}
	for(i = 0; i < n; i++){
		A[i] = (double*)malloc( n*sizeof(double) );
		if( A[i] == NULL ){
			printf("No hi ha prou memoria");
			return 2;
		}else{
			for(j = 0; j < n; j++){
                        	A[i][j]=0;
                	}
		}
	}
	b = (double*)malloc( n*sizeof(double) );
	x = (double*)malloc( n*sizeof(double) );
	if( b == NULL || x == NULL ){
		printf("No hi ha prou memoria");
		return 3;
	}
	printf("Doneu els (%d x %d) elements de la matriu A \n", n, n);
	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			scanf("%le", &A[i][j]);
		}
	}
	printf("Doneu els %d elements del vector b \n", n);
	for(i = 0; i < n; i++)scanf("%le", &b[i]);
	if(resoltrisup(n,A,b,x,tol)==0){
		printf("( ");
		for(i=0;i<n;i++)printf("%2.2f ", x[i]);
		printf(")\n");
	}
	return 0;
}

int resoltrisup(int n, double **A, double *b, double *x, double tol){
	int i, j;
	for(i=n-1;i>=0;i--){
		for(j=n-1;j!=i;j--){
			b[i]-=(A[i][j]*x[j]);
		}
		if(abs(A[i][i])<tol && abs(b[i])>=tol){
			printf("No hi ha solució\n");
			return 1;
		}else if(abs(A[i][i])<tol && abs(b[i])<tol){
			x[i]=0;
		}else{
			x[i]=b[i]/A[i][i];
		}
	}
	return 0;
}
