#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
int main() {
  
  std::vector<float> values = {0,1,2,3,4,5};
  SinglyLinkedList<float> linkedList = values;
  linkedList.printList();
  linkedList.push_back(2);
  linkedList.printList();
  linkedList.push_front(-100);
  linkedList.printList();
  linkedList.insert(3, 1000);
  linkedList.printList();
  linkedList.reverse();
  linkedList.printList();

  return 0;
}