#include "DataStructures/List/LinearList.hpp"
#include "DataStructures/List/LinkedList.hpp"
#include <vector>
#include <limits>
#include <queue>
#include <stdexcept>

typedef LinearList<LinearList<int>> AdjList;

// template <typename T>

class Graph {

    private:
    size_t V;
    size_t E;
    AdjList data;

    int minVertex(int distance[], bool visited[], bool discovered[]){
        int vertex = -1;
        int lower = std::numeric_limits<int>::max();
        for (int i = 0; i < V; i++){
            if ( !visited[i] && discovered[i] && distance[i] < lower ){
                vertex = i;
                lower = distance[i];
            }
        }

        return vertex;
    }

    int maxVertex(int distance[], bool visited[], bool discovered[]){
        int vertex = -1;
        int greater = std::numeric_limits<int>::min();
        for (int i = 0; i < V; i++){
            if ( !visited[i] && discovered[i] && distance[i] > greater ){
                vertex = i;
                greater = distance[i];
            }
        }

        return vertex;
    }

    bool inline hasEdge(int u, int v){ return data[u][v] != std::numeric_limits<int>::max(); }

    LinearList<int> buildPath(const int& u, int v, int prev[]) {

        LinearList<int> shortestPath;

        if (prev[v] != -1) {

            while (v != u) {
                shortestPath.pushFront(v);
                v = prev[v];
            }

            shortestPath.pushFront(v);
        }

        

        return shortestPath;
    }

    public:
    Graph (size_t V, size_t E) {

        this->V = V;
        this->E = E;
        data = AdjList(V);

        for ( size_t i = 0; i < V; i++ ) {
            data[i] = LinearList<int>(V); 

            for ( int& edge : data[i] ) edge = std::numeric_limits<int>::max();
        }
    }

     Graph(const std::vector<std::vector<std::pair<int, int>>>& adjacencyList) {
        this->V = adjacencyList.size();
        this->E = 0;
        data = AdjList(V);

        for (size_t u = 0; u < V; ++u) {
            data[u] = LinearList<int>(V);  

            for (int i = 0; i < V; i++) { data[u][i] = std::numeric_limits<int>::max();}

            // Preenche as listas de adjacência com os valores fornecidos
            for (const auto& [v, weight] : adjacencyList[u]) {
                if (v >= V) {
                    throw std::out_of_range("Erro: Vértice fora do limite.");
                }
                std::cout << "u: " << u << " v: " << v << " weight: " << weight << "\n";
                data[u][v] = weight;
                this->E++;  // Incrementa o número de arestas
            }
        }
    }

    void insert (int u, int v, int weigth = 1) {
        if (u >= V || v >= V || v < 0 || u < 0) {
            throw std::out_of_range("Error: Invalid edge in Graph.");
        }
        data[u][v] = weigth;
        E++;
    }

    void remove (int u, int v){
        if (u >= V || v >= V || v < 0 || u < 0) {
            throw std::out_of_range("Error: Invalid edge in Graph.");
        }
        data[u][v] = std::numeric_limits<int>::max();
        E--;
    }


    void print() const {
        for (size_t i = 0; i < V; i++) {
            std::cout << "Vertex " << i << ": ";
            for (size_t j = 0; j < data[i].getSize(); j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }



    LinearList<int> minmax(int u, int v){
        int prev[V];
        bool visited[V];
        bool discovered[V];
        int distance[V];

        for (int i = 0; i < V; i++){
            distance[i] = std::numeric_limits<int>::max();
            visited[i] = discovered[i] = false;
            prev[i] = -1;
        } 

        distance[u] = 0;
        discovered[u] = true;

        for (int i = 0; i < V; i++){

            int vertex = minVertex(distance, visited, discovered);

            visited[vertex] = true;

            if (vertex == v) break;

            for (int neighbour = 0; neighbour < V; neighbour++){


                if (!visited[neighbour] && hasEdge(vertex, neighbour)){
                    discovered[neighbour] = true;

                    float flow = std::max(distance[vertex], data[vertex][neighbour]);
                    if (distance[neighbour] > flow){
                        distance[neighbour] = flow;
                        prev[neighbour] = vertex;
                    }
                }
            }
        }

            std::cout << "{";
        for(int i = 0; i < V; i++){
            std::cout << "{" << i << ", " << distance[i] << "}, ";
        }
            std::cout << "}" << std::endl;
        

        return buildPath(u, v, prev);
    }


    LinearList<int> maxmin(int u, int v){
        int prev[V];
        bool visited[V];
        bool discovered[V];
        int distance[V];

        for (int i = 0; i < V; i++){
            distance[i] = std::numeric_limits<int>::min();
            visited[i] = discovered[i] = false;
            prev[i] = -1;
        } 

        distance[u] = 0;
        discovered[u] = true;

        for (int i = 0; i < V; i++){

            int vertex = maxVertex(distance, visited, discovered);

            visited[vertex] = true;

            if (vertex == v) break;

            for (int neighbour = 0; neighbour < V; neighbour++){

                if (!visited[neighbour] && hasEdge(vertex, neighbour)){
                    discovered[neighbour] = true;

                    float flow = std::min(distance[vertex], data[vertex][neighbour]);
                    if (distance[neighbour] < flow){
                        distance[neighbour] = flow;
                        prev[neighbour] = vertex;
                    }
                }
            }
        }

        return buildPath(u, v, prev);
    }

    LinearList<int> dijkstra(int u){
        int prev[V];
        bool visited[V];
        bool discovered[V];
        int distance[V];
    
        for (int i = 0; i < V; i++){
            distance[i] = std::numeric_limits<int>::max();
            visited[i] = discovered[i] = false;
            prev[i] = -1;
        } 
    
        distance[u] = 0;
        discovered[u] = true;
    
        for (int i = 0; i < V; i++){
    
            int vertex = minVertex(distance, visited, discovered);
    
            visited[vertex] = true;
    
            for (int neighbour = 0; neighbour < V; neighbour++){
    
                if (!visited[neighbour] && hasEdge(vertex, neighbour)){
                    discovered[neighbour] = true;
    
                    float accumulatedW = distance[vertex] + data[vertex][neighbour];
                    if (distance[neighbour] > accumulatedW){
                        distance[neighbour] = accumulatedW;
                        prev[neighbour] = vertex;
                    }
                }
            }
        }

        LinearList<int> distances = LinearList<int>(V);
        for(int i = 0; i < V; i++){ distances.pushBack(distance[i]); }
        
        return distances;
    }

};
