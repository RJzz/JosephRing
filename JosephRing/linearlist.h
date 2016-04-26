#pragma once
#ifndef LINEARLIST_LIST_H_
#define LINEARLIST_LIST_H_
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
template <class T>
class LinerList {
public:
	virtual bool IsEmpty() const = 0;
	virtual int Length() const = 0;
	virtual bool Find(int i, T &x) const = 0;
	virtual int Search(T x) const = 0;
	virtual bool Delete(int i) = 0;
	virtual bool Update(int i, T x) = 0;
	virtual bool Insert(int i, T x) = 0;
	//virtual void OutPut() const = 0;
protected:
	int n;		//线性表的长度
};


#endif LINEARLIST_LIST_H_