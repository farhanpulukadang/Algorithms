#include <iostream>
using namespace std;
template <class T>
struct linked_list {
	struct Node {
		Node* next;
		Node* prev;
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
			head = new Node({ 0, 0, value });
			tail = head;
		}
		else {
			tail->next = new Node({ 0, tail->prev, value });
			tail->next->prev = tail;
			tail = tail->next;
		}
		length++;
	}
	void push_front(T value) {
		head = new Node({head, 0, value});
		head->next->prev = head;
		length++;
	}
	void insert(unsigned pos, T value) {
		Node* ptr = head;
		for (int i = 0; i != pos; i++) {
			ptr = ptr->next;
		}
		if (pos == 0) {
			this->push_front(value);
			return;
		}
		else if (pos == length) {
			this->push_back(value);
			return;
		}
		else {
			Node* newnode = new Node({ ptr, ptr->prev, value });
			ptr->prev->next = newnode;
			ptr->prev = newnode;
			length++;
		}
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
	number.push_front("Zeroth");
	number.insert(5, "Inserted");
	cout << number.size() << endl;
	for (int i = 0; i != number.size(); i++) {
		cout << number[i] << endl;
	}
	return 0;
}