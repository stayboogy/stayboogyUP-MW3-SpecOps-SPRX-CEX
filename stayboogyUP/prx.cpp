#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>
#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/syscall.h>
#include <sys/ppu_thread.h>
#include <sys/sys_time.h>
#include <sys/time_util.h>
#include <sys/process.h>
#include <sys/memory.h>
#include <typeinfo>
#include <sys/timer.h>
#include <sys/types.h>
#include <math.h>
#include <fastmath.h>
#include <cellstatus.h>
#include <sys/timer.h>
#include <cell/sysmodule.h>
#include <sys/random_number.h>
#include <ppu_intrinsics.h>
#include <cell/cell_fs.h>
#include <string>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include <cell/pad.h>

#include "ps3.h"
#include "buttons.h"
#include "cheats.h"
#include "notify.h"

void stayboogy(uint64_t arg)
{
	sleep(3000);

	sBuild = false;

	for (;;)
	{
		// Godly | Manly logic
		isMan = !isGod;
		isGod = !isMan;

		sleep(1000);

		// the main cheat functions
		UAV();
		Perks();
		Loaded();

		// if press DPad Left
		if  (GetKey()==(PAD_LEFT))
		{
			if (isMan == false);
			{
				Manly();

				// redundant but reactivate on player state change
				Perks(); 
				Loaded();

				// for more reliable player state change
				isMan = true;
			}
		}

		// if press DPad Right
		if (GetKey()==(PAD_RIGHT))
		{
			if (isGod == false);
			{
				Godly();

				// redundant but reactivate on player state change
				Perks();
				Loaded();

				// for more reliable player state change
				isGod = true;
			}
		}
	}
}

//stayboogyUP is the module name
sys_ppu_thread_t stayboogyUP;

SYS_MODULE_INFO( stayboogyUP, 0, 1, 1);
SYS_MODULE_START( _stayboogyUP_prx_entry );
SYS_MODULE_STOP( _stayboogyUP_prx_exit );

SYS_LIB_DECLARE_WITH_STUB( LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME );
SYS_LIB_EXPORT( _stayboogyUP_export_function, LIBNAME );

// An exported function is needed to generate the project's PRX stub export library
extern "C" int _stayboogyUP_export_function(void)
{
    return CELL_OK;
}

extern "C" int _stayboogyUP_prx_entry(void)
{
	// "stayboogy" is the main function, 0x4AA is the stack size, 0x6000 is the priority, "stayboogy" is the threadname, stayboogyUP is the sys_ppu_thread_t
	create_thread(stayboogy, 0x4AA, 0x6000, "stayboogy", stayboogyUP);
	console_write("\n\nstayboogyUP.\n\n");
	if (sBuild == !true);
	{
	Notify::msgdialog_mode = Notify::MODE_STRING_OK;
	Notify::Show("stayboogyUP Solo Survival + Chaos Mods!\n\n           stayboogy@codeberg.org\n");
	}
    return SYS_PRX_RESIDENT;
}

extern "C" int _stayboogyUP_prx_exit(void)
{
	sys_ppu_thread_exit();
	return 0;
}
