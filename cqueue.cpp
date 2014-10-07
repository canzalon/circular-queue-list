// ////////////////////////////////////////////////////////////////
//Author: Anzalone, Christopher      Due Date: 11/08/2011
//USERID: canzalon                   Email Addy: canzalon@fau.edu
//File: cqueue.cpp                   Last Modified: 11/06/2011								 
// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// DESCRIPTION:
// 
//	Implementation of the circular queue abstract data type
//  that uses the doubly linked list data structure.
//
// ////////////////////////////////////////////////////////////////

#include "cqueue.h"
#include <string>
#include <iostream>

using namespace std;

//default constructor
CQUEUE::CQUEUE()
{
	front = 0;
}

CQUEUE::~CQUEUE()
{
	while (front != 0)
	{
		Dequeue(); 
	}
}

CQUEUE::CQUEUE(const CQUEUE & otherCQueue)
{
	if (otherCQueue.front != 0)
	{
		qnode * p = otherCQueue.front;    //pointer for queue parameter's traversal, set to front of list

		qnode * tempQNode = new qnode;    //temp pointer for first node in queue declared, memory allocated
		tempQNode->name = p->name;    //copy data (name) from original queue's first node to temp node
		tempQNode->next = tempQNode;    //for first node, the next and prev pointers are set to the 
		tempQNode->prev = tempQNode;    //node itself for circulation
		front = tempQNode;    //this object's front pointer set to first node (front of queue) 
		p=p->next;    //original queue pointer moved to next node for further copying

		while (p != otherCQueue.front)
		{
			tempQNode = new qnode;    //allocate memory for new node
			tempQNode->name = p->name;    //copy data (name) from original queue's current node to temp node
			tempQNode->next = front;    //set next ptr of new node to front's location to wrap around
			tempQNode->prev = front->prev;    //set prev ptr of new node to current last node in queue
			front->prev->next = tempQNode;    //set last node of queue's next ptr to temp node
			front->prev = tempQNode;    //set front node's prev ptr to temp node, to complete circulation
			p = p->next;    //original queue pointer moved to next node for further copying
		}
	}
	else    //if original queue is empty
	{
		front = 0;
	}
}

void CQUEUE::Enqueue(string queueItem)
{
	qnode * p = new qnode;
	p->name = queueItem;

	if (front==0)  //if empty, queue is initialized with the new node; this 
		           //node points to itself to maintain circular nature
	{
		front = p;    //front pointer set to new node's location
		p->prev = p;    //new node's prev ptr points to the node itself
		p->next = p;    //new node's next ptr points to the node itself
	}
	else  //works for all cases except for empty list
	{
		p->prev = front->prev;   //set new node's prev ptr to the current last node in queue
		p->next = front;    //set new node's next ptr to the front of the queue
		front->prev->next = p;   //set current last node's next ptr to new last node
		front->prev = p;    //set prev ptr of first node to new last node
	}
}

void CQUEUE::Dequeue()
{
	if (front == 0)  //list is empty
	{
		cout<<"List is empty, can not dequeue"<<endl;
	}
	else if (front->next == front)   //if there's only one node in queue
	{
		qnode * p = front;    //qnode pointer to point to front node for later deletion
		front = 0;   //set front to null since the queue will be empty
		delete p;  //p still points to the old front node, it is deleted
	} 
	else   //if queue is not empty and has more than one node
	{
		qnode * p = front;    //qnode pointer to point to front node for later deletion
		front->prev->next = front->next;   //points the last node in the queue to the eventual front node
		front->next->prev = front->prev;   //points eventual front node's prev ptr to last node in the queue
		front = front->next;   //move front pointer to eventual front node
		delete p;  //p still points to the old front node, it is deleted
	}
}

void CQUEUE::Print()
{
	if (front != 0)
	{
		qnode * p = front;   //qnode pointer for traversal through queue
		//will loop until p reaches front again
		do
		{
			cout<< p->name <<endl;     //string from current qnode sent to console
			p = p->next;     //move p pointer to next node
		} while (p != front);

		cout<<endl;
	}
	else
	{
		cout<<"List is empty, can not print"<<endl;
	}
}

CQUEUE & CQUEUE::operator=(const CQUEUE & otherCQueue)
{
	//check for self-assignment
	if (this == &otherCQueue) 
		return *this;

	if (otherCQueue.front != 0)
	{
		qnode * p = otherCQueue.front;    //pointer for queue parameter's traversal, set to front of list

		qnode * tempQNode = new qnode;    //temp pointer for first node in queue declared, memory allocated
		tempQNode->name = p->name;    //copy data (name) from original queue's first node to temp node
		tempQNode->next = tempQNode;    //for first node, the next and prev pointers are set to the 
		tempQNode->prev = tempQNode;    //node itself for circulation
		front = tempQNode;    //this object's front pointer set to first node (front of queue) 
		p=p->next;    //original queue pointer moved to next node for further copying

		while (p != otherCQueue.front)
		{
			tempQNode = new qnode;    //allocate memory for new node
			tempQNode->name = p->name;    //copy data (name) from original queue's current node to temp node
			tempQNode->next = front;    //set next ptr of new node to front's location to wrap around
			tempQNode->prev = front->prev;    //set prev ptr of new node to current last node in queue
			front->prev->next = tempQNode;    //set last node of queue's next ptr to temp node
			front->prev = tempQNode;    //set front node's prev ptr to temp node, to complete circulation
			p = p->next;    //original queue pointer moved to next node for further copying
		}
	}
	else    //if original queue is empty
	{
		front = 0;
	}

	return *this;
}