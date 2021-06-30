#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
    public:
        float density() override
        {
            int Nedges = 0;
            int Nvertex = 0;
            for(auto it : vertexes){
                Nedges += it->edges.size();
                Nvertex += 1;
            }

            float densidad = (Nedges)/(Nvertex*(Nvertex-1));
            return densidad;

        }
        bool isDense(float threshold = 0.5) override
        {
            int densidad = this->density();
            return (densidad > threshold ? true : false);
        }
};

#endif