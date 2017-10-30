#include "run_background.h"
#include "fastjet/ClusterSequence.hh"

#include <util/pythia/pyargs.h>
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

int run_background (const std::string &s)
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
        
        // creating file to be written?
        TFile *fout = TFile::Open(outfname.c_str(), "RECREATE");
        fout->cd();
        TH1F *jet_pt_vacuum = new TH1F("jet_pt_vacuum", "Subjet pT", 100, 0, 1);
        TH1F *norm_vacuum = new TH1F("norm_vacuum", "pT;p_{T} (GeV/#it{c});counts", 3, 0, 3);
        TH1F *jet_pt_with_background = (TH1F*) jet_pt_vacuum->Clone("jet_pt_with_background");
        TH1F *norm_with_background = (TH1F*) norm_vacuum->Clone("norm_with_background");
        double eta = 2;

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

            // setting jetfinder parameters
            vector<PseudoJet> particles;
            vector<PseudoJet> particles_with_background
            double R = .4;
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
                    particles_with_background.push_back(PseudoJet(event[ip].px(), event[ip].py(), event[ip].pz(), event[ip].e()));
                }
            }

            //Generate background particles and push_back to particles_with_background
            for (int i = 0; i < 10, i++)
            {
                temp_eta = (2/10)*i - 2
                temp_theta = 2*TMath::ATan(TMath::Exp(-temp_eta))
                for (int j = 0; j < 10, i++)
                {
                    temp_phi = 2*TMath::Pi()*i/10
                    particles_with_background.push_back(PseudoJet(  (700./TMath::C())*TMath::Sin(temp_theta)*TMath::Cos(temp_phi), 
                                                                    (700./TMath::C())*TMath::Sin(temp_theta)*TMath::Sin(temp_phi), 
                                                                    (700./TMath::C())*TMath::Cos(temp_theta), 
                                                                    700.    ));
                }
            }

            // clustering and extracting jets
            ClusterSequence cs(particles, jet_def);
            ClusterSequence cs_with_background(particles_with_background, jet_def)
            vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());
            vector<PseudoJet> jets_with_background = sorted_by_pt(cs_with_background.inclusive_jets());

            //clustering and extracting subjets
            for (int i=0; i<jets.size(); i++)
            {
                if (jets[i].pt() < 90 || jets[i].pt() > 110 || TMath::Abs(jets[i].eta()) > eta - R)
                    continue;
                vector<PseudoJet> constituents = jets[i].constituents();
                ClusterSequence cs2(constituents, subjet_def);
                vector<PseudoJet> subjets = sorted_by_pt(cs2.inclusive_jets());
                
                // filling histogram with subjets' pT
                for (int j=0; j<subjets.size(); j++)
                {
                    jet_pt->Fill(subjets[j].pt()/jets[i].pt(), 1.);
                }
                continue;
            }
            for (int i=0; i<jets_with_background.size(); i++)
            {
                if (jets_with_background[i].pt() < 90 || jets_with_background[i].pt() > 110 || 
                        TMath::Abs(jets_with_background[i].eta()) > eta - R)
                    continue;
                vector<PseudoJet> constituents = jets_with_background[i].constituents();
                ClusterSequence cs2(constituents, subjet_def);
                vector<PseudoJet> subjets = sorted_by_pt(cs2.inclusive_jets());
                
                // filling histogram with subjets' pT
                for (int j=0; j<subjets.size(); j++)
                {
                    jet_pt_with_background->Fill(subjets[j].pt()/jets_with_background[i].pt(), 1.);
                }
                continue;
            }
        }
        
        norm_vacuum->SetBinContent(1, pythia.info.sigmaGen());
        norm_vacuum->SetBinContent(2, pythia.info.weightSum());
        norm_vacuum->SetBinContent(3, eta);

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
