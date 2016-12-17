/*COGNOM1:Bergantiños 
COGNOM2: Yeste
NOM: Angel
DNI: 46722842K*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"prac2funs.h"

int main(void){
	int i=0,j, n[4]={6,9,12,15},nb=5,dia,mes,pos;
	double *temps, *x, *y, *z,*subt,*subx,*suby,*subz,test=2462225.5,data,avalx,avaly,avalz;
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
	/*We want 4 cases: n=6,9,12 and 15, so we use a vector to use each value every time*/
	for(i=0;i<4;i++){
		/*Allocate the vector every time to use only the memory we need every for every case
		We could also allocate the vectors to 15 and use only the positions we need*/
		subt=(double*)malloc((n[i]+1)*sizeof(double));
		subx=(double*)malloc((n[i]+1)*sizeof(double));
		/*Like before, if any of the vectors couldn't be allocated, we end the program*/
		if(subx==NULL || subt==NULL){
			return 3;
		}
		/*Retrieve the n-1 last positions of the data
		Again, we could get the last 16 lines and use only those we need, but we overwrite data when we
		generate the polynomial, so it's not a valid option*/
		for(j=413;j>=413-n[i];j--){
			subt[n[i]-(413-j)]=temps[j];
			subx[n[i]-(413-j)]=x[j];
		}
		printf("n=%d\n",n[i]);
		for(j=0;j<=n[i];j++){
			printf("t[%2d]=%.1f x[%2d]=%+.8e\n",j,subt[j],j,subx[j]);
		}
		/*Generate the interpolation polynomial*/
		dif_dividides(subt,subx,n[i]);
		printf("**********************\n");
		printf("Els coeficients del polinomi de grau %d per x(t) son\n",n[i]);
		for(j=0;j<=n[i];j++){
			printf("dd[%2d]=%+.8e\n",j,subx[j]);
		}
		printf("n=%d x(%.1f)=%+.8e\n",n[i], test, aval(subt,subx,n[i],test));
		printf("**********************\n");
		/*We have to free the vectors every iteration, because we allocate new memory every time*/
		free(subt);
		free(subx);
	}
	
	/*Allocate the memory we will need to store all data we are going to need*/
	subt=(double*)malloc((nb+1)*sizeof(double));
	subx=(double*)malloc((nb+1)*sizeof(double));
	suby=(double*)malloc((nb+1)*sizeof(double));
	subz=(double*)malloc((nb+1)*sizeof(double));
	/*Check if all alocations were done*/
	if(subx==NULL || suby==NULL || subz==NULL || subt==NULL){
		return 4;
	}
	printf("Data a comprovar dia/mes?\n");
	scanf("%d %d",&dia,&mes);
	/*Convert our date to julian*/
	data=datajuliana(dia,mes,2020);
	/*If the date is already in our data set, we use the same date but 5 years later*/
	if(data==temps[((int)(data-2453979.5)/20)]){
		/*Calculate date again*/
		data=datajuliana(dia,mes,2025);
		printf("Data calendari: %d %d 2025\n",dia,mes);
	}else{
		printf("Data calendari: %d %d 2020\n",dia,mes);
	}
	printf("Data juliana a considerar: %.1f\n",data);
	printf("**********************\nCalculs del dia de l’aniversari\n");
	/*data is 3 positions after the first one we need, so we substract 60 (=3*20) to start at the position we want*/
	data-=60;
	/*Look for the data wee are going to use*/
	pos=1+(data-2453979.5)/20;
	printf("pos=%d\n",pos);
	/*Get data we need*/
	for(i=pos;i<pos+6;i++){
		subt[i-pos]=temps[i];
		subx[i-pos]=x[i];
		suby[i-pos]=y[i];
		subz[i-pos]=z[i];
	}
	for(i=0;i<=nb;i++){
		printf("%d t=%.8e x=%+.8e y=%+.8e z=%+.8e\n",i,subt[i],subx[i],suby[i],subz[i]);
	}
	/*For each cordinate, generate its polynomial*/
	dif_dividides(subt,subx,nb);
	dif_dividides(subt,suby,nb);
	dif_dividides(subt,subz,nb);
	printf("**********************\n");
	printf("Els coeficients del polinomi de grau 5 per x(t),y(t),z(t) son\n");
	/*Get the information we need from our data set*/
	for(i=0;i<=nb;i++){
		printf("dd_x[%d]=%+.8e dd_y[%d]=%+.8e dd_z[%d]=%+.8e\n",i,subx[i],i,suby[i],i,subz[i]);
	}
	printf("**********************\n");
	/*Retrieve real date again*/
	data+=60;
	/*Evaluate the polynomial in the date we want*/
	avalx=aval(subt,subx,nb,data);
	avaly=aval(subt,suby,nb,data);
	avalz=aval(subt,subz,nb,data);
	printf("t=%.1f x=%+.8e y=%+.8e z=%+.8e\n",data, avalx,avaly,avalz);
	printf("La distancia al sol es %.12e UA\n",sqrt(pow(avalx,2)+pow(avaly,2)+pow(avalz,2)));
	/*Free all memory we have used to avoid memory leaks*/
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
