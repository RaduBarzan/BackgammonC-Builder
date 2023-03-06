//---------------------------------------------------------------------------

#ifndef ServerH
#define ServerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TServerForm : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TStaticText *StaticText1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TServerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TServerForm *ServerForm;
//---------------------------------------------------------------------------
#endif
