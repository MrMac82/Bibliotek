name=electrotest
lpath=/usr/lib
bpath=/usr/bin

# Build program and libraries and use local version
all:
	make clean
	make lib
	mkdir -p lib
	mv -f lib*.so lib
	gcc main.c -o $(name) -L./lib -lpower -Wl,-rpath,./lib

# Only build libraries
lib:
	gcc -c -fPIC libpower.c
	gcc -shared -fPIC -o libpower.so libpower.o 

# Copy program and libs to appropriate directories and use global version
install:
	make clean
	make lib
	sudo mv -u *.so $(lpath)
	gcc main.c -o $(name) -lpower
	sudo mv -u $(name) $(bpath)

uninstall:
	sudo rm -f $(lpath)/libpower.so $(bpath)/$(name) 

clean:
	rm -rf lib *.o $(name) 
