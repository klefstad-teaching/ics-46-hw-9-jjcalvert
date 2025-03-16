#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include "dijkstras.h"


// vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    // int numVertices = graph.size();
    // vector<int> distances(numVertices, INF);
    // vector<bool> visited(numVertices);

    // distances[source] = 0;
    // previous[source] = -1;

    // priority_queue<pair<int,int>> minHeap; //pair<vertex,weight> must change, maxheap by default
    // minHeap.push({source,0})
    // while(!minHeap.empty()){
    //     int u = minHeap.extract_shortest_path().first;
    //     if(visited[u]) continue;
    //     visited[u] = true;
    //     for(Edge edge: graph[u]){
    //         int v = edge.dest;
    //         int weight = edge.second;
    //         if(!visited[v] && distances[u] + weight < distances[v]){
    //             distances[v] = distances[u] + weight;
    //             previous[v] = u;
    //             minHeap.push({v, distances[v]});
    //         }
    //     }
    // }
    // return distances;
// }
// vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination);
void print_path(const vector<int>& v, int total){
    for (int vertex : path) {
        cout << vertex << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}
