name=electrotest
lpath=/usr/lib
bpath=/usr/bin

# Build program and libraries and use local version
all:
	make clean
	make lib
	mkdir -p lib
	mv -f lib*.so lib
	gcc main.c -o $(name) -L./lib -lpower -lcomponent -lresistance -Wl,-rpath,./lib

# Only build libraries
lib:
	gcc -c -fPIC libpower.c
	gcc -shared -fPIC -o libpower.so libpower.o
	gcc -c -fPIC libcomponent.c
	gcc -shared -fPIC -o libcomponent.so libcomponent.o
	gcc -c -fPIC libresistance.c
	gcc -shared -fPIC -o libresistance.so libresistance.o

# Copy program and libs to appropriate directories and use global version
install:
	make clean
	make lib
	sudo mv -u *.so $(lpath)
	gcc main.c -o $(name) -lpower -lcomponent
	sudo mv -u $(name) $(bpath)

uninstall:
	sudo rm -f $(lpath)/libpower.so $(lpath)/libcomponent.so $(bpath)/$(name)

clean:
	rm -rf lib *.o *.so $(name)

# For testing purposes only
test_libcomponent:
	gcc -o libcomponent.o -c libcomponent.c
	gcc -shared -o libcomponent.so libcomponent.o
	gcc -o test_libcomponent libcomponent_test.c libcomponent.so
