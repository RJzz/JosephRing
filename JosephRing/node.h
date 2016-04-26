#pragma once
#ifndef NODE_H_
#define NODE_H_
template <class T> class SingleList;
template <class T> class Node;
//void JosephRing(SingleList<int> *a, int m, Node<int> *x);

template <class T>
class Node {
private:
	T firstNode;
	T originNumber;
	T secretNumber;
	Node<T> *link;
	friend class SingleList<T>;
	//friend void JosephRing(SingleList<int> *a, int m, Node<int> *x);
};
#endif NODE_H_