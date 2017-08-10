//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Aug  9 11:38:48 2017 by ROOT version 5.34/36
// from TTree _tree_event/
// found on file: AnalysisResults.root
//////////////////////////////////////////////////////////

#ifndef AnalysisClass_h
#define AnalysisClass_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class AnalysisClass {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Char_t          id_git[48];
   Char_t          version_aliroot[11];
   Char_t          version_aliphysics[14];
   Char_t          version_jec[21];
   Char_t          grid_data_dir[24];
   Char_t          grid_data_pattern[22];
   Int_t           beam_particle[2];
   UChar_t         ntrigger_class;
   Char_t          trigger_class[1];   //[ntrigger_class]
   Int_t           run_number;
   ULong64_t       trigger_mask[2];
   Char_t          mixed_event;
   Float_t         multiplicity_v0[64];
   Float_t         centrality_v0m;
   Float_t         centrality[9];
   Float_t         event_plane_psi_v0[3];
   Double_t        event_plane_q_v0[3][2];
   Bool_t          has_misalignment_matrix;
   Int_t           eg_ntrial;
   Float_t         eg_perp_hat;
   Float_t         eg_cross_section;
   Double_t        primary_vertex[3];
   ULong64_t       ncluster;
   Float_t         cluster_e[1697];   //[ncluster]
   Float_t         cluster_pt[1697];   //[ncluster]
   Float_t         cluster_eta[1697];   //[ncluster]
   Float_t         cluster_phi[1697];   //[ncluster]
   Float_t         cluster_m02[1697];   //[ncluster]
   Float_t         cluster_m20[1697];   //[ncluster]
   Float_t         cluster_tof[1697];   //[ncluster]
   Int_t           cluster_ncell[1697];   //[ncluster]
   UShort_t        cluster_cell_id_max[1697];   //[ncluster]
   ULong64_t       ntrack;
   Float_t         track_e[3282];   //[ntrack]
   Float_t         track_pt[3282];   //[ntrack]
   Float_t         track_eta[3282];   //[ntrack]
   Float_t         track_phi[3282];   //[ntrack]
   UChar_t         track_quality[3282];   //[ntrack]
   Float_t         track_tpc_dedx[3282];   //[ntrack]
   Float_t         track_tpc_length_active_zone[3282];   //[ntrack]
   UChar_t         track_tpc_xrow[3282];   //[ntrack]
   UChar_t         track_tpc_ncluster[3282];   //[ntrack]
   UChar_t         track_tpc_ncluster_dedx[3282];   //[ntrack]
   UChar_t         track_tpc_ncluster_findable[3282];   //[ntrack]
   UChar_t         track_its_ncluster[3282];   //[ntrack]
   Float_t         track_dca_xy[3282];   //[ntrack]
   Float_t         track_dca_z[3282];   //[ntrack]
   UShort_t        track_mc_truth_index[3282];   //[ntrack]
   ULong64_t       nmuon_track;
   Float_t         muon_track_e[51];   //[nmuon_track]
   Float_t         muon_track_pt[51];   //[nmuon_track]
   Float_t         muon_track_eta[51];   //[nmuon_track]
   Float_t         muon_track_phi[51];   //[nmuon_track]
   Float_t         muon_track_r_abs[51];   //[nmuon_track]
   Float_t         muon_track_p_dca[51];   //[nmuon_track]
   Float_t         muon_track_sigma_p_dca[51];   //[nmuon_track]
   UShort_t        muon_track_mc_truth_index[51];   //[nmuon_track]
   ULong64_t       nmc_truth;
   Float_t         mc_truth_e[1];   //[nmc_truth]
   Float_t         mc_truth_pt[1];   //[nmc_truth]
   Float_t         mc_truth_eta[1];   //[nmc_truth]
   Float_t         mc_truth_phi[1];   //[nmc_truth]
   Short_t         mc_truth_pdg_code[1];   //[nmc_truth]
   UChar_t         mc_truth_status[1];   //[nmc_truth]
   UChar_t         mc_truth_generator_index[1];   //[nmc_truth]
   ULong64_t       njet;
   Float_t         jet_e_raw[49];   //[njet]
   Float_t         jet_e[49];   //[njet]
   Float_t         jet_e_charged[49];   //[njet]
   Float_t         jet_pt_raw[49];   //[njet]
   Float_t         jet_pt[49];   //[njet]
   Float_t         jet_pt_charged[49];   //[njet]
   Float_t         jet_eta_raw[49];   //[njet]
   Float_t         jet_eta[49];   //[njet]
   Float_t         jet_phi[49];   //[njet]
   Float_t         jet_area[49];   //[njet]
   Float_t         jet_emf_raw[49];   //[njet]
   Float_t         jet_emf[49];   //[njet]
   Float_t         jet_e_truth[49];   //[njet]
   Float_t         jet_pt_truth[49];   //[njet]
   Float_t         jet_eta_truth[49];   //[njet]
   Float_t         jet_phi_truth[49];   //[njet]
   Float_t         jet_area_truth[49];   //[njet]
   Float_t         jet_emf_truth[49];   //[njet]
   Int_t           jet_truth_index_z_truth[49][2];   //[njet]
   Float_t         jet_truth_z_truth[49][2];   //[njet]
   Int_t           jet_truth_index_z_reco[49][2];   //[njet]
   Float_t         jet_truth_z_reco[49][2];   //[njet]
   ULong64_t       njet_truth;
   Float_t         jet_truth_e[1];   //[njet_truth]
   Float_t         jet_truth_pt[1];   //[njet_truth]
   Float_t         jet_truth_eta[1];   //[njet_truth]
   Float_t         jet_truth_phi[1];   //[njet_truth]
   Float_t         jet_truth_area[1];   //[njet_truth]
   Float_t         jet_truth_emf[1];   //[njet_truth]
   Float_t         cell_amplitude[17664];
   Float_t         cell_time[17664];
   UShort_t        cell_mc_truth_index[17664];
   UChar_t         cell_efrac[17664];

   // List of branches
   TBranch        *b_id_git;   //!
   TBranch        *b_version_aliroot;   //!
   TBranch        *b_version_aliphysics;   //!
   TBranch        *b_version_jec;   //!
   TBranch        *b_grid_data_dir;   //!
   TBranch        *b_grid_data_pattern;   //!
   TBranch        *b_beam_particle;   //!
   TBranch        *b_ntrigger_class;   //!
   TBranch        *b_trigger_class;   //!
   TBranch        *b_run_number;   //!
   TBranch        *b_trigger_mask;   //!
   TBranch        *b_mixed_event;   //!
   TBranch        *b_multiplicity_v0;   //!
   TBranch        *b_centrality_v0m;   //!
   TBranch        *b_centrality;   //!
   TBranch        *b_event_plane_psi_v0;   //!
   TBranch        *b_event_plane_q_v0;   //!
   TBranch        *b_has_misalignment_matrix;   //!
   TBranch        *b_eg_ntrial;   //!
   TBranch        *b_eg_perp_hat;   //!
   TBranch        *b_eg_cross_section;   //!
   TBranch        *b_primary_vertex;   //!
   TBranch        *b_ncluster;   //!
   TBranch        *b_cluster_e;   //!
   TBranch        *b_cluster_pt;   //!
   TBranch        *b_cluster_eta;   //!
   TBranch        *b_cluster_phi;   //!
   TBranch        *b_cluster_m02;   //!
   TBranch        *b_cluster_m20;   //!
   TBranch        *b_cluster_tof;   //!
   TBranch        *b_cluster_ncell;   //!
   TBranch        *b_cluster_cell_id_max;   //!
   TBranch        *b_ntrack;   //!
   TBranch        *b_track_e;   //!
   TBranch        *b_track_pt;   //!
   TBranch        *b_track_eta;   //!
   TBranch        *b_track_phi;   //!
   TBranch        *b_track_quality;   //!
   TBranch        *b_track_tpc_dedx;   //!
   TBranch        *b_track_tpc_length_active_zone;   //!
   TBranch        *b_track_tpc_xrow;   //!
   TBranch        *b_track_tpc_ncluster;   //!
   TBranch        *b_track_tpc_ncluster_dedx;   //!
   TBranch        *b_track_tpc_ncluster_findable;   //!
   TBranch        *b_track_its_ncluster;   //!
   TBranch        *b_track_dca_xy;   //!
   TBranch        *b_track_dca_z;   //!
   TBranch        *b_track_mc_truth_index;   //!
   TBranch        *b_nmuon_track;   //!
   TBranch        *b_muon_track_e;   //!
   TBranch        *b_muon_track_pt;   //!
   TBranch        *b_muon_track_eta;   //!
   TBranch        *b_muon_track_phi;   //!
   TBranch        *b_muon_track_r_abs;   //!
   TBranch        *b_muon_track_p_dca;   //!
   TBranch        *b_muon_track_sigma_p_dca;   //!
   TBranch        *b_muon_track_mc_truth_index;   //!
   TBranch        *b_nmc_truth;   //!
   TBranch        *b_mc_truth_e;   //!
   TBranch        *b_mc_truth_pt;   //!
   TBranch        *b_mc_truth_eta;   //!
   TBranch        *b_mc_truth_phi;   //!
   TBranch        *b_mc_truth_pdg_code;   //!
   TBranch        *b_mc_truth_status;   //!
   TBranch        *b_mc_truth_generator_index;   //!
   TBranch        *b_njet;   //!
   TBranch        *b_jet_e_raw;   //!
   TBranch        *b_jet_e;   //!
   TBranch        *b_jet_e_charged;   //!
   TBranch        *b_jet_pt_raw;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_pt_charged;   //!
   TBranch        *b_jet_eta_raw;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_area;   //!
   TBranch        *b_jet_emf_raw;   //!
   TBranch        *b_jet_emf;   //!
   TBranch        *b_jet_e_truth;   //!
   TBranch        *b_jet_pt_truth;   //!
   TBranch        *b_jet_eta_truth;   //!
   TBranch        *b_jet_phi_truth;   //!
   TBranch        *b_jet_area_truth;   //!
   TBranch        *b_jet_emf_truth;   //!
   TBranch        *b_jet_truth_index_z_truth;   //!
   TBranch        *b_jet_truth_z_truth;   //!
   TBranch        *b_jet_truth_index_z_reco;   //!
   TBranch        *b_jet_truth_z_reco;   //!
   TBranch        *b_njet_truth;   //!
   TBranch        *b_jet_truth_e;   //!
   TBranch        *b_jet_truth_pt;   //!
   TBranch        *b_jet_truth_eta;   //!
   TBranch        *b_jet_truth_phi;   //!
   TBranch        *b_jet_truth_area;   //!
   TBranch        *b_jet_truth_emf;   //!
   TBranch        *b_cell_amplitude;   //!
   TBranch        *b_cell_time;   //!
   TBranch        *b_cell_mc_truth_index;   //!
   TBranch        *b_cell_efrac;   //!

   AnalysisClass(TTree *tree=0);
   virtual ~AnalysisClass();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef AnalysisClass_cxx
AnalysisClass::AnalysisClass(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("AnalysisResults.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("AnalysisResults.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("AnalysisResults.root:/AliAnalysisTaskNTGJ");
      dir->GetObject("_tree_event",tree);

   }
   Init(tree);
}

AnalysisClass::~AnalysisClass()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AnalysisClass::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AnalysisClass::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void AnalysisClass::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("id_git", id_git, &b_id_git);
   fChain->SetBranchAddress("version_aliroot", version_aliroot, &b_version_aliroot);
   fChain->SetBranchAddress("version_aliphysics", version_aliphysics, &b_version_aliphysics);
   fChain->SetBranchAddress("version_jec", version_jec, &b_version_jec);
   fChain->SetBranchAddress("grid_data_dir", grid_data_dir, &b_grid_data_dir);
   fChain->SetBranchAddress("grid_data_pattern", grid_data_pattern, &b_grid_data_pattern);
   fChain->SetBranchAddress("beam_particle", beam_particle, &b_beam_particle);
   fChain->SetBranchAddress("ntrigger_class", &ntrigger_class, &b_ntrigger_class);
   fChain->SetBranchAddress("trigger_class", &trigger_class, &b_trigger_class);
   fChain->SetBranchAddress("run_number", &run_number, &b_run_number);
   fChain->SetBranchAddress("trigger_mask", trigger_mask, &b_trigger_mask);
   fChain->SetBranchAddress("mixed_event", &mixed_event, &b_mixed_event);
   fChain->SetBranchAddress("multiplicity_v0", multiplicity_v0, &b_multiplicity_v0);
   fChain->SetBranchAddress("centrality_v0m", &centrality_v0m, &b_centrality_v0m);
   fChain->SetBranchAddress("centrality", centrality, &b_centrality);
   fChain->SetBranchAddress("event_plane_psi_v0", event_plane_psi_v0, &b_event_plane_psi_v0);
   fChain->SetBranchAddress("event_plane_q_v0", event_plane_q_v0, &b_event_plane_q_v0);
   fChain->SetBranchAddress("has_misalignment_matrix", &has_misalignment_matrix, &b_has_misalignment_matrix);
   fChain->SetBranchAddress("eg_ntrial", &eg_ntrial, &b_eg_ntrial);
   fChain->SetBranchAddress("eg_perp_hat", &eg_perp_hat, &b_eg_perp_hat);
   fChain->SetBranchAddress("eg_cross_section", &eg_cross_section, &b_eg_cross_section);
   fChain->SetBranchAddress("primary_vertex", primary_vertex, &b_primary_vertex);
   fChain->SetBranchAddress("ncluster", &ncluster, &b_ncluster);
   fChain->SetBranchAddress("cluster_e", cluster_e, &b_cluster_e);
   fChain->SetBranchAddress("cluster_pt", cluster_pt, &b_cluster_pt);
   fChain->SetBranchAddress("cluster_eta", cluster_eta, &b_cluster_eta);
   fChain->SetBranchAddress("cluster_phi", cluster_phi, &b_cluster_phi);
   fChain->SetBranchAddress("cluster_m02", cluster_m02, &b_cluster_m02);
   fChain->SetBranchAddress("cluster_m20", cluster_m20, &b_cluster_m20);
   fChain->SetBranchAddress("cluster_tof", cluster_tof, &b_cluster_tof);
   fChain->SetBranchAddress("cluster_ncell", cluster_ncell, &b_cluster_ncell);
   fChain->SetBranchAddress("cluster_cell_id_max", cluster_cell_id_max, &b_cluster_cell_id_max);
   fChain->SetBranchAddress("ntrack", &ntrack, &b_ntrack);
   fChain->SetBranchAddress("track_e", track_e, &b_track_e);
   fChain->SetBranchAddress("track_pt", track_pt, &b_track_pt);
   fChain->SetBranchAddress("track_eta", track_eta, &b_track_eta);
   fChain->SetBranchAddress("track_phi", track_phi, &b_track_phi);
   fChain->SetBranchAddress("track_quality", track_quality, &b_track_quality);
   fChain->SetBranchAddress("track_tpc_dedx", track_tpc_dedx, &b_track_tpc_dedx);
   fChain->SetBranchAddress("track_tpc_length_active_zone", track_tpc_length_active_zone, &b_track_tpc_length_active_zone);
   fChain->SetBranchAddress("track_tpc_xrow", track_tpc_xrow, &b_track_tpc_xrow);
   fChain->SetBranchAddress("track_tpc_ncluster", track_tpc_ncluster, &b_track_tpc_ncluster);
   fChain->SetBranchAddress("track_tpc_ncluster_dedx", track_tpc_ncluster_dedx, &b_track_tpc_ncluster_dedx);
   fChain->SetBranchAddress("track_tpc_ncluster_findable", track_tpc_ncluster_findable, &b_track_tpc_ncluster_findable);
   fChain->SetBranchAddress("track_its_ncluster", track_its_ncluster, &b_track_its_ncluster);
   fChain->SetBranchAddress("track_dca_xy", track_dca_xy, &b_track_dca_xy);
   fChain->SetBranchAddress("track_dca_z", track_dca_z, &b_track_dca_z);
   fChain->SetBranchAddress("track_mc_truth_index", track_mc_truth_index, &b_track_mc_truth_index);
   fChain->SetBranchAddress("nmuon_track", &nmuon_track, &b_nmuon_track);
   fChain->SetBranchAddress("muon_track_e", muon_track_e, &b_muon_track_e);
   fChain->SetBranchAddress("muon_track_pt", muon_track_pt, &b_muon_track_pt);
   fChain->SetBranchAddress("muon_track_eta", muon_track_eta, &b_muon_track_eta);
   fChain->SetBranchAddress("muon_track_phi", muon_track_phi, &b_muon_track_phi);
   fChain->SetBranchAddress("muon_track_r_abs", muon_track_r_abs, &b_muon_track_r_abs);
   fChain->SetBranchAddress("muon_track_p_dca", muon_track_p_dca, &b_muon_track_p_dca);
   fChain->SetBranchAddress("muon_track_sigma_p_dca", muon_track_sigma_p_dca, &b_muon_track_sigma_p_dca);
   fChain->SetBranchAddress("muon_track_mc_truth_index", muon_track_mc_truth_index, &b_muon_track_mc_truth_index);
   fChain->SetBranchAddress("nmc_truth", &nmc_truth, &b_nmc_truth);
   fChain->SetBranchAddress("mc_truth_e", &mc_truth_e, &b_mc_truth_e);
   fChain->SetBranchAddress("mc_truth_pt", &mc_truth_pt, &b_mc_truth_pt);
   fChain->SetBranchAddress("mc_truth_eta", &mc_truth_eta, &b_mc_truth_eta);
   fChain->SetBranchAddress("mc_truth_phi", &mc_truth_phi, &b_mc_truth_phi);
   fChain->SetBranchAddress("mc_truth_pdg_code", &mc_truth_pdg_code, &b_mc_truth_pdg_code);
   fChain->SetBranchAddress("mc_truth_status", &mc_truth_status, &b_mc_truth_status);
   fChain->SetBranchAddress("mc_truth_generator_index", &mc_truth_generator_index, &b_mc_truth_generator_index);
   fChain->SetBranchAddress("njet", &njet, &b_njet);
   fChain->SetBranchAddress("jet_e_raw", jet_e_raw, &b_jet_e_raw);
   fChain->SetBranchAddress("jet_e", jet_e, &b_jet_e);
   fChain->SetBranchAddress("jet_e_charged", jet_e_charged, &b_jet_e_charged);
   fChain->SetBranchAddress("jet_pt_raw", jet_pt_raw, &b_jet_pt_raw);
   fChain->SetBranchAddress("jet_pt", jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_pt_charged", jet_pt_charged, &b_jet_pt_charged);
   fChain->SetBranchAddress("jet_eta_raw", jet_eta_raw, &b_jet_eta_raw);
   fChain->SetBranchAddress("jet_eta", jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_area", jet_area, &b_jet_area);
   fChain->SetBranchAddress("jet_emf_raw", jet_emf_raw, &b_jet_emf_raw);
   fChain->SetBranchAddress("jet_emf", jet_emf, &b_jet_emf);
   fChain->SetBranchAddress("jet_e_truth", jet_e_truth, &b_jet_e_truth);
   fChain->SetBranchAddress("jet_pt_truth", jet_pt_truth, &b_jet_pt_truth);
   fChain->SetBranchAddress("jet_eta_truth", jet_eta_truth, &b_jet_eta_truth);
   fChain->SetBranchAddress("jet_phi_truth", jet_phi_truth, &b_jet_phi_truth);
   fChain->SetBranchAddress("jet_area_truth", jet_area_truth, &b_jet_area_truth);
   fChain->SetBranchAddress("jet_emf_truth", jet_emf_truth, &b_jet_emf_truth);
   fChain->SetBranchAddress("jet_truth_index_z_truth", jet_truth_index_z_truth, &b_jet_truth_index_z_truth);
   fChain->SetBranchAddress("jet_truth_z_truth", jet_truth_z_truth, &b_jet_truth_z_truth);
   fChain->SetBranchAddress("jet_truth_index_z_reco", jet_truth_index_z_reco, &b_jet_truth_index_z_reco);
   fChain->SetBranchAddress("jet_truth_z_reco", jet_truth_z_reco, &b_jet_truth_z_reco);
   fChain->SetBranchAddress("njet_truth", &njet_truth, &b_njet_truth);
   fChain->SetBranchAddress("jet_truth_e", &jet_truth_e, &b_jet_truth_e);
   fChain->SetBranchAddress("jet_truth_pt", &jet_truth_pt, &b_jet_truth_pt);
   fChain->SetBranchAddress("jet_truth_eta", &jet_truth_eta, &b_jet_truth_eta);
   fChain->SetBranchAddress("jet_truth_phi", &jet_truth_phi, &b_jet_truth_phi);
   fChain->SetBranchAddress("jet_truth_area", &jet_truth_area, &b_jet_truth_area);
   fChain->SetBranchAddress("jet_truth_emf", &jet_truth_emf, &b_jet_truth_emf);
   fChain->SetBranchAddress("cell_amplitude", cell_amplitude, &b_cell_amplitude);
   fChain->SetBranchAddress("cell_time", cell_time, &b_cell_time);
   fChain->SetBranchAddress("cell_mc_truth_index", cell_mc_truth_index, &b_cell_mc_truth_index);
   fChain->SetBranchAddress("cell_efrac", cell_efrac, &b_cell_efrac);
   Notify();
}

Bool_t AnalysisClass::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AnalysisClass::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AnalysisClass::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef AnalysisClass_cxx