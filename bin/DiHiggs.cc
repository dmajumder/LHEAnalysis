#include <cmath>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>

#include "LHEF.h"

#include <TFile.h>
#include <TH1D.h>
#include <TLorentzVector.h>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/replace.hpp>

#define pow2(a) pow(a,2.)

using namespace std;

void readerExample(std::string fname, int rescode, int maxEvents) {

  std::ifstream ifs1(fname.c_str());
  std::cout << " Opening file " << ifs1 << std::endl ; 
  LHEF::Reader reader1(ifs1);
  std::cout << reader1.headerBlock;
  std::cout << reader1.initComments;
  std::cout << "Beam A: " << reader1.heprup.EBMUP.first << " GeV, Beam B: "
    << reader1.heprup.EBMUP.second << " GeV." << std::endl;
  std::vector<string> fnamecut;
  boost::split(fnamecut, fname, boost::is_any_of("/"));
  std::stringstream fout ;
  boost::replace_all(fnamecut.at(fnamecut.size()-1), "_unweighted_events.lhe", ".root");
  fout << fnamecut.at(fnamecut.size()-1) ; 
  TFile *rootoutput = new TFile((fout.str()).c_str(),"RECREATE"); 

  boost::replace_all(fnamecut.at(fnamecut.size()-1), ".root", "");
  fout.str(std::string());
  fout.clear() ;
  fout <<  fnamecut.at(fnamecut.size()-1) << ";M_{res.} [GeV];" ;
  TH1D* h_mass_res = new TH1D("h_mass_res" ,(fout.str()).c_str() ,500 ,0.  ,5000) ; 
  fout.str(std::string());
  fout.clear() ;

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut.at(fnamecut.size()-1) << ";inv. M(HH) [GeV];" ;
  TH1D* h_mass_hhinv = new TH1D("h_mass_hhinv" ,(fout.str()).c_str() ,250 ,0.  ,5000) ; 
  fout.str(std::string());
  fout.clear() ;

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut.at(fnamecut.size()-1) << ";inv. M(qH) [GeV];" ;
  TH1D* h_mass_qhinv = new TH1D("h_mass_qhinv" ,(fout.str()).c_str() ,200 ,500.  ,2500) ; 
  fout.str(std::string());
  fout.clear() ;

  typedef std::vector<TLorentzVector> Vp4 ; 
  typedef std::vector<TLorentzVector>::const_iterator it_Vp4 ; 

  int nevents(0) ; 
  while ( reader1.readEvent() && nevents < maxEvents) {
    TLorentzVector p4_res;
    Vp4 vp4_H, vp4_qfromT, vp4_HfromT ; 

    for(int ii=0;ii < reader1.hepeup.NUP;ii++){
      //cout << " ii =" << ii << " pid = " << reader1.hepeup.IDUP[ii] 
      //  << " moth1 = " << reader1.hepeup.MOTHUP[ii].first-1 << " moth1 pid = " << reader1.hepeup.IDUP[reader1.hepeup.MOTHUP[ii].first-1] 
      //  << " moth2 = " << reader1.hepeup.MOTHUP[ii].second-1 << " moth2 pid = " << reader1.hepeup.IDUP[reader1.hepeup.MOTHUP[ii].second-1]
      //  << endl; 
      if ( abs(reader1.hepeup.IDUP[ii]) == rescode ) {
        p4_res.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
      }
      else if ( abs(reader1.hepeup.IDUP[ii]) == 25 ) {
        TLorentzVector p4_H ; 
        p4_H.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        vp4_H.push_back(p4_H) ; 
        if ( (reader1.hepeup.IDUP[reader1.hepeup.MOTHUP[ii].first-1]) == 8000001 || (reader1.hepeup.IDUP[reader1.hepeup.MOTHUP[ii].second-1]) == 8000001) {
          TLorentzVector p4_HfromT ; 
          p4_HfromT.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
          vp4_HfromT.push_back(p4_HfromT) ; 
        }
      }
      else if ( abs(reader1.hepeup.IDUP[ii]) < 5 ) { 
        if ( (reader1.hepeup.IDUP[reader1.hepeup.MOTHUP[ii].first-1]) == 8000001 || (reader1.hepeup.IDUP[reader1.hepeup.MOTHUP[ii].second-1]) == 8000001) {
          TLorentzVector p4_qfromT ; 
          p4_qfromT.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
          vp4_qfromT.push_back(p4_qfromT) ; 
        }
      }
    }
    
    h_mass_res -> Fill(p4_res.Mag()) ; 

    for ( it_Vp4 it = vp4_H.begin(); it != vp4_H.end(); ++it) { 
      for ( it_Vp4 jt = it+1; jt != vp4_H.end(); ++jt) { 
        h_mass_hhinv -> Fill ( (*it + *jt).Mag() ) ; 
      }
    }
    
    for ( it_Vp4 it = vp4_HfromT.begin(); it != vp4_HfromT.end(); ++it) { 
      for ( it_Vp4 jt = vp4_qfromT.begin(); jt != vp4_qfromT.end(); ++jt) { 
        h_mass_qhinv -> Fill ( (*it + *jt).Mag() ) ; 
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
    std::cout << "usage: " << argv[0] << " <filename>" << " maxEvents\n" ; 
  else {
    ifstream infile ( argv[1] );
    if ( !infile.is_open() ) {
      std::cout<<"Could not open file\n"; 
    }
    else {
      std::string input, fname, rescode;
      while ( std::getline ( infile, input ) && input[0] != '#' ) { 
        std::vector<std::string> args;
        boost::split(args, input, boost::is_any_of("\t "));
        fname = args[0]; 
        rescode = args[1] ;  
        cout << ">>>>>>>>>>>> Opening file " << fname << " with res pdgid " << rescode << endl ; 
        readerExample(fname, atoi(rescode.c_str()), atoi(argv[2])); 
      } 
    }
  }

  return 0;

}

