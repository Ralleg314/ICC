#include<stdio.h>
#include<stdlib.h>
void prod(double**,double*,double*);
int main(void){
        int n, m, i, j;
        FILE *f;
        double **a, **b, *u, *v;
        f=fopen("dades.dad","r");
        if(f==NULL){
                printf("El fitxer no existeix\n");
                return 5;
        }
       	fscanf(f,"%d %d", &n,&m);
        a = (double**)malloc(n*sizeof(double*)); 
	if( a == NULL ){
                printf("No hi ha prou memoria");
                return 1;
        }
        for(i = 0; i < n; i++){
                a[i] = (double*)malloc( m*sizeof(double) );
                if( a[i] == NULL ){
                        printf("No hi ha prou memoria");
                        return 2;
                }
        }
	b = (double**)malloc(m*sizeof(double*)); 
        if( a == NULL ){
                printf("No hi ha prou memoria");
                return 1;
        }
        for(i = 0; i < m; i++){
                a[i] = (double*)malloc( n*sizeof(double) );
               if( a[i] == NULL ){
                        printf("No hi ha prou memoria");
                        return 2;
                }
        }
        u = (double*)malloc( m*sizeof(double) );
        v = (double*)malloc( n*sizeof(double) );
        if( u == NULL || v == NULL ){
                printf("No hi ha prou memoria");
                return 3;
        }
        printf("Doneu els (%d x %d) elements de la matriu A \n", n, m);
        for(i = 0; i < n; i++){
                for(j = 0; j < m; j++){
                        fscanf(f,"%le", &a[i][j]);
                }
        }
        for(i = 0; i < m; i++)fscanf(f,"%le", &u[i]);
        for(i = 0; i < n; i++){
        v[i] = 0.;
                for(j = 0; j < m; j++){
                        v[i] += a[i][j]*u[j];
                }
        }
        printf("El producte de la matriu A = \n");
        for(i = 0; i < n; i++){
                for(j = 0; j < m; j++){
                        printf(" %16.7e ", a[i][j]);
                }
                printf("\n");
        }
        printf("pel vector u=\n");
        for(i = 0; i < m; i++)printf("%16.7e \n", u[i]);
        printf("ens dona v=\n");
        for(i = 0; i < n; i++)printf("%16.7e \n", v[i]);
        for(i = 0; i < n; i++)free (a[i]);
        free(a);
        free(u);
        free(v);
        return 0;
}

