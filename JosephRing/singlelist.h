#pragma once
#ifndef SINGLE_LIST_H_
#define SINGLE_LIST_H_
#include "linearlist.h"
#include "node.h"
//链表类不带头节点，节点的下标从0开始，第一个元素为a0，最后一个为an-1
template <class T>
class SingleList : public LinerList<T> {
public:
	SingleList(){
		first = nullptr;
		n = 0;
	};
	//~SingleList();
	bool IsEmpty() const;
	int Length() const;
	int Search(T x) const;
	bool Insert(int i, T x);
	bool Delete(int i);
	bool Update(int i, T x);
	bool Find(int i, T &x) const;
	void Output() const;
	void getFirst(Node<T> *x);
	void MoveNonius(int i);
	void GetPath(int i, Node<T> *p);
	void set_length(int i);
	bool DeleteNode(int *x);
private:
	Node<T> *first;
	Node<T> *now;
};

//删除节点 
template <class T>
bool SingleList<T>::DeleteNode(int *x) {
	if (n == 0) {
		cout << "没有了，你还想删？naive!!!";
		return false;
	} else if (n == 1) {
		cout << "\t\t\t" << now->originNumber << endl;
		n--;
		return true;
	}

	int l = Length();
	Node<T>  *last = new Node<T>;
	last->link = now->link;

	//last指向now指针指向节点的上一个节点
	for (int i = 0; i < l - 1; ++i) {
		last = last->link;
	}

	Node<T> *q = new Node<T>;
	q = last->link;
	last->link = q->link;
	//改变密钥
	*x = q->secretNumber;
	MoveNonius(*x);
	//输出被产出节点最初的值
	cout << "\t\t\t" << q->originNumber << endl;

	delete q;
	n--;
	return true;
}

//移动游标
template <class T>
void SingleList<T>::MoveNonius(int i) {
	for (int j = 0; j < i; ++j) {
		now = now->link;
	}
}

//获取到头指针
template <class T>
void SingleList<T>::getFirst(Node<T> *x) {
	x->link = first;
	x = first;
}

//获取第i + 1个节点的地址
template <class T>
void SingleList<T>::GetPath(int i, Node<T> *x) {
	if (i < 0 || i > n - 1) {
		std::cout << "Out of Bounds" << endl;
	}
	Node<T>  *p = first;
	for (int j = 0; j < i; ++i) {
		p = p->link;
	}
	x = p;
}

//
//销毁链表时的操作
//template <class T>
//SingleList<T>::~SingleList() {
//	Node<T> *p;
//	while (first) {
//		p = first->link;
//		delete first;
//		first = p;
//	}
//}

//返回链表的长度
template <class T>
int SingleList<T>::Length() const {
	return n;
}

//设置链表的长度
template <class T>
void SingleList<T>::set_length(int i) {
	n = i;
}

//判断链表是否为空
template <class T>
bool SingleList<T>::IsEmpty() const {
	return n == 0;
}

//获取链表中第i + 1个节点的地址
template <class T>
bool SingleList<T>::Find(int i, T &x) const {
	//if (i < 0 || i > n - 1) {
	//	std::cout << "Out of Bounds" << endl;
	//}
	Node<T>  *p = first;
	for (int j = 0; j < i; ++i) {
		p = p->link;
	}
	x = p->originNumber;
	return true;
}

//输出链表
template<class T>
void SingleList<T>::Output() const {
	Node<T> *p = first;
	while(p) {
		std::cout << p->element << "\t";
		p = p->link;
	}
	std::cout << endl;
}


//查找节点在链表中的位置
template <class T>
int SingleList<T>::Search(T x) const {
	Node<T> *p = first;
	int j = 0;
	for (; p && p->secretNumber != x; ++j) {
		p = p->link;
	}
	if (p) {
		return j + 1;
	}
	return -1;
}

//插入节点的空隙i处-1， 0， 1， 2， 3
template <class T>
bool SingleList<T>::Insert(int i, T x) {
	if (i < -1 || i > n - 1) {
		std::cout << "Out Of Bounds" << endl;
		return false;
	}  
	Node<T> *q = new Node<T>();
	q->secretNumber = x;
	q->originNumber = i + 2;
	Node<T> *p = first;
	for (int j = 0; j < i; ++j) {
		p = p->link;
	}
	if (i > -1) {
		q->link = p->link;
		p->link = q;
		q->link = first;
		q->firstNode = 0;
	} else {
		//头指针就是第一个节点
		now = new Node<int>;
		q->link = first;
		first = q;
		first->firstNode = 1;
		//初始化的时候now指针指向第一个节点
		now->link = first;
	}
	
	n++;
	return true;
}

//删除第i + 1个节点
template <class T>
bool SingleList<T>::Delete(int i) {
	//当n == 0时就不能再删除了
	if (!n) {
		std::cout << "UnderFlow" << endl;
		return false;
	}
	if (i < 0 || i > n - 1) {
		cout << "Out of Bounds" << endl;
		return false;
	}
	Node<T> *p = first;
	Node<T> *q = first;
	//让p指向要被删除节点的上一个节点
	for (int j = 0; j < i - 1; ++j) {
		p = p->link;
	}
	//若i为0，则删除头节点
	if (i == 0) {
		cout << first->originNumber;
		Node<T> *last = first;
		for (int a = 0; a < n - 1; ++a) {
			last = last->link;
		}
		last->link = first->link;
		first = first->link;
		first->firstNode = 1;
	} else {
		q = p->link;
		p->link = q->link;
	}
	delete q;
	n--;
	return true;
}

//更新第i + 1个节点的数据
template <class T>
bool SingleList<T>::Update(int i, T x) {
	if (i < 0 || i > n - 1) {
		std::cout << "Out of Bounds" << endl;
		return false;
	}
	Node<T> *p = first;
	for (int j = 0; j < i; ++j) {
		p = p->link;
	}
	p->secretNumber = x;
	return true;
}



#endif // !SINGLE_LIST_H_