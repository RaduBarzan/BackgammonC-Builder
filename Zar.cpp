//---------------------------------------------------------------------------

#pragma hdrstop

#include "Zar.h"
//---------------------------------------------------------------------------
Zar::Zar(int zar1,int zar2){
		 this->zar1=zar1;
		 this->zar2=zar2;

}
int Zar::GetZar1(){
	return zar1;
}
int Zar::GetZar2(){
	return zar2;
}
void Zar::SetZar1(int zar1){
	 this->zar1=zar1;
}
void Zar::SetZar2(int zar2){
	 this->zar2=zar2;
}
bool Zar::ZarDublu(){
   if(this->zar1==this->zar2){
		Dubla=true;
   }
   else
		Dubla=false;
   return Dubla;
       }

#pragma package(smart_init)
