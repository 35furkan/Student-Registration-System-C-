//Emre Furkan Akyol Section2  22103352
#ifndef NODE_
#define NODE_
#include <string>
#include <iostream>
//#include "Course.h"
//#include "Student.h"
template <class ItemType>
class Node
{
private:
	ItemType item;
	Node<ItemType>* next;
	Node<ItemType>* previous;
public:
	Node();
	Node(const ItemType& item);
	Node(const ItemType& item, Node<ItemType>* nextNodePtr);
	Node(const ItemType& item, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr);
	void setItem(const ItemType& item);
	void setNext(Node < ItemType >*nextNodePtr);
	void setPrev(Node < ItemType >* prevNodePtr);
	ItemType* getItem() ;
	Node < ItemType >* getNext() const;
	Node < ItemType >* getPrev() const;
};
#endif
