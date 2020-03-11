cd bin
del Pool.exe
cd ..
cl /Fe"bin/Pool" raylib/lib/raylib.lib src/*.c /I raylib/include /I include
move *.obj obj