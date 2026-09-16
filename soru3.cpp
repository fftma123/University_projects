#include<stdio.h>
#define Boyut 100
int indis=-1;
int yigin[Boyut];
void yiginekle(int veri){
	if(indis>=Boyut-1){
		printf("yigin dolu");
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
	int sayi;
	while(1){
		printf("sayi gir cikmak icin0 gir:");
		scanf("%d",&sayi);
		if(sayi==0){
			break;
		}
		yiginekle(sayi);
	}
	printf("cikan elemanlar:");
	while(indis!=-1){
		printf("%d",yigincikar());
	}
	return 0;
}
