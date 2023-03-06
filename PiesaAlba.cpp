//---------------------------------------------------------------------------

#pragma hdrstop

#include "PiesaAlba.h"
#include "FereastraPrincipala.h"
//---------------------------------------------------------------------------
void PiesaAlba::Muta(int PozX,int PozY){
	  this->imagine->Left=PozX;
	  this->imagine->Top=PozY;

}
TImage* PiesaAlba::GetImagine(){
	return imagine;
}
int PiesaAlba::GetPozitie(){
		 return pozitie;
}
void PiesaAlba::SetPozitie(int pozitie){
      this->pozitie=pozitie;
}
PiesaAlba::PiesaAlba(int PozX,int PozY,int pozitie){
		 imagine = new TImage(mForm);
		 imagine->Left=PozX;
		 imagine->Parent=mForm;
		 imagine->Top=PozY;
		 imagine->Picture->LoadFromFile("gri.png");
		 imagine->Width=50;
		 imagine->Height=50;
		 imagine->Stretch=true;
		 imagine->BringToFront();
		 this->pozitie=pozitie;
}
#pragma package(smart_init)
