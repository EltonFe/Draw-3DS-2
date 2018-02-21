//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "UnitArquivo2.h"
#include "UnitConstrucaoXYZ.h"
#include "UnitEixoXY.h"
#include <fstream>
using std::ifstream;
using std::ios;
//---------------------------------------------------------------------------
#pragma package(smart_init)


#pragma resource "*.dfm"
TForm3 *Form3;

int Contador;
float AlphaX1=0;
TPoint P1[1000][51];
long double MZo1[1000];
long double MAlpha1[1000];
long double MMVetorG1[1000];
long double LZo1[1000];
long double LAlpha1[1000];
long double LMVetorG1[1000];
int   FullMKxDes[1000];
int   FullMKyDes[1000];
int   FullLKxDes[1000];
int   FullLKyDes[1000];
int Fullxy[4][1000];
int Fullxy2[4][1000];
int Fullxy3[4][1000];
int Kx1=300;
int Ky1=370;
int ContadorCircle1;

long double TetaXDes=0;
long double BetaT=M_PI/2;
long double BetaTDes=M_PI/2;
Desenho  Desenho3DS1;
int SentidoAlpha=1;
int SentidoBeta=1;
int SentidoTeta=1;
int Mxyz[3][1000];
int Lxyz[3][1000];
float A1[1000];
float B1[1000];
float AZo1[1000];
float BZo1[1000];
float Center1[1000][3];
void Colorido1(TCanvas *,int );
int RotaXY1(float *,float *,long double ,float ,float ,float , float );
int X1(int ,int);
 int Y1(int ,int);

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{

}
void MLimpa(TCanvas *h,TPoint P[1000][51]){
h->Pen->Color=clWhite;
for(int j=0;j<ContadorCircle1;j++){

h->Polyline(P[j],50);
}

}
int EixoXo(long double xo,long double yo,float zo,  long double *Alphat,long double *MVetorXY){

long double MXYVetor;

long double MVetorXY1;
long double Alphat1=0;






MVetorXY1=Sqrt((xo*xo) +(yo*yo));
if (MVetorXY1==0){

MVetorXY1=1;

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
int EixoYMo(float zo,float Alphat,float Betat, float MVetort){



	  if (zo<=0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}
//---------------------------------------------------------------------------
float EixoXMo(long double Alphat,long double MVetort){

	return  MVetort*Cos(Alphat);

}
void Circle1(float A[1000],float AZ[1000],float B[1000],float BZ[1000],TPoint P[1000][51],float Center[1000][3]){

float sx1=300;
float sy1=150;
float sz1;
float x1;
float y1;
long double Ang;
long double MVetor;
float Cnd=0;
float AngVar=((2*M_PI)/50);
for(int j=0;j<ContadorCircle1;j++){
for (int i=0;i<51;i++){


sx1=A[j]*Cos((i*((2*M_PI)/50)))+Center[j][0];
sy1=B[j]*Sin(i*((2*M_PI)/50))+Center[j][1];
sz1=AZ[j]*Cos((i*((2*M_PI)/50)))+BZ[j]*Sin((i*((2*M_PI)/50)))+Center[j][2];




EixoXo(sx1,sy1,0,&Ang,&MVetor);

x1=EixoXMo(Ang+AlphaX1,MVetor);
y1=EixoYMo(sz1,Ang+AlphaX1,BetaTDes,MVetor);

RotaXY1(&x1,&y1,sz1,Ang+AlphaX1,BetaTDes,MVetor,TetaXDes);

P[j][i].x= X1(x1,Kx1);
P[j][i].y= Y1(y1,Ky1);
}
Form3->Image1->Canvas->Pen->Color=clGreen;
Form3->Image1->Canvas->Polyline(P[j],50);

}

}

void GiraAlpha(int h){
if (h>0){
for(int i=0;i<Contador;i++){
MAlpha1[i]=MAlpha1[i]+M_PI/50;
LAlpha1[i]=LAlpha1[i]+M_PI/50;
}
AlphaX1=AlphaX1+ M_PI/50;
} else{
for(int i=0;i<Contador;i++){
MAlpha1[i]=MAlpha1[i]-M_PI/50;
LAlpha1[i]=LAlpha1[i]-M_PI/50;

	}
AlphaX1=AlphaX1- M_PI/50;
}



}

void GiraBeta(int h){
if (h>0){
BetaTDes=BetaTDes+M_PI/50;
} else{

 BetaTDes=BetaTDes-M_PI/50;
	}
}

void GiraTeta(int h){
if (h>0){
TetaXDes=TetaXDes+M_PI/50;
} else{

 TetaXDes=TetaXDes-M_PI/50;
	}
}



 void MLimpaB1(TCanvas *h){
int i=0;
TPoint MP[2];
for (int i = 0; i < Contador; i++) {
   MP[0].x=FullMKxDes[i];
   MP[0].y=FullMKyDes[i];
   MP[1].x=FullLKxDes[i];
   MP[1].y= FullLKyDes[i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;


   h->Polyline(MP,1);
}




}
void MLimpaB1Des(TCanvas *h,int Fullxy1[4][1000]){
int i=0;
TPoint MP[2];
for (int i = 0; i < Contador; i++) {
   MP[0].x=Fullxy1[0][i];
   MP[0].y=Fullxy1[1][i];
   MP[1].x=Fullxy1[2][i];
   MP[1].y= Fullxy1[3][i];

   h->Pen->Color=clWhite;
   h->Pen->Width=0;


   h->Polyline(MP,1);
}




}

void RecuperaDes(Desenho Des){
for(int i=0;i<Contador;i++){
MAlpha1[i]=Des.GetMAlpha(i);
MMVetorG1[i]=Des.GetMMVetorGr(i);
LAlpha1[i]=Des.GetLAlpha(i);
LMVetorG1[i]=Des.GetLMVetorGr(i);
MZo1[i]=Des.GetMzo(i);
LZo1[i]=Des.GetLzo(i);

}
BetaTDes=Des.BetaT;
AlphaX1=Des.GetAlphaX1();
for (int j=0;j<ContadorCircle1;j++){
A1[j]=Des.GetA(j);
B1[j]=Des.GetB(j);
AZo1[j]=Des.GetAZo(j);
BZo1[j]=Des.GetBZo(j);
Des.GetCenter(j,Center1);


}



}


int X1(int x,int Kx){
return x+Kx;
   }

   int Y1(int y,int Ky){
return Ky-y;
   }

int RotaXY1(float *x1,float *y1,long double zo,float Alphat,float Betat,float MVetort, float Teta){
	 float k;
     if (zo<=0) {
	  zo=-zo;
	  k= MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }else
	  k=MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);

	*x1= (MVetort*Cos(Alphat))*Cos(Teta) + (k)*Sin(Teta);
	*y1= -(MVetort*Cos(Alphat))*Sin(Teta)+ (k)*Cos(Teta);




}

   void Grafics5(TCanvas *h){
 TPoint MP[2];
 float kx1[2];
 float ky1[2];



 for (int i = 0; i < Contador; i++) {


  RotaXY1(&kx1[0],&ky1[0],MZo1[i],MAlpha1[i],BetaTDes,MMVetorG1[i],TetaXDes);
  RotaXY1(&kx1[1],&ky1[1],LZo1[i],LAlpha1[i],BetaTDes,LMVetorG1[i],TetaXDes);



int  MLLkx= X1(kx1[0],Kx1);
int   MLLky= Y1(ky1[0],Ky1) ;
int   LLLkx= X1(kx1[1],Kx1);
int   LLLky=Y1(ky1[1],Ky1);
   FullMKxDes[i]=MLLkx;
   FullMKyDes[i]=MLLky;
   FullLKxDes[i]=LLLkx;
   FullLKyDes[i]=LLLky;
   MP[0].x=MLLkx;
   MP[0].y=MLLky;
   MP[1].x=LLLkx;
   MP[1].y= LLLky;

   h->Pen->Color=clGreen;
   h->Pen->Width=0;


   h->Polyline(MP,1);




}

}
  void Grafics6(TCanvas *h,int Kx1,int Ky1,int Fullxy1[4][1000]){
 TPoint MP[2];
 float kx1[2];
 float ky1[2];



 for (int i = 0; i < Contador; i++) {


  RotaXY1(&kx1[0],&ky1[0],MZo1[i],MAlpha1[i],BetaTDes,MMVetorG1[i],TetaXDes);
  RotaXY1(&kx1[1],&ky1[1],LZo1[i],LAlpha1[i],BetaTDes,LMVetorG1[i],TetaXDes);



int  MLLkx= X1(kx1[0],Kx1);
int   MLLky= Y1(ky1[0],Ky1) ;
int   LLLkx= X1(kx1[1],Kx1);
int   LLLky=Y1(ky1[1],Ky1);
   Fullxy1[0][i]=MLLkx;
   Fullxy1[1][i]=MLLky;
   Fullxy1[2][i]=LLLkx;
   Fullxy1[3][i]=LLLky;
   MP[0].x=MLLkx;
   MP[0].y=MLLky;
   MP[1].x=LLLkx;
   MP[1].y= LLLky;

   Colorido1(Form3->Image1->Canvas,i);
   h->Pen->Width=0;


   h->Polyline(MP,1);




}

}
void __fastcall TForm3::Button1Click(TObject *Sender)
{
int Posi;

int i=0;
int j=0;
int kx=0;
int ky=0;
TPoint MP[2];
char Chr;



 UnicodeString FileNome;
char FileUni[500];

if (OpenDialog1->Execute()){

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
Recupera.read(reinterpret_cast<char *>(&Desenho3DS1),sizeof (Desenho3DS1));

	 }
}
Recupera.close();
Contador=Desenho3DS1.GetPosi();
ContadorCircle1= Desenho3DS1.GetContCircle();


 RecuperaDes(Desenho3DS1);





   Circle1(A1,AZo1,B1,BZo1,P1,Center1);
   Grafics6(Image1->Canvas,Kx1,Ky1,Fullxy);
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Timer1Timer(TObject *Sender)
{
if ((CheckBox1->Checked)||(CheckBox2->Checked)||(CheckBox3->Checked)){



 MLimpaB1Des(Image1->Canvas,Fullxy);
 MLimpaB1Des(Image1->Canvas,Fullxy2);
 MLimpa(Image1->Canvas,P1);
 Circle1(A1,AZo1,B1,BZo1,P1,Center1);
 Grafics6(Image1->Canvas,Kx1,Ky1,Fullxy2);


}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton1Click(TObject *Sender)
{
SentidoAlpha=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton2Click(TObject *Sender)
{
SentidoAlpha=-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton3Click(TObject *Sender)
{
SentidoBeta=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton4Click(TObject *Sender)
{
SentidoBeta=-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton5Click(TObject *Sender)
{
SentidoTeta=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RadioButton6Click(TObject *Sender)
{
SentidoTeta=-1;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer2Timer(TObject *Sender)
{
if( CheckBox1->Checked){
GiraAlpha(SentidoAlpha);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer3Timer(TObject *Sender)
{
if (CheckBox2->Checked){
GiraBeta(SentidoBeta);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Timer4Timer(TObject *Sender)
{
if (CheckBox3->Checked){
GiraTeta(SentidoTeta);}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
if (Timer2->Interval>80){
Timer2->Interval= Timer2->Interval-50;
}
if (Timer2->Interval>40){
Timer2->Interval= Timer2->Interval-20;
}
if (Timer2->Interval>10){
Timer2->Interval= Timer2->Interval-2;
}
if (Timer2->Interval==0){
Timer2->Interval=1;
}
}
//---------------------------------------------------------------------------


void __fastcall TForm3::Button5Click(TObject *Sender)
{
long double Ang;
long double Vetor;
Form1->XYZO(MMVetorG1,MAlpha1,MZo1,Mxyz,Contador);
Form1->XYZO(LMVetorG1,LAlpha1,LZo1,Lxyz,Contador);
Label1->Caption=FloatToStr(Mxyz[0][Contador-1])+";|;"+ FloatToStr(Mxyz[1][Contador-1])+";|;"+ FloatToStr(Mxyz[1][Contador-1]);
for (int i=0;i<Contador;i++){

 Form1->EixoXo2Move(Mxyz[0][i]+300,Mxyz[1][i],0,&Ang,&Vetor);
 MAlpha1[i]=Ang;
 MMVetorG1[i]=Vetor;
 MZo1[i]=MZo1[i];
 Form1->EixoXo2Move(Lxyz[0][i]+300,Lxyz[1][i],0,&Ang,&Vetor);
 LAlpha1[i]=Ang;
 LMVetorG1[i]=Vetor;
 LZo1[i]=LZo1[i];
}
}
//---------------------------------------------------------------------------
 void Colorido1(TCanvas *h,int i){

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


void __fastcall TForm3::Button3Click(TObject *Sender)
{
if (Timer3->Interval>80){
Timer3->Interval= Timer3->Interval-50;
}
if (Timer3->Interval>40){
Timer3->Interval= Timer3->Interval-20;
}
if (Timer3->Interval>10){
Timer3->Interval= Timer3->Interval-2;
}
if (Timer3->Interval==0){
Timer3->Interval=1;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button4Click(TObject *Sender)
{
if (Timer4->Interval>80){
Timer4->Interval= Timer4->Interval-50;
}
if (Timer4->Interval>40){
Timer4->Interval= Timer4->Interval-20;
}
if (Timer4->Interval>10){
Timer4->Interval= Timer4->Interval-2;
}
if (Timer4->Interval==0){
Timer4->Interval=1;
}
}
//---------------------------------------------------------------------------

