#include <iostream>
#include <string>
const int TrieMaxElem = 26;
const int StrMaxElem = 80;

//Count the number of words in the dictionary which has at most 5 letters 
//and is a prefix of at least another word in the Trie

using namespace std;

class Trie;
class TrieNode {
private:
    bool StrEnds;
    TrieNode *ptr[TrieMaxElem];
public:
    TrieNode();
    void SetStrEnds(){StrEnds = true;}
    void UnSetStrEnds(){StrEnds = false;}
    bool GetStrEnds(){return StrEnds;}
    void SetPtr(int i, TrieNode* j){ptr[i]=j;}
    TrieNode* GetPtr(int i){return ptr[i];}
    
};

TrieNode::TrieNode(){
    StrEnds = false;
    for(int i=0; i<TrieMaxElem; i++)
       ptr[i] = 0;
}

class Trie {
public:
    Trie() ;
    void Readlist();
    void Insert(char  x[]);
    bool Member(char  x[]);
    void Delete(char  x[]);
	int Count();
	int Count(TrieNode* p, int num);

private:
    TrieNode *root;
};

Trie::Trie(){
    root = new TrieNode();
    root->SetStrEnds();
}

void Trie::Readlist(){
  int numtimes;
  char x[StrMaxElem];
  cin >> numtimes;
  for ( int i = 1 ; i <= numtimes ; i = i + 1 )
  {
     cin >> x;
     Insert( x );
  }
}

void Trie::Insert(char x[]) {
  TrieNode *current = root;
  int i = 0;
  while ( x[i] != '\0' )
   { int j = x[i] - 'a';
     if ( current->GetPtr(j) == 0 )
              current->SetPtr(j, new TrieNode());
     current = current->GetPtr(j);
     i = i + 1;
   }
  current->SetStrEnds();
}

int Trie::Count(){
	int counter = 0;
	for(int i=0;i<TrieMaxElem;i++)
		counter = counter + Count(root->GetPtr(i), 1);
	return counter;
}

//Due to the implementation of insert(), we are only coutning unique strings
int Trie::Count(TrieNode* p, int num){
	int counter=0;
	if(p==0) return 0;
	bool b = false;
	for (int i=0; i<TrieMaxElem; i++)
	{
		if(p->GetPtr(i)!=NULL)
			b=true;
		counter = counter + Count(p->GetPtr(i),num+1);
	}
	if((p->GetStrEnds() && b) && num<=5)
		counter++;
	return counter;
}

int main()
{

	int numtests;
	char newelem[StrMaxElem];
	Trie t;
	t.Readlist();
	cout<<endl<<" "<<t.Count()<<endl;

	return 0;
}


