#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
int main() {
  
  std::vector<float> values = {0,1,2,3,4,5,6,7};
  auto linkedList = SinglyLinkedList<float>(values);
  linkedList.printList();

  linkedList.pop_front();
  linkedList.printList();

  linkedList.pop_back();
  linkedList.printList();

  linkedList.popAt(2);
  linkedList.printList();

  return 0;
}