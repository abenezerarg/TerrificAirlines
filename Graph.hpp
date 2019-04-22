#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <string>
#include "PriorityQ.hpp"

using namespace std;

struct vertex;

/*This is the struct for the adjacent vertices for each
vertex in the graph. */

struct Edge
{
    vertex *v;
    int distance;
    int duration;
    PriorityQueue firstClass = PriorityQueue(25);
    PriorityQueue businessClass = PriorityQueue(50);
    PriorityQueue coachClass = PriorityQueue(100);

};

/*this is the struct for each vertex in the graph. */
struct vertex
{
    std::string cityName;
    bool visited;
    std::vector<Edge> Edges; //stores edges to adjacent vertices
};

class Graph
{
  public:
    Graph();
    ~Graph();
    void addVertex(std::string cityName);
    void addEdge(std::string city1, std::string city2, int distance, int duration);
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
