// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class sent{
public:
int book;
int page;
int para;
int sn;
string st;
sent(int b,int pg,int pr,int s,string sr){
  book=b;
  page=pg;
  para=pr;  
  sn=s;
  st=sr;
}
};

class SearchEngine {
private:
vector<sent*> vec;
public: 
    
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node* search(string pattern, int& n_matches);

    /* -----------------------------------------*/
};