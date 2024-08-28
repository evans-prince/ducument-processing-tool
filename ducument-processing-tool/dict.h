// Do NOT add any other includes
#include <string> 
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class trivec {
    public:
    // vector<trivec*>child;
    trivec* child[68];
    int value;
    
    trivec(){
        value=0;
        for(int i=0;i<68;i++){
            child[i]=nullptr;
        }
    }
    ~trivec(){
        for(trivec* k: child ){
            delete k;
        }
//        delete[] child;
    }
    void insert(trivec *&node ,string ram){
        trivec* current=node;
        for(int j=0;j<ram.size();j++){
            int i=ram[j];
            // if(i>93 && i<123){
            //     i=i-73;
            // }else if(i<91 && i>64 ){
            //     i=i-41;
            // }else if(i>46 && i<58){
            //     i=i-41;
            // }else if(i==42||i==43){
            //     i=i-38;
            // }else if(i<39){
            //     i=i-35;
            // }else if(i>59 && i<63){
            //     i=i-43;
            // }else if(i==92){
            //     i=i-72;
            // }else if(i==124){
            //     i=i-74;
            // }else if(i==126){
            //     i=i-75;
            // }
            if(i>=97 && i<=122){
                i=i-32;
            }
            if(i>122){
                i=i-26;
            }
            i=i-35;
            if(current->child[i]==nullptr){
                current->child[i]=new trivec();
            }
            current=current->child[i];
        }
        current->value=current->value+1;
    }

    int search(string ram){
        trivec* current=this;
        for(char c : ram){
            int i=c;
            // if(i>93 && i<123){
            //     i=i-73;
            // }else if(i<91 && i>64 ){
            //     i=i-41;
            // }else if(i>46 && i<58){
            //     i=i-41;
            // }else if(i==42||i==43){
            //     i=i-38;
            // }else if(i<39){
            //     i=i-35;
            // }else if(i>59 && i<63){
            //     i=i-43;
            // }else if(i==92){
            //     i=i-72;
            // }else if(i==124){
            //     i=i-74;
            // }else if(i==126){
            //     i=i-75;
            // }
            if(i>=97 && i<=122){
                i=i-32;
            }
            if(i>122){
                i=i-26;
            }
            i=i-35;
            if(current->child[i]==nullptr){
                current->child[i]=new trivec();
            }
            current=current->child[i];
        }
        return current->value;

    }

};

class Dict {
private:
    // You can add attributes/helper functions here

public: 
    trivec* node;
    /* Please do not touch the attributes and 
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    
    Dict();

    ~Dict();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    int get_word_count(string word);

    void dump_dictionary(string filename);

    /* -----------------------------------------*/
};
