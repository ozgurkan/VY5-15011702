#include <stdio.h>
#include <stdlib.h>

void Read_input();
void Find_variable();
void Push(char karakter);
void Pop();
void WritePostfix();
int BuyukEsit(char,char);
void FindPostfix();
void PrintAraCikislar();
void SolvePostfix();
void WriteDegiskenDegerleri();





static char matris[100][100];
char Degiskenler[100];
static int  DegiskenDegerleri[100];
char fonksiyonMatris[100][100];



char StackArray[1000];
char Postfix[1000];
char AraCikisMatris[1000][1000];
static int SayiStack[1000];


int sp=0;
int SayiSp=0;
int i,j,k,x,y=0;


int BufferSP=0;
char buffer[256];

int main()
{
    Read_input();
    Find_variable();
    FindPostfix();
    PrintAraCikislar();
    SolvePostfix();
    WriteDegiskenDegerleri();
    return 0;
}

void Read_input(){
    //TEXT DOSYASINDAN OKUNAN BÝLGÝLER KARAKTER TÜRÜNDE MATRÝSE ALINDI VE DOSYA KAPATILDI.
     i=0;j=0;
        FILE *dosya;
        if((dosya=fopen("input.txt","r"))!=NULL){
            printf("DOSYA ACILDI....\n");
                while(!feof(dosya)){
                    char okunan;
                    fscanf(dosya,"%c",&okunan);
                    if(okunan!='\0'){
                        matris[i][j]=okunan;
                        j++;
                    }
                    if(okunan==';'){
                        j=-1;
                        i++;
                    }
                }
        fclose(dosya);
            /*MATRÝSE ALINAN BÝLGÝLER EKRANA YAZDIRILDI.*/
            i=0;
            j=0;
            while(matris[i][j]!='\0'){
                while(matris[i][j]!='\0'){
                    printf("%c",matris[i][j]);
                    j++;
                }
                printf("\n");
                j=0;
                i++;
            }
        }
 }

void Find_variable(){
    //GÝRÝLEN DEÐÝÞKENLER BAÞKA BÝR KARAKTER DÝZÝSÝNE KAYDEDÝLDÝ.
     i=0;j=0;
     int kontrol=0;
    while(matris[i][0]!='\0'){
            j=0;kontrol=0;
            while(Degiskenler[j]!='\0'){
                if(Degiskenler[j]==matris[i][0]){
                    kontrol=1;
                }
                j++;
            }
            if(kontrol==0){
               Degiskenler[j]=matris[i][0];
            }
            i++;
    }

    //GÝRÝLEN DEÐÝÞKENLER ÝÇÝN DEÐERLERÝ AYRI BÝR DÝZÝYE KAYDEDÝLDÝ.
    //GÝRÝLEN FONKSÝYONLAR AYRI BÝR MATRÝSE KOPYALANDI.
    i=0;
    j=4;
    while(matris[i][0]!='\0'){
        kontrol=0;
        BufferSP=0;
         while(matris[i][j]!=';'){
                if(matris[i][j]!=' '){
                   buffer[BufferSP]=matris[i][j];
                    BufferSP++;
                    if(matris[i][j]=='+' || matris[i][j]=='-' || matris[i][j]=='*' ||matris[i][j]=='/' || matris[i][j]=='(' || matris[i][j]==')')
                        {
                        kontrol=1;
                        }
                }
            j++;
         }
         if(kontrol==0){
            int sayi = atoi (buffer);
            k=0;
                while(Degiskenler[k]!=matris[i][0]){
                    k++;
                }
                DegiskenDegerleri[k]=sayi;
         }
         else{
                fonksiyonMatris[x][0]=matris[i][0];
                fonksiyonMatris[x][1]='=';
             y=2;
             while(buffer[y-2]!='\0'){
                fonksiyonMatris[x][y]=buffer[y-2];
                y++;
             }
             x++;
         }
            for(BufferSP=0;BufferSP<256;BufferSP++){
                    buffer[BufferSP]='\0';
                }
            i++;
            j=4;
    }

    //GÝRÝLEN DEÐÝÞKENLER VE DEÐERLERÝ EKRANA YAZDIRILDI.
        i=0;
    printf("\nGirilen degiskenler ve degerleri:\n");
      while(Degiskenler[i]!='\0'){
        printf("%c =%d\n",Degiskenler[i],DegiskenDegerleri[i]);
        i++;
      }

    //GÝRÝLEN FONKSÝYONLAR EKRANA YAZDIRILDI.
      printf("\nGirilen fonksiyonlar:\n");
        x=0;
        y=0;
        while(fonksiyonMatris[x][y]!='\0'){
            while(fonksiyonMatris[x][y]!='\0'){
                printf("%c",fonksiyonMatris[x][y]);
                y++;
            }
            printf("\n");
            y=0;
            x++;
        }
 }

void WritePostfix(){
    //POSTFÝX ÝFADE EKRANA YAZDIRILDI.
    i=0;
    while(Postfix[i]!='\0'){
            if(Postfix[i]>='0' && Postfix[i]<='9'){
                 printf("%c",Postfix[i]);
                i++;
            }else{
                 printf("%c ",Postfix[i]);
                i++;
            }
    }
}

void Push(char karakter){
    StackArray[sp]=karakter;
    sp++;
}

void Pop(){
    Postfix[j]=StackArray[sp-1];
    StackArray[sp-1]='\0';
    j++;
    sp--;
}

int BuyukEsit(char a, char b){
    if (a=='*' || a=='/'){
        return 1;
    }
    if (b=='+' || b=='-'){
        return 1;
    }
    return 0;
}

void FindPostfix(){
    i=0,j=0;
    x=0,y=2;
    printf("\n\nPostfix ifadeler:");
        while(fonksiyonMatris[x][y]!='\0'){
                while(fonksiyonMatris[x][y]!='\0'){
                if(Postfix[0]!='\0' || StackArray[0]!='\0'){
                       k=0;
                        printf("posfix:");
                            while(Postfix[k]!='\0'){
                                printf("%c",Postfix[k]);
                                k++;
                            }
                        if(StackArray[0]!='\0'){
                                k=0;
                                printf("    yigin:");
                                    while(StackArray[k]!='\0'){
                                        printf("%c",StackArray[k]);
                                        k++;
                                    }
                        }else{
                                printf("    yigin:bos");
                        }
                }

                if(fonksiyonMatris[x][y]=='+' || fonksiyonMatris[x][y]=='-' || fonksiyonMatris[x][y]=='*' || fonksiyonMatris[x][y]=='/'){
                    while(sp!=0){
                        if(StackArray[sp-1]=='('){
                            break;
                        }
                        if(BuyukEsit(StackArray[sp-1],fonksiyonMatris[x][y])==1){
                                Pop();
                        }
                        else{
                            break;
                        }
                    }
                    Push(fonksiyonMatris[x][y]);
                }
                else if(fonksiyonMatris[x][y]==')'){
                    while(sp!=0){
                        if(StackArray[sp-1]=='('){
                            sp--;
                            break;
                        }
                        Pop();
                    }
                    StackArray[sp]='\0';
                }
                else if(fonksiyonMatris[x][y]=='('){
                    Push(fonksiyonMatris[x][y]);
                }
                else{
                    if(fonksiyonMatris[x][y]>='0' && fonksiyonMatris[x][y]<='9'){
                        if(fonksiyonMatris[x][y+1]>='0' && fonksiyonMatris[x][y+1]<='9'){
                                BufferSP=0;
                                while(fonksiyonMatris[x][y]>='0' && fonksiyonMatris[x][y]<='9'){
                                        buffer[BufferSP]=fonksiyonMatris[x][y];
                                        BufferSP++;
                                        y++;

                                }
                                i=0;
                                while(buffer[i]!='\0'){
                                    Postfix[j]=buffer[i];
                                    buffer[i]='\0';
                                    j++;
                                    i++;
                                }
                               Pop();
                               y--;

                        }else{
                            Postfix[j]=fonksiyonMatris[x][y];
                            j++;
                        }
                    }else{
                    Postfix[j]=fonksiyonMatris[x][y];
                    j++;
                    }
                }
                printf("\n");
                y++;
    }

 while(sp>0){
        Pop();
    }
    printf("posfix:");WritePostfix();
    if(StackArray[0]!='\0'){
                k=0;
                printf("    yigin:");
                while(StackArray[k]!='\0'){
                    printf("%c",StackArray[k]);
                    k++;
                }
    }else{
        printf("    yigin:bos");
    }
    printf("\n Ara cikis: ");WritePostfix();printf("\n\n");



    k=0;
    while(Postfix[k]!='\0'){
        AraCikisMatris[x][k]=Postfix[k];
        Postfix[k]='\0';
        k++;
    }
    j=0;
    i=0;
    y=2;
    x++;
    }
}

void PrintAraCikislar(){
i=0;j=0;
printf("TUM ARA CIKISLAR:\n");
    while(AraCikisMatris[i][j]!='\0'){
            printf("%c = ",fonksiyonMatris[i][0]);
            while(AraCikisMatris[i][j]!='\0'){
                if(AraCikisMatris[i][j]>='0' && AraCikisMatris[i][j]<='9'){
                    printf("%c",AraCikisMatris[i][j]);
                    j++;
                    }
                else{
                    printf("%c ",AraCikisMatris[i][j]);
                    j++;
                }
        }
        printf("\n");
        j=0;
        i++;
    }
}

void SolvePostfix(){
    x=0;y=0;sp=0;
    printf("\nTUM ARA CIKISLARIN STACK YARDIMI ILE COZULMESI\n");
    while(AraCikisMatris[x][y]!='\0'){
             SayiSp=0;
            while(AraCikisMatris[x][y]!='\0'){
                     if(AraCikisMatris[x][y]>='0' && AraCikisMatris[x][y]<='9'){
                        i=0;
                                while(buffer[i]!='\0'){
                                    buffer[i]=' ';
                                    //printf("%c ",buffer[i]);
                                    i++;
                                }
                                BufferSP=0;
                                while(AraCikisMatris[x][y]>='0' && AraCikisMatris[x][y]<='9'){
                                        buffer[BufferSP]=AraCikisMatris[x][y];
                                        BufferSP++;
                                        y++;

                                }
                                int sayi = atoi (buffer);
                                //printf("%d ",sayi);
                                SayiStack[SayiSp]=sayi;
                                SayiSp++;
                                y--;
                     }
                     else if(AraCikisMatris[x][y]=='+' ){
                        int sayi1=SayiStack[SayiSp-1];
                        int sayi2=SayiStack[SayiSp-2];
                        SayiStack[SayiSp-1]=0;
                        SayiStack[SayiSp-2]=0;
                        SayiSp--;
                        SayiSp--;
                        SayiStack[SayiSp]=sayi2+sayi1;
                        SayiSp++;
                     }
                    else if(AraCikisMatris[x][y]=='-' ){
                        int sayi1=SayiStack[SayiSp-1];
                        int sayi2=SayiStack[SayiSp-2];
                        SayiStack[SayiSp-1]=0;
                        SayiStack[SayiSp-2]=0;
                        SayiSp--;
                        SayiSp--;
                        SayiStack[SayiSp]=sayi2-sayi1;
                        SayiSp++;
                     }
                    else if(AraCikisMatris[x][y]=='*' ){
                        int sayi1=SayiStack[SayiSp-1];
                        int sayi2=SayiStack[SayiSp-2];
                        SayiStack[SayiSp-1]=0;
                        SayiStack[SayiSp-2]=0;
                        SayiSp--;
                        SayiSp--;
                        SayiStack[SayiSp]=sayi2*sayi1;
                        SayiSp++;
                     }
                    else if(AraCikisMatris[x][y]=='/' ){
                        int sayi1=SayiStack[SayiSp-1];
                        int sayi2=SayiStack[SayiSp-2];
                        SayiStack[SayiSp-1]=0;
                        SayiStack[SayiSp-2]=0;
                        SayiSp--;
                        SayiSp--;
                        SayiStack[SayiSp]=sayi2/sayi1;
                        SayiSp++;
                     }
                     else{
                        i=0;
                        while(Degiskenler[i]!=AraCikisMatris[x][y]){
                            i++;
                        }
                        SayiStack[SayiSp]=DegiskenDegerleri[i];
                                SayiSp++;
                     }


            printf("yigin:");
                i=0;
                while(SayiStack[i]!=0){
                    printf("%d ",SayiStack[i]);
                        i++;
                    }
                    printf("\n");
                    y++;


        }

                i=0;

                while(Degiskenler[i]!=fonksiyonMatris[sp][0]){
                     i++;
                }
                DegiskenDegerleri[i]=SayiStack[0];
                printf("%c = %d",fonksiyonMatris[sp][0],SayiStack[0]);
                SayiStack[0]=0;
                printf("\n\n");
                sp++;

        y=0;
        x++;
    }
}

void WriteDegiskenDegerleri(){
       i=0;
    printf("\nTUM ISLEMLER SONUCUNDA DEGISKENLER VE EN SON DEGERLERI:\n");
      while(Degiskenler[i]!='\0'){
        printf("%c =%d\n",Degiskenler[i],DegiskenDegerleri[i]);
        i++;
      }
}

