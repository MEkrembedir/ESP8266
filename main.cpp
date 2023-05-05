#include <Arduino.h>
#include<Servo.h>
//set servo
Servo motor1; Servo motor2; Servo motor3; Servo motor4;
Servo motor5; Servo motor6; Servo motor7; Servo motor8; 

//make table for servo angle  
int kalk1=70;  int snv1=120; int yer1=123; int adim1=55;   int cek1=60; int geri1=45; 
int kalk2=60;  int snv2=35;  int yer2=37;  int adim2=50;   int cek2=80; int geri2=30; 
int kalk3=72;  int snv3=45;  int yer3=20;  int adim3=75;   int cek3=72; int geri3=80; 
int kalk4=125; int snv4=150; int yer4=150; int adim4=143;  int cek4=110;int geri4=133;
int kalk5=65;  int snv5=120; int yer5=123; int adim5=55;   int cek5=50; int geri5=40;
int kalk6=130; int snv6=150; int yer6=155; int adim6=145;  int cek6=115;int geri6=130;
int kalk7=110; int snv7=50;  int yer7=53;  int adim7=130;  int cek7=115;int geri7=120;
int kalk8=55;  int snv8=35;  int yer8=37;  int adim8=40;   int cek8=70; int geri8=30; 

int anlik1=yer1;int anlik2=yer2;int anlik3=yer3;int anlik4=yer4;
int anlik5=yer5;int anlik6=yer6;int anlik7=yer7;int anlik8=yer8;
int ss1,ss2,ss3,ss4,ss5,ss6,ss7,ss8;



void ontkm( int a1, int a2, int a3, int a4){ Serial.println(a1);anlik1=a1;anlik2=a2;anlik3=a3;anlik4=a4;}
void arkatkm( int a5, int a6, int a7, int a8){Serial.println(a5);anlik5=a5;anlik6=a6;anlik7=a7;anlik8=a8;}

  
int delta(int deger,int anlik){
  int cikti;
  if(deger < anlik){
                    cikti = anlik - deger;
                    }

  if(deger > anlik){
                    cikti = deger - anlik;
                    }

  if(deger == anlik){
                     cikti = 1;
                     }
  return cikti;
}


int sirala(int deger1,int deger2,int deger3,int deger4,int deger5,int deger6,int deger7,int deger8){
  int dizi[7];int s, x, y, t;
   
   dizi[0]=delta(deger1,anlik1);
   dizi[1]=delta(deger2,anlik2);
   dizi[2]=delta(deger3,anlik3);
   dizi[3]=delta(deger4,anlik4);
   dizi[4]=delta(deger5,anlik5);
   dizi[5]=delta(deger6,anlik6);
   dizi[6]=delta(deger7,anlik7);
   dizi[7]=delta(deger8,anlik8);
   
  for (x=0;x<7;x++)  {
    for (y=0;y<7-x; y++)
    {
      if (dizi[y] > dizi[y+1])
      {
        t         = dizi[y];
        dizi[y]   = dizi[y+1];
        dizi[y+1] = t;
      }
    }
  }
  return dizi[7];
}

 int hareket(int basla,int son){
    int cikti;
     if(basla<son){
                 if(basla+1<son){cikti=basla+1;} 
                 if(basla+1==son){cikti=son;} 
                 if(basla+1>son){cikti=son;}}
     if(basla>son){     
                if(basla-1>son){cikti=basla-1;}     
                if(basla-1<son){cikti=son;}     
               if(basla-1==son){cikti=son;}}
 if(basla==son){cikti=son;}              
  return cikti;}

//acılara göre hareketleme
void fiil(){
  int a;
  a = sirala(ss1,ss2,ss3,ss4,ss5,ss6,ss7,ss8);
  for(int i=0;i<a;i++){
  ontkm(hareket(anlik1,ss1),hareket(anlik2,ss2),hareket(anlik3,ss3),hareket(anlik4,ss4));arkatkm(hareket(anlik5,ss5),hareket(anlik6,ss6),hareket(anlik7,ss7),hareket(anlik8,ss8));
  delay(30);
  }
  }

//chart->acı dondurme
void komut(char bir[],char iki[],char uc[],char dort[],char bes[],char alti[],char yedi[],char sekiz[]){
if(bir[0] =='k'){ss1=kalk1;};if(bir[0] =='s'){ss1=snv1;};if(bir[0] =='y'){ss1=yer1;};
if(bir[0] =='a'){ss1=adim1;};if(bir[0] =='c'){ss1=cek1;};if(bir[0] =='g'){ss1=geri1;};

if(iki[0] =='k'){ss2=kalk2;};if(iki[0] =='s'){ss2=snv2;};if(iki[0] =='y'){ss2=yer2;};
if(iki[0] =='a'){ss2=adim2;};if(iki[0] =='c'){ss2=cek2;};if(iki[0] =='g'){ss2=geri2;};

if(uc[0] =='k'){ss3=kalk3;};if(uc[0] =='s'){ss3=snv3;};if(uc[0] =='y'){ss3=yer3;};
if(uc[0] =='a'){ss3=adim3;};if(uc[0] =='c'){ss3=cek3;};if(uc[0] =='g'){ss3=geri3;};

if(dort[0] =='k'){ss4=kalk4;};if(dort[0] =='s'){ss4=snv4;};if(dort[0] =='y'){ss4=yer4;};
if(dort[0] =='a'){ss4=adim4;};if(dort[0] =='c'){ss4=cek4;};if(dort[0] =='g'){ss4=geri4;};

if(bes[0] =='k'){ss5=kalk5;};if(bes[0] =='s'){ss5=snv5;};if(bes[0] =='y'){ss5=yer5;};
if(bes[0] =='a'){ss5=adim5;};if(bes[0] =='c'){ss5=cek5;};if(bes[0] =='g'){ss5=geri5;};

if(alti[0] =='k'){ss6=kalk6;};if(alti[0] =='s'){ss6=snv6;};if(alti[0] =='y'){ss6=yer6;};
if(alti[0] =='a'){ss6=adim6;};if(alti[0] =='c'){ss6=cek6;};if(alti[0] =='g'){ss6=geri6;};

if(yedi[0] =='k'){ss7=kalk7;};if(yedi[0] =='s'){ss7=snv7;};if(yedi[0] =='y'){ss7=yer7;};
if(yedi[0] =='a'){ss7=adim7;};if(yedi[0] =='c'){ss7=cek7;};if(yedi[0] =='g'){ss7=geri7;};

if(sekiz[0] =='k'){ss8=kalk8;};if(sekiz[0] =='s'){ss8=snv8;};if(sekiz[0] =='y'){ss8=yer8;};
if(sekiz[0] =='a'){ss8=adim8;};if(sekiz[0] =='c'){ss8=cek8;};if(sekiz[0] =='g'){ss8=geri8;};
fiil();
}

//Hazır Hareket Kombosu
void adim(){
  komut("cek","cek","adim","adim","kalk","yer","yer","kalk");
  komut("kalk","kalk","adim","yer","adim","cek","cek","adim");
  komut("kalk","kalk","yer","yer","adim","cek","cek","adim");
  komut("adim","adim","cek","cek","yer","kalk","kalk","yer");
  komut("adim","adim","cek","cek","yer","kalk","kalk","yer");
  komut("adim","yer","kalk","kalk","cek","adim","adim","adim");
  komut("yer","yer","kalk","kalk","cek","adim","adim","adim");
  komut("cek","cek","adim","adim","kalk","yer","adim","kalk");
  komut("cek","cek","adim","adim","kalk","yer","yer","kalk");
  }

void setup() {motor1.attach(2);motor2.attach(3);motor3.attach(4);motor4.attach(5);motor5.attach(6);motor6.attach(7);motor7.attach(8);motor8.attach(9);}

void loop() {adim();}