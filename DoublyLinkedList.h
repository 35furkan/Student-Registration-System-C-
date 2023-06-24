//Emre Furkan Akyol Section2  22103352
#ifndef DoublyLinkedList_
#define DoublyLinkedList_
#include <string>
#include <iostream>
#include "Node.h"
//#include "Student.h"
template <class ItemType>
class DoublyLinkedList {
private:
	Node <ItemType>* headPtr;
	int count;
	Node<ItemType>* getNodeAt(int pos) const;

public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList<ItemType>& copyList);
	virtual ~DoublyLinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPos, const ItemType& newEntry);
	bool remove(int pos);
	void clear();
	bool removeWithData(const ItemType& newEntry);
	bool addByOrder(const ItemType& newEntry);
	int getCount();
	Node<ItemType>* getHeadPtr();
	Node<ItemType>* getNodeByItem(const ItemType& newEntry) const;
	ItemType getEntry(int pos) const;
	//ItemType replace(int pos, const ItemType& newEntry);

};
#endif
