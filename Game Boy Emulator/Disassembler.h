#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H

/* gbDisassembler
INPUTS: 
	char * fileName: name of Path & file to read
	char * logFile: name of path and & file to log to
OUTPUTS:
	int: 1 if sucessful read of gb file
		 0 if unsecessful read, error dumped to stdout FUNCTION:
	Attempts to open file in given path and dumps
	the hex instructions to a log file given. 
FUNCTION:
	Attempts to open file in given path and dumps
	the hex instructions to a log file given.
*/
int gbDisassembler(const char* fileName);


#endif