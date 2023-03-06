//---------------------------------------------------------------------------

#pragma hdrstop

#include "PiesaAlbastra.h"
#include "FereastraPrincipala.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void PiesaAlbastra::Muta(int PozX,int PozY){
	  this->imagine3->Left=PozX;
	  this->imagine3->Top=PozY;

}
TImage* PiesaAlbastra::GetImagine(){
	return imagine3;
}
int PiesaAlbastra::GetPozitie(){
		 return pozitie;
}
void PiesaAlbastra::SetPozitie(int pozitie){
	  this->pozitie=pozitie;
}
PiesaAlbastra::PiesaAlbastra(int PozX,int PozY,int pozitie){
		 imagine3 = new TImage(mForm);
		 imagine3->Left=PozX;
		 imagine3->Parent=mForm;
		 imagine3->Top=PozY;
		 imagine3->Picture->LoadFromFile("albastra4.png");
		 imagine3->Width=50;
		 imagine3->Height=50;
		 imagine3->Stretch=true;
		 imagine3->BringToFront();
		 this->pozitie=pozitie;
}
