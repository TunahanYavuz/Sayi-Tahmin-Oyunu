#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    setlocale(LC_ALL,"Turkish");
    int PCtahmin,altSinir,ustSinir,PCtahminustsinir,tahminSayisi=0;
    char hazirMisin,cevap;
    wprintf(L"***Sayı Tahmin Oyunu***\n"
            "Alt Sınır ve Üst Sınır Girin (min:0 max:32767) : ");
    while (1){
    scanf("%d%d",&altSinir,&ustSinir);
        if(altSinir<ustSinir)
            break;
        else
            wprintf(L"Lütfen Önce Alt Sınırı Giriniz\n");
    }
    PCtahminustsinir=ustSinir+1-altSinir;
    wprintf(L"%d %d Arasında Bir Sayı Tut\n"
            "Tuttun mu ? (hazır olduğunda e, aksi halde çıkış yapmak için herhangi bir tuş gir) : ",altSinir,ustSinir);
    scanf(" %c",&hazirMisin);
    if(hazirMisin!='e'){
        wprintf(L"\nHazır Değilsiniz Program Kapatıldı");
        return 0;}
    wprintf(L"Tuttuğun Sayı Daha Büyük İse b,\n Daha Küçük İse k, Doğru İse d Gir\n");
    PCtahmin=rand()%PCtahminustsinir+altSinir;
    wprintf(L"Tahminim : %d Cevabın : ",PCtahmin);
    scanf(" %c",&cevap);
    tahminSayisi++;
    while(cevap!='d'){
        def:
        switch (cevap) {
            case 'k':
                tahminSayisi++;
                PCtahminustsinir = PCtahmin-altSinir+1;
                ustSinir=PCtahmin;
                break;
            case 'b':
                tahminSayisi++;
                altSinir = PCtahmin;
                PCtahminustsinir-=altSinir;
                break;
            case 'd':
                tahminSayisi++;
                break;
            default:
                wprintf(L"Yanlış Bir Tuş Girdiniz Lütfen Tekrar Deneyiniz\n");
                scanf(" %c",&cevap);
                goto def;
        }
        if(PCtahminustsinir<=0)
            PCtahminustsinir=ustSinir-altSinir+1;

        int tempPCtahmin=PCtahmin;
        while(PCtahmin==tempPCtahmin){
        PCtahmin=rand()%PCtahminustsinir+altSinir;}
        wprintf(L"\nYeni Tahminim : %d Cevabın : ",PCtahmin);
        scanf(" %c",&cevap);
        if((PCtahmin==altSinir&&cevap=='k')||(PCtahmin==ustSinir&&cevap=='b')){
            wprintf(L"Tuttuğun Sayı %d Sayısından Farklı Olamaz",PCtahmin);
            break;
        }
    }
    wprintf(L"\n%d Denemede Buldum",tahminSayisi);



    return 0;
}
