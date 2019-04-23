#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include "PriorityQ.hpp"
using namespace std;

void swap(PNode &a,PNode &b)
{
	PNode temp;
	temp = a;
	a = b;
	b = temp;
}

PriorityQueue::PriorityQueue(int queueSize)
{
	priorityQueue = new PNode[queueSize];
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

bool PriorityQueue::enqueue (string _PName, string _Depart,string _Arrive,string _BClass,int _Bagnum)
{
	PNode newGroup;/*Making new group*/
	newGroup.PName = _PName;
	newGroup.Depart = _Depart;
	newGroup.Arrive = _Arrive;
	newGroup.BClass = _BClass;
	newGroup.Bagnum = _Bagnum;
	newGroup.seatNum = currentQueueSize;
	newGroup.confNum = rand() % 66000 + 65000;

	if(currentQueueSize == maxQueueSize)
	{
		cout << "Sorry, we do not have available space for you in this class" << endl;
		return false;
	}
	else
	{
		priorityQueue[currentQueueSize] = newGroup; // put it at the end of the array
		repairUpward(currentQueueSize);
		currentQueueSize++;             //increment current size
		cout<<"Congradulations! "<<_PName<< " You are going to " <<_Arrive<<endl;
		return true;
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
bool PriorityQueue::cancelflight(string name)
{
	int flag = false;
	if(isEmpty())
	{
		cout << "We can not find you in our database" << endl;
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
			swap(priorityQueue[currentQueueSize-1],priorityQueue[p]);
			currentQueueSize--;
			repairDownward(p);
			for (int i = 0; i < currentQueueSize; i++)
			{
				if(priorityQueue[i].PName == name)
				{
					flag = true;
					break;
				}
			}
			if(!flag)
			{
				cout<<"Your flight has been canceled"<<endl;
			}
			return true;
		}
		else
		{
			cout<<"No passenger exists"<<endl;
			return false;
		}
	}
}

void PriorityQueue::repairDownward(int nodeIndex)
{
	int leftChild = (2*nodeIndex) + 1;
	int rightChild = (2*nodeIndex) + 2;
	int min = nodeIndex;           //min is the highest priority

	if((leftChild < currentQueueSize) && (priorityQueue[leftChild].Bagnum < priorityQueue[min].Bagnum ))
	{
		min = leftChild;
	}
	else if((leftChild < currentQueueSize) && (priorityQueue[leftChild].Bagnum == priorityQueue[min].Bagnum) && (priorityQueue[leftChild].seatNum < priorityQueue[min].seatNum))
	{
		min = leftChild;
	}

	if((rightChild < currentQueueSize) && (priorityQueue[min].Bagnum > priorityQueue[rightChild].Bagnum))
	{
		min = rightChild;
	}
	else if((rightChild < currentQueueSize) && (priorityQueue[rightChild].Bagnum == priorityQueue[min].Bagnum) && (priorityQueue[rightChild].seatNum < priorityQueue[min].seatNum))
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
	if(nodeIndex>0 &&priorityQueue[nodeIndex].BClass < priorityQueue[parent].BClass)
	{
		swap(priorityQueue[nodeIndex],priorityQueue[parent]);
		repairUpward(parent);
	}

	if(nodeIndex > 0 && priorityQueue[nodeIndex].Bagnum == priorityQueue[parent].Bagnum && priorityQueue[nodeIndex].seatNum < priorityQueue[parent].seatNum)
	{
		swap(priorityQueue[parent],priorityQueue[nodeIndex]);
		repairUpward(parent);
	}
}
