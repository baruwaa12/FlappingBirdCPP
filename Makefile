all:
	g++ -I src/include -L src/lib -o output/main main.cpp -lmingw32 -lSDL2main -lSDl2