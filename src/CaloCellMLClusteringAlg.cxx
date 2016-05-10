// CaloCellMLClustering includes
#include "CaloCellMLClusteringAlg.h"

//#include "xAODEventInfo/EventInfo.h"

#include "CaloEvent/CaloCellContainer.h"
#include "CaloEvent/CaloClusterCellLink.h"

//#include "xAODCaloEvent/CaloClusterContainer.h"

#include "GaudiKernel/MsgStream.h"
//#include "xAODJet/JetContainer.h"
//#include "xAODBase/IParticle.h"
//#include "JetUtils/JetCellAccessor.h"

//uncomment the line below to use the HistSvc for outputting trees and histograms
//#include "GaudiKernel/ITHistSvc.h"
//#include "TTree.h"
//#include "TH1D.h"



CaloCellMLClusteringAlg::CaloCellMLClusteringAlg( const std::string& name, ISvcLocator* pSvcLocator ) : AthAnalysisAlgorithm( name, pSvcLocator ){

  //declareProperty( "Property", m_nProperty ); //example property declaration

}


CaloCellMLClusteringAlg::~CaloCellMLClusteringAlg() {}


StatusCode CaloCellMLClusteringAlg::initialize() {
  ATH_MSG_INFO ("Initializing " << name() << "...");
  //
  //This is called once, before the start of the event loop
  //Retrieves of tools you have configured in the joboptions go here
  //

  //HERE IS AN EXAMPLE
  //We will create a histogram and a ttree and register them to the histsvc
  //Remember to uncomment the configuration of the histsvc stream in the joboptions
  //
  //ServiceHandle<ITHistSvc> histSvc("THistSvc",name());
  //TH1D* myHist = new TH1D("myHist","myHist",10,0,10);
  //CHECK( histSvc->regHist("/MYSTREAM/myHist", myHist) ); //registers histogram to output stream (like SetDirectory in EventLoop)
  //TTree* myTree = new TTree("myTree","myTree");
  //CHECK( histSvc->regTree("/MYSTREAM/SubDirectory/myTree", myTree) ); //registers tree to output stream (like SetDirectory in EventLoop) inside a sub-directory


  return StatusCode::SUCCESS;
}

StatusCode CaloCellMLClusteringAlg::finalize() {
  ATH_MSG_INFO ("Finalizing " << name() << "...");
  //
  //Things that happen once at the end of the event loop go here
  //


  return StatusCode::SUCCESS;
}

StatusCode CaloCellMLClusteringAlg::execute() {
  ATH_MSG_DEBUG ("Executing " << name() << "...");
  setFilterPassed(false); //optional: start with algorithm not passed

  const CaloCellContainer* cellContainer = nullptr;
  CHECK( evtStore()->retrieve( cellContainer, "AllCalo") );

  for(auto cell : cellContainer) {
    ATH_MSG_DEBUG("cell pt : " << cell->pt() );
  }

  setFilterPassed(true); //if got here, assume that means algorithm passed
  return StatusCode::SUCCESS;
}

StatusCode CaloCellMLClusteringAlg::beginInputFile() {
  //
  //This method is called at the start of each input file, even if
  //the input file contains no events. Accumulate metadata information here
  //

  //example of retrieval of CutBookkeepers: (remember you will need to include the necessary header files and use statements in requirements file)
  // const xAOD::CutBookkeeperContainer* bks = 0;
  // CHECK( inputMetaStore()->retrieve(bks, "CutBookkeepers") );

  //example of IOVMetaData retrieval (see https://twiki.cern.ch/twiki/bin/viewauth/AtlasProtected/AthAnalysisBase#How_to_access_file_metadata_in_C)
  //float beamEnergy(0); CHECK( retrieveMetadata("/TagInfo","beam_energy",beamEnergy) );
  //std::vector<float> bunchPattern; CHECK( retrieveMetadata("/Digitiation/Parameters","BeamIntensityPattern",bunchPattern) );



  return StatusCode::SUCCESS;
}


