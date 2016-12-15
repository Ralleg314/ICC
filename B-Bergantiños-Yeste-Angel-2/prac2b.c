/*COGNOM1:Bergantiños 
COGNOM2: Yeste
NOM: Angel
DNI: 46722842K*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"prac2funs.h"

double datajuliana(int,int,int);

int main(void){
	int i=0,j, n[4]={6,9,12,15},nb=5,dia,mes,pos;
	double *temps, *x, *y, *z,*subt,*subx,*suby,*subz,test=2462225.5,data,avalx,avaly,avalz;
	FILE *fin;
	fin=fopen("dades_apophis.dat","r");
	if(fin==NULL){
		return 1;
	}
	temps=(double*)malloc(414*sizeof(double));
	x=(double*)malloc(414*sizeof(double));
	y=(double*)malloc(414*sizeof(double));
	z=(double*)malloc(414*sizeof(double));
	if(x==NULL || y==NULL || z==NULL || temps==NULL){
		return 2;
	}
	do{
		fscanf(fin,"%lf %lf %lf %lf", &temps[i], &x[i], &y[i], &z[i]);
		i++;
	}while(!feof(fin));
	for(i=0;i<4;i++){
		subt=(double*)malloc((n[i]+1)*sizeof(double));
		subx=(double*)malloc((n[i]+1)*sizeof(double));
		if(subx==NULL || subt==NULL){
			return 3;
		}
		for(j=413;j>=413-n[i];j--){
			subt[n[i]-(413-j)]=temps[j];
			subx[n[i]-(413-j)]=x[j];
		}
		printf("n=%d\n",n[i]);
		for(j=0;j<=n[i];j++){
			printf("t[%2d]=%.1f x[%2d]=%+.8e\n",j,subt[j],j,subx[j]);
		}
		dif_dividides(subt,subx,n[i]);
		printf("**********************\n");
		printf("Els coeficients del polinomi de grau %d per x(t) son\n",n[i]);
		for(j=0;j<=n[i];j++){
			printf("dd[%2d]=%+.8e\n",j,subx[j]);
		}
		printf("n=%d x(%.1f)=%+.8e\n",n[i], test, aval(subt,subx,n[i],test));
		printf("**********************\n");
		free(subt);
		free(subx);
	}
	printf("Data a comprovar dia/mes?\n");
	scanf("%d %d",&dia,&mes);
	printf("Data calendari: %d %d 2020\n",dia,mes);
	data=datajuliana(dia,mes,2020);
	printf("Data juliana a considerar: %.1f\n",data);
	printf("**********************\nCalculs del dia de l’aniversari\n");
	subt=(double*)malloc((nb+1)*sizeof(double));
	subx=(double*)malloc((nb+1)*sizeof(double));
	suby=(double*)malloc((nb+1)*sizeof(double));
	subz=(double*)malloc((nb+1)*sizeof(double));
	if(subx==NULL || suby==NULL || subz==NULL || subt==NULL){
		return 4;
	}
	pos=0;
	data-=60;
	while(temps[pos]<data){
		if(pos>407){
			return 5;
		}
		pos++;
	}
	for(i=pos;i<pos+6;i++){
		subt[i-pos]=temps[i];
		subx[i-pos]=x[i];
		suby[i-pos]=y[i];
		subz[i-pos]=z[i];
	}
	for(i=0;i<=nb;i++){
		printf("%d t=%.8e x=%+.8e y=%+.8e z=%+.8e\n",i,subt[i],subx[i],suby[i],subz[i]);
	}
	dif_dividides(subt,subx,nb);
	dif_dividides(subt,suby,nb);
	dif_dividides(subt,subz,nb);
	printf("**********************\n");
	printf("Els coeficients del polinomi de grau 5 per x(t),y(t),z(t) son\n");
	for(i=0;i<=nb;i++){
		printf("dd_x[%d]=%+.8e dd_y[%d]=%+.8e dd_z[%d]=%+.8e\n",i,subx[i],i,suby[i],i,subz[i]);
	}
	printf("**********************\n");
	data+=60;
	avalx=aval(subt,subx,nb,data);
	avaly=aval(subt,suby,nb,data);
	avalz=aval(subt,subz,nb,data);
	printf("t=%.1f x=%+.8e y=%+.8e z=%+.8e\n",data, avalx,avaly,avalz);
	printf("La distancia al sol es %.12e UA\n",sqrt(pow(avalx,2)+pow(avaly,2)+pow(avalz,2)));
	free(temps);
	free(x);
	free(y);
	free(z);
	free(subt);
	free(subx);
	free(suby);
	free(subz);
	return 0;
}

double datajuliana(int dia,int mes,int any){
	int a,m,y;
	double D;
	a=(14-mes)/12;
	m=mes+12*a-3;
	y=any+4800-a;
	D=dia+(153*m+2)/5+365*y+(y/4)-(y/100)+(y/400)-32045-0.5;
	return D;
}
