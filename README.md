# Forza4
A simple Forza4 game in C

## Setup
You need a C compiler. I've used Mingw-w64 (a fork of the original Mingw with 64 bit support and a faster installing process): [http://mingw-w64.org/doku.php](http://mingw-w64.org/doku.php)

1) Launch the mingw-w64 setup
	- Set "x86_64" as processor
	- (Optional) Set "win32" as thread (possible values are "posix", "win32"; google for the differences)
	- Choose an installation path without spaces (for example, no "C:\Program Files\mingw-w64"; use "C:\mingw-w64")

2) Add the installation folder to the user's Path variable (PC > Properties > Advanced > Ambient Variables > User Variables > select Path > Modify > click New > add the mingw-w64 folder)

## Build
1) Open the terminal
2) Move to the folder with the source code
3) Launch `gcc name_of_source_file`
	-	(Optional) By default the executable will be named "a.exe"; use `gcc name_of_source_file -o name_of_executable` to get a file called "name_of_executable.exe
