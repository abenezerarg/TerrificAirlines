#include "Graph.hpp"
#include <string>
#include <vector>
#include <queue>

using namespace std;

Graph::Graph(){
}

Graph::~Graph(){
}

void Graph::addVertex(string name){
	vertex * found = findVertex(name);

	if(found == NULL) {
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
	if(c1 == NULL || c2 == NULL || c1 == c2) {
		cout << "One or both of the cities do not exist" << endl;
		return;
	}else{
		Edge c1TOc2;
		c1TOc2.distance = distance;
		c1TOc2.duration = duration;
		c1TOc2.v = c2;
		for(int i = 0; i < vertices.size(); i++) {
			if(vertices[i].cityName == city1) {
				vertices[i].Edges.push_back(c1TOc2);
				break;
			}
		}
	}
}

void Graph::displayEdges(){
	for(int i = 0; i <  vertices.size(); i++) {
		cout << vertices[i].cityName << "-->";
		if(vertices[i].Edges.empty())
			cout << endl;
		else{
			for(int j = 0; j < vertices[i].Edges.size(); j++) {
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

	for(int i = 0; i < vertices.size(); i++) {
		if(!vertices[i].visited)
			cout << vertices[i].cityName << endl;
		DFT_traversal(&vertices[i]);
	}
}

void Graph::printBFT(){
	setAllVerticesUnvisited();

	for(int i = 0; i < vertices.size(); i++) {
		if(!vertices[i].visited)
			cout << vertices[i].cityName << endl;
		BFT_traversal(&vertices[i]);
	}
}

void Graph::setAllVerticesUnvisited(){
	for(int i = 0; i < vertices.size(); i++) {
		vertices[i].visited = false;
	}
}

vertex *Graph::findVertex(string name){
	for(int i = 0; i < vertices.size(); i++) {
		if(vertices[i].cityName == name) {
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
	while(!q.empty()) {
		n = q.front();
		q.pop();
		for(int i = 0; i < n->Edges.size(); i++) {
			if(n->Edges[i].v->visited == false) {
				n->Edges[i].v->visited = true;
				cout << n->Edges[i].v->cityName << endl;
				q.push(n->Edges[i].v);
			}
		}
	}
}

void Graph::DFT_traversal(vertex * v){
	v->visited = true;
	for(int i = 0; i < v->Edges.size(); i++) {
		if(v->Edges[i].v->visited != true) {
			cout << v->Edges[i].v->cityName << endl;
			DFT_traversal(v->Edges[i].v);
		}
	}
}

bool Graph::addMember(string name, string class_, string depart, string arrive, int bags){
	vertex * d = findVertex(depart);
	vertex * a = findVertex(arrive);
	if(d != NULL && a != NULL) {
		for(int i = 0; i < d->Edges.size(); i++) {
			if(d->Edges[i].v == a) {
				if(class_ == "First Class") {
					d->Edges[i].firstClass->enqueue(name, depart, arrive, class_, bags);
					break;
				}else if(class_ == "Business Class") {
					d->Edges[i].businessClass->enqueue(name, depart, arrive, class_, bags);
					break;
				}else if(class_ == "Economy Class") {
					d->Edges[i].coachClass->enqueue(name, depart, arrive, class_, bags);
					break;
				}else{
					cout << "We do not recognize this as a class option" << endl;
				}
			}
		}
	}else{
		cout << "One of the cities listed is not available to book to (/from). " << endl;
		return false;
	}
	return true;
}

Edge * Graph::findEdge(string depart, string arrive){
	vertex * d = findVertex(depart);
	vertex * a = findVertex(arrive);

	if(d != NULL && a != NULL) {
		for(int i = 0; i < d->Edges.size(); i++) {
			if(d->Edges[i].v == a) {
				return &d->Edges[i];
			}
		}
	}
	return NULL;
}

PriorityQueue *Graph::findClass(string depart, string arrive, string className)
{
	Edge *found = findEdge(depart, arrive);
	if(found != NULL)
	{
		if(className.compare("First Class") == 0) return found->firstClass;
		else if(className.compare("Business Class") == 0) return found->businessClass;
		else if(className.compare("Economy Class") == 0) return found->coachClass;
		else
		{
			return NULL;
		}
	}
	return NULL;
}

void Graph::passengerInfo(string name,string depart,string arrive, string className)
{
	PriorityQueue *Class = findClass(depart, arrive, className);
	int add;
	if(className.compare("First Class") == 0) add = 0;
	else if(className.compare("Business Class") == 0) add = 25;
	else if(className.compare("Economy Class") == 0) add = 50;

	if(Class != NULL)
	{
		PNode *priorityQueue = Class->priorityQueue;
		int size = Class->currentQueueSize;
		for(int i = 0; i < size; i++)
		{
			if(name == priorityQueue[i].PName)
			{
				cout << "------------------------------------------------------------------------------------------------------" << endl;
				cout << "[Pasenger name: " << priorityQueue[i].PName<< "]" <<"   [Departaure city: "<<priorityQueue[i].Depart << "]"<< endl;
				cout << endl;
				cout << "[seat: " <<priorityQueue[i].seatNum+1+add<<"]"<<"   [Arrival city: "<<priorityQueue[i].Arrive <<"]"<< "   [Confirmation number:" <<priorityQueue[i].confNum<< "]" << endl;
				cout << endl;
				cout <<  "[class: " <<priorityQueue[i].BClass<< "]" << "   [checked bags: " << priorityQueue[i].Bagnum <<"]"<< endl;
				cout << endl;
				cout << "------------------------------------------------------------------------------------------------------" << endl;
				return;
			}
		}
	}
	cout << endl;
	cout << "passenger not found" << endl;
	cout << endl;
}
void Graph::bookFlight(){
	string _PName, _Bclass, _Bagnum, depart, arrive;
	int bagnum;
	string Bcheck;
	bool check= false;
	Edge * pq;
	float price;
	cout<<"Departaure city: ";
	getline(cin,depart);
	while(!findVertex(depart))
	{
		cout << "TerrificAirlines does not have any flight available from that city: ";
		getline(cin,depart);
	}
	cout<<"Arrival city: ";
	getline(cin,arrive);
	while(!findVertex(arrive))
	{
		cout << "TerrificAirlines does not have any flight available to that city: ";
		getline(cin,arrive);
	}
	cout<<"Please enter your full name"<<endl;
	getline(cin,_PName);

	while(!check)
	{
		cout<<"Please enter number of bag"<<endl;
		getline(cin,_Bagnum);
		bagnum = stoi(_Bagnum);
		if(bagnum > 0 && bagnum <=3)
		{
			check = true;
		}
		else
		{
			check = false;
			cout<<"Sorry, please enter the valid input, we only allow up to 3 bags at most"<<endl;
		}
	}
	check = false;
	while(!check)
	{

		cout<<"Please enter the class type from the following options: (First Class/ Business Class/ Economy Class)"<<endl;
		getline(cin,_Bclass);
		if(_Bclass == "First Class" || _Bclass == "Business Class" || _Bclass =="Economy Class")
		{
			check = true;
		}
		else
		{
			check= false;
			cout<<"Please enter from the available options (First Class/ Business Class/ Economy Class)"<<endl;
		}
	}
	check = false;
	while(!check)
	{
		pq = findEdge(depart, arrive);
		if(pq != NULL) {
			price = pq->distance;
			if(_Bclass == "First Class") {
				price = (price/2) + 50;
			}else if(_Bclass == "Business Class") {
				price = (price/3) + 50;
			}else{
				price = (price/4) + 50;
			}

		}
		cout << std::fixed;
		cout << fixed <<setprecision(2);
		cout<<"The price of this trip will be $"<< price << ", do you want to book this trip? Please enter (Yes/No)"<<endl;
		getline(cin,Bcheck);
		if(Bcheck == "Yes") {
			addMember(_PName, _Bclass, depart, arrive, bagnum);
			check = true;
		}else if(Bcheck == "No") {
			break;
		}
		else{
			cout<<"Please enter (Yes/No)"<<endl;
			check = false;
		}
	}
}

void Graph::cancelFlightG(){
	string _Bclass, depart, arrive, name;
	bool check = false, checkedge = false;
	while (!check)
	{
		cout<<"Please enter your class before you cancel (First Class / Business Class / Economy Class)"<<endl;
		getline(cin, _Bclass);
		if(_Bclass == "First Class" || _Bclass == "Business Class" || _Bclass =="Economy Class")
		{
			check = true;
		}
		else
		{
			cout<<"Please enter (First Class / Business Class / Economy Class)"<<endl;
			cout<<endl;
			check = false;
		}
	}
	cout<<"Please enter your name"<<endl;
	getline(cin, name);
	cout<<"Please enter the Departure city of your flight"<<endl;
	getline(cin, depart);
	cout<<"Please enter the Arrive city of your flight"<<endl;
	getline(cin,arrive);
	if(_Bclass == "First Class")
	{
		Edge * temp = findEdge(depart,arrive);
		if(temp !=nullptr)
		{
			temp->firstClass->cancelflight(name);
		}

	}

	else if(_Bclass == "Business Class")
	{
		Edge *temp = findEdge(depart,arrive);
		if(temp !=nullptr)
		{
			temp->businessClass->cancelflight(name);
		}



	}
	else if(_Bclass == "Economy Class")
	{

		Edge *temp = findEdge(depart,arrive);
		if(temp !=nullptr)
		{
			temp->coachClass->cancelflight(name);
		}
	}
	else
	{
		cout <<"The class you input is not a vaild class"<<endl;
	}
}
