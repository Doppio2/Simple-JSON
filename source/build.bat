@echo off

set CommonCompilerFlags=-MT -nologo -D_CRT_SECURE_NO_WARNINGS -Gm- -GR- -EHa- -Od -Oi -WX -W4 -wd4530 -wd4201 -wd4100 -wd4101 -wd4189 -FC -Z7
set CommonLinkerFlags= -opt:ref -SUBSYSTEM:CONSOLE 

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

REM 64-bit build
cl %CommonCompilerFlags% ../source/main.c /link %CommonLinkerFlags% 
popd
