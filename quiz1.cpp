#include <stdio.h>
#include <stdlib.h>

// Baðlý liste düðüm yapýsý
typedef struct Liste {
    int veri;
    struct Liste *sonraki;
} Liste;

// Liste baþý göstericisi
Liste *ilk = NULL;

// Yeni düðüm oluþturma fonksiyonu
Liste* dugum_olustur(int sayi) {
    Liste *yeni = (Liste*)malloc(sizeof(Liste));
    yeni->veri = sayi;
    yeni->sonraki = NULL;
    return yeni;
}

// Listeye eleman ekleme (sona ekleme)
void listeye_ekle(int sayi) {
    Liste *yeni = dugum_olustur(sayi);
    if (ilk == NULL) {
        ilk = yeni;
    } else {
        Liste *gecici = ilk;
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
}

// Listedeki en küçük sayýyý bulma
int en_kucuk_bul() {
    if (ilk == NULL) {
        printf("Liste bos!\n");
        return 0;
    }

    int en_kucuk = ilk->veri;
    Liste *gecici = ilk->sonraki;

    while (gecici != NULL) {
        if (gecici->veri < en_kucuk) {
            en_kucuk = gecici->veri;
        }
        gecici = gecici->sonraki;
    }
    return en_kucuk;
}

// Listeyi ekrana yazdýrma
void listeyi_yazdir() {
    Liste *gecici = ilk;
    printf("Listedeki sayilar: ");
    while (gecici != NULL) {
        printf("%d ", gecici->veri);
        gecici = gecici->sonraki;
    }
    printf("\n");
}

// Ana fonksiyon
int main() {
    int sayi, adet, i;

    printf("Kac sayi gireceksiniz? ");
    scanf("%d", &adet);

    for (i = 0; i < adet; i++) {
        printf("%d. sayiyi girin: ", i + 1);
        scanf("%d", &sayi);
        listeye_ekle(sayi);
    }

    listeyi_yazdir();

    int en_kucuk = en_kucuk_bul();
    printf("Listedeki en kucuk sayi: %d\n", en_kucuk);

    return 0;
}

