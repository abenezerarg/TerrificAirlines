#include "Graph.hpp"
#include <string>
#include <vector>
#include <queue>

using namespace std;

Graph::Graph(){}

Graph::~Graph(){}

void Graph::addVertex(string name){
  vertex * found = findVertex(name);

  if(found == NULL){
    vertex temp;
    temp.cityName = name;
    temp.visited = false;
    vertices.push_back(temp);
  }else{
    cout << "City already exists" << endl;
  }
}

void Graph::addEdge(string city1, string city2, int distance, int duration){
  vertex * c1 = findVertex(city1);
  vertex * c2 = findVertex(city2);
  if(c1 == NULL || c2 == NULL || c1 == c2){
    cout << "One or both of the cities do not exist" << endl;
    return;
  }else{
    Edge c1TOc2;
    c1TOc2.distance = distance;
    c1TOc2.duration = duration;
    c1TOc2.v = c2;
    for(int i = 0; i < vertices.size(); i++){
      if(vertices[i].cityName == city1){
        vertices[i].Edges.push_back(c1TOc2);
        cout << "hey" << endl;
        break;
      }
    }
  }
}

void Graph::displayEdges(){
  for(int i = 0; i <  vertices.size(); i++){
    cout << vertices[i].cityName << "-->";
    if(vertices[i].Edges.empty())
      cout << endl;
    else{
      for(int j = 0; j < vertices[i].Edges.size(); j++){
        cout << vertices[i].Edges[j].v->cityName << " (" << vertices[i].Edges[j].distance << " miles, " << vertices[i].Edges[j].duration << " min)";
        if(vertices[i].Edges[j].v->cityName == vertices[i].Edges.back().v->cityName)
          cout << endl;
        else
          cout << "***";
      }
    }
  }
}

void Graph::printDFT(){
  setAllVerticesUnvisited();

  for(int i = 0; i < vertices.size(); i++){
    if(!vertices[i].visited)
      cout << vertices[i].cityName << endl;
    DFT_traversal(&vertices[i]);
  }
}

void Graph::printBFT(){
  setAllVerticesUnvisited();

  for(int i = 0; i < vertices.size(); i++){
    if(!vertices[i].visited)
      cout << vertices[i].cityName << endl;
    BFT_traversal(&vertices[i]);
  }
}

void Graph::setAllVerticesUnvisited(){
  for(int i = 0; i < vertices.size(); i++){
    vertices[i].visited = false;
  }
}

vertex *Graph::findVertex(string name){
  for(int i = 0; i < vertices.size(); i++){
    if(vertices[i].cityName == name){
      return &vertices[i];
    }
  }
  return NULL;
}

void Graph::BFT_traversal(vertex * v){
  v->visited = true;
  vertex * n;
  queue<vertex *> q;
  q.push(v);
  while(!q.empty()){
    n = q.front();
    q.pop();
    for(int i = 0; i < n->Edges.size(); i++){
      if(n->Edges[i].v->visited == false){
        n->Edges[i].v->visited = true;
        cout << n->Edges[i].v->cityName << endl;
        q.push(n->Edges[i].v);
      }
    }
  }
}

void Graph::DFT_traversal(vertex * v){
  v->visited = true;
  for(int i = 0; i < v->Edges.size(); i++){
    if(v->Edges[i].v->visited != true){
      cout << v->Edges[i].v->cityName << endl;
      DFT_traversal(v->Edges[i].v);
    }
  }
}

void Graph::addMember(string name, string class_, string depart, string arrive, int bags, int index){
  // vertex * d = findVertex(depart);
  // vertex * a = findVertex(arrive);
  //
  // if(d != NULL && a != NULL){
  //   for(int i = 0, i < d->Edges.size(); i++){
  //     if(d->Edges[i].v == a){
  //       if(class == "First Class"){
  //         d->Edges[i].firstClass.enqueue(name, depart, arrive, bags, index);
  //       }else if(class == "Business Class"){
  //         d->Edges[i].businessClass.enqueue(name, depart, arrive, bags, index);
  //       }else if(class == "Economy Class"){
  //         d->Edges[i].coachClass.enqueue(name, depart, arrive, bags, index);
  //       }else{
  //         cout << "We do not recognize this as a class option" << endl;
  //       }
  //     }
  //     break;
  //   }
  // }else{
  //   cout << "One of the cities listed is not available to book to (/from). "
  // }
  // return;
}
