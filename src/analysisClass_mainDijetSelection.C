#define analysisClass_cxx
#include "analysisClass.h"
#include <TH2.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TVector2.h>
#include <TVector3.h>

analysisClass::analysisClass(string * inputList, string * cutFile, string * treeName, string * outputFileName, string * cutEfficFile)
  :baseClass(inputList, cutFile, treeName, outputFileName, cutEfficFile)
{
  std::cout << "analysisClass::analysisClass(): begins " << std::endl;

  std::string jetAlgo = getPreCutString1("jetAlgo");
  double rParam = getPreCutValue1("DeltaR");

  if( jetAlgo == "AntiKt" )
    fjJetDefinition = JetDefPtr( new fastjet::JetDefinition(fastjet::antikt_algorithm, rParam) );
  else if( jetAlgo == "Kt" )
    fjJetDefinition = JetDefPtr( new fastjet::JetDefinition(fastjet::kt_algorithm, rParam) );
  else 
    fjJetDefinition = JetDefPtr( new fastjet::JetDefinition(fastjet::cambridge_algorithm, rParam) );

  // For JECs
  if( int(getPreCutValue1("useJECs"))==1 )
  {
    std::cout << "Reapplying JECs on the fly" << std::endl;
    //std::string L1Path = "/cmshome/gdimperi/Dijet/CMSDIJETrepo/CMSSW_7_4_6_patch6/src/CMSDIJET/DijetRootTreeMaker/data/Summer15_V5/Summer15_V5_MC_L1FastJet_AK4PFchs.txt";
    //std::string L2Path = "/cmshome/gdimperi/Dijet/CMSDIJETrepo/CMSSW_7_4_6_patch6/src/CMSDIJET/DijetRootTreeMaker/data/Summer15_V5/Summer15_V5_MC_L2Relative_AK4PFchs.txt"; 
    //std::string L3Path = "/cmshome/gdimperi/Dijet/CMSDIJETrepo/CMSSW_7_4_6_patch6/src/CMSDIJET/DijetRootTreeMaker/data/Summer15_V5/Summer15_V5_MC_L3Absolute_AK4PFchs.txt";
    //std::string L1Path = "data/Summer15_50nsV2/Summer15_50nsV2_MC_L1FastJet_AK4PFchs.txt";
    //std::string L2Path = "data/Summer15_50nsV2/Summer15_50nsV2_MC_L2Relative_AK4PFchs.txt"; 
    //std::string L3Path = "data/Summer15_50nsV2/Summer15_50nsV2_MC_L3Absolute_AK4PFchs.txt";
    //std::string L1DATAPath = "data/Summer15_50nsV2/Summer15_50nsV2_MC_L1FastJet_AK4PFchs.txt";
    //std::string L2DATAPath = "data/Summer15_50nsV2/Summer15_50nsV2_MC_L2Relative_AK4PFchs.txt"; 
    //std::string L3DATAPath = "data/Summer15_50nsV2/Summer15_50nsV2_MC_L3Absolute_AK4PFchs.txt";
    //
    //std::string L1Path = "data/Summer15_50nsV4/Summer15_50nsV4_MC_L1FastJet_AK4PFchs.txt";
    //std::string L2Path = "data/Summer15_50nsV4/Summer15_50nsV4_MC_L2Relative_AK4PFchs.txt"; 
    //std::string L3Path = "data/Summer15_50nsV4/Summer15_50nsV4_MC_L3Absolute_AK4PFchs.txt";
    //std::string L1DATAPath = "data/Summer15_50nsV4/Summer15_50nsV4_DATA_L1FastJet_AK4PFchs.txt";
    //std::string L2DATAPath = "data/Summer15_50nsV4/Summer15_50nsV4_DATA_L2Relative_AK4PFchs.txt"; 
    //std::string L3DATAPath = "data/Summer15_50nsV4/Summer15_50nsV4_DATA_L3Absolute_AK4PFchs.txt";
    //std::string L2L3ResidualPath = "data/Summer15_50nsV4/Summer15_50nsV4_DATA_L2L3Residual_AK4PFchs.txt" ;
    //
    //std::string L1Path = "data/Summer15_25nsV3_MC/Summer15_25nsV3_MC_L1FastJet_AK4PFchs.txt";
    //std::string L2Path = "data/Summer15_25nsV3_MC/Summer15_25nsV3_MC_L2Relative_AK4PFchs.txt"; 
    //std::string L3Path = "data/Summer15_25nsV3_MC/Summer15_25nsV3_MC_L3Absolute_AK4PFchs.txt";
    //std::string L1DATAPath = "data/Summer15_25nsV3_DATA/Summer15_25nsV3_DATA_L1FastJet_AK4PFchs.txt";
    //std::string L2DATAPath = "data/Summer15_25nsV3_DATA/Summer15_25nsV3_DATA_L2Relative_AK4PFchs.txt"; 
    //std::string L3DATAPath = "data/Summer15_25nsV3_DATA/Summer15_25nsV3_DATA_L3Absolute_AK4PFchs.txt";
    //std::string L2L3ResidualPath = "data/Summer15_25nsV3_DATA/Summer15_25nsV3_DATA_L2L3Residual_AK4PFchs.txt" ;
    //
    //std::string L1Path = "data/Summer15_25nsV5_MC/Summer15_25nsV5_MC_L1FastJet_AK4PFchs.txt";
    //std::string L2Path = "data/Summer15_25nsV5_MC/Summer15_25nsV5_MC_L2Relative_AK4PFchs.txt"; 
    //std::string L3Path = "data/Summer15_25nsV5_MC/Summer15_25nsV5_MC_L3Absolute_AK4PFchs.txt";
    //std::string L1DATAPath = "data/Summer15_25nsV5_DATA/Summer15_25nsV5_DATA_L1FastJet_AK4PFchs.txt";
    //std::string L2DATAPath = "data/Summer15_25nsV5_DATA/Summer15_25nsV5_DATA_L2Relative_AK4PFchs.txt"; 
    //std::string L3DATAPath = "data/Summer15_25nsV5_DATA/Summer15_25nsV5_DATA_L3Absolute_AK4PFchs.txt";
    //std::string L2L3ResidualPath = "data/Summer15_25nsV5_DATA/Summer15_25nsV5_DATA_L2L3Residual_AK4PFchs.txt" ;
    //
    /*
    std::string L1Path = "data/Summer15_25nsV6_MC/Summer15_25nsV6_MC_L1FastJet_AK4PFchs.txt";
    std::string L2Path = "data/Summer15_25nsV6_MC/Summer15_25nsV6_MC_L2Relative_AK4PFchs.txt"; 
    std::string L3Path = "data/Summer15_25nsV6_MC/Summer15_25nsV6_MC_L3Absolute_AK4PFchs.txt";
    std::string L1DATAPath = "data/Summer15_25nsV6_DATA/Summer15_25nsV6_DATA_L1FastJet_AK4PFchs.txt";
    std::string L2DATAPath = "data/Summer15_25nsV6_DATA/Summer15_25nsV6_DATA_L2Relative_AK4PFchs.txt"; 
    std::string L3DATAPath = "data/Summer15_25nsV6_DATA/Summer15_25nsV6_DATA_L3Absolute_AK4PFchs.txt";
    std::string L2L3ResidualPath = "data/Summer15_25nsV6_DATA/Summer15_25nsV6_DATA_L2L3Residual_AK4PFchs.txt" ;
    */
    // New production with V7 JEC for comparing RECO and HLT datasets for dijet scouting
    std::string L1Path = "data/Summer15_25nsV7_MC/Summer15_25nsV7_MC_L1FastJet_AK4PFchs.txt";
    std::string L2Path = "data/Summer15_25nsV7_MC/Summer15_25nsV7_MC_L2Relative_AK4PFchs.txt"; 
    std::string L3Path = "data/Summer15_25nsV7_MC/Summer15_25nsV7_MC_L3Absolute_AK4PFchs.txt";
    std::string L1DATAPath = "data/Summer15_25nsV7_DATA/Summer15_25nsV7_DATA_L1FastJet_AK4PFchs.txt";
    std::string L2DATAPath = "data/Summer15_25nsV7_DATA/Summer15_25nsV7_DATA_L2Relative_AK4PFchs.txt"; 
    std::string L3DATAPath = "data/Summer15_25nsV7_DATA/Summer15_25nsV7_DATA_L3Absolute_AK4PFchs.txt";
    std::string L2L3ResidualPath = "data/Summer15_25nsV7_DATA/Summer15_25nsV7_DATA_L2L3Residual_AK4PFchs.txt" ;
    

    
    L1Par = new JetCorrectorParameters(L1Path);
    L2Par = new JetCorrectorParameters(L2Path);
    L3Par = new JetCorrectorParameters(L3Path);
    L1DATAPar = new JetCorrectorParameters(L1DATAPath);
    L2DATAPar = new JetCorrectorParameters(L2DATAPath);
    L3DATAPar = new JetCorrectorParameters(L3DATAPath);
    L2L3Residual = new JetCorrectorParameters(L2L3ResidualPath);

    std::vector<JetCorrectorParameters> vPar;
    std::vector<JetCorrectorParameters> vPar_data;
    vPar.push_back(*L1Par);
    vPar.push_back(*L2Par);
    vPar.push_back(*L3Par);
   
    //residuals are applied only to data
    vPar_data.push_back(*L1DATAPar);
    vPar_data.push_back(*L2DATAPar);
    vPar_data.push_back(*L3DATAPar);
    vPar_data.push_back(*L2L3Residual);

    JetCorrector = new FactorizedJetCorrector(vPar);
    JetCorrector_data = new FactorizedJetCorrector(vPar_data);

    //uncertainty
    //unc = new JetCorrectionUncertainty("data/Summer15_50nsV5_DATA/Summer15_50nsV5_DATA_Uncertainty_AK4PFchs.txt");
    //unc = new JetCorrectionUncertainty("data/Summer15_25nsV5_DATA/Summer15_25nsV5_DATA_Uncertainty_AK4PFchs.txt");
    unc = new JetCorrectionUncertainty("data/Summer15_25nsV7_DATA/Summer15_25nsV7_DATA_Uncertainty_AK4PFchs.txt");
  }
  
  std::cout << "analysisClass::analysisClass(): ends " << std::endl;
}

analysisClass::~analysisClass()
{
  std::cout << "analysisClass::~analysisClass(): begins " << std::endl;

  std::cout << "analysisClass::~analysisClass(): ends " << std::endl;
}

void analysisClass::Loop()
{
   std::cout << "analysisClass::Loop() begins" <<std::endl;   
    
   if (fChain == 0) return;
   
   //////////book histos here

   // TH1F *h_nJetFinal = new TH1F ("h_nJetFinal","",10,0,10);
   // h_nJetFinal->Sumw2();      
   // TH1F *h_nVtx = new TH1F ("h_nVtx","",30,0,30);
   // h_nVtx->Sumw2(); 
   // TH1F *h_trueVtx = new TH1F ("h_trueVtx","",40,0,40);
   // h_trueVtx->Sumw2();  
   // TH1F *h_pT1stJet = new TH1F ("h_pT1stJet","",100,0,3000);
   // h_pT1stJet->Sumw2();
   // TH1F *h_pT2ndJet = new TH1F ("h_pT2ndJet","",100,0,3000);
   // h_pT2ndJet->Sumw2();
   // TH1F *h_eta1stJet = new TH1F ("h_eta1stJet","",5,-2.5,2.5);
   // h_eta1stJet->Sumw2();
   // TH1F *h_eta2ndJet = new TH1F ("h_eta2ndJet","",5,-2.5,2.5);
   // h_eta2ndJet->Sumw2();
   // TH1F *h_DijetMass = new TH1F ("h_DijetMass","",600,0,6000);
   // h_DijetMass->Sumw2();
   // TH1F *h_DeltaETAjj = new TH1F ("h_DeltaETAjj","",120,0,3.);
   // h_DeltaETAjj->Sumw2();

   // variable binning for mjj trigger efficiency plots
   const int nMassBins = 103;

   double massBoundaries[nMassBins+1] = {1, 3, 6, 10, 16, 23, 31, 40, 50, 61, 74, 88, 103, 119, 137, 156, 176, 197, 220, 244, 270, 296, 325,
     354, 386, 419, 453, 489, 526, 565, 606, 649, 693, 740, 788, 838, 890, 944, 1000, 1058, 1118, 1181, 1246, 1313, 1383, 1455, 1530, 1607, 1687,
     1770, 1856, 1945, 2037, 2132, 2231, 2332, 2438, 2546, 2659, 2775, 2895, 3019, 3147, 3279, 3416, 3558, 3704, 3854, 4010, 4171, 4337, 4509,
     4686, 4869, 5058, 5253, 5455, 5663, 5877, 6099, 6328, 6564, 6808, 7060, 7320, 7589, 7866, 8152, 8447, 8752, 9067, 9391, 9726, 10072, 10430, 
     10798, 11179, 11571, 11977, 12395, 12827, 13272, 13732, 14000};


   char* HLTname[50] = {"noTrig","PFHT475","PFHT800","PFHT650MJJ900","PFHT800_OR_PFHT650MJJ900","PFHT800_noPFHT475", 
                        "Mu45Eta2p1", "PFHT800AndMu45Eta2p1"};
   TH1F* h_mjj_HLTpass[8];
   char name_histoHLT[50];
   for (int i=0; i<8; i++){  
     sprintf(name_histoHLT,"h_mjj_HLTpass_%s",HLTname[i]);
     h_mjj_HLTpass[i]= new TH1F(name_histoHLT,"",103,massBoundaries);
   }
  

   /////////initialize variables

   Long64_t nentries = fChain->GetEntriesFast();
   std::cout << "analysisClass::Loop(): nentries = " << nentries << std::endl;   

   ////// The following ~7 lines have been taken from rootNtupleClass->Loop() /////
   ////// If the root version is updated and rootNtupleClass regenerated,     /////
   ////// these lines may need to be updated.                                 /////    
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<2000;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     if(jentry < 10 || jentry%1000 == 0) std::cout << "analysisClass::Loop(): jentry = " << jentry << std::endl;   
     // if (Cut(ientry) < 0) continue;

     ////////////////////// User's code starts here ///////////////////////

     ///Stuff to be done for every event

     size_t no_jets_ak4=jetPtAK4->size();

     vector<TLorentzVector> widejets;
     TLorentzVector wj1, wj2, wdijet; 
     TLorentzVector wj1_shift, wj2_shift, wdijet_shift; 

     vector<TLorentzVector> AK4jets;
     TLorentzVector ak4j1, ak4j2, ak4dijet;      

     resetCuts();

     //find intime BX
     int idx_InTimeBX=-1;
     for(size_t j=0; j<PileupOriginBX->size(); ++j)
       {
	 //cout << PileupOriginBX->at(j) << endl;	 
	 if(PileupOriginBX->at(j)==0)
	   {
	     idx_InTimeBX = j;
	     //cout << "idx_InTimeBX: " << idx_InTimeBX << endl; 
	   }
       }

     std::vector<double> jecFactors;
     std::vector<double> jecUncertainty;
     // new JECs could change the jet pT ordering. the vector below
     // holds sorted jet indices after the new JECs had been applied
     std::vector<unsigned> sortedJetIdx;
     bool isData = 0;
     if(idx_InTimeBX > -1 ) isData = 0;
     else isData = 1;

     if( int(getPreCutValue1("useJECs"))==1 )
       {
	 // sort jets by increasing pT
	 std::multimap<double, unsigned> sortedJets;
	 for(size_t j=0; j<no_jets_ak4; ++j)
	   {
	     JetCorrector->setJetEta(jetEtaAK4->at(j));
	     JetCorrector->setJetPt(jetPtAK4->at(j)/jetJecAK4->at(j)); //pTraw
	     JetCorrector->setJetA(jetAreaAK4->at(j));
	     JetCorrector->setRho(rho);

  	     JetCorrector_data->setJetEta(jetEtaAK4->at(j));
	     JetCorrector_data->setJetPt(jetPtAK4->at(j)/jetJecAK4->at(j)); //pTraw
	     JetCorrector_data->setJetA(jetAreaAK4->at(j));
	     JetCorrector_data->setRho(rho);


  	     //nominal value of JECs
	     double correction;//, old_correction, nominal_correction;
	     //if( int(getPreCutValue1("shiftJECs"))==0 ){
	     if (isData == 1) correction = JetCorrector_data->getCorrection();
	     else correction = JetCorrector->getCorrection();
	     //nominal_correction=correction;
	     //old_correction = jetJecAK4->at(j);
	     //}
	     //JEC uncertainties
	     unc->setJetEta(jetEtaAK4->at(j));
	     unc->setJetPt(jetPtAK4->at(j)/jetJecAK4->at(j)*correction);
	     double uncertainty = unc->getUncertainty(true);
	     jecUncertainty.push_back(uncertainty); 

	     // std::cout << "run:" << runNo << "    lumi:" << lumi << "   event:" << evtNo << "   jet pt:" << jetPtAK4->at(j)/jetJecAK4->at(j)*correction << "   correction:" << correction <<   "   uncertainty:" <<  uncertainty  << "  nominal correction:" << nominal_correction  << " old correction: " << old_correction << std::endl;
	     //use "shifted" JECs for study of systematic uncertainties 
	     if( int(getPreCutValue1("shiftJECs"))==1 ){
	       //flat shift
	       //if (isData == 1) correction = JetCorrector_data->getCorrection() * getPreCutValue2("shiftJECs");
	       //else correction = JetCorrector->getCorrection() * getPreCutValue2("shiftJECs");
	       //shift of the corresponding unc
	       correction = correction + getPreCutValue2("shiftJECs")*uncertainty*correction;
	       //  std::cout << "run:" << runNo << "    lumi:" << lumi << "   event:" << evtNo << "   jet pt:" << jetPtAK3->at(j)/jetJecAK4->at(j)*correction << "   correction:" << correction << "   uncertainty:" <<  uncertainty  << std::endl << std::endl;
	       
	   }

	 jecFactors.push_back(correction);
	 sortedJets.insert(std::make_pair((jetPtAK4->at(j)/jetJecAK4->at(j))*correction, j));

       }
     // get jet indices in decreasing pT order
     for(std::multimap<double, unsigned>::const_reverse_iterator it = sortedJets.rbegin(); it != sortedJets.rend(); ++it)
	 sortedJetIdx.push_back(it->second);
     
     }
     else if( int(getPreCutValue1("noJECs"))==1  )
       {
	 // sort jets by increasing pT
	 std::multimap<double, unsigned> sortedJets;
	 for(size_t j=0; j<no_jets_ak4; ++j) //same ordering of original root trees
	   {
	     jecUncertainty.push_back(0.); 
	     jecFactors.push_back(1.);
	     sortedJets.insert(std::make_pair((jetPtAK4->at(j)/jetJecAK4->at(j)), j)); //raw
	   }       
	 // get jet indices in decreasing pT order
	 for(std::multimap<double, unsigned>::const_reverse_iterator it = sortedJets.rbegin(); it != sortedJets.rend(); ++it)
	   sortedJetIdx.push_back(it->second);
       }
     else
       {
	 for(size_t j=0; j<no_jets_ak4; ++j) //same ordering of original root trees
	   {
	     jecFactors.push_back(jetJecAK4->at(j));
	     jecUncertainty.push_back(0.); 
	     sortedJetIdx.push_back(j);
	   }
       }


     //#############################################################
     //########## NOTE: from now on sortedJetIdx[ijet] should be used
     //#############################################################

     // if(no_jets_ak4>=2){
     //  if(!(fabs(jetEtaAK4->at(0)) < getPreCutValue1("jetFidRegion") && idTAK4->at(0) == getPreCutValue1("tightJetID"))){
     //    std::cout << " JET 0 FAIL " << jetEtaAK4->at(0) << " JET 0  ID " << idTAK4->at(0) << std::endl;
     //  }
     //  if(!(fabs(jetEtaAK4->at(1)) < getPreCutValue1("jetFidRegion") && idTAK4->at(1) == getPreCutValue1("tightJetID"))){
     //    std::cout << " JET 1 FAIL " << jetEtaAK4->at(1) << " JET 1  ID " << idTAK4->at(1) << std::endl;
     //  }  
     // }

     //count ak4 jets passing pt threshold and id criteria
     int Nak4 = 0;
     double HTak4 = 0;
     for(size_t ijet=0; ijet<no_jets_ak4; ++ijet)
       {	 
	  //cout << "ijet=" << ijet << " , sortedJetIdx[ijet]=" << sortedJetIdx[ijet] 
	  //     << " , raw pT=" << jetPtAK4->at(sortedJetIdx[ijet])/jetJecAK4->at(sortedJetIdx[ijet]) 
	  //     << " , final corrected pT - old =" << jetPtAK4->at(sortedJetIdx[ijet] ) 
	  //     << " , final corrected pT - new =" << (jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet]))*jetPtAK4->at(sortedJetIdx[ijet])
	  //     << endl;

	 //////////////cout << "id Tight jet" << sortedJetIdx[1] << " = " << idTAK4->at(sortedJetIdx[1]) << endl;
	 if(fabs(jetEtaAK4->at(sortedJetIdx[ijet])) < getPreCutValue1("jetFidRegion")
	    && idTAK4->at(sortedJetIdx[ijet]) == getPreCutValue1("tightJetID")
	    && (jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet]))*jetPtAK4->at(sortedJetIdx[ijet]) > getPreCutValue1("ptCut"))
	   {
	     Nak4 += 1;
	     HTak4 += (jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet]))*jetPtAK4->at(sortedJetIdx[ijet]);
	   }
       }


     if( int(getPreCutValue1("useFastJet"))==1 )
     {
       // vector of ak4 jets used for wide jet clustering
       std::vector<fastjet::PseudoJet> fjInputs, fjInputs_shift;

       for(size_t j=0; j<no_jets_ak4; ++j)
       {
	 if( !(jetEtaAK4->at(sortedJetIdx[j]) < getPreCutValue1("jetFidRegion")
	       && idTAK4->at(sortedJetIdx[j]) == getPreCutValue1("tightJetID")) ) continue;

	 double rescale = (jecFactors[sortedJetIdx[j]]/jetJecAK4->at(sortedJetIdx[j]));

	 if( j==0 && !( rescale*jetPtAK4->at(sortedJetIdx[j]) > getPreCutValue1("pt0Cut")) ) continue;
	 else if( j==1 && !( rescale*jetPtAK4->at(sortedJetIdx[j]) > getPreCutValue1("pt1Cut")) ) continue;
	 else if( !( rescale*jetPtAK4->at(sortedJetIdx[j]) > getPreCutValue1("ptCut")) ) continue;

	 TLorentzVector tempJet, tempJet_shift;

	 tempJet.SetPtEtaPhiM( rescale*jetPtAK4->at(sortedJetIdx[j]) , jetEtaAK4->at(sortedJetIdx[j]) , jetPhiAK4->at(sortedJetIdx[j]) , rescale*jetMassAK4->at(sortedJetIdx[j]));
	 tempJet_shift.SetPtEtaPhiM( (1+jecUncertainty[sortedJetIdx[j]])* rescale*jetPtAK4->at(sortedJetIdx[j]) , jetEtaAK4->at(sortedJetIdx[j]) , jetPhiAK4->at(sortedJetIdx[j]) ,  (1+jecUncertainty[sortedJetIdx[j]])* rescale*jetMassAK4->at(sortedJetIdx[j]));

	 fjInputs.push_back(fastjet::PseudoJet(tempJet.Px(),tempJet.Py(),tempJet.Pz(),tempJet.E()));
	 fjInputs_shift.push_back(fastjet::PseudoJet(tempJet_shift.Px(),tempJet_shift.Py(),tempJet_shift.Pz(),tempJet_shift.E()));
       }

       fjClusterSeq = ClusterSequencePtr( new fastjet::ClusterSequence( fjInputs, *fjJetDefinition ) );
       fjClusterSeq_shift = ClusterSequencePtr( new fastjet::ClusterSequence( fjInputs_shift, *fjJetDefinition ) );

       std::vector<fastjet::PseudoJet> inclusiveWideJets = fastjet::sorted_by_pt( fjClusterSeq->inclusive_jets(0.) );
       std::vector<fastjet::PseudoJet> inclusiveWideJets_shift = fastjet::sorted_by_pt( fjClusterSeq_shift->inclusive_jets(0.) );

       if( inclusiveWideJets.size()>1 )
       {
	 wj1.SetPxPyPzE(inclusiveWideJets.at(0).px(), inclusiveWideJets.at(0).py(), inclusiveWideJets.at(0).pz(), inclusiveWideJets.at(0).e());
	 wj2.SetPxPyPzE(inclusiveWideJets.at(1).px(), inclusiveWideJets.at(1).py(), inclusiveWideJets.at(1).pz(), inclusiveWideJets.at(1).e());
	 wj1_shift.SetPxPyPzE(inclusiveWideJets_shift.at(0).px(), inclusiveWideJets_shift.at(0).py(), inclusiveWideJets_shift.at(0).pz(), inclusiveWideJets_shift.at(0).e());
	 wj2_shift.SetPxPyPzE(inclusiveWideJets_shift.at(1).px(), inclusiveWideJets_shift.at(1).py(), inclusiveWideJets_shift.at(1).pz(), inclusiveWideJets_shift.at(1).e());
       }
     }
     else
     {
       TLorentzVector wj1_tmp, wj2_tmp;
       TLorentzVector wj1_shift_tmp, wj2_shift_tmp;
       double wideJetDeltaR_ = getPreCutValue1("DeltaR");

       if(no_jets_ak4>=2)
	 {
	   if(fabs(jetEtaAK4->at(sortedJetIdx[0])) < getPreCutValue1("jetFidRegion") 
	      && (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0]))*jetPtAK4->at(sortedJetIdx[sortedJetIdx[0]]) > getPreCutValue1("pt0Cut"))
	     {
	       if(fabs(jetEtaAK4->at(sortedJetIdx[1])) < getPreCutValue1("jetFidRegion") 
		  && (jecFactors[sortedJetIdx[1]]/jetJecAK4->at(sortedJetIdx[1]))*jetPtAK4->at(sortedJetIdx[1]) > getPreCutValue1("pt1Cut"))
		 {
		   TLorentzVector jet1, jet2, jet1_shift, jet2_shift;
		   jet1.SetPtEtaPhiM( (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) *jetPtAK4->at(sortedJetIdx[0])
				      ,jetEtaAK4->at(sortedJetIdx[0]),jetPhiAK4->at(sortedJetIdx[0])
				      , (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) * jetMassAK4->at(sortedJetIdx[0]));
		   jet2.SetPtEtaPhiM( (jecFactors[sortedJetIdx[1]]/jetJecAK4->at(sortedJetIdx[1])) *jetPtAK4->at(sortedJetIdx[1])
				      ,jetEtaAK4->at(sortedJetIdx[1]),jetPhiAK4->at(sortedJetIdx[1])
				      , (jecFactors[sortedJetIdx[1]]/jetJecAK4->at(sortedJetIdx[1])) * jetMassAK4->at(sortedJetIdx[1]));
		   jet1_shift.SetPtEtaPhiM( (1+jecUncertainty[sortedJetIdx[0]])*(jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) *jetPtAK4->at(sortedJetIdx[0])
				      ,jetEtaAK4->at(sortedJetIdx[0]),jetPhiAK4->at(sortedJetIdx[0])
				      , (1+jecUncertainty[sortedJetIdx[0]])*(jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) * jetMassAK4->at(sortedJetIdx[0]));
		   jet2_shift.SetPtEtaPhiM( (1+jecUncertainty[sortedJetIdx[1]])* (jecFactors[sortedJetIdx[1]]/jetJecAK4->at(sortedJetIdx[1])) *jetPtAK4->at(sortedJetIdx[1])
				      ,jetEtaAK4->at(sortedJetIdx[1]),jetPhiAK4->at(sortedJetIdx[1])
				      , (1+jecUncertainty[sortedJetIdx[0]])*(jecFactors[sortedJetIdx[1]]/jetJecAK4->at(sortedJetIdx[1])) * jetMassAK4->at(sortedJetIdx[1]));
		   
		   for(Long64_t ijet=0; ijet<no_jets_ak4; ijet++)
		     { //jet loop for ak4
		       TLorentzVector currentJet;
		       
		       if(fabs(jetEtaAK4->at(sortedJetIdx[ijet])) < getPreCutValue1("jetFidRegion") 
			  && idTAK4->at(sortedJetIdx[ijet]) == getPreCutValue1("tightJetID") 
			  && (jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet]))*jetPtAK4->at(sortedJetIdx[ijet]) > getPreCutValue1("ptCut"))
			 {
			   TLorentzVector currentJet, currentJet_shift;
			   currentJet.SetPtEtaPhiM( (jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet])) *jetPtAK4->at(sortedJetIdx[ijet])
						    ,jetEtaAK4->at(sortedJetIdx[ijet]),jetPhiAK4->at(sortedJetIdx[ijet])
						    , (jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet])) *jetMassAK4->at(sortedJetIdx[ijet]));   
			   currentJet_shift.SetPtEtaPhiM( (1+jecUncertainty[sortedJetIdx[ijet]])*(jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet])) *jetPtAK4->at(sortedJetIdx[ijet])
						    ,jetEtaAK4->at(sortedJetIdx[ijet]),jetPhiAK4->at(sortedJetIdx[ijet])
						    , (1+jecUncertainty[sortedJetIdx[ijet]])*(jecFactors[sortedJetIdx[ijet]]/jetJecAK4->at(sortedJetIdx[ijet])) *jetMassAK4->at(sortedJetIdx[ijet]));   
			   
			   double DeltaR1 = currentJet.DeltaR(jet1);
			   double DeltaR2 = currentJet.DeltaR(jet2);
			   
			   if(DeltaR1 < DeltaR2 && DeltaR1 < wideJetDeltaR_)
			     {
			       wj1_tmp += currentJet;
			       wj1_shift_tmp += currentJet_shift;
			     }
			   else if(DeltaR2 < wideJetDeltaR_)
			     {
			       wj2_tmp += currentJet;
			       wj2_shift_tmp += currentJet_shift;
			     }			 
			 } // if AK4 jet passes fid and jetid.
		     } //end of ak4 jet loop		     

		   // if(wj1_tmp.Pt()==0 && wj2_tmp.Pt() ==0) 
		   // std::cout << " wj1_tmp.Pt() IN  " <<wj1_tmp.Pt()  << " wj2_tmp.Pt() " <<  wj2_tmp.Pt()  << std::endl;		     

		 } //fid, jet id, pt cut
	     } //fid, jet id, pt cut
	 } // end of two jets.
	 
       // Re-order the wide jets in pt
       if( wj1_tmp.Pt() > wj2_tmp.Pt())
	 {
	   wj1 = wj1_tmp;
	   wj2 = wj2_tmp;
	   wj1_shift = wj1_shift_tmp;
	   wj2_shift = wj2_shift_tmp;
	 }
       else
	 {
	   wj1 = wj2_tmp;
	   wj2 = wj1_tmp;
	   wj1_shift = wj2_shift_tmp;
	   wj2_shift = wj1_shift_tmp;
	 }
     }


     double MJJWide = 0; 
     double DeltaEtaJJWide = 0;
     double DeltaPhiJJWide = 0;
     double MJJWide_shift = 0; 
     if( wj1.Pt()>0 && wj2.Pt()>0 )
     {
       // Create dijet system
       wdijet = wj1 + wj2;
       MJJWide = wdijet.M();
       DeltaEtaJJWide = fabs(wj1.Eta()-wj2.Eta());
       DeltaPhiJJWide = fabs(wj1.DeltaPhi(wj2));
       
       wdijet_shift = wj1_shift + wj2_shift;
       MJJWide_shift = wdijet_shift.M();

       // Put widejets in the container
       widejets.push_back( wj1 );
       widejets.push_back( wj2 );
     }

     //AK4 jets
     if(no_jets_ak4>=2)
       //cout << "eta j1 " << jetEtaAK4->at(sortedJetIdx[0]) << endl;
       //cout << "pt j1 " << (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) *jetPtAK4->at(sortedJetIdx[0]) << endl;
       {
	 if(fabs(jetEtaAK4->at(sortedJetIdx[0])) < getPreCutValue1("jetFidRegion") 
	    && (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0]))*jetPtAK4->at(sortedJetIdx[0]) > getPreCutValue1("pt0Cut"))
	   {
	     if(fabs(jetEtaAK4->at(sortedJetIdx[1])) < getPreCutValue1("jetFidRegion") 
		&& (jecFactors[sortedJetIdx[1]]/jetJecAK4->at(sortedJetIdx[1]))*jetPtAK4->at(sortedJetIdx[1]) > getPreCutValue1("pt1Cut"))
	       {
		 //cout << "filling ak4j1 and ak4j2" << endl;
		 //cout << "pt ak4 j1 = " << (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) *jetPtAK4->at(sortedJetIdx[0]) << endl;
		 ak4j1.SetPtEtaPhiM( (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) *jetPtAK4->at(sortedJetIdx[0])
				     ,jetEtaAK4->at(sortedJetIdx[0])
				     ,jetPhiAK4->at(sortedJetIdx[0])
				     , (jecFactors[sortedJetIdx[0]]/jetJecAK4->at(sortedJetIdx[0])) *jetMassAK4->at(sortedJetIdx[0]));
		 ak4j2.SetPtEtaPhiM( (jecFactors[sortedJetIdx[1]]/jetJecAK4->at(sortedJetIdx[1])) *jetPtAK4->at(sortedJetIdx[1])
				     ,jetEtaAK4->at(sortedJetIdx[1])
				     ,jetPhiAK4->at(sortedJetIdx[1])
				     , (jecFactors[sortedJetIdx[1]]/jetJecAK4->at(sortedJetIdx[1])) *jetMassAK4->at(sortedJetIdx[1]));
	       }
	   }
       }   

     double MJJAK4 = 0; 
     double DeltaEtaJJAK4 = 0;
     double DeltaPhiJJAK4 = 0;
     
     //std::cout << "ak4j1.Pt()=" << ak4j1.Pt() << "   ak4j2.Pt()=" << ak4j2.Pt() << std::endl;
     if( ak4j1.Pt()>0 && ak4j2.Pt()>0 )
     {
       // Create dijet system
       ak4dijet = ak4j1 + ak4j2;
       MJJAK4 = ak4dijet.M();
       DeltaEtaJJAK4 = fabs(ak4j1.Eta()-ak4j2.Eta());
       DeltaPhiJJAK4 = fabs(ak4j1.DeltaPhi(ak4j2));

       // Put widejets in the container
       AK4jets.push_back( ak4j1 );
       AK4jets.push_back( ak4j2 );
     }
    
     //== Fill Variables ==

     fillVariableWithValue("run",runNo);     
     fillVariableWithValue("event",evtNo);     
     fillVariableWithValue("lumi",lumi);     
     fillVariableWithValue("nVtx",nvtx);     
     fillVariableWithValue("nJet",widejets.size());
     fillVariableWithValue("metSig",metSig);
     fillVariableWithValue("Nak4",Nak4);
     fillVariableWithValue ( "PassJSON", passJSON (runNo, lumi, isData));

     if( AK4jets.size() >=1 ){
       //cout << "AK4jets.size() " <<  AK4jets.size() << endl;
       //cout << "IdTight_j1 : " << idTAK4->at(sortedJetIdx[0]) << endl;
       fillVariableWithValue( "IdTight_j1",idTAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "pTAK4_j1", AK4jets[0].Pt());
       fillVariableWithValue( "etaAK4_j1", AK4jets[0].Eta());
       fillVariableWithValue( "phiAK4_j1", AK4jets[0].Phi());
       fillVariableWithValue( "jetPtAK4matchCaloJet_j1", jetPtAK4matchCaloJet->at(sortedJetIdx[0]));
       fillVariableWithValue( "jetJecAK4_j1", jecFactors[sortedJetIdx[0]] );
       fillVariableWithValue( "jetJecUncAK4_j1", jecUncertainty[sortedJetIdx[0]] );
       //jetID
       fillVariableWithValue( "neutrHadEnFrac_j1", jetNhfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "chargedHadEnFrac_j1", jetChfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "photonEnFrac_j1", jetPhfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "eleEnFract_j1", jetElfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "muEnFract_j1", jetMufAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "neutrElectromFrac_j1", jetNemfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "chargedElectromFrac_j1", jetCemfAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "chargedMult_j1", chMultAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "neutrMult_j1", neMultAK4->at(sortedJetIdx[0]));
       fillVariableWithValue( "photonMult_j1", phoMultAK4->at(sortedJetIdx[0]));
     }
     if( AK4jets.size() >=2 ){
       //cout << "IdTight_j2 : " << idTAK4->at(sortedJetIdx[1]) << endl << endl;
       fillVariableWithValue( "IdTight_j2",idTAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "pTAK4_j2", AK4jets[1].Pt() );
       fillVariableWithValue( "etaAK4_j2", AK4jets[1].Eta());
       fillVariableWithValue( "phiAK4_j2", AK4jets[1].Phi());
       fillVariableWithValue( "jetPtAK4matchCaloJet_j2", jetPtAK4matchCaloJet->at(sortedJetIdx[1]));
       fillVariableWithValue( "jetJecAK4_j2", jecFactors[sortedJetIdx[1]]); 
       fillVariableWithValue( "jetJecUncAK4_j2", jecUncertainty[sortedJetIdx[1]] );
       //jetID
       fillVariableWithValue( "neutrHadEnFrac_j2", jetNhfAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "chargedHadEnFrac_j2", jetChfAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "photonEnFrac_j2", jetPhfAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "eleEnFract_j2", jetElfAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "muEnFract_j2", jetMufAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "neutrElectromFrac_j2", jetNemfAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "chargedElectromFrac_j2", jetCemfAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "chargedMult_j2", chMultAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "neutrMult_j2", neMultAK4->at(sortedJetIdx[1]));
       fillVariableWithValue( "photonMult_j2", phoMultAK4->at(sortedJetIdx[1]));
       //dijet
       fillVariableWithValue( "Dijet_MassAK4", MJJAK4) ; 
       fillVariableWithValue( "CosThetaStarAK4", TMath::TanH( (AK4jets[0].Eta()-AK4jets[1].Eta())/2 )); 
       fillVariableWithValue( "deltaETAjjAK4", DeltaEtaJJAK4 ) ;
       fillVariableWithValue( "deltaPHIjjAK4", DeltaPhiJJAK4 ) ;
     }

     if( widejets.size() >= 1 ){
         fillVariableWithValue( "pTWJ_j1", widejets[0].Pt() );
         fillVariableWithValue( "etaWJ_j1", widejets[0].Eta());
	 //no cuts on these variables, just to store in output
         fillVariableWithValue( "massWJ_j1", widejets[0].M());
         fillVariableWithValue( "phiWJ_j1", widejets[0].Phi());
       }

     if( widejets.size() >= 2 ){
         fillVariableWithValue( "pTWJ_j2", widejets[1].Pt() );
         fillVariableWithValue( "etaWJ_j2", widejets[1].Eta());
	 fillVariableWithValue( "deltaETAjj", DeltaEtaJJWide ) ;
         fillVariableWithValue( "mjj", MJJWide ) ;
         fillVariableWithValue( "mjj_shiftJEC", MJJWide_shift ) ;
	 //no cuts on these variables, just to store in output
         fillVariableWithValue( "massWJ_j2", widejets[1].M());
         fillVariableWithValue( "phiWJ_j2", widejets[1].Phi());	
	 //dijet
         fillVariableWithValue( "CosThetaStarWJ", TMath::TanH( (widejets[0].Eta()-widejets[1].Eta())/2 )); 
	 fillVariableWithValue( "deltaPHIjj", DeltaPhiJJWide ) ;
	 //fillVariableWithValue( "Dijet_MassAK8", mjjAK8 ) ;  
	 //fillVariableWithValue( "Dijet_MassC", mjjCA8 ) ;
	 // if(wdijet.M()<1){
	 //    std::cout << " INV MASS IS " << wdijet.M() << std::endl;
	 //    std::cout << " Delta Eta IS " << DeltaEtaJJWide << " n is  " << widejets.size() << std::endl;
	 //    std::cout << " INV MASS FROM NTUPLE AK8 " << mjjAK8 << std::endl;
	 //    //std::cout << " INV MASS FROM NTUPLE CA8 " << mjjCA8 << std::endl;
       }

     //no cuts on these variables, just to store in output
     if(!isData)
       fillVariableWithValue("trueVtx",PileupInteractions->at(idx_InTimeBX));
     else if(isData)
       fillVariableWithValue("trueVtx",999);     

     fillVariableWithValue("MET",met);
     //double METoverHTAK4=double(met/htAK4);
     double METoverHTAK4=double(met/HTak4);
     fillVariableWithValue("METoverHTAK4",METoverHTAK4);
     //fillVariableWithValue("HTAK4",htAK4);
     fillVariableWithValue("HTAK4",HTak4);
     fillVariableWithValue("ptHat",ptHat);

     // Trigger
     int NtriggerBits = triggerResult->size();
     if( NtriggerBits > 0 && isData)
       fillVariableWithValue("passHLT_PFHT800",triggerResult->at(0));// HLT_PFHT800_v*    
     if( NtriggerBits > 1 && isData)
       fillVariableWithValue("passHLT_PFHT650",triggerResult->at(1));// HLT_PFHT650_v*    
     if( NtriggerBits > 3 && isData)
       fillVariableWithValue("passHLT_PFHT475",triggerResult->at(3));// HLT_PFHT475_v*    
     if( NtriggerBits > 8 && isData)
       fillVariableWithValue("passHLT_PFHT200",triggerResult->at(8));// HLT_PFHT200_v*   
     if( NtriggerBits > 9 && isData)
       fillVariableWithValue("passHLT_PFHT650MJJ950",triggerResult->at(9));// HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v*        
     if( NtriggerBits > 10 && isData)
       fillVariableWithValue("passHLT_PFHT650MJJ900",triggerResult->at(10));// HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v*        
     if( NtriggerBits > 11 && isData)
       fillVariableWithValue("passHLT_PFJET500",triggerResult->at(11));// HLT_PFJET500_v*    
     if( NtriggerBits > 12 && isData)
       fillVariableWithValue("passHLT_PFJET450",triggerResult->at(12));// HLT_PFJET450_v*    
     if( NtriggerBits > 16 && isData)
       fillVariableWithValue("passHLT_Mu45",triggerResult->at(16));// HLT_Mu45Eta2p1_v*    
     if( NtriggerBits > 17 && isData)
       fillVariableWithValue("passHLT_AK8DiPFJet280200TrimMass30Btag",triggerResult->at(17));// HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p45_v*    
     if( NtriggerBits > 18 && isData)
       fillVariableWithValue("passHLT_AK8PFHT600TriMass50Btag",triggerResult->at(18));// HLT_AK8PFHT600_TrimR0p1PT0p03Mass50_BTagCSV0p45_v*    
     if( NtriggerBits > 19 && isData)
       fillVariableWithValue("passHLT_AK8PFHT700TriMass50",triggerResult->at(19));// HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v*   
     if( NtriggerBits > 20 && isData)
       fillVariableWithValue("passHLT_AK8PFJet360TrimMass50",triggerResult->at(20));// HLT_AK8PFJet360_TrimMass30_v*   
     if( NtriggerBits > 21 && isData)
       fillVariableWithValue("passHLT_CaloJet500NoJetID",triggerResult->at(21));// HLT_CaloJet500_NoJetID_v*  
     if( NtriggerBits > 22 && isData)
       fillVariableWithValue("passHLT_DiPFJetAve300HFJEC",triggerResult->at(22));// HLT_DiPFJetAve300_HFJEC_v* 
     if( NtriggerBits > 23 && isData)
       fillVariableWithValue("passHLT_DiPFJetAve500",triggerResult->at(23));// HLT_DiPFJetAve500_v*
     if( NtriggerBits > 24 && isData)
       fillVariableWithValue("passHLT_PFHT400SixJet30Btag",triggerResult->at(24));// HLT_PFHT400_SixJet30_BTagCSV0p55_2PFBTagCSV0p72_v*
     if( NtriggerBits > 25 && isData)
       fillVariableWithValue("passHLT_PFHT450SixJet40Btag",triggerResult->at(25));// HLT_PFHT450_SixJet40_PFBTagCSV0p72_v*
     if( NtriggerBits > 26 && isData)
       fillVariableWithValue("passHLT_PFHT750FourJetPt50",triggerResult->at(26));// HLT_PFHT750_4JetPt50_v*
     if( NtriggerBits > 27 && isData)
       fillVariableWithValue("passHLT_QuadPFJetVBF",triggerResult->at(27));// HLT_QuadPFJet_VBF_v*


     // Evaluate cuts (but do not apply them)
     evaluateCuts();
     
     // optional call to fill a skim with the full content of the input roottuple
     //if( passedCut("nJetFinal") ) fillSkimTree();
     if( passedCut("PassJSON")
	 && passedCut("nVtx") 
	 && passedCut("IdTight_j1")
	 && passedCut("IdTight_j2")
	 && passedCut("nJet")
	 && passedCut("pTWJ_j1")
	 && passedCut("etaWJ_j1")
	 && passedCut("pTWJ_j2")
	 && passedCut("etaWJ_j2")
	 && getVariableValue("deltaETAjj") <  getPreCutValue1("DetaJJforTrig") ){

       h_mjj_HLTpass[0] -> Fill(MJJWide); 
       
       if(isData && triggerResult->size()>10) // only run on data
	 {
	   if(triggerResult->at(3)) h_mjj_HLTpass[1] -> Fill(MJJWide); //PFHT475
	   if(triggerResult->at(3) && triggerResult->at(0)) h_mjj_HLTpass[2] -> Fill(MJJWide); //PFHT800
	   if(triggerResult->at(3) && triggerResult->at(10)) h_mjj_HLTpass[3] -> Fill(MJJWide); //PFHT650MJJ900
	   if(triggerResult->at(3) && (triggerResult->at(0) || triggerResult->at(10))) h_mjj_HLTpass[4] -> Fill(MJJWide); //PFHT800 && PFHT650MJJ900
	   if(triggerResult->at(0)) h_mjj_HLTpass[5] -> Fill(MJJWide); //PFHT800 without PFHT475

	   if(triggerResult->size()>16) //not called in old ntuples used for 65 pb-1 publication (Francesco, 11/09/2015)
	     {
	       if(triggerResult->at(16)) h_mjj_HLTpass[6] -> Fill(MJJWide); //Mu45Eta2p1
	       if(triggerResult->at(16) && triggerResult->at(0)) h_mjj_HLTpass[7] -> Fill(MJJWide); //Mu45Eta2p1 AND PFHT800
	     }
	 }
       //std::cout << "triggerResult->at(3) = " << triggerResult->at(3) << "  triggerResult->at(0) = " << triggerResult->at(0) << "  triggerResult->at(5) = " << triggerResult->at(5) << std::endl;
     }

     // optional call to fill a skim with a subset of the variables defined in the cutFile (use flag SAVE)
     if( passedAllPreviousCuts("mjj") && passedCut("mjj") ) 
       {
	 fillReducedSkimTree();

	 // ===== Take a look at this =====
	 // //Example on how to investigate quickly the data
	 // if(getVariableValue("mjj")>4000)
	 //   {
	 //     //fast creation and filling of histograms
	 //     CreateAndFillUserTH1D("h_dphijj_mjjgt4000", 100, 0, 3.15, getVariableValue("deltaPHIjj"));
	 //     CreateAndFillUserTH1D("h_htak4_mjjgt4000", 1000, 0, 10000, getVariableValue("HTAK4"));
	 //     CreateAndFillUserTH1D("h_nvtx_mjjgt4000", 31, -0.5, 30.5, getVariableValue("nVtx"));
	 //   }

       }

     // ===== Example of mjj spectrum after HLT selection =====
     // if( passedAllPreviousCuts("mjj") )
     //   {
     // 	 if(getVariableValue("passHLT")>0)
     // 	   {
     // 	     //fast creation and filling of histograms
     // 	     CreateAndFillUserTH1D("h_mjj_passHLT", getHistoNBins("mjj"), getHistoMin("mjj"), getHistoMax("mjj"), getVariableValue("mjj"));
     // 	   }
     //   }

     // reject events that did not pass level 0 cuts
     //if( !passedCut("0") ) continue;
     // ......
     
     // reject events that did not pass level 1 cuts
     //if( !passedCut("1") ) continue;
     // ......

     // reject events that did not pass the full cut list
     //if( !passedCut("all") ) continue;
     // ......

     // if( widejets.size() >= 2) {
     //  h_nJetFinal->Fill(widejets.size());
     //  h_DijetMass->Fill(wdijet.M());
     //  h_pT1stJet->Fill(widejets[0].Pt());
     //  h_pT2ndJet->Fill(widejets[1].Pt());
     //  h_eta1stJet->Fill(widejets[0].Eta());
     //  h_eta2ndJet->Fill(widejets[1].Eta());
     // }
     ////////////////////// User's code ends here ///////////////////////

   } // End loop over events

   //////////write histos 
   for (int i=0; i<8; i++){
     h_mjj_HLTpass[i]->Write();
   }

   // h_nVtx->Write();
   // h_trueVtx->Write();
   // h_nJetFinal->Write();
   // h_pT1stJet->Write();
   // h_pT2ndJet->Write();
   // h_DijetMass->Write();
   // h_eta1stJet->Write();
   // h_eta2ndJet->Write();

   // //pT of both jets, to be built using the histograms produced automatically by baseClass
   // TH1F * h_pTJets = new TH1F ("h_pTJets","", getHistoNBins("pT1stJet"), getHistoMin("pT1stJet"), getHistoMax("pT1stJet"));
   // h_pTJets->Add( & getHisto_noCuts_or_skim("pT1stJet") ); // all histos can be retrieved, see other getHisto_xxxx methods in baseClass.h
   // h_pTJets->Add( & getHisto_noCuts_or_skim("pT2ndJet") );
   // //one could also do:  *h_pTJets = getHisto_noCuts_or_skim("pT1stJet") + getHisto_noCuts_or_skim("pT2ndJet");
   // h_pTJets->Write();
   // //one could also do:   const TH1F& h = getHisto_noCuts_or_skim// and use h

   std::cout << "analysisClass::Loop() ends" <<std::endl;   
   }
