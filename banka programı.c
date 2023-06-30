#include<stdio.h>
#include<conio.h> //getch() fonksiyonu için kullanılmıştır.
#include<Windows.h> //Sleep() ve system("CLS") fonksiyonları için kullanılmıştır.
void main()
{ 
	int bakiye=1000,yatanpara,cekilenpara,gonderilenpara; //Başlangıç parası 1000 olarak tanımlanmıştır. İsteğe bağlı olarak değiştirilebilir.
	int k; //switch-case yapısı için tanımlanmıştır.
	char kullaniciadi[6]="bulut"; //Kullanıcı adı "bulut" olarak tanımlanmıştır.
	char kullanici[30]="0";
	int adkontrol=0;
	int kullanicisifresi=2013; //Kullanıcı şifresi 2013 olarak tanımlanmıştır.
	int sifre;
	char cevap; //do-while yapısı için tanımlanmıştır.
	printf("\n\t\t\t =Banka Hesap Sistemi Programi=\n");
	for(;;) //Kullanıcı adı girişi için sonsuz döngü oluşturulmuştur. İsteğe bağlı olarak while(1) sonsuz döngüsü de kullanılabilir.
	{ 
		printf("\n Kullanici Adinizi Giriniz:");
		scanf("%s",kullanici);
		fflush(stdin); //Girilen veri değişkene aktarıldıktan sonra gerekli alan boşaltılmaktadır.
		adkontrol=strcmp(kullanici,kullaniciadi); //kullanici ile kullaniciadi dizileri karşılaştırılmaktadır.
		if(adkontrol!=0) //Kullanıcının girmiş olduğu kullanıcı adıyla, sistemde kayitli kullanıcı adının uyuşmaması halinde if komutu çalışır. 
		{ 	 
			printf("\n Yanlis Kullanici Adi Girdiniz.\n");
			printf(" Lutfen Tekrar Deneyiniz.\n");
			printf("\n Lutfen Bekleyiniz...");
			Sleep(2000); //Programa gerçeklik katması amacıyla kullanılmıştır.
			system("CLS"); //Ekrandaki her şeyin silinmesi sağlanmaktadır.
			printf("\n\n");
			continue; //Tekrar for döngüsüne dönülmesi sağlanmaktadır.
		}
         
		else //Kullanıcının girmiş olduğu kullanıcı adıyla, sistemde kayitli kullanıcı adının uyuşması halinde else komutu çalışır.
		{   
			printf("\n Kullanici Adiniz Dogrulanmaktadir...");
			Sleep(2000);
			system("CLS");
			printf("\n Kullanici Adiniz Dogrudur.\n");
			break; //for döngüsünden çıkış sağlanmaktadır.
		}
  	
	}
   	for(;;) //Kullanıcı şifresi girişi için sonsuz döngü oluşturulmuştur. İsteğe bağlı olarak while(1) sonsuz döngüsü de kullanılabilir.
	{ 
	    printf("\n Lutfen Kullanici Sifrenizi Giriniz:");
	    scanf("%d",&sifre);
	    fflush(stdin); //Girilen veri değişkene aktarıldıktan sonra gerekli alan boşaltılmaktadır.
	    if(kullanicisifresi!=sifre) //Kullanıcı tarafından girilen şifre, sistemde kayıtlı olan kullanıcı şifresine eşit değilse if komutu çalışır. 
	    {	 
		    printf("\n Yanlis Sifre Girdiniz.\n");
	            printf(" Lutfen Tekrar Deneyiniz.\n");
		    printf("\n Lutfen Bekleyiniz...");
		    printf("\n\n");
		    Sleep(2000);
		    system("CLS");
		    continue; //Tekrar for döngüsüne dönülmesi sağlanmaktadır.
            }

	    else //Kullanıcı tarafından girilen şifre, sistemde kayıtlı olan kullanıcı şifresine eşit ise else komutu çalışır.
	    {   
		    printf("\n Kullanici Sifreniz Dogrulanmaktadir...");
		    Sleep(2000);
		    system("CLS");
		    printf("\n Kullanici Sifreniz Dogrudur.\n\n");
		    Sleep(1000);
		    system("CLS");
		    printf("\n Hosgeldiniz, ");
		    printf("%c\n",puts(kullanici)); //Kullanıcının, kullanıcı adı ekrana yazılmaktadır.
		    do
		    { 
			Menu: //goto fonksiyonu için kullanılmıştır.
			printf(" ISLEM MENUSU\n");
			printf(" ============\n\n");
			printf(" 1-Hesap Bakiyesi Goruntuleme\n");
			printf(" 2-Hesaba Para Yatirma\n");
			printf(" 3-Hesaptan Para Cekme\n");
			printf(" 4-Para Gonderme\n");
			printf(" 5-Cikis\n");
			printf("\n Luften Rakam Girerek Yapacaginiz Islemi Seciniz (1/2/3/4/5): ");
			scanf("%d",&k);
			fflush(stdin);
			printf("\n");
			switch(k)
			{  					
				case 1: //Hesap bakiyesi görüntüleme.
					system("CLS");
					printf("\n Hesap Bakiyesi Goruntuleme");
					printf("\n --------------------------");
					printf("\n\n Hesabinizda Bulunan Para: %d TL \n",bakiye);
					printf("\n\n");
					break;

				case 2: //Hesaba para yatırma.
					system("CLS");
					printf("\n Hesaba Para Yatirma");
					printf("\n -------------------");
					printf("\n\n Hesabiniza Yatacak Para Tutarini Giriniz:");
					scanf("%d",&yatanpara);
					bakiye=bakiye+yatanpara;
					printf(" Hesabiniza Yatan Para: %d TL \n",yatanpara);
					printf(" Hesabinizda Bulunan Para: %d TL \n",bakiye);
					printf("\n\n");
					break;

				case 3: //Hesaptan para çekme.
					while(1)
					{	
						system("CLS");
						printf("\n Hesaptan Para Cekme");
						printf("\n -------------------");
						printf("\n\n Hesabinizdan Cekilecek Para Tutarini Giriniz:");
						scanf("%d",&cekilenpara);
						if(cekilenpara<=bakiye)
						{ 
							bakiye=bakiye-cekilenpara;
							printf(" Hesabinizdan Cekilen Para: %d TL \n",cekilenpara);
							printf(" Hesabinizda Kalan Para: %d TL \n",bakiye);
							break;
						}

						else
						{ 
							printf("\n Bakiyeniz Yetersiz.\n");
							printf(" Hesabinizdan Cekilecek Para Tutarini Tekrar Giriniz.\n\n");
							Sleep(2000);
							continue;
						}
					}
					printf("\n\n");
					break;

				case 4: //Para gönderme.
					while(1)
					{	
						system("CLS");
						printf("\n Para Gönderme");
						printf("\n -------------");
						printf("\n\n Hesabinizdan Gonderilecek Para Tutarini Giriniz:");
						scanf("%d",&gonderilenpara);
						if(bakiye>=gonderilenpara)
						{ 
							bakiye=bakiye-gonderilenpara;
							printf(" Hesabinizdan Gonderilen Para Tutari: %d TL \n",gonderilenpara);
							printf(" Hesabinizda Kalan Para: %d TL \n",bakiye);
							break;
						}
						else 
						{   
							printf("\n");
							printf(" Bakiyeniz Yetersiz.\n");
							printf(" Hesabinizdan Gonderilecek Para Tutarini Tekrar Giriniz.\n");
							Sleep(2000);
							continue;
						}

					}
					printf("\n\n");
					break;

				case 5: //Banka sisteminden çıkış yapma.
					system("CLS");
					printf("\n");
					goto cikis; //Kullanıcı direkt olarak çıkışa yönlendirilir. (NOT: goto kullanımı tavsiye edilmez. Bunun yerine döngüler kullanılabilir.)
       
					default: //Kullanıcının 1-2-3-4-5 dışında bir seçenek girmesi halide default yapısı çalışır.
					system("CLS");
					printf("\n Boyle Bir Islem Secenegi Yoktur. Lutfen Tekrar Deneyiniz.\n");
					printf("\n");
					goto Menu; //Kullanıcı direkt olarak menüye yönlendirilir.
					break;
			} 
			printf(" Baska Islem Yapmak Istiyor Musunuz? ( (E)vet - (H)ayir )");
			cevap=getch(); //Kullanıcının cevabı cevap değişkenine aktarılmaktadır.
			system("CLS");
			printf("\n");
		}
		while(cevap=='E' || cevap=='e'); //cevap değişkeninin 'E' veya 'e' olması halinde menü ekrana gelecektir.
		if(cevap=='H' || cevap=='h') //cevap değişkeninin 'H' veya 'h' olması halinde döngüden çıkılacak ve çıkış işlemi gerçekleşecektir.
		break;
	      }
        }
	cikis:
        printf(" Cikis");
	printf("\n -----");
	printf("\n\n Banka Sistemi Programindan Cikis Yaptiniz.");
	printf("\n Banka Sistemi Programini Kullandiginiz Icin Tesekkur Ederiz.");
	Sleep(2000);
	system("CLS");
	printf("\n Programi Kapatmak Icin Bir Tusa Basiniz.");
	getch(); //Herhangi bir tuşa basıldığında program kapanacaktır.
}