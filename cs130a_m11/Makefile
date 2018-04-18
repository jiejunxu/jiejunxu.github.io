OBJS = main.o BasicNode.o BasicTrieNode.o Element.o ENode.o HeaderTrieNode.o Item.o Node.o Set.o STRep.o Trie.o TrieNode.o
FLAGS = -W -Wall -pedantic -g

all: $(OBJS)
	g++ $(FLAGS) -o main $(OBJS)

main.o: main.cpp

BasicNode.o: BasicNode.cpp BasicNode.h
	g++ $(FLAGS) -c BasicNode.cpp

BasicTrieNode.o: BasicTrieNode.cpp BasicTrieNode.h
	g++ $(FLAGS) -c BasicTrieNode.cpp

Element.o: Element.cpp Element.h
	g++ $(FLAGS) -c Element.cpp

ENode.o: ENode.cpp ENode.h
	g++ $(FLAGS) -c ENode.cpp

HeaderTrieNode.o: HeaderTrieNode.cpp HeaderTrieNode.h
	g++ $(FLAGS) -c HeaderTrieNode.cpp

Item.o: Item.cpp Item.h
	g++ $(FLAGS) -c ENode.cpp

Node.o: Node.cpp Node.h
	g++ $(FLAGS) -c Node.cpp

Set.o: Set.cpp Set.h
	g++ $(FLAGS) -c Set.cpp

STRep.o: STRep.cpp STRep.h
	g++ $(FLAGS) -c STRep.cpp

Trie.o: Trie.cpp Trie.h
	g++ $(FLAGS) -c Trie.cpp

TrieNode.o: TrieNode.cpp TrieNode.h
	g++ $(FLAGS) -c TrieNode.cpp