//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitElipse.h"
#include "UnitEixoXY.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
 float *AS=new float[1000];
 float *BS=new float[1000];
 float *ASZ=new float[1000];
 float *BSZ=new float[1000];
 if (Edit1->Text.IsEmpty()){
 Edit1->Text="0";

 }
 if (Edit2->Text.IsEmpty()){
 Edit2->Text="0";
 }
 if (Edit3->Text.IsEmpty()){

 Edit3->Text="0";
 }

 AS= Form2->A;
 ASZ=Form2->AZo;
 BS=Form2->B;
 BSZ= Form2->BZo;

 Form2->A[Form2->ContadorCircle]= Edit1->Text.ToDouble();

 Form2->AZo[Form2->ContadorCircle]= Edit2->Text.ToDouble();

 Form2->B[Form2->ContadorCircle]=Edit3->Text.ToDouble();

 Form2->BZo[Form2->ContadorCircle]= Edit4->Text.ToDouble();


 Form2->Center[Form2->ContadorCircle][0]= Edit5->Text.ToDouble();
 Form2->Center[Form2->ContadorCircle][1]=Edit6->Text.ToDouble();
 Form2->Center[Form2->ContadorCircle][2]=Edit7->Text.ToDouble();
 Form2->ContadorCircle++;

 Form2->Circle(AS,ASZ,BS,BSZ,Form2->P,Form2->Center);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormCreate(TObject *Sender)
{
Form2->ContadorCircle=0;
}
//---------------------------------------------------------------------------
