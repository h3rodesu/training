#include<iostream>
#include<iomanip>
using namespace std;
class DoublyListNode {
private:
	struct Node {
		int val;
		Node* next;
		Node* prev; 
		Node(int value) : val(value), next(nullptr), prev(nullptr) {}
	};
	Node* head;
	Node* tail;
public:
	DoublyListNode() :head(nullptr), tail(nullptr) {}//созданиe объекта
	void InsertAtEnd(int value) {
		Node* NewNode = new Node(value);
		if (head == nullptr) {
			head = NewNode;
	 tail=NewNode;
		}
		else {
			tail->next = NewNode;
			NewNode->prev = tail;
			tail = NewNode;
		}
	}
	void ShowDefaultList() {
		cout << "Список:" << endl;
		Node* current = head;
		if (head = nullptr) {
			cout << "Список пуст" << endl;
			return;
		}
		else {
			while (current != nullptr) {
				cout << current->val;
				current = current->next;
			}
		}
	}
	void ShowReversedList() {
		cout << "Ревёрс:" << endl;
		Node* current = tail;
		while (current != nullptr) {
			cout << current->val;
			current = current->prev;
		}
	}
	~DoublyListNode() {
		Node* current = head;
		Node* NextNode;
		while (current!= nullptr) {
			NextNode = current->next;
			delete current;
			current = NextNode;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	DoublyListNode List;
	List.InsertAtEnd(10);
	List.InsertAtEnd(20);
	List.InsertAtEnd(30);
	List.InsertAtEnd(40);
	List.InsertAtEnd(50);

	List.ShowDefaultList();
	cout << endl;
	List.ShowReversedList();
	system("Pause");
	return 0;
}