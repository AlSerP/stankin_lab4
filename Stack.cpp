#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int data) {
	element* q;

	q = new element();
	q->data = data;

	top = q;
	length = 1;
}

Stack::Stack() {}

void Stack::push(int data) {
	element *q;

	q = new element();
	q->data = data;
	q->next = top;

	top = q;
	length++;
}

void Stack::extract(element *el) {
	if (length < 2) {
		cout << "You can't delete the element from stack with length = 1\n";
	}
	else if (el == top) {
		top = top->next;
	}
	else {
		element* q = top;
		element* p;
		while (q) {
			p = q;
			q = q->next;
			if (q == el) {
				if (q->next)
					p->next = q->next;
				else
					p->next = NULL;
				length--;
				break;
			}
		}
	}
}

void Stack::reverse() const {
	int* nums = new int[length];
	int i = 0;

	element* q = top;
	while (q) {
		nums[i] = q->data;
		q = q->next;
		i++;
	}

	q = top;
	while (q) {
		i--;
		q->data = nums[i];
		q = q->next;
	}
	delete[] nums;
}


int Stack::get_length() const {
	return length;
}

element* Stack::get_element(int id) const {
	if (id + 1 >= length) {
		cout << "There are no element with such id\n";
		return NULL;
	}

	element* q = top;
	if (id == 0)
		return q;
	for (int i = 0; i != id; i++)
		q = q->next;
	
	return q;
}

int Stack::get_id_by_element(element* el) const {
	element* q = top;
	int i = 0;
	while (i < length && q != el) {
		q = q->next;
		i++;
	}

	return i;
}

Stack Stack::copy() const {
	element* q = top;
	
	Stack stack_copy(q->data);
	q = q->next;
	
	while (q) {
		element* el;
		
		stack_copy.push(q->data);
		q = q->next;
	}
	stack_copy.reverse();
	
	return stack_copy;
}

// -----------------------OPERATORS-----------------------

Stack Stack::operator + (int data) const {
	Stack result = this->copy();
	result.push(data);
	return result;
}

Stack Stack::operator += (int data) {
	this->push(data);
	return this->copy();
}

Stack Stack::operator - (element* el) const {
	Stack result = this->copy();
	result.extract(result.get_element(this->get_id_by_element(el)));
	return result;
}

Stack Stack::operator -= (element* el) {
	this->extract(el);
	return *this;
}

Stack Stack::operator * (int n) const {
	Stack result = this->copy();
	element* el = result.get_element(0);
	el->data *= n;
	return result;
}


bool Stack::operator == (Stack stack) const {
	if (this->length != stack.get_length()) {
		cout << this->length << ' ' << stack.get_length() << '\n';
		return false;
	}
	
	element* q_1 = top;
	element* q_2 = stack.get_element(0);
	
	while (q_1 && q_2) {
		if (q_1->data != q_2->data)
			return false;
		q_1 = q_1->next;
		q_2 = q_2->next;
	}
	return true;
}

Stack Stack::operator = (Stack stack) const {
	return stack.copy();
}

int &Stack::operator [] (int j) {
  element* q = top;

  j = length - j - 1;
	if (j <= 0)
		return q->data;
	for (int i = 0; i != j; i++)
		q = q->next;
	
	return q->data;
}
