ifdef SystemRoot
	RM = del /Q
	EXT = .exe
else
	ifeq ($(shell uname), Linux)
		RM = rm -f
		EXT =
	endif
endif

CC = g++
CFLAGS = -msse4.2 -O3 -fomit-frame-pointer -funroll-loops -lm -I .

all: trie
	$(CC) $(CFLAGS) -o main$(EXT) trie.o main.o

trie:
	$(CC) $(CFLAGS) -c trie.cpp main.cpp

clean:
	$(RM) trie.o main.o main$(EXT)
