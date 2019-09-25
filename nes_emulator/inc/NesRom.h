/* 
Author: Aaron Cox
Description:
	NesRom.h file used to load in .nes rom files.
	Information about the .nes rom format can be located here: http://fms.komkon.org/EMUL8/NES.html#LABM

	currently a work in progress, i am yet to understand the format, and define good naming conventions
*/


#pragma once

#include "NesMemory.h"

#pragma pack(push, 1)
struct NesRomFileHeader
{
public:
	char ext[4];							// string 4 bytes - "NES^Z" used to recognise .nes files
	uint8_t num16kbRomBanks;				// number of 16kb ROM banks
	uint8_t num8kbVRomBanks;				// number of 8kb VRom banks
	
	struct
	{
		uint8_t mirroringModeBit : 1;		// 1 for vertical mirroring, 0 for horizontal mirroring.
		uint8_t batteryBackedRamBit : 1;	// 1 for battery-backed RAM at $6000-$7FFF.
		uint8_t trainerBit : 1;				// 1 for a 512-byte trainer at $7000-$71FF.
		uint8_t vramLayoutBit : 1;			// 1 for a four-screen VRAM layout.
		uint8_t loMapperType : 4;			// Four lower bits of ROM Mapper Type.
		//------------------
		uint8_t vsSystemCartridges : 1;		// 1 for VS - System cartridges.
		uint8_t : 3;						// *un-named variable* - 3 Reserved bits, must be zeroes!
		uint8_t hi_mapper_type : 4;			// Four higher bits of ROM Mapper Type
	};
	
	uint8_t num8kbRamBanks;					// Number of 8kB RAM banks. 
											// For compatibility with the previous versions of the .NES format, 
											// assume 1x8kB RAM page when this byte is zero.

	struct
	{
		uint8_t isPALVideoMode : 1;
		uint8_t : 7;						// *un-named variable* - 7 reservedBits must be zeros
	};

	uint8_t reservedBytes[5];				// 5 reserved Bytes - must be zeros

};
#pragma pack(pop)


class NesCartridge
{
public:
	NesCartridge();
	~NesCartridge();

	void LoadFromFile(const char *filename);
	void LoadFromBytes(uint8_t *data, unsigned int length);

	uint8_t GetRomBankCount() { return m_data->num16kbRomBanks; }
	const RomBankMem *GetRomBanks() { return ROM_Banks; }

protected:

	// pointer to raw file data in the .nes file format
	uint8_t			*m_rawRomData;
	long			 m_rawRomDataLength;

	// rom file header, should overlay first 15bytes of m_rawRomData
	NesRomFileHeader	*m_data;

	// pointers to approprate locations within the m_rawRomData format.
	TrainerMem *trainer = nullptr;
	RomBankMem *ROM_Banks = nullptr;
	VRomBankMem *VROM_Banks = nullptr;

	

	

private:
};