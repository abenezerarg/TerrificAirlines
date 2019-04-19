#ifndef GRAPH_HPP
#define GRAPH_HPP

////////////////////////////////////////////////////////////////////////////////////////////
//
//  I am not very familar with graph 0.0
//  This code still have so many error feel free to change any thing or rewrite completely
//  I will work on this later
//
////////////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
using namespace std;

#define length 100

struct vertex;
/*This is the struct for the adjacent vertices for each
vertex in the graph. */

struct Edge
{
    vertex *v;
    int Tdepart;  //departure time
    int Tarrive;  //arriveal time
};


struct vertex
{
    string Location;
    bool   visited;
    vector<Edge> Edges; //stores edges to adjacent vertices
};

class Graph
{
  public:
    Graph();
    ~Graph();
    void addVertex(std::string cityName);
    void addEdge(std::string city1, std::string city2, int distance);
    void displayEdges();
    void printDFT();
    void printBFT();
    void setAllVerticesUnvisited();

    bool Searchflight(string Depart, string Arrive);



  private:
    vector<vertex> vertices; //stores vertices

    vertex *findVertex(std::string name);
    void BFT_traversal(vertex *v);
    void DFT_traversal(vertex *v);

};

#endif // GRAPH_HPP
