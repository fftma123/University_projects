#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define KBOYUT 100

typedef struct {
    int son;
    int eleman[KBOYUT];
} Kuyruk;

// Global kuyruk deðiþkeni
Kuyruk Yeni_Kuyruk;


// Kuyruk dolu mu kontrolü
int Kuyruk_Dolumu() {
    if (Yeni_Kuyruk.son >= KBOYUT - 1)
        return 1;   // Dolu
    else
        return 0;   // Dolu degil
}

// Kuyruk bos mu kontrolü
int Kuyruk_Bosmu() {
    if (Yeni_Kuyruk.son == -1)
        return 1;   // Bos
    else
        return 0;   // Bos degil
}

// Kuyruga eleman ekleme
void Kuyruga_Ekle(int sayi) {
    if (Kuyruk_Dolumu()) {
        printf("Kuyruk dolu! Eleman eklenemedi.\n");
    } else {
        Yeni_Kuyruk.son++;
        Yeni_Kuyruk.eleman[Yeni_Kuyruk.son] = sayi;
        printf("%d kuyruða eklendi.\n", sayi);
    }
}

// Kuyruktan eleman cikarma
int Kuyruktan_Cikar() {
    int cikan, i;

    if (Kuyruk_Bosmu()) {
        printf("Kuyruk bos! Cikarilacak eleman yok.\n");
        return -1;
    } else {
        cikan = Yeni_Kuyruk.eleman[0];

        // Tum elemanlari sola kaydir
        for (i = 1; i <= Yeni_Kuyruk.son; i++) {
            Yeni_Kuyruk.eleman[i - 1] = Yeni_Kuyruk.eleman[i];
        }

        Yeni_Kuyruk.son--;
        return cikan;
    }
}

// Kuyruktaki elemanlari listeleme
void Listele() {
    int i;

    if (Kuyruk_Bosmu()) {
        printf("Kuyruk bos!\n");
        return;
    }

    printf("Kuyruktaki elemanlar:\n");
    for (i = 0; i <= Yeni_Kuyruk.son; i++) {
        printf("%d ", Yeni_Kuyruk.eleman[i]);
    }
    printf("\n");
}

// Ana fonksiyon (menu)
int main() {
    int secim;
    int sayi;
    int cikan;

    // Kuyrugu baslangicta bos yap
    Yeni_Kuyruk.son = -1;

    while (1) {
        printf("\n--- KUYRUK ISLEMLERI ---\n");
        printf("1. Eleman ekle\n");
        printf("2. Eleman cikar\n");
        printf("3. Listele\n");
        printf("4. Cikis\n");
        printf("Seciminizi girin: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Eklenecek sayiyi girin: ");
                scanf("%d", &sayi);
                Kuyruga_Ekle(sayi);
                break;

            case 2:
                cikan = Kuyruktan_Cikar();
                if (cikan != -1)
                    printf("Cikan eleman: %d\n", cikan);
                break;

            case 3:
                Listele();
                break;

            case 4:
                printf("Programdan cikiliyor...\n");
                exit(0);
                break;

            default:
                printf("Hatali secim!\n");
                break;
        }

    
    }

    return 0;
}

