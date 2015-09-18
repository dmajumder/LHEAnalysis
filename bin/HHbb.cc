#include <cmath>
#include <iostream>
#include <cstring>
#include <sstream>

#include "LHEF.h"

#include <TFile.h>
#include <TH1D.h>
#include <TLorentzVector.h>

#define pow2(a) pow(a,2.)

using namespace std;

void readerExample(std::string fname, int maxEvents) {

  std::ifstream ifs1(fname.c_str());
  std::cout << " Opening file " << ifs1 << std::endl ; 
  LHEF::Reader reader1(ifs1);
  std::cout << reader1.headerBlock;
  std::cout << reader1.initComments;
  std::cout << "Beam A: " << reader1.heprup.EBMUP.first << " GeV, Beam B: "
    << reader1.heprup.EBMUP.second << " GeV." << std::endl;
  int pos0 = fname.find("/LHE/");  
  std::string fnamecut = fname.substr (pos0+5, -1);
  int pos1 = fnamecut.find(".lhe");  
  if (pos1 != -1) fnamecut.erase (pos1,4);
  int pos2 = fnamecut.find("_unweighted_events");  
  if (pos2 != -1) fnamecut.erase (pos2,18);
  std::stringstream fout ;
  fout << fnamecut << "_13TeV.root"  ; 
  TFile *rootoutput = new TFile((fout.str()).c_str(),"RECREATE"); 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";M_{res} [GeV];" ;
  TH1D* h_mass_res = new TH1D("h_mass_res" ,(fout.str()).c_str() ,1000 ,0.  ,5000) ; 
  fout.str(std::string());
  fout.clear() ;

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";inv. M(HH) [GeV];" ;
  TH1D* h_mass_hhinv = new TH1D("h_mass_hhinv" ,(fout.str()).c_str() ,200 ,0.  ,5000) ; 
  fout.str(std::string());
  fout.clear() ;

  typedef std::vector<TLorentzVector> Vp4 ; 
  typedef std::vector<TLorentzVector>::const_iterator it_Vp4 ; 

  int nevents(0) ; 
  while ( reader1.readEvent() && nevents < maxEvents) {
    TLorentzVector p4_res ;
    Vp4 vp4_H ; 
    for(int ii=0;ii< reader1.hepeup.NUP;ii++){
      if ( abs(reader1.hepeup.IDUP[ii]) == 35 || abs(reader1.hepeup.IDUP[ii]) == 39 ) {
        p4_res.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
      }
      else if ( abs(reader1.hepeup.IDUP[ii]) == 25 && reader1.hepeup.MOTHUP[ii].first ==  3 && reader1.hepeup.MOTHUP[ii].second ==  3 ) {
        TLorentzVector p4_H ; 
        p4_H.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        vp4_H.push_back(p4_H) ; 
      }
    }
    
    h_mass_res -> Fill(p4_res.Mag()) ; 
    for ( it_Vp4 it = vp4_H.begin(); it != vp4_H.end(); ++it) { 
      for ( it_Vp4 jt = it+1; jt != vp4_H.end(); ++jt) { 
        h_mass_hhinv -> Fill ( (*it + *jt).Mag() ) ; 
      }
    }
   
    ++nevents; 
    if (nevents%100 == 0) std::cout << " Processing event " << nevents << " of " << maxEvents << std::endl ; 

  }

  rootoutput->Write();
  rootoutput->Close();

  return ; 

}

int main(int argc, char *argv[]) { 

  if ( argc != 3 ) // argc should be 2 for correct execution
    // We print argv[0] assuming it is the program name
    std::cout << "usage: " << argv[0] << " <filename>\n" ; 
  else {
    ifstream infile ( argv[1] );
    if ( !infile.is_open() ) {
      std::cout<<"Could not open file\n"; 
    }
    else {
      std::string fname;
      while ( std::getline ( infile, fname ) && fname[0] != '#' ) { 
        readerExample(fname, atoi(argv[2])); 
      } 
    }
  }

  return 0;

}

