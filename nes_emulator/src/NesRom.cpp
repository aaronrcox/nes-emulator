#include "NesRom.h"
#include <stdio.h>
#include <stddef.h>     /* offsetof */
#include <iostream>

NesCartridge::NesCartridge()
{

}

NesCartridge::~NesCartridge()
{

}

void NesCartridge::LoadFromFile(const char *filename)
{
	// open file in "read binary" mode
	FILE *file = fopen(filename, "rb");
	
	// get the size in bytes of the file
	fseek(file, 0, SEEK_END);
	long filesize = ftell(file);
	fseek(file, 0, SEEK_SET);

	// allocate memory for the file to be loaded into
	uint8_t *buffer = new uint8_t[filesize];
	
	// read the file into memory then close
	fread(buffer, 1, filesize, file);
	fclose(file);
	
	// continue parsing the file
	LoadFromBytes(buffer, filesize);
}

void NesCartridge::LoadFromBytes(uint8_t *data, unsigned int length)
{
	m_rawRomData = data;
	m_rawRomDataLength = length;

	// the first 15 bytes should overlay the data passed in perfectly
	// the trainer, rom banks and vrom banks vary in number and are set to point
	// at the approprate location within the data.
	std::cout << sizeof(NesRomFileHeader) << std::endl;
	m_data = (NesRomFileHeader *)m_rawRomData;
	trainer = nullptr;
	ROM_Banks = nullptr;
	VROM_Banks = nullptr;

	// address to the 16th byte
	uint8_t *nextMemoryLoc = (m_rawRomData + 16);

	if (m_data->trainerBit == 1)
	{
		trainer = (TrainerMem*)nextMemoryLoc;
		nextMemoryLoc = (uint8_t *)(trainer + 1);
	}

	ROM_Banks = (RomBankMem *)nextMemoryLoc;
	nextMemoryLoc = (uint8_t *)(ROM_Banks + m_data->num16kbRomBanks);

	VROM_Banks = (VRomBankMem *)nextMemoryLoc;
	nextMemoryLoc = (uint8_t *)(VROM_Banks + m_data->num8kbVRomBanks);
}
