#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "utilityFuncs.h"
#include <optional>

using std::shared_ptr;

template<typename T>
/**
 * @struct The singly linked list node contains a value and a pointer to the next object. 
 */
struct sllNode {
  sllNode(T val):value(val) {}
  T value;
  shared_ptr<sllNode<T>> next{nullptr};
};

template<typename T>
/**
 * @class The SinglyLinkedList class is an implementation of the singly linked list data structure, 
 *        which supports operations such as search, insert and delete. 
 */
class SinglyLinkedList {
public:
  SinglyLinkedList(T startVal) {
    head = std::make_shared<sllNode<T>>(startVal);
    std::cout<< "Created a singly linked list with the head as "<<startVal<<std::endl;
    _size = 1;
  }

  SinglyLinkedList(std::vector<T> vec) {
    
    if(vec.empty()) {
      std::cout<<"EMPTY VECTOR PROVIDED"<<std::endl;
      return;
    }
    
    head = std::make_shared<sllNode<T>>(*vec.begin());
    auto temp = head;
    
    for(auto it = std::next(vec.begin());it!=vec.end();it++) {
      // using push back is not the best idea as it would be o(nlogn)
      temp->next = std::make_shared<sllNode<T>>(*it);
      temp = temp->next;
    }

    this->_size = vec.size();
  }

  void insert(int position, T val) {
    if (position>_size) {
      std::cout<<"Given a position out of bounds. Ignoring"<<std::endl;
      return;
    }
    if(position == 0) {
      push_front(val);
      return;
    }

    int index = 0;
    auto temp = head;
    while(index!=position-1) {
      index++;
      temp = temp->next;
    }
    auto nodeToAdd = std::make_shared<sllNode<T>>(val);
    nodeToAdd->next = temp->next;
    temp->next = nodeToAdd;

  }

  void reverse() {
    auto curr = head;
    shared_ptr<sllNode<T>> prev = nullptr, next = nullptr;

    while(curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev=curr;
      curr =next;
    }
    head = prev;
     
  }

  void push_front(T val) {
    auto nodeToAdd = std::make_shared<sllNode<T>>(val);
    nodeToAdd->next = head;
    head = nodeToAdd;
    _size++;
  }

  void push_back(T val) {
    // reach the tail
    auto temp = head;
    while(temp->next != nullptr) {
      temp = temp->next;
    } 
    temp->next = std::make_shared<sllNode<T>>(val);
    _size++;
  }

  // pop operations
  void pop_front() {
    if(_size==0) {
      return;
    }
    _size--;
    head = head->next;
  }

  void pop_back() {
    if(_size==0) {
      return;
    }
    if(_size ==1) {
      head=nullptr;
      _size--;
      return;
    }
    auto temp = head;
    while(temp->next->next!=nullptr) {
      temp = temp->next;
    }
    _size--;
    temp->next = nullptr;
  }

  void popAt(int index) {
    if(index <0 || index >=_size) {
      return;
    }
    if(index == 0) {
      pop_front();
      return;
    }
    auto temp = head;
    for(int i=0;i<index-1;i++) {
      temp = temp->next;
    }
    _size--;
    temp->next = temp->next->next;
  }

  void clear() {
    head = nullptr;
    _size = 0;
  }

  inline size_t size() const {
    return this->_size;
  }

  void printList()  {
    if(_size == 0) {
      std::cout<<"Linked list is empty"<<std::endl;
      return;
    }

    std::cout<< "PRINTING THE LINKED LIST : "<<std::endl;
    std::vector<T> vec = getAsVector();
    print_range(vec.begin(), vec.end(), "->");
    std::cout<<"Size of the list is:  "<<_size<<std::endl;
  }

  std::vector<T> getAsVector() {
    
    std::vector<T> result;
    if(_size == 0) {
      return result;
    }

    auto temp = head;
    
    
    while(temp!=nullptr) {
      
      result.emplace_back(temp->value);
      temp = temp->next;
      
    }
    return result;
  }

  int find(T valueToCheck) {
    auto temp = head;
    int index = -1;
    while(temp!=nullptr) {
      ++index;

      if(temp->value == valueToCheck)
        return index;
      temp = temp->next;
    }

    return -1;
  }

  std::optional<T> atIndex(int indexToCheck) {
    if(indexToCheck >=_size || indexToCheck <0) {
      return std::nullopt;
    }
    auto temp = head;
    for(int index = 0; index <indexToCheck; ++index){
      temp = temp->next;
    }
    return temp->value;
  }

protected: 
  shared_ptr<sllNode<T>> head = nullptr;
  int _size = 0;
};