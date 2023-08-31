transporter: main.o train.o bus.o cargo.o person.o dynamicarray.o
	g++ -o transporter main.o train.o bus.o cargo.o person.o dynamicarray.o

main.o: main.cpp train.h bus.h dynamicarray.h
	g++ -c main.cpp

train.o: train.cpp train.h dynamicarray.h
	g++ -c train.cpp

bus.o: bus.cpp bus.h dynamicarray.h
	g++ -c bus.cpp

cargo.o: cargo.cpp cargo.h
	g++ -c cargo.cpp

person.o: person.cpp person.h
	g++ -c person.cpp

dynamicarray.o: dynamicarray.cpp dynamicarray.h
	g++ -c dynamicarray.cpp

clean:
	rm *.o transporter