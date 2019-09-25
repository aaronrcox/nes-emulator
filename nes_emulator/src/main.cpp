
#include <iostream>
#include <string>

#include "NesRom.h"
#include "Mos6502CPU.h"

std::string RomFileFromCmdLineArgs(int argc, char **argv, const char *fallbackFilename);

//=============================================================================
// Program Entry point
//=============================================================================
int main(int argc, char **argv)
{
	// detect rom to load from command line arguments
	// or use default filename
	std::string romFile = RomFileFromCmdLineArgs(argc, argv, "assets\\roms\\helloWorld\\hello.nes");

	// load rom carterage from file
	NesCartridge rom;
	rom.LoadFromFile(romFile.c_str());

	// Load CPU
	Mos6502CPU cpu;
	cpu.SetRomData(rom.GetRomBanks(), rom.GetRomBankCount());

	// Print CPU Instructions to console window.
	cpu.PrintProgram();

	system("pause");
	return 0;
}








std::string RomFileFromCmdLineArgs(int argc, char **argv, const char *fallbackFilename)
{
	// loop through command line arguments
	for (int i = 0; i < argc; i++)
	{
		// extract filename and file extension
		std::string arg = argv[i];
		std::string ext = arg.substr(arg.length() - 4, 4);

		// if one of the comandline args has the last 4 characters of .nes
		// than return that parameter as the file to load
		if (ext == ".nes")
			return arg;
	}

	// if we get here, return the fallback filename.
	return fallbackFilename;
}