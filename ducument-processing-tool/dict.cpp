// Do NOT add any other includes
#include "dict.h"
#include "fstream"

char indextochar(int i){
    i=i+35;
    if(i>=65 && i<=90){
        i=i+32;
    }
    else if(i>96){
        i=i+26;
    }
    char x=i;
    return x;
}

Dict::Dict(){
    node=new trivec();
}

Dict::~Dict(){
    delete  node;
}

bool isbreaker(char k){
    char arr[]=" (\")!'(),-.:;?@[]{}";
    for(int i=0;i<sizeof(arr);i++){
        if(arr[i]==k){
            return true;
        }
    }
    return false;
}

void Dict::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    string beta = "";
    for (char c : sentence) {
        if(isbreaker(c)){
            if (!beta.empty()) {
                node->insert(node,beta);
                beta = "";
            }
        }
        else{
            beta = beta + c;
        }
    }
    if (!beta.empty()) {
        node->insert(node,beta);
        beta = "";
    }
}

int Dict::get_word_count(string word){
    return node->search(word);
}

void dump(trivec* root,string hem,ofstream& file){
    if(root==nullptr){
        return ;
    }
    if(root->value!=0){
        file<<hem<<", "<<to_string(root->value)<<endl;
    }
    for(int i=0;i<68;i++){
        char c=indextochar(i);
        dump(root->child[i],hem+c,file);
    }
}
void Dict::dump_dictionary(string filename){
    std::ofstream file(filename,std::ios::app);
    dump(node,"",file);
    file.close();
}

 int main() {
     // Create a dictionary
     Dict dictionary;
     // ('1', 0, 0, 1, 0) VOL.1: 1884 30 NOVEMBER, 1896 1

     // Insert sentences into the dictionary
     dictionary.insert_sentence(1, 1, 1, 1, "VOL.1: 1884 30 NOVEMBER, 1896 1");
     dictionary.insert_sentence(1, 1, 1, 1, "My name  hemant is  ~hemant my birth  date is 0511 ");

      dictionary.insert_sentence(1, 1, 1, 2, "Another sentence for testing.");

     // Dump the dictionary to a file
     // dictionary.dump_dictionary("dictionary.txt");

     // Get the word count
     std::string word_to_search = "1";
     int word_count = dictionary.get_word_count(word_to_search);
     std::cout << "Word count of '" << word_to_search << "': " << word_count << std::endl;

     // dictionary.dump_dictionary("hemant.txt");

     return 0;
 }
// int main() {
//     Dict kam;
//     std::string sen;
    
//     // Open the input file
//     std::ifstream inputFile("input.txt");
    
//     if (!inputFile) {
//         std::cerr << "Error: Failed to open input file." << std::endl;
//         return 1;
//     }

//     // Read sentences from the input file
//     int i=1;
//     while (std::getline(inputFile, sen)) {
//         kam.insert_sentence(1, 1, 1, i, sen);
//         i++;
//         cout<<i;
//     }
//     inputFile.close();
//     int p = 0;
//     std::string pt;
//     kam.dump_dictionary("ramgarhia.txt");
//     // Open the output file
//     // std::ofstream outputFile("output.txt");
    
//     // if (!outputFile) {
//     //     std::cerr << "Error: Failed to open output file." << std::endl;
//     //     return 1;
//     // }

//     // Read search queries from the input file and write results to the output file
//     // while () {
//     //     if(pt=="!"){
//     //         break;
//     //     }
//     // Close the output file
//     return 0;
// }

