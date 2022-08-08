#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
int main() {
  
  std::vector<float> values = {0,1,2,3,4,5};
  SinglyLinkedList<float> linkedList = values;
  linkedList.printList();
  linkedList.push_back(2);
  linkedList.printList();
  linkedList.push_front(1);
  linkedList.printList();
  return 0;
}