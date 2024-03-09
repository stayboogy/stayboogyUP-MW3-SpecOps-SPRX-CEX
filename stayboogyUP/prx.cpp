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

#include <ps3.h>
#include <cheats.h>

void stayboogy(uint64_t arg)
{
	for(;;)
	{
		sleep(10000);
		UAV();
		Perks();
		Loaded();
		sleep(5000);
		Godly();
	}
}

//stayboogy is the module name
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
	create_thread(stayboogy, 0x4AA, 0x6000, "stayboogy", stayboogyUP);
    return SYS_PRX_RESIDENT;
}

extern "C" int _stayboogyUP_prx_exit(void)
{
	sys_ppu_thread_exit();
	return 0;
}
