#include <stdio.h>
#include <string.h>
#define N 100

char Yigin[N];
int indis = -1;

// --- Yýðýna Ekleme Fonksiyonu ---
void Yigina_Ekle(char ch) {
    if (indis >= N - 1) {
        printf("Yigin dolu!\n");
    } else {
        indis++;
        Yigin[indis] = ch;
    }
}

// --- Yýðýndan Çýkarma Fonksiyonu ---
char Yigindan_Cikar() {
    if (indis == -1) {
        printf("Yigin bos!\n");
        return '\0';
    } else {
        char ch = Yigin[indis];
        indis--;
        return ch;
    }
}

// --- Yýðýnýn Boþ Olup Olmadýðýný Kontrol Et ---
int Yigin_Bosmu() {
    if (indis == -1)
        return 1;  // boþ
    else
        return 0;  // dolu
}

// --- Palindrom Kontrol Fonksiyonu ---
void Palindrom_Kontrol(char sayi[]) {
    int uzunluk = strlen(sayi);
    int i;
    int palindrom = 1; // baþta palindrom kabul ediyoruz

    // Sayýnýn tüm karakterlerini yýðýna ekle
    for (i = 0; i < uzunluk; i++) {
        Yigina_Ekle(sayi[i]);
    }

    // Þimdi sayýyý tersten kontrol et
    for (i = 0; i < uzunluk; i++) {
        char ters = Yigindan_Cikar();
        if (sayi[i] != ters) {
            palindrom = 0;
            break;
        }
    }

    if (palindrom)
        printf("Girilen sayi palindromdur ?\n");
    else
        printf("Girilen sayi palindrom degildir ?\n");
}

// --- Ana Fonksiyon ---
int main() {
    char sayi[100];
    printf("Bir sayi giriniz: ");
    scanf("%s", sayi);

    Palindrom_Kontrol(sayi);

    return 0;
}

