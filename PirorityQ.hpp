#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// #define First 1; //First class
// #define Buss  2; //bussness
// #define Econ  3; //Econ

struct PNode
{
  string PName;  //passenger name
  string Depart; //depart location
  string Arrive; //arrive location
  int    Bagnum; //bag number
  int    Pindex;

};

class PriorityQueue
{
    public:

    //Purpose: perform all operations necessary to instantiate a class object
    PriorityQueue(int queueSize);

    // Purpose: free all resources that the object has acquired
    ~PriorityQueue();

    // Purpose: enqueue new group into priority queue; call other
    bool enqueue (string _PName, string _Depart,string _Arrive,int _Bagnum, int _Pindex);

    //Purpose: remove the group (allocate the table) at the front of the priority queue from
    void dequeue();

    // return: groupID of the group at the front of the priority queue
    PNode peek();

    //return: true if queue is full, false otherwise
    bool isFull();

    // return: true if queue is empty, false otherwise
    bool isEmpty();

    //
    bool cancelflight(string name);


    private:
    //Purpose: maintain heap properties by swapping node with parent if necessary
    void repairUpward(int nodeIndex);

    // Purpose: maintain heap properties by swapping node with child if necessary
    void repairDownward(int nodeIndex);

    PNode* priorityQueue; //pointer to the array used to implement priority queue
    int currentQueueSize; //number of group currently in the priority queue
    int maxQueueSize; //maximum capacity of priority queue
};
