#ifndef _SIMPLELIST_H   //checks for defintion in linked file as a header include guard
#define _SIMPLELIST_H

#include <iostream>
#include <string>

using std::string;

template <typename Container> //Container is the type
class SimpleList {
private:
  class Node {      //private nested class called Node as suggested
    public:         
      Node* next;
      Container data;
  };
  string listname;      //private data member to store the name of the list

protected:              //ability to insert a node at the start and end of the list and remove from start of the list, constant time complexity
  Node* head;
  Node* tail;

//create a new node and assign pointers
//there is a pointer to the end (tail), create a new node and redirect the pointer to the new last node
//removing from the first node (head) requires having the next pointer point to the new fist node which is the original second node
  void insert_start (Container data){
    Node* next_ptr = new Node();     //assignment to node pointer
    next_ptr->data = data;           //SimpleList<Container>::Node *next_ptr
    next_ptr->next = nullptr;       

    if(head == nullptr){
      head = next_ptr;
      tail = head;
    }
    else{
      next_ptr->next = head;        //new node at the start
      head = next_ptr;
    }
  }

  void insert_end (Container data){  
    Node* next_ptr = new Node();     //assignment to node pointer
    next_ptr->data = data;           //SimpleList<Container>::Node *next_ptr
    next_ptr->next = nullptr;

    if(head == nullptr){
      head = next_ptr;
      tail = head;
    }
    else{
      tail->next = next_ptr;         //new node at the end
      tail = next_ptr;
    }
  }
  
//create temporary node pointing to the head node 
//move the head to the next node 
//free the temproary node and return the head
  Container remove_start(){          
    Container data = head->data;
    if(tail == head){
      delete head;
      tail = nullptr;
      head = nullptr;
    }
    else{
       Node* temp = head;
       head = head->next;
      delete temp;
    }
    return data;
  }
SimpleList(string listname) : listname(listname), head(nullptr), tail(nullptr){}

public:
  string get_listname(){  //public data memeber to retrieve name of list
    return listname;
  }
  bool empty_list(){                  //returns a bool for if statement that checks for an empty list
    return head == nullptr;           //if the head node is the nullptr then there is no data in the list
  }
  virtual void push(Container data) = 0;    //pure public virtual class
  virtual Container pop() = 0;
};

#endif //end of header guard
