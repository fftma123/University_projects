#include <stdio.h>
#include <stdlib.h>

typedef struct Liste
{
    int numara;
    struct Liste *sonraki;
    struct Liste *onceki;
} BListe;

BListe *ilk = NULL, *son = NULL;

BListe *Bilgi_Al(int num)
{
    BListe *bilgi = (BListe *)malloc(sizeof(BListe));
    bilgi->numara = num;
    bilgi->sonraki = NULL;
    bilgi->onceki = NULL;
    return bilgi;
}

void Ekle(BListe *bilgi)
{
    if (ilk == NULL)
    {
        ilk = bilgi;
        son = ilk;
    }
    else
    {
        son->sonraki = bilgi;
        bilgi->onceki = son;
        son = bilgi;
    }
}

void Listele()
{
    BListe *gecici = ilk;
    if (gecici == NULL)
    {
        printf("Liste bos!\n");
        return;
    }

    printf("\n--- Liste Elemanlari ---\n");
    while (gecici)
    {
        printf("%d ", gecici->numara);
        gecici = gecici->sonraki;
    }
    printf("\n-------------------------\n");
}

BListe *Ara(int num)
{
    BListe *gecici = ilk;
    while (gecici)
    {
        if (gecici->numara == num)
            return gecici;
        gecici = gecici->sonraki;
    }
    return NULL;
}

void Silme(int silnum)
{
    BListe *gecici = Ara(silnum);
    if (gecici != NULL)
    {
        if (ilk == gecici) // silinecek ilk kayitsa
        {
            if (ilk->sonraki == NULL) // tek kayýt varsa
            {
                ilk = NULL;
                son = NULL;
            }
            else // ilk kayýt ama birden fazla varsa
            {
                ilk = ilk->sonraki;
                ilk->onceki = NULL;
            }
        }
        else // ilk kayýt deðilse
        {
            if (gecici == son) // son kayýt siliniyorsa
            {
                son = son->onceki;
                son->sonraki = NULL;
            }
            else // aradaki kayýt siliniyorsa
            {
                gecici->onceki->sonraki = gecici->sonraki;
                gecici->sonraki->onceki = gecici->onceki;
            }
        }
        free(gecici);
        printf("%d numarali kayit silindi.\n", silnum);
    }
    else
    {
        printf("%d numarali kayit bulunamadi.\n", silnum);
    }
}

int main()
{
    int secim, numara;
    BListe *bulunan;

    while (1)
    {
        printf("\n===== CIFT YONLU BAGLI LISTE MENU =====\n");
        printf("1. Ekleme\n");
        printf("2. Listeleme\n");
        printf("3. Arama\n");
        printf("4. Silme\n");
        printf("5. Cikis\n");
        printf("Seciminizi yapiniz: ");
        scanf("%d", &secim);

        switch (secim)
        {
        case 1:
            printf("Eklenecek numarayi giriniz: ");
            scanf("%d", &numara);
            Ekle(Bilgi_Al(numara));
            printf("Numara eklendi!\n");
            break;

        case 2:
            Listele();
            break;

        case 3:
            printf("Aranacak numarayi giriniz: ");
            scanf("%d", &numara);
            bulunan = Ara(numara);
            if (bulunan != NULL)
                printf("%d numarali kayit bulundu.\n", bulunan->numara);
            else
                printf("Kayit bulunamadi.\n");
            break;

        case 4:
            printf("Silinecek numarayi giriniz: ");
            scanf("%d", &numara);
            Silme(numara);
            break;

        case 5:
            printf("Programdan cikiliyor...\n");
            return 0;

        default:
            printf("Hatali secim! Lutfen 1-5 arasinda bir deger giriniz.\n");
        }
    }
}

