#ifndef CALOCELLMLCLUSTERING_CALOCELLMLCLUSTERINGALG_H
#define CALOCELLMLCLUSTERING_CALOCELLMLCLUSTERINGALG_H 1

#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"



class CaloCellMLClusteringAlg: public ::AthAnalysisAlgorithm { 
 public: 
  CaloCellMLClusteringAlg( const std::string& name, ISvcLocator* pSvcLocator );
  virtual ~CaloCellMLClusteringAlg(); 

  virtual StatusCode  initialize();
  virtual StatusCode  execute();
  virtual StatusCode  finalize();
  
  virtual StatusCode beginInputFile();

 private: 

}; 

#endif //> !CALOCELLMLCLUSTERING_CALOCELLMLCLUSTERINGALG_H
