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
    Edge(Vertex<TV, TE>* vertex_1, Vertex<TV, TE>* vertex_2, TE _weight){
        this->vertexes[0] = vertex_1;
        this->vertexes[1] = vertex_2;
        this->weight = _weight;
    }
    void killSelf(){
        this->vertexes[0] = nullptr;
        this->vertexes[1] = nullptr;
        delete this;
    }
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    string id;
    list<Edge<TV, TE>*> edges;
    Vertex(TV _data, string _id){
        this->data = _data;
        this->id = _id;
    }
    void killSelf(){
        edges.clear();
        delete this;
    }
};

template<typename TV, typename TE>
class Graph{
protected:
    unordered_map<string, Vertex<TV, TE>*>  vertexes;
    
public:
    Graph() = default;
    virtual ~Graph() { this->clear() };
    bool insertVertex(string id, TV vertex) = 0;   
    bool createEdge(string id1, string id2, TE w) = 0;     
    bool deleteVertex(string id) = 0;     
    bool deleteEdge(string id) = 0;   
    TE &operator()(string start, string end)= 0;  
    float density() = 0;
    bool isDense(float threshold = 0.5) = 0;
    bool isConnected()= 0;
    bool isStronglyConnected() throw();
    bool empty();
    void clear()= 0;  
      
    void displayVertex(string id)= 0;
    bool findById(string id) = 0;
    void display() = 0;
};

#endif