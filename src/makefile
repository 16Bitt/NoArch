build-common:
	cd common && make

noarch-i386: build-common
	cd runtime/i386 && make

noarch-linux: build-common
	cd runtime/linux && make
	gcc *.o -o noarch

clean:
	-rm *.o noarch
