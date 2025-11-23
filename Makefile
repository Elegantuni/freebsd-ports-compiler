portscompiler:
	clang -o portscompiler portscompiler.c

install: portscompiler
	cp portscompiler /usr/local/bin/

clean:
	rm -f portscompiler

