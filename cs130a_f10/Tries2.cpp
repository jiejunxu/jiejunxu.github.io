#include <iostream>
#include <string>
const int TrieMaxElem = 26;
const int StrMaxElem = 80;

// Counts the total number of words that includes the letter 'a' and contains
// at least 2 leeters but no more than 6 letters
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
	int Count(TrieNode* p, int i, bool b, int num);

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
		counter = counter + Count(root->GetPtr(i), i, false, 1);
	return counter;
}

//Due to the implementation of insert, we are only coutning unique strings
int Trie::Count(TrieNode* p, int j, bool b, int num){
	int counter=0;
	if(p==0) return 0;
	if(j==0)
		b = true;
	for(int i=0; i<TrieMaxElem; i++){
		if(i==0||b)
			counter=counter + Count(p->GetPtr(i), i, true, num+1);
		else
			counter=counter + Count(p->GetPtr(i), i, false,num+1);
	}
	if((p->GetStrEnds() && b) && num<=6 && num>=2)
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

