//Emre Furkan Akyol Section2  22103352
#include "DoublyLinkedList.h"
#include "Student.h"
#include <string>
#include <iostream>
using namespace std;
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList() {
	headPtr = nullptr;
	count = 0;
}
template<class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList<ItemType>& copyList) {

	Node<ItemType>* copyChainPtr = copyList.headPtr;
	count = copyList.count;
	if (copyChainPtr == nullptr) {
		headPtr = nullptr;
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
			newNodePtr->setPrev(newChainPtr);
			newChainPtr = newChainPtr->getNext();
			copyChainPtr = copyChainPtr->getNext();

		}
		newChainPtr->setNext(nullptr);
	}
}
template<class ItemType>
ItemType DoublyLinkedList<ItemType>::getEntry(int pos)const {
	if (pos<1 || pos>count) {

	}
	else {
		Node<ItemType>* nodePtr = getNodeAt(pos);
		return *(nodePtr->getItem());
	}
}
template<class ItemType>
Node<ItemType>* DoublyLinkedList<ItemType>::getNodeAt(int pos)const {
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
bool DoublyLinkedList<ItemType>::insert(int pos, const ItemType& newEntry) {
	if (pos<1 || pos>count + 1) {
		return false;
	}
	else
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		if (pos == 1) {
			newNodePtr->setNext(headPtr);
			newNodePtr->setPrev(nullptr);
			headPtr->setPrev(newNodePtr);
			headPtr = newNodePtr;
		}
		else {
			Node<ItemType>* prevPtr = getNodeAt(pos)->getPrev();
			Node<ItemType>* currentPtr = getNodeAt(pos);
			newNodePtr->setPrev(currentPtr->getPrev());
			currentPtr->setPrev(newNodePtr);
			prevPtr->setNext(newNodePtr);
			newNodePtr->setNext(currentPtr);
		}
		count++;

	}
	return true;
}
template<class ItemType>
bool DoublyLinkedList<ItemType>::remove(int pos) {
	if (pos < 1 || pos > count) {
		return false;
	}
	else if (pos == 1) {
		Node<ItemType>* curPtr = headPtr;
		headPtr = headPtr->getNext();

		if (headPtr != nullptr) {
			headPtr->setPrev(nullptr);
		}

		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
	}
	else {
		Node<ItemType>* curPtr = getNodeAt(pos);
		Node<ItemType>* prevPtr = curPtr->getPrev();
		Node<ItemType>* nextPtr = curPtr->getNext();

		prevPtr->setNext(nextPtr);

		if (nextPtr != nullptr) {
			nextPtr->setPrev(prevPtr);
		}

		curPtr->setNext(nullptr);
		curPtr->setPrev(nullptr);
		delete curPtr;
		curPtr = nullptr;
	}

	count--;
	return true;
}

/*bool DoublyLinkedList<ItemType>::remove(int pos) {
	if (pos<1 || pos>count) {
		return false;
	}
	else
	{
		Node<ItemType>* curPtr = nullptr;
		if (pos == 1) {
			if (count == 1) {

			}
			headPtr->getNext()->setPrev(nullptr);
			headPtr = headPtr->getNext();
			count--;
		}
		else {
			if (getNodeAt(pos) == nullptr) {

			}
			else {
				curPtr = getNodeAt(pos);
				Node<ItemType>* prevPtr = getNodeAt(pos)->getPrev();
				prevPtr->setNext(curPtr->getNext());
				curPtr->getNext()->setPrev(curPtr->getPrev());
				curPtr->setNext(nullptr);
				curPtr->setPrev(nullptr);
			}


		}
		

		delete curPtr;
		curPtr = nullptr;

	}
	return true;
}*/
template<class ItemType>
void DoublyLinkedList<ItemType>::clear() {
	while (!isEmpty()) {
		remove(1);
	}
}
template<class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const {
	return count == 0;
}
template<class ItemType>
int DoublyLinkedList<ItemType>::getLength() const {
	return count;
}
/*template<class ItemType>
ItemType DoublyLinkedList<ItemType> ::replace(int pos, const ItemType& newEntry) {
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
DoublyLinkedList<ItemType>::~DoublyLinkedList() {
	clear();
}
template<class ItemType>
bool DoublyLinkedList<ItemType>::removeWithData(const ItemType& removedEntry) {
	if (headPtr == nullptr) {
	
		return false;
	}

	bool found = false;
	Node<ItemType>* curPtr = headPtr;

	if (*(curPtr->getItem()) == removedEntry) {
		
		found = true;
		headPtr = curPtr->getNext();
		if (headPtr != nullptr) {
			headPtr->setPrev(nullptr);
		}
		delete curPtr;
		count--;
		return found;
	}

	while (!found && curPtr != nullptr) {
		if (curPtr->getNext() != nullptr && *(curPtr->getNext()->getItem()) == removedEntry) {
			found = true;
			Node<ItemType>* deletedPtr = curPtr->getNext();
			curPtr->setNext(deletedPtr->getNext());
			if (deletedPtr->getNext() != nullptr) {
				deletedPtr->getNext()->setPrev(curPtr);
			}
			delete deletedPtr;
			count--;
			return found;
		}
		curPtr = curPtr->getNext();
	}

	return false;
}

/*template<class ItemType>
bool DoublyLinkedList<ItemType>::removeWithData(const ItemType& removedEntry) {
	bool found = false;
	Node<ItemType>* curPtr = headPtr;
	if (*(curPtr->getItem()) == removedEntry) {
		found = true;
		headPtr = curPtr->getNext();
		headPtr->setPrev(nullptr);
		delete curPtr;
		count--;
		return found;
	}
	while (!found && curPtr->getNext() != nullptr) {

		if (*(curPtr->getNext()->getItem()) == removedEntry) {
			found = true;
			Node<ItemType>* deletedPtr = curPtr->getNext();
			if (curPtr->getNext()->getNext() != nullptr) {
				curPtr->setNext(curPtr->getNext()->getNext());
				curPtr->getNext()->getNext()->setPrev(curPtr);
			}
			else {
				curPtr->setNext(nullptr);
			}

			delete deletedPtr;
			count--;
			return found;
		}
		curPtr = curPtr->getNext();
	}

	return false;;
}*/
template<class ItemType>
bool DoublyLinkedList<ItemType>::addByOrder(const ItemType& newEntry) {

	bool done = false;
	Node<ItemType>* newNode = new Node<ItemType>(newEntry);
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;
	if (headPtr == nullptr) {
		headPtr = newNode;
		headPtr->setPrev(nullptr);
		headPtr->setNext(nullptr);
		count++;
		done = true;
		return done;

	}
	else if (*(newNode->getItem()) < *(headPtr->getItem())) {
		newNode->setNext(headPtr);
		headPtr->setPrev(newNode);
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
				curPtr->setPrev(newNode);
				prevPtr->setNext(newNode);
				newNode->setPrev(prevPtr);
				count++;
				done = true;
				return done;
			}
			prevPtr = curPtr;
			curPtr = curPtr->getNext();

		}
		if (!done) {
			prevPtr->setNext(newNode);
			newNode->setPrev(prevPtr);
			count++;
			done = true;
			return done;
		}
	}

}
template<class ItemType>
Node<ItemType>* DoublyLinkedList<ItemType>::getNodeByItem(const ItemType& newEntry) const {
	Node<ItemType>* curPtr = headPtr;
	while (curPtr != nullptr) {
		if (*(curPtr->getItem()) == newEntry) {
			return curPtr;
		}
	}
	return nullptr;
}
template<class ItemType>
Node<ItemType>* DoublyLinkedList<ItemType>::getHeadPtr() {

	return headPtr;

}
template<class ItemType>
int DoublyLinkedList<ItemType>::getCount() {
	return count;
}
template class DoublyLinkedList<Student>;