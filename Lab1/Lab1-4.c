#include<stdio.h>
int main(void){
	float auxf=1;
	double auxd=1;
	while(1+auxf>1){
		auxf/=2;
	}
	printf("float: %f\n", auxf);
	while(1+auxd>1){
		auxd/=2;
	}
	printf("double: %e\n", auxd);
	return 0;
}
