#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    std::list<Edge<TV, TE>*> edges;
};

template<typename TV, typename TE>
class Graph{
private:    
    std::unordered_map<string, Vertex<TV, TE>*>  vertexes;
    
public:

    /*TODO:
    -> deleteVertex();
    -> deleteEdge();
    -> isConnected();
    ->isStronglyCoonnected() throw();
    */
    bool insertVertex(string id, TV vertex) = 0;   
    bool createEdge(string id1, string id2, TE w) = 0; 

    //TODO: Falta implementar funciones de eliminación
    bool deleteVertex(string id) = 0;     
    bool deleteEdge(string id) = 0;   
    TE &operator()(string start, string end)= 0;  
    //* Implementando en ambos tipos de grafos
    virtual float density() = 0;
    virtual bool isDense(float threshold = 0.5) = 0;

    //! No implementado
    bool isConnected()= 0;
    bool isStronglyConnected() throw();
    bool empty();
    void clear()= 0;  
      
    void displayVertex(string id)= 0;
    bool findById(string id) = 0;
    void display() = 0;
};

#endif