#!/bin/bash

jettyDevanExe --subjet --output="subjet_pthat20.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=20 PhaseSpace:pTHatMax=25
jettyDevanExe --subjet --output="subjet_pthat25.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=25 PhaseSpace:pTHatMax=30
jettyDevanExe --subjet --output="subjet_pthat30.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=30 PhaseSpace:pTHatMax=35
jettyDevanExe --subjet --output="subjet_pthat40.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=40 PhaseSpace:pTHatMax=50
jettyDevanExe --subjet --output="subjet_pthat50.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=50 PhaseSpace:pTHatMax=60
jettyDevanExe --subjet --output="subjet_pthat60.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=60 PhaseSpace:pTHatMax=70
jettyDevanExe --subjet --output="subjet_pthat70.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=70 PhaseSpace:pTHatMax=85
jettyDevanExe --subjet --output="subjet_pthat85.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=85 PhaseSpace:pTHatMax=105
jettyDevanExe --subjet --output="subjet_pthat105.root" Beams:eCM=2760. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=105 PhaseSpace:pTHatMax=-1