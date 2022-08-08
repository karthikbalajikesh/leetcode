# Linked lists

Linked lists are data structures that contain objects with reference to the next object in the list. 
They are very useful and efficient in inserting and deleting elements in the list, as it only involves changing the pointers.
However, the bottleneck is in search or find operations as you would have to iterate over the list(skip list is supposed to make this better)

Types of linked lists:

* singly linked list
* doubly linked list
* skip list

## Singly Linked list:
In this system, every item holds a pointer to the next item in the list. The list terminates when the next item is a nullptr.

### Time complexity for common applications

#### Adding at the end
We need to traverse the list to reach the end. Hence, it is O(N)

#### Removing at the end
O(N)

#### Adding or Removing  at the front or middle
Adding or removing at the front is O(1). Middle involves traversing and hence O(N)

## Doubly Linked list
In this data structure, each element has a pointer to the next and previous item. The list has a head and a tail and is used to perform operations. 
The advantage of this is that adding and removing at the back are also O(1) operation.


## Skip List
The skip list is an advanced version of the linkedlist school of structures, which is an alternate to the balanced Binary Search trees. 
Their insertion and deletion are complicated. However, the search operation becomes a O(log N) vs an O(N) as in traditional linked lists. 


