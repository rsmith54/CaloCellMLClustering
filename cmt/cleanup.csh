# echo "cleanup CaloCellMLClustering CaloCellMLClustering-00-00-00 in /afs/cern.ch/user/r/rsmith/testarea/metRecR21"

if ( $?CMTROOT == 0 ) then
  setenv CMTROOT /cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.6/CMT/v1r25p20140131
endif
source ${CMTROOT}/mgr/setup.csh
set cmtCaloCellMLClusteringtempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if $status != 0 then
  set cmtCaloCellMLClusteringtempfile=/tmp/cmt.$$
endif
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=CaloCellMLClustering -version=CaloCellMLClustering-00-00-00 -path=/afs/cern.ch/user/r/rsmith/testarea/metRecR21  $* >${cmtCaloCellMLClusteringtempfile}
if ( $status != 0 ) then
  echo "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -csh -pack=CaloCellMLClustering -version=CaloCellMLClustering-00-00-00 -path=/afs/cern.ch/user/r/rsmith/testarea/metRecR21  $* >${cmtCaloCellMLClusteringtempfile}"
  set cmtcleanupstatus=2
  /bin/rm -f ${cmtCaloCellMLClusteringtempfile}
  unset cmtCaloCellMLClusteringtempfile
  exit $cmtcleanupstatus
endif
set cmtcleanupstatus=0
source ${cmtCaloCellMLClusteringtempfile}
if ( $status != 0 ) then
  set cmtcleanupstatus=2
endif
/bin/rm -f ${cmtCaloCellMLClusteringtempfile}
unset cmtCaloCellMLClusteringtempfile
exit $cmtcleanupstatus

