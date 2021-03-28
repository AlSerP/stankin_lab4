#pragma once
#include "Element.h"
#include <iostream>

class Stack {
private:
	element *top = NULL;
	int length = 0;
public:
	Stack(int data);
	Stack();
	void push(int data);
	void extract(element *element);
	void reverse() const;
	int get_length() const;
	element* get_element(int id) const;
	int get_id_by_element(element* el) const;
	Stack copy() const;
	
	Stack operator + (int data) const;
	Stack operator += (int data);
	
	Stack operator - (element* el) const;
	Stack operator -= (element* el);

	Stack operator * (int n) const;
	
	bool operator == (Stack stack) const;
	
	Stack operator = (Stack stack) const;

  int &operator [] (int i);
};
