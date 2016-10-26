#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int resoltrisup(int, double**, double*, double*, double);
void prodMatVec(int,double**,double*,double*);
double norma2(int, double*);
int gausspivot(int, double**, double*, double);
int main(void){
	int n, i, j;
	double tol=1.0E-3;	
	double **A, *b, *x, *y, *z;
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
	b = (double*)malloc( n*sizeof(double));
	x = (double*)malloc( n*sizeof(double));
	y = (double*)malloc( n*sizeof(double));
	z = (double*)malloc( n*sizeof(double));
	if( b == NULL || x == NULL || y==NULL || z==NULL){
		printf("No hi ha prou memoria");
		return 3;
	}
	printf("Doneu els (%d x %d) elements de la matriu A \n", n, n);
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%le", &A[i][j]);
		}
	}	
	printf("Doneu els %d elements del vector b \n", n);
	for(i = 0; i < n; i++)scanf("%le", &b[i]);
	if(gausspivot(n,A,b,tol)==0){
		printf("( ");
		for(i=0;i<n;i++)printf("%2.2f ", x[i]);
		printf(")\n");
		prodMatVec(n,A,x,y);
		for(i=0;i<n;i++)z[i]=y[i]-b[i];
		printf("La norma es igual a %e\n",norma2(n,z));		
	}else{
		printf("No hi ha solució\n");
	}
	return 0;
}

int gausspivot(int n, double **A, double *v, double tol){
	int i,j,k, maxpos;
	double temp, max;
	for(k=0;k<n-1;k++){
		max=-1.0/0.0;
		for(i=k;i<n;i++){
			if(A[i][k]>max){
				max=A[i][k];
				maxpos=i;
			}
		}
		for(i=k;i<n;i++){
			temp=A[k][i];
			A[k][i]=A[maxpos][i];
			A[maxpos][i]=temp;
		} 
		for(i=k+1;i<n;i++){
			if(fabs(A[k][k])<tol){
				return 1;
			}else{
				temp=A[i][k]/A[k][k];
				for(j=k;j<n;j++){
					A[i][j]-=A[k][j]*temp;
				}
			}
		}
	}
	for(i=0;i<n;i++){
     		for(j=0;j<n;j++){
                	printf(" %2.2e ",A[i][j]);
               	}
		printf("\n");
        }               
                    

	return 0;
}

int resoltrisup(int n, double **A, double *b, double *x, double tol){
	int i, j;
	for(i=n-1;i>=0;i--){
		x[i]=b[i];
		if(fabs(A[i][i])<tol){
			return 1;
		}else{
			for(j=n-1;j!=i;j--){
	                        x[i]-=(A[i][j]*x[j]);
	                }
			x[i]=x[i]/A[i][i];
		}
	}
	return 0;
}

void prodMatVec(int n, double **A, double *x, double *y){
	int i, j;
	for(i=0;i<n;i++){
		y[i]=0;
		for(j=0;j<n;j++){
			y[i]+=A[i][j]*x[j];
		}
	}
}

double norma2(int n, double *z){
	int i;
	double norma=0;
	for(i=0;i<n;i++){
		norma+=pow(z[i],2);
	}
	return sqrt(norma);
}

