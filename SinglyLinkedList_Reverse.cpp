#include<iostream>
#include<iomanip>
using namespace std;
struct DNode {
public:
	int val;
	DNode* next;
	DNode* prev;
	DNode(int value) :val(value), next(nullptr), prev(nullptr) {}
};
void InsertToEnd(DNode*& head, int value) {
	DNode* newNode = new DNode(value);
	DNode* current = head;
	if (head == nullptr) {
		head = newNode;
	}
	else {
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
		newNode->prev = current;
	}
}
void ShowReverseList(DNode*& head) {
	if (head == nullptr) {
		cout << "Пусто" << endl;
		return;
	}
	else {
		DNode* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		while (current != nullptr) {
			cout << current->val << endl;
			current = current->prev;
		}
	}
}
void DeleteList(DNode*& head) {
	DNode* current = head;
	DNode* nextNode;
	while (current!= nullptr) {
		 nextNode=current->next;
		 delete current;
		 current = nextNode;
		 
	}
	cout << "Список удален" << endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	DNode* head = nullptr;
	InsertToEnd(head, 10);
	InsertToEnd(head, 20);
	InsertToEnd(head,30);
	ShowReverseList(head);

	DeleteList(head);
	system("Pause");
	return 0;
}