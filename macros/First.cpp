void First()
{
	TFile *file1 = TFile::Open("~/lbnl/jetty/outputs/default_output.root");
	TH1F *hist1 = (TH1F*)file1->Get("hpT");
	TCanvas *c1 = new TCanvas("foo");
	c1->SetLogy();
	hist1->SetMarkerStyle(24);
	hist1->Draw("pe");
}