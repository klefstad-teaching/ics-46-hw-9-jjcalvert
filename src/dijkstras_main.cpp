#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include "dijkstras.h"


int main(){
    set<string> word_list;
    cout << "testing load " << endl;
    load_words(word_list, "words.txt");

    vector<string> test_ladder =  {"cat", "cot", "dot", "dog"};
    print_word_ladder(test_ladder);

    // verify_word_ladder();
    return 0;
}