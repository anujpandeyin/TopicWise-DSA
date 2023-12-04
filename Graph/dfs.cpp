// #include <iostream>
// #include <vector>
// #include <unordered_set>

// using namespace std;

// void DFS(int currentNode, vector<vector<int>>& adjacencyList, vector<bool>& visited) {
//     visited[currentNode] = true;
//     cout << currentNode << " ";

//     for (int neighbor : adjacencyList[currentNode]) {
//         if (!visited[neighbor]) {
//             DFS(neighbor, adjacencyList, visited);
//         }
//     }
// }

// vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>>& edges) {
//     vector<vector<int>> adjacencyList(V);  // Adjacency list representation of the graph
//     vector<bool> visited(V, false);        // To keep track of visited nodes

//     // Create the adjacency list from the given edges
//     for (int i = 0; i < E; ++i) {
//         int u = edges[i][0];
//         int v = edges[i][1];
//         adjacencyList[u].push_back(v);
//         adjacencyList[v].push_back(u); // Assuming an undirected graph
//     }

//     // Perform DFS starting from each unvisited node
//     for (int i = 0; i < V; ++i) {
//         if (!visited[i]) {
//             cout << "DFS starting from node " << i << ": ";
//             DFS(i, adjacencyList, visited);
//             cout << endl;
//         }
//     }

//     return adjacencyList;  // You can choose to return the adjacency list if needed
// }

// int main() {
//     // Example usage
//     int V = 5;  // Number of vertices
//     int E = 4;  // Number of edges
//     vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}};

//     vector<vector<int>> adjacencyList = depthFirstSearch(V, E, edges);

//     return 0;
// }

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Graph {
public:
    void addEdge(int u, int v) {
        adjList[u].insert(v);
        adjList[v].insert(u); // Assuming an undirected graph
    }

    void DFS(int startNode) {
        unordered_set<int> visited;
        DFSHelper(startNode, visited);
    }

private:
    unordered_map<int, unordered_set<int>> adjList;

    void DFSHelper(int currentNode, unordered_set<int>& visited) {
        cout << currentNode << " ";
        visited.insert(currentNode);

        for (int neighbor : adjList[currentNode]) {
            if (visited.find(neighbor) == visited.end()) {
                DFSHelper(neighbor, visited);
            }
        }
    }
};

int main() {
    Graph g;

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS starting from node 2: ";
    g.DFS(2);

    return 0;
}
