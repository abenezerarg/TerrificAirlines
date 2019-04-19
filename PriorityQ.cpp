#include <iostream>
#include <sstream>
#include <string>
<<<<<<< HEAD
#include "PirorityQ.hpp"
using namespace std;

void swap(PNode &a,PNode &b)
{
  PNode temp;
=======
#include <ctring>
#include "PriorityQ.hpp"
using namespace std;

void swap(GroupNode &a,GroupNode &b)
{
  GroupNode temp;
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
  temp = a;
  a = b;
  b = temp;
}

PriorityQueue::PriorityQueue(int queueSize)
{
<<<<<<< HEAD
  priorityQueue = new PNode[queueSize];
=======
  priorityQueue = new GroupNode[queueSize];
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
  currentQueueSize = 0;
  maxQueueSize = queueSize;
}

<<<<<<< HEAD




=======
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
PriorityQueue::~PriorityQueue()
{
    delete[] priorityQueue;
}

bool PriorityQueue::isFull()
{
  if(currentQueueSize == maxQueueSize) return true;
  return false;
}

bool PriorityQueue::isEmpty()
{
  if(currentQueueSize == 0) return true;
  return false;
}

<<<<<<< HEAD
bool PriorityQueue::enqueue (string _PName, string _Depart,string _Arrive, int _Bagnum,int _Pindex)
{
  PNode newGroup;/*Making new group*/
  newGroup.PName = _PName;
  newGroup.Depart = _Depart;
  newGroup.Arrive = _Arrive;
  newGroup.Bagnum = _Bagnum;
  newGroup.Pindex = _Pindex;

  if(currentQueueSize == maxQueueSize)
  {
    cout << "Sorry, we do not have available space for you in this class" << endl;
    return false;
=======
void PriorityQueue::enqueue (string _PName, string _Depart,string _Arrive,string _Bclass ,int _Bagnum)
{
  GroupNode newGroup;/*Making new group*/
  newGroup.PName = _PName;
  newGroup.Depart = _Depart;
  newGroup.Arrive = _Arrive;
  newGroup.Bclass = _Bclass;
  newGroup.Bagnum = _Bagnum;

  if(currentQueueSize == maxQueueSize)
  {
    cout << "Heap full, cannot enqueue" << endl;
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
  }
  else
  {
    priorityQueue[currentQueueSize] = newGroup; // put it at the end of the array
    repairUpward(currentQueueSize);
    currentQueueSize++;                         //increment current size
<<<<<<< HEAD
    cout<<"Congraduation! "<<_PName<< " You are going to " <<_Arrive<<endl;
    return true;
=======
    cout<<"Congraduation! "<<_PName<< " You are going to" <<_Arrive<<endl;
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
  }
}

void PriorityQueue::dequeue()
{
  if(isEmpty())
  {
    cout << "Heap empty, cannot dequeue" << endl;
  }
  else if(currentQueueSize==1)
  {
    currentQueueSize--;
  }
  else
  {
    swap(priorityQueue[0],priorityQueue[currentQueueSize-1]);
    currentQueueSize--;
    repairDownward(0);
  }
}

<<<<<<< HEAD
bool PriorityQueue::cancelflight(string name)
{
  if(isEmpty())
  {
    cout << "I can not find you in our database" << endl;
    return false;
  }
  else if(currentQueueSize==1)
  {
    currentQueueSize--;
    cout<<"Your flight has been canceled"<<endl;
    return true;
  }
  else
  {
    int p = -1;
    for (int i = 0; i < currentQueueSize; i++)
    {
      if(priorityQueue[i].PName == name)
      {
        p = i;
      }
    }
    if(p  != -1)
    {
      swap(priorityQueue[0],priorityQueue[p]);
      currentQueueSize--;
      repairDownward(0);
      cout<<"Your flight has been canceled"<<endl;
      return true;
    }
    else
    {
      cout<<"No passenger exists"<<endl;
      return false;
    }
  }
}

PNode PriorityQueue::peek()
{
  if(isEmpty())
  {
    PNode dummy;
    dummy.PName = "";
    dummy.Depart = "";
    dummy.Arrive = "";
    dummy.Bagnum = -1;
=======
PNode peek()
{
  if(isEmpty())
  {
    GroupNode dummy;
    dummy.groupName = "";
    dummy.groupSize = -1;
    dummy.cookingTime = -1;
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
    cout << "Heap empty, nothing to peek" << endl;
    return dummy;
  }
  else
  {
    return priorityQueue[0];
  }
}

void PriorityQueue::repairDownward(int nodeIndex)
{
  int leftChild = (2*nodeIndex) + 1;
  int rightChild = (2*nodeIndex) + 2;
  int min = nodeIndex;                 //min is the highest priority
<<<<<<< HEAD
  if((leftChild < currentQueueSize) && (priorityQueue[leftChild].Pindex < priorityQueue[min].Pindex ))
  {
      min = leftChild;
  }
  else if((leftChild < currentQueueSize) && (priorityQueue[leftChild].Pindex == priorityQueue[min].Pindex) && (priorityQueue[leftChild].Bagnum < priorityQueue[min].Bagnum))
=======
  if((leftChild < currentQueueSize) && (priorityQueue[leftChild].Bclass < priorityQueue[min].Bclass ))
  {
      min = leftChild;
  }
  else if((leftChild < currentQueueSize) && (priorityQueue[leftChild].Bclass == priorityQueue[min].Bclass) && (priorityQueue[leftChild].Bagnum < priorityQueue[min].Bagnum))
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
  {
      min = leftChild;
  }

<<<<<<< HEAD
  if((rightChild < currentQueueSize) && (priorityQueue[min].Pindex > priorityQueue[rightChild].Pindex))
  {
      min = rightChild;
  }
  else if((rightChild < currentQueueSize) && (priorityQueue[rightChild].Pindex == priorityQueue[min].Pindex) && (priorityQueue[rightChild].Bagnum < priorityQueue[min].Bagnum))
=======
  if((rightChild < currentQueueSize) && (priorityQueue[min].Bclass > priorityQueue[rightChild].Bclass))
  {
      min = rightChild;
  }
  else if((rightChild < currentQueueSize) && (priorityQueue[rightChild].Bclass == priorityQueue[min].Bclass) && (priorityQueue[rightChild].Bagnum < priorityQueue[min].Bagnum))
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
  {
    min = rightChild;
  }

  if(min != nodeIndex)
  {
    swap(priorityQueue[min],priorityQueue[nodeIndex]);
    repairDownward(min);
  }
}


void PriorityQueue::repairUpward(int nodeIndex)
{
  int parent = (nodeIndex-1)/2;
<<<<<<< HEAD
  if(nodeIndex>0&&priorityQueue[nodeIndex].Pindex < priorityQueue[parent].Pindex)
=======
  if(nodeIndex>0&&priorityQueue[nodeIndex].Bclass < priorityQueue[parent].Bclass)
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
  {
    swap(priorityQueue[nodeIndex],priorityQueue[parent]);
    repairUpward(parent);
  }

<<<<<<< HEAD
  if(nodeIndex > 0 && priorityQueue[nodeIndex].Pindex == priorityQueue[parent].Pindex && priorityQueue[nodeIndex].Bagnum < priorityQueue[parent].Bagnum)
=======
  if(nodeIndex > 0 && priorityQueue[nodeIndex].Bclass == priorityQueue[parent].Bclass && priorityQueue[nodeIndex].Bagnum < priorityQueue[parent].Bagnum)
>>>>>>> 5c062c7f52e901dd36ca5b1e686245b1a5b10768
  {
    swap(priorityQueue[parent],priorityQueue[nodeIndex]);
    repairUpward(parent);
  }
}
