all:
	g++ -I src/include -L src/lib -o main src/main.cpp -lmingw32 -lSDL2main -lSDl2