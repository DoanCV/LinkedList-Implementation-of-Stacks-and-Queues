#ifndef _QUEUE_H   //checks for definition in linked file as a header include guard
#define _QUEUE_H

#include "SimpleList.h"
#include <iostream>
#include <string>

using std::string;

template <typename Container>
class Queue : public SimpleList<Container>{   //derived class
public:
  void push(Container data){          //Pushes to the back
    this->insert_end(data);           //Queue<Container> *const this
  }
  Container pop(){
    return this->remove_start();      //pops the front
  }
Queue(string listname) : SimpleList<Container>(listname){}
};

#endif //end of the header guard
