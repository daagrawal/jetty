#!/bin/bash

jettyDevanExe --background --output="background.root" --config="~/lbnl/jetty/config/" Beams:eCM=13000. Main:numberOfEvents=1000 PhaseSpace:pTHatMin=90 PhaseSpace:pTHatMax=110
