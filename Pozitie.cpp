//---------------------------------------------------------------------------

#pragma hdrstop

#include "Pozitie.h"
#include "FereastraPrincipala.h"
//---------------------------------------------------------------------------

Pozitie::Pozitie(int Ox,int Oy,int PieseContorAlbe,int PieseContorAlbastre){
		 imagine2 = new TImage(mForm);
		 imagine2->Left=Ox;
		 imagine2->Parent=mForm;
		 imagine2->Top=Oy;
		 imagine2->Picture->LoadFromFile("blank.png");
		 imagine2->Width=50;
		 imagine2->Height=50;
		 imagine2->Stretch=true;
		 imagine2->BringToFront();
		 this->PieseContorAlbe=PieseContorAlbe;
		 this->PieseContorAlbastre=PieseContorAlbastre;

}
void Pozitie::SetContorAlbe(int contor){
	 this->PieseContorAlbe=contor;
}
int Pozitie::PozitieLeft(){
		 return this->imagine2->Left;
}
int Pozitie::PozitieTop(){
		 return this->imagine2->Top;
}
int Pozitie::GetContor(){
	   return this->PieseContorAlbe;
}
int Pozitie::GetContorAlbastre(){
	   return this->PieseContorAlbastre;
}
void Pozitie::SetContorAlbastre(int contor){
	 this->PieseContorAlbastre=contor;
}
#pragma package(smart_init)
