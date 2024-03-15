# Paradan 6 sıfır atma uygulaması

def sifirat(listeleme):
    sonuc=[]
    for sayi in listeleme:
        sayi=sayi/1000000
        sonuc.append(sayi)
    return sonuc
print(sifirat([25000000,74000000,450000,52000]))

