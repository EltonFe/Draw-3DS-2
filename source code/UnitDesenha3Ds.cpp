//---------------------------------------------------------------------------

#pragma hdrstop


#include <math.h>
#include "UnitDesenha3Ds.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

VetorDes3Ds::VetorDes3Ds(long double Beta1 ):Beta(M_PI/2),Kx(900),Ky(500),Posi1(0) {




 }
 int  VetorDes3Ds::X(int x){
   return x+Kx;
   }
int VetorDes3Ds::Y(int y){

 return 500 - y;

   }

int VetorDes3Ds::OX(float x){
 return x-KOx;
	}


int VetorDes3Ds::OY(float y){

    return KOy-y;
	}
	float VetorDes3Ds::EixoXMo(long double Alphat,long double MVetort){

	return  MVetort*Cos(Alphat);

}
float VetorDes3Ds::EixoYMo(long double zo,long double Alphat,long double Betat, long double MVetort){



	  if (zo<=0) {
	  zo=-zo;
	  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetort *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}

int VetorDes3Ds::EixoYo(long double zo, long double Alphat,long double Betat,long double MVetor){




	  if (zo<=0) {
	  zo=-zo;
	  return MVetor *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI+M_PI/2+Betat);
	  }


  return MVetor *Sin(Alphat)*Sin(Betat)+zo*Sin(M_PI/2+Betat);


}

long double VetorDes3Ds::EixoXo2(long double xo,long double yo,  long double *Alphat,long double *MVetorXY){

long double MXYVetor;

long double MVetorXY1;
long double Alphat1=0;






MVetorXY1=sqrt((xo*xo) +(yo*yo));
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
   return  MXYVetor*cos(Alphat1);




}

long double   VetorDes3Ds::GetLAlpha(int i){
return LAlpha[i];
}
void   VetorDes3Ds::SetLAlpha(long double LAlphaSet,int i){
LAlpha[i]=LAlphaSet;
}
long double   VetorDes3Ds::GetMAlpha(int i){

return MAlpha[i];
}
void   VetorDes3Ds::SetMAlpha(long double MAlphaSet,int i){
MAlpha[i]=MAlphaSet;

}

long double   VetorDes3Ds::GetMMVetorG( int i){


  return MMVetor[i];


}




long double   VetorDes3Ds::GetLMVetorG(int i){
  return LMVetorG[i];
}
long double  VetorDes3Ds::GetBetaT(){

return Beta;

}
void VetorDes3Ds::SetLMVetorG(long double LMVetorGSet,int i){

LMVetorG[i]=LMVetorGSet;

}
void VetorDes3Ds::SetBetaT(long double BetaTSet){
long double Beta=BetaTSet;

}
void  VetorDes3Ds::SetMMVetorG(long double MMVetorG,int i){
  MMVetor[i]=MMVetorG;
}
int VetorDes3Ds::GetPosi1(){

return Posi1;
}
void VetorDes3Ds::SetPosi1(int Posi){

Posi1=Posi;
}
long double VetorDes3Ds::GetMZo(int i){

return MZo1[i];

}
void  VetorDes3Ds::SetMZo(long double MZo,int i){

MZo1[i]=MZo;

}
long double VetorDes3Ds::GetLZo(int i){

return LZo1[i];
}

void VetorDes3Ds::SetLZo(long double LZo,int i){

 LZo1[i]=LZo;
}

 void VetorDes3Ds::Desenha(TCanvas *h){
  int kx;
int ky;
int kx1;
int ky1;
int j=2;
int i;

 int LBMkx[1000];
 int LBMky[1000];
 int LBLkx[1000];
 int  LBLky[1000];
TPoint MP[2];


   for (i = 0; i < Posi1; i++) {
  kx=EixoXMo(GetMAlpha(i),GetMMVetorG(i));
  ky=EixoYMo(GetMZo(i),GetMAlpha(i),GetBetaT(),GetMMVetorG(i));


  LBMkx[i]=X(kx);
  LBMky[i]=Y(ky);
  MP[0].x= LBMkx[i];
  MP[0].y= LBMky[i];



  kx=EixoXMo(GetLAlpha(i),GetLMVetorG(i));
  ky=EixoYMo(GetLZo(i),GetLAlpha(i),GetBetaT(),GetLMVetorG(i));

  LBLkx[i]= X(kx);
  LBLky[i]=Y(ky);
  MP[1].x=LBLkx[i];
  MP[1].y=  LBLky[i];


   h->Polyline(MP,1);






   }

 }
 float   VetorDes3Ds::GetA(int i){
 return A[i];
 }
 float VetorDes3Ds::GetB(int i) {
	 return B[i];
 }
 float VetorDes3Ds::GetAZo(int i){
 return AZo[i];
 }

 float VetorDes3Ds::GetBZo(int i){
 return BZo[i];
 }
 int VetorDes3Ds::GetContCircle(){

 return ContadorCircle;
 }
 void VetorDes3Ds::GetCenter(int i,float A[1000][3]){
 A[i][0]=Center[i][0];
 A[i][1]=Center[i][1];
 A[i][2]=Center[i][2];

 }
 void VetorDes3Ds::SetA(int i,float x){
 A[i]=x;

 }
 void VetorDes3Ds::SetB(int i,float x){
 B[i]=x;

 }
 void VetorDes3Ds::SetAZo(int i,float x){

 AZo[i]=x;
 }

 void VetorDes3Ds::SetBZo(int i,float x){

 BZo[i]=x;

 }


 void VetorDes3Ds::SetCenter(int i,float x,float y,float z){

 Center[i][0]=x;
 Center[i][1]=y;
 Center[i][2]=z;
 }
 void VetorDes3Ds::SetContCircle(int x){
 ContadorCircle=x;
 }
