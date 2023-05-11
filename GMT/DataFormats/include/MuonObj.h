#ifndef MuonObj_H
#define MuonObj_H
#include "TrackObj.h"
#include <ostream>

class MuonObj : public TrackObj {
public:
    MuonObj(float pt=0., float eta=0., float phi=0., int charge=0) 
      : TrackObj(pt,eta,phi,charge), 
        nRPCHits(0), nDTHits(0), nCSCHits(0), nTrackerHits(0), nMatchedStations(0),
        isUnique(true), isLoose(false), isMedium(false), isTight(false), 
        isMatchedHlt(false), isMatchedIsoHlt(false),
        isTkIsolated(false), isPFIsolated(false),
        chi2Norm(0.), l1Eta(9999.), l1Phi(9999.),
        nAllMuons(0), theMuonBits(0) {}
  virtual ~MuonObj(){}
  void setBits(bool isGlobal, bool isTracker, bool isOuter, bool isCalo, bool isMatched) {
     if (isGlobal)  theMuonBits = 1 << 4;
     if (isTracker) theMuonBits |= 1<<3;
     if (isOuter)   theMuonBits |= 1<<2;
     if (isCalo)    theMuonBits |= 1<<1;
     if (isMatched) theMuonBits |= 1; 
  }
  bool isGlobal()  const { return  (theMuonBits>>4)&1 ;}  
  bool isTracker() const { return  (theMuonBits>>3)&1 ;}  
  bool isOuter()   const { return  (theMuonBits>>2)&1 ;}  
  bool isCalo()    const { return  (theMuonBits>>1)&1 ;}  
  bool isMatched() const { return   theMuonBits&1 ;}  

  bool isValid() const {return  (pt()>0.001 && charge()!=0); }; 
public:
  unsigned int nRPCHits, nDTHits, nCSCHits, nTrackerHits, nMatchedStations;
  bool         isUnique, isLoose, isMedium, isTight;
  bool         isMatchedHlt, isMatchedIsoHlt;
  bool         isTkIsolated, isPFIsolated;
  float        chi2Norm;
  float l1Eta, l1Phi;
  unsigned int nAllMuons;
private:  
  unsigned int theMuonBits; 
public:
ClassDef(MuonObj,5)
};


std::ostream & operator<< (std::ostream &out, const MuonObj &o);

#endif
