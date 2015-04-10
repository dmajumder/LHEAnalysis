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

void readerExample(std::string& fname) {

  std::ifstream ifs1(fname.c_str());
  std::cout << " Opening file " << ifs1 << std::endl ; 
  LHEF::Reader reader1(ifs1);
  std::cout << reader1.headerBlock;
  std::cout << reader1.initComments;
  std::cout << "Beam A: " << reader1.heprup.EBMUP.first << " GeV, Beam B: "
    << reader1.heprup.EBMUP.second << " GeV." << std::endl;
  unsigned pos = fname.find("_unweighted_events.lhe");  
  std::string fnamecut = fname.substr (0, pos);
  std::stringstream fout ;
  fout << fnamecut << "_13TeV.root"  ; 
  TFile *rootoutput = new TFile((fout.str()).c_str(),"RECREATE"); 

  //fout.str(std::string());
  //fout.clear() ;
  //fout << fnamecut << ";p_{T} (Z) [GeV];" ;
  //TH1D* hnpart6_pt_H = new TH1D("hnpart6_pt_H" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  //fout.str(std::string());
  //fout.clear() ;
  //fout << fnamecut << ";p_{T} (#bar{b}) [GeV];" ;
  //TH1D* hnpart6_pt_Hbar = new TH1D("hnpart6_pt_Hbar" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  //fout.str(std::string());
  //fout.clear() ;
  //fout << fnamecut << ";y (Z);" ;
  //TH1D* hnpart6_y_H  = new TH1D("hnpart6_y_H"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  //fout.str(std::string());
  //fout.clear() ;
  //fout << fnamecut << ";y (#bar{b});" ;
  //TH1D* hnpart6_y_Hbar  = new TH1D("hnpart6_y_Hbar"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  //fout.str(std::string());
  //fout.clear() ;
  //fout << fnamecut << ";p_{T} (#bar{b}) [GeV];" ;
  //TH1D* hnpart9_pt_Hbar = new TH1D("hnpart9_pt_Hbar" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  //fout.str(std::string());
  //fout.clear() ;
  //fout << fnamecut << ";y (#bar{b});" ;
  //TH1D* hnpart9_y_Hbar  = new TH1D("hnpart9_y_Hbar"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (b) [GeV];" ;
  TH1D* hnpart6_pt_b = new TH1D("hnpart6_pt_b" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (#bar{b}) [GeV];" ;
  TH1D* hnpart6_pt_bbar = new TH1D("hnpart6_pt_bbar" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (b);" ;
  TH1D* hnpart6_y_b  = new TH1D("hnpart6_y_b"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (#bar{b});" ;
  TH1D* hnpart6_y_bbar  = new TH1D("hnpart6_y_bbar"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (T) [GeV];" ;
  TH1D* hnpart6_pt_tp = new TH1D("hnpart6_pt_tp" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (#bar{T}) [GeV];" ;
  TH1D* hnpart6_pt_tpbar = new TH1D("hnpart6_pt_tpbar" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (T);" ;
  TH1D* hnpart6_y_tp  = new TH1D("hnpart6_y_tp"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (#bar{T});" ;
  TH1D* hnpart6_y_tpbar  = new TH1D("hnpart6_y_tpbar"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  /////////////////////////////////////////////////////////

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (T) [GeV];" ;
  TH1D* hnpart9_pt_tp = new TH1D("hnpart9_pt_tp" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (#bar{T}) [GeV];" ;
  TH1D* hnpart9_pt_tpbar = new TH1D("hnpart9_pt_tpbar" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (T);" ;
  TH1D* hnpart9_y_tp  = new TH1D("hnpart9_y_tp"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (#bar{T});" ;
  TH1D* hnpart9_y_tpbar  = new TH1D("hnpart9_y_tpbar"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (t) [GeV];" ;
  TH1D* hnpart9_pt_t = new TH1D("hnpart9_pt_t" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (#bar{t}) [GeV];" ;
  TH1D* hnpart9_pt_tbar = new TH1D("hnpart9_pt_tbar" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (t);" ;
  TH1D* hnpart9_y_t  = new TH1D("hnpart9_y_t"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (#bar{t});" ;
  TH1D* hnpart9_y_tbar  = new TH1D("hnpart9_y_tbar"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (W) [GeV];" ;
  TH1D* hnpart9_pt_W = new TH1D("hnpart9_pt_W" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (W);" ;
  TH1D* hnpart9_y_W  = new TH1D("hnpart9_y_W"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (H) [GeV];" ;
  TH1D* hnpart9_pt_H = new TH1D("hnpart9_pt_H" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (H);" ;
  TH1D* hnpart9_y_H  = new TH1D("hnpart9_y_H"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (b) [GeV];" ;
  TH1D* hnpart9_pt_b = new TH1D("hnpart9_pt_b" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (#bar{b}) [GeV];" ;
  TH1D* hnpart9_pt_bbar = new TH1D("hnpart9_pt_bbar" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (b);" ;
  TH1D* hnpart9_y_b  = new TH1D("hnpart9_y_b"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (#bar{b});" ;
  TH1D* hnpart9_y_bbar  = new TH1D("hnpart9_y_bbar"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (q) [GeV];" ;
  TH1D* hnpart9_pt_q = new TH1D("hnpart9_pt_q" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (q);" ;
  TH1D* hnpart9_y_q  = new TH1D("hnpart9_y_q"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (b from t) [GeV];" ;
  TH1D* hnpart9_pt_bfromt = new TH1D("hnpart9_pt_bfromt" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (b from t);" ;
  TH1D* hnpart9_y_bfromt  = new TH1D("hnpart9_y_bfromt"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";p_{T} (b from t) [GeV];" ;
  TH1D* hnpart9_pt_lfromw = new TH1D("hnpart9_pt_lfromw" ,(fout.str()).c_str() ,200 ,0.  ,1000) ; 

  fout.str(std::string());
  fout.clear() ;
  fout << fnamecut << ";y (b from t);" ;
  TH1D* hnpart9_y_lfromw  = new TH1D("hnpart9_y_lfromw"  ,(fout.str()).c_str() ,100 ,-5 , 5) ; 

  fout.str(std::string());
  fout.clear() ;

  while ( reader1.readEvent() ) {
    int npart(0) ; 
    bool hardpart(false) ; 
    npart = reader1.hepeup.NUP ; 
    for(int ii=0;ii< reader1.hepeup.NUP;ii++){
      if ( ( abs(reader1.hepeup.IDUP[ii]) < 6 || abs(reader1.hepeup.IDUP[ii]) == 21 ) &&
          ( reader1.hepeup.MOTHUP[ii].first == 1 && reader1.hepeup.MOTHUP[ii].second == 2 ) && 
          sqrt( pow2(reader1.hepeup.PUP[ii][0]) + pow2(reader1.hepeup.PUP[ii][1]) ) > 0 ) hardpart = true ;
    }
    if ( !hardpart ) continue ; 
    TLorentzVector p4_tp, p4_t, p4_H, p4_b, p4_q, p4_W, p4_bfromt, p4_lfromw ; 
    for(int ii=0;ii< reader1.hepeup.NUP;ii++){
      if ( reader1.hepeup.IDUP[ii] == 8000001 ) {
        p4_tp.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 6 ) hnpart6_pt_tp->Fill(p4_tp.Pt()) ; 
        if ( npart == 6 ) hnpart6_y_tp -> Fill(p4_tp.Rapidity()) ; 
        if ( npart == 11 ) hnpart9_pt_tp->Fill(p4_tp.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_tp -> Fill(p4_tp.Rapidity()) ; 
      }
      else if ( reader1.hepeup.IDUP[ii] == -8000001 ) {
        p4_tp.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 6 ) hnpart6_pt_tpbar->Fill(p4_tp.Pt()) ; 
        if ( npart == 6 ) hnpart6_y_tpbar -> Fill(p4_tp.Rapidity()) ; 
        if ( npart == 11 ) hnpart9_pt_tpbar->Fill(p4_tp.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_tpbar -> Fill(p4_tp.Rapidity()) ; 
      }
      else if ( reader1.hepeup.IDUP[ii] == 6 && reader1.hepeup.MOTHUP[ii].first ==  3 && reader1.hepeup.MOTHUP[ii].second ==  3 ) {
        p4_t.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 11 ) hnpart9_pt_t->Fill(p4_t.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_t -> Fill(p4_t.Rapidity()) ; 
      }
      else if ( reader1.hepeup.IDUP[ii] == -6 && reader1.hepeup.MOTHUP[ii].first == 3 && reader1.hepeup.MOTHUP[ii].second ==  3 ) {
        p4_t.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 11 ) hnpart9_pt_tbar->Fill(p4_t.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_tbar -> Fill(p4_t.Rapidity()) ; 
      }
      else if ( abs(reader1.hepeup.IDUP[ii]) == 25 && reader1.hepeup.MOTHUP[ii].first ==  3 && reader1.hepeup.MOTHUP[ii].second ==  3 ) {
        p4_H.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 11 ) hnpart9_pt_H->Fill(p4_H.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_H -> Fill(p4_H.Rapidity()) ; 
      }
      else if ( reader1.hepeup.IDUP[ii] == 5 && reader1.hepeup.MOTHUP[ii].first ==  1 && reader1.hepeup.MOTHUP[ii].second ==  2 ) {
        p4_b.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 6 ) hnpart6_pt_b->Fill(p4_b.Pt()) ; 
        if ( npart == 6 ) hnpart6_y_b -> Fill(p4_b.Rapidity()) ; 
        if ( npart == 11 ) hnpart9_pt_b->Fill(p4_b.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_b -> Fill(p4_b.Rapidity()) ; 
      }
      else if ( reader1.hepeup.IDUP[ii] == -5 && reader1.hepeup.MOTHUP[ii].first == 1 && reader1.hepeup.MOTHUP[ii].second ==  2 ) {
        p4_b.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 6 ) hnpart6_pt_bbar->Fill(p4_b.Pt()) ; 
        if ( npart == 6 ) hnpart6_y_bbar -> Fill(p4_b.Rapidity()) ; 
        if ( npart == 11 ) hnpart9_pt_bbar->Fill(p4_b.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_bbar -> Fill(p4_b.Rapidity()) ; 
      }
      else if ( abs(reader1.hepeup.IDUP[ii]) < 5 && reader1.hepeup.MOTHUP[ii].first ==  1 && reader1.hepeup.MOTHUP[ii].second ==  2 ) {
        p4_q.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 11 ) hnpart9_pt_q->Fill(p4_q.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_q -> Fill(p4_q.Rapidity()) ; 
      }
      else if ( abs(reader1.hepeup.IDUP[ii]) == 24 && reader1.hepeup.MOTHUP[ii].first ==  4 && reader1.hepeup.MOTHUP[ii].second ==  4 ) {
        p4_W.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 11 ) hnpart9_pt_W->Fill(p4_W.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_W -> Fill(p4_W.Rapidity()) ; 
      }
      else if ( abs(reader1.hepeup.IDUP[ii]) == 5 && reader1.hepeup.MOTHUP[ii].first ==  4 && reader1.hepeup.MOTHUP[ii].second ==  4 ) {
        p4_bfromt.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 11 ) hnpart9_pt_bfromt->Fill(p4_bfromt.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_bfromt -> Fill(p4_bfromt.Rapidity()) ; 
      }
      else if (  ( abs(reader1.hepeup.IDUP[ii]) == 11 || abs(reader1.hepeup.IDUP[ii]) == 13 || abs(reader1.hepeup.IDUP[ii]) == 15 )  
          && reader1.hepeup.MOTHUP[ii].first ==  5 && reader1.hepeup.MOTHUP[ii].second ==  5 ) {
        p4_lfromw.SetPxPyPzE(reader1.hepeup.PUP[ii][0], reader1.hepeup.PUP[ii][1], reader1.hepeup.PUP[ii][2], reader1.hepeup.PUP[ii][3]) ; 
        if ( npart == 11 ) hnpart9_pt_lfromw->Fill(p4_lfromw.Pt()) ; 
        if ( npart == 11 ) hnpart9_y_lfromw -> Fill(p4_lfromw.Rapidity()) ; 
      }
    }

  }

  double npart6_pt_bNorm    = hnpart6_pt_b->Integral() ; 
  double npart6_pt_bbarNorm = hnpart6_pt_bbar->Integral() ; 
  double npart9_pt_bNorm    = hnpart9_pt_b->Integral() ; 
  double npart9_pt_bbarNorm = hnpart9_pt_bbar->Integral() ; 

  double npart6_y_bNorm    = hnpart6_y_b->Integral() ; 
  double npart6_y_bbarNorm = hnpart6_y_bbar->Integral() ; 
  double npart9_y_bNorm    = hnpart9_y_b->Integral() ; 
  double npart9_y_bbarNorm = hnpart9_y_bbar->Integral() ; 

  hnpart6_pt_b -> Scale(1./npart6_pt_bNorm) ; 
  hnpart6_pt_bbar -> Scale(1./npart6_pt_bbarNorm) ; 
  hnpart9_pt_b -> Scale(1./npart9_pt_bNorm) ; 
  hnpart9_pt_bbar -> Scale(1./npart9_pt_bbarNorm) ; 

  hnpart6_y_b -> Scale(1./npart6_y_bNorm) ; 
  hnpart6_y_bbar -> Scale(1./npart6_y_bbarNorm) ; 
  hnpart9_y_b -> Scale(1./npart9_y_bNorm) ; 
  hnpart9_y_bbar -> Scale(1./npart9_y_bbarNorm) ; 

  double npart6_pt_tpNorm    = hnpart6_pt_tp->Integral() ; 
  double npart6_pt_tpbarNorm = hnpart6_pt_tpbar->Integral() ; 
  double npart9_pt_tpNorm    = hnpart9_pt_tp->Integral() ; 
  double npart9_pt_tpbarNorm = hnpart9_pt_tpbar->Integral() ; 

  double npart6_y_tpNorm    = hnpart6_y_tp->Integral() ; 
  double npart6_y_tpbarNorm = hnpart6_y_tpbar->Integral() ; 
  double npart9_y_tpNorm    = hnpart9_y_tp->Integral() ; 
  double npart9_y_tpbarNorm = hnpart9_y_tpbar->Integral() ; 

  hnpart6_pt_tp -> Scale(1./npart6_pt_tpNorm) ; 
  hnpart6_pt_tpbar -> Scale(1./npart6_pt_tpbarNorm) ; 
  hnpart9_pt_tp -> Scale(1./npart9_pt_tpNorm) ; 
  hnpart9_pt_tpbar -> Scale(1./npart9_pt_tpbarNorm) ; 

  hnpart6_y_tp -> Scale(1./npart6_y_tpNorm) ; 
  hnpart6_y_tpbar -> Scale(1./npart6_y_tpbarNorm) ; 
  hnpart9_y_tp -> Scale(1./npart9_y_tpNorm) ; 
  hnpart9_y_tpbar -> Scale(1./npart9_y_tpbarNorm) ; 

  rootoutput->Write();
  rootoutput->Close();

  return ; 

}

int main(int argc, char *argv[]) { 

  if ( argc != 2 ) // argc should be 2 for correct execution
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
        readerExample(fname); 
      } 
    }
  }

  return 0;

}

