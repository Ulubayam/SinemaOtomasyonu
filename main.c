#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

enum Salonlar
{
	Red=1,
	Green,
	Blue

};

typedef struct
{
	int koltuk[50];
	int BiletliKisiSayisi;

}Seanslar;
typedef struct
{
	int SalonNo;
	Seanslar seansbilgileri[5];
	int Hasilat;




}SalonBilgisi;




int hasilat;



int main()
{


FILE *sifre=fopen("sifre.txt","w+");
FILE *dosya=fopen("sinemabilgileri.txt","w+");
int salonsecim,seanssecim,i;
	SalonBilgisi S1,S2,S3;
	S1.SalonNo=Red;
	S2.SalonNo=Green;
	S3.SalonNo=Blue;
	S1.Hasilat=0;
	S2.Hasilat=0;
	S3.Hasilat=0;
	int sorgu=1;
	for( i=0;i<5;i++)
	{
    S1.seansbilgileri[i].BiletliKisiSayisi=0;

	}
	for(i=0;i<5;i++)
	{
    S2.seansbilgileri[i].BiletliKisiSayisi=0;

	}
	for( i=0;i<5;i++)
	{
    S3.seansbilgileri[i].BiletliKisiSayisi=0;

	}
    int alinansifre,sifregirilen,olusturulansifre;
int girisonayi=0;
printf("Sadece rakamlardan olusan bir sifre olusturunuz:");
scanf("%d",&olusturulansifre);
fprintf(sifre,"%d",olusturulansifre);
rewind(sifre);
fscanf(sifre,"%d",&alinansifre);

int denemesayisi=0;
while(girisonayi==0)
{

    printf("Sifre giriniz:");
scanf("%d",&sifregirilen);
if(alinansifre!=sifregirilen)
{
   printf("Hatali Sifre Girdiniz(Kalan deneme sayisi:%d\n",3-denemesayisi);
   if(denemesayisi==3)
   {
       printf("Hesabiniz bloke oldu,program kapatiliyor...\n");
       exit(1);



   }
   denemesayisi++;

}


else
{
    system("cls");
    printf("HOSGELDINIZ\n");
  break;
}


}

while(alinansifre=sifregirilen)
{


while(sorgu!=0)
{
    printf("**********Sinema Salonu islem Menusu**********\n");
    printf("1-Bilet Satin Al\n");
    printf("2-Hasilat Bilgilerini Yazdir\n");
    printf("3-Salon Bilgilerini Goster\n");
    printf("4-Cikis\n");
    printf("***********************************************\n");
    int menusecim;
    scanf("%d",&menusecim);
    switch(menusecim)
    {

    case 1:


        printf(" RED   Sinema Salonunda Big Fish Filmi Gosterilmektedir.\n");
        printf(" GREEN Sinema Salonunda Sherlock Holmes Filmi Gosterilmektedir.\n");
        printf(" BLUE  Sinema Salonunda Captan America Filmi Gosterilmektedir.\n");
		printf(" Hangi Sinema Salonunda Izlemek Istiyorsunuz?\n (RED icin:1/GREEN icin:2/BLUE icin:3 Seciniz):");
		scanf("%d",&salonsecim);

		switch(salonsecim)
		{
			case 1:
				printf("Seans Seciniz\n1\t2\t3\t4\t5\n");

                scanf("%d",&seanssecim);
                if(seanssecim>5 && seanssecim<=0)
                {
                    printf("Hatali Tuslama Girdiniz\n");
                    break;
                }
                Seanslar *seanspointer1;
                seanspointer1=S1.seansbilgileri;

                int mevcutbiletlis1=(seanspointer1+seanssecim-1)->BiletliKisiSayisi;
                if(mevcutbiletlis1!=50)
                {
                    (seanspointer1+seanssecim-1)->koltuk[mevcutbiletlis1]=1;
                    (seanspointer1+seanssecim-1)->BiletliKisiSayisi++;
                    S1.Hasilat+=UcretHesapla(seanspointer1);
                    system("cls");
                printf("Bilet Satin Alindi\n");
                }
                else
                {
                    printf("Salon Dolu");
                }





				break;

			case 2:
			printf("Seans Seciniz\n1\t2\t3\t4\t5\n");
			          scanf("%d",&seanssecim);
                Seanslar *seanspointer2;
                seanspointer2=S2.seansbilgileri;
                   int mevcutbiletlis2=(seanspointer2+seanssecim-1)->BiletliKisiSayisi;
                if(mevcutbiletlis2!=50)
                {
                    (seanspointer2+seanssecim-1)->koltuk[mevcutbiletlis2]=1;
                    (seanspointer2+seanssecim-1)->BiletliKisiSayisi++;
                    S2.Hasilat+=UcretHesapla(seanspointer2);
                    system("cls");
                printf("Bilet Satin Alindi\n");
                }
                else
                {
                    printf("Salon Dolu\n");
                }


			break;

			case 3:
			printf("Seans Seciniz\n1\t2\t3\t4\t5\n");
			          scanf("%d",&seanssecim);
               Seanslar *seanspointer3;
                seanspointer3=S3.seansbilgileri;

                int mevcutbiletlis3=(seanspointer3+seanssecim-1)->BiletliKisiSayisi;
                if(mevcutbiletlis3!=50)
                {



                (seanspointer3+seanssecim-1)->koltuk[mevcutbiletlis3]=1;
                (seanspointer3+seanssecim-1)->BiletliKisiSayisi++;
                S3.Hasilat+=UcretHesapla(seanspointer3);
                system("cls");
                printf("Bilet Satin Alindi\n");
                }

                else
                {
                    printf("Salon Dolu");

                }
			break;

			default:
                printf("Hatali Tuslama Yaptiniz\n");

                break;


		}


        break;



            case 2:
             system("cls");
            DosyayaYazdir(dosya,S1,S2,S3);
            int j=0,c;
            int bilgiler[20];
            int arttirma=6;

            printf("Hasilat Bilgileri\n");
            rewind(dosya);
            while(fscanf(dosya,"%d",&bilgiler[j])!=EOF)
            {
                if(j==0)
                printf("Red Sinema Salonu Hasilati:%d\n",bilgiler[j]);
                else if(j==6)
                printf("Green Sinema Salonu Hasilati:%d\n",bilgiler[j]);
                else if(j==12)
                printf("Blue Sinema Salonu Hasilati:%d\n",bilgiler[j]);

                j++;
            }






            break;


            case 3:
            DosyayaYazdir(dosya,S1,S2,S3);
            system("cls");
            rewind(dosya);
            printf("Izlenme Bilgileri\n");
            int k=-1,t=0;
               while(fscanf(dosya,"%d",&bilgiler[t])!=EOF)
            {
                if(t==0)
                printf("RED   SALONU IZLENME SAYILARI\n");
                else if(t==6)
                printf("GREEN SALONU IZLENME SAYILARI\n");
                else if(t==12)
                printf("BLUE  SALONU IZLENME SAYILARI\n");

                else if(t>=1 && t<6)
                {
                    k++;
                    printf("%d. Salondaki Izlenme Sayisi:%d\n",k+1,bilgiler[t]);
                    if(k==4)k=-1;

                }

                 else if(t>=6 && t<12)
                {
                    k++;
                    printf("%d. Salondaki Izlenme Sayisi:%d\n",k+1,bilgiler[t]);
                    if(k==4)k=-1;

                }

                 else if(t>=13 && t<18)
                {
                    k++;
                    printf("%d. Salondaki Izlenme Sayisi:%d\n",k+1,bilgiler[t]);
                    if(k==4)k=-1;

                }
                t++;





            }




            break;

            case 4:
                sorgu=0;
                break;






}
}
break;
}
}
int  UcretHesapla(SalonBilgisi *tmpSalon)
{

	int secim;

	int sonuc=0;
    printf("Ucret Icin Secim Yapiniz : Ogrenci icin 1'i,Tam icin 2'yi tuslayiniz:");
    scanf("%d",&secim);

    switch(secim)
    {
    	case 1:
    	sonuc+=20;
    	break;
    	case 2:
    	sonuc+=30;
    	break;
	}
	return sonuc;




}

void DosyayaYazdir(FILE *dosya,SalonBilgisi s1,SalonBilgisi s2,SalonBilgisi s3)
{

            rewind(dosya);
            int j=0,c;
            int bilgiler[20];
            int arttirma=6;


            fprintf(dosya,"%d\n",s1.Hasilat);
            int i;

            for(i=0;i<5;i++)
            {
            fprintf(dosya,"%d\n",s1.seansbilgileri[i].BiletliKisiSayisi);

            }
            fprintf(dosya,"%d\n",s2.Hasilat);
            i=0;
            for(i=0;i<5;i++)
            {
            fprintf(dosya,"%d\n",s2.seansbilgileri[i].BiletliKisiSayisi);

            }
             fprintf(dosya,"%d\n",s3.Hasilat);
            i=0;
            for(i=0;i<5;i++)
            {
            fprintf(dosya,"%d\n",s3.seansbilgileri[i].BiletliKisiSayisi);

            }



}


