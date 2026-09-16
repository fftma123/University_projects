#include <stdio.h>
#include <stdlib.h>

#define YBoyut 100

// ---------- Yýðýn Yapýsý ----------
typedef struct {
    int indis;
    int eleman[YBoyut];
} Yigin;

Yigin Yeni_Yigin;

// ---------- Yýðýn Dolu mu? ----------
int Yigin_Dolumu()
{
    if (Yeni_Yigin.indis >= YBoyut - 1)
    {
        // Eðer indis son indekse ulaþtýysa yýðýn doludur
        return -1;
    }
    else
    {
        // Deðilse dolu deðildir
        return 1;
    }
}

// ---------- Yýðýn Boþ mu? ----------
int Yigin_Bosmu()
{
    if (Yeni_Yigin.indis == -1)
    {
        // Eðer indis -1 ise yýðýn boþ demektir
        return -1;
    }
    else
    {
        // Deðilse içinde eleman vardýr
        return 1;
    }
}

// ---------- Ekleme (Push) ----------
void Yigina_Ekle(int veri)
{
    if (Yigin_Dolumu() == -1)
    {
        printf("??  Yigin Dolu! Yeni eleman eklenemez.\n");
    }
    else
    {
        Yeni_Yigin.indis++;
        Yeni_Yigin.eleman[Yeni_Yigin.indis] = veri;
        printf("? %d eklendi.\n", veri);
    }
}

// ---------- Çýkarma (Pop) ----------
int Yigindan_Cikar()
{
    int cikan;
    if (Yigin_Bosmu() == -1)
    {
        printf("??  Yigin Bos! Cikarma yapilamaz.\n");
        return -1;
    }
    else
    {
        cikan = Yeni_Yigin.eleman[Yeni_Yigin.indis];
        Yeni_Yigin.indis--;
        return cikan;
    }
}

// ---------- Listeleme ----------
void Listele()
{
    if (Yigin_Bosmu() == -1)
    {
        printf("??  Yigin Bos!\n");
        return;
    }

    printf("\n?? Yigin Elemanlari (Tepeden Alta):\n");
    for (int i = Yeni_Yigin.indis; i >= 0; i--)
    {
        printf("%d\n", Yeni_Yigin.eleman[i]);
    }
}

// ---------- Ana Fonksiyon ----------
int main()
{
    Yeni_Yigin.indis = -1;  // Yýðýn boþ baþlatýlýr
    char secim;
    int sayi, sonuc;

    while (1)
    {
        printf("\n========== YIGIN MENUSU ==========\n");
        printf("[E] Ekleme (Push)\n");
        printf("[S] Cikarma (Pop)\n");
        printf("[L] Listeleme\n");
        printf("[C] Cikis\n");
        printf("Seciminiz: ");
        scanf(" %c", &secim);

        switch (secim)
        {
        case 'E':
        case 'e':
            printf("Eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi);
            Yigina_Ekle(sayi);
            break;

        case 'S':
        case 's':
            sonuc = Yigindan_Cikar();
            if (sonuc != -1)
                printf("Yigindan cikan: %d\n", sonuc);
            break;

        case 'L':
        case 'l':
            Listele();
            break;

        case 'C':
        case 'c':
            printf("Programdan cikiliyor...\n");
            exit(0);

        default:
            printf("??  Gecersiz secim!\n");
        }
    }
    return 0;
}

