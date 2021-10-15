@ECHO OFF

setlocal EnableDelayedExpansion

SET var=
FOR /R %%f in (*.cpp) do (
    SET var=!var! "%%f"
)

SET includePath= -Isrc -Isrc/core -I../math/src
SET compilerFlags= -g -shared -Wall -Werror
SET linking= -L../bin -static -lmath

ECHO "Building engine ..."

g++ -DPNTEXPORT -o ../bin/engine.dll %var% %includePath% %linking% %compilerFlags%  