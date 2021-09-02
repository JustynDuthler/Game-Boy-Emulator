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
			int pc = 0;	/* program counter, in real gameboy pc starts at 0x0100 */
			while (pc < fileSize) {
				logFile << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc]) << ": ";
				switch (fileMem[pc]) {
					case 0x00: // NOP
						logFile << "NOP\n"; 
						pc++; 
						break;
					case 0x01: // LD BC, d16
						logFile << "LD BC, d16 -- d16 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 2]) << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 3; 
						break;
					case 0x02: // LD (BC), A
						logFile << "LD (BC), A\n"; 
						pc++;
						break;
					case 0x03: // INC BC
						logFile << "INC BC\n";
						pc++;
						break;
					case 0x04: // INC B
						logFile << "INC B\n"; 
						pc++;
						break;
					case 0x05: // DEC B
						logFile << "DEC B\n"; 
						pc++;
						break;
					case 0x06: // LD B, d8
						logFile << "LD B, d8\n"; 
						logFile << "LD BC, d16 -- d16 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x07: // RLCA 
						logFile << "RLCA\n"; 
						pc++;
						break;
					case 0x08: // LD (a16), SP
						logFile << "LD (a16), SP -- SP = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 2]) << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 3;
						break;
					case 0x09: // ADD HL, BC
						logFile << "ADD HL, BC\n"; 
						pc++;
						break;
					case 0x0A: // LD A, (BC)
						logFile << "LD A, (BC)\n"; 
						pc++;
						break;
					case 0x0B: // DEC BC
						logFile << "DEC BC\n"; 
						pc++;
						break;
					case 0x0C: // INC C
						logFile << "INC C\n";
						pc++;
						break;
					case 0x0D: // DEC C
						logFile << "DEC C\n";
						pc++;
						break;
					case 0x0E: // LD C, d8
						logFile << "LD C, d8 -- d8 = "<< std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n"; 
						pc += 2;
						break;
					case 0x0F: // RRCA
						logFile << "RRCA\n"; 
						pc++;
						break;

					case 0x10: // STOP
						logFile << "STOP\n"; 
						pc += 2;
						break;
					case 0x11: // LD DE, d16
						logFile << "LD DE, d16 -- d16 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 2]) << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 3;
						break;
					case 0x12: // LD (DE), A
						logFile << "LD (DE), A\n";
						pc++;
						break;
					case 0x13: // INC DE
						logFile << "INC DE\n"; 
						pc++;
						break;
					case 0x14: // INC D
						logFile << "INC D\n"; 
						pc++;
						break;
					case 0x15: // DEC D
						logFile << "DEC D\n"; 
						pc++;
						break;
					case 0x16: // LD D, d8
						logFile << "LD D, d8 -- d8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x17: // RLA 
						logFile << "RLA\n"; 
						pc++;
						break;
					case 0x18: // JR s8
						logFile << "JR s8 -- s8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x19: // ADD HL, DE
						logFile << "ADD HL, DE\n";
						pc++;
						break;
					case 0x1A: // LD A, (DE)
						logFile << "LD A, (DE)\n";
						pc++;
						break;
					case 0x1B: // DEC DE
						logFile << "DEC DE\n";
						pc++;
						break;
					case 0x1C: // INC E
						logFile << "INC E\n"; 
						pc++;
						break;
					case 0x1D: // DEC E
						logFile << "DEC E\n"; 
						pc++;
						break;
					case 0x1E: // LD E, d8
						logFile << "LD E, d8 -- d8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x1F: // RRA
						logFile << "RRA\n";
						pc++;
						break;

					case 0x20: // JR NZ, s8
						logFile << "JR NZ, s8 -- s8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x21: // LD HL, d16
						logFile << "LD HL, d16 -- d16 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 2]) << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 3;
						break;
					case 0x22: // LD (HL+), A
						logFile << "LD (HL+), A\n";
						pc++;
						break;
					case 0x23: // INC HL
						logFile << "INC HL\n";
						pc++;
						break;
					case 0x24: // INC H
						logFile << "INC H\n"; 
						pc++;
						break;
					case 0x25: // DEC H
						logFile << "DEC H\n";
						pc++;
						break;
					case 0x26: // LD H, d8
						logFile << "LD H, d8 -- d8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x27: // DAA 
						logFile << "DAA\n";
						pc++;
						break;
					case 0x28: // JR Z, s8
						logFile << "JR Z, s8 -- s8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x29: // ADD HL, HL
						logFile << "ADD HL, HL\n";
						pc++;
						break;
					case 0x2A: // LD A, (HL+)
						logFile << "LD A, (HL+)\n";
						pc++;
						break;
					case 0x2B: // DEC HL
						logFile << "DEC HL\n";
						pc++;
						break;
					case 0x2C: // INC L
						logFile << "INC L\n";
						pc++;
						break;
					case 0x2D: // DEC L
						logFile << "DEC L\n";
						pc++;
						break;
					case 0x2E: // LD L, d8
						logFile << "LD L, d8 -- d8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x2F: // CPL
						logFile << "CPL\n"; 
						pc++;
						break;
					
					case 0x30: // JR NC, s8
						logFile << "JR NC, s8 -- s8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x31: // LD SP, d16
						logFile << "LD SP, d16 -- d16 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 2]) << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 3;
						break;
					case 0x32: // LD (HL-), A
						logFile << "LD (HL-), A\n";
						pc++;
						break;
					case 0x33: // INC SP
						logFile << "INC HL\n";
						pc++;
						break;
					case 0x34: // INC (HL)
						logFile << "INC (HL)\n";
						pc++;
						break;
					case 0x35: // DEC (HL)
						logFile << "DEC (HL)\n";
						pc++;
						break;
					case 0x36: // LD (HL), d8
						logFile << "LD (HL), d8 -- d8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x37: // SCF 
						logFile << "SCF\n"; 
						pc++;
						break;
					case 0x38: // JR C, s8
						logFile << "JR C, s8 -- s8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x39: // ADD HL, SP
						logFile << "ADD HL, SP\n"; 
						pc++; 
						break;
					case 0x3A: // LD A, (HL-)
						logFile << "LD A, (HL-)\n";
						pc++;
						break;
					case 0x3B: // DEC SP
						logFile << "DEC SP\n";
						pc++;
						break;
					case 0x3C: // INC A
						logFile << "INC A\n";
						pc++;
						break;
					case 0x3D: // DEC A
						logFile << "DEC A\n"; 
						pc++;
						break;
					case 0x3E: // LD A, d8
						logFile << "LD A, d8 -- d8 = " << std::setfill('0') << std::setw(2) << std::hex << (0xff & fileMem[pc + 1]) << "\n";
						pc += 2;
						break;
					case 0x3F: // CCF
						logFile << "CCF\n"; 
						pc++;
						break;

					case 0x40: // LD B, B
						logFile << "LD B, B\n"; break;
					case 0x41: // LD B, C
						logFile << "LD B, C\n"; break;
					case 0x42: // LD B, D
						logFile << "LD B, D\n"; break;
					case 0x43: // LD B, E
						logFile << "LD B, E\n"; break;
					case 0x44: // LD B, H
						logFile << "LD B, H\n"; break;
					case 0x45: // LD B, L
						logFile << "LD B, L\n"; break;
					case 0x46: // LD B, (HL)
						logFile << "LD B, (HL)\n"; break;
					case 0x47: // LD B, A 
						logFile << "LD B, A\n"; break;
					case 0x48: // LD C, B
						logFile << "LD C, B\n"; break;
					case 0x49: // LD C, C
						logFile << "LD C, C\n"; break;
					case 0x4A: // LD C, D
						logFile << "LD C, D\n"; break;
					case 0x4B: // LD C, E
						logFile << "LD C, E\n"; break;
					case 0x4C: // LD C, H
						logFile << "LD C, H\n"; break;
					case 0x4D: // LD C, L
						logFile << "LD C, L\n"; break;
					case 0x4E: // LD C, (HL)
						logFile << "LD C, (HL)\n"; break;
					case 0x4F: // LD C, A
						logFile << "LD C, A\n"; break;

					case 0x50: // LD D, B
						logFile << "LD D, B\n"; break;
					case 0x51: // LD D, C
						logFile << "LD D, C\n"; break;
					case 0x52: // LD D, D
						logFile << "LD D, D\n"; break;
					case 0x53: // LD D, E
						logFile << "LD D, E\n"; break;
					case 0x54: // LD D, H
						logFile << "LD D, H\n"; break;
					case 0x55: // LD D, L
						logFile << "LD D, L\n"; break;
					case 0x56: // LD D, (HL)
						logFile << "LD D, (HL)\n"; break;
					case 0x57: // LD D, A 
						logFile << "LD D, A\n"; break;
					case 0x58: // LD E, B
						logFile << "LD E, B\n"; break;
					case 0x59: // LD E, C
						logFile << "LD E, C\n"; break;
					case 0x5A: // LD E, D
						logFile << "LD E, D\n"; break;
					case 0x5B: // LD E, E
						logFile << "LD E, E\n"; break;
					case 0x5C: // LD E, H
						logFile << "LD E, H\n"; break;
					case 0x5D: // LD E, L
						logFile << "LD E, L\n"; break;
					case 0x5E: // LD E, (HL)
						logFile << "LD E, (HL)\n"; break;
					case 0x5F: // LD E, A
						logFile << "LD E, A\n"; break;

					case 0x60: // LD H, B
						logFile << "LD H, B\n"; break;
					case 0x61: // LD H, C
						logFile << "LD H, C\n"; break;
					case 0x62: // LD H, D
						logFile << "LD H, D\n"; break;
					case 0x63: // LD H, E
						logFile << "LD H, E\n"; break;
					case 0x64: // LD H, H
						logFile << "LD H, H\n"; break;
					case 0x65: // LD H, L
						logFile << "LD H, L\n"; break;
					case 0x66: // LD H, (HL)
						logFile << "LD H, (HL)\n"; break;
					case 0x67: // LD H, A 
						logFile << "LD H, A\n"; break;
					case 0x68: // LD L, B
						logFile << "LD L, B\n"; break;
					case 0x69: // LD L, C
						logFile << "LD L, C\n"; break;
					case 0x6A: // LD L, D
						logFile << "LD L, D\n"; break;
					case 0x6B: // LD L, E
						logFile << "LD L, E\n"; break;
					case 0x6C: // LD L, H
						logFile << "LD L, H\n"; break;
					case 0x6D: // LD L, L
						logFile << "LD L, L\n"; break;
					case 0x6E: // LD L, (HL)
						logFile << "LD L, (HL)\n"; break;
					case 0x6F: // LD L, A
						logFile << "LD C, A\n"; break;
					
					case 0x70: // LD (HL), B
						logFile << "LD (HL), B\n"; break;
					case 0x71: // LD (HL), C
						logFile << "LD (HL), C\n"; break;
					case 0x72: // LD (HL), D
						logFile << "LD (HL), D\n"; break;
					case 0x73: // LD (HL), E
						logFile << "LD (HL), E\n"; break;
					case 0x74: // LD (HL), H
						logFile << "LD (HL), H\n"; break;
					case 0x75: // LD (HL), L
						logFile << "LD (HL), L\n"; break;
					case 0x76: // HALT
						logFile << "HALT\n"; break;
					case 0x77: // LD (HL), A 
						logFile << "LD (HL), A\n"; break;
					case 0x78: // LD A, B
						logFile << "LD A, B\n"; break;
					case 0x79: // LD A, C
						logFile << "LD A, C\n"; break;
					case 0x7A: // LD A, D
						logFile << "LD A, D\n"; break;
					case 0x7B: // LD A, E
						logFile << "LD A, E\n"; break;
					case 0x7C: // LD A, H
						logFile << "LD A, H\n"; break;
					case 0x7D: // LD A, L
						logFile << "LD A, L\n"; break;
					case 0x7E: // LD A, (HL)
						logFile << "LD A, (HL)\n"; break;
					case 0x7F: // LD A, A
						logFile << "LD C, A\n"; break;

					case 0x80: // ADD A, B
						logFile << "ADD A, B\n"; break;
					case 0x81: // ADD A, C
						logFile << "ADD A, C\n"; break;
					case 0x82: // ADD A, D
						logFile << "ADD A, D\n"; break;
					case 0x83: // ADD A, E
						logFile << "ADD A, E\n"; break;
					case 0x84: // ADD A, H
						logFile << "ADD A, H\n"; break;
					case 0x85: // ADD A, L
						logFile << "ADD A, L\n"; break;
					case 0x86: // ADD A, (HL)
						logFile << "ADD A, (HL)\n"; break;
					case 0x87: // ADD A, A 
						logFile << "ADD A, A\n"; break;
					case 0x88: // ADC A, B
						logFile << "ADC A, B\n"; break;
					case 0x89: // ADC A, C
						logFile << "ADC A, C\n"; break;
					case 0x8A: // ADC A, D
						logFile << "ADC A, D\n"; break;
					case 0x8B: // ADC A, E
						logFile << "ADC A, E\n"; break;
					case 0x8C: // ADC A, H
						logFile << "ADC A, H\n"; break;
					case 0x8D: // ADC A, L
						logFile << "ADC A, L\n"; break;
					case 0x8E: // ADC A, (HL)
						logFile << "ADC, (HL)\n"; break;
					case 0x8F: // ADC A, A
						logFile << "ADC, A\n"; break;

					case 0x90: // SUB B
						logFile << "SUB B\n"; break;
					case 0x91: // SUB C
						logFile << "SUB C\n"; break;
					case 0x92: // SUB D
						logFile << "SUB D\n"; break;
					case 0x93: // SUB E
						logFile << "SUB E\n"; break;
					case 0x94: // SUB H
						logFile << "SUB H\n"; break;
					case 0x95: // SUB L
						logFile << "SUB L\n"; break;
					case 0x96: // SUB (HL)
						logFile << "SUB (HL)\n"; break;
					case 0x97: // SUB A 
						logFile << "SUB A\n"; break;
					case 0x98: // SBC A, B
						logFile << "SBC A, B\n"; break;
					case 0x99: // SBC A, C
						logFile << "SBC A, C\n"; break;
					case 0x9A: // SBC A, D
						logFile << "SBC A, D\n"; break;
					case 0x9B: // SBC A, E
						logFile << "SBC A, E\n"; break;
					case 0x9C: // SBC A, H
						logFile << "SBC A, H\n"; break;
					case 0x9D: // SBC A, L
						logFile << "SBC A, L\n"; break;
					case 0x9E: // SBC A, (HL)
						logFile << "SBC A, (HL)\n"; break;
					case 0x9F: // SBC A, A
						logFile << "SBC A, A\n"; break;

					case 0xA0: // AND B
						logFile << "AND B\n"; break;
					case 0xA1: // AND C
						logFile << "AND C\n"; break;
					case 0xA2: // AND D
						logFile << "AND D\n"; break;
					case 0xA3: // AND E
						logFile << "AND E\n"; break;
					case 0xA4: // AND H
						logFile << "SUB H\n"; break;
					case 0xA5: // AND L
						logFile << "AND L\n"; break;
					case 0xA6: // AND (HL)
						logFile << "AND (HL)\n"; break;
					case 0xA7: // AND A 
						logFile << "AND A\n"; break;
					case 0xA8: // XOR B
						logFile << "XOR B\n"; break;
					case 0xA9: // XOR C
						logFile << "XOR C\n"; break;
					case 0xAA: // XOR D
						logFile << "XOR D\n"; break;
					case 0xAB: // XOR E
						logFile << "XOR E\n"; break;
					case 0xAC: // XOR H
						logFile << "XOR H\n"; break;
					case 0xAD: // XOR L
						logFile << "XOR L\n"; break;
					case 0xAE: // XOR (HL)
						logFile << "XOR (HL)\n"; break;
					case 0xAF: // XOR A
						logFile << "XOR A\n"; break;

					case 0xB0: // OR B
						logFile << "OR B\n"; break;
					case 0xB1: // OR C
						logFile << "OR C\n"; break;
					case 0xB2: // OR D
						logFile << "OR D\n"; break;
					case 0xB3: // OR E
						logFile << "OR E\n"; break;
					case 0xB4: // OR H
						logFile << "OR H\n"; break;
					case 0xB5: // OR L
						logFile << "OR L\n"; break;
					case 0xB6: // OR (HL)
						logFile << "OR (HL)\n"; break;
					case 0xB7: // OR A 
						logFile << "OR A\n"; break;
					case 0xB8: // CP B
						logFile << "CP B\n"; break;
					case 0xB9: // CP C
						logFile << "CP C\n"; break;
					case 0xBA: // CP D
						logFile << "CP D\n"; break;
					case 0xBB: // CP E
						logFile << "CP E\n"; break;
					case 0xBC: // CP H
						logFile << "CP H\n"; break;
					case 0xBD: // CP L
						logFile << "CP L\n"; break;
					case 0xBE: // CP (HL)
						logFile << "CP (HL)\n"; break;
					case 0xBF: // CP A
						logFile << "CP A\n"; break;

					case 0xC0: // RET NZ
						logFile << "RET NZ\n"; break;
					case 0xC1: // POP BC
						logFile << "POP BC\n"; break;
					case 0xC2: // JP NZ, a16
						logFile << "JP NZ, a16\n"; break;
					case 0xC3: // JP NZ, a16
						logFile << "JP NZ, a16\n"; break;
					case 0xC4: // CALL NZ, a16
						logFile << "CALL NZ, a16\n"; break;
					case 0xC5: // PUSH BC
						logFile << "PUSH BC\n"; break;
					case 0xC6: // ADD A, d8
						logFile << "ADD A, d8\n"; break;
					case 0xC7: // RST 0 
						logFile << "RST 0\n"; break;
					case 0xC8: // RET Z
						logFile << "RET Z\n"; break;
					case 0xC9: // RET
						logFile << "RET\n"; break;
					case 0xCA: // JP Z, a16
						logFile << "JP Z, a16\n"; break;
					case 0xCB: // 16-bit opcodes
						logFile << "16-bit opcodes\n"; break;
					case 0xCC: // CALL Z, a16
						logFile << "CALL Z, a16\n"; break;
					case 0xCD: // CALL a16
						logFile << "CALL a16\n"; break;
					case 0xCE: // ADC A, d8
						logFile << "ADC A, d8\n"; break;
					case 0xCF: // RST 1
						logFile << "RST 1\n"; break;

					case 0xD0: // RET NC
						logFile << "RET NC\n"; break;
					case 0xD1: // POP DE
						logFile << "POP DE\n"; break;
					case 0xD2: // JP NC, a16
						logFile << "JP NC, a16\n"; break;
					case 0xD3: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xD4: // CALL NC, a16
						logFile << "CALL NC, a16\n"; break;
					case 0xD5: // PUSH DE
						logFile << "PUSH DE\n"; break;
					case 0xD6: // SUB d8
						logFile << "SUB d8\n"; break;
					case 0xD7: // RST 2 
						logFile << "RST 2\n"; break;
					case 0xD8: // RET C
						logFile << "RET C\n"; break;
					case 0xD9: // RETI
						logFile << "RETI\n"; break;
					case 0xDA: // JP C, a16
						logFile << "JP C, a16\n"; break;
					case 0xDB: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xDC: // CALL C, a16
						logFile << "CALL C, a16\n"; break;
					case 0xDD: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xDE: // SBC A, d8
						logFile << "SBC A, d8\n"; break;
					case 0xDF: // RST 3
						logFile << "RST 3\n"; break;

					case 0xE0: // LD (a8), A
						logFile << "LD (a8), A\n"; break;
					case 0xE1: // POP HL
						logFile << "POP HL\n"; break;
					case 0xE2: // LD (C), A
						logFile << "LD (C), A\n"; break;
					case 0xE3: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xE4: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xE5: // PUSH HL
						logFile << "PUSH HL\n"; break;
					case 0xE6: // AND d8
						logFile << "AND d8\n"; break;
					case 0xE7: // RST 4 
						logFile << "RST 4\n"; break;
					case 0xE8: // ADD SP, s8
						logFile << "ADD SP, s8\n"; break;
					case 0xE9: // JP HL
						logFile << "JP HL\n"; break;
					case 0xEA: // LD (a16), A
						logFile << "LD (a16), A\n"; break;
					case 0xEB: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xEC: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xED: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xEE: // XOR d8
						logFile << "XOR d8\n"; break;
					case 0xEF: // RST 5
						logFile << "RST 5\n"; break;

					case 0xF0: // LD A, (a8)
						logFile << "LD A, (a8)\n"; break;
					case 0xF1: // POP AF
						logFile << "POP AF\n"; break;
					case 0xF2: // LD A, (C)
						logFile << "LD A, (C)\n"; break;
					case 0xF3: // DI
						logFile << "DI\n"; break;
					case 0xF4: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xF5: // PUSH AF
						logFile << "PUSH AF\n"; break;
					case 0xF6: // OR d8
						logFile << "OR d8\n"; break;
					case 0xF7: // RST 6 
						logFile << "RST 6\n"; break;
					case 0xF8: // LD HL, SP+s8
						logFile << "LD HL, SP+s8\n"; break;
					case 0xF9: // LD SP, HL
						logFile << "LD SP. HL\n"; break;
					case 0xFA: // LD A, (a16)
						logFile << "LD A, (a16)\n"; break;
					case 0xFB: // EI
						logFile << "EI\n"; break;
					case 0xFC: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xFD: // NO CODE
						logFile << "NO CODE\n"; break;
					case 0xFE: // CP d8
						logFile << "CP d8\n"; break;
					case 0xFF: // RST 7
						logFile << "RST 7\n"; break;

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


