#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "ladder.h"


void error(string word1, string word2, string msg){
    cout << "Error: " << msg <<" "<< word1 << "and " << word2 << endl;
}


bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
    int l1 = str1.size();
    int l2 = str2.size();
    if (abs(l1 - l2) > d){ // check if +or-1 letter away
        return false;
    }

    int actualD = 0;
    int index1 = 0;
    int index2 = 0;
    while (index1 < l1 && index2 < l2) { // for each letter of string
        if (str1[index1] != str2[index2]) {
            actualD++;
            if (actualD > d) return false;
            if (l1 > l2) index1++; //delete
            else if (l1 < l2) index2++; //insert
            else { //replace
                index1++;
                index2++; 
            }
        } else {
            index1++; 
            index2++;
        }
    }
    return (actualD == 1) || (actualD == 0 && l1 != l2);
}

bool is_adjacent(const string& word1, const string& word2){
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    if(begin_word == end_word){
        return {begin_word}; // possibly cahnge to set with only begin word
    }
    queue<vector<string>> ladder_queue;
    set<string> visited;
    ladder_queue.push({begin_word});
    visited.insert(begin_word);

    while(!ladder_queue.empty()){
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back();
        for(string word: word_list){
            if(is_adjacent(last_word, word)){
                if(visited.find(word) == visited.end()){
                    vector<string> new_ladder = ladder;
                    new_ladder.push_back(word);

                    if(word == end_word){
                        return new_ladder;
                    }

                    ladder_queue.push(new_ladder);
                    visited.insert(word);
                }
            }
        }
    }
    return {};
}

void load_words(set<string> & word_list, const string& file_name){
    ifstream file(file_name);
    string word;
    if (!file) {
        return;
    }
    while (file >> word) {
        word_list.insert(word);
    }
}

void print_word_ladder(const vector<string>& ladder){
    for (size_t i = 0; i < ladder.size(); ++i) {
        cout << ladder[i];
        if (i < ladder.size() - 1) cout << " -> ";
    }
    cout << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}