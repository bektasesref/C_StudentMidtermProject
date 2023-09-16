#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "types.h" // Type Struct definitons stored in this header
#include "file_io.h"// File (database) input output communication handled by this
#include "util.h" // common extension & useful methods/functions etcetra
#include "ui.h" // All the stuff releated to UI like geting inputs, visualizing texts...

int main(int argc, char** argv) 
{
	if(!CheckIfDatabaseExists())
        CreateDatabase();
	
	PrintWelcomeScreenSelections();
	SetSelection(GetSelection());
	
	return 1;
}
