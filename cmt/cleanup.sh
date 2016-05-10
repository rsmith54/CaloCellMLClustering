# echo "cleanup CaloCellMLClustering CaloCellMLClustering-00-00-00 in /afs/cern.ch/user/r/rsmith/testarea/metRecR21"

if test "${CMTROOT}" = ""; then
  CMTROOT=/cvmfs/atlas.cern.ch/repo/sw/software/AthAnalysisBase/x86_64-slc6-gcc49-opt/2.4.6/CMT/v1r25p20140131; export CMTROOT
fi
. ${CMTROOT}/mgr/setup.sh
cmtCaloCellMLClusteringtempfile=`${CMTROOT}/${CMTBIN}/cmt.exe -quiet build temporary_name`
if test ! $? = 0 ; then cmtCaloCellMLClusteringtempfile=/tmp/cmt.$$; fi
${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=CaloCellMLClustering -version=CaloCellMLClustering-00-00-00 -path=/afs/cern.ch/user/r/rsmith/testarea/metRecR21  $* >${cmtCaloCellMLClusteringtempfile}
if test $? != 0 ; then
  echo >&2 "${CMTROOT}/${CMTBIN}/cmt.exe cleanup -sh -pack=CaloCellMLClustering -version=CaloCellMLClustering-00-00-00 -path=/afs/cern.ch/user/r/rsmith/testarea/metRecR21  $* >${cmtCaloCellMLClusteringtempfile}"
  cmtcleanupstatus=2
  /bin/rm -f ${cmtCaloCellMLClusteringtempfile}
  unset cmtCaloCellMLClusteringtempfile
  return $cmtcleanupstatus
fi
cmtcleanupstatus=0
. ${cmtCaloCellMLClusteringtempfile}
if test $? != 0 ; then
  cmtcleanupstatus=2
fi
/bin/rm -f ${cmtCaloCellMLClusteringtempfile}
unset cmtCaloCellMLClusteringtempfile
return $cmtcleanupstatus

