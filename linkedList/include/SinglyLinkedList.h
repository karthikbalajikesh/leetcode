#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "utilityFuncs.h"

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
    size = 1;
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

    this->size = vec.size();
  }

  void push_front(T val) {
    auto nodeToAdd = std::make_shared<sllNode<T>>(val);
    nodeToAdd->next = head;
    head = nodeToAdd;
    size++;
  }

  void push_back(T val) {
    // reach the tail
    auto temp = head;
    while(temp->next != nullptr) {
      temp = temp->next;
    } 
    temp->next = std::make_shared<sllNode<T>>(val);
    size++;
  }

  void printList()  {
    if(size == 0) {
      std::cout<<"Linked list is empty"<<std::endl;
      return;
    }

    std::cout<< "PRINTING THE LINKED LIST : "<<std::endl;
    std::vector<T> vec = getAsVector();
    print_range(vec.begin(), vec.end(), "->");
    
  }

  std::vector<T> getAsVector() {
    
    std::vector<T> result;
    if(size == 0) {
      return result;
    }

    auto temp = head;
    
    
    while(temp!=nullptr) {
      
      result.emplace_back(temp->value);
      temp = temp->next;
      
    }
    return result;
  }

private: 
  shared_ptr<sllNode<T>> head = nullptr;
  int size = 0;
};