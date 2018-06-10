# VY5-15011702
2017-2018 Bahar Yarıyılı  Veri yapıları ve Algoritmalar Dersi Final Ödevi 
Konu : Aritmetik Hesaplayıcı

PROBLEMİ ÇÖZMEK İÇİN UYGULANAN YÖNTEMLER:

    ÖNCELİKLE İNPUT.TXT DOSYASINDAN BİLGİLER TEK TEK KARAKTER ŞEKLİNDE OKUNDU VE BU BİLGİLER CHAR TÜRÜNDE BİR MATRİSE SIRASIYLA KAYDEDİLDİ.
      DAHA SONRA OKUDUĞUMUZ BİLGİLERİ GÖRMEK İÇİN BU MATRİS EKRANA YAZDIRILDI.
    
    SONRA GİRİLEN FONKSİYON VE DEĞİŞKENLERİ AYIRMAK İÇİN FİND_VARİABLE İSİMLE FONKSİYON OLUŞTURULDU.BU FONKSİYON OLUŞTURDUĞUMUZ MATRİSİ
        SATIR SATIR OKUDU.EĞER OKUNAN SATIR BİR DEĞİŞKEN İSE DEİŞKENİN ADI DEĞİŞKENLER DİZİSİNE, DEĞERİ İSE DEĞİŞKENDEĞERLERİ İSİMLİ DİZİYE 
        KAYDEDİLDİ.EĞER OKUNAN SATIR BİR FONKSİYON İSE BU FONKSİYON FONKSİYONMATRİSİ İSİMLİ BİR MATRSİE KAYDEDİLDİ.BU FONKSİYON SONUCUNDA
        ELİMİZDE DEĞİŞKENLER VE DEĞİŞKEN DEĞERLERİ DİYE İKİ AYRI DİZİ VE SADECE FONKSİYONLARIN BULUNDUĞU BİR MATRİS OLUŞMUŞ OLDU.
        BU FONKSİYONDAN ÇIKMADAN ÖNCE DEĞİŞKENLER VE DEĞİŞKEN DEĞERLERİ VE FONKSİYONMATRİSİ EKRANA YAZDIRILDI.
        
    DAHA SONRA FİNDPOSTFİX İSİMLİ FONKSİYON OLUŞTURULDU.BU FONKSİYON OLUŞTURULAN FONKSİYON MATRİSİNİ SATIR SATIR GEZEREK O SATIRDAKİ 
        FONKSİYONUN POSTFİX İFADESİNİ BULDU VE EKRANA YAZDIRDI VE ARACIKISLAR MATRİSİNE BU POSTFİX İFADEYİ EKLEDİ.BÖYLECE ELİMİZDE TÜM 
        FONKSİYONLARIN POSTFİX İFADESİNİN BULUNDUĞU ARACIKISLAR MATRİSİ ELDE EDİLDİ.
        
        -FİNDPOSTFİX FONKSİYONU POSTFİX İFADEYİ BULMAK İÇİN ŞU İŞLEMLERİ UYGULADI:
                1. FONKSİYON MATRİSİNDEN BİR SATIR İÇİN O SATIRIN BÜTÜN SÜTUNLARINI GEZDİ.  
                    Eğer o anda bakılan bilgi: sol parantez ise : sol parantez yığına  push edildi.  
                                                sağ parantez ise : sol parantez  çıkana kadar yığından pop yapıldı. 
                   Alınan işlem işareti postfix ifadeye eklendi. Sol parantez görüldüğünde pop işlemine son verildi. 
                   Parantezler postfix’e eklenmedi.
                   sayı ise : postfix ifadeye eklendi.  
                   işlem işareti ise :  
                        i.) yığının en üstünde sol parantez varsa veya en üstteki işaretin önceliği gelen işaretten düşük ise işlem işareti yığına  push edildi.  
                        ii.) Gelen işaretin önceliği en üstteki işaretin önceliğinden daha düşük ise yığındaki gelen işaretten yüksek öncelikli bütün işaretler için  pop işlemi yapıldı.   
                        iii.) Stackten pop edilen işaretler postfix ifadeye eklendi.  
                        iv.) İşlem işareti  yığına  push edildi.  
                  
                  ifadeler bittiğinde : yığındaki işaretler sıra ile pop edilerek postfix ifadeye eklendi.
                  Son olarak bu postfix ifade ekrana yazdırıldı ve ARACIKISLAR matrisine eklendi.
                  
       DAHA SONRA ARACIKISLAR MATRİSİ YAZDIRILDI.
       
       SON OLARAK BU ARACIKISLARI ÇÖZMEK İÇİN SOLVEPOSTFİX FONKSİYONU OLUŞTURULDU.BU FONKSİYON ŞU İŞLEMLERİ GERÇEKLEŞTİRDİ.
            ARACIKISLAR MATRİSİ SATIR SATIR VE HER BİR SATIR İÇİN BÜTÜN SÜTUNLAR DOLAŞILARAK İFADE OKUNDU.  
         Eğer o anda bakılan karakter:  
         sayı  ise : sayı  yığına  push edildi. 
         değişken ise  : değişkenin değeri yığına  push edildi.
         işlem işareti ise : yığının üstündeki iki değer pop edildi ve bu işarete göre iki sayı arasında işlem yapıldı.İşlem sonucu                   yığının en üstüne yerleştirildi.
         BÜTÜN İFADE BİTİNCE YIĞINDA SADECE BİR ADET SAYI KALDI.OKUNAN FONKSİYON HANGİ DEĞİŞKENE AİT İSE O DEĞİŞKENİN DEĞERİ YIĞINDA 
            KALAN DEĞER İLE DEĞİŞTİRİLDİ
            
         SON OLARAK BÜTÜN DEĞİŞKEN DEĞERLERİ EKRANA YAZDIRILDI VE İŞLEM SONLANDIRILDI.
                 
  
                                                        ÖZGÜR  KAN
                                                         15011702
