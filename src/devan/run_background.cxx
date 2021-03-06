#include "run_background.h"
#include "fastjet/ClusterSequence.hh"

#include <util/pythia/pyargs.h>
#include <util/pyutil.h>
#include <util/looputil.h>

#include <Pythia8/Pythia.h>

#include <TFile.h>
#include <TH1F.h>
#include <TH2F.h>
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
        TH1F *delta_s_vacuum = new TH1F("delta_s_vacuum", "Delta s of jets", 100, 0, 1);
        TH1F *delta_s_with_background = new TH1F("delta_s_with_background", "Delta s of jets", 100, 0, 1);
        TH2F *background_spectrum = new TH2F("background_spectrum", "Distribution of Background Particles", 100, 0, 6.3, 100, -2, 2);
        TH1F *jet_spectrum_vacuum = new TH1F("jet_spectrum_vacuum", "Distribution of Full Jet pT in Vacuum", 150, 70, 180);
        TH1F *jet_spectrum_with_background = new TH1F("jet_spectrum_with_background", "Distribution of Full Jet pT with Background", 150, 70, 180);
        TH1F *backgrounmd_jetfinder = new TH1F("background_jetfinder", "Results of Jetfinder on Only Background", 100, 0, 10);
        double eta = 2;

        // initialize pythia with a config and command line args
		Pythia8::Pythia *ppythia = PyUtil::make_pythia(args.asString());
		Pythia8::Pythia &pythia  = *ppythia;
		auto &event              = pythia.event;

		// this is where the event loop section starts
        auto nEv = args.getI("Main:numberOfEvents");
        LoopUtil::TPbar pbar(nEv);
        double num_background_particles = 100.;
        double sqrt_num_background = TMath::Sqrt(num_background_particles);
        double pt_background = 700.;
        for (unsigned int iE = 0; iE < nEv; iE++)
        {
            pbar.Update();

            // setting jetfinder parameters
            vector<PseudoJet> particles;
            vector<PseudoJet> particles_with_background;
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
                    particles.push_back(PseudoJet(event[ip].px(), event[ip].py(), event[ip].pz(), event[ip].e()));
                    particles_with_background.push_back(PseudoJet(event[ip].px(), event[ip].py(), event[ip].pz(), event[ip].e()));
                }
            }

            //Generate background particles and push_back to particles_with_background
            for (int i = 0; i < sqrt_num_background; i++)
            {
                double temp_eta = (4/sqrt_num_background)*i - 2;
                double temp_theta = 2*TMath::ATan(TMath::Exp(-temp_eta));
                for (int j = 0; j < sqrt_num_background; j++)
                {
                    double temp_phi = 2*TMath::Pi()*j/sqrt_num_background;
                    particles_with_background.push_back(PseudoJet(  (pt_background/TMath::C())*TMath::Sin(temp_theta)*TMath::Cos(temp_phi), 
                                                                    (pt_background/TMath::C())*TMath::Sin(temp_theta)*TMath::Sin(temp_phi), 
                                                                    (pt_background/TMath::C())*TMath::Cos(temp_theta), 
                                                                    pt_background    ));
                    background_spectrum->Fill(temp_phi, temp_eta, 1.);
                }
            }

            // clustering and extracting jets
            ClusterSequence cs(particles, jet_def);
            ClusterSequence cs_with_background(particles_with_background, jet_def);
            vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());
            vector<PseudoJet> jets_with_background = sorted_by_pt(cs_with_background.inclusive_jets());

            //clustering and extracting subjets
            for (int i=0; i<jets.size(); i++)
            {
                if (jets[i].pt() < 90 || TMath::Abs(jets[i].eta()) > eta - R)
                    continue;
                vector<PseudoJet> constituents = jets[i].constituents();
                ClusterSequence cs2(constituents, subjet_def);
                vector<PseudoJet> subjets = sorted_by_pt(cs2.inclusive_jets());
                
                // filling histogram with subjets' pT
                for (int j=0; j<subjets.size(); j++)
                {
                    jet_pt_vacuum->Fill(subjets[j].pt()/jets[i].pt(), 1.);
                }

                // computing delta_s_vacuum
                delta_s_vacuum->Fill((subjets[0].pt() - subjets[1].pt()) / jets[i].pt(), 1.);
                jet_spectrum_vacuum->Fill(jets[i].pt(), 1.);

                continue;
            }
            for (int i=0; i<jets_with_background.size(); i++)
            {
                if (jets_with_background[i].pt() < 90 || TMath::Abs(jets_with_background[i].eta()) > eta - R)
                    continue;
                vector<PseudoJet> constituents = jets_with_background[i].constituents();
                ClusterSequence cs2(constituents, subjet_def);
                vector<PseudoJet> subjets = sorted_by_pt(cs2.inclusive_jets());
                
                // filling histogram with subjets' pT
                for (int j=0; j<subjets.size(); j++)
                {
                    jet_pt_with_background->Fill(subjets[j].pt()/jets_with_background[i].pt(), 1.);
                }

                //computing delta_s_with_background
                delta_s_with_background->Fill((subjets[0].pt() - subjets[1].pt()) / jets[i].pt(), 1.);
                jet_spectrum_with_background->Fill(jets[i].pt(), 1.);

                continue;
            }
        }
        
        norm_vacuum->SetBinContent(1, pythia.info.sigmaGen());
        norm_vacuum->SetBinContent(2, pythia.info.weightSum());
        norm_vacuum->SetBinContent(3, eta);

        norm_with_background->SetBinContent(1, pythia.info.sigmaGen());
        norm_with_background->SetBinContent(2, pythia.info.weightSum());
        norm_with_background->SetBinContent(3, eta);

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
