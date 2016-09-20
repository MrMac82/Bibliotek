name=electrotest
lpath=/usr/lib
bpath=/usr/bin
CFLAGS=-fPIC
LFLAGS=-shared 
LDNAMES=$(patsubst lib%.c,%,$(wildcard lib*.c))
LDFLAGS =$(foreach library,$(LDNAMES),-l$(library))

# Build program and libraries and use local version
all: 
	make clean
	make lib
	mkdir -p lib
	mv -f lib*.so lib
	gcc main.c -o $(name) -L./lib $(LDFLAGS) -Wl,-rpath,./lib

# Only build libraries
lib%.o: lib%.c
	gcc -c $(CFLAGS) $<     

lib%.so: lib%.o
	gcc $(LFLAGS) -o $@ $<

lib: $(patsubst %.c,%.so,$(wildcard lib*.c))


# Copy program and libs to appropriate directories and use global version
install:
	make clean
	make lib
	sudo mv -u *.so $(lpath)
	gcc main.c -o $(name) $(LDFLAGS)
	sudo mv -u $(name) $(bpath)

uninstall:
	sudo rm -f $(lpath)/libpower.so $(lpath)/libcomponent.so $(bpath)/$(name)

clean:
	rm -rf lib *.o *.so $(name)

