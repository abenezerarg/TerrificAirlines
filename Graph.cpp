#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

////////////////////////////////////////////////////////////////////////////////////////////
//
//  I am not very familar with graph 0.0
//  This code still have so many error feel free to change any thing or rewrite completely
//  I will work on this later
//
////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;

Graph::Graph(){};
Graph::~Graph(){};


void Graph::addEdge(string v1, string v2,int _Tdepart, int _Tarrive)
{
  Edge addE;
  for(int i = 0; i < vertices.size(); i++)
  {
    if(v1==vertices[i].Location)
    {
      for(int k = 0; k < vertices.size(); k++)
      {
        if(v2 == vertices[k].Location && i != k)
        {
          addE.v = &vertices[k];
          addE.Tdepart = _Tdepart;
          addE.Tarrive = _Tarrive;
          vertices[i].Edges.push_back(addE);
        }
      }
    }
  }
}

void Graph::addVertex(string AirportName)
{
  vertex newVertex;
  newVertex.Location = AirportName;
  vertices.push_back(newVertex);
}

void Graph::BFT_traversal(vertex *v)
{
  queue <vertex*> q;
  vertex *frontv = v;                       //put v to the frontv
  q.push(frontv);                           //store the first element to the head of the Q
  vertex *store;
  while(!q.empty())                         //if the Q is not empty
  {
    store = q.front();                      //store the head of the Q
    q.pop();                                //pop the front Q


      if (store -> visited == false)
      {
        cout<<store->Location<<endl;
         store -> visited = true;           //set the store has been visited
      }
      for (int i = 0; i < store->Edges.size(); i++) //loop through edges
      {
          if(!(store->Edges[i].v->visited))
          {
            q.push(store->Edges[i].v);              //push the edges to Q
          }
      }
  }
}


void Graph::printBFT()
{
  for(int i = 0; i < vertices.size(); i++) //set everything unvisited
  {
      vertices[i].visited = false;
  }
  for(int i=0; i < vertices.size(); i++) //travesal the departure city
  {
    BFT_traversal(&vertices[i]);
  }
}


void Graph::setAllVerticesUnvisited()
{
  for(int i = 0; i < vertices.size(); i++)
  vertices[i].visited = false;
}


void Graph::DFT_traversal(vertex *v, string destination)
{
  bool found = false;
    if (v -> visited == false)    //if not visited
      {
        cout<<"Possible connection: ";
        cout<<v->Location<<endl;  // print out the location
         v-> visited = true;      //set the vertices as visited
      }

      for (int i = 0; i < v->Edges.size(); i++)  //looping through that edges
      {
        if(!( v->Edges[i].v->visited) && (vertices[i]).Location != destination ))   //if the edges has not been visited
        {                                                                            //and the location is not what we are looking for
          DFT_traversal(v->Edges[i].v); //look for that vertice's edges
        }
        else
        {
          break;
          found = true;
        }
      }
      if(!found)
      {
        cout<<"Sorry, We went through every possible option but can not find the flight for you"<<endl;
      }
}


void Graph::printDFT()
{
  for(int i = 0; i < vertices.size(); i++) //set everything unvisited
    {
      vertices[i].visited = false;
    }
  for(int i = 0; i < vertices.size(); i++) //loop through every vertices
  {
    DFT_traversal(&vertices[i]);
  }
}


// I am having trouble coming up with the idea to print the Depart and Arrive Time together ????????
void Graph::displayFlight(string Depart, string Arrive) //how to display passenger flight with possible connection flights
{
  vertices * store;
  for(int i = 0; i < vertices.size(); i++) //loop through every
  {
    if(vertices[i].Location == Depart)
    {
      store = vertices[i];
      break;
    }
  }
  DFT_traversal(store,Arrive);
}
