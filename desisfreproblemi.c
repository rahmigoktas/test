#include <stdio.h>
#include <stdlib.h>


// input >>> the quick brown fox jumps over the lazy dog
//  Kaydırma Miktarı >>> 3 
// output >>>> wkh txlfn eurzq ira mxpsv ryhu wkh odcb grj


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


		void desifre(char kelime[], int kaydirma) {// desifre adında fonksiyon oluşturuyoruz 2 tane de argüman ekliyoruz(kelime,kaydırma miktarı)
		int i;
    	for (i = 0; kelime[i] != '\0'; i++) // kelimenin 0 .indexinden başlayıp en sonuncu dolu indexine kadar gidecek
		{
        
        	if (isalpha(kelime[i])) // Eğer karakter bir harf ise
			{
            
            	if (islower(kelime[i])) 	// Küçük harf ise
				{
				
                	kelime[i] = 'a' + (kelime[i] - 'a' + kaydirma) % 26;  // kaymayı bulacağız
            	}
            
            	else if (isupper(kelime[i])) // Büyük harf ise
			 	{
			 		
                	kelime[i] = 'A' + (kelime[i] - 'A' + kaydirma) % 26;  // kaymayı bulacağız
            	}
        }
    }
}

int main() {
	char kelime[100];
    int kaydirma;

    // Kullanıcıdan metni ve kaydırma miktarını al
    printf("Metni giriniz: ");
    fgets(kelime, sizeof(kelime), stdin);
    printf("Kaydirma miktarini giriniz: ");
    scanf("%d", &kaydirma);

   
    desifre(kelime, kaydirma);// başta tanımladığımız fonksiyonu argümanlarını da yazarak çağırıyoruz 

    // Sonucu ekrana yazdır
    printf("Sifrelenmis metin: %s", kelime);
	
	return 0;
}
