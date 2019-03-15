CC=clang++#g++
LD=clang++#g++
CFLAGS=-Weverything -Wno-c++98-compat #-std=c++11 -Wall -fPIC
LDFLAGS=
EXEC=main
RM=rm -f *.o
OUTPUT=anagrams

all:$(EXEC)

main: main.o anagrams.o
	@$(LD) -o $(OUTPUT) $^ $(LDFLAGS)

main.o: main.cpp anagrams.hpp
	@$(CC) -c $< -o $@ $(CFLAGS)

anagrams.o: anagrams.cpp anagrams.hpp
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(RM)

clean-all:
	@$(RM) $(OUTPUT)