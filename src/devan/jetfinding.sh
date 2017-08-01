#!/bin/bash

jettyDevanExe --jetfinding --output="jetfinding_pthat10.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=10 PhaseSpace:pTHatMax=25
jettyDevanExe --jetfinding --output="jetfinding_pthat25.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=25 PhaseSpace:pTHatMax=50
jettyDevanExe --jetfinding --output="jetfinding_pthat50.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=50 PhaseSpace:pTHatMax=100
jettyDevanExe --jetfinding --output="jetfinding_pthat100.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=100 PhaseSpace:pTHatMax=200
jettyDevanExe --jetfinding --output="jetfinding_pthat200.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=200 PhaseSpace:pTHatMax=-1