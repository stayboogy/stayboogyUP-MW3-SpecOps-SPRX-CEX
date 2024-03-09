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
	// so game can boot
	sleep(3000);

	// is this a stayboogy build?
	sBuild = false;

	// do forever in a loop the next part
	// this stayboogy function specifically
	for (;;)
	{
		// Godly | Manly logic
		isMan = !isGod;
		isGod = !isMan;

		// rest is always good
		sleep(1000);

		// cheats.h fuctions
		UAV();
		Perks();
		Loaded();
		Manly();
		Godly();
	}
}

//stayboogyUP is the thread name
sys_ppu_thread_t stayboogyUP;

//stayboogyUP is the module name
SYS_MODULE_INFO( stayboogyUP, 0, 1, 1);

// module begins
SYS_MODULE_START( _stayboogyUP_prx_entry );

// module ends
SYS_MODULE_STOP( _stayboogyUP_prx_exit );

// required for linker
SYS_LIB_DECLARE_WITH_STUB( LIBNAME, SYS_LIB_AUTO_EXPORT, STUBNAME );
SYS_LIB_EXPORT( _stayboogyUP_export_function, LIBNAME );

// An exported function is needed to generate the project's PRX stub export library
extern "C" int _stayboogyUP_export_function(void)
{
    return CELL_OK;
}

// Module Entry Point Information
// What Module Does in Simplest Form
extern "C" int _stayboogyUP_prx_entry(void)
{
	// so game boots dependably
	sleep(3000);

	// "stayboogy" is the main function, 
	// 0x4AA is the stack size, 
	// 0x6000 is the priority, 
	// "stayboogy" is the threadname, 
	// stayboogyUP is the sys_ppu_thread_t
	create_thread(stayboogy, 0x4AA, 0x6000, "stayboogy", stayboogyUP);
	console_write("\n\nstayboogyUP.\n\n");

	// Initialization Notification for end users only
	// to alert end users that it worked
	// stayboogy doesn't need this
	// I know it will load
	if (sBuild == !true);
	{
	// Initialization Message
	Notify::msgdialog_mode = Notify::MODE_STRING_OK;
	Notify::Show("stayboogyUP Solo Survival + Chaos Mods!\n\n           stayboogy@codeberg.org\n");
	}
    return SYS_PRX_RESIDENT;
}

// Module Exit Point Information
// What do on when finished
extern "C" int _stayboogyUP_prx_exit(void)
{
	sys_ppu_thread_exit();
	return 0;
}
