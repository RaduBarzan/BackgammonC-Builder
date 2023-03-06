//---------------------------------------------------------------------------

#ifndef PozitieH
#define PozitieH
#include "Piesa.h"
//---------------------------------------------------------------------------
class Pozitie{
private:
 int PieseContorAlbe;
 int PieseContorAlbastre;
 int Ox;
 int Oy;
public:
	  Pozitie(int Ox,int Oy,int PieseContorAlbe,int PieseContorAlbastre);
	  TImage* imagine2;
	  void SetContorAlbe(int contor);
	  void SetContorAlbastre(int contor);
	  int GetContor();
	  int GetContorAlbastre();
	  int PozitieLeft();
	  int PozitieTop();
};
#endif
