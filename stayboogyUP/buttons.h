// Copyright (c) 2022, stayboogy@github.com, stayboogy@mail.com, M.C.
//
// stayboogy did it!
//

#include <cell/pad.h>

// use actual hardcoded buttons for the PS3
// why use game memory addresses for something the PS3 has natively?
// why reinvent the wheel?
// don't be a dumb coder

#define PAD_LEFT (1 << 7)
#define PAD_DOWN (1 << 6)
#define PAD_RIGHT (1 << 5)
#define PAD_UP (1 << 4)
#define PAD_START (1 << 3)
#define PAD_R3 (1 << 2)
#define PAD_L3 (1 << 1)
#define PAD_SELECT (1 << 0)
#define PAD_SQUARE (1 << 15)
#define PAD_CROSS (1 << 14)
#define PAD_CIRCLE (1 << 13)
#define PAD_TRIANGLE (1 << 12)
#define PAD_R1 (1 << 11)
#define PAD_L1 (1 << 10)
#define PAD_R2 (1 << 9)
#define PAD_L2 (1 << 8)

CellPadData PadData;

// simplest button press data determination possible
uint32_t GetKey(void)
{
	uint32_t temp;
	cellPadGetData(0, &PadData);
	temp = PadData.button[3];
	temp = (temp << 8) + PadData.button[2];
	return temp;
}
