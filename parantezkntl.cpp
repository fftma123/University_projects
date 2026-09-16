#include <stdio.h>
#define N 100

char Yigin[N];
int indis = -1; // Yýðýn boþ

// ---------- Eleman ekleme ----------
void Yigina_Ekle(char ch) {
    if (indis >= N - 1) {
        printf("Yigin dolu!\n");
    } else {
        indis++;
        Yigin[indis] = ch;
    }
}

// ---------- Eleman çýkarma ----------
void Yigindan_Cikar() {
    if (indis == -1) {
        printf("Yigin bos!\n");
    } else {
        indis--;
    }
}

// ---------- Yýðýn boþ mu kontrol ----------
int Yigin_Bosmu() {
    if (indis == -1)
        return -1; // boþ
    else
        return 1;  // boþ deðil
}

int main() {
    char ifade[100];
    int i = 0, dengeli = 1;

    printf("Ifade giriniz: ");
    scanf("%s", ifade);

    while (ifade[i] != '\0') {
        if (ifade[i] == '(') {
            Yigina_Ekle('(');
        } 
        else if (ifade[i] == ')') {
            if (Yigin_Bosmu() == -1) { // yýðýn boþsa dengeli deðil
                dengeli = 0;
                break;
            }
            Yigindan_Cikar();
        }
        i++;
    }

    // Yýðýn hâlâ boþ deðilse dengeli deðil
    if (Yigin_Bosmu() != -1) dengeli = 0;

    if (dengeli)
        printf("Parantezler dengeli \n");
    else
        printf("Parantezler dengeli degil \n");

    return 0;
}

