del Release\stayboogyUP-last.zip 
del Release\stayboogyUP.sprx 
del Release\EBOOT.BIN
tar.exe -cf Release\stayboogyUP-last.zip PS3_Debug\stayboogyUP.sprx PS3_Debug\EBOOT.BIN
start cleanup.cmd
exit

