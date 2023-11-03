#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <time.h>
#include <stdbool.h>
#define oyuncuIsaret 'X'
#define bilgisayarIsaret 'O'

char kazananKisi = ' ';
void kazananKontrol(); // kazanan kisiyi dondur yoksa bosluk dondur
bool tumKutucuklarDoluMu(); // 1 & 0
void yazdirDuzlem();
void oyuncuGirdisi();
void bilgisayarSirasi();

char duzlem[3][3] = {"   ","   ","   "};

int main(void){
    do{

        yazdirDuzlem();
        printf("oynamak istediginiz yeri satir ve sutun olarak sirasiyla giriniz (x,y): ");
        oyuncuGirdisi();
        bilgisayarSirasi();
        kazananKontrol();
        printf("-----------------\n");


    }while(!(tumKutucuklarDoluMu()) && !(kazananKisi == 'X' || kazananKisi == 'O' )); // iki kere mi fonksiyon calisiyor?
    yazdirDuzlem();
    switch (kazananKisi)
    {
    case ' ':
        printf("Berabere!");
        break;
    case 'O':
        printf("Kaybettiniz!");
        break;
    case 'X':
        printf("Kazandiniz!");
        break;
    default:
        printf("beklenmedik hata...");
        break;
    }
}

void yazdirDuzlem(){
    printf("|------|------|------|\n"
           "|  %c   |  %c   |  %c   |\n"
           "|------|------|------|\n"
           "|  %c   |  %c   |  %c   |\n"
           "|------|------|------|\n"
           "|  %c   |  %c   |  %c   |\n"
           "|------|------|------|\n",
           duzlem[0][0],duzlem[0][1],duzlem[0][2],duzlem[1][0],duzlem[1][1],duzlem[1][2],duzlem[2][0],duzlem[2][1],duzlem[2][2]
           );
}
void oyuncuGirdisi(){
    short sutun,satir;
    scanf("%d %d",&satir,&sutun);
    satir--;
    sutun--;
    if((duzlem[satir][sutun] !=' ') || !(satir >= 0 && satir <= 3 && sutun >= 0 && sutun <= 3)){ // x,y girdisi tablonun icinde mi? secilen yer bos mu ?
        fprintf(stderr,"HATA TEKRAR DENEYIN\n");
        oyuncuGirdisi();
    }
    else{
        duzlem[satir][sutun] = oyuncuIsaret;
    }
}
void bilgisayarSirasi(){
    int hafiza_x[9],hafiza_y[9],sayac = 0; // ilk bos yerler bulunur
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if(duzlem[i][j] == ' '){
                hafiza_x[sayac] = j;
                hafiza_y[sayac] = i;
                sayac++;
            }
        }
    }
    srand(time(0));
    short secilen_sayi = rand() % sayac; // ardindan rasgele bir yer secilir
    duzlem[hafiza_y[secilen_sayi]][hafiza_x[secilen_sayi]] = bilgisayarIsaret;
}
bool tumKutucuklarDoluMu(){
    bool dolulukDurumu = 1; // tum kutucuklar kontrol edilir eger bos yer varsa doluluk durumu 0 atanır
    for (short i = 0; i < 3; i++)
    {
        for (short j = 0; j < 3; j++)
        {
            if (duzlem[i][j] == ' ')
            {
                dolulukDurumu = 0;
            }
        }
    }
    return dolulukDurumu;
}
void kazananKontrol(){
    // 1- yatay kontrol
    for (short i = 0; i < 3; i++)
    {
        if((duzlem[i][0] == duzlem[i][1] && duzlem[i][0] == duzlem[i][2])){
            //printf("case1\n");
            kazananKisi = duzlem[i][0];
        }
    }
    // 2- dikey kontrol
    for (short i = 0; i < 3; i++)
    {
        if((duzlem[0][i] == duzlem[1][i] && duzlem[0][i] == duzlem[2][i])){
            //printf("case2\n");
            kazananKisi = duzlem[0][i];
        }
    }
    // 3- sol capraz kontrol
    if((duzlem[0][0] == duzlem[1][1] && duzlem[0][0] == duzlem[2][2])){
        //printf("case3\n");
        kazananKisi = duzlem[0][0];
    }
    // 4 -sağ çapraz kontrol
    else if((duzlem[0][2] == duzlem[1][1] && duzlem[0][2] == duzlem[2][0])){
        //printf("case4\n");
        kazananKisi = duzlem[0][2];
    }
}

