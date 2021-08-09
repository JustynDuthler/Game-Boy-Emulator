// Disassembler.cpp 
#include <iostream>
#include <fstream>
#include <iomanip>
/* gbDisassembler
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
		gbFile.close();
		// output memory into log file, trunc is called to clear any previous log
		std::ofstream logFile("C:\\Users\\Justyn Duthler\\Desktop\\Game-Boy-Emulator\\logs\\disassemblerLog.txt", std::fstream::out | std::fstream::trunc);
		if (logFile.is_open()) {
			for (int i = 0; i < fileSize; i+=4) {
				logFile << std::setfill('0') << std::setw(2) << std::hex << (0xff & (int)fileMem[i]) << " " <<
					std::setfill('0') << std::setw(2) << std::hex << (0xff & (int)fileMem[i + 1]) << " " <<
					std::setfill('0') << std::setw(2) << std::hex << (0xff & (int)fileMem[i + 2]) << " " <<
					std::setfill('0') << std::setw(2) << std::hex << (0xff & (int)fileMem[i + 3]) << "\n";
			}
		} else {
			std::cout << "Cannot open log file\n";
			return 0;
		}
		logFile.close();
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
