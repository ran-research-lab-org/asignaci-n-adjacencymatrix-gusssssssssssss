#include <iostream>
#include <vector>
#include <stdexcept>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    // Crea un vector de 2D n x n
    Graph(int n) : numVertices(n), adjMatrix(n, std::vector<int>(n, 0)) {}

    // Add a vertex from node u to node v
    void addEdge(int u, int v) {
        if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
            adjMatrix[u][v] = 1;
        } else {
            std::out_of_range("Vertice fuera de rango");
        }
    }

    // Imprime la matriz de adyacencias
    void print() const {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

    // Implementar!! 
    // Devuelve la cantidad de aristas
    int numEdges() const {
        int count = 0;
        for(int i = 0; i < numVertices; ++i){
            for(int j = 0; j < numVertices; ++j){
                if(adjMatrix[i][j] == 1) ++count; //Adds all 1's in adyacency matrix
            }
        }
        return count;
    }

    // Completa esta función
    // Devuelve el in-degree de un vertice
    int inDegree(int u) const {
        if (u < 0 || u >= numVertices)
            throw std::out_of_range("Vertice fuera de rango");
        int inDeg = 0;
        for(int i = 0; i < numVertices; ++i){
            if(adjMatrix[i][u] == 1) ++inDeg; //Goes through column of adyacency matrix and adds all 1's
        }
        return inDeg;
    }

    // Completa esta función
    // Devuelve cierto si u es el nodo con mayor inDegree.
    // En caso de que haya varios nodos que tengan el mayor inDegree,
    // devuelve true si u es uno de ellos
    bool isInfluencer(int u) const  {
        std::vector<int> all;
        int maxInfluence = 0;
        for(int i = 0; i < numVertices; ++i){
            if(inDegree(i) > maxInfluence) {all = {i}; maxInfluence = inDegree(i);} // if it finds greater degree resets vector with all influencers
            else if(inDegree(i) == maxInfluence) all.push_back(i); // adds influencer
        }
        for(int i : all) if(i == u) return true;
        return false;
    }
};

