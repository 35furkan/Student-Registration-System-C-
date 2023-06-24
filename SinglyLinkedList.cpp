//Emre Furkan Akyol Section2  22103352
#include "SinglyLinkedList.h"
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;
template<class ItemType>
SinglyLinkedList<ItemType>::SinglyLinkedList() {
	headPtr = nullptr;
	count = 0;
}
template<class ItemType>
SinglyLinkedList<ItemType>::SinglyLinkedList(const SinglyLinkedList<ItemType>& copyList) {

	Node<ItemType>* copyChainPtr = copyList.headPtr;
	count = copyList.count;
	if (copyChainPtr == nullptr) {
		headPtr = nullptr;
		count = 0;
	}
	else {
		headPtr = new Node<ItemType>();
		headPtr->setItem(*(copyChainPtr->getItem()));
		Node<ItemType>* newChainPtr = headPtr;
		copyChainPtr = copyChainPtr->getNext();
		while (copyChainPtr != nullptr) {
			ItemType nextItem = *(copyChainPtr->getItem());
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			newChainPtr->setNext(newNodePtr);
			newChainPtr = newChainPtr->getNext();
			copyChainPtr = copyChainPtr->getNext();

		}
	}
}
template<class ItemType>
ItemType SinglyLinkedList<ItemType>::getEntry(int pos)const {
	if (pos<1 || pos>count) {

	}
	else {
		Node<ItemType>* nodePtr = getNodeAt(pos);
		return *(nodePtr->getItem());
	}
}
template<class ItemType>
Node<ItemType>* SinglyLinkedList<ItemType>::getNodeAt(int pos)const {
	if (pos<1 || pos>count) {

	}
	else {
		Node<ItemType>* curPtr = headPtr;
		for (int i = 1; i < pos; i++) {
			curPtr = curPtr->getNext();
		}
		return curPtr;
	}
}
template<class ItemType>
bool SinglyLinkedList<ItemType>::insert(int pos, const ItemType& newEntry) {
	if (pos<1 || pos>count + 1) {
		return false;
	}
	else
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		if (pos == 1) {
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else {
			Node<ItemType>* prevPtr = getNodeAt(pos - 1);
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}
		count++;

	}
	return true;
}
template<class ItemType>
bool SinglyLinkedList<ItemType>::addByOrder(const ItemType& newEntry) {
	bool done = false;
	Node<ItemType>* newNode = new Node<ItemType>(newEntry);
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;
	if (curPtr == nullptr) {
		headPtr = newNode;
		headPtr->setNext(nullptr);
		count++;
		return true;
	}
	else {
		if (*(newNode->getItem()) < *(headPtr->getItem())) {
			newNode->setNext(headPtr);
			headPtr = newNode;
			count++;
			done = true;
			return done;
		}
		else {
			prevPtr = curPtr;
			curPtr = curPtr->getNext();
			while (curPtr != nullptr && !done) {
				if (*(newNode->getItem()) < *(curPtr->getItem())) {
					newNode->setNext(curPtr);
					prevPtr->setNext(newNode);
					count++;
					done = true;
					return done;
				}
				prevPtr = curPtr;
				curPtr = curPtr->getNext();

			}
			if (!done) {
				prevPtr->setNext(newNode);
				done = true;
				return done;
			}
		}
	}
	

}
/*template<class ItemType>
bool SinglyLinkedList<ItemType>::remove(int pos) {
	if (pos<1 || pos>count) {
		return false;
	}
	else
	{
		Node<ItemType>* curPtr = nullptr;
		if (pos == 1) {
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else {
			Node<ItemType>* prevPtr = getNodeAt(pos - 1);
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());

		}
		count--;
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;

	}
	return true;
}*/
template<class ItemType>
bool SinglyLinkedList<ItemType>::remove(int pos) {
	if (pos < 1 || pos > count) {
		return false;
	}
	else {
		Node<ItemType>* curPtr = nullptr;
		if (pos == 1) {
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else {
			Node<ItemType>* prevPtr = getNodeAt(pos - 1);
			if (prevPtr == nullptr || prevPtr->getNext() == nullptr) {
				return false; // Invalid position
			}
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}
		count--;
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
	}
	return true;
}
template<class ItemType>
bool SinglyLinkedList<ItemType>::removeWithData(const ItemType& removedEntry) {
	bool found = false;
	Node<ItemType>* curPtr = headPtr;
	if (*(curPtr->getItem()) == removedEntry) {
		found = true;
		headPtr = curPtr->getNext();
		delete curPtr;
		count--;
		return found;
	}
	while (!found && curPtr->getNext() != nullptr) {

		if (*(curPtr->getNext()->getItem()) == removedEntry) {
			found = true;
			Node<ItemType>* deletedPtr = curPtr->getNext();
			curPtr->setNext(curPtr->getNext()->getNext());
			delete deletedPtr;
			count--;
			return found;
		}
		curPtr = curPtr->getNext();
	}

	return false;;
}

/*template<class ItemType>
void SinglyLinkedList<ItemType>::clear() {
	while (!isEmpty()) {
		remove(1);
	}
}*/
template<class ItemType>
void SinglyLinkedList<ItemType>::clear() {
	Node<ItemType>* curPtr = headPtr;
	while (curPtr != nullptr) {
		Node<ItemType>* nextPtr = curPtr->getNext();
		delete curPtr;
		curPtr = nextPtr;
	}
	headPtr = nullptr;
	count = 0;
}
template<class ItemType>
bool SinglyLinkedList<ItemType>::isEmpty() const {

	return count == 0;
}
template<class ItemType>
int SinglyLinkedList<ItemType>::getLength() const {
	return count;
}
/*template<class ItemType>
ItemType SinglyLinkedList<ItemType> ::replace(int pos, const ItemType& newEntry) {
	ItemType oldEntry = getEntry(pos);
	bool isInserted = false;
	bool isRemoved = remove(pos);
	if (isRemoved) {
		 isInserted = insert(pos, newEntry);

	}
	if (isInserted) {
		return oldEntry;
	}
	else {
		return nullptr;
	}
}*/
template<class ItemType>
SinglyLinkedList<ItemType>::~SinglyLinkedList() {
	clear();
}
template<class ItemType>
Node<ItemType>* SinglyLinkedList<ItemType>::getNodeByItem(const ItemType& newEntry) const {
	Node<ItemType>* curPtr = headPtr;
	while (curPtr != nullptr) {
		if (*(curPtr->getItem()) == newEntry) {
			return curPtr;
		}
	}
	return nullptr;
}
template<class ItemType>
Node<ItemType>* SinglyLinkedList<ItemType>::getHeadPtr() {

	return headPtr;

}
template<class ItemType>
int SinglyLinkedList<ItemType>::getCount() {
	return count;
}
template class SinglyLinkedList<Course>;