
#pragma once

#include <stdint.h>


#pragma pack(push, 1)

	template<int size>
	struct Memory
	{
		uint8_t data[size];
	};

#pragma pack(pop)

typedef Memory<16384> RomBankMem;
typedef Memory<8192> VRomBankMem;
typedef Memory<512> TrainerMem;

