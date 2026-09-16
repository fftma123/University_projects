#include <stdio.h>
#include <stdlib.h>

typedef struct Dugum {
    int numara;
    struct Dugum* sonraki;
} Dugum;

Dugum* ilk = NULL;

// Yeni düðüm oluþturma
Dugum* yeniDugum(int numara) {
    Dugum* yeni = (Dugum*)malloc(sizeof(Dugum));
    yeni->numara = numara;
    yeni->sonraki = NULL;
    return yeni;
}

// Listeye ekleme (sona ekleme)
void listeyeEkle(int numara) {
    Dugum* yeni = yeniDugum(numara);
    if (ilk == NULL) {
        ilk = yeni;
    } else {
        Dugum* gecici = ilk;
        while (gecici->sonraki != NULL)
            gecici = gecici->sonraki;
        gecici->sonraki = yeni;
    }
}

// Ortalama hesaplama
float ortalamaBul() {
    if (ilk == NULL) return 0;

    int toplam = 0, adet = 0;
    Dugum* gecici = ilk;
    while (gecici != NULL) {
        toplam += gecici->numara;
        adet++;
        gecici = gecici->sonraki;
    }
    return (float)toplam / adet;
}

int main() {
    int n, sayi;

    printf("Kaç sayý gireceksiniz: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d. sayýyý girin: ", i + 1);
        scanf("%d", &sayi);
        listeyeEkle(sayi);
    }

    printf("\nGirilen sayýlarýn ortalamasý: %.2f\n", ortalamaBul());

    return 0;
}

