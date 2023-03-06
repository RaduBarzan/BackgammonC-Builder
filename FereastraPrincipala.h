//---------------------------------------------------------------------------

#ifndef FereastraPrincipalaH
#define FereastraPrincipalaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include "Piesa.h"
#include "PiesaAlba.h"
#include "Zar.h"
#include "PiesaAlbastra.h"
#include "Pozitie.h"
#include <System.Win.ScktComp.hpp>
#include "Server.h"
//---------------------------------------------------------------------------
class TmForm : public TForm
{
__published:	// IDE-managed Components
	TButton *btnZAR;
	TStaticText *Text1;
	TStaticText *Text2;
	TImage *Image2;
	TButton *AlegeZar1;
	TButton *AlegeZar2;
	TServerSocket *ServerSocket1;
	TClientSocket *ClientSocket1;
	void __fastcall btnZARClick(TObject *Sender);
	void __fastcall AlbClick(TObject *Sender);
	void __fastcall AlbastruClick(TObject *Sender);
	void __fastcall AlegeZar2Click(TObject *Sender);
	void __fastcall AlegeZar1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ServerSocket1ClientRead(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket);




private:
PiesaAlba* Albe[15];
PiesaAlbastra* Albastre[15];
Zar* zaruri;
int Mutari1;
int Mutari2;
bool AlegeZar;
Pozitie* pozitie[26];
int ctAlb;
int ctAlb1=15;
int ctAlbastre1=15;
int ctAlbastre;
bool PotJuca;
// Use declarations
public:		// User declarations
	__fastcall TmForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmForm *mForm;
//---------------------------------------------------------------------------
#endif
