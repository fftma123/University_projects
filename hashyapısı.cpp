#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_ROW 16

typedef struct _Row
{
    int index;
    int numara;
    struct _Row *pNext;
} Row;

typedef struct _Table
{
    Row rows[MAX_ROW];
} Table;

Table table;

int RSHash(int no);
void initialize_Table();
void add_Row(int no);
void collision(Row *row, Row *startRow);
int find_row(int no);
void Display_Table();


//------------------ HASH FONKSÝYONU ------------------
int RSHash(int no)
{
    return no % MAX_ROW;
}


//------------------ TABLOYU BAÞLAT ------------------
void initialize_Table()
{
    int i;
    for (i = 0; i < MAX_ROW; ++i)
    {
        table.rows[i].index = -1;
        table.rows[i].numara = -1;
        table.rows[i].pNext = NULL;
    }
}


//------------------ SATIR EKLE ------------------
void add_Row(int no)
{
    int hash_index;
    Row *row;

    hash_index = RSHash(no);
    printf("%d ", hash_index);

    // Eðer slot boþsa
    if (table.rows[hash_index].index == -1 ||
        table.rows[hash_index].numara == no)
    {
        table.rows[hash_index].index = hash_index;
        table.rows[hash_index].numara = no;
        return;
    }

    // Çakýþma varsa yeni düðüm oluþtur
    row = (Row *)malloc(sizeof(Row));
    if (!row)
    {
        puts("yeterli bellek yok!");
        exit(0);
    }

    row->index = hash_index;
    row->numara = no;
    row->pNext = NULL;

    collision(row, &table.rows[hash_index]);
}


//------------------ ÇAKIÞMA ÝÞLEME ------------------
void collision(Row *row, Row *startRow)
{
    while (startRow->pNext != NULL)
        startRow = startRow->pNext;

    startRow->pNext = row;
}


//------------------ ELEMAN BUL ------------------
int find_row(int no)
{
    int hash_index;
    Row *row;

    hash_index = RSHash(no);

    // Ýlk eleman
    if (table.rows[hash_index].numara == no)
        return table.rows[hash_index].index;

    // Linked list içinde ara
    row = table.rows[hash_index].pNext;

    while (row)
    {
        if (row->numara == no)
            return row->index;

        row = row->pNext;
    }

    return -1;
}


//------------------ TABLOYU YAZDIR ------------------
void Display_Table()
{
    int i;
    Row *row;

    puts("\n***Tablo***\n");

    for (i = 0; i < MAX_ROW; ++i)
    {
        if (table.rows[i].index != -1)
        {
            printf("%2d: %d ", table.rows[i].index, table.rows[i].numara);

            row = table.rows[i].pNext;

            while (row)
            {
                printf("-> %2d: %d ", row->index, row->numara);
                row = row->pNext;
            }

            printf("\n");
        }
    }
}


//------------------ MAIN ------------------
int main()
{
    int i, index;

    int numaralar[MAX_ROW] = {
        15, 26, 6, 58, 35, 95, 86,
        21, 14, 18, 27, 33, 10, 7, 16, 38
    };

    initialize_Table();

    for (i = 0; i < MAX_ROW; ++i)
        add_Row(numaralar[i]);

    int aranan = numaralar[5];   // 95
    index = find_row(aranan);

    printf("\n\n%d numarali kayit %d. indextedir\n", aranan, index);

    Display_Table();

    getch();
    return 0;
}

