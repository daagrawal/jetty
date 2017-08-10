#!/bin/bash

jettyDevanExe --subjet --output="subjet_pthat25.root" Beams:eCM=13000. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=25 PhaseSpace:pTHatMax=100
jettyDevanExe --subjet --output="subjet_pthat100.root" Beams:eCM=13000. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=100 PhaseSpace:pTHatMax=200
jettyDevanExe --subjet --output="subjet_pthat200.root" Beams:eCM=13000. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=200 PhaseSpace:pTHatMax=300
jettyDevanExe --subjet --output="subjet_pthat300.root" Beams:eCM=13000. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=300 PhaseSpace:pTHatMax=400
jettyDevanExe --subjet --output="subjet_pthat400.root" Beams:eCM=13000. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=400 PhaseSpace:pTHatMax=500