binary: Lab3.o
	g++ Lab3.o -o binary

Lab3.o: Lab3.cpp
	g++ -c Lab3.cpp

clean:
	rm -rf *.o binary
