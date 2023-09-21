all: main.o HashTable.o ../Arraylist/Arraylist.o
	g++ main.o HashTable.o ../Arraylist/Arraylist.o -o HashTable
main.o: main.cpp
	g++ -c main.cpp -o main.o
HashTable.o: HashTable.cpp
	g++ -c HashTable.cpp -o HashTable.o
../Arraylist/Arraylist.o: ../Arraylist/Arraylist.cpp
	g++ -c ../Arraylist/Arraylist.cpp -o ../Arraylist/Arraylist.o

clean:
	rm -f *.o ../Arraylist/Arraylist.o HashTable