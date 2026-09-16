#include <stdio.h>
#include <stdlib.h>

typedef struct Liste {
    int numara;               // data kýsmý (düðümün tuttuðu veri)
    struct Liste *sonraki;    // sonraki düðümün adresi
} BListe;

BListe *ilk = NULL, *son = NULL;

// Yeni düðüm oluþturma fonksiyonu
BListe *Bilgi_Al(int num) {
    BListe *bilgi = (BListe *)malloc(sizeof(BListe));
    bilgi->numara = num;
    bilgi->sonraki = NULL;
    return bilgi;
}

// Listeye eleman ekleme (sona ekleme)
void Ekle(BListe *bilgi) {
    if (ilk == NULL) {        // liste boþsa
        ilk = bilgi;
        son = bilgi;
    } else {                  // liste doluysa sona ekle
        son->sonraki = bilgi;
        son = bilgi;
    }
}

// Listeleme
void Listele() {
    BListe *gecici = ilk;
    if (gecici == NULL) {
        printf("Liste bos!\n");
        return;
    }
    printf("Listedeki elemanlar:\n");
    while (gecici != NULL) {
        printf("%d -> ", gecici->numara);
        gecici = gecici->sonraki;
    }
    printf("NULL\n");
}

// Arama
BListe *Ara(int num) {
    BListe *gecici = ilk;
    while (gecici != NULL) {
        if (gecici->numara == num)
            return gecici;  // bulundu
        gecici = gecici->sonraki;
    }
    return NULL; // bulunamadý
}

// Silme
void Silme(int num) {
    BListe *gecici = ilk, *onceki = NULL;
    while (gecici != NULL && gecici->numara != num) {
        onceki = gecici;
        gecici = gecici->sonraki;
    }
    if (gecici == NULL) {
        printf("Kayit bulunamadi.\n");
        return;
    }

    if (gecici == ilk) { // ilk eleman siliniyorsa
        ilk = ilk->sonraki;
    } else {             // ortada veya sonda silme
        onceki->sonraki = gecici->sonraki;
    }

    if (gecici == son)  // son eleman silindiyse
        son = onceki;

    free(gecici);
    printf("Kayit silindi.\n");
}

// Ana menü
int main() {
    BListe *bul;
    char secim;
    int numara;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("e - Ekleme\n");
        printf("l - Listeleme\n");
        printf("a - Arama\n");
        printf("s - Silme\n");
        printf("c - Cikis\n");
        printf("Secim: ");
        scanf(" %c", &secim);

        switch (secim) {
            case 'e':
                printf("Numarayi giriniz: ");
                scanf("%d", &numara);
                Ekle(Bilgi_Al(numara));
                break;

            case 'l':
                Listele();
                break;

            case 'a':
                printf("Aranacak numarayi giriniz: ");
                scanf("%d", &numara);
                bul = Ara(numara);
                if (bul != NULL)
                    printf("Kayit bulundu: %d\n", bul->numara);
                else
                    printf("Kayit bulunamadi.\n");
                break;

            case 's':
                printf("Silinecek numarayi giriniz: ");
                scanf("%d", &numara);
                Silme(numara);
                break;

            case 'c':
                printf("Programdan cikiliyor...\n");
                exit(0);

            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}

