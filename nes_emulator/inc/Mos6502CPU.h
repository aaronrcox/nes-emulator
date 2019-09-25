#pragma once


#include "NesMemory.h"

class Mos6502CPU
{
public:

	Mos6502CPU();
	~Mos6502CPU();

	void SetRomData(const RomBankMem *romMemory, uint8_t numRomBanks);

	// Processes a single instruction and increments the Program Counter
	void Tick();

	void PrintProgram();

protected:

	// pointer to rom banks - this is where the cpu instructions are fetched from.
	const RomBankMem *m_rom;
	uint8_t m_numRomBanks;

	uint16_t PC;	// Program Counter
	uint8_t SP;		// stack pointer
	uint8_t A;		// A Register
	uint8_t X;		// X Register
	uint8_t Y;		// Y Register

	// Status Register
	// http://www.obelisk.me.uk/6502/registers.html - Processor Status
	// http://nesdev.com/6502.txt - THE STATUS REGISTER

	union
	{
		struct
		{
			uint8_t carryFlag		: 1;
			uint8_t zeroFlag		: 1;
			uint8_t interruptFlag	: 1;
			uint8_t decimalFlag		: 1;
			uint8_t breakFlag		: 1;
			uint8_t					: 1; // (un-named) bit not used
			uint8_t overflowFlag	: 1;
			uint8_t negativeFlag	: 1;
		};

		struct
		{
			uint8_t C	: 1;
			uint8_t Z	: 1;
			uint8_t I	: 1;
			uint8_t D	: 1;
			uint8_t B	: 1;
			uint8_t		: 1;   // (un-named) bit not used?
			uint8_t V	: 1;
			uint8_t N	: 1;
		};
	} SR;
	

private:
};