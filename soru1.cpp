
//SORU 1
#include<stdio.h>
#define Boyut 100
int yigin[Boyut];
int indis=-1;
void yiginekle(int veri){
	if(indis>=Boyut-1){
		printf("yiigin dolu");
	}else{
		indis++;
		yigin[indis]=veri;
	}
}
int yigincikar(){
    int cikan;
    if(indis==-1){
    	printf("yigin bos");
    	return -1;
	}else{
	cikan=yigin[indis];
	indis--;
	return cikan;	
	}
}
int main(){
	yiginekle(1);
	yiginekle(9);
	yiginekle(0);
	yiginekle(5);
	for(int i=0;i<4;i++){
		printf("%d",yigincikar());
	}
	return 0;
}
