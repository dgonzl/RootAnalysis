#include "MuonObj.h"
#include <iomanip>

ClassImp(MuonObj)

std::ostream & operator<< (std::ostream &out, const MuonObj &o)
{
  out<<(TrackObj)o <<" MuonObj: ";
  out <<" stat: "<<o.nMatchedStations;
  out <<" hits: "<<o.nTrackerHits<<"_"<<o.nDTHits<<"_"<<o.nCSCHits<<"_"<<o.nRPCHits;
  if (o.isTracker()) out << "_TRK";
  if (o.isOuter())   out << "_OUT";
  if (o.isGlobal())  out << "_GLB";
  out <<std::setw(6)<<std::setprecision(2)<<std::fixed;
  out <<" L1EtaPhi:("<<o.l1Eta<<","<<o.l1Phi<<")";
  out <<std::setprecision(2)<<" chi2:"<<o.chi2Norm;
  out <<" #AllMuons: "<<o.nAllMuons;
  if (o.isUnique) out<<"_UNIQUE";
  if (o.isMatchedHlt) out <<"_HLT";
  if (o.isMatchedIsoHlt) out <<"_ISOHLT";
  if (o.isTkIsolated) out <<"_TkIso";
  if (o.isPFIsolated) out <<"_PFIso";
  if (o.isTight) out <<"_Tight";
  else if (o.isMedium) out <<"_Medium";
  else if (o.isLoose) out <<"_Loose";
  return out;
}
