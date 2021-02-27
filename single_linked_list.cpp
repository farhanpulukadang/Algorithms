#include <iostream>
using namespace std;
template <class T>
struct linked_list {
	struct Node {
		Node* next;
		T value;
	};
	Node* head;
	Node* tail;
	unsigned length{ 0 };
	unsigned size(void) {
		return length;
	}
	void push_back(T value) {
		if (length == 0) {
			head = new Node({0, value});
			tail = head;
		}
		else {
			tail->next = new Node({0, value});
			tail = tail->next;
		}
		length++;
	}
	T operator[](unsigned index) {
		Node* ptr = head;
		for (int i = 0; i != index; i++) {
			ptr = ptr->next;
		}
		return ptr->value;
	}
};
int main() {
	linked_list<string> number;
	number.push_back("First");
	number.push_back("Second");
	number.push_back("Third");
	number.push_back("Fourth");
	for (int i = 0; i != number.size(); i++) {
		cout << number[i] << endl;
	}
	return 0;
}