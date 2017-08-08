#!/bin/bash

jettyDevanExe --subjet --output="subjet_pthat25.root" Beams:eCM=13000. Main:numberOfEvents=5000 PhaseSpace:pTHatMin=25 PhaseSpace:pTHatMax=50
jettyDevanExe --subjet --output="subjet_pthat50.root" Beams:eCM=13000. Main:numberOfEvents=5000 PhaseSpace:pTHatMin=50 PhaseSpace:pTHatMax=100
jettyDevanExe --subjet --output="subjet_pthat100.root" Beams:eCM=13000. Main:numberOfEvents=5000 PhaseSpace:pTHatMin=100 PhaseSpace:pTHatMax=200
jettyDevanExe --subjet --output="subjet_pthat200.root" Beams:eCM=13000. Main:numberOfEvents=5000 PhaseSpace:pTHatMin=200 PhaseSpace:pTHatMax=-1