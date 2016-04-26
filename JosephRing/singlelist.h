#pragma once
#ifndef SINGLE_LIST_H_
#define SINGLE_LIST_H_
#include "linearlist.h"
#include "node.h"
//�����಻��ͷ�ڵ㣬�ڵ���±��0��ʼ����һ��Ԫ��Ϊa0�����һ��Ϊan-1
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

//ɾ���ڵ� 
template <class T>
bool SingleList<T>::DeleteNode(int *x) {
	if (n == 0) {
		cout << "û���ˣ��㻹��ɾ��naive!!!";
		return false;
	} else if (n == 1) {
		cout << "\t\t\t" << now->originNumber << endl;
		n--;
		return true;
	}

	int l = Length();
	Node<T>  *last = new Node<T>;
	last->link = now->link;

	//lastָ��nowָ��ָ��ڵ����һ���ڵ�
	for (int i = 0; i < l - 1; ++i) {
		last = last->link;
	}

	Node<T> *q = new Node<T>;
	q = last->link;
	last->link = q->link;
	//�ı���Կ
	*x = q->secretNumber;
	MoveNonius(*x);
	//����������ڵ������ֵ
	cout << "\t\t\t" << q->originNumber << endl;

	delete q;
	n--;
	return true;
}

//�ƶ��α�
template <class T>
void SingleList<T>::MoveNonius(int i) {
	for (int j = 0; j < i; ++j) {
		now = now->link;
	}
}

//��ȡ��ͷָ��
template <class T>
void SingleList<T>::getFirst(Node<T> *x) {
	x->link = first;
	x = first;
}

//��ȡ��i + 1���ڵ�ĵ�ַ
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
//��������ʱ�Ĳ���
//template <class T>
//SingleList<T>::~SingleList() {
//	Node<T> *p;
//	while (first) {
//		p = first->link;
//		delete first;
//		first = p;
//	}
//}

//��������ĳ���
template <class T>
int SingleList<T>::Length() const {
	return n;
}

//��������ĳ���
template <class T>
void SingleList<T>::set_length(int i) {
	n = i;
}

//�ж������Ƿ�Ϊ��
template <class T>
bool SingleList<T>::IsEmpty() const {
	return n == 0;
}

//��ȡ�����е�i + 1���ڵ�ĵ�ַ
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

//�������
template<class T>
void SingleList<T>::Output() const {
	Node<T> *p = first;
	while(p) {
		std::cout << p->element << "\t";
		p = p->link;
	}
	std::cout << endl;
}


//���ҽڵ��������е�λ��
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

//����ڵ�Ŀ�϶i��-1�� 0�� 1�� 2�� 3
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
		//ͷָ����ǵ�һ���ڵ�
		now = new Node<int>;
		q->link = first;
		first = q;
		first->firstNode = 1;
		//��ʼ����ʱ��nowָ��ָ���һ���ڵ�
		now->link = first;
	}
	
	n++;
	return true;
}

//ɾ����i + 1���ڵ�
template <class T>
bool SingleList<T>::Delete(int i) {
	//��n == 0ʱ�Ͳ�����ɾ����
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
	//��pָ��Ҫ��ɾ���ڵ����һ���ڵ�
	for (int j = 0; j < i - 1; ++j) {
		p = p->link;
	}
	//��iΪ0����ɾ��ͷ�ڵ�
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

//���µ�i + 1���ڵ������
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