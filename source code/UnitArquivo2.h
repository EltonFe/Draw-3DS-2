//---------------------------------------------------------------------------

#ifndef UnitArquivo2H
#define UnitArquivo2H
//---------------------------------------------------------------------------

class Desenho{
public:


void SetMAlpha(float,int);
float GetMAlpha(int);
void SetLAlpha(float,int);
float GetLAlpha(int);
void SetMMVetorGr(float,int);
float GetMMVetorGr(int);
void SetLMVetorGr(float , int);
float GetLMVetorGr(int);
void SetBetaT(float);
float GetBetaT ();
void SetMZo(float,int);
float GetMzo(int);
void SetLZo(float,int);
float GetLzo(int);
void SetPosi(int);
int GetPosi();
int Posi;
float MAlpha[1000];
float LAlpha[1000];
float MMVetorGr[1000];
float LMVetorGr[1000];
float BetaT;
float MZo[1000];
float LZo[1000];
 float GetA(int);
   float GetB(int);
   float GetAZo(int);
   float GetBZo(int);
   int GetContCircle();
   float GetAlphaX1();
   void GetCenter(int,float [1000][3]);
   void SetA(int,float);
   void SetB(int,float);
   void SetAZo(int,float);
   void SetBZo(int,float);
   void SetCenter(int,float [1000][3]);
   void SetContCircle(int);
   void SetAlphaX1(float);


  private:

   float A[1000];
   float B[1000];
   float AZo[1000];
   float BZo[1000];
   float Center[1000][3];
   int ContadorCircle;
   float AlphaX1;

};







#endif
