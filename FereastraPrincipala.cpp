//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FereastraPrincipala.h"
#include "Piesa.h"
#include "PiesaAlba.h"
#include "PiesaAlbastra.h"
#include "Zar.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmForm *mForm;
//---------------------------------------------------------------------------
__fastcall TmForm::TmForm(TComponent* Owner)
	: TForm(Owner)
{
	 
}
//---------------------------------------------------------------------------
void __fastcall TmForm::btnZARClick(TObject *Sender)
{
	Mutari1=2;
	Mutari2=2;
	zaruri->SetZar1(rand()%6+1);
	zaruri->SetZar2(rand()%6+1);
	if(zaruri->ZarDublu()==true){
	   Mutari1=5;
	   Mutari2=1;
	}
	mForm->Text1->Caption=zaruri->GetZar1();
	mForm->Text2->Caption=zaruri->GetZar2();
	//mForm->btnZAR->Enabled=false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TmForm::AlegeZar2Click(TObject *Sender)
{
  AlegeZar=false;
}

//---------------------------------------------------------------------------

void __fastcall TmForm::AlegeZar1Click(TObject *Sender)
{
   AlegeZar=true;
}
//---------------------------------------------------------------------------

//Mutare Piesa Alba
void __fastcall TmForm::AlbClick(TObject *Sender){

//------------------------ MUTARE PIESA ALBA -------------------------------------------------
if(PotJuca==true){
for(int i=0;i<15;i++){

  if(Albe[i]->GetImagine()==(TImage*) Sender){

  int FirstMove=Albe[i]->GetPozitie()+zaruri->GetZar1();
  int SecondMove=Albe[i]->GetPozitie()+zaruri->GetZar2();
  int PozitieInitiala=Albe[i]->GetPozitie();
  if(FirstMove>24 && ctAlb!=ctAlb1)
  break;
  if(SecondMove>24 && ctAlb!=ctAlb1)
  break;
   if(AlegeZar==true && FirstMove>=25 && ctAlb==ctAlb1 && Mutari1>1){
   String s="";
   s=IntToStr(i);
   s+=IntToStr(808);
   s+=IntToStr(288);
   if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
		 Albe[i]->Muta(808,288);
		 pozitie[PozitieInitiala]->SetContorAlbe((pozitie[PozitieInitiala]->GetContor()-1));
		 Mutari1--;
		 ctAlb1--;
	 }
	 else{
  if(AlegeZar==true && pozitie[FirstMove]->GetContorAlbastre()<=1 && FirstMove<25){
	  int x=pozitie[FirstMove]->GetContor();
	  if((Mutari1>1 || Mutari1==4) && FirstMove>=1 && FirstMove<13){
	  String s="";
	  s=IntToStr(i);
	  s+=IntToStr(pozitie[FirstMove]->PozitieLeft());
	  s+=IntToStr(pozitie[FirstMove]->PozitieTop()-(40*x));
	  if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
	   Albe[i]->Muta(pozitie[FirstMove]->PozitieLeft(),pozitie[FirstMove]->PozitieTop()-(40*x));
	   Albe[i]->SetPozitie(FirstMove);
	   pozitie[FirstMove]->SetContorAlbe(x+1);
	   pozitie[PozitieInitiala]->SetContorAlbe((pozitie[PozitieInitiala]->GetContor()-1));
	   Mutari1--;
	 }
	 if((Mutari1>1 || Mutari1==4) && FirstMove>=13 && FirstMove<25){
	 String s="";
	 s=IntToStr(i);
	 s+=IntToStr(pozitie[FirstMove]->PozitieLeft());
	 s+=IntToStr(pozitie[FirstMove]->PozitieTop()+(40*x));
	 if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
	   Albe[i]->Muta(pozitie[FirstMove]->PozitieLeft(),pozitie[FirstMove]->PozitieTop()+(40*x));
	   Albe[i]->SetPozitie(FirstMove);
	   pozitie[FirstMove]->SetContorAlbe(x+1);
	   pozitie[PozitieInitiala]->SetContorAlbe((pozitie[PozitieInitiala]->GetContor()-1));
	   Mutari1--;
	 }
  }
	 ctAlb=0;
	for(int i=19;i<=24;i++){
	   ctAlb+=pozitie[i]->GetContor();

   }
  }
  if(AlegeZar==false && SecondMove>=25 && ctAlb==ctAlb1 && Mutari2>1){
		String s="";
		s=IntToStr(i);
		s+=IntToStr(808);
		s+=IntToStr(288);
		if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
		 Albe[i]->Muta(808,288);
		 ctAlb1--;
		 pozitie[PozitieInitiala]->SetContorAlbe((pozitie[PozitieInitiala]->GetContor()-1));
		 Mutari2--;
	 }
	 else{
   if(AlegeZar==false && pozitie[SecondMove]->GetContorAlbastre()<=1 && SecondMove<25){
	 int y=pozitie[SecondMove]->GetContor();
	 if(Mutari2>1 && SecondMove>=1 && SecondMove<13){
	 String s="";
	 s=IntToStr(i);
	 s+=IntToStr(pozitie[SecondMove]->PozitieLeft());
	 s+=IntToStr(pozitie[SecondMove]->PozitieTop()-(40*y));
		if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }

	   Albe[i]->Muta(pozitie[SecondMove]->PozitieLeft(),pozitie[SecondMove]->PozitieTop()-(40*y));
	   Albe[i]->SetPozitie(SecondMove);
	   pozitie[SecondMove]->SetContorAlbe(y+1);
	   pozitie[PozitieInitiala]->SetContorAlbe((pozitie[PozitieInitiala]->GetContor()-1));
	   Mutari2--;
	 }
	  if(Mutari2>1 && SecondMove>=13 && SecondMove<25){
	  String s="";
	   s=IntToStr(i);
	  s+=IntToStr(pozitie[SecondMove]->PozitieLeft());
	  s+=IntToStr(pozitie[SecondMove]->PozitieTop()+(40*y));
	  if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
	   Albe[i]->Muta(pozitie[SecondMove]->PozitieLeft(),pozitie[SecondMove]->PozitieTop()+(40*y));
	   Albe[i]->SetPozitie(SecondMove);
	   pozitie[SecondMove]->SetContorAlbe(y+1);
	   pozitie[PozitieInitiala]->SetContorAlbe((pozitie[PozitieInitiala]->GetContor()-1));
	   Mutari2--;
	 }
   }
  }
	 ctAlb=0;
	for(int i=19;i<=24;i++){
	   ctAlb+=pozitie[i]->GetContor();


  }

	}         //------------------SCOATERE PIESA -------------------------
	for(int j=0;j<15;j++){
		  if(Albe[i]->GetPozitie()==Albastre[j]->GetPozitie()){
          String s="";
	   s=IntToStr(i);
	  s+=IntToStr(pozitie[25]->PozitieLeft());
	  s+=IntToStr(pozitie[25]->PozitieTop());
	  if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
			pozitie[Albastre[j]->GetPozitie()]->SetContorAlbastre(0);
			Albastre[j]->Muta(pozitie[25]->PozitieLeft(),pozitie[25]->PozitieTop());
			Albastre[j]->SetPozitie(25);
		  }
	}
		 // ---SCOATERE PIESA----------------
	//----------------------------FINAL MUTARE PIESA ALBA---------------------------------//
 }
}
 if(Mutari1==1 && Mutari2==1){
   PotJuca=false;
 }
 else
   PotJuca=true;
 if(ctAlb1==0)
  exit(0);
   }

void __fastcall TmForm::AlbastruClick(TObject *Sender){
if(PotJuca==true){
for(int i=0;i<15;i++){
  if(Albastre[i]->GetImagine()==(TImage*) Sender){
  int FirstMove=Albastre[i]->GetPozitie()-zaruri->GetZar1();
  int SecondMove=Albastre[i]->GetPozitie()-zaruri->GetZar2();
  if(FirstMove<1 && ctAlbastre!=ctAlbastre1)
  break;
  if(SecondMove<1 && ctAlbastre!=ctAlbastre1)
  break;
  int PozitieInitiala=Albastre[i]->GetPozitie();
  if(AlegeZar==true && FirstMove<1 && ctAlbastre==ctAlbastre1 && Mutari1>1){
  String s="";
   s=IntToStr(i);
   s+=IntToStr(808);
   s+=IntToStr(352);
   if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
		 Albastre[i]->Muta(808,352);
		 pozitie[PozitieInitiala]->SetContorAlbastre((pozitie[PozitieInitiala]->GetContorAlbastre()-1));
		 Mutari1--;
		 ctAlbastre1--;
	 }
	 else{
  if(AlegeZar==true && pozitie[FirstMove]->GetContor()<=1){
	  int x=pozitie[FirstMove]->GetContorAlbastre();
	  if((Mutari1>1 || Mutari1==4) && FirstMove>=1 && FirstMove<13){
      String s="";
   s=IntToStr(i);
   s+=IntToStr(pozitie[FirstMove]->PozitieLeft());
   s+=IntToStr(pozitie[FirstMove]->PozitieTop()-(40*x));
   if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
	   Albastre[i]->Muta(pozitie[FirstMove]->PozitieLeft(),pozitie[FirstMove]->PozitieTop()-(40*x));
	   Albastre[i]->SetPozitie(FirstMove);
	   pozitie[FirstMove]->SetContorAlbastre(x+1);
	   pozitie[PozitieInitiala]->SetContorAlbastre((pozitie[PozitieInitiala]->GetContorAlbastre()-1));
	   Mutari1--;
	 }
	 if((Mutari1>1 || Mutari1==4) && FirstMove>=13 && FirstMove<25){
	 String s="";
   s=IntToStr(i);
   s+=IntToStr(pozitie[FirstMove]->PozitieLeft());
   s+=IntToStr(pozitie[FirstMove]->PozitieTop()+(40*x));
   if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
	   Albastre[i]->Muta(pozitie[FirstMove]->PozitieLeft(),pozitie[FirstMove]->PozitieTop()+(40*x));
	   Albastre[i]->SetPozitie(FirstMove);
	   pozitie[FirstMove]->SetContorAlbastre(x+1);
	   pozitie[PozitieInitiala]->SetContorAlbastre((pozitie[PozitieInitiala]->GetContorAlbastre()-1));
	   Mutari1--;
	 }
  }
	 ctAlbastre=0;
	for(int i=1;i<=6;i++){
	   ctAlbastre+=pozitie[i]->GetContorAlbastre();

   }
  }
  if(AlegeZar==false && SecondMove<1 && ctAlbastre==ctAlbastre1 && Mutari2>1){
	String s="";
   s=IntToStr(i);
   s+=IntToStr(808);
   s+=IntToStr(352);
   if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }

		 Albastre[i]->Muta(808,352);
		 pozitie[PozitieInitiala]->SetContorAlbastre((pozitie[PozitieInitiala]->GetContorAlbastre()-1));
		 Mutari2--;
		 ctAlbastre1--;
	 }
	 else{
   if(AlegeZar==false && pozitie[SecondMove]->GetContor()<=1){
	 int y=pozitie[SecondMove]->GetContorAlbastre();
	 if(Mutari2>1 && SecondMove>=1 && SecondMove<13){
	   String s="";
   s=IntToStr(i);
   s+=IntToStr(pozitie[SecondMove]->PozitieLeft());
   s+=IntToStr(pozitie[SecondMove]->PozitieTop()-(40*y));
   if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }
	   Albastre[i]->Muta(pozitie[SecondMove]->PozitieLeft(),pozitie[SecondMove]->PozitieTop()-(40*y));
	   Albastre[i]->SetPozitie(SecondMove);
	   pozitie[SecondMove]->SetContorAlbastre(y+1);
	   pozitie[PozitieInitiala]->SetContorAlbastre((pozitie[PozitieInitiala]->GetContorAlbastre()-1));
	   Mutari2--;
	 }
	  if(Mutari2>1 && SecondMove>=13 && SecondMove<25){
		   String s="";
   s=IntToStr(i);
   s+=IntToStr(pozitie[SecondMove]->PozitieLeft());
   s+=IntToStr(pozitie[SecondMove]->PozitieTop()+(40*y));
   if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }

	   Albastre[i]->Muta(pozitie[SecondMove]->PozitieLeft(),pozitie[SecondMove]->PozitieTop()+(40*y));
	   Albastre[i]->SetPozitie(SecondMove);
	   pozitie[SecondMove]->SetContorAlbastre(y+1);
	   pozitie[PozitieInitiala]->SetContorAlbastre((pozitie[PozitieInitiala]->GetContorAlbastre()-1));
	   Mutari2--;
	 }
   }
  }
   ctAlbastre=0;
	for(int i=1;i<=6;i++){
	   ctAlbastre+=pozitie[i]->GetContorAlbastre();
   }


  } //---------------------SCOATERE PIESE-----------------------
  for(int j=0;j<15;j++){
		  if(Albastre[i]->GetPozitie()==Albe[j]->GetPozitie()){
		  pozitie[Albe[j]->GetPozitie()]->SetContorAlbe(0);
          String s="";
   s=IntToStr(i);
   s+=IntToStr(pozitie[0]->PozitieLeft());
   s+=IntToStr(pozitie[0]->PozitieTop());
   if(ServerSocket1->Active==true)
   {
	   ServerSocket1->Socket->Connections[0]->SendText(s);
   }
   if(ClientSocket1->Active==true)
   {
	   ClientSocket1->Socket->SendText(s) ;
   }

			Albe[j]->Muta(pozitie[0]->PozitieLeft(),pozitie[0]->PozitieTop());
			Albe[j]->SetPozitie(0);
		  }
	   }
   // --------------------SCOATERE PIESA-------------------------
  }
 // PotJuca=false;
  //ClientSocket1->Socket->SendText(string);
}
if(Mutari1==1 && Mutari2==1){
   PotJuca=false;
 }
 else
   PotJuca=true;
  if(ctAlbastre1==0)
  exit(0);

	}


//---------------------------------------------------------------------------

void __fastcall TmForm::FormShow(TObject *Sender)
{
  if(ServerForm->ShowModal()==mrYes){
		 ServerSocket1->Active=True;
		 PotJuca=true;
		 mForm->Caption="Server";

	 }
	 if( ServerForm->ShowModal()==mrOk){
		 //ClientSocket1->Address="127.0.0.1";
		 ClientSocket1->Active=True;
		 PotJuca=false;
         mForm->Caption="Client";
		 }
	 Image2 = new TImage(mForm);
	 Image2->Left=208;
	 Image2->Parent=mForm;
	 Image2->Top=125;
	 Image2->Picture->LoadFromFile("table2.png");
	 Image2->Width=649;
	 Image2->Height=465;
	 Image2->Stretch=true;
	 Image2->SendToBack();
	 srand(time(0));
	 zaruri=new Zar(0,0);
  for(int i=1;i<7;i++){
	 pozitie[i]=new Pozitie(744-((i-1)*45),528,0,0);
  }
  for(int i=7;i<13;i++){
	  pozitie[i]=new Pozitie(448-(i-7)*45,528,0,0);
					   //	223,128
  }
  for(int i=13;i<19;i++){
	 pozitie[i]=new Pozitie(223+(i-13)*45,125,0,0);
  }
  for(int i=19;i<25;i++){
	 pozitie[i]=new Pozitie(520+(i-19)*45,125,0,0);
  }
  pozitie[25]=new Pozitie(485,340,0,0);
  pozitie[0]=new Pozitie(485,300,0,0);

  pozitie[1]->SetContorAlbe(2);
  pozitie[6]->SetContorAlbastre(5);
  pozitie[8]->SetContorAlbastre(3);
  pozitie[12]->SetContorAlbe(5);
  pozitie[13]->SetContorAlbastre(5);
  pozitie[17]->SetContorAlbe(3);
  pozitie[19]->SetContorAlbe(5);
  pozitie[24]->SetContorAlbastre(2);

  Albe[0]=new PiesaAlba(744,490,1);
  Albe[1]=new PiesaAlba(744,530,1);
  Albe[2]=new PiesaAlba(224,528,12);
  Albe[3]=new PiesaAlba(224,488,12);
  Albe[4]=new PiesaAlba(224,448,12);
  Albe[5]=new PiesaAlba(224,408,12);
  Albe[6]=new PiesaAlba(224,368,12);
  Albe[7]=new PiesaAlba(403,125,17);
  Albe[8]=new PiesaAlba(403,165,17);
  Albe[9]=new PiesaAlba(403,205,17);
  Albe[10]=new PiesaAlba(520,125,19);
  Albe[11]=new PiesaAlba(520,165,19);
  Albe[12]=new PiesaAlba(520,205,19);
  Albe[13]=new PiesaAlba(520,245,19);
  Albe[14]=new PiesaAlba(520,285,19);
  Albastre[0]=new PiesaAlbastra(520,528,6);
  Albastre[1]=new PiesaAlbastra(520,488,6);
  Albastre[2]=new PiesaAlbastra(520,448,6);
  Albastre[3]=new PiesaAlbastra(520,408,6);
  Albastre[4]=new PiesaAlbastra(520,368,6);
  Albastre[5]=new PiesaAlbastra(400,528,8);
  Albastre[6]=new PiesaAlbastra(400,488,8);
  Albastre[7]=new PiesaAlbastra(400,448,8);
  Albastre[8]=new PiesaAlbastra(224,128,13);
  Albastre[9]=new PiesaAlbastra(224,168,13);
  Albastre[10]=new PiesaAlbastra(224,208,13);
  Albastre[11]=new PiesaAlbastra(224,248,13);
  Albastre[12]=new PiesaAlbastra(224,288,13);
  Albastre[13]=new PiesaAlbastra(744,128,24);
  Albastre[14]=new PiesaAlbastra(744,168,24);
  for(int i=0;i<15;i++){
	 Albe[i]->GetImagine()->OnClick=AlbClick;
  }
  for(int i=0;i<15;i++){
	Albastre[i]->GetImagine()->OnClick=AlbastruClick;
  }
}
//---------------------------------------------------------------------------


void __fastcall TmForm::ServerSocket1ClientRead(TObject *Sender, TCustomWinSocket *Socket)

{
String s=Socket->ReceiveText();
long date=StrToInt64(s);
int co2=date%1000;
date/=1000;
int co1=date%1000;
date/=1000;
int nr_p=date;
Albastre[nr_p]->Muta(co1,co2);






}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TmForm::ClientSocket1Read(TObject *Sender, TCustomWinSocket *Socket)

{
String s=Socket->ReceiveText();
long date=StrToInt64(s);
int co2=date%1000;
date/=1000;
int co1=date%1000;
date/=1000;
int nr_p=date;
Albe[nr_p]->Muta(co1,co2);

}
//---------------------------------------------------------------------------

