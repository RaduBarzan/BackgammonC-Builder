//---------------------------------------------------------------------------

#ifndef PiesaH
#define PiesaH
//---------------------------------------------------------------------------
class Piesa{
public:
	 int PozX;
	 int PozY;
	 TImage *imagine;
	 TImage *imagine3;
  virtual void Muta(int PozX,int PozY)=0;


};

#endif
