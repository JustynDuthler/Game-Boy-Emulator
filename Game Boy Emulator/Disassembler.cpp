// Disassembler.cpp 

#include <iostream>
#include <fstream>
/************************** gbDisassembler *************************
INPUTS: 
	char * fileName: name of Path & file to read
	char * logFile: name of path and & file to log to
OUTPUTS:
	int: 1 if sucessful read of gb file
		 0 if unsecessful read, error dumped to stdout 
FUNCTION:
	Attempts to open file in given path and dumps
	the hex instructions to a log file given. 
*/

int gbDisassembler(const char* fileName) {
	// open file with binary flag and ate flag to be at end of file
	std::ifstream gbFile (fileName, std::ios::binary | std::ios::ate);
	if (gbFile.is_open()) { 
		// tellg() points to end of file or file size
		std::streampos fileSize = gbFile.std::istream::tellg();
		std::cout << "File " << fileName << "Size: " << fileSize << "\n";
		// allocate and write entire file into memory
		char* fileMem = new char[fileSize];
		gbFile.seekg(0, std::ios::beg);
		gbFile.read(fileMem, fileSize);
		// output memory into log file, trunc is called to clear any previous log
		std::fstream logFile("C:\\Users\\Justyn Duthler\\Desktop\\Game-Boy-Emulator\\logs\\disassemblerLog.txt", std::fstream::out | std::fstream::trunc);
		if (logFile.is_open()) {
			logFile.write(fileMem, fileSize);
		} else {
			std::cout << "Cannot open log file\n";
			return 0;
		}

		gbFile.close();

		return 1;

	} else {
		std::cout << "Cannot open file " << fileName << "\n";
		return 0;
	}

}

int main()
{
	const char* tetrisPath = "C:\\Users\\Justyn Duthler\\Desktop\\Game-Boy-Emulator\\Roms\\Tetris.gb";
	if (gbDisassembler(tetrisPath)) {
		return 0;
	} else {
		return 1;
	}
}
