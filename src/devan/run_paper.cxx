#include "run_paper.h"


#include <util/pythia/pyargs.h>
#include <util/pyutil.h>
#include <util/looputil.h>

#include <Pythia8/Pythia.h>

#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>

#include <string>
#include <iostream>

using namespace std;

int run_paper (const std::string &s)
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

        TFile *alice = TFile::Open("~/lbnl/outputs/particle_data_alice.root");
        alice->cd("Table 1");
        TH1F *hpT_original = (TH1F*)gDirectory->Get("Hist1D_y3");
        
        TFile *fout = TFile::Open(outfname.c_str(), "RECREATE");
        fout->cd();
        TH1F *hpT = (TH1F*)hpT_original->Clone("hpT");
        hpT->Reset();
        TH1F *norm = new TH1F("norm", "pT;p_{T} (GeV/#it{c});counts", 3, 0, 3);
        double eta = .8;

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
            if (pythia.next() == false) continue;

            // loop over particles in the event
            for (unsigned int ip = 0; ip < event.size(); ip++)
            {
                if (event[ip].isFinal() && event[ip].isCharged() && TMath::Abs(event[ip].eta()) < eta)
                {
                	hpT->Fill(event[ip].pT(), 1./event[ip].pT());
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
