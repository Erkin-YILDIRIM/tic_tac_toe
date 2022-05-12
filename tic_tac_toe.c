#include <stdio.h>//Standard Input-Output Kutuphanesi. Temel input (girdi) ve output (cikti) komutlarini barindirir.
#include <stdlib.h>//Genel Amacli Standart Kutuphane. Dinamik bellek yonetimi, rastgele sayi uretimi, tamsayi aritmetigi gibi genel fonksiyonlari icinde barindirir.

int main() {//Her C programinda olmasi gereken main() fonksiyonu.
	char birinciOyuncuAdi[] = "Player 1";
	char ikinciOyuncuAdi[]="Player 2"; //Oyuncu adlarini tutacak degiskenler deklare ediliyor.
	int birinciOyuncuHamlesi, ikinciOyuncuHamlesi; //Oyuncu hamlelerini tutacak degiskenler deklare ediliyor.
	int hamleKoordinatX , hamleKoordinatY; //Oyuncunun girdigi sayi, matematiksel bir bilgi olarak oyun tablosunun belli bir pozisyonunu gostermektedir. Bu degerlerle numara bilgisi uzerinden degistirilmek istenen array elemani bulunacaktir.
	int kazanmaDurumu = 0; // Bu "bayrak", herhangi bir oyuncu oyunu kazandýðý zaman 1 deðerini alacak ve böylece oyunun istenmeyen bir biçimde devam etmesi engellenecektir.
	int kontrolDongusu = 0; //Matrikste, herhangi bir oyuncunun kazanma sartini (tabloda yatay,dikey ya da capraz sirali 3 ayni sembol) saglayip saglamadigina for dongusu icinde bakilacaktir. for dongusu, bu sayiyi her dondugunde 2 olana kadar 1 arttiracak ve boylece yatay duzlem kontrol edilecektir.
	int donguSayisi = 1; //Eger oyun herhangi bir sekilde bitmezse hamleler oyun tarafindan alinmaya devam edecektir. Oyun maksimum 9 hamlede biter, ancak oyuncular sirali oynayacaklari icin (her iki tarafa da birer kez sira gelmeli), hamlelerin 8 tanesi for dongusu kapsamina alinacak ve son hamle ayrica kontrol edilecektir. for dongusu icinde 2 hamle olacagi icin dongu 8/2=4 defa calismalidir.
	//donguSayisi adli degisken, for dongu yapisina kacinci dongude oldugunu soyleyecektir.
	char baslangicKarakterleri[3][3] = {'1','2','3','4','5','6','7','8','9'};//Bu karakterler, ikinci turda tablodaki degerler sifirlanmak istendiginde kullanilacaktir.
	char tablo[3][3] = {'1','2','3','4','5','6','7','8','9'}; //Oyun tablosunda hamle yapilacak yerleri gösteren sayilar deklare ediliyor.
	int koordinatSifirlamaX=0;//koordinatSifirlamaX ve koordinatSifirlamaY degiskenleri, ikinci turda for dongusunde kullanýlacaktir. Bahsi gecen bu for dongusu, teker teker butun matriks degerlerine ardisik rakamlar verecektir.
	int koordinatSifirlamaY=0;//Bu degiskenin gorevi bir ust satirda belirtilmistir.
	printf("	Tic Tac Toe\n%s (X)  -  %s (O)\n\n\n",birinciOyuncuAdi,ikinciOyuncuAdi); //Oyunun adi ve kullanicilarin sembolleri, odev formatinda istendigi gibi belirtiliyor.
	printf("     |     |     \n  %c  |  %c  |  %c        \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n     |     |     \n", tablo[0][0],tablo[0][1],tablo[0][2],tablo[1][0],tablo[1][1],tablo[1][2],tablo[2][0],tablo[2][1],tablo[2][2]); //Oyuna baslarken ilk tablo cizimi yapiliyor.
	printf("Ilk oyuncunun adini yaziniz:"); scanf("%s", birinciOyuncuAdi); //Birinci oyuncunun adi aliniyor ve "birinciOyuncuAdi" adli deðiskene kaydediliyor.
	printf("Ikinci oyuncunun adini yaziniz:"); scanf("%s", ikinciOyuncuAdi); //Ikinci oyuncunun adi aliniyor ve "ikinciOyuncuAdi" adli deðiskene kaydediliyor.
	for(donguSayisi=1; donguSayisi<=4; donguSayisi++){ //Ilk 8 olasi hamleyi kontrol edecek olan for dongusu.
	if(kazanmaDurumu==0){//Hamleye baslamadan once herhangi bir oyuncunun kazanip kazanmadigini kontrol eden "bayrak". Bayrak degeri 1 ise bu, oyunculardan herhangi birinin kazandigini gosterir ve bilgisayar daha fazla hamle istemeyecektir.
	/*Birinci oyuncunun hamle kodu.*/
	printf("%s, oynamak istedigin kare numarasini gir:", birinciOyuncuAdi); scanf("%d", &birinciOyuncuHamlesi);//Birinci oyuncunun hamle yapmak istedigi kutu numarasi aliniyor.
	hamleKoordinatX = birinciOyuncuHamlesi%3; hamleKoordinatY = birinciOyuncuHamlesi/3;//Birinci oyuncunun oynadigi numara, tabloda belli bir matematiksel duzen icinde. Bu duzene gore bu numaranin, yukarida tanimlanan matrikste nereye karsilik geldigi bulunuyor.
	tablo[hamleKoordinatY][hamleKoordinatX-1] = 'X'; //Bir ustteki kodda bulunan koordinatlara gore karakter, tabloya yazdiriliyor.
	printf("	Tic Tac Toe\n%s (X)  -  %s (O)\n\n\n",birinciOyuncuAdi,ikinciOyuncuAdi); //Oyunun adi ve kullanicilarin sembolleri, odev formatinda istendigi gibi belirtiliyor.
	printf("     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n     |     |     \n", tablo[0][0],tablo[0][1],tablo[0][2],tablo[1][0],tablo[1][1],tablo[1][2],tablo[2][0],tablo[2][1],tablo[2][2]); //Oyuncunun oynadigi hamleye gore guncellenen matriks, burada tablo formatina donusturuluyor ve yazdiriliyor.
	for(kontrolDongusu=0; kontrolDongusu<=2; kontrolDongusu++){//Bu dongu, teker teker "kontrolDongusu" degiskenini arttirarak sirayla satir ya da sutunlarýn kontrolunu saglayacaktir. Alttaki if yapilarinin her birisinde, bir koordinat degeri sabit tutulup diger deger for dongusu yardimiyla degistirilmekte ve boylece satir ya da sutunlarin ardisik kontrolu yapilmaktadir.
	if(tablo[0][kontrolDongusu]=='X'&&tablo[1][kontrolDongusu]=='X'&&tablo[2][kontrolDongusu]=='X'){// Bu if yapisi, sutunlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
		} 
	if(tablo[kontrolDongusu][0]=='X'&&tablo[kontrolDongusu][1]=='X'&&tablo[kontrolDongusu][2]=='X'){// Bu if yapisi, satirlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	} 	
	}
		if(tablo[0][0]=='X'&&tablo[1][1]=='X'&&tablo[2][2]=='X'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	}
		if(tablo[0][2]=='X'&&tablo[1][1]=='X'&&tablo[2][0]=='X'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	} 
	} 
	if(kazanmaDurumu==0){//Hamleye baslamadan once herhangi bir oyuncunun kazanip kazanmadigini kontrol eden "bayrak". Bayrak degeri 1 ise bu, oyunculardan herhangi birinin kazandigini gosterir ve bilgisayar daha fazla hamle istemeyecektir.
	/*Ikinci oyuncunun hamle kodu.*/
	printf("%s, oynamak istedigin kare numarasini gir:", ikinciOyuncuAdi); scanf("%d", &ikinciOyuncuHamlesi);//Ikinci oyuncunun hamle yapmak istedigi kutu numarasi aliniyor.
	hamleKoordinatX = ikinciOyuncuHamlesi%3; hamleKoordinatY = ikinciOyuncuHamlesi/3;//Ikinci oyuncunun oynadigi numara, tabloda belli bir matematiksel duzen icinde. Bu duzene gore bu numaranin, yukarida tanimlanan matrikste nereye karsilik geldigi bulunuyor.
	tablo[hamleKoordinatY][hamleKoordinatX-1] = 'O'; //Bir ustteki kodda bulunan koordinatlara gore karakter, tabloya yazdiriliyor.
	printf("	Tic Tac Toe\n%s (X)  -  %s (O)\n\n\n",birinciOyuncuAdi,ikinciOyuncuAdi); //Oyunun adi ve kullanicilarin sembolleri, odev formatinda istendigi gibi belirtiliyor.
	printf("     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n     |     |     \n", tablo[0][0],tablo[0][1],tablo[0][2],tablo[1][0],tablo[1][1],tablo[1][2],tablo[2][0],tablo[2][1],tablo[2][2]); //Oyuncunun oynadigi hamleye gore guncellenen matriks, burada tablo formatina donusturuluyor ve yazdiriliyor.
		for(kontrolDongusu=0; kontrolDongusu<=2; kontrolDongusu++){//Bu dongu, teker teker "kontrolDongusu" degiskenini arttirarak sirayla satir ya da sutunlarýn kontrolunu saglayacaktir. Alttaki if yapilarinin her birisinde, bir koordinat degeri sabit tutulup diger deger for dongusu yardimiyla degistirilmekte ve boylece satir ya da sutunlarin ardisik kontrolu yapilmaktadir.
	if(tablo[0][kontrolDongusu]=='O'&&tablo[1][kontrolDongusu]=='O'&&tablo[2][kontrolDongusu]=='O'){// Bu if yapisi, satirlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
		} 
	if(tablo[kontrolDongusu][0]=='O'&&tablo[kontrolDongusu][1]=='O'&&tablo[kontrolDongusu][2]=='O'){// Bu if yapisi, sutunlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	} 
}
		if(tablo[0][0]=='O'&&tablo[1][1]=='O'&&tablo[2][2]=='O'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	}
		if(tablo[0][2]=='O'&&tablo[1][1]=='O'&&tablo[2][0]=='O'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
		
	} 
	} 
	} 
	if(kazanmaDurumu==0){//Hamleye baslamadan once herhangi bir oyuncunun kazanip kazanmadigini kontrol eden "bayrak". Bayrak degeri 1 ise bu, oyunculardan herhangi birinin kazandigini gosterir ve bilgisayar daha fazla hamle istemeyecektir.
	/*Birinci oyuncunun hamle kodu. Bu kod, son mümkün hamle olan dokuzuncu hamleyi oynatýr.*/
	printf("%s, oynamak istedigin kare numarasini gir:", birinciOyuncuAdi); scanf("%d", &birinciOyuncuHamlesi);//Birinci oyuncunun hamle yapmak istedigi kutu numarasi aliniyor.
	hamleKoordinatX = birinciOyuncuHamlesi%3; hamleKoordinatY = birinciOyuncuHamlesi/3;//Birinci oyuncunun oynadigi numara, tabloda belli bir matematiksel duzen icinde. Bu duzene gore bu numaranin, yukarida tanimlanan matrikste nereye karsilik geldigi bulunuyor.
	tablo[hamleKoordinatY][hamleKoordinatX-1] = 'X'; //Bir ustteki kodda bulunan koordinatlara gore karakter, tabloya yazdiriliyor.
	printf("	Tic Tac Toe\n%s (X)  -  %s (O)\n\n\n",birinciOyuncuAdi,ikinciOyuncuAdi); //Oyunun adi ve kullanicilarin sembolleri, odev formatinda istendigi gibi belirtiliyor.
	printf("     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n     |     |     \n", tablo[0][0],tablo[0][1],tablo[0][2],tablo[1][0],tablo[1][1],tablo[1][2],tablo[2][0],tablo[2][1],tablo[2][2]); //Oyuncunun oynadigi hamleye gore guncellenen matriks, burada tablo formatina donusturuluyor ve yazdiriliyor.
		for(kontrolDongusu=0; kontrolDongusu<=2; kontrolDongusu++){//Bu dongu, teker teker "kontrolDongusu" degiskenini arttirarak sirayla satir ya da sutunlarýn kontrolunu saglayacaktir. Alttaki if yapilarinin her birisinde, bir koordinat degeri sabit tutulup diger deger for dongusu yardimiyla degistirilmekte ve boylece satir ya da sutunlarin ardisik kontrolu yapilmaktadir.
	if(tablo[0][kontrolDongusu]=='X'&&tablo[1][kontrolDongusu]=='X'&&tablo[2][kontrolDongusu]=='X'){// Bu if yapisi, satirlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
		} 
	if(tablo[kontrolDongusu][0]=='X'&&tablo[kontrolDongusu][1]=='X'&&tablo[kontrolDongusu][2]=='X'){// Bu if yapisi, sutunlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	} 

	else{//Eger yukarida sayilan sartlar dahilinde kazanan olmamissa:
		printf("Ilk tur berabere\n");//Yukarida sayilan sartlar dahilinde kazanan olmamissa bu else yapisi icindeki komutlar islenir. Kazanan varsa islenmez ve oyun ilk turda biter.
		for(koordinatSifirlamaX=0; koordinatSifirlamaX<=2; koordinatSifirlamaX++){//Bu for yapisi, teker teker satir ve sutunlardaki degerleri baslangictaki tablo degerlerine geri dondurecektir.
			for(koordinatSifirlamaY=0; koordinatSifirlamaY<=2; koordinatSifirlamaY++){
		tablo[koordinatSifirlamaX][koordinatSifirlamaY]=baslangicKarakterleri[koordinatSifirlamaX][koordinatSifirlamaY];
		} 
		} 
		for(donguSayisi=1; donguSayisi<=4; donguSayisi++){ //Ilk 8 olasi hamleyi kontrol edecek olan for dongusu.
	if(kazanmaDurumu==0){//Hamleye baslamadan once herhangi bir oyuncunun kazanip kazanmadigini kontrol eden "bayrak". Bayrak degeri 1 ise bu, oyunculardan herhangi birinin kazandigini gosterir ve bilgisayar daha fazla hamle istemeyecektir.
	/*Ikinci oyuncunun hamle kodu.*/
	printf("%s, oynamak istedigin kare numarasini gir:", ikinciOyuncuAdi); scanf("%d", &ikinciOyuncuHamlesi);//Ikinci oyuncunun hamle yapmak istedigi kutu numarasi aliniyor.
	hamleKoordinatX = ikinciOyuncuHamlesi%3; hamleKoordinatY = ikinciOyuncuHamlesi/3;//Ikinci oyuncunun oynadigi numara, tabloda belli bir matematiksel duzen icinde. Bu duzene gore bu numaranin, yukarida tanimlanan matrikste nereye karsilik geldigi bulunuyor.
	tablo[hamleKoordinatY][hamleKoordinatX-1] = 'O'; //Bir ustteki kodda bulunan koordinatlara gore karakter, tabloya yazdiriliyor.
	printf("	Tic Tac Toe\n%s (X)  -  %s (O)\n\n\n",birinciOyuncuAdi,ikinciOyuncuAdi); //Oyunun adi ve kullanicilarin sembolleri, odev formatinda istendigi gibi belirtiliyor.
	printf("     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n     |     |     \n", tablo[0][0],tablo[0][1],tablo[0][2],tablo[1][0],tablo[1][1],tablo[1][2],tablo[2][0],tablo[2][1],tablo[2][2]); //Oyuncunun oynadigi hamleye gore guncellenen matriks, burada tablo formatina donusturuluyor ve yazdiriliyor.
	for(kontrolDongusu=0; kontrolDongusu<=2; kontrolDongusu++){//Bu dongu, teker teker "kontrolDongusu" degiskenini arttirarak sirayla satir ya da sutunlarýn kontrolunu saglayacaktir. Alttaki if yapilarinin her birisinde, bir koordinat degeri sabit tutulup diger deger for dongusu yardimiyla degistirilmekte ve boylece satir ya da sutunlarin ardisik kontrolu yapilmaktadir.
	if(tablo[0][kontrolDongusu]=='O'&&tablo[1][kontrolDongusu]=='O'&&tablo[2][kontrolDongusu]=='O'){// Bu if yapisi, satirlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
		} 
	if(tablo[kontrolDongusu][0]=='O'&&tablo[kontrolDongusu][1]=='O'&&tablo[kontrolDongusu][2]=='O'){// Bu if yapisi, sutunlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	} 
		
	}
		if(tablo[0][0]=='O'&&tablo[1][1]=='O'&&tablo[2][2]=='O'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	}
		if(tablo[0][2]=='O'&&tablo[1][1]=='O'&&tablo[2][0]=='O'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	} 
	} 
	if(kazanmaDurumu==0){//Hamleye baslamadan once herhangi bir oyuncunun kazanip kazanmadigini kontrol eden "bayrak". Bayrak degeri 1 ise bu, oyunculardan herhangi birinin kazandigini gosterir ve bilgisayar daha fazla hamle istemeyecektir.
	/*Birinci oyuncunun hamle kodu.*/
	printf("%s, oynamak istedigin kare numarasini gir:", birinciOyuncuAdi); scanf("%d", &birinciOyuncuHamlesi);//Birinci oyuncunun hamle yapmak istedigi kutu numarasi aliniyor.
	hamleKoordinatX = birinciOyuncuHamlesi%3; hamleKoordinatY = birinciOyuncuHamlesi/3;//Birinci oyuncunun oynadigi numara, tabloda belli bir matematiksel duzen icinde. Bu duzene gore bu numaranin, yukarida tanimlanan matrikste nereye karsilik geldigi bulunuyor.
	tablo[hamleKoordinatY][hamleKoordinatX-1] = 'X'; //Bir ustteki kodda bulunan koordinatlara gore karakter, tabloya yazdiriliyor.
	printf("	Tic Tac Toe\n%s (X)  -  %s (O)\n\n\n",birinciOyuncuAdi,ikinciOyuncuAdi); //Oyunun adi ve kullanicilarin sembolleri, odev formatinda istendigi gibi belirtiliyor.
	printf("     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n     |     |     \n", tablo[0][0],tablo[0][1],tablo[0][2],tablo[1][0],tablo[1][1],tablo[1][2],tablo[2][0],tablo[2][1],tablo[2][2]); //Oyuncunun oynadigi hamleye gore guncellenen matriks, burada tablo formatina donusturuluyor ve yazdiriliyor.
		for(kontrolDongusu=0; kontrolDongusu<=2; kontrolDongusu++){//Bu dongu, teker teker "kontrolDongusu" degiskenini arttirarak sirayla satir ya da sutunlarýn kontrolunu saglayacaktir. Alttaki if yapilarinin her birisinde, bir koordinat degeri sabit tutulup diger deger for dongusu yardimiyla degistirilmekte ve boylece satir ya da sutunlarin ardisik kontrolu yapilmaktadir.
	if(tablo[0][kontrolDongusu]=='X'&&tablo[1][kontrolDongusu]=='X'&&tablo[2][kontrolDongusu]=='X'){// Bu if yapisi, satirlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
		} 
	if(tablo[kontrolDongusu][0]=='X'&&tablo[kontrolDongusu][1]=='X'&&tablo[kontrolDongusu][2]=='X'){// Bu if yapisi, sutunlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	} 
	
	}
			if(tablo[0][0]=='X'&&tablo[1][1]=='X'&&tablo[2][2]=='X'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	}
		if(tablo[0][2]=='X'&&tablo[1][1]=='X'&&tablo[2][0]=='X'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	}
	} 
	}  
	if(kazanmaDurumu==0){//Hamleye baslamadan once herhangi bir oyuncunun kazanip kazanmadigini kontrol eden "bayrak". Bayrak degeri 1 ise bu, oyunculardan herhangi birinin kazandigini gosterir ve bilgisayar daha fazla hamle istemeyecektir.
	/*Ikinci oyuncunun hamle kodu. Bu kod, son mümkün hamle olan dokuzuncu hamleyi oynatýr.*/
	printf("%s, oynamak istedigin kare numarasini gir:", ikinciOyuncuAdi); scanf("%d", &ikinciOyuncuHamlesi);//Ikinci oyuncunun hamle yapmak istedigi kutu numarasi aliniyor.
	hamleKoordinatX = ikinciOyuncuHamlesi%3; hamleKoordinatY = ikinciOyuncuHamlesi/3;//Ikinci oyuncunun oynadigi numara, tabloda belli bir matematiksel duzen icinde. Bu duzene gore bu numaranin, yukarida tanimlanan matrikste nereye karsilik geldigi bulunuyor.
	tablo[hamleKoordinatY][hamleKoordinatX-1] = 'O'; //Bir ustteki kodda bulunan koordinatlara gore karakter, tabloya yazdiriliyor.
	printf("	Tic Tac Toe\n%s (X)  -  %s (O)\n\n\n",birinciOyuncuAdi,ikinciOyuncuAdi); //Oyunun adi ve kullanicilarin sembolleri, odev formatinda istendigi gibi belirtiliyor.
	printf("     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n_____|_____|_____\n     |     |     \n  %c  |  %c  |  %c  \n     |     |     \n", tablo[0][0],tablo[0][1],tablo[0][2],tablo[1][0],tablo[1][1],tablo[1][2],tablo[2][0],tablo[2][1],tablo[2][2]); //Oyuncunun oynadigi hamleye gore guncellenen matriks, burada tablo formatina donusturuluyor ve yazdiriliyor.
		for(kontrolDongusu=0; kontrolDongusu<=2; kontrolDongusu++){
	if(tablo[0][kontrolDongusu]=='O'&&tablo[1][kontrolDongusu]=='O'&&tablo[2][kontrolDongusu]=='O'){// Bu if yapisi, satirlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
		} 
	if(tablo[kontrolDongusu][0]=='O'&&tablo[kontrolDongusu][1]=='O'&&tablo[kontrolDongusu][2]=='O'){// Bu if yapisi, sutunlari kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	} 

	else{//Eger kazanan yoksa:

	}
		if(tablo[0][0]=='O'&&tablo[1][1]=='O'&&tablo[2][2]=='O'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	}
		if(tablo[0][2]=='O'&&tablo[1][1]=='O'&&tablo[2][0]=='O'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", ikinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	}
	}
	} 
	}	
}
		if(tablo[0][0]=='X'&&tablo[1][1]=='X'&&tablo[2][2]=='X'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	}
		if(tablo[0][2]=='X'&&tablo[1][1]=='X'&&tablo[2][0]=='X'){// Bu if yapisi, capraz karakterleri kontrol eder ve kazanma sarti meydana gelmisse kazanmaDurumu bayragina 1 degerini verir.
		kazanmaDurumu = 1;//kazanmaDurumu bayragi, bir ust satirdaki aciklamada da belirtildigi uzere 1 degerini aliyor. Bu sayede kazanan olursa baska hamle sorgusu olmayacak.
		printf("%s kazandi!", birinciOyuncuAdi);//Bu kod, bulundugu if yapisi sarti saglandiysa kullanici ya da kullanicilari bilgilendirir ve kimin kazandigini konsola yazdirir.
	}
	if(kazanmaDurumu==0){
			printf("Oyun berabere");//Odev sartlarinda belirtildigi uzere, eger ikinci turda da kazanan olmamissa, oyun berabere biter.
			}
}
return 0;//main() fonksiyonunun kod basariyla calistigi anda dondurmesi gereken deger. Programin basariyla calistirildigini programa bildirir.
}
