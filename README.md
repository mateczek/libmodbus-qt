# libmodbus-qt korzysta z biblioteki libmodbus instalacja z poziomu msys2 dla windows
msys2 https://www.msys2.org/

instalacja Qt w msys2:
1. Aktualizacja Msys2 wszystkich pakietów(po aktualizacji zamknąć okno msys2 i ponownie uruchomić i powtórzyć aktualizację)

pacman -Syuu 

2. Instalacja kompilatora włąściwie (toolchain) mingw w wersji 64 bit: 

pacman -S  mingw-w64-x86_64-toolchain

3.Instalacja qtCreator:

pacman -S  mingw-w64-x86_64-qt-creator

4 intalacja libmodbus:

pacman -S mingw-w64-x86_64-libmodbus-git
