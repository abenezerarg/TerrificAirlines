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
    PriorityQueue* firstClass = new PriorityQueue(25);
    PriorityQueue* businessClass = new PriorityQueue(50);
    PriorityQueue* coachClass = new PriorityQueue(100);

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
    bool addMember(string name, string class_, string depart, string arrive, int bags);
    vertex *findVertex(std::string name);
    Edge * findEdge(string depart, string arrive);


  private:
    vector<vertex> vertices; //stores vertices

    void BFT_traversal(vertex *v);
    void DFT_traversal(vertex *v);

};

#endif // GRAPH_HPP
