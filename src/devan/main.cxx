#include <util/args.h>
#include "run_pythia.h"
#include "run_paper.h"
#include "run_jetfinding.h"
#include "run_subjet.h"
#include "run_background.h"

int main ( int argc, char *argv[] )
{
	int rv = 0;

    SysUtil::Args args(argc, argv);

    if (args.isSet("--pythia"))
    {
    	rv = run_pythia(args.asString());
    }

    if (args.isSet("--paper"))
    {
    	rv = run_paper(args.asString());
    }

    if (args.isSet("--jetfinding"))
    {
        rv = run_jetfinding(args.asString());
    }

    if (args.isSet("--subjet"))
    {
        rv = run_subjet(args.asString());
    }
    if (args.isSet("--background"))
    {
        rv = run_background(args.asString());
    }

    return rv;
}
