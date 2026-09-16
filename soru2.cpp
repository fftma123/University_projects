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
int main(){
	int sayi;
	for(int i=0;i<3;i++){
		printf("%d. sayiyi gir:",i+1);
		scanf("%d",&sayi);
		yiginekle(sayi);
	}
	printf("yiginin tepesindeki eleman: %d",yigin[indis]);
	return 0;
}
