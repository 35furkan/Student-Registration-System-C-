//Emre Furkan Akyol Section2  22103352
#ifndef SinglyLinkedList_
#define SinglyLinkedList_
#include <string>
#include <iostream>
#include "Node.h"
//#include "Course.h"

template <class ItemType>
class SinglyLinkedList {
private:
	Node <ItemType>* headPtr;
	int count;
	Node<ItemType>* getNodeAt(int pos) const;

public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList<ItemType>& copyList);
	virtual ~SinglyLinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPos, const ItemType& newEntry);
	bool remove(int pos);
	bool removeWithData(const ItemType& newEntry);
	bool addByOrder(const ItemType& newEntry);
	void clear();
	int getCount();
	Node<ItemType>* getHeadPtr();
	Node<ItemType>* getNodeByItem(const ItemType& newEntry) const;
	ItemType getEntry (int pos) const;
	//ItemType replace(int pos, const ItemType& newEntry);
	
};
#endif
