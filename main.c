#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
int PCTahmin(int altSinir,int ustSinir);
int KullaniciTahmin(int altSinir,int ustSinir);
int main() {
    srand(time(NULL));
    setlocale(LC_ALL,"Turkish");
    int altSinir,ustSinir,PCTahminSayi,kullaniciTahminSayi;
    char secim;
    wprintf(L"***Sayı Tahmin Oyunu***\n"
                "Alt Sınır ve Üst Sınırı Girin (min:0 max:32767) : ");
    while (1){
        scanf("%d%d",&altSinir,&ustSinir);
        if(altSinir<ustSinir)
            break;
        else
            wprintf(L"Lütfen Önce Alt Sınırı Giriniz\n");
    }

    while(1) {
        wprintf(L"\n 1. Önce Bilgisayar Sayı Tutsun\n"
                " 2. Önce Ben Sayı Tutacağım\n"
                " c. Çıkış\n");

        scanf(" %c",&secim);
        switch (secim) {
            case '1':
                kullaniciTahminSayi=KullaniciTahmin(altSinir, ustSinir);

                wprintf(L"Simdi Sıra Bende\n");
                PCTahminSayi= PCTahmin(altSinir,ustSinir);
                if(PCTahminSayi > kullaniciTahminSayi)
                    wprintf(L"\nSen Daha Az Denemede Buldun ve Oyunu Kazandın");
                else if(PCTahminSayi < kullaniciTahminSayi)
                    wprintf(L"\nBen Daha Az Denemede Buldum ve Oyunu Kazandım");
                else{
                    wprintf(L"\nOyun Berabere Bitti");
                }
                break;

            case '2':
                PCTahminSayi=PCTahmin(altSinir, ustSinir);
                if(PCTahminSayi){
                    wprintf(L"\nŞimdi Sıra Sende\n");
                    kullaniciTahminSayi=KullaniciTahmin(altSinir, ustSinir);
                    if(PCTahminSayi > kullaniciTahminSayi)
                        wprintf(L"\nSen Daha Az Denemede Buldun ve Oyunu Kazandın");
                    else if(PCTahminSayi < kullaniciTahminSayi)
                        wprintf(L"\nBen Daha Az Denemede Buldum ve Oyunu Kazandım");
                    else{
                        wprintf(L"\nOyun Berabere Bitti");
                    }
                }
                break;
            case 'c':
                wprintf(L"Çıkış Yapılıyor");
                return 0;
            default:
                wprintf(L"Hatalı Seçim. Lütfen Geçerli Bir Seçim Yap : ");
        }
    }
}
int PCTahmin(int altSinir,int ustSinir){
    int PCtahmin,PCtahminustsinir,tahminSayisi=0;
    char hazirMisin,cevap;
    PCtahminustsinir=ustSinir+1-altSinir;
    wprintf(L"%d ile %d Arasında Bir Sayı Tut\n"
            "Tuttun mu ? (hazır olduğunda e, aksi halde çıkış yapmak için herhangi bir tuş gir) : ",altSinir,ustSinir);
    scanf(" %c",&hazirMisin);
    if(hazirMisin!='e'){
        wprintf(L"\nHazır Değilsiniz Program Kapatıldı");
        return 0;
    }
    else{
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
                    PCtahminustsinir=ustSinir-altSinir+1;
                    break;
                case 'd':
                    tahminSayisi++;
                    break;
                default:
                    wprintf(L"Yanlış Bir Tuş Girdiniz Lütfen Tekrar Deneyiniz\n");
                    scanf(" %c",&cevap);
                    goto def;
            }

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
        wprintf(L"\n%d Denemede Buldum",tahminSayisi);}
    return tahminSayisi;

}
int KullaniciTahmin(int altSinir,int ustSinir){

    int PCRastSayi=rand()%(ustSinir-altSinir)+altSinir;
    int kullaniciTahmin,kullaniciTahminSayisi=1;
    wprintf(L"%d ile %d Arasında Bir Sayı Tuttum. Tahminin : ",altSinir,ustSinir);
    scanf("%d",&kullaniciTahmin);
    while(PCRastSayi != kullaniciTahmin){
        kullaniciTahminSayisi++;
        if(PCRastSayi > kullaniciTahmin)
            wprintf(L"Daha Büyük Bir Sayı Tuttum. Yeni Tahminin : ");
        else{
            wprintf(L"Daha Küçük Bir Sayı Tuttum. Yeni Tahminin : ");
        }
        scanf("%d",&kullaniciTahmin);
    }
    wprintf(L"%d Denemede Buldun\n",kullaniciTahminSayisi);


    return kullaniciTahminSayisi;
}