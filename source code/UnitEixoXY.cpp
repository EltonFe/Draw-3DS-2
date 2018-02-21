//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "UnitEixoXY.h"
#include "UnitArquivo2.h"
#include "Unit3.h"
#include <fstream>
using std::ifstream;

#include <string.h>
#include <math.h>
#include "UnitConstrucaoXYZ.h"
#include "UnitDesenha3Ds.h"
#include "UnitElipse.h"
using std::string;
using std::ostream;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
VetorDes3Ds Desenho3D1(M_PI/2);




long double BetaTDes=M_PI/2;
 int j=0;
int KOOx2=900;
int KOOy2=430;
int kx1;
int ky1;
int kx2=0;
int ky2=0;
long double TetaX1=0;
long double AlphaX1=0;
int Kx=900;
int Ky=430;
int KOx=900;
int KOy=430;
int KxO;
int KxOO=0;
int KyOO=500;
int Contar=0;
int Cont=2;









 bool Move=false;




long double LMVetorG[1000];
long double MVetorG[1000];


int Y (int y);
int X (int x);

float EixoX(float xo,float yo,float zo,long double *Alphat,long double *Betat,float Tetat,float *MVetor);
float EixoY(float xo,float yo,float zo, long double *Alphat,long double Betat,float Tetat,float MVetor);
int Configura(long double , int );






int EixoXo(long double xo,long double yo,float zo,  long double *Alphat,long double *MVetorXY);
int OX(float x);
int OY(float y);

void Colorido(TCanvas *,int );




int Zo[1000];

int MYo[1000];
int LYo[1000];
int Yo[1000];
int LMkx[1000];
int LLkx[1000];
int LMky[1000];
int LLky[1000];
int LBMkx[1000];
int LBLkx[1000];
int LBMky[1000];
int LBLky[1000];
float AngVetor;

Desenho Desenho3DS;

void MLimpaB(TCanvas *);
void GravaArquivo();
void RecebeUnicode(char *,UnicodeString);
void Eixos(TCanvas *);
float TetaX=0;
int RotaXY(float*,float,long double ,float ,float ,float , float );
Rotacional(float *x1,float *y1,long double zo,long double x,long double y,float Alphat,float Betat,float MVetort, float Teta) ;
int EixoYMo1(float,float ,float , float,float);
float EixoXMo1(long double ,long double,float );
int FullMKx[1000];
int FullMKy[1000];
int FullLKx[1000];
int FullLKy[1000];
int FullMKxDes[1000];
 int FullMKyDes[1000];
 int FullLKxDes[1000];
 int FullLKyDes[1000];
long double AlphaGr=0.0;
int  Kr=1;
float MTetaX[1000];
float LTetaX[1000];
float AlphaZo[1000];
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
 Contador=0;
}
//---------------------------------------------------------------------------

 int RotaXY(float *x1,float *y1,long double zo,float Alphat,float Betat,float MVetort, float Teta){
	 float k;
	 if (zo<=0) {
	  zo=-zo;
	  k= MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }else
	  k=MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);

	*x1= (MVetort*Cos(Alphat))*Cos(Teta) + (k)*Sin(Teta);
	*y1= -(MVetort*Cos(Alphat))*Sin(Teta)+ (k)*Cos(Teta);




}
int Rotacional(float *x1,float *y1,long double zo,long double x,long double y,float Alphat,float Betat,float MVetort, float Teta){
	 float k;
	 long double Ang;

	 if (zo<=0) {
	  zo=-zo;
	  k= MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }else
	  k=MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);

	*x1= x*Cos(Teta) - y*Sin(Teta);
	*y1= x*Sin(Teta)+ y*Cos(Teta);




}
void RecebeUnicode(char *File,UnicodeString FileEnter){
  int i=0;
  string Str;
  for (i=0;i<FileEnter.Length();i++){
  Str[i]=FileEnter[i];


  }

}
int OXDes2(int x){
return x+KOOx2;

}
int OYDes2(int y){
 return KOOy2-y;
}

int OX(float x){

return x-KOx;

}
int OXDes(int x){

return	x-1800;

}
int OY(float y){
  return KOy-y;
}
int OYDes(int y){
  return KyOO-y;
}
 int X(int x){
return x+Kx;
   }

   int Y(int y){
return Ky-y;
   }
   void ColorGrafico(TCanvas *Imagem,int i){
int Color;
Color=i%7;


 if (Color==0) {
 Imagem->Pen->Color=clPurple;
  }
  if (Color==1) {
  Imagem->Pen->Color=clYellow;
  }
 if (Color==2) {
   Imagem->Pen->Color=clBlue;
  }
  if (Color==3) {
   Imagem->Pen->Color=clLime;
  }
  if (Color==4) {
   Imagem->Pen->Color=clGreen;
  }
  if (Color==5) {
   Imagem->Pen->Color=clBlack;
  }
  if (Color==6) {
  Imagem->Pen->Color=clRed;
  }
  }
   void Grafics3(TCanvas *h){
   TPoint MP[2];
 float kx1[2];
 float ky1[2];

 for (int i = 0; i < Form2->Contador; i++) {


  RotaXY(&kx1[0],&ky1[0],Form2->MZo[i],Form2->MAlpha[i],Form2->BetaT,Form2->MMVetorG[i],TetaX);
  RotaXY(&kx1[1],&ky1[1],Form2->LZo[i],Form2->LAlpha[i],Form2->BetaT,Form2->LMVetorG[i],TetaX);



int  MLLkx= X(kx1[0]);
int   MLLky= Y(ky1[0]) ;
int   LLLkx= X(kx1[1]);
int   LLLky=Y(ky1[1]);
   FullMKx[i]=MLLkx;
   FullMKy[i]=MLLky;
   FullLKx[i]=LLLkx;
   FullLKy[i]=LLLky;
   MP[0].x=MLLkx;
   MP[0].y=MLLky;
   MP[1].x=LLLkx;
   MP[1].y= LLLky;

   ColorGrafico(h,i);
   h->Pen->Width=0;


   h->Polyline(MP,1);




}
}

void Grafics(TCanvas *h){
 TPoint MP[2];
 float kx1[2];
 float ky1[2];

 if ((Form2->RZoX->Checked)||( Form2->RXoY->Checked)){
   if (Form2->RZoX->Checked){
   BetaTDes=0;

   }
   if (Form2->RXoY->Checked){
   BetaTDes=M_PI/2;

   }

 for (int i = 0; i < Form2->Contador; i++) {


  RotaXY(&kx1[0],&ky1[0],Form2->MZo[i],Form2->MAlpha[i],BetaTDes,Form2->MMVetorG[i],TetaX);
  RotaXY(&kx1[1],&ky1[1],Form2->LZo[i],Form2->LAlpha[i],BetaTDes,Form2->LMVetorG[i],TetaX);



int  MLLkx= X(kx1[0]);
int   MLLky= Y(ky1[0]) ;
int   LLLkx= X(kx1[1]);
int   LLLky=Y(ky1[1]);
   FullMKxDes[i]=MLLkx;
   FullMKyDes[i]=MLLky;
   FullLKxDes[i]=LLLkx;
   FullLKyDes[i]=LLLky;
   MP[0].x=MLLkx;
   MP[0].y=MLLky;
   MP[1].x=LLLkx;
   MP[1].y= LLLky;

   ColorGrafico(h,i);
   h->Pen->Width=0;


   h->Polyline(MP,1);




}
 }
}








int EixoXo(long double xo,long double yo,float zo,  long double *Alphat,long double *MVetorXY){

long double MXYVetor;

long double MVetorXY1;
long double Alphat1=0;






MVetorXY1=Sqrt((xo*xo) +(yo*yo));
if (MVetorXY1==0){

MVetorXY1=1;
 return 0;
}

MXYVetor=MVetorXY1;


 *MVetorXY=MVetorXY1;

   if (xo==0) {
	if (yo>0){
	  *Alphat=M_PI/2;
  Alphat1=asin(1.0);
  return 0;

	}
	 if (yo<0) {
	   *Alphat=M_PI+M_PI/2;
  Alphat1=asin(-1.0);
  return 0;
	 }

}else{

	  if (yo==0) {

		 Alphat1=acos(xo/MVetorXY1);

	  }

	  if ((xo<0)&&(yo<0)) {
		 xo=-xo;

		 Alphat1=acos(xo/MVetorXY1)+M_PI;
		 xo=-xo;



	  }


   if ((xo<0)&&(yo>0)) {
		xo=-xo;

			Alphat1=M_PI-acos(xo/MVetorXY1);

		xo=-xo;
   }

	 if ((xo>0)&&(yo<0)) {
		 Alphat1=2*M_PI-acos(xo/MVetorXY1);

	 }
	 if ((xo>0)&&(yo>0)) {
		 Alphat1=acos(xo/MVetorXY1);

	 }

	  }

	 if (MVetorXY1<=0) {
	   *MVetorXY=0;
	   return 0;
		}
	*Alphat=Alphat1;
   return floor( MXYVetor*Cos(Alphat1));



}
int EixoYo(float zo, long double Alphat,float Betat,float MVetor){




  if (zo<=0) {
  zo=-zo;
		 return MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	 }


  return MVetor*Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);



}


float EixoXMo(long double Alphat,long double MVetort){

	return  MVetort*Cos(Alphat);

}
float EixoXMo1(long double Alphat,long double MVetort,float tetat){

return MVetort *Sin(Alphat)*Sin(TetaX);

}

float EixoXMoCircle(long double Alphat,long double MVetort){

	return  MVetort*Cos(Alphat);

}


int EixoYMo(float zo,float Alphat,float Betat, float MVetort){



	  if (zo<=0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}

int EixoYMo1(float zo,float Alphat,float Betat, float MVetort,float tetat){

	return  MVetort*Cos(Alphat);

}


int EixoYMoCircle(float zo,float Alphat,float Betat, float MVetort){



	  if (zo<=0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}






void Colorido(TCanvas *h,int i){

int  j;
j=i%7;

if (j==0){
h->Pen->Color=clGreen;

}
if(j==1){

h->Pen->Color=clYellow;
}
if (j==2){

h->Pen->Color=clLime;
}
if (j==3){
 h->Pen->Color=clPurple;

}
if (j==4){
h->Pen->Color=clRed;
}

if (j==5){

h->Pen->Color=clBlue;

}
if (j==6){

h->Pen->Color=clGray;
}







}

void TForm2::Circle(float A[1000],float AZ[1000],float B[1000],float BZ[1000],TPoint P[1000][51],float Center[1000][3]){

float sx1=300;
float sy1=150;
float sz1;
float x1;
float y1;
long double Ang;
long double MVetor;
float Cnd=0;
float AngVar=((2*M_PI)/50);
for(int j=0;j<Form2->ContadorCircle;j++){
for (int i=0;i<51;i++){


sx1=A[j]*Cos((i*((2*M_PI)/50)))+Center[j][0];
sy1=B[j]*Sin(i*((2*M_PI)/50))+Center[j][1];
sz1=AZ[j]*Cos((i*((2*M_PI)/50)))+BZ[j]*Sin((i*((2*M_PI)/50)))+Center[j][2];




EixoXo(sx1,sy1,0,&Ang,&MVetor);

x1=EixoXMo(Ang+AlphaX1,MVetor);
y1=EixoYMo(sz1,Ang+AlphaX1,Form2->BetaT,MVetor);

RotaXY(&x1,&y1,sz1,Ang+AlphaX1,Form2->BetaT,MVetor,TetaX);

P[j][i].x= X(x1);
P[j][i].y= Y(y1);
}
Form2->Image1->Canvas->Pen->Color=clGreen;
Form2->Image1->Canvas->Polyline(P[j],50);

}

}

void LimpaMemoria(){



memset(&Form2->LZo,0,sizeof(Form2->LZo));
memset(&Form2->MZo,0,sizeof(Form2->MZo));
memset(&Form2->MAlpha,0,sizeof(Form2->MAlpha));
memset(&Form2->LAlpha,0,sizeof(Form2->LAlpha));
memset(&Form2->MMVetorG,0,sizeof(Form2->MMVetorG));
memset(&Form2->LMVetorG,0,sizeof(Form2->LMVetorG));
memset(&Form2->A,0,sizeof(Form2->A));
memset(&Form2->B,0,sizeof(Form2->B));
memset(&Form2->AZo,0,sizeof(Form2->AZo));
memset(&Form2->BZo,0,sizeof(Form2->BZo));
memset(&Form2->Center,0,sizeof(Form2->Center));
memset(&Form2->ContadorCircle,0,sizeof(Form2->ContadorCircle));
memset(&AlphaX1,0,sizeof(AlphaX1));
memset(&Cont,0,sizeof(Cont));
memset(&Kr,0,sizeof(Kr));
j=0;
Kr=1;

AlphaX1=0;
AlphaGr=0;
Form2->Contador=0;
Contar=0;

 if (Form2->RadioXoY->Checked){
Form2->BetaT=M_PI/2;
}
if (  Form2->RadioZoX->Checked){
Form2->BetaT=0;

}
TetaX=0;
Form2->Label10->Caption="PXYZ(0,0,0};";
Form2->Label11->Caption="PXYZ(0,0,0};";
Form2->CheckBox2->Checked=true;


}










void Eixos(TCanvas *p){
long double kx;
long double ky;
long double Ang;
long double Mtar;

Form2->Image1->Canvas->Pen->Width=0  ;
Form2->Image1->Canvas->Pen->Color=clBlack;
kx=EixoXo(-1000.0,0.0,0.0,&Ang,&Mtar);
kx=Configura(kx,1);
ky=EixoYo(0.0,Ang,M_PI/2,Mtar);
ky=Configura(ky,-1);
p->MoveTo(X(kx),Y(ky));
kx=EixoXo(2000.0,0.0,0.0,&Ang,&Mtar);
kx=Configura(kx,1);
ky=EixoYo(0.0,Ang,M_PI/2,Mtar);
ky=Configura(ky,-1);
 Form2->Image1->Canvas->Pen->Color=clBlack;
p->LineTo(X(kx),Y(ky));
if ( Form2->RadioXoY->Checked ){

Form2->Image1->Canvas->Pen->Color=clPurple;
}else
   Form2->Image1->Canvas->Pen->Color=clLime;
kx=EixoXo(0.0,1000.0,0.0,&Ang,&Mtar);
kx=Configura(kx,1);
ky=EixoYo(0.0,Ang,M_PI/2,Mtar);
ky=Configura(ky,-1);
 p->MoveTo(X(kx),Y(ky));

 kx=EixoXo(0.0,-1000.0,0.0,&Ang,&Mtar);
 kx=Configura(kx,1);
ky=EixoYo(0,Ang,M_PI/2,Mtar);
ky=Configura(ky,-1);
p->LineTo(X(kx),Y(ky));
}


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

void __fastcall TForm2::Image1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{

long double Ang;
long double Mtar;
	 if (Button== mbLeft){


if (Edit1->Text.IsEmpty() ) {
	 Edit1->Text="0";}
if (Edit2->Text.IsEmpty()) {
	 Edit2->Text="0";
}
 if (RadioXoY->Checked) {
	 CheckBox2->Checked=true;

 }

 if (RadioZoX->Checked) {

	CheckBox2->Checked=true;
 }


Contar=Contar+1;
 if(Button==mbLeft){

if ((RadioButton1->Checked)&&(Contar==1)&&(RadioXoY->Checked)) {
  kx1=OX(X);
  ky1=OY(Y);
  MZo[Contador]=Edit1->Text.ToInt();

  EixoXo(OX(X),OY(Y),MZo[Contador],&Ang,&Mtar);
  EixoYo(MZo[Contador],Ang,BetaT,Mtar);




   MAlpha[Contador]=Ang;

   MMVetorG[Contador]=Mtar;


	::Move=true;
  }
   }
if ((RadioButton1->Checked)&&(Contar==2)&&(RadioXoY->Checked)) {

  ::Move=false;
  Contar=0;
   LZo[Contador]=Edit1->Text.ToInt();

  EixoXo(OX(X),OY(Y),0,&Ang,&Mtar);
  EixoYo(LZo[Contador],Ang,BetaT,Mtar);
  LAlpha[Contador]=Ang;

  LMVetorG[Contador]=Mtar;





  Contador=Contador+1;
   Desenho3DS.SetPosi(Contador);
   MLimpaB(Image1->Canvas);
  Grafics3(Image1->Canvas);
  }
	if(Button==mbLeft){
  if ((RadioButton1->Checked)&&(Contar==1)&&(RadioZoX->Checked)) {
  kx1=OX(X);
  ky1=OY(Y);
   MZo[Contador]=OY(Y);
   MYo[Contador]=Edit2->Text.ToInt();

  EixoXo(OX(X),MYo[Contador],0,&Ang,&Mtar);
  EixoYo(OY(Y),Ang,BetaT,Mtar);





   MAlpha[Contador]=Ang;
   MTetaX[Contador]=Ang;
   MMVetorG[Contador]=Mtar;
 
	::Move=true;
  }
  }

   if ((RadioButton1->Checked)&&(Contar==2)&&(RadioZoX->Checked)) {
  ::Move=false;
  Contar=0;
   LZo[Contador]=OY(Y);
   LYo[Contador]=Edit2->Text.ToInt();
  EixoXo(OX(X),LYo[Contador],0,&Ang,&Mtar);
  EixoYo(OY(Y),Ang,BetaT,Mtar);
 LTetaX[Contador]= LAlpha[Contador]=Ang;

  LMVetorG[Contador]=Mtar;


  Contador=Contador+1;
  MLimpaB(Image1->Canvas);
  Desenho3DS.SetPosi(Contador);
   Grafics(Image1->Canvas);

   }


  if (RadioButton2->Checked) {
	 Contar=0;
  }
  if (Contar>4) {
	 Contar=0;
  }

   }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button22Click(TObject *Sender)
{
TetaX=TetaX+M_PI/50;


   TPoint MP[2];
 float kx1[2];
 float ky1[2];
 int i;
 for ( i = 0; i < Contador; i++) {

  kx1[0]=EixoXMo1(MAlpha[i],MMVetorG[i],MTetaX[i]);
  ky1[0]=EixoYMo1(MZo[i],MAlpha[i],BetaT,MMVetorG[i],MTetaX[i]);
  kx1[1]=EixoXMo1(LAlpha[i],LMVetorG[i],LTetaX[i]);
  ky1[1]=EixoYMo1(LZo[i],LAlpha[i],BetaT,LMVetorG[i],LTetaX[i]);

int  MLLkx= X(kx1[0]);
int   MLLky= Y(ky1[0]) ;
int   LLLkx= X(kx1[1]);
int   LLLky=Y(ky1[1]);

   MP[0].x=MLLkx;
   MP[0].y=MLLky;
   MP[1].x=LLLkx;
   MP[1].y= LLLky;


   Image1->Canvas->Pen->Width=0;

 }


   Image1->Canvas->Polyline(MP,1);







}
//---------------------------------------------------------------------------


void __fastcall TForm2::Image1MouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y)
{

  int kx[5000];
int ky[5000];
int LLLkx;
int LLLky;
int MLLkx;
int MLLky;
TRect P;
TPoint MP[2];
long double Ang;
long double Mtar;

Image1->Canvas->Brush->Color=clWhite;

	if ((RadioButton1->Checked)&&(::Move)&&(RadioXoY->Checked)) {


kx[1]=EixoXo(OX(X),OY(Y),Zo[Contador],&Ang,&Mtar);
 ky[1]=EixoYo(Zo[Contador],Ang,M_PI/2,Mtar);

  Image1->Canvas->Pen->Color=clRed;





   MLLkx= ::X(kx1);
   MLLky= ::Y(ky1) ;
   LLLkx= ::X(kx[1]);
   LLLky=::Y(ky[1]);

  FullMKx[Contador]=MP[0].x=MLLkx;
  FullMKy[Contador]= MP[0].y=MLLky;
  FullLKx[Contador]= MP[1].x=X;
  FullLKy[Contador]=MP[1].y=Y;
   Image1->Canvas->Pen->Color=clWhite;
   Image1->Canvas->Pen->Width=80;
	 Image1->Canvas->Polyline(MP,1);
	 Image1->Canvas->Pen->Color=clRed;
	 Image1->Canvas->Pen->Width=0;
	 Image1->Canvas->Polyline(MP,1);





  }

	if ((RadioButton1->Checked)&&(::Move)&&(RadioZoX->Checked)) {

	kx[1]=EixoXo(OX(X),0,Zo[Contador],&Ang,&Mtar);
	ky[1]=EixoYo(OY(Y),Ang,0,Mtar);

   MLLkx= ::X(kx1);
   MLLky= ::Y(ky1) ;
   LLLkx= ::X(kx[1]);
   LLLky=::Y(ky[1]);



  FullMKx[Contador]= MP[0].x=MLLkx;
  FullMKy[Contador]= MP[0].y=MLLky;
  FullLKx[Contador]= MP[1].x=X;
  FullLKy[Contador]= MP[1].y=Y;
   Image1->Canvas->Pen->Color=clWhite;
   Image1->Canvas->Pen->Width=80;
	 Image1->Canvas->Polyline(MP,1);
	 Image1->Canvas->Pen->Color=clRed;
	 Image1->Canvas->Pen->Width=0;


		Image1->Canvas->Polyline(MP,1);

	}

  Label1->Top=Y+235;
  Label1->Left=X+15;

  kx[0]=X;
  ky[0]=Y;
  Label1->Caption="{ "+IntToStr(::OX(X))+" ; "+IntToStr(OY(Y))+" };";

}
//---------------------------------------------------------------------------
  void MLimpaB(TCanvas *h){
int i=0;
TPoint MP[2];
for (int i = 0; i < Form2->Contador; i++) {









   MP[0].x=FullMKx[i];
   MP[0].y=FullMKy[i];
   MP[1].x=FullLKx[i];
   MP[1].y= FullLKy[i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;


   h->Polyline(MP,1);




}




}
void TForm2::MLimpa(TCanvas *h,TPoint P[1000][51]){
h->Pen->Color=clWhite;

for(int j=0;j<Form2->ContadorCircle;j++){

h->Polyline(P[j],50);
}
h->Pen->Color=clPurple;
}
void MLimpaBDes(TCanvas *h){
int i=0;
TPoint MP[2];

for (int i = 0; i < Form2->Contador; i++) {









   MP[0].x=FullMKxDes[i];
   MP[0].y=FullMKyDes[i];
   MP[1].x=FullLKxDes[i];
   MP[1].y= FullLKyDes[i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;
   h->Polyline(MP,1);






}

}






//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
 Eixos(Image1->Canvas);




 if ((Contador>0)||(ContadorCircle>0)) {



 if (CheckBox2->Checked){
   Grafics(Image1->Canvas);
   Grafics3(Image1->Canvas);
   Circle(A,AZo,B,BZo,P,Center);
 }


}





}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button24Click(TObject *Sender)
{
int i=0;
int kx=0;
int ky =0;

CheckBox2->Checked=false;
MLimpa(Image1->Canvas,P);
MLimpaB(Image1->Canvas);


for (i = 0; i < Contador; i++) {
 MAlpha[i]=MAlpha[i]+M_PI/50 ;
 LAlpha[i]=LAlpha[i]+M_PI/50;
}
AlphaX1=AlphaX1+M_PI/50;
Grafics3(Image1->Canvas);
Circle(A,AZo,B,BZo,P,Center);
AlphaGr= Kr++*M_PI/50;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button25Click(TObject *Sender)
{
int i=0;
float kx=0;
float ky=0;
TPoint MP[2];



 CheckBox2->Checked=false;
  MLimpa(Image1->Canvas,P);
  MLimpaB(Form2->Image1->Canvas);

  BetaT=BetaT+M_PI/50;

  Grafics3(Image1->Canvas);
 Circle(A,AZo,B,BZo,P,Center);
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1DblClick(TObject *Sender)
{
Edit1->Clear();
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------


//---------------------------------------------------------------------------



void __fastcall TForm2::Button28Click(TObject *Sender)
{
MLimpaB(Image1->Canvas);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::RadioZoXClick(TObject *Sender)
{
BetaT=0;
RadioButton3->Checked=true;
Cancel->Checked=true;
MLimpaBDes(Image1->Canvas);
MLimpaB(Image1->Canvas);
MLimpa(Image1->Canvas,P);
Label12->Font->Color=clLime;
Label12->Caption="Eixo Zo";
CheckBox2->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioXoYClick(TObject *Sender)
{
BetaT=M_PI/2;
RadioButton3->Checked=true;
Cancel->Checked=true;
MLimpaBDes(Image1->Canvas);
MLimpaB(Image1->Canvas);
MLimpa(Image1->Canvas,P);
Label12->Font->Color=clPurple;
Label12->Caption="Eixo Yo";
CheckBox2->Checked=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BetaT0Click(TObject *Sender)
{
BetaT=0;
MLimpa(Image1->Canvas,P);
MLimpaB(Image1->Canvas);
Circle(A,AZo,B,BZo,P,Center);
CheckBox2->Checked=true;
Grafics3(Image1->Canvas);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::BetaTMPI2Click(TObject *Sender)
{
BetaT=M_PI/2;
MLimpa(Image1->Canvas,P);
MLimpaB(Image1->Canvas);
CheckBox2->Checked=true;
Grafics3(Image1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonSalvarClick(TObject *Sender)
{
int k;
int i;
int Cont=0;
GravaArquivo();
UnicodeString FileNome;
char FileUni[500];
if (SaveDialog1->Execute()){
ShowMessage(SaveDialog1->FileName );
FileNome=SaveDialog1->FileName;
}
Cont= FileNome.Length();
for(i=0;i<FileNome.Length();i++){
FileUni[i]=FileNome[i+1];

}
 FileUni[ FileNome.Length()]='\0';


ofstream FDesenho(FileUni,ios::binary);


if (!FDesenho) {
  ShowMessage("Arquivo Não pode ser Aberto...");



}





  ShowMessage("Numero de Retas: "+IntToStr(Desenho3DS.GetPosi()));

  for (i = 0; i < Contador+ContadorCircle; i++) {

   FDesenho.write(reinterpret_cast<const char *>(&Desenho3DS),sizeof(Desenho3DS));

   }

   FDesenho.close();

}
//---------------------------------------------------------------------------
void RecuperaShow(Desenho Des){
for (int i=0;i<Form2->Contador;i++){
Form2->MAlpha[i]=Des.GetMAlpha(i);
Form2->LAlpha[i]=Des.GetLAlpha(i);
Form2->MMVetorG[i]=Des.GetMMVetorGr(i);
Form2->LMVetorG[i]=Des.GetLMVetorGr(i);
Form2->MZo[i]=Des.GetMzo(i);
Form2->LZo[i]=Des.GetLzo(i);
Form2->BetaT=Des.BetaT;
}


for (int j=0;j<Form2->ContadorCircle;j++){
Form2->A[j]=Des.GetA(j);
Form2->B[j]=Des.GetB(j);
Form2->AZo[j]=Des.GetAZo(j);
Form2->BZo[j]=Des.GetBZo(j);
Des.GetCenter(j,Form2->Center);


}
AlphaX1=Des.GetAlphaX1();


}

void __fastcall TForm2::ButtonRecuperaClick(TObject *Sender)
{
int Posi;

int i=0;
int j=0;
int kx=0;
int ky=0;
TPoint MP[2];
char Chr;

float AlphaBlend[1000];

 UnicodeString FileNome;
char FileUni[500];

if (OpenDialog1->Execute()){
LimpaMemoria();
FileNome=OpenDialog1->FileName;
}
int Cont= FileNome.Length();
for(i=0;i<FileNome.Length();i++){
FileUni[i]=FileNome[i+1];

}


FileUni[Cont]='\0';
ShowMessage(FileUni);








ifstream Recupera(FileUni,ios::in|ios::binary);

if (!Recupera) {
	ShowMessage("Arquivo Não Pode Ser Lido...");
}else {

while ((Recupera)&&(!Recupera.eof())){
Recupera.read(reinterpret_cast<char *>(&Desenho3DS),sizeof (Desenho3DS));
  
	 }
}
Recupera.close();

ShowMessage("Contador:"+IntToStr(Desenho3DS.Posi));
 Form2->Image1->Canvas->Pen->Width=1;



   Contador=Desenho3DS.GetPosi();
   ContadorCircle=Desenho3DS.GetContCircle();
   RecuperaShow(Desenho3DS);

  Circle(A,AZo,B,BZo,P,Center);
  Grafics(Image1->Canvas);


}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

  void GravaArquivo(){
   int i;
	ShowMessage(IntToStr(Form2->Contador));
	Desenho3DS.SetPosi(Form2->Contador);
	Desenho3DS.SetBetaT(Form2->BetaT);
    Desenho3DS.SetAlphaX1(AlphaX1);
	Desenho3DS.SetContCircle(Form2->ContadorCircle);
   for (i = 0; i < Form2->Contador; i++) {



   Desenho3DS.SetMAlpha(Form2->MAlpha[i],i);
   Desenho3DS.SetLAlpha(Form2->LAlpha[i],i);
   Desenho3DS.SetMMVetorGr(Form2->MMVetorG[i],i);
   Desenho3DS.SetLMVetorGr(Form2->LMVetorG[i],i);

   Desenho3DS.SetMZo(Form2->MZo[i],i);
   Desenho3DS.SetLZo(Form2->LZo[i],i);
   }

   for (int j=0;j<Form2->ContadorCircle;j++){

   Desenho3DS.SetA(j,Form2->A[j]);
   Desenho3DS.SetB(j,Form2->B[j]);
   Desenho3DS.SetAZo(j,Form2->AZo[j]);
   Desenho3DS.SetBZo(j,Form2->BZo[j]);
   Desenho3DS.SetCenter(j,Form2->Center);


   }



  }

//---------------------------------------------------------------------------





void __fastcall TForm2::RadioButton1Click(TObject *Sender)
{     if ( RadioXoY->Checked){
BetaT=M_PI/2;
}
if (  RadioZoX->Checked){
BetaT=0;

}


	  CheckBox2->Checked=true;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button29Click(TObject *Sender)
{
int i=0;

float kx=0.0;
float ky=0.0;

MLimpaB(Image1->Canvas);

for (i = 0; i < Contador; i++) {
MMVetorG[i]=MMVetorG[i]*1.1;
 LMVetorG[i]=LMVetorG[i]*1.1;
 MZo[i]=MZo[i]*1.1;
 LZo[i]=LZo[i]*1.1;
}
Grafics3(Image1->Canvas);

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button30Click(TObject *Sender)
{
int i=0;
float kx=0.0;
float ky=0.0;


MLimpaB(Image1->Canvas);

for (i = 0; i < Contador; i++) {
MMVetorG[i]=MMVetorG[i]/1.1;
 LMVetorG[i]=LMVetorG[i]/1.1 ;
 MZo[i]=MZo[i]/1.1;
 LZo[i]=LZo[i]/1.1;
}
Grafics3(Image1->Canvas);

}


//---------------------------------------------------------------------------



//---------------------------------------------------------------------------




//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void ConfiguraBut(TButton * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);
But->Font->Height=Configura(But->Font->Height,-1);
}
void ConfiguraForm(TForm * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);

}
void ConfiguraBox(TCheckBox * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);


But->Font->Height=Configura(But->Font->Height,-1);
}
void ConfiguraRadioBut(TRadioButton * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);
But->Font->Height=Configura(But->Font->Height,-1);

}
void ConfiguraEd(TEdit * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);
But->Font->Height=Configura(But->Font->Height,-1);
}

void ConfiguraPan(TPanel * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);

}
void ConfiguraLab(TLabel * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Font->Height=Configura(But->Font->Height,-1);

}
void ConfiguraImg(TImage * But){
But->Top=Configura( But->Top,-1);
But->Left=Configura( But->Left,1);
But->Height=Configura( But->Height,-1);
But->Width=Configura( But->Width,1);

}
void __fastcall TForm2::FormCreate(TObject *Sender)
{

BetaT=M_PI/2;
Image1->Height=Screen->DesktopHeight;
Label12->Top=Image1->Top+20;
Label12->Left=920;
Label12->Font->Color=clPurple;
Label12->Caption="Eixo Yo";
//configuração do visual proporcional;

ConfiguraImg(Image1);
Kx=Configura(Kx,1);
Ky=Configura(Ky,-1);
KOx= Configura(KOx,1);
KOy=Configura(KOy,-1);
ConfiguraBut(Button22);
ConfiguraBut(Button35);
ConfiguraBut(Close);

ConfiguraBut(Button31);
ConfiguraBut(Button32);
ConfiguraBut(Button33);
ConfiguraBut(Button34);

ConfiguraBut(Button24);
ConfiguraBut(Button25);
ConfiguraBut(Button29);
ConfiguraBut(Button30);
ConfiguraBut(ButtonRecupera);
ConfiguraBut(ButtonSalvar);
ConfiguraBut(Button36);
//labels
ConfiguraLab(Label1);
ConfiguraLab(Label12);
ConfiguraLab(Label2);
ConfiguraLab(Label6);
ConfiguraLab(Label4);
ConfiguraLab(Label7);
ConfiguraLab(Label10);
ConfiguraLab(Label11);
ConfiguraLab(Label3);
ConfiguraLab(Label5);
ConfiguraLab(Label9);

//panels
ConfiguraPan(Panel1);
ConfiguraPan(Panel2);
ConfiguraPan(Panel3);
ConfiguraPan(Panel4);
ConfiguraPan(Panel5);
ConfiguraPan(Panel6);
ConfiguraPan(Panel7);
ConfiguraPan(Panel8);
ConfiguraPan(Panel9);
//Edit
ConfiguraEd(Edit1);
ConfiguraEd(Edit2);
ConfiguraEd(Edit3);
ConfiguraEd(Edit4);
ConfiguraEd(Edit5);
//RadioButton

ConfiguraRadioBut(RadioButton1);
ConfiguraRadioBut(RadioButton2);
ConfiguraRadioBut(RadioXoY);
ConfiguraRadioBut(RadioZoX);
ConfiguraRadioBut(Cancel);
ConfiguraRadioBut(RXoY);
ConfiguraRadioBut(RZoX);
ConfiguraRadioBut(BetaT0);
ConfiguraRadioBut(BetaTMPI2);
ConfiguraRadioBut(RadioButton3);
//CheckBox
ConfiguraBox(CheckBox2);
ConfiguraBox(CheckBox1);
}


//---------------------------------------------------------------------------

void __fastcall TForm2::LimpaDesenho1Click(TObject *Sender)
{

MLimpa(Image1->Canvas,P);
MLimpaB(Image1->Canvas);
AlphaGr=0;

LimpaMemoria();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::PontoaPonto1Click(TObject *Sender)
{
Form1->Visible=true;
Form1->Edit1->SetFocus();
}
//---------------------------------------------------------------------------





void __fastcall TForm2::Button36Click(TObject *Sender)
{

 long double Ang;
 long double Mtar;
long double xo;
long double yo;
long double zo;
 if (RadioXoY->Checked) {
	 CheckBox2->Checked=true;

 }

 if (RadioZoX->Checked) {

	CheckBox2->Checked=true;
 }
 if (Edit3->Text.IsEmpty()){
 Edit3->Text="0";
 xo=0;
 }
 if(Edit4->Text.IsEmpty()){
 Edit4->Text="0";
 yo=0;
 }
 if(Edit5->Text.IsEmpty()){
 Edit5->Text="0";
 zo=0;
 }
 xo=Edit3->Text.ToDouble();
 yo=Edit4->Text.ToDouble();
 zo=Edit5->Text.ToDouble();

  j=Cont%2;

 if (j==0){

 MZo[Contador]=zo;

  EixoXo(xo,yo,0,&Ang,&Mtar);
  EixoYo(zo,Ang,BetaT,Mtar);




   MAlpha[Contador]=Ang+AlphaGr;
   MMVetorG[Contador]=Mtar;

   Label10->Font->Color=clBlue;
   Label10->Caption="P" + IntToStr(Contador)+" : "+IntToStr(0)+"{ "+FloatToStr(xo)+ " , "+FloatToStr(yo)+" ,"+FloatToStr(zo)+" }; °°°";
   Cont++;
 } if (j==1)
   {
  LZo[Contador]=zo;

  EixoXo(xo,yo,0,&Ang,&Mtar);
  EixoYo(zo,Ang,BetaT,Mtar);
  Cont++;
  Label11->Font->Color=clBlue;
  Label11->Caption="P" + IntToStr(Contador)+" : "+IntToStr(1)+"{ "+FloatToStr(xo)+ " , "+FloatToStr(yo)+" ,"+FloatToStr(zo)+" }; °°°";



   LAlpha[Contador]=Ang+AlphaGr;
   LMVetorG[Contador]=Mtar;


 Contador=Contador+1;


 }

 Sleep(2000);

}
//---------------------------------------------------------------------------




//---------------------------------------------------------------------------

void __fastcall TForm2::RZoXClick(TObject *Sender)
{
MLimpaBDes(Image1->Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button35Click(TObject *Sender)
{

 int i=0;
float kx=0;
float ky=0;
float kx1;
float ky1;
TPoint MP[2];
CheckBox2->Checked=false;
	MLimpa(Image1->Canvas,P);
	MLimpaB(Image1->Canvas);
	TetaX=TetaX+M_PI/50;
	Grafics3(Image1->Canvas);
	Circle(A,AZo,B,BZo,P,Center);


}
//---------------------------------------------------------------------------

void __fastcall TForm2::Form31Click(TObject *Sender)
{
Form3->Visible=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::RXoYClick(TObject *Sender)
{
  MLimpaBDes(Image1->Canvas);
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ConstruoEIxoXYZ1Click(TObject *Sender)
{
Form1->Visible=true;
}
//---------------------------------------------------------------------------

int Configura(long double Desk, int x){
long double k;
long double k2;

if (x<1){
k=1080;
k2=Screen->DesktopHeight;
}else {
  k=1920;
  k2=Screen->DesktopWidth;
  }
return (k2/k)*Desk;
}

void __fastcall TForm2::ConstruoElipse1Click(TObject *Sender)
{
 Form4->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton3Click(TObject *Sender)
{
CheckBox2->Checked=true;
}
//---------------------------------------------------------------------------

