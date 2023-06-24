//Emre Furkan Akyol Section2  22103352
#include "Node.h"
#include "Student.h"
#include "Course.h"
template<class ItemType>
Node<ItemType>::Node() {
	this->previous = nullptr;
	this->next = nullptr;

}
template<class ItemType>
Node<ItemType>::Node(const ItemType& item) {
	this->item = item;
	this->next = nullptr;
}
template<class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType>* nextNodePtr) {
	this->item = item;
	this->next = nextNodePtr;
}
template<class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType>* nextNodePtr, Node<ItemType>* prevNodePtr)
{
	this->item = item;
	this->next = nextNodePtr;
	this->previous = prevNodePtr;
}
template<class ItemType>
void Node<ItemType>::setItem(const ItemType& item)
{
	this->item = item;
}
template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}
template<class ItemType>
void Node<ItemType>::setPrev(Node<ItemType>* prevNodePtr)
{
	previous = prevNodePtr;
}
template<class ItemType>
ItemType* Node<ItemType>::getItem()  {
	return &item;
}
template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const {
	return next;
}
template<class ItemType>
Node<ItemType>* Node<ItemType>::getPrev() const {
	return previous;
}
template class Node<Course>;
template class Node<Student>;
