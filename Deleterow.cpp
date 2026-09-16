#include <stdio.h>      // printf, puts gibi fonksiyonlar için gerekli
#include <stdlib.h>     // standart kütüphane
#include <string.h>     // string iþlemleri için (burada kullanýlmadý)
#define MAX_ROW 15      // Hash tablosu boyutu 15

// Bir satýrý temsil eden yapý
typedef struct _Row{ 
	int index;          // satýrýn indeks numarasý (-1 ise boþ demek)
	int numara;         // o satýrda tutulan veri (kaydedilen sayý)
}Row;

// Hash tablosu yapýsý
typedef struct _Table{
	Row rows[MAX_ROW];  // 15 elemanlýk Row dizisi
}Table;

// Hash tablosu deðiþkeni
Table table;

// Fonksiyon prototipleri
void initialize_Table();
int hashing1(int no);
int hashing2(int no);
void doubleHashing(int no);
void add_Row(int no);
void display_Table();
void delete_Row(int no);

// Birinci hash fonksiyonu
int hashing1(int no){
	return no % MAX_ROW;   // sayýnýn tablodaki ilk konumu
}

// Ýkinci hash fonksiyonu (double hashing için)
int hashing2(int no){
	return (10 - (no % 10)); // ikinci adým (çakýþma çözümü için)
}

// Tabloyu baþlangýç deðerlerine getirir
void initialize_Table(){ 
	int i;
	for (i = 0; i < MAX_ROW; ++i)
	{ 
		table.rows[i].index = -1;   // -1 = “boþ”
		table.rows[i].numara = -1;  // -1 = “boþ”
	}
}

// Hash tablosuna ekleme fonksiyonu
void add_Row(int no){ 
	int hash_index = hashing1(no);  // ilk indeks hesaplanýr

	// Eðer ilk indeks boþsa direkt ekle
	if (table.rows[hash_index].index == -1)	{ 
		table.rows[hash_index].index = hash_index;
        table.rows[hash_index].numara = no;
        return;
	}

	// Çakýþma varsa double hashing ile yer bul
	doubleHashing(no);	
}

// Double hashing ile boþ yer bulup ekleme
void doubleHashing(int no){	
	int hash1 = hashing1(no);  // ilk hash
	int hash2 = hashing2(no);  // ikinci hash

	int i = 1;                 // deneme sayýsý 1’den baþlar

	while( i < MAX_ROW){       // MAX_ROW kadar deneme yapýlýr
		int hash_index = (hash1 + i * hash2) % MAX_ROW;
		// yeni indeks hesaplanýr

		// Boþ yer bulunduysa ekle
		if(table.rows[hash_index].index == -1){
			table.rows[hash_index].index = hash_index;
			table.rows[hash_index].numara = no;
			return;
		}
		i++; // Deneme sayýsýný artýr
	}
}

// Tabloyu ekrana yazdýrýr
void Display_Table(){ 
	int i;
	puts("\n***Tablo***");
	for (i =0; i < MAX_ROW; ++i){ 
		if (table.rows[i].index!=-1){
			printf("%2d: %d ", table.rows[i].index, table.rows[i].numara);
		}
	}
	printf("\n");
}

//------------------------------------------------------------------
// NUMARA BÝLGÝSÝNE GÖRE VERÝ SÝLME FONKSÝYONU
//------------------------------------------------------------------

void delete_Row(int no) {

    int hash1 = hashing1(no);     // ilk indeks hesapla
    int hash2 = hashing2(no);     // double hashing için ikinci deðer

    int hash_index = hash1;       // ilk kontrol edilen indeks

    // 1) Ýlk indekste aranan sayý var mý?
    if (table.rows[hash_index].numara == no) {
        table.rows[hash_index].index = -1;   // indeksi boþ yap
        table.rows[hash_index].numara = -1;  // veriyi boþ yap
        return;
    }

    // 2) Deðilse double hashing ile diðer olasý yerleri kontrol et
    for (int i = 1; i < MAX_ROW; i++) {

        hash_index = (hash1 + i * hash2) % MAX_ROW;
        // yeni indeks hesaplanýyor

        // Bu indeks aradýðýmýz numarayý içeriyorsa sil
        if (table.rows[hash_index].numara == no) {
            table.rows[hash_index].index = -1;
            table.rows[hash_index].numara = -1;
            return;
        }
    }

    // 3) Hiç bulunmadýysa zaten tabloda yoktur
}

//------------------------------------------------------------------

int main(){ 
	int i;

	// Tabloda tutulacak sayýlar
	int numaralar[MAX_ROW] =  {43, 58, 15, 10, 50, 34, 27, 14, 32, 45, 88, 72};

	initialize_Table();  // tabloyu boþalt

	// numaralarý tabloya ekle
	for (i = 0; numaralar[i] != '\0'; ++i) 
		add_Row(numaralar[i]);

	Display_Table();  // tabloyu yazdýr

	delete_Row(numaralar[4]);	// 50'yi sil
	delete_Row(numaralar[6]);	// 27'yi sil

	Display_Table();  // tekrar yazdýr

	return 0;
}

