#include "Mos6502CPU.h"
#include <iostream>

Mos6502CPU::Mos6502CPU()
{

}

Mos6502CPU::~Mos6502CPU()
{

}


void Mos6502CPU::SetRomData(const RomBankMem *romMemory, uint8_t numRomBanks)
{
	m_rom = romMemory;
	m_numRomBanks = numRomBanks;
}

void Mos6502CPU::Tick()
{
	uint8_t opCode = m_rom->data[PC];
	
	// Instruction Set References:
	// http://www.obelisk.me.uk/6502/reference.html
	// http://www.6502.org/tutorials/6502opcodes.html
	// http://e-tradition.net/bytes/6502/6502_instruction_set.html (best)

	switch (opCode)
	{	
	// ADC  Add Memory to Accumulator with Carry
	// 
	//      A + M + C -> A, C                N Z C I D V
	//                                       + + + - - +
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     ADC #oper     69    2     2
	//      zeropage      ADC oper      65    2     3
	//      zeropage,X    ADC oper,X    75    2     4
	//      absolute      ADC oper      6D    3     4
	//      absolute,X    ADC oper,X    7D    3     4*
	//      absolute,Y    ADC oper,Y    79    3     4*
	//      (indirect,X)  ADC (oper,X)  61    2     6
	//      (indirect),Y  ADC (oper),Y  71    2     5*

	case 0x69: break;
	case 0x65: break;
	case 0x75: break;
	case 0x6D: break;
	case 0x7D: break;
	case 0x79: break;
	case 0x61: break;
	case 0x71: break;

	
	// AND  AND Memory with Accumulator
	// 
	//      A AND M -> A                     N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     AND #oper     29    2     2
	//      zeropage      AND oper      25    2     3
	//      zeropage,X    AND oper,X    35    2     4
	//      absolute      AND oper      2D    3     4
	//      absolute,X    AND oper,X    3D    3     4*
	//      absolute,Y    AND oper,Y    39    3     4*
	//      (indirect,X)  AND (oper,X)  21    2     6
	//      (indirect),Y  AND (oper),Y  31    2     5*
	

	case 0x29: break;
	case 0x25: break;
	case 0x35: break;
	case 0x2D: break;
	case 0x3D: break;
	case 0x39: break;
	case 0x21: break;
	case 0x31: break;

	
	// ASL  Shift Left One Bit (Memory or Accumulator)
	// 
	//      C <- [76543210] <- 0             N Z C I D V
	//                                       + + + - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      accumulator   ASL A         0A    1     2
	//      zeropage      ASL oper      06    2     5
	//      zeropage,X    ASL oper,X    16    2     6
	//      absolute      ASL oper      0E    3     6
	//      absolute,X    ASL oper,X    1E    3     7


	case 0x0A: break;
	case 0x06: break;
	case 0x16: break;
	case 0x0E: break;
	case 0x1E: break;


	// BCC  Branch on Carry Clear
	// 
	//      branch on C = 0                  N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      relative      BCC oper      90    2     2**


	case 0x90: break;


	// BCS  Branch on Carry Set
	// 
	//      branch on C = 1                  N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      relative      BCS oper      B0    2     2**

	case 0xB0: break;

	// BEQ  Branch on Result Zero
	// 
	//      branch on Z = 1                  N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      relative      BEQ oper      F0    2     2**
	

	case 0xF0: break;


	// BIT  Test Bits in Memory with Accumulator
	// 
	//      bits 7 and 6 of operand are transfered to bit 7 and 6 of SR (N,V);
	//      the zeroflag is set to the result of operand AND accumulator.
	// 
	//      A AND M, M7 -> N, M6 -> V        N Z C I D V
	//                                      M7 + - - - M6
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      zeropage      BIT oper      24    2     3
	//      absolute      BIT oper      2C    3     4
	

	case 0x24: break;
	case 0x2C: break;


	// BMI  Branch on Result Minus
	// 
	//      branch on N = 1                  N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      relative      BMI oper      30    2     2**
	

	case 0x30: break;


	// BNE  Branch on Result not Zero
	// 
	//      branch on Z = 0                  N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      relative      BNE oper      D0    2     2**
	

	case 0xD0: break;

	// BPL  Branch on Result Plus
	// 
	//      branch on N = 0                  N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      relative      BPL oper      10    2     2**
	

	case 0x10: break;


	// BRK  Force Break
	// 
	//      interrupt,                       N Z C I D V
	//      push PC+2, push SR               - - - 1 - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       BRK           00    1     7
	

	case 0x00: break;


	// BVC  Branch on Overflow Clear
	// 
	//      branch on V = 0                  N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      relative      BVC oper      50    2     2**
	

	case 0x50: break;


	// BVS  Branch on Overflow Set
	// 
	//      branch on V = 1                  N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      relative      BVC oper      70    2     2**
	

	case 0x70: break;


	// CLC  Clear Carry Flag
	// 
	//      0 -> C                           N Z C I D V
	//                                       - - 0 - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       CLC           18    1     2
	

	case 0x18: break;


	// CLD  Clear Decimal Mode
	// 
	//      0 -> D                           N Z C I D V
	//                                       - - - - 0 -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       CLD           D8    1     2
	

	case 0xD8: break;


	// CLI  Clear Interrupt Disable Bit
	// 
	//      0 -> I                           N Z C I D V
	//                                       - - - 0 - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       CLI           58    1     2
	

	case 0x58: break;


	// CLV  Clear Overflow Flag
	// 
	//      0 -> V                           N Z C I D V
	//                                       - - - - - 0
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       CLV           B8    1     2
	

	case 0xB8: break;

	// CMP  Compare Memory with Accumulator
	// 
	//      A - M                            N Z C I D V
	//                                     + + + - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     CMP #oper     C9    2     2
	//      zeropage      CMP oper      C5    2     3
	//      zeropage,X    CMP oper,X    D5    2     4
	//      absolute      CMP oper      CD    3     4
	//      absolute,X    CMP oper,X    DD    3     4*
	//      absolute,Y    CMP oper,Y    D9    3     4*
	//      (indirect,X)  CMP (oper,X)  C1    2     6
	//      (indirect),Y  CMP (oper),Y  D1    2     5*
	

	case 0xC9: break;
	case 0xC5: break;
	case 0xD5: break;
	case 0xCD: break;
	case 0xDD: break;
	case 0xD9: break;
	case 0xC1: break;
	case 0xD1: break;


	// CPX  Compare Memory and Index X
	// 
	//      X - M                            N Z C I D V
	//                                       + + + - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     CPX #oper     E0    2     2
	//      zeropage      CPX oper      E4    2     3
	//      absolute      CPX oper      EC    3     4
	

	case 0xE0: break;
	case 0xE4: break;
	case 0xEC: break;


	// CPY  Compare Memory and Index Y
	// 
	//      Y - M                            N Z C I D V
	//                                       + + + - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     CPY #oper     C0    2     2
	//      zeropage      CPY oper      C4    2     3
	//      absolute      CPY oper      CC    3     4
	

	case 0xC0: break;
	case 0xC4: break;
	case 0xCC: break;


	// DEC  Decrement Memory by One
	// 
	//      M - 1 -> M                       N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      zeropage      DEC oper      C6    2     5
	//      zeropage,X    DEC oper,X    D6    2     6
	//      absolute      DEC oper      CE    3     3
	//      absolute,X    DEC oper,X    DE    3     7
	

	case 0xC6: break;
	case 0xD6: break;
	case 0xCE: break;
	case 0xDE: break;


	// DEX  Decrement Index X by One
	// 
	//      X - 1 -> X                       N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       DEC           CA    1     2
	

	case 0xCA: break;


	// DEY  Decrement Index Y by One
	// 
	//      Y - 1 -> Y                       N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       DEC           88    1     2
	
	case 0x88: break;

	// EOR  Exclusive-OR Memory with Accumulator
	// 
	//      A EOR M -> A                     N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     EOR #oper     49    2     2
	//      zeropage      EOR oper      45    2     3
	//      zeropage,X    EOR oper,X    55    2     4
	//      absolute      EOR oper      4D    3     4
	//      absolute,X    EOR oper,X    5D    3     4*
	//      absolute,Y    EOR oper,Y    59    3     4*
	//      (indirect,X)  EOR (oper,X)  41    2     6
	//      (indirect),Y  EOR (oper),Y  51    2     5*
	

	case 0x49: break;
	case 0x45: break;
	case 0x55: break;
	case 0x4D: break;
	case 0x5D: break;
	case 0x59: break;
	case 0x41: break;
	case 0x51: break;


	// INC  Increment Memory by One
	// 
	//      M + 1 -> M                       N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      zeropage      INC oper      E6    2     5
	//      zeropage,X    INC oper,X    F6    2     6
	//      absolute      INC oper      EE    3     6
	//      absolute,X    INC oper,X    FE    3     7
	

	case 0xE6: break;
	case 0xF6: break;
	case 0xEE: break;
	case 0xFE: break;


	// INX  Increment Index X by One
	// 
	//      X + 1 -> X                       N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       INX           E8    1     2
	

	case 0xE8: break;


	// INY  Increment Index Y by One
	// 
	//      Y + 1 -> Y                       N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       INY           C8    1     2
	

	case 0xC8: break;


	// JMP  Jump to New Location
	// 
	//      (PC+1) -> PCL                    N Z C I D V
	//      (PC+2) -> PCH                    - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      absolute      JMP oper      4C    3     3
	//      indirect      JMP (oper)    6C    3     5
	

	case 0x4C: break;
	case 0x6C: break;


	// JSR  Jump to New Location Saving Return Address
	// 
	//      push (PC+2),                     N Z C I D V
	//      (PC+1) -> PCL                    - - - - - -
	//      (PC+2) -> PCH
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      absolute      JSR oper      20    3     6
	

	case 0x20: break;


	// LDA  Load Accumulator with Memory
	// 
	//      M -> A                           N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     LDA #oper     A9    2     2
	//      zeropage      LDA oper      A5    2     3
	//      zeropage,X    LDA oper,X    B5    2     4
	//      absolute      LDA oper      AD    3     4
	//      absolute,X    LDA oper,X    BD    3     4*
	//      absolute,Y    LDA oper,Y    B9    3     4*
	//      (indirect,X)  LDA (oper,X)  A1    2     6
	//      (indirect),Y  LDA (oper),Y  B1    2     5*


	case 0xA9: break;
	case 0xA5: break;
	case 0xB5: break;
	case 0xAD: break;
	case 0xBD: break;
	case 0xB9: break;
	case 0xA1: break;
	case 0xB1: break;


	// LDX  Load Index X with Memory
	// 
	//      M -> X                           N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     LDX #oper     A2    2     2
	//      zeropage      LDX oper      A6    2     3
	//      zeropage,Y    LDX oper,Y    B6    2     4
	//      absolute      LDX oper      AE    3     4
	//      absolute,Y    LDX oper,Y    BE    3     4*
	
	case 0xA2: break;
	case 0xA6: break;
	case 0xB6: break;
	case 0xAE: break;
	case 0xBE: break;

	// LDY  Load Index Y with Memory
	// 
	//      M -> Y                           N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     LDY #oper     A0    2     2
	//      zeropage      LDY oper      A4    2     3
	//      zeropage,X    LDY oper,X    B4    2     4
	//      absolute      LDY oper      AC    3     4
	//      absolute,X    LDY oper,X    BC    3     4*
	

	case 0xA0: break;
	case 0xA4: break;
	case 0xB4: break;
	case 0xAC: break;
	case 0xBC: break;

	
	// LSR  Shift One Bit Right (Memory or Accumulator)
	// 
	//      0 -> [76543210] -> C             N Z C I D V
	//                                       - + + - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      accumulator   LSR A         4A    1     2
	//      zeropage      LSR oper      46    2     5
	//      zeropage,X    LSR oper,X    56    2     6
	//      absolute      LSR oper      4E    3     6
	//      absolute,X    LSR oper,X    5E    3     7
	

	case 0x4A: break;
	case 0x46: break;
	case 0x56: break;
	case 0x4E: break;
	case 0x5E: break;


	// NOP  No Operation
	// 
	//      ---                              N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       NOP           EA    1     2
	

	case 0xEA: break;


	// ORA  OR Memory with Accumulator
	// 
	//      A OR M -> A                      N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     ORA #oper     09    2     2
	//      zeropage      ORA oper      05    2     3
	//      zeropage,X    ORA oper,X    15    2     4
	//      absolute      ORA oper      0D    3     4
	//      absolute,X    ORA oper,X    1D    3     4*
	//      absolute,Y    ORA oper,Y    19    3     4*
	//      (indirect,X)  ORA (oper,X)  01    2     6
	//      (indirect),Y  ORA (oper),Y  11    2     5*
	

	case 0x09: break;
	case 0x05: break;
	case 0x15: break;
	case 0x0D: break;
	case 0x1D: break;
	case 0x19: break;
	case 0x01: break;
	case 0x11: break;


	// PHA  Push Accumulator on Stack
	// 
	//      push A                           N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       PHA           48    1     3
	
	case 0x48: break;

	// PHP  Push Processor Status on Stack
	// 
	//      push SR                          N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       PHP           08    1     3
	

	case 0x08: break;


	// PLA  Pull Accumulator from Stack
	// 
	//      pull A                           N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       PLA           68    1     4
	

	case 0x68: break;


	// PLP  Pull Processor Status from Stack
	// 
	//      pull SR                          N Z C I D V
	//                                       from stack
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       PHP           28    1     4
	

	case 0x2B: break;


	// ROL  Rotate One Bit Left (Memory or Accumulator)
	// 
	//      C <- [76543210] <- C             N Z C I D V
	//                                       + + + - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      accumulator   ROL A         2A    1     2
	//      zeropage      ROL oper      26    2     5
	//      zeropage,X    ROL oper,X    36    2     6
	//      absolute      ROL oper      2E    3     6
	//      absolute,X    ROL oper,X    3E    3     7
	

	case 0x2A: break;
	case 0x26: break;
	case 0x36: break;
	case 0x2E: break;
	case 0x3E: break;


	// ROR  Rotate One Bit Right (Memory or Accumulator)
	// 
	//      C -> [76543210] -> C             N Z C I D V
	//                                       + + + - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      accumulator   ROR A         6A    1     2
	//      zeropage      ROR oper      66    2     5
	//      zeropage,X    ROR oper,X    76    2     6
	//      absolute      ROR oper      6E    3     6
	//      absolute,X    ROR oper,X    7E    3     7
	

	case 0x6A: break;
	case 0x66: break;
	case 0x76: break;
	case 0x6E: break;
	case 0x7E: break;


	// RTI  Return from Interrupt
	// 
	//      pull SR, pull PC                 N Z C I D V
	//                                       from stack
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       RTI           40    1     6
	

	case 0x40: break;


	// RTS  Return from Subroutine
	// 
	//      pull PC, PC+1 -> PC              N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       RTS           60    1     6
	

	case 0x60: break;


	// SBC  Subtract Memory from Accumulator with Borrow
	// 
	//      A - M - C -> A                   N Z C I D V
	//                                       + + + - - +
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      immidiate     SBC #oper     E9    2     2
	//      zeropage      SBC oper      E5    2     3
	//      zeropage,X    SBC oper,X    F5    2     4
	//      absolute      SBC oper      ED    3     4
	//      absolute,X    SBC oper,X    FD    3     4*
	//      absolute,Y    SBC oper,Y    F9    3     4*
	//      (indirect,X)  SBC (oper,X)  E1    2     6
	//      (indirect),Y  SBC (oper),Y  F1    2     5*
	
	case 0xE9: break;
	case 0xE5: break;
	case 0xF5: break;
	case 0xED: break;
	case 0xFD: break;
	case 0xF9: break;
	case 0xE1: break;
	case 0xF1: break;

	// SEC  Set Carry Flag
	// 
	//      1 -> C                           N Z C I D V
	//                                       - - 1 - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       SEC           38    1     2
	

	case 0x38: break;


	// SED  Set Decimal Flag
	// 
	//      1 -> D                           N Z C I D V
	//                                       - - - - 1 -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       SED           F8    1     2
	

	case 0xF8: break;


	// SEI  Set Interrupt Disable Status
	// 
	//      1 -> I                           N Z C I D V
	//                                       - - - 1 - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       SEI           78    1     2
	

	case 0x78: break;


	// STA  Store Accumulator in Memory
	// 
	//      A -> M                           N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      zeropage      STA oper      85    2     3
	//      zeropage,X    STA oper,X    95    2     4
	//      absolute      STA oper      8D    3     4
	//      absolute,X    STA oper,X    9D    3     5
	//      absolute,Y    STA oper,Y    99    3     5
	//      (indirect,X)  STA (oper,X)  81    2     6
	//      (indirect),Y  STA (oper),Y  91    2     6
	

	case 0x85: break;
	case 0x95: break;
	case 0x8D: break;
	case 0x9D: break;
	case 0x99: break;
	case 0x81: break;
	case 0x91: break;


	// STX  Store Index X in Memory
	// 
	//      X -> M                           N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      zeropage      STX oper      86    2     3
	//      zeropage,Y    STX oper,Y    96    2     4
	//      absolute      STX oper      8E    3     4
	

	case 0x86: break;
	case 0x96: break;
	case 0x8E: break;


	// STY  Sore Index Y in Memory
	// 
	//      Y -> M                           N Z C I D V
	//                                       - - - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      zeropage      STY oper      84    2     3
	//      zeropage,X    STY oper,X    94    2     4
	//      absolute      STY oper      8C    3     4
	

	case 0x84: break;
	case 0x94: break;
	case 0x8C: break;


	// TAX  Transfer Accumulator to Index X
	// 
	//      A -> X                           N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       TAX           AA    1     2
	

	case 0xAA: break;


	// TAY  Transfer Accumulator to Index Y
	// 
	//      A -> Y                           N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       TAY           A8    1     2
	

	case 0xA8: break;


	// TSX  Transfer Stack Pointer to Index X
	// 
	//      SP -> X                          N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       TSX           BA    1     2
	

	case 0xBA: break;


	// TXA  Transfer Index X to Accumulator
	// 
	//      X -> A                           N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       TXA           8A    1     2
	

	case 0x8A: break;


	// TXS  Transfer Index X to Stack Register
	// 
	//      X -> SP                          N Z C I D V
	//                                       + + - - - -
	// 
	//      addressing    assembler    opc  bytes  cyles
	//      --------------------------------------------
	//      implied       TXS           9A    1     2
	

	case 0x9A: break;


	// TYA  Transfer Index Y to Accumulator
	//
	//     Y -> A                           N Z C I D V
	//                                      + + - - - -
	//
	//     addressing    assembler    opc  bytes  cyles
	//     --------------------------------------------
	//     implied       TYA           98    1     2

	case 0x98: break;


	default:
		break;
	}



}



void Mos6502CPU::PrintProgram()
{
	uint32_t size = sizeof(RomBankMem) * m_numRomBanks;
	uint16_t ip = 0;

	uint8_t instructionsPerPage = 40;
	uint8_t pageInstructionCount = 0;

	while (ip < size)
	{
		if (pageInstructionCount >= instructionsPerPage)
		{
			system("pause");
			pageInstructionCount = 0;
		}

		pageInstructionCount++;


		uint8_t opCode = ((uint8_t *)m_rom)[ip];
		std::cout << std::hex << (int)opCode << ": ";

 		switch (opCode)
		{
			// ADC  Add Memory to Accumulator with Carry
			// 
			//      A + M + C -> A, C                N Z C I D V
			//                                       + + + - - +
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     ADC #oper     69    2     2
			//      zeropage      ADC oper      65    2     3
			//      zeropage,X    ADC oper,X    75    2     4
			//      absolute      ADC oper      6D    3     4
			//      absolute,X    ADC oper,X    7D    3     4*
			//      absolute,Y    ADC oper,Y    79    3     4*
			//      (indirect,X)  ADC (oper,X)  61    2     6
			//      (indirect),Y  ADC (oper),Y  71    2     5*

		case 0x69: std::cout << "ADC" << std::endl; ip += 2; break;
		case 0x65: std::cout << "ADC" << std::endl; ip += 2; break;
		case 0x75: std::cout << "ADC" << std::endl; ip += 2; break;
		case 0x6D: std::cout << "ADC" << std::endl; ip += 3; break;
		case 0x7D: std::cout << "ADC" << std::endl; ip += 3; break;
		case 0x79: std::cout << "ADC" << std::endl; ip += 3; break;
		case 0x61: std::cout << "ADC" << std::endl; ip += 2; break;
		case 0x71: std::cout << "ADC" << std::endl; ip += 2; break;


			// AND  AND Memory with Accumulator
			// 
			//      A AND M -> A                     N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     AND #oper     29    2     2
			//      zeropage      AND oper      25    2     3
			//      zeropage,X    AND oper,X    35    2     4
			//      absolute      AND oper      2D    3     4
			//      absolute,X    AND oper,X    3D    3     4*
			//      absolute,Y    AND oper,Y    39    3     4*
			//      (indirect,X)  AND (oper,X)  21    2     6
			//      (indirect),Y  AND (oper),Y  31    2     5*


		case 0x29: std::cout << "AND" << std::endl; ip += 2; break;
		case 0x25: std::cout << "AND" << std::endl; ip += 2; break;
		case 0x35: std::cout << "AND" << std::endl; ip += 2; break;
		case 0x2D: std::cout << "AND" << std::endl; ip += 3; break;
		case 0x3D: std::cout << "AND" << std::endl; ip += 3; break;
		case 0x39: std::cout << "AND" << std::endl; ip += 3; break;
		case 0x21: std::cout << "AND" << std::endl; ip += 2; break;
		case 0x31: std::cout << "AND" << std::endl; ip += 2; break;


			// ASL  Shift Left One Bit (Memory or Accumulator)
			// 
			//      C <- [76543210] <- 0             N Z C I D V
			//                                       + + + - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      accumulator   ASL A         0A    1     2
			//      zeropage      ASL oper      06    2     5
			//      zeropage,X    ASL oper,X    16    2     6
			//      absolute      ASL oper      0E    3     6
			//      absolute,X    ASL oper,X    1E    3     7


		case 0x0A: std::cout << "ASL" << std::endl; ip += 1; break;
		case 0x06: std::cout << "ASL" << std::endl; ip += 2; break;
		case 0x16: std::cout << "ASL" << std::endl; ip += 2; break;
		case 0x0E: std::cout << "ASL" << std::endl; ip += 3; break;
		case 0x1E: std::cout << "ASL" << std::endl; ip += 3; break;


			// BCC  Branch on Carry Clear
			// 
			//      branch on C = 0                  N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      relative      BCC oper      90    2     2**


		case 0x90: std::cout << "BCC" << std::endl; ip += 2; break;


			// BCS  Branch on Carry Set
			// 
			//      branch on C = 1                  N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      relative      BCS oper      B0    2     2**

		case 0xB0: std::cout << "BSC" << std::endl; ip += 2; break;

			// BEQ  Branch on Result Zero
			// 
			//      branch on Z = 1                  N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      relative      BEQ oper      F0    2     2**


		case 0xF0: std::cout << "BEQ" << std::endl; ip += 2; break;


			// BIT  Test Bits in Memory with Accumulator
			// 
			//      bits 7 and 6 of operand are transfered to bit 7 and 6 of SR (N,V);
			//      the zeroflag is set to the result of operand AND accumulator.
			// 
			//      A AND M, M7 -> N, M6 -> V        N Z C I D V
			//                                      M7 + - - - M6
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      zeropage      BIT oper      24    2     3
			//      absolute      BIT oper      2C    3     4


		case 0x24: std::cout << "BIT" << std::endl; ip += 2; break;
		case 0x2C: std::cout << "BIT" << std::endl; ip += 3; break;


			// BMI  Branch on Result Minus
			// 
			//      branch on N = 1                  N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      relative      BMI oper      30    2     2**


		case 0x30: std::cout << "BMI" << std::endl; ip += 2; break;


			// BNE  Branch on Result not Zero
			// 
			//      branch on Z = 0                  N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      relative      BNE oper      D0    2     2**


		case 0xD0: std::cout << "BNE" << std::endl; ip += 2; break;

			// BPL  Branch on Result Plus
			// 
			//      branch on N = 0                  N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      relative      BPL oper      10    2     2**


		case 0x10: std::cout << "BPL" << std::endl; ip += 2; break;


			// BRK  Force Break
			// 
			//      interrupt,                       N Z C I D V
			//      push PC+2, push SR               - - - 1 - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       BRK           00    1     7


		case 0x00: std::cout << "BRK" << std::endl; ip += 1; break;


			// BVC  Branch on Overflow Clear
			// 
			//      branch on V = 0                  N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      relative      BVC oper      50    2     2**


		case 0x50: std::cout << "BVC" << std::endl; ip += 2; break;


			// BVS  Branch on Overflow Set
			// 
			//      branch on V = 1                  N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      relative      BVC oper      70    2     2**


		case 0x70: std::cout << "BVS" << std::endl; ip += 2; break;


			// CLC  Clear Carry Flag
			// 
			//      0 -> C                           N Z C I D V
			//                                       - - 0 - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       CLC           18    1     2


		case 0x18: std::cout << "CLC" << std::endl; ip += 1; break;


			// CLD  Clear Decimal Mode
			// 
			//      0 -> D                           N Z C I D V
			//                                       - - - - 0 -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       CLD           D8    1     2


		case 0xD8: std::cout << "CLD" << std::endl; ip += 1; break;


			// CLI  Clear Interrupt Disable Bit
			// 
			//      0 -> I                           N Z C I D V
			//                                       - - - 0 - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       CLI           58    1     2


		case 0x58: std::cout << "CLI" << std::endl; ip += 1; break;


			// CLV  Clear Overflow Flag
			// 
			//      0 -> V                           N Z C I D V
			//                                       - - - - - 0
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       CLV           B8    1     2


		case 0xB8: std::cout << "CLV" << std::endl; ip += 1; break;

			// CMP  Compare Memory with Accumulator
			// 
			//      A - M                            N Z C I D V
			//                                     + + + - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     CMP #oper     C9    2     2
			//      zeropage      CMP oper      C5    2     3
			//      zeropage,X    CMP oper,X    D5    2     4
			//      absolute      CMP oper      CD    3     4
			//      absolute,X    CMP oper,X    DD    3     4*
			//      absolute,Y    CMP oper,Y    D9    3     4*
			//      (indirect,X)  CMP (oper,X)  C1    2     6
			//      (indirect),Y  CMP (oper),Y  D1    2     5*


		case 0xC9: std::cout << "CMP" << std::endl; ip += 2; break;
		case 0xC5: std::cout << "CMP" << std::endl; ip += 2; break;
		case 0xD5: std::cout << "CMP" << std::endl; ip += 3; break;
		case 0xCD: std::cout << "CMP" << std::endl; ip += 3; break;
		case 0xDD: std::cout << "CMP" << std::endl; ip += 3; break;
		case 0xD9: std::cout << "CMP" << std::endl; ip += 3; break;
		case 0xC1: std::cout << "CMP" << std::endl; ip += 2; break;
		case 0xD1: std::cout << "CMP" << std::endl; ip += 2; break;


			// CPX  Compare Memory and Index X
			// 
			//      X - M                            N Z C I D V
			//                                       + + + - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     CPX #oper     E0    2     2
			//      zeropage      CPX oper      E4    2     3
			//      absolute      CPX oper      EC    3     4


		case 0xE0: std::cout << "CPX" << std::endl; ip += 2; break;
		case 0xE4: std::cout << "CPX" << std::endl; ip += 2; break;
		case 0xEC: std::cout << "CPX" << std::endl; ip += 3; break;


			// CPY  Compare Memory and Index Y
			// 
			//      Y - M                            N Z C I D V
			//                                       + + + - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     CPY #oper     C0    2     2
			//      zeropage      CPY oper      C4    2     3
			//      absolute      CPY oper      CC    3     4


		case 0xC0: std::cout << "CPY" << std::endl; ip += 2; break;
		case 0xC4: std::cout << "CPY" << std::endl; ip += 2; break;
		case 0xCC: std::cout << "CPY" << std::endl; ip += 3; break;


			// DEC  Decrement Memory by One
			// 
			//      M - 1 -> M                       N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      zeropage      DEC oper      C6    2     5
			//      zeropage,X    DEC oper,X    D6    2     6
			//      absolute      DEC oper      CE    3     3
			//      absolute,X    DEC oper,X    DE    3     7


		case 0xC6: std::cout << "DEC" << std::endl; ip += 2; break;
		case 0xD6: std::cout << "DEC" << std::endl; ip += 2; break;
		case 0xCE: std::cout << "DEC" << std::endl; ip += 3; break;
		case 0xDE: std::cout << "DEC" << std::endl; ip += 3; break;


			// DEX  Decrement Index X by One
			// 
			//      X - 1 -> X                       N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       DEC           CA    1     2


		case 0xCA: std::cout << "DEX" << std::endl; ip += 1; break;


			// DEY  Decrement Index Y by One
			// 
			//      Y - 1 -> Y                       N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       DEC           88    1     2

		case 0x88: std::cout << "DEY" << std::endl; ip += 1; break;

			// EOR  Exclusive-OR Memory with Accumulator
			// 
			//      A EOR M -> A                     N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     EOR #oper     49    2     2
			//      zeropage      EOR oper      45    2     3
			//      zeropage,X    EOR oper,X    55    2     4
			//      absolute      EOR oper      4D    3     4
			//      absolute,X    EOR oper,X    5D    3     4*
			//      absolute,Y    EOR oper,Y    59    3     4*
			//      (indirect,X)  EOR (oper,X)  41    2     6
			//      (indirect),Y  EOR (oper),Y  51    2     5*


		case 0x49: std::cout << "EOR" << std::endl; ip += 1; break;
		case 0x45: std::cout << "EOR" << std::endl; ip += 1; break;
		case 0x55: std::cout << "EOR" << std::endl; ip += 1; break;
		case 0x4D: std::cout << "EOR" << std::endl; ip += 1; break;
		case 0x5D: std::cout << "EOR" << std::endl; ip += 1; break;
		case 0x59: std::cout << "EOR" << std::endl; ip += 1; break;
		case 0x41: std::cout << "EOR" << std::endl; ip += 1; break;
		case 0x51: std::cout << "EOR" << std::endl; ip += 1; break;


			// INC  Increment Memory by One
			// 
			//      M + 1 -> M                       N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      zeropage      INC oper      E6    2     5
			//      zeropage,X    INC oper,X    F6    2     6
			//      absolute      INC oper      EE    3     6
			//      absolute,X    INC oper,X    FE    3     7


		case 0xE6: std::cout << "INC" << std::endl; ip += 2; break;
		case 0xF6: std::cout << "INC" << std::endl; ip += 2; break;
		case 0xEE: std::cout << "INC" << std::endl; ip += 3; break;
		case 0xFE: std::cout << "INC" << std::endl; ip += 3; break;


			// INX  Increment Index X by One
			// 
			//      X + 1 -> X                       N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       INX           E8    1     2


		case 0xE8: std::cout << "INX" << std::endl; ip += 1; break;


			// INY  Increment Index Y by One
			// 
			//      Y + 1 -> Y                       N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       INY           C8    1     2


		case 0xC8: std::cout << "INY" << std::endl; ip += 1; break;


			// JMP  Jump to New Location
			// 
			//      (PC+1) -> PCL                    N Z C I D V
			//      (PC+2) -> PCH                    - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      absolute      JMP oper      4C    3     3
			//      indirect      JMP (oper)    6C    3     5


		case 0x4C: std::cout << "JMP" << std::endl; ip += 3; break;
		case 0x6C: std::cout << "JMP" << std::endl; ip += 3; break;


			// JSR  Jump to New Location Saving Return Address
			// 
			//      push (PC+2),                     N Z C I D V
			//      (PC+1) -> PCL                    - - - - - -
			//      (PC+2) -> PCH
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      absolute      JSR oper      20    3     6


		case 0x20: std::cout << "JSR" << std::endl; ip += 3; break;


			// LDA  Load Accumulator with Memory
			// 
			//      M -> A                           N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     LDA #oper     A9    2     2
			//      zeropage      LDA oper      A5    2     3
			//      zeropage,X    LDA oper,X    B5    2     4
			//      absolute      LDA oper      AD    3     4
			//      absolute,X    LDA oper,X    BD    3     4*
			//      absolute,Y    LDA oper,Y    B9    3     4*
			//      (indirect,X)  LDA (oper,X)  A1    2     6
			//      (indirect),Y  LDA (oper),Y  B1    2     5*


		case 0xA9: std::cout << "LDA" << std::endl; ip += 2; break;
		case 0xA5: std::cout << "LDA" << std::endl; ip += 2; break;
		case 0xB5: std::cout << "LDA" << std::endl; ip += 2; break;
		case 0xAD: std::cout << "LDA" << std::endl; ip += 3; break;
		case 0xBD: std::cout << "LDA" << std::endl; ip += 3; break;
		case 0xB9: std::cout << "LDA" << std::endl; ip += 3; break;
		case 0xA1: std::cout << "LDA" << std::endl; ip += 2; break;
		case 0xB1: std::cout << "LDA" << std::endl; ip += 2; break;


			// LDX  Load Index X with Memory
			// 
			//      M -> X                           N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     LDX #oper     A2    2     2
			//      zeropage      LDX oper      A6    2     3
			//      zeropage,Y    LDX oper,Y    B6    2     4
			//      absolute      LDX oper      AE    3     4
			//      absolute,Y    LDX oper,Y    BE    3     4*

		case 0xA2: std::cout << "LDX" << std::endl; ip += 2; break;
		case 0xA6: std::cout << "LDX" << std::endl; ip += 2; break;
		case 0xB6: std::cout << "LDX" << std::endl; ip += 2; break;
		case 0xAE: std::cout << "LDX" << std::endl; ip += 3; break;
		case 0xBE: std::cout << "LDX" << std::endl; ip += 3; break;

			// LDY  Load Index Y with Memory
			// 
			//      M -> Y                           N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     LDY #oper     A0    2     2
			//      zeropage      LDY oper      A4    2     3
			//      zeropage,X    LDY oper,X    B4    2     4
			//      absolute      LDY oper      AC    3     4
			//      absolute,X    LDY oper,X    BC    3     4*


		case 0xA0: std::cout << "LDY" << std::endl; ip += 2; break;
		case 0xA4: std::cout << "LDY" << std::endl; ip += 2; break;
		case 0xB4: std::cout << "LDY" << std::endl; ip += 2; break;
		case 0xAC: std::cout << "LDY" << std::endl; ip += 3; break;
		case 0xBC: std::cout << "LDY" << std::endl; ip += 3; break;


			// LSR  Shift One Bit Right (Memory or Accumulator)
			// 
			//      0 -> [76543210] -> C             N Z C I D V
			//                                       - + + - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      accumulator   LSR A         4A    1     2
			//      zeropage      LSR oper      46    2     5
			//      zeropage,X    LSR oper,X    56    2     6
			//      absolute      LSR oper      4E    3     6
			//      absolute,X    LSR oper,X    5E    3     7


		case 0x4A: std::cout << "LSR" << std::endl; ip += 1; break;
		case 0x46: std::cout << "LSR" << std::endl; ip += 2; break;
		case 0x56: std::cout << "LSR" << std::endl; ip += 2; break;
		case 0x4E: std::cout << "LSR" << std::endl; ip += 3; break;
		case 0x5E: std::cout << "LSR" << std::endl; ip += 3; break;


			// NOP  No Operation
			// 
			//      ---                              N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       NOP           EA    1     2


		case 0xEA: std::cout << "NOP" << std::endl; ip += 1; break;


			// ORA  OR Memory with Accumulator
			// 
			//      A OR M -> A                      N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     ORA #oper     09    2     2
			//      zeropage      ORA oper      05    2     3
			//      zeropage,X    ORA oper,X    15    2     4
			//      absolute      ORA oper      0D    3     4
			//      absolute,X    ORA oper,X    1D    3     4*
			//      absolute,Y    ORA oper,Y    19    3     4*
			//      (indirect,X)  ORA (oper,X)  01    2     6
			//      (indirect),Y  ORA (oper),Y  11    2     5*


		case 0x09: std::cout << "ORA" << std::endl; ip += 2; break;
		case 0x05: std::cout << "ORA" << std::endl; ip += 2; break;
		case 0x15: std::cout << "ORA" << std::endl; ip += 2; break;
		case 0x0D: std::cout << "ORA" << std::endl; ip += 3; break;
		case 0x1D: std::cout << "ORA" << std::endl; ip += 3; break;
		case 0x19: std::cout << "ORA" << std::endl; ip += 3; break;
		case 0x01: std::cout << "ORA" << std::endl; ip += 2; break;
		case 0x11: std::cout << "ORA" << std::endl; ip += 2; break;


			// PHA  Push Accumulator on Stack
			// 
			//      push A                           N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       PHA           48    1     3

		case 0x48: std::cout << "PHA" << std::endl; ip += 1; break;

			// PHP  Push Processor Status on Stack
			// 
			//      push SR                          N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       PHP           08    1     3


		case 0x08: std::cout << "PHP" << std::endl; ip += 1; break;


			// PLA  Pull Accumulator from Stack
			// 
			//      pull A                           N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       PLA           68    1     4


		case 0x68: std::cout << "PLA" << std::endl; ip += 1; break;


			// PLP  Pull Processor Status from Stack
			// 
			//      pull SR                          N Z C I D V
			//                                       from stack
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       PHP           28    1     4


		case 0x2B: std::cout << "PLP" << std::endl; ip += 1; break;


			// ROL  Rotate One Bit Left (Memory or Accumulator)
			// 
			//      C <- [76543210] <- C             N Z C I D V
			//                                       + + + - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      accumulator   ROL A         2A    1     2
			//      zeropage      ROL oper      26    2     5
			//      zeropage,X    ROL oper,X    36    2     6
			//      absolute      ROL oper      2E    3     6
			//      absolute,X    ROL oper,X    3E    3     7


		case 0x2A: std::cout << "ROL" << std::endl; ip += 1; break;
		case 0x26: std::cout << "ROL" << std::endl; ip += 2; break;
		case 0x36: std::cout << "ROL" << std::endl; ip += 2; break;
		case 0x2E: std::cout << "ROL" << std::endl; ip += 3; break;
		case 0x3E: std::cout << "ROL" << std::endl; ip += 3; break;


			// ROR  Rotate One Bit Right (Memory or Accumulator)
			// 
			//      C -> [76543210] -> C             N Z C I D V
			//                                       + + + - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      accumulator   ROR A         6A    1     2
			//      zeropage      ROR oper      66    2     5
			//      zeropage,X    ROR oper,X    76    2     6
			//      absolute      ROR oper      6E    3     6
			//      absolute,X    ROR oper,X    7E    3     7


		case 0x6A: std::cout << "ROR" << std::endl; ip += 1; break;
		case 0x66: std::cout << "ROR" << std::endl; ip += 2; break;
		case 0x76: std::cout << "ROR" << std::endl; ip += 2; break;
		case 0x6E: std::cout << "ROR" << std::endl; ip += 3; break;
		case 0x7E: std::cout << "ROR" << std::endl; ip += 3; break;


			// RTI  Return from Interrupt
			// 
			//      pull SR, pull PC                 N Z C I D V
			//                                       from stack
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       RTI           40    1     6


		case 0x40: std::cout << "RTI" << std::endl; ip += 1; break;


			// RTS  Return from Subroutine
			// 
			//      pull PC, PC+1 -> PC              N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       RTS           60    1     6


		case 0x60: std::cout << "RTS" << std::endl; ip += 1; break;


			// SBC  Subtract Memory from Accumulator with Borrow
			// 
			//      A - M - C -> A                   N Z C I D V
			//                                       + + + - - +
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      immidiate     SBC #oper     E9    2     2
			//      zeropage      SBC oper      E5    2     3
			//      zeropage,X    SBC oper,X    F5    2     4
			//      absolute      SBC oper      ED    3     4
			//      absolute,X    SBC oper,X    FD    3     4*
			//      absolute,Y    SBC oper,Y    F9    3     4*
			//      (indirect,X)  SBC (oper,X)  E1    2     6
			//      (indirect),Y  SBC (oper),Y  F1    2     5*

		case 0xE9: std::cout << "SBC" << std::endl; ip += 2; break;
		case 0xE5: std::cout << "SBC" << std::endl; ip += 2; break;
		case 0xF5: std::cout << "SBC" << std::endl; ip += 2; break;
		case 0xED: std::cout << "SBC" << std::endl; ip += 3; break;
		case 0xFD: std::cout << "SBC" << std::endl; ip += 3; break;
		case 0xF9: std::cout << "SBC" << std::endl; ip += 3; break;
		case 0xE1: std::cout << "SBC" << std::endl; ip += 2; break;
		case 0xF1: std::cout << "SBC" << std::endl; ip += 2; break;

			// SEC  Set Carry Flag
			// 
			//      1 -> C                           N Z C I D V
			//                                       - - 1 - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       SEC           38    1     2


		case 0x38: std::cout << "SEC" << std::endl; ip += 1; break;


			// SED  Set Decimal Flag
			// 
			//      1 -> D                           N Z C I D V
			//                                       - - - - 1 -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       SED           F8    1     2


		case 0xF8: std::cout << "SED" << std::endl; ip += 1; break;


			// SEI  Set Interrupt Disable Status
			// 
			//      1 -> I                           N Z C I D V
			//                                       - - - 1 - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       SEI           78    1     2


		case 0x78: std::cout << "SEI" << std::endl; ip += 1; break;


			// STA  Store Accumulator in Memory
			// 
			//      A -> M                           N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      zeropage      STA oper      85    2     3
			//      zeropage,X    STA oper,X    95    2     4
			//      absolute      STA oper      8D    3     4
			//      absolute,X    STA oper,X    9D    3     5
			//      absolute,Y    STA oper,Y    99    3     5
			//      (indirect,X)  STA (oper,X)  81    2     6
			//      (indirect),Y  STA (oper),Y  91    2     6


		case 0x85: std::cout << "STA" << std::endl; ip += 2; break;
		case 0x95: std::cout << "STA" << std::endl; ip += 2; break;
		case 0x8D: std::cout << "STA" << std::endl; ip += 3; break;
		case 0x9D: std::cout << "STA" << std::endl; ip += 3; break;
		case 0x99: std::cout << "STA" << std::endl; ip += 3; break;
		case 0x81: std::cout << "STA" << std::endl; ip += 2; break;
		case 0x91: std::cout << "STA" << std::endl; ip += 2; break;


			// STX  Store Index X in Memory
			// 
			//      X -> M                           N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      zeropage      STX oper      86    2     3
			//      zeropage,Y    STX oper,Y    96    2     4
			//      absolute      STX oper      8E    3     4


		case 0x86: std::cout << "STX" << std::endl; ip += 2; break;
		case 0x96: std::cout << "STX" << std::endl; ip += 2; break;
		case 0x8E: std::cout << "STX" << std::endl; ip += 3; break;


			// STY  Sore Index Y in Memory
			// 
			//      Y -> M                           N Z C I D V
			//                                       - - - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      zeropage      STY oper      84    2     3
			//      zeropage,X    STY oper,X    94    2     4
			//      absolute      STY oper      8C    3     4


		case 0x84: std::cout << "STY" << std::endl; ip += 2; break;
		case 0x94: std::cout << "STY" << std::endl; ip += 2; break;
		case 0x8C: std::cout << "STY" << std::endl; ip += 3; break;


			// TAX  Transfer Accumulator to Index X
			// 
			//      A -> X                           N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       TAX           AA    1     2


		case 0xAA: std::cout << "TAX" << std::endl; ip += 1; break;


			// TAY  Transfer Accumulator to Index Y
			// 
			//      A -> Y                           N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       TAY           A8    1     2


		case 0xA8: std::cout << "TAY" << std::endl; ip += 1; break;


			// TSX  Transfer Stack Pointer to Index X
			// 
			//      SP -> X                          N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       TSX           BA    1     2


		case 0xBA: std::cout << "TSX" << std::endl; ip += 1; break;


			// TXA  Transfer Index X to Accumulator
			// 
			//      X -> A                           N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       TXA           8A    1     2


		case 0x8A: std::cout << "TXA" << std::endl; ip += 1; break;


			// TXS  Transfer Index X to Stack Register
			// 
			//      X -> SP                          N Z C I D V
			//                                       + + - - - -
			// 
			//      addressing    assembler    opc  bytes  cyles
			//      --------------------------------------------
			//      implied       TXS           9A    1     2


		case 0x9A: std::cout << "TXS" << std::endl; ip += 1; break;


			// TYA  Transfer Index Y to Accumulator
			//
			//     Y -> A                           N Z C I D V
			//                                      + + - - - -
			//
			//     addressing    assembler    opc  bytes  cyles
			//     --------------------------------------------
			//     implied       TYA           98    1     2

		case 0x98: std::cout << "TYA" << std::endl; ip += 1; break;


		default:
			std::cout << "--- UNKNOWN -- " << std::endl; ip += 1;
			break;
		}

	}



}


