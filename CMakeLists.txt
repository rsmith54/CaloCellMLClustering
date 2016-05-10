# $Id: CMakeLists.txt 730170 2016-03-15 16:32:19Z krasznaa $
################################################################################
# Package: CaloCellMLClustering
################################################################################

# Declare the package name:
atlas_subdir( CaloCellMLClustering )

# Declare the package's dependencies:
atlas_depends_on_subdirs(
   PUBLIC
   # Calorimeter/CaloConditions
   # Calorimeter/CaloDetDescr
   # Calorimeter/CaloGeoHelpers
   # Calorimeter/CaloIdentifier
   # Control/AthAllocators
   # Control/AthContainers
   # Control/AthLinks
   # Control/CLIDSvc
   # Control/CxxUtils
   # Control/DataModel
   # Control/Navigation
   # DetectorDescription/GeoPrimitives
   # DetectorDescription/Identifier
   # Event/EventKernel
   # Event/FourMom
   # Event/NavFourMom
   PRIVATE
#   AtlasTest/TestTools
#   Control/AthenaKernel
#   Control/SGTools
#   Control/StoreGate
#   DetectorDescription/IdDictParser
#   GaudiKernel
    )

# External dependencies:
find_package( Boost )
find_package( CLHEP )

# Component(s) in the package:
atlas_add_library( CaloCellMLClustering CaloCellMLClustering/*.h CaloCellMLClustering/*.icc src/*.cxx
   PUBLIC_HEADERS CaloCellMLClustering
   PRIVATE_INCLUDE_DIRS ${Boost_INCLUDE_DIRS} ${CLHEP_INCLUDE_DIRS}
   LINK_LIBRARIES CaloConditions CaloGeoHelpers CaloIdentifier AthAllocators
   AthContainers AthLinks CxxUtils DataModel Navigation GeoPrimitives
   Identifier EventKernel FourMom NavFourMom CaloDetDescrLib
   PRIVATE_LINK_LIBRARIES ${Boost_LIBRARIES} ${CLHEP_LIBRARIES} AthenaKernel
   SGTools )

atlas_add_dictionary( CaloCellMLClusteringDict
   CaloCellMLClustering/CaloCellMLClusteringDict.h CaloCellMLClustering/selection.xml
   LINK_LIBRARIES CaloCellMLClustering
   NAVIGABLES CaloCellContainer CaloClusterContainer
   DATA_LINKS CaloTowerContainer )

# # Test(s) in the package:
# atlas_add_test( CaloCellContainer_test
#    SOURCES test/CaloCellContainer_test.cxx
#    LINK_LIBRARIES CaloDetDescrLib CaloIdentifier TestTools IdDictParser
#    GaudiKernel CaloCellMLClustering
#    EXTRA_PATTERNS "${_patterns}"
#    ENVIRONMENT "JOBOPTSEARCHPATH=${CMAKE_CURRENT_SOURCE_DIR}/share" )
