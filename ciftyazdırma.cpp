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

// Çift numaralarý tersten yazdýrma (özyinelemeli)
void tersYazdir(Dugum* dugum) {
    if (dugum == NULL)
        return;

    tersYazdir(dugum->sonraki);

    if (dugum->numara % 2 == 0)
        printf("%d ", dugum->numara);
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

    printf("\nÇift sayýlar (ters sýrayla): ");
    tersYazdir(ilk);
    printf("\n");

    return 0;
}

