# freebsd-ports-compiler
Program to compile multiple packages from freebsd ports <br />
It enables to configure multiple packages and download all the packages you need.  Then disconnect from <br />
the internet and then compile and install those packages if you want.  This is good for laptops. <br />

A example is to run: <br />
portscompiler /usr/ports/x11/xorg /usr/ports/devel/cmake /usr/ports/shells/bash <br />

Compile with: <br />
gcc -o portscompiler portscompiler.c <br />
or <br />
clang -o portscompiler portscompiler.c <br />
Then put in your path and run with root privates, because it works on the existing ports. <br />
