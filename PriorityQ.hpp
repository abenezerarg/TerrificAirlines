#include <iostream>
#include <sstream>
#include <string>
#include <ctring>

using namespace std;

// #define First 1; //First class
// #define Buss  2; //bussness
// #define Econ  3; //Econ

struct PNode
{
  string PName;//passenger name
  string Depart;//depart location
  string Arrive; //arrive location
  string BClass; //boarding class
  int    Bagnum; //bag number
  int    seatNum;
};

class PriorityQueue
{
    public:

    //Purpose: perform all operations necessary to instantiate a class object
    PriorityQueue(int queueSize);

    // Purpose: free all resources that the object has acquired
    ~PriorityQueue();

    // Purpose: enqueue new group into priority queue; call other
    bool enqueue (string _PName, string _Depart,string _Arrive,string _Bclass ,int _Bagnum);

    //Purpose: remove the group (allocate the table) at the front of the priority queue from
    void dequeue();

    // return: groupID of the group at the front of the priority queue
    PNode peek();

    //return: true if queue is full, false otherwise
    bool isFull();

    // return: true if queue is empty, false otherwise
    bool isEmpty();

    //searches for specific passenger in a class and returns their information
    void search(string name, int add);
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

// struct cityNode{
//   string cityName;
//   cityNode *parent = nullptr;     //  Pointer to the parent node
//   cityNode *leftChild = nullptr;  // Pointer to the leftchild
//   cityNode *rightChild = nullptr; // Pointer to the rightChild
// };
class Cities
{
 public:
 void addCity(string name);
 bool isInTree(string city);

 private:
  cityNode *root;


};
