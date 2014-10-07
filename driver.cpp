// ////////////////////////////////////////////////////////////////
//Author: Anzalone, Christopher      Due Date: 11/08/2011
//USERID: canzalon                   Email Addy: canzalon@fau.edu
//File: driver.cpp                   Last Modified: 11/06/2011								 
// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// DESCRIPTION:
// 
//	Implementation of the circular queue abstract data type
//  that uses the doubly linked list data structure.
//
// ////////////////////////////////////////////////////////////////

#include <iostream>
#include "cqueue.h"

using namespace std;

int main()
{
	cout<<"*---------------------------------*"<<endl;
	cout<<" ENQUEUE, DEQUEUE, & PRINT TESTING"<<endl;
	cout<<"*---------------------------------*"<<endl;

	CQUEUE testObject;

	//four strings have been added to the circular queue testObject
	//the result is printed
	testObject.Enqueue("This is a");
	testObject.Enqueue("doubly-linked");
	testObject.Enqueue("circular queue of");
	testObject.Enqueue("strings");
	testObject.Print();

	//two of the strings have been removed from the same queue
	//the result is printed
	testObject.Dequeue();
	testObject.Dequeue();
	testObject.Print();

	//two more strings have been added to the same queue
	//the result is printed
	testObject.Enqueue("with a doubly-linked list");
	testObject.Enqueue("implementation");
	testObject.Print();

	//every string (node) in the queue is removed
	//the result is printed with an error because it is empty
	testObject.Dequeue();
	testObject.Dequeue();
	testObject.Dequeue();
	testObject.Dequeue();
	testObject.Print();
	cout<<endl;  //new line for readability in console

	//an error is printed from the dequeue function because the 
	//.. testObject queue is empty
	testObject.Dequeue();

	cout<<"*---------------------------------*"<<endl;
	cout<<" COPY CONSTRUCTOR TESTING"<<endl;
	cout<<"*---------------------------------*"<<endl;

	//copy constructor called to initialize twoQueue with oneQueue's data
	//printing it produces an error because it is empty
	CQUEUE oneQueue;
	CQUEUE twoQueue(oneQueue);
	twoQueue.Print();
	cout<<endl;  //new line for readability in console

	//another test for copy constructor, this time with an 
	//..object that has data already
	//result of object initialized with other object printed
	CQUEUE someQueue;
	someQueue.Enqueue("The shortest distance");
	someQueue.Enqueue("between two points");
	someQueue.Enqueue("is a line");

	CQUEUE anotherQueue(someQueue);
	anotherQueue.Print();

	cout<<"*---------------------------------*"<<endl;
	cout<<" OVERLOADED = OPERATOR TESTING"<<endl;
	cout<<"*---------------------------------*"<<endl;

	//a queue object with two strings (nodes) is assigned to
	//..another queue object, which is empty
	//result is printed
	CQUEUE firstQueue, secondQueue;
	firstQueue.Enqueue("Logic");
	firstQueue.Enqueue("Design");
	secondQueue = firstQueue;
	secondQueue.Print();

	//a queue object with three strings (nodes) is assigned
	//..to another queue object, which already has its own strings
	//result is printed
	CQUEUE almostLastQueue, lastQueue;
	almostLastQueue.Enqueue("Data");
	almostLastQueue.Enqueue("Structures");
	almostLastQueue.Enqueue("with Bullard");

	lastQueue.Enqueue("FAU");
	lastQueue.Enqueue("Boca Raton");

	lastQueue = almostLastQueue;

	lastQueue.Print();

	return 0;
}