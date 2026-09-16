#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define KBoyut 100

typedef struct Kuyruk
{
    int son;
    int bas;
    int sayi;
    int eleman[KBoyut];
} Kuyruklar;

Kuyruklar Yeni_Kuyruk; // Global kuyruk deðiþkeni

// Kuyruk dolu mu kontrolü
int Kuyruk_Dolumu()
{
    if (Yeni_Kuyruk.sayi >= KBoyut - 1)
        return -1; // Dolu
    else
        return 1;  // Dolu deðil
}

// Kuyruk boþ mu kontrolü
int Kuyruk_Bosmu()
{
    if (Yeni_Kuyruk.sayi == 0)
        return -1; // Boþ
    else
        return 1;  // Boþ deðil
}

// Kuyruða eleman ekleme
void Kuyruga_Ekle(int ekle)
{
    if (Kuyruk_Dolumu() == -1)
    {
        printf("Kuyruk Dolu!\n");
        getch();
    }
    else
    {
        Yeni_Kuyruk.son = (Yeni_Kuyruk.son + 1) % KBoyut;
        Yeni_Kuyruk.eleman[Yeni_Kuyruk.son] = ekle;
        Yeni_Kuyruk.sayi++;
    }
}

// Kuyruktan eleman çýkarma
int Kuyruktan_Cikar()
{
    int cikan_eleman;

    if (Kuyruk_Bosmu() == -1)
    {
        printf("Kuyruk Bos!\n");
        getch();
        return -1;
    }
    else
    {
        Yeni_Kuyruk.bas = (Yeni_Kuyruk.bas + 1) % KBoyut;
        cikan_eleman = Yeni_Kuyruk.eleman[Yeni_Kuyruk.bas];
        Yeni_Kuyruk.sayi--;
        return cikan_eleman;
    }
}

// Kuyruðu listeleme
void Listele()
{
    int i;
    if (Kuyruk_Bosmu() == -1)
    {
        printf("Kuyruk Bos!\n");
        return;
    }

    printf("\nKuyruktaki Elemanlar:\n");
    for (i = 1; i <= Yeni_Kuyruk.sayi; i++)
        printf("%d ", Yeni_Kuyruk.eleman[(Yeni_Kuyruk.bas + i) % KBoyut]);
}

// Ana fonksiyon
int main()
{
    char secim;
    int numara;

    // Kuyruk ilk deðerleri
    Yeni_Kuyruk.son = -1;
    Yeni_Kuyruk.bas = -1;
    Yeni_Kuyruk.sayi = 0;

    while (1)
    {
        
        puts("----- KUYRUK ISLEMLERI -----");
        puts("e - Eleman Ekle");
        puts("s - Eleman Cikar");
        puts("l - Listele");
        puts("c - Cikis");
        printf("Secim: ");
        secim = getch();

        switch (secim)
        {
        case 'e':
            printf("\nNumarayi giriniz: ");
            scanf("%d", &numara);
            Kuyruga_Ekle(numara);
            break;

        case 's':
            numara = Kuyruktan_Cikar();
            if (numara != -1)
                printf("\nCikan Eleman = %d", numara);
            getch();
            break;

        case 'l':
            Listele();
            getch();
            break;

        case 'c':
            exit(0);

        default:
            printf("\nHatali Secim!");
            getch();
        }
    }
}

