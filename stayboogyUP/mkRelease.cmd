del Release\stayboogyUP-last.zip 
del Release\stayboogyUP.sprx 
del Release\EBOOT.BIN
copy PS3_Debug\stayboogyUP.sprx Release\stayboogyUP.sprx
copy EBOOT.BIN Release\EBOOT.BIN
cd Release
tar.exe -cf stayboogyUP-last.zip stayboogyUP.sprx EBOOT.BIN
cd ..\
start cleanup.cmd
exit