// Do NOT add any other includes
#include "search.h"
#include<fstream>

SearchEngine::SearchEngine(){
  
}

SearchEngine::~SearchEngine(){
    // Implement your function here  
}

void SearchEngine::insert_sentence(int b_code, int pg, int para, int s_no, string sen){
     for (char &c : sen) {
        c = std::tolower(c);
    }
    vec.push_back(new sent(b_code,pg,para,s_no,sen));
}

Node* SearchEngine::search(string patt, int& n_matches){
    n_matches=0;
    string pattern=patt;
       for (char &c : pattern) {
        c = std::tolower(c);
    }
    string s;
    int sz=pattern.size();
    Node* root=nullptr;
    Node* end=nullptr;
    for(sent* k : vec){
        char c=7;
        string e="";
        e=e+c;
        s=pattern+e+k->st;
        int n = s.size();
        vector<int> z(n);
        int x = 0, y = 0;
        for (int i = 1; i < n; i++) {
            z[i] = max(0,min(z[i-x],y-i+1));
            while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
                x = i; y = i+z[i]; z[i]++;
        }
}
for(int i=0;i<n;i++){
    if(z[i]==sz){
        if(root==nullptr){
            root=new Node(k->book,k->page,k->para,k->sn,i-sz-1);
            end=root;
            end->right=nullptr;
        }
        else{
            end->right=new Node(k->book,k->page,k->para,k->sn,i-sz-1);
            end=end->right;
            end->right=nullptr;
        }
        n_matches++;
    }
}
    }
   return root;
}
