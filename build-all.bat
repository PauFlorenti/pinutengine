@ECHO OFF

PUSHD math
CALL build.bat
POPD

PUSHD engine
CALL buiLd.bat
POPD

PUSHD sandbox
CALL build.bat
POPD