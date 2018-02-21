//---------------------------------------------------------------------------

#ifndef UnitDesenha3DsH
#define UnitDesenha3DsH
//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
class VetorDes3Ds{
public:
   VetorDes3Ds(long double);
   int X(int x);
   int Y(int y);
   int OX(float x);
   int OY(float y);
   int OXDes2(int x);
   int OYDes2(int y);
   long double EixoXo2(long double ,long double  ,  long double *,long double *);
   int EixoYo(long double zo, long double Alphat,long double Betat,long double MVetor);
  float EixoXMo(long double ,long double );
  float EixoYMo(long double ,long double ,long double, long double );
   long double GetLAlpha(int );
   long double  GetMAlpha(int);
   long double GetLMVetorG(int );
   long double GetMMVetorG(int);
   long double GetBetaT();
  void SetLAlpha(long double  ,int );
   void  SetMAlpha(long double , int);
   void SetLMVetorG(long double ,int );
   void SetBetaT(long double);
   void SetMMVetorG(long double ,int i);
   int GetPosi1();
   long double GetMZo(int);
   void SetMZo(long double ,int  );
   long double GetLZo(int);
   void SetLZo(long double,int);
   void SetPosi1(int);
   float GetA(int);
   float GetB(int);
   float GetAZo(int);
   float GetBZo(int);
   int GetContCircle();
   void GetCenter(int,float [1000][3]);
   void SetA(int,float);
   void SetB(int,float);
   void SetAZo(int,float);
   void SetBZo(int,float);
   void SetCenter(int,float,float,float);
   void SetContCircle(int);
   void Desenha(TCanvas *);

   private:
   const Kx;
   const Ky;
   float KOx;
   float KOy;
   long double LAlpha[1000];
   long double MAlpha[1000];
   long double LMVetorG[1000];
   long double MMVetor[1000];
   long double MZo1[1000];
   float A[1000];
   float B[1000];
   float AZo[1000];
   float BZo[1000];
   float Center[1000][3];
   int ContadorCircle;

   float LZo1[1000];
   long double Beta;
   int Posi1;



};








#endif
