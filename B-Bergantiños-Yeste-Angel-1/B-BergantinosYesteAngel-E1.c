/*COGNOM1:Bergantiños 
COGNOM2: Yeste
NOM: Angel
DNI: 46722842K*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double determinant(int, double**, double);

int main(void){
	int n=8, i, j;
	double tol=1.0E-3;	
	double **A;
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
		}
		for(j=0;j<n;j++){
			A[i][j]=fabs(i-j);
		}
	}
	printf("Doneu els (%d x %d) elements de la matriu A \n", n, n);
	for(i = 0; i < n; i++){
		scanf("%le", &A[0][i]);
	}	
	printf("El determinant es igual a %+.12e\n", determinant(n,A,tol));
	free(A);
	return 0;
}

double determinant(int n, double **A, double tol){
	int i,j,k, maxpos=-1,count=0;
	double temp, max, det=1;
	for(k=0;k<n-1;k++){
		max=-1.0/0.0;
		for(i=k;i<n;i++){
			if(A[i][k]>max){
				max=A[i][k];
				maxpos=i;
			}
		}
		if(maxpos!=-1){
			count++;
			for(i=k;i<n;i++){
				temp=A[k][i];
				A[k][i]=A[maxpos][i];
				A[maxpos][i]=temp;
			}
		}
		for(i=k+1;i<n;i++){
			if(fabs(A[k][k])<tol){
				return 0;
			}else{
				temp=A[i][k]/A[k][k];
				for(j=k;j<n;j++){
					A[i][j]-=A[k][j]*temp;
				}
			}
		}
		maxpos=-1;
	}             
	for(i=0;i<n;i++){
		det*=A[i][i];
	}
	if(count%2==0){
		return det;
	}
	return -det;
}
