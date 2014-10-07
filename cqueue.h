// ////////////////////////////////////////////////////////////////
//Author: Anzalone, Christopher      Due Date: 11/08/2011
//USERID: canzalon                   Email Addy: canzalon@fau.edu
//File: cqueue.h                     Last Modified: 11/06/2011								 
// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
//
// DESCRIPTION:
// 
//	Implementation of the circular queue abstract data type
//  that uses the doubly linked list data structure.
//
// ////////////////////////////////////////////////////////////////

#ifndef CQUEUE_H
#define CQUEUE_H

// Class for storing strings in a doubly-linked circular queue.
//
// CQUEUE ADT:
//
// Data:
//     An unordered, arbitrary sequence of string items. 
// Operations:
//     
//
//class qnode
//
//    public:
//        string name;  //data of node
//        qnode *prev, *next;   //previous ptr to prev node, next " next "
//
//
//class CQUEUE
//
//    public:
//        CQUEUE( );  //default constructor
//        ~CQUEUE( );  //destructor
//       CQUEUE(const CQUEUE &);  //copy constructor
//       void Enqueue(string);  //add
//       void Dequeue( );  //delete
//       void Print( );  //display
//	   CQUEUE & operator=(const CQUEUE &); 
//   private:
//       qnode *front;  //pointer to front (first node) of queue
//
//
//
//
//
//
//


#include <string>
using namespace std;

//doubly linked-list circular queue

//queue node class
class qnode
{
    public:
        string name;  //data of node
        qnode *prev, *next;   //previous ptr to prev node, next " next "
};

//circular queue class
class CQUEUE
{
    public:
        CQUEUE( );  //default constructor
        ~CQUEUE( );  //destructor
       CQUEUE(const CQUEUE &);  //copy constructor
       void Enqueue(string);  //add
       void Dequeue( );  //delete
       void Print( );  //display
	   CQUEUE & operator=(const CQUEUE &); 
   private:
       qnode *front;  //pointer to front (first node) of queue
};


#endif