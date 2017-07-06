#include <util/args.h>
#include "run_pythia.h"
#include "run_rose.h"

int main ( int argc, char *argv[] )
{
	int rv = 0;

    SysUtil::Args args(argc, argv);

    if (args.isSet("--pythia"))
    {
    	rv = run_pythia(args.asString());
    }

    if (args.isSet("--rose"))
    {
    	rv = run_rose(args.asString());
    }

    return rv;
}
