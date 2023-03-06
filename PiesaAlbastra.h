//---------------------------------------------------------------------------

#ifndef PiesaAlbastraH
#define PiesaAlbastraH
#include "Piesa.h"
//---------------------------------------------------------------------------
 class PiesaAlbastra:public Piesa{
  private:
  int pozitie;
	public:
  PiesaAlbastra(int PozX,int PozY,int pozitie);
   void Muta(int PozX,int PozY);
   TImage* GetImagine();
   int GetPozitie();
   void SetPozitie(int pozitie);

};
#endif

