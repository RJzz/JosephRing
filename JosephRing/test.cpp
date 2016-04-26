#include "singlelist.h"
#include <stdio.h>
int main() {
	int number;		//人数
	int m;			//报数初始值
	int count = 0;	//用于控制游标的移动信号
	cout << "\t\t--------------------------欢迎来到RJzz的约瑟夫程序--------------------------\n";
	cout << "\t\t\t请输入初始的人数: ";
	cin >> number;
	cout << "\t\t\t请输入报数的初始值: ";
	cin >> m;
	cout << "\t\t\t请按照顺序输入他们的密钥!" << endl;
	SingleList<int> a;
	for (int i = 0; i < number; ++i) {
		int secret;
		cout << "\t\t\t请输入第" << i + 1 << "个成员的密钥: ";
		cin >> secret;
		a.Insert(i - 1, secret);
	}
	cout << "\t\t\t输入结束，正在进行计算出队顺序" << endl;
	while (!a.IsEmpty()) {
		if (count == 0) {
			//第一次移动游标后count++,
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
//		//获取到当前出来那个人的密钥
//		secretKey = x->link->secretNumber;
//		//q为要删除的那个节点
//		Node<int> *q = new Node<int>;
//		//如果是要删除头节点则将头节点指向他后继的后继
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
//			//链表的长度减少
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
