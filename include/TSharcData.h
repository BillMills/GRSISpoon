#ifndef __SharcDATA__
#define __SharcDATA__
/*****************************************************************************
 *
 *  The current layout of the 'data;' is inspired by and should be compatable
 *  with the NPTOOLS analysis kit maintained by our friends at the univeristy 
 *  of Surrey.   These class however are unique to the triumf sort code.
 *
 *  pcb
 *                                                                           
 *****************************************************************************/

// STL
#include <cstdlib>
#include <vector>
//#include <map>
using namespace std ;

// ROOT
//#include "TObject.h"
#include "TTigFragment.h"

class TSharcData  {
private:
  // Sharc
  // Energy
  vector<UShort_t>   fSharc_StripFront_DetectorNbr;		//!
  vector<UShort_t>   fSharc_StripFront_StripNbr;		//!
  vector<Double_t>   fSharc_StripFront_Energy;			//!
  vector<UInt_t>	 fSharc_StripFront_Charge;			//!
  vector<Double_t>   fSharc_StripFront_TimeCFD;			//!
  vector<Double_t>   fSharc_StripFront_TimeLED;			//!
  vector<Double_t>   fSharc_StripFront_Time;			//!
  vector<vector<Int_t> > fSharc_StripFront_Wave;			//!  


  vector<UShort_t>   fSharc_StripBack_DetectorNbr;		//!
  vector<UShort_t>   fSharc_StripBack_StripNbr;			//!
  vector<Double_t>   fSharc_StripBack_Energy;			//!
  vector<UInt_t>	 fSharc_StripBack_Charge;			//!
  vector<Double_t>   fSharc_StripBack_TimeCFD;			//!
  vector<Double_t>   fSharc_StripBack_TimeLED;			//!
  vector<Double_t>   fSharc_StripBack_Time;				//!
  vector<vector<Int_t> > fSharc_StripBack_Wave;			//!	

  vector<UShort_t>   fSharc_PAD_DetectorNbr;			//!
  vector<Double_t>   fSharc_PAD_Energy;					//!
  vector<Int_t>	   	 fSharc_PAD_Charge;					//!
  vector<Double_t>   fSharc_PAD_TimeCFD;				//!
  vector<Double_t>   fSharc_PAD_TimeLED;				//!
  vector<Double_t>   fSharc_PAD_Time;					//!
  vector<vector<Int_t> > fSharc_PAD_Wave;				//!

public:
  TSharcData();
  virtual ~TSharcData();
  
  void ClearData();
  //void Clear(const Option_t*) {};
  void Print();
  
  /////////////////////           SETTERS           ////////////////////////
  inline void SetFront_DetectorNbr(const UShort_t &DetNbr){fSharc_StripFront_DetectorNbr.push_back(DetNbr);}	//!
  inline void SetFront_StripNbr(const UShort_t &StripNbr){fSharc_StripFront_StripNbr.push_back(StripNbr);}		//!
  inline void SetFront_Energy(const Double_t &Energy){fSharc_StripFront_Energy.push_back(Energy);}				//!
  inline void SetFront_Charge(const UInt_t &Charge){fSharc_StripFront_Charge.push_back(Charge);}				//!
  inline void SetFront_TimeCFD(const Double_t &TimeCFD){fSharc_StripFront_TimeCFD.push_back(TimeCFD);}			//!
  inline void SetFront_TimeLED(const Double_t &TimeLED){fSharc_StripFront_TimeLED.push_back(TimeLED);}			//!
  inline void SetFront_Time(const Double_t &Time){fSharc_StripFront_Time.push_back(Time);}						//!

  inline void SetFront_Wave(const vector<Int_t> &Wave){fSharc_StripFront_Wave.push_back(Wave);}						//!


  inline void SetBack_DetectorNbr(const UShort_t &DetNbr){fSharc_StripBack_DetectorNbr.push_back(DetNbr);}		//!
  inline void SetBack_StripNbr(const UShort_t &StripNbr){fSharc_StripBack_StripNbr.push_back(StripNbr);}		//!
  inline void SetBack_Energy(const Double_t &Energy){fSharc_StripBack_Energy.push_back(Energy);}				//!
  inline void SetBack_Charge(const UInt_t &Charge){fSharc_StripBack_Charge.push_back(Charge);}					//!
  inline void SetBack_TimeCFD(const Double_t &TimeCFD){fSharc_StripBack_TimeCFD.push_back(TimeCFD);}			//!
  inline void SetBack_TimeLED(const Double_t &TimeLED){fSharc_StripBack_TimeLED.push_back(TimeLED);}			//!
  inline void SetBack_Time(const Double_t &Time){fSharc_StripBack_Time.push_back(Time);}						//!

  inline void SetBack_Wave(const vector<Int_t> &Wave){fSharc_StripBack_Wave.push_back(Wave);}							//!


  inline void SetPAD_DetectorNbr(const UShort_t &DetNbr){fSharc_PAD_DetectorNbr.push_back(DetNbr);}				//!
  inline void SetPAD_Energy(const Double_t &Energy){fSharc_PAD_Energy.push_back(Energy);}						//!
  inline void SetPAD_Charge(const Int_t &Charge){fSharc_PAD_Charge.push_back(Charge);}							//!
  inline void SetPAD_TimeCFD(const Double_t &TimeCFD){fSharc_PAD_TimeCFD.push_back(TimeCFD);}					//!
  inline void SetPAD_TimeLED(const Double_t &TimeLED){fSharc_PAD_TimeLED.push_back(TimeLED);}					//!
  inline void SetPAD_Time(const Double_t &Time){fSharc_PAD_Time.push_back(Time);}								//!

  inline void SetPAD_Wave(const vector<Int_t> &Wave){fSharc_PAD_Wave.push_back(Wave);}							//!


	inline void SetFront(const UShort_t &DetNbr,const UShort_t &StripNbr,const Double_t &Energy ,const Double_t &TimeCFD,const Double_t &TimeLED,const Double_t &Time = 0, const UInt_t &Charge = 0)	{
		SetFront_DetectorNbr(DetNbr);
		SetFront_StripNbr(StripNbr);
		SetFront_Energy(Energy);
		SetFront_TimeCFD(TimeCFD);
		SetFront_TimeLED(TimeLED);
		SetFront_Time(Time);
 		SetFront_Charge(Charge);
	};	//! sets the front using explicit inputs
	inline void SetFront(TTigFragment *frag,const UShort_t &DetNbr,const UShort_t &StripNbr )	{
		SetFront_DetectorNbr(DetNbr);
		SetFront_StripNbr(StripNbr);
		SetFront_Energy(frag->ChargeCal);
		SetFront_TimeCFD(frag->Cfd);
		SetFront_TimeLED(frag->Led);
		SetFront_Time(frag->TimeToTrig);
 		SetFront_Charge(frag->Charge);
	};	//! overload function that sets the front using fragment (updated by sjc)
	
	inline void SetBack(const UShort_t &DetNbr,const UShort_t &StripNbr,const Double_t &Energy,const Double_t &TimeCFD,const Double_t &TimeLED,const Double_t &Time = 0, const UInt_t &Charge = 0)	{
		SetBack_DetectorNbr(DetNbr);
		SetBack_StripNbr(StripNbr);
		SetBack_Energy(Energy);
		SetBack_TimeCFD(TimeCFD);
		SetBack_TimeLED(TimeLED);
		SetBack_Time(Time);
		SetBack_Charge(Charge);
	};	//!
	inline void SetBack(TTigFragment *frag,const UShort_t &DetNbr, const UShort_t &StripNbr )	{
		SetBack_DetectorNbr(DetNbr);
		SetBack_StripNbr(StripNbr);
		SetBack_Energy(frag->ChargeCal);
		SetBack_TimeCFD(frag->Cfd);
		SetBack_TimeLED(frag->Led);
		SetBack_Time(frag->TimeToTrig);
 		SetBack_Charge(frag->Charge);
	};	//! (updated by sjc)
	
	inline void SetPAD(const UShort_t &DetNbr,const Double_t &Energy,const Double_t &TimeCFD,const Double_t &TimeLED,const Double_t &Time = 0, const Int_t &Charge = 0)	{
		SetPAD_DetectorNbr(DetNbr);
		SetPAD_Energy(Energy);
		SetPAD_TimeCFD(TimeCFD);
		SetPAD_TimeLED(TimeLED);
		SetPAD_Time(Time);
		SetPAD_Charge(Charge);
	};	//!
	inline void SetPAD(TTigFragment *frag,const UShort_t &DetNbr)	{
		SetPAD_DetectorNbr(DetNbr);
		SetPAD_Energy(frag->ChargeCal);
		SetPAD_TimeCFD(frag->Cfd);
		SetPAD_TimeLED(frag->Led);
		SetPAD_Time(frag->TimeToTrig);
 		SetPAD_Charge(frag->Charge);
	};	//! (updated by sjc)  
	
  ///////////i//////////           GETTERS           ////////////////////////
  inline UShort_t GetFront_DetectorNbr(const unsigned int &i) const {return fSharc_StripFront_DetectorNbr[i];}	//!
  inline UShort_t GetFront_StripNbr(const unsigned int &i)    const {return fSharc_StripFront_StripNbr[i];}		//!
  inline Double_t GetFront_Energy(const unsigned int &i)      const {return fSharc_StripFront_Energy[i];}		//!
  inline UInt_t 	GetFront_Charge(const unsigned int &i)      const {return fSharc_StripFront_Charge[i];}		//!
  inline Double_t GetFront_TimeCFD(const unsigned int &i)     const {return fSharc_StripFront_TimeCFD[i];}		//!
  inline Double_t GetFront_TimeLED(const unsigned int &i)     const {return fSharc_StripFront_TimeLED[i];}		//!
  inline Double_t GetFront_Time(const unsigned int &i)     const {return fSharc_StripFront_Time[i];}			//!

  inline vector<Int_t> GetFront_Wave(const unsigned int &i)	const {return fSharc_StripFront_Wave.at(i);}		//!


  inline UShort_t GetBack_DetectorNbr(const unsigned int &i) const {return fSharc_StripBack_DetectorNbr[i];}	//!
  inline UShort_t GetBack_StripNbr(const unsigned int &i)    const {return fSharc_StripBack_StripNbr[i];}		//!
  inline Double_t GetBack_Energy(const unsigned int &i)      const {return fSharc_StripBack_Energy[i];}			//!
  inline UInt_t		GetBack_Charge(const unsigned int &i)      const {return fSharc_StripBack_Charge[i];}		//!
  inline Double_t GetBack_TimeCFD(const unsigned int &i)     const {return fSharc_StripBack_TimeCFD[i];}		//!
  inline Double_t GetBack_TimeLED(const unsigned int &i)     const {return fSharc_StripBack_TimeLED[i];}		//!
  inline Double_t GetBack_Time(const unsigned int &i)     const {return fSharc_StripBack_Time[i];}				//!

  inline vector<Int_t> GetBack_Wave(const unsigned int &i)	const {return fSharc_StripBack_Wave.at(i);}			//!


  inline UShort_t GetPAD_DetectorNbr(const unsigned int &i) const {return fSharc_PAD_DetectorNbr[i];}			//!
  inline Double_t GetPAD_Energy(const unsigned int &i)      const {return fSharc_PAD_Energy[i];}				//!
  inline Int_t		GetPAD_Charge(const int &i)      		const {return fSharc_PAD_Charge[i];}				//!
  inline Double_t GetPAD_TimeCFD(const unsigned int &i)     const {return fSharc_PAD_TimeCFD[i];}				//!
  inline Double_t GetPAD_TimeLED(const unsigned int &i)     const {return fSharc_PAD_TimeLED[i];}				//!
  inline Double_t GetPAD_Time(const unsigned int &i)    	  const {return fSharc_PAD_Time[i];}				//!

  inline vector<Int_t> GetPAD_Wave(const unsigned int &i)	const {return fSharc_PAD_Wave.at(i);}				//!


  inline unsigned int GetMultiplicityFront() const {return fSharc_StripFront_DetectorNbr.size();}				//!
  inline unsigned int GetMultiplicityBack()  const {return fSharc_StripBack_DetectorNbr.size();}				//!
  inline unsigned int GetMultiplicityPAD()   const {return fSharc_PAD_DetectorNbr.size();}						//!
 
  ClassDef(TSharcData,0)  // SharcData structure
};

#endif
