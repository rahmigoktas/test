# Ulonachi sayısını bulan algoritma

fibonacci=list()
def ulonachi(x):
    sayi1=1
    sayi2=1 
    while sayi1+sayi2<=x:
        sayi3=sayi1+sayi2
        sayi1=sayi2
        sayi2=sayi3
        fibonacci.append(sayi3)

    for i in fibonacci:
        if x%i==0:
            return f"{x} sayısı Ulonachi sayısı değildir"
        else:
             return f"{x} sayısı Ulonachi sayıdır"

print(ulonachi(47))
print(ulonachi(50))






    

