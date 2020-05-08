//#include "list.h"

#include "docopt.h"

#include <iostream>
#include <string>

using namespace std;

static const char USAGE[]{
R"(Todo-App.
 Usage:
 todo [-o FILE] add <text>
 todo [-o FILE] remove [--all|<number>]
 todo [-o FILE] change <number> (--open|--done|--cancelled)
 todo [-o FILE] change <number> <text>
 todo [-o FILE] list
 Options:
 -o FILE specify storage file to use [default: todos.txt].
 --open change status of a todo item to open.
 --done change status of a todo item to done.
 --cancelled change status of a todo item to cancelled.
)"};

int main(int argc, const char* argv[]) {
	try {map<string, docopt::value> args{docopt::docopt(
 		USAGE, //pattern
 		{argv+1, argv+argc}, //arguments
 		true //help?
 	)};
	cout << endl;
 	
	for(auto const& arg : args) {
 		cout << arg.first << arg.second << endl;
 	}} catch (...) {}
}

/*int main() {
	Data data;
	List l{};
		
	data.text = "def";
	data.state = TodoState::OPEN;
	
	l.push_back(data);
	data.text = "ghi";
	l.push_back(data);
	data.text = "jkl";
    l.push_back(data);
	data.text = "abc";
	l.push_front(data);


	l.erase(1);
	l.pop_front();
	l.pop_back();
	l.push_back(data);
    data.text = "ghi";
    l.push_back(data);
    data.text = "jkl";
    l.push_back(data);
    data.text = "abc";
    l.push_front(data);


    l.erase(1);
    l.pop_front();
    l.pop_back();

	cout << endl;
	l.print();
	cout << l.get(3).text << endl;
	cout << l.front().text << endl;
	cout << l.back().text << endl;
	l.clear();
	l.push_back(data);
    data.text = "ghi";
    l.push_back(data);
    data.text = "jkl";
    l.push_back(data);
    data.text = "abc";
    l.push_front(data);


    l.erase(1);
    l.pop_front();
    l.pop_back();

    cout << endl;
    l.print();
}*/
