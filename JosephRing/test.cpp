#include "singlelist.h"
#include <stdio.h>
int main() {
	int number;		//����
	int m;			//������ʼֵ
	int count = 0;	//���ڿ����α���ƶ��ź�
	cout << "\t\t--------------------------��ӭ����RJzz��Լɪ�����--------------------------\n";
	cout << "\t\t\t�������ʼ������: ";
	cin >> number;
	cout << "\t\t\t�����뱨���ĳ�ʼֵ: ";
	cin >> m;
	cout << "\t\t\t�밴��˳���������ǵ���Կ!" << endl;
	SingleList<int> a;
	for (int i = 0; i < number; ++i) {
		int secret;
		cout << "\t\t\t�������" << i + 1 << "����Ա����Կ: ";
		cin >> secret;
		a.Insert(i - 1, secret);
	}
	cout << "\t\t\t������������ڽ��м������˳��" << endl;
	while (!a.IsEmpty()) {
		if (count == 0) {
			//��һ���ƶ��α��count++,
			a.MoveNonius(m);
			count++;
		}
		a.DeleteNode(&m);
	}

	system("PAUSE");
	return 0;
} 


//void JosephRing(SingleList<int> *a, int secretKey, Node<int> *x) {
//	if (!a->IsEmpty()) {
//
//		//int outputNumber = 0;
//		//a->Find(secretKey - 1, outputNumber);
//		//cout << outputNumber << "\t\n";
//		for (int j = 0; j < secretKey - 1; ++j) {
//			x = x->link;
//		}
//		//��ȡ����ǰ�����Ǹ��˵���Կ
//		secretKey = x->link->secretNumber;
//		//qΪҪɾ�����Ǹ��ڵ�
//		Node<int> *q = new Node<int>;
//		//�����Ҫɾ��ͷ�ڵ���ͷ�ڵ�ָ������̵ĺ��
//		if (x->link->firstNode == 1) {
//			//Node<int> *last = new Node<int>;
//			//a->GetPath(a->Length() - 1, last);
//			//last->link = vernier->link;
//			//vernier = vernier->link;
//			
//			a->Delete(0);
//		} else {
//			q = x->link;
//			x->link = q->link;
//			//����ĳ��ȼ���
//			a->set_length(a->Length() - 1);
//		}
//
//		delete q;
//		JosephRing(a, secretKey, x);
//	} else {
//		cout << "Over";
//	}
//
//}
