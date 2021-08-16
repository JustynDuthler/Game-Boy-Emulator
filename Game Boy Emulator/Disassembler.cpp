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

					case 0x10: // STOP
						logFile << "STOP\n"; break;
					case 0x11: // LD DE, d16
						logFile << "LD DE, d16\n"; break;
					case 0x12: // LD (DE), A
						logFile << "LD (DE), A\n"; break;
					case 0x13: // INC DE
						logFile << "INC DE\n"; break;
					case 0x14: // INC D
						logFile << "INC D\n"; break;
					case 0x15: // DEC D
						logFile << "DEC D\n"; break;
					case 0x16: // LD D, d8
						logFile << "LD D, d8\n"; break;
					case 0x17: // RLA 
						logFile << "RLA\n"; break;
					case 0x18: // JR s8
						logFile << "JR s8\n"; break;
					case 0x19: // ADD HL, DE
						logFile << "ADD HL, DE\n"; break;
					case 0x1A: // LD A, (DE)
						logFile << "LD A, (DE)\n"; break;
					case 0x1B: // DEC DE
						logFile << "DEC DE\n"; break;
					case 0x1C: // INC E
						logFile << "INC E\n"; break;
					case 0x1D: // DEC E
						logFile << "DEC E\n"; break;
					case 0x1E: // LD E, d8
						logFile << "LD E, d8\n"; break;
					case 0x1F: // RRA
						logFile << "RRA\n"; break;

					case 0x20: // JR NZ, s8
						logFile << "JR NZ, s8\n"; break;
					case 0x21: // LD HL, d16
						logFile << "LD HL, d16\n"; break;
					case 0x22: // LD (HL+), A
						logFile << "LD (HL+), A\n"; break;
					case 0x23: // INC HL
						logFile << "INC HL\n"; break;
					case 0x24: // INC H
						logFile << "INC H\n"; break;
					case 0x25: // DEC H
						logFile << "DEC H\n"; break;
					case 0x26: // LD H, d8
						logFile << "LD H, d8\n"; break;
					case 0x27: // DAA 
						logFile << "DAA\n"; break;
					case 0x28: // JR Z, s8
						logFile << "JR Z, s8\n"; break;
					case 0x29: // ADD HL, HL
						logFile << "ADD HL, HL\n"; break;
					case 0x2A: // LD A, (HL+)
						logFile << "LD A, (HL+)\n"; break;
					case 0x2B: // DEC HL
						logFile << "DEC HL\n"; break;
					case 0x2C: // INC L
						logFile << "INC L\n"; break;
					case 0x2D: // DEC L
						logFile << "DEC L\n"; break;
					case 0x2E: // LD L, d8
						logFile << "LD L, d8\n"; break;
					case 0x2F: // CPL
						logFile << "CPL\n"; break;
					
					case 0x30: // JR NC, s8
						logFile << "JR NC, s8\n"; break;
					case 0x31: // LD SP, d16
						logFile << "LD SP, d16\n"; break;
					case 0x32: // LD (HL-), A
						logFile << "LD (HL-), A\n"; break;
					case 0x33: // INC SP
						logFile << "INC HL\n"; break;
					case 0x34: // INC (HL)
						logFile << "INC (HL)\n"; break;
					case 0x35: // DEC (HL)
						logFile << "DEC (HL)\n"; break;
					case 0x36: // LD (HL), d8
						logFile << "LD (HL), d8\n"; break;
					case 0x37: // SCF 
						logFile << "SCF\n"; break;
					case 0x38: // JR C, s8
						logFile << "JR C, s8\n"; break;
					case 0x39: // ADD HL, SP
						logFile << "ADD HL, SP\n"; break;
					case 0x3A: // LD A, (HL-)
						logFile << "LD A, (HL-)\n"; break;
					case 0x3B: // DEC SP
						logFile << "DEC SP\n"; break;
					case 0x3C: // INC A
						logFile << "INC A\n"; break;
					case 0x3D: // DEC A
						logFile << "DEC A\n"; break;
					case 0x3E: // LD A, d8
						logFile << "LD A, d8\n"; break;
					case 0x3F: // CCF
						logFile << "CCF\n"; break;
					
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


