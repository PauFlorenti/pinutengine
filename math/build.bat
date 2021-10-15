@ECHO OFF

setlocal EnableDelayedExpansion

SET var=
FOR /R %%f in (*.cpp) do (
    SET var=!var! "%%f"
)

SET compilerFlags= -g -Wall -Werror
SET includePath= -Isrc -I../math/src

ECHO "Building Math library ..."

g++ -c -o ../bin/math.lib %var% %compilerFlags% %includePath%