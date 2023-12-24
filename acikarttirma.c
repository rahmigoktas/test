#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	
// Ürünleri temsil eden struct
// kullanacağımız verileri yapının içine atıyoruz
// Struct : verileri tanımlayıp main içinde kullanmamızı sağlar bir nevi  kalıtım gibi
// Pointer : verilerin bellekte tutulma adresleridir 
struct Urun {
    char isim[50];
    double baslangicFiyati;
    double enYuksekTeklif;
    char kazananKisi[50];
};

// Açık artırmayı başlatan fonksiyon
void artirmaBaslat(struct Urun *urun, double baslangicFiyati) {// bu fonksiyonda urun adlı yapının bellekteki adresini alıyoruz 
																// çünkü o yapıdaki verileri fonksiyonda kullanmak için 
    urun->baslangicFiyati = baslangicFiyati;// bu kısımda urunun en yuksek teklifi baslangıç fiyatına atıyoruz 
    urun->enYuksekTeklif = baslangicFiyati;
}

// Teklif veren fonksiyon
void teklifAl(struct Urun *urun, char kisiAdi[50]) {//urun adlı yapıdaki verileri fonksiyon içinde kullnacağımız için fonksiyon içinde çağırıyoruz 
    double teklif;
    printf("%s, teklifinizi giriniz: ", kisiAdi);
    scanf("%lf", &teklif);// burada teklif alınacak

    if (teklif > urun->enYuksekTeklif) {// verilen teklif en yuksek teklif den fazla ise
        urun->enYuksekTeklif = teklif; // en yuksek teklifi verilen teklife eşitleyecek
        strcpy(urun->kazananKisi, kisiAdi); // ve bir önceki ad yerine en yuksek teklifi veren kişinin ismini kopyalayacak
        printf("Yeni en yüksek teklif: %.2f, %s kazandı!\n", urun->enYuksekTeklif, urun->kazananKisi);
    } else {
        printf("Mevcut en yüksek tekliften daha yüksek bir miktar vermelisiniz.\n");// verilen teklif en yuksek tekliften az ise hata mesajı verecek
    }
}

int main() {
	 // Ürün oluşturma
    struct Urun acikArtirmaUrunu;
    printf("urun adini  giriniz: ");
    scanf("%s", acikArtirmaUrunu.isim);
    printf("Baslangic fiyatini giriniz: ");
    scanf("%lf", &acikArtirmaUrunu.baslangicFiyati);

    // Açık artırma başlatma
    artirmaBaslat(&acikArtirmaUrunu, acikArtirmaUrunu.baslangicFiyati);// burada fonsiyonu cağırıyoruz 

    // Katılımcı sayısını al
    int kisiSayisi;
    printf("Acik artirmaya katilacak kisi sayisini giriniz: ");
    scanf("%d", &kisiSayisi);

    // Açık artırma örnekleri
    int i;
    // kisi sayisina kadar teklif alacak ve sonunda teklif al fonksiyonuyla bir önceki kişinin verdiği teklifle değerlendirecek
    for (i = 0; i < kisiSayisi; i++) {
        char kisiAdi[50];
        printf("Katilimci %d adini giriniz: ", i + 1);
        scanf("%s",&kisiAdi);
        teklifAl(&acikArtirmaUrunu, kisiAdi);
    }

	return 0;
}
