
//#include "../include/Globals.h" // for color

void testGauntlet()	{

	//open our files
	TFile *standard  = new TFile("fragment27422_000_benchmark.root");
	printf("\t"  "standard  file opened: %s" "\n", standard->GetName());
	TFile *contender = new TFile("fragment27422_000.root");
	printf("\t"  "contender file opened: %s" "\n", contender->GetName());

	
	//open our trees
	TTree *benchmarkTree = (TTree*)standard->Get("FragmentTree");
	TTree *contenderTree = (TTree*)contender->Get("FragmentTree");

	TTigFragment *frag_bench = 0;
	TTigFragment *frag_contd = 0;

	benchmarkTree->SetBranchAddress("TTigFragment",&frag_bench);
	contenderTree->SetBranchAddress("TTigFragment",&frag_contd);

	Int_t nentries_st = (Int_t)benchmarkTree->GetEntries();
	Int_t nentries_ct = (Int_t)contenderTree->GetEntries();
	
	TStopwatch w;

	if(nentries_ct != nentries_st)	{
		printf("warning standrad  tree has " "%i fragments!" "\n"  ,nentries_st);
		printf("warning contender tree has " "%i fragments!" "\n"  ,nentries_ct);
		return;
	}

	float percent; 
	for(Int_t i=0; i<nentries_st;i++)	{
		benchmarkTree->GetEntry(i);
		contenderTree->GetEntry(i);

		int status = CompareFragments(frag_bench,frag_contd);
		if(status<0) 
			printf("\terror on entry number: %i\n",i);

		if(i%500==0)	{
			percent = (float)i/(float)nentries_st * 100;
			printf("\t %.1f %% done. %.2f sec elapsed.             \r",percent,w.RealTime()); 
			w.Continue();
		}

	}

	percent = (float)i/(float)nentries_st * 100;
	printf("\t %.1f %% done. %.2f sec elapsed.             \n\n",percent,w.RealTime()); 
	printf("\n"); 
	int NumberBuiltFragments = CheckEventIndexing(contenderTree);
	printf("Fragments in FragmentTree  = %i\n",contenderTree->GetEntries());
	printf("Fragments in from in Index = %i\n",NumberBuiltFragments); 

	return;
};

          
int CompareFragments(TTigFragment *frag1, TTigFragment *frag2)	{
	if(!frag1 || !frag2)	{
		printf("One fragment not set!\n");
		return -1;				
	}

	if(frag1->MidasTimeStamp	!=	  frag2->MidasTimeStamp)	{	
		printf("TimeStamps do not match\n");
		return -1;				
	}

    	if(frag1->MidasId		!=        frag2->MidasId)	{		
		printf("Midas Ids do not match!\n");
		return -1;				
	}

	if(frag1->TriggerId		!=        frag2->TriggerId)	{	
		printf("Trigger Ids do not match!\n");
		return -1;				
	}

	if(frag1->FragmentId		!=        frag2->FragmentId)	{
		printf("Fragment Ids do not match!\n");
		return -1;				
	}

	if(frag1->TriggerBitPattern	!=        frag2->TriggerBitPattern)	{
		printf("TriggerBitPatterns do not match!\n");
		return -1;				
	}

	if(frag1->DigitizerType		!=        frag2->DigitizerType)	{		
		printf("Digitizer types do not match!\n");
		return -1;				
	}

	if(frag1->ODBType		!=        frag2->ODBType)	{		
		printf("ODB types do not match!\n");
		return -1;				
	}
                                                                               

	if(frag1->ChannelName		!=	  frag2->ChannelName)	{	
		printf("Channel Names do not match!\n");
		return -1;				
	}

	if(frag1->ChannelNumber		!=        frag2->ChannelNumber)	{		
		printf("Channel Numbers do not match!\n");
		return -1;				
	}

	if(frag1->ChannelAddress		!=        frag2->ChannelAddress)	{
		printf("Address Channel Values do not match!\n");
		return -1;				
	}

	if(frag1->Cfd			!=        frag2->Cfd)	{		
		printf("CFD values do not match!\n");
		return -1;				
	}

	if(frag1->Led			!=        frag2->Led)	{	
		printf("LED values do not match!\n");
		return -1;				
	}

	if(frag1->TimeToTrig		!=        frag2->TimeToTrig)	{	
		printf("CFD time master trigger time do not match!\n");
		return -1;				
	}

	if(frag1->Charge		!=        frag2->Charge)	{		
		printf("Raw charge values do not match!\n");
		return -1;				
	}

	if(frag1->ChargeCal		!=        frag2->ChargeCal)	{	
		printf("Calibrated charge values do not match!\n");
		return -1;				
	}
                                                                                
	if(frag1->TimeStampLow		!=        frag2->TimeStampLow)	{	
		printf("Low timestamp bits do not match!\n");
		return -1;				
	}

	if(frag1->TimeStampHigh		!=        frag2->TimeStampHigh)	{		
		printf("High timesatmp bits do not match!\n");
		return -1;				
	}

	if(frag1->TimeStampLive		!=        frag2->TimeStampLive)	{		
		printf("Live time stamps do not match!\n");
		return -1;				
	}

	if(frag1->TimeStampTR		!=        frag2->TimeStampTR)	{		
		printf("Triggers requested do not match!\n");
		return -1;				
	}

	if(frag1->TimeStampTA		!=        frag2->TimeStampTA)	{		
		printf("Triggers accepted do not match!\n");
		return -1;				
	}
};


int CheckEventIndexing(TTree *tree)	{

	int Total = 0; 

	int MinTriggerId = tree->GetMinimum("TriggerId");
	int MaxTriggerId = tree->GetMaximum("TriggerId");

	if(!tree->GetTreeIndex())	{
		printf("Tree Index not found, building index....\t");
		tree->BuildIndex("TriggerId","FragmentId");	
		printf(" done.\n");
	}
	

	for(int x=MinTriggerId;x<=MaxTriggerId;x++)	{
		int fragno = 1;
		while(tree->GetEntryNumberWithIndex(x,fragno++) != -1)	{
			Total += 1;
		}
	}
	return Total;
}



