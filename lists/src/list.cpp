#include "list.h"

#include <iostream>

using namespace std;

void List::push_front(Data data) {
	Node* temp = new Node();
	temp->data = data;
	if (head != nullptr) {
		temp->prev = nullptr;
		temp->next = head;
		if (head == tail) {
			tail->prev = temp;
		}
		head->prev = temp;
	} else {
		temp->prev = nullptr;
		temp->next = nullptr;
		tail = temp;
	}
	head = temp;
	temp = nullptr;
	delete temp;
	counter++;
}

void List::push_back(Data data) {
	Node* temp = new Node();
    temp->data = data;
	if (tail != nullptr) {
        temp->prev = tail;
		temp->next = nullptr;
        if (head == tail) {
            head->next = temp;
        }
		tail->next = temp;
    } else {
		temp->prev = nullptr;
		temp->next = nullptr;
		head = temp;
	}
    tail = temp;
	temp = nullptr;
	delete temp;
	counter++;
}

void List::print() {
	Node* temp = head;
	while (temp != tail) {
		cout  << temp->data.text << ", ";
		temp = temp->next;
	}

	cout << temp->data.text << endl;
}

Data List::pop_front() {
	if (head != nullptr) {
		Data data = head->data;
		Node* temp = head;

		if (head == tail) {
			head = nullptr;
			tail = nullptr;
		} else {
			head = head->next;
		}
		counter--;
		return data;
	}
	Data data;
	return data;
}

Data List::pop_back() {
	if (head != nullptr) {
        Data data = tail->data;
        Node* temp = tail;

        if (head == tail) {
            tail = nullptr;
			head = nullptr;
        } else {
            tail = tail->prev;
        }
		counter--;
        return data;
    }
    Data data;
    return data;
}

Data List::front() {
	if (head != nullptr) {
        return head->data;
    }
}

Data List::back() {
	if (head != nullptr) {
        return tail->data;
    }
}

unsigned int List::size() {
	return counter;
}

Data List::get(unsigned int idx) {
	if (idx < counter) {
		Node* temp = head;
    	while (idx > 0) {
        	temp = temp->next;
        	idx--;
    	}
		return temp->data;
	}
	Data data;
	return data;
}


bool List::empty() {
	return (head == nullptr); // return (counter == 0);
}

void List::erase(unsigned int idx) {
	if (idx < counter) {
        Node* temp = head;
        while (idx != 0) {
            temp = temp->next;
            idx--;
        }

        if (temp != head) {
        	temp->prev->next = temp->next;
		} else {
			head = temp->next;
		}
		
		if (temp != tail) {
        	temp->next->prev = temp->prev;
		} else {
			delete tail;
			tail = temp->prev;
		}
        counter--;
    }
	// exception??
}

void List::clear() {
	Node* temp = head;
	while (temp != tail && temp != nullptr) {
		temp->prev = nullptr;
		delete temp->prev;
		temp = temp->next;
	}
	tail = nullptr;
	delete tail;
	delete head;

	counter = 0;
}

