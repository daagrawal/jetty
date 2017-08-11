#include "run_subjet.h"
#include "fastjet/ClusterSequence.hh"
#include "AnalysisClass.h"

#include <util/pyargs.h>
#include <util/pyutil.h>
#include <util/looputil.h>

#include <Pythia8/Pythia.h>

#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>

#include <string>
#include <iostream>

using namespace fastjet;
using namespace std;

int run_subjet (const std::string &s)
{
        PyUtil::Args args(s);
        cout << args.asString("[pythia_run_wrapper:status]") << endl;
        if (args.isSet("--dry")) return 0;

        // create the output root file
        string outfname = args.get("--output");
        if (outfname.size() < 1)
        {
        	outfname = "default_output.root";
        }

        // initializing data extraction
        TFile *fin = new TFile("~/lbnl/jetty/src/devan/AnalysisResults.root");
        TDirectoryFile *fdir = (TDirectoryFile*)fin->Get("AliAnalysisTaskNTGJ");
        TTree *t = (TTree*)fdir->Get("_tree_event");
        AnalysisClass ana(t);
        // iterative counters for data extraction
        Long64_t nbytes = 0, nb = 0;
        Long64_t jentry = 0;
        
        // creating file to be written?
        TFile *fout = TFile::Open(outfname.c_str(), "RECREATE");
        fout->cd();
        TH1F *jet_pt_25 = new TH1F("jet_pt_25", "Subjet pT", 100, 0, 1);
        TH1F *jet_pt_50 = new TH1F("jet_pt_50", "Subjet pT", 100, 0, 1);
        TH1F *jet_pt_100 = new TH1F("jet_pt_100", "Subjet pT", 100, 0, 1);
        TH1F *jet_pt_200 = new TH1F("jet_pt_200", "Subjet pT", 100, 0, 1);
        TH1F *norm = new TH1F("norm", "pT;p_{T} (GeV/#it{c});counts", 3, 0, 3);
        double eta = 1.2;

        // initialize pythia with a config and command line args
		Pythia8::Pythia *ppythia = PyUtil::make_pythia(args.asString());
		Pythia8::Pythia &pythia  = *ppythia;
		auto &event              = pythia.event;

		// this is where the event loop section starts
        auto nEv = args.getI("Main:numberOfEvents");
        LoopUtil::TPbar pbar(nEv);
        for (unsigned int iE = 0; iE < nEv; iE++)
        {
            pbar.Update();

            // implementing data extraction
            Long64_t ientry = ana.LoadTree(jentry);
            if (ientry < 0) continue;
            nb = ana.GetEntry(jentry);
            nbytes += nb;
            jentry++;
            if (ana.ntrack > 1) 
            {
                vector<PseudoJet> tracks;
                for (int itrack = 0; itrack < ana.ntrack; itrack++)
                {
                    PseudoJet track;
                    track.reset_momentum_PtYPhiM (ana.track_pt[itrack], ana.track_eta[itrack], ana.track_phi[itrack], 0.0);
                    tracks.push_back(track);
                }
            }

            // setting jetfinder parameters
            vector<PseudoJet> particles;
            double R = .6;
            double r = .2;
            JetDefinition jet_def(antikt_algorithm, R);
            JetDefinition subjet_def(antikt_algorithm, r);

            if (pythia.next() == false) continue;

            // loop over particles in the event
            for (unsigned int ip = 0; ip < event.size(); ip++)
            {
                if (event[ip].isFinal() && TMath::Abs(event[ip].eta()) < eta)
                {
                	//hpT->Fill(event[ip].pT(), 1./event[ip].pT());
                    particles.push_back(PseudoJet(event[ip].px(), event[ip].py(), event[ip].pz(), event[ip].e()));
                }
            }

            // clustering and extracting jets
            ClusterSequence cs(particles, jet_def);
            vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());

            //clustering and extracting subjets
            for (int i=0; i<jets.size(); i++)
            {
                if (jets[i].pt() < 25 || jets[i].pt() > 500 || TMath::Abs(jets[i].eta()) > eta - R)
                    continue;
                vector<PseudoJet> constituents = jets[i].constituents();
                ClusterSequence cs2(constituents, subjet_def);
                vector<PseudoJet> subjets = sorted_by_pt(cs2.inclusive_jets());
                
                // filling histogram with subjets' pT
                if (jets[i].pt() > 25 && jets[i].pt() < 50)
                {
                    for (int j=0; j<subjets.size(); j++)
                    {
                        jet_pt_25->Fill(subjets[j].pt()/jets[i].pt(), 1.);
                    }
                    continue;
                }
                if (jets[i].pt() > 50 && jets[i].pt() < 100)
                {
                    for (int j=0; j<subjets.size(); j++)
                    {
                        jet_pt_50->Fill(subjets[j].pt()/jets[i].pt(), 1.);
                    }
                    continue;
                }
                if (jets[i].pt() > 100 && jets[i].pt() < 200)
                {
                    for (int j=0; j<subjets.size(); j++)
                    {
                        jet_pt_100->Fill(subjets[j].pt()/jets[i].pt(), 1.);
                    }
                    continue;
                }
                else
                    for (int j=0; j<subjets.size(); j++)
                    {
                        jet_pt_200->Fill(subjets[j].pt()/jets[i].pt(), 1.);
                    }
            }
        }
        
        norm->SetBinContent(1, pythia.info.sigmaGen());
        norm->SetBinContent(2, pythia.info.weightSum());
        norm->SetBinContent(3, eta);

        pythia.stat();
        cout << "[i] Generation done." << endl;

        // remember to properly save/update and close the output file
        fout->cd();
        fout->Write();
        fout->Close();
        delete fout;

        string xsec_outfname = outfname + ".txt";
        PyUtil::CrossSections(pythia, xsec_outfname.c_str());

        // delete the pythia
        delete ppythia;
        return 0;
}
