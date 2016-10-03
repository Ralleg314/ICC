#include<stdio.h>
#include<stdlib.h>
int resultrisup(int, double**, double*, double*, double);
int main(void){
	int n, i, j;
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
	return 0;
}

int resoltrisup (int n, double **A, double *b, double *x, double tol){
	int i, j;
	for(i=n-1;i>=0;i--){
	
	return 0;
}
