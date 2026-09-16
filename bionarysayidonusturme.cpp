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
        // Yýðýn doluysa -1 döndür
        return -1;
    }
    else
    {
        // Dolu deðilse 1 döndür
        return 1;
    }
}

// ---------- Yýðýn Boþ mu? ----------
int Yigin_Bosmu()
{
    if (Yeni_Yigin.indis == -1)
    {
        // Yýðýn boþsa -1 döndür
        return -1;
    }
    else
    {
        // Boþ deðilse 1 döndür
        return 1;
    }
}

// ---------- Push (Ekleme) ----------
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
    }
}

// ---------- Pop (Çýkarma) ----------
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

// ---------- Desimal › Binary Dönüþüm ----------
void Desimalden_Binarye(int sayi)
{
    int kalan;

    // Sayý 0 olana kadar mod al ve yýðýna ekle
    while (sayi > 0)
    {
        kalan = sayi % 2;
        Yigina_Ekle(kalan);
        sayi = sayi / 2;
    }

    printf("\nÝkilik (binary) karþýlýðý: ");

    // Yýðýndan çýkararak ters sýrada yazdýr
    while (Yigin_Bosmu() != -1)
    {
        printf("%d", Yigindan_Cikar());
    }
    printf("\n");
}

// ---------- Ana Fonksiyon ----------
int main()
{
    Yeni_Yigin.indis = -1;  // Yýðýn boþ baþlatýlýr
    int sayi;

    printf("Desimal sayiyi giriniz: ");
    scanf("%d", &sayi);

    if (sayi < 0)
    {
        printf("Negatif sayilar desteklenmiyor.\n");
        return 0;
    }

    if (sayi == 0)
    {
        printf("0'in binary karsiligi: 0\n");
        return 0;
    }

    Desimalden_Binarye(sayi);

    return 0;
}

