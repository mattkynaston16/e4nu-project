/**
 * A  practice script to analyse Anjali's
 * histograms.
 * Matt Kynaston October 7th 2020
*/
#include <string>
using namespace std;

/* Run this from the root command line  with .x anjaliPlots.C */
void anjaliPlotsnew() // This name has to match the file name
{
  gStyle->SetOptStat(false); // Turn off that ugly stats box
  
  // Create a TFile object and connect it to your file
  //TFile *f = new TFile("energy_reconstruction_gst-nu_carbon.root");
  string GENIE  = "/genie/app/users/kynaston/e4nu_scripts/macros/energy_rec/Ev_upper_12/Ev_upper_12energy_reconstruction_gst-nu_dune.root ";
    // "f" is just a placeholder name at this point
  //  string CLAS = "/genie/app/users/kynaston/e4nu_scripts/macros/Stuart_plots/e2a_C12_2261.root"; 
  TFile *f = new TFile(GENIE.c_str());
  
  f->ls(); // This will print out a list of histograms in your file
  //  f->Get("gst");

  // Create a canvas to draw on
   TCanvas *canvas = new TCanvas("e4nu","e4nu",900,600); // We will overwrite the default titles. The numbers set the size
   TLine *E = new TLine(2.261,0,2.261,30);
   E->SetLineColor(14);
   E->SetLineWidth(1);
   
   //TH1D *h_Ev = (TH1D*) f->Get("Ev");  
      TH1D *h_cal_qe = (TH1D*) f->Get("hEv");
      //   TH1D *h_cal_qe = (TH1D*) f->Get("kin_qe");
   h_cal_qe -> SetTitle("True neutrino beam energy for a DUNE like neutrino flux");                           
   h_cal_qe->GetXaxis()->SetTitle("True incoming neutrino energy [GeV]");                                         
   h_cal_qe->GetXaxis()->SetRangeUser(0,10); 
   h_cal_qe->GetYaxis()->SetRangeUser(0,12000);
   h_cal_qe->GetYaxis()->SetTitle("Arbitrary scale"); 
   h_cal_qe->SetLineWidth(2);                                                                                              
   h_cal_qe->SetFillColor(8);                                                                                              
   h_cal_qe->SetLineColor(8); 
   h_cal_qe->Draw("HIST");
   //   TH1D *h_cal_res = (TH1D*) f->Get("hEv");
   //h_cal_res->SetLineWidth(2);
   //h_cal_res->SetFillColor(2);
   // h_cal_res->SetLineColor(4);
   //TH1D *h_cal_mec = (TH1D*) f->Get("kin_mec");
   //TH1D *h_cal_mec = (TH1D*) f->Get("hEv");
   //h_cal_mec->SetLineWidth(1);
   //h_cal_mec->SetFillColor(1);
   // h_cal_mec->SetLineColor(1); 
   //TH1D *h_cal_dis = (TH1D*) f->Get("kin_dis");
   //TH1D *h_cal_dis = (TH1D*) f->Get("hEv");
   //h_cal_res->SetLineWidth(2);
   //h_cal_dis->SetFillColor(4);
   //h_cal_dis->SetLineColor(3);

   //h_cal_res->Draw("HIST SAME");
   //h_cal_mec->Draw("HIST SAME");
   //h_cal_dis->Draw("HIST SAME");
   // Add a legend using TLegend https://root.cern.ch/doc/master/classTLegend.html
   // E->Draw();
  auto legend = new TLegend(0.75, 0.5, 0.85, 0.8); //(bottom left corner x coordinate, bottom left corner y coordinate, top right corner x coordinate, top right corner y coordinate)
  legend->SetHeader("Legend");
  //legend->AddEntry(h_cal_qe,"QE");
  //l/egend->AddEntry(h_cal_res,"RES");
  //legend->AddEntry(h_cal_mec,"MEC");
  //legend->AddEntry(h_cal_dis,"DIS");
  // legend->Draw();  
  
  // Save the plot you make as an image file
  canvas->SaveAs("DUNESPEC.png");
  

}
