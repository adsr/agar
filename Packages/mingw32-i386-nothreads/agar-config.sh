#!/bin/sh
# Public domain

PREFIX="%PREFIX%"

if [ "$1" = "--version" ]; then echo "%INSTALLED_VERSION%"; fi
if [ "$1" = "--prefix" ]; then echo "${PREFIX}"; fi
if [ "$1" = "--exec-prefix" ]; then echo "${PREFIX}"; fi

if [ "$1" = "--cflags" ]; then
	echo "-I${PREFIX}/include/agar -I${PREFIX}/include/SDL -I/usr/local/include/SDL -I${PREFIX}/include/freetype2 -I/usr/local/include/freetype2 -I${PREFIX}/include -I/usr/local/include -I/usr/include/mingw -D_GNU_SOURCE=1 -Dmain=SDL_main"
fi
if [ "$1" = "--libs" ]; then
	echo "-L${PREFIX}/lib -lag_gui -lag_core -L/usr/local/lib -lmingw32 -lSDLmain -lSDL -mwindows -lfreetype -lopengl32 -lm"
fi
