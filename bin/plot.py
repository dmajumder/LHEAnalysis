#!/usr/bin/env python

import os, sys, ROOT

def plot (str): 
  f = ROOT.TFile.Open("tH_b_LH_narrow_M1800_13TeV.root", "READ")
  f.cd()
  
  pt_tp = f.Get("hnpart9_"+str)

  ROOT.gROOT.SetStyle('Plain')
  ROOT.gStyle.SetOptTitle(0) 
  
  c0 = ROOT.TCanvas(str, "", 800,600)
  c0.cd()
  pt_tp.Draw()
  
  c0.SaveAs(c0.GetName()+".pdf")
  c0.SaveAs(c0.GetName()+".C")

  f.Close()

  return

plot("pt_tp")
plot("y_tp")
plot("pt_t")
plot("y_t")
plot("pt_H")
plot("y_H")
plot("pt_b")
plot("y_b")
plot("pt_bbar")
plot("y_bbar")
plot("pt_q")
plot("y_q")
