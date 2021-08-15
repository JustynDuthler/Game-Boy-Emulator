// Disassembler.cpp 
#include <iostream>
#include <fstream>
#include <iomanip>

int gbDisassembler(const char* fileName) {
	// open file with binary flag and ate flag to be at end of file
	std::ifstream gbFile (fileName, std::ios::binary | std::ios::ate);
	if (gbFile.is_open()) { 
		// tellg() points to end of file or file size
		std::streampos fileSize = gbFile.std::istream::tellg();
		std::cout << "File " << fileName << "Size: " << fileSize << "\n";
		// allocate and write entire file into memory
		unsigned char* fileMem = new unsigned char[fileSize];
		gbFile.seekg(0, std::ios::beg);
		gbFile.read((char*)fileMem, fileSize);
		gbFile.close();
		// output memory into log file, trunc is called to clear any previous log
		std::ofstream logFile("C:\\Users\\Justyn Duthler\\Desktop\\Game-Boy-Emulator\\logs\\disassemblerLog.txt", std::fstream::out | std::fstream::trunc);
		if (logFile.is_open()) {
			for (int i = 0; i < fileSize; i+=1) {
				logFile << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[i]) << ": ";
				switch (fileMem[i]) {
					case 0x00: // NOP
						logFile << "NOP\n"; break;
					case 0x01: // LD BC, d16
						logFile << "LD BC, d16\n"; break;
					case 0x02: // LD (BC), A
						logFile << "LD (BC), A\n"; break;
					case 0x03: // INC BC
						logFile << "INC BC\n"; break;
					case 0x04: // INC B
						logFile << "INC B\n"; break;
					case 0x05: // DEC B
						logFile << "DEC B\n"; break;
					case 0x06: // LD B, d8
						logFile << "LD B, d8\n"; break;
					case 0x07: // RLCA 
						logFile << "RLCA\n"; break;
					case 0x08: // LD (a16), SP
						logFile << "LD (a16), SP\n"; break;
					case 0x09: // ADD HL, BC
						logFile << "ADD HL, BC\n"; break;
					case 0x0A: // LD A, (BC)
						logFile << "LD A, (BC)\n"; break;
					case 0x0B: // DEC BC
						logFile << "DEC BC\n"; break;
					case 0x0C: // INC C
						logFile << "INC C\n"; break;
					case 0x0D: // DEC C
						logFile << "DEC C\n"; break;
					case 0x0E: // LD C, d8
						logFile << "LD C, d8\n"; break;
					case 0x0F: // RRCA
						logFile << "RRCA\n"; break;
					case 0xc3: // JP NZ, a16
						logFile << "JP NZ, a16\n"; break;
					default:
						logFile << "\n"; break;
				}
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


