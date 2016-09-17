PROGRAMNAME=electrotest

# Build program and libraries and use local version
all:
	make lib
	mkdir -p lib
	mv lib*.so lib/
	gcc main.c -o $(PROGRAMNAME) -L./lib -lpower -Wl,-rpath,./lib

# Only build libraries
lib:
	gcc -c -fPIC libpower.c
	gcc -shared -fPIC -o libpower.so libpower.o 

# Copy program and libs to appropriate directories and use global version
install:

clean:
	rm -rf lib *.o $(PROGRAMNAME)
