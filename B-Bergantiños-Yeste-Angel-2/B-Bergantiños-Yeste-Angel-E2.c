/*COGNOM1:Bergantiños 
COGNOM2: Yeste
NOM: Angel
DNI: 46722842K*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"prac2funs.h"

int main(void){
	int i=0,nb=5,pos;
	double *temps, *x, *y, *z,*subt,*subx,*suby,*subz,*t,data,*v,*r;
	FILE *fin;
	/*Open the file in read mode*/
	fin=fopen("dades_apophis.dat","r");
	/*If we weren't able to open and read the file, end the program*/
	if(fin==NULL){
		return 1;
	}
	/*Allocate the vectors we are going to need to store all data from the file*/
	temps=(double*)malloc(414*sizeof(double));
	x=(double*)malloc(414*sizeof(double));
	y=(double*)malloc(414*sizeof(double));
	z=(double*)malloc(414*sizeof(double));
	/*If any of these vectors hasn't been allocated, end the program*/
	if(x==NULL || y==NULL || z==NULL || temps==NULL){
		return 2;
	}
	/*Read every line of the file and save each value in its corresponding position*/
	do{
		fscanf(fin,"%lf %lf %lf %lf", &temps[i], &x[i], &y[i], &z[i]);
		i++;
	}while(!feof(fin));
	
	/*Allocate the memory we will need to store all data we are going to need*/
	subt=(double*)malloc((nb+1)*sizeof(double));
	subx=(double*)malloc((nb+1)*sizeof(double));
	suby=(double*)malloc((nb+1)*sizeof(double));
	subz=(double*)malloc((nb+1)*sizeof(double));
	r=(double*)malloc((nb+1)*sizeof(double));
	t=(double*)malloc((nb-1)*sizeof(double));
	v=(double*)malloc((nb-1)*sizeof(double));
	/*Check if all alocations were done*/
	if(subx==NULL || suby==NULL || subz==NULL || subt==NULL || t==NULL ||  v==NULL || r==NULL){
		return 4;
	}
	/*Convert our date to julian*/
	data=2457741.5+9.144;
	printf("Data juliana a considerar: %.1f\n",data);
	printf("**********************\nCalculs del dia de la prova\n");
	/*data is 3 positions after the first one we need, so we substract 60 (=3*20) to start at the position we want*/
	data-=60;
	/*Look for the data wee are going to use*/
	pos=1+(data-2453979.5)/20;
	/*Get data we need*/
	for(i=pos;i<pos+6;i++){
		subt[i-pos]=temps[i];
		subx[i-pos]=x[i];
		suby[i-pos]=y[i];
		subz[i-pos]=z[i];
		r[i-pos]=sqrt(pow(subx[i-pos],2)+pow(suby[i-pos],2)+pow(subz[i-pos],2));
	}
	for(i=0;i<=nb;i++){
		printf("%d t=%.8e x=%+.8e y=%+.8e z=%+.8e r=%+.8e\n",i,subt[i],subx[i],suby[i],subz[i],r[i]);
	}
	/*Retrieve real date again*/
	data+=60;
	printf("\n");
	/*Evaluate the polynomial in the date we want*/
	for(i=0;i<nb-1;i++){
		t[i]=subt[i+1];
		v[i]=(r[i+2]-r[i])/40.;
		printf("%d t=%+.8e v=%+.8e\n",i,subt[i+1],v[i]);
	}
	dif_dividides(t,v,nb-1);
	printf("**********************\n");
	printf("t*=%.1f v(t*)=%+.8e\n",data, aval(t,v,nb-1,data));
	/*Free all memory we have used to avoid memory leaks*/
	free(temps);
	free(x);
	free(y);
	free(z);
	free(t);
	free(v);
	free(r);
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
