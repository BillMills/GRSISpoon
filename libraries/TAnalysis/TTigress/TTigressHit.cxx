
#include "TTigressHit.h"

ClassImp(TTigressHit)

TTigressHit::TTigressHit()	{	
	Clear();
}

TTigressHit::~TTigressHit()	{	}


void TTigressHit::Clear(Option_t *opt)	{

	detector = -1;
	crystal  = -1;
	first_segment = -1;
	first_segment_charge = 0.0;

	core.Clear();
	for(int x=0;x<segment.size();x++) { 
		segment[x].Clear();
	}
	segment.clear();
	for(int x=0;x<bgo.size();x++)	{
		bgo[x].Clear();
	}
	bgo.clear();

}


void TTigressHit::Print(Option_t *opt)	{
	printf("Tigress hit energy: %.2f\n",GetCore()->GetEnergy());
	printf("Tigress hit time:   %.2f\n",GetCore()->GetTime());
	//printf("Tigress hit TV3 theta: %.2f\tphi%.2f\n",position.Theta() *180/(3.141597),position.Phi() *180/(3.141597));
}


bool TTigressHit::Compare(TTigressHit lhs, TTigressHit rhs)	{
	if (lhs.GetDetectorNumber() == rhs.GetDetectorNumber())	{
		return(lhs.GetCrystalNumber() < rhs.GetCrystalNumber());
	}
	else	{
		return (lhs.GetDetectorNumber() < rhs.GetDetectorNumber()); 
	}
}

void TTigressHit::CheckFirstHit(int charge,int segment)	{
	if(charge > first_segment_charge)	{
 		first_segment = segment;
	}
	return;				
}

