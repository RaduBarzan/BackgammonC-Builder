//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Server.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TServerForm *ServerForm;
//---------------------------------------------------------------------------
__fastcall TServerForm::TServerForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TServerForm::Button2Click(TObject *Sender)
{
       ModalResult=mrOk;
}
//---------------------------------------------------------------------------

void __fastcall TServerForm::Button1Click(TObject *Sender)
{
	   ModalResult=mrYes;
}
//---------------------------------------------------------------------------

