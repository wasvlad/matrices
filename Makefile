include = /usr/local/include/WVL/matrices/
lib = /usr/local/lib/WVL/matrices/

.PHONY: install
install: create_libraries copy
	echo Installed

.PHONY: create_libraries
create_libraries:
	-mkdir /usr/local/include/WVL
	-mkdir /usr/local/include/WVL/matrices
	-mkdir /usr/local/lib/WVL/
	-mkdir /usr/local/lib/WVL/matrices

.PHONY: copy
copy: copyinclude
	echo Copied

.PHONY: copyinclude
copyinclude: $(include)vector.h $(include)matrix.h
	echo headers copied

$(include)vector.h: vector.h
	cp vector.h $(include)vector.h
	chmod 744 $(include)vector.h

$(include)matrix.h: matrix.h
	cp matrix.h $(include)matrix.h
	chmod 744 $(include)vector.h

.PHONY: test
test: install test.o
	./test.o
test.o: test.cpp  vectortests.h matrixtests.h
	g++ test.cpp /usr/local/lib/libgtest.a -o test.o


.PHONY: remove
remove: rminclude 

rminclude:
	-rm $(include)matrix.h
	-rm $(include)vector.h
