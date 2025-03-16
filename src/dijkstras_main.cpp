#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include "dijkstras.h"


int main(){
    Graph G;
    string filename = "small.txt";
    file_to_graph(filename, G);

    int source = 0;
    vector<int> previous(G.numVertices);
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    for(int i = 0; i < 4; i++){
        vector<int> path = extract_shortest_path(distances, previous, i);
        int total_distance = distances[i];
        print_path(path, total_distance);
    }
    
    return 0;
}