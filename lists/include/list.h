#ifndef LIST_H
#define LIST_H

#include <string>

enum class TodoState {OPEN, DONE, CANCELLED};

struct Data {
	std::string text;
	TodoState state;
};

struct Node {
	Data data;
	Node* prev = nullptr;
	Node* next = nullptr;
};

class List {
private:
	Node* head;
 	Node* tail;
 	unsigned int counter;
public:
	List() {
		head = nullptr;
		tail = nullptr;
		counter = 0;
	}
	
	~List() {
		clear();
		delete head;
		delete tail;
	}
	
	void push_front(Data data);
	void push_back(Data data);
	Data pop_front();
	Data pop_back();
	Data front();
	Data back();
	unsigned int size();
	Data get(unsigned int idx);
	bool empty();
	void erase(unsigned int idx);
	void clear();
	void print();
};

#endif
