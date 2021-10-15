@ECHO OFF

setlocal EnableDelayedExpansion

SET var=
FOR /R %%f in (*.cpp) do (
    SET var=!var! "%%f"
)

SET compilerFlags= -g -Wall -Werror
SET includePath= -Isrc -I../engine/src
SET linkingFlags= -L../bin -lengine

ECHO "Building Sandbox ..."

g++ -DPNTEXPORT -o ../bin/sandbox.exe %var% %linkingFlags% %compilerFlags% %includePath%