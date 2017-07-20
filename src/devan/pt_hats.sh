#!/bin/bash

jettyDevanExe --paper --output="7TeV_paper_pthat8.root" Beams:eCM=7000. Main:numberOfEvents=10000 PhaseSpace:pTHatMin=8 PhaseSpace:pTHatMax=10
jettyDevanExe --paper --output="7TeV_paper_pthat10.root" Beams:eCM=7000. Main:numberOfEvents=10000 PhaseSpace:pTHatMin=10 PhaseSpace:pTHatMax=15
jettyDevanExe --paper --output="7TeV_paper_pthat15.root" Beams:eCM=7000. Main:numberOfEvents=10000 PhaseSpace:pTHatMin=15 PhaseSpace:pTHatMax=20
jettyDevanExe --paper --output="7TeV_paper_pthat25.root" Beams:eCM=7000. Main:numberOfEvents=10000 PhaseSpace:pTHatMin=25 PhaseSpace:pTHatMax=30
jettyDevanExe --paper --output="7TeV_paper_pthat30.root" Beams:eCM=7000. Main:numberOfEvents=10000 PhaseSpace:pTHatMin=30 PhaseSpace:pTHatMax=-1