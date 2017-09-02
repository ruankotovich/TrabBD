### C Arguments
CC=g++
CFLAGS=-std=c++11 -g -Wall

### Compiler Arguments
INCLUDE_PATH=src
SRC_PATH=src

all: upload findrec seek1 seek2 main debug clean

seek1:

seek2:

debug: debug.o
	$(CC) -o debug iohandler.o debug.o btree.o article.o block.o hashfilefactory.o $(CFLAGS)

main: main.o
	$(CC) -o main iohandler.o main.o btree.o article.o block.o hashfilefactory.o $(CFLAGS)

main.o: btree.o $(SRC_PATH)/main.cpp
	$(CC) -c $(SRC_PATH)/main.cpp -I/$(INCLUDE_PATH) $(CFLAGS)
	
debug.o: btree.o $(SRC_PATH)/debug.cpp
	$(CC) -c $(SRC_PATH)/debug.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

upload: upload.o  
	$(CC) -o upload iohandler.o upload.o btree.o article.o block.o hashfilefactory.o $(CFLAGS)

findrec:findrec.o
	$(CC) -o findrec iohandler.o findrec.o article.o block.o hashfilefactory.o $(CFLAGS)

findrec.o: hashfilefactory.o $(SRC_PATH)/findrec.cpp
	$(CC) -c $(SRC_PATH)/findrec.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

upload.o: btree.o $(SRC_PATH)/upload.cpp
	$(CC) -c $(SRC_PATH)/upload.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

hashfilefactory.o: iohandler.o block.o $(SRC_PATH)/hashfilefactory.cpp $(INCLUDE_PATH)/hashfilefactory.hpp
	$(CC) -c $(SRC_PATH)/hashfilefactory.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

btree.o: hashfilefactory.o $(SRC_PATH)/btree.cpp $(INCLUDE_PATH)/btree.hpp
	$(CC) -c $(SRC_PATH)/btree.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

iohandler.o: article.o $(SRC_PATH)/iohandler.cpp $(INCLUDE_PATH)/iohandler.hpp
	$(CC) -c $(SRC_PATH)/iohandler.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

article.o: $(SRC_PATH)/article.cpp $(INCLUDE_PATH)/article.hpp
	$(CC) -c $(SRC_PATH)/article.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

block.o: article.o $(SRC_PATH)/block.cpp $(INCLUDE_PATH)/block.hpp
	$(CC) -c $(SRC_PATH)/block.cpp -I/$(INCLUDE_PATH) $(CFLAGS)

clean:
	rm -rf **.o
