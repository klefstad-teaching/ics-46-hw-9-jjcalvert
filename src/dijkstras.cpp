#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include <algorithm>
#include "dijkstras.h"

using namespace std;
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    
    int numVertices = G.numVertices;
    vector<int> distances(numVertices, INF);
    vector<bool> visited(numVertices, false);
    previous.assign(numVertices, -1);

    distances[source] = 0;

    priority_queue<Node, vector<Node>, greater<Node>> minHeap; //pair<vertex,weight> must change, maxheap by default
    minHeap.push({source,0});
    while(!minHeap.empty()){
        int u = minHeap.top().vertex;
        minHeap.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(Edge edge: G[u]){
            int v = edge.dst;
            int weight = edge.weight;
            if(!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v, distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> path;
    if (distances[destination] == INF) return path;
    for (int v = destination; v != -1; v = previous[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total){
    for (int vertex : v) {
        cout << vertex << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;
}
