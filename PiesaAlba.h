//---------------------------------------------------------------------------

#ifndef PiesaAlbaH
#define PiesaAlbaH
#include "Piesa.h"
//---------------------------------------------------------------------------
	class PiesaAlba:public Piesa{
  private:
  int pozitie;
	public:
  PiesaAlba(int PozX,int PozY,int pozitie);
   void Muta(int PozX,int PozY);
   TImage* GetImagine();
   int GetPozitie();
   void SetPozitie(int pozitie);

};

#endif
