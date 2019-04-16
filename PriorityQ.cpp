#include <iostream>
#include <sstream>
#include <string>
#include <ctring>
#include "PriorityQ.hpp"
using namespace std;

void swap(GroupNode &a,GroupNode &b)
{
  GroupNode temp;
  temp = a;
  a = b;
  b = temp;
}

PriorityQueue::PriorityQueue(int queueSize)
{
  priorityQueue = new GroupNode[queueSize];
  currentQueueSize = 0;
  maxQueueSize = queueSize;
}

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
  }
  else
  {
    priorityQueue[currentQueueSize] = newGroup; // put it at the end of the array
    repairUpward(currentQueueSize);
    currentQueueSize++;                         //increment current size
    cout<<"Congraduation! "<<_PName<< " You are going to" <<_Arrive<<endl;
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

PNode peek()
{
  if(isEmpty())
  {
    GroupNode dummy;
    dummy.groupName = "";
    dummy.groupSize = -1;
    dummy.cookingTime = -1;
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
  if((leftChild < currentQueueSize) && (priorityQueue[leftChild].Bclass < priorityQueue[min].Bclass ))
  {
      min = leftChild;
  }
  else if((leftChild < currentQueueSize) && (priorityQueue[leftChild].Bclass == priorityQueue[min].Bclass) && (priorityQueue[leftChild].Bagnum < priorityQueue[min].Bagnum))
  {
      min = leftChild;
  }

  if((rightChild < currentQueueSize) && (priorityQueue[min].Bclass > priorityQueue[rightChild].Bclass))
  {
      min = rightChild;
  }
  else if((rightChild < currentQueueSize) && (priorityQueue[rightChild].Bclass == priorityQueue[min].Bclass) && (priorityQueue[rightChild].Bagnum < priorityQueue[min].Bagnum))
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
  if(nodeIndex>0&&priorityQueue[nodeIndex].Bclass < priorityQueue[parent].Bclass)
  {
    swap(priorityQueue[nodeIndex],priorityQueue[parent]);
    repairUpward(parent);
  }

  if(nodeIndex > 0 && priorityQueue[nodeIndex].Bclass == priorityQueue[parent].Bclass && priorityQueue[nodeIndex].Bagnum < priorityQueue[parent].Bagnum)
  {
    swap(priorityQueue[parent],priorityQueue[nodeIndex]);
    repairUpward(parent);
  }
}
