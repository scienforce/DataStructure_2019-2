#include <iostream>

using namespace std;

template <class T>
class list {
private:
	class listNode {
	public:
		T data;
		listNode * next;
		listNode() { data = -1; next = NULL; }
		listNode(T newItem);
	};
public:
	list() { size = 0; head = new listNode(); head->next = new listNode(); }
	~list();
	listNode * Find(listNode * curr, int k) {
		if (k == 0 || curr == NULL) {
			return curr;
		}
		else {
			Find(curr->next, k - 1);
		}
	}
	void insertAtFront(listNode * &curr, T d);
	void insert(int k, T d);
	void remove(listNode *& curr) {
		listNode * temp = curr->next;
		curr->data = temp->data;
		curr->next = temp->next;
		delete temp;
		size--;
	}
	void printReverse(listNode * curr) {
		if (curr->next != NULL) {
			printReverse(curr->next);
			cout << curr->data;
		}
	}
	int getSize() const {
		cout << "Size : " << size << endl;
		return size;
	}
	T & getData(int loc) {
		listNode * temp = find(head, loc);
		return temp->data;
	}
	listNode * getHead();
private:
	listNode * head;
	int size;
};

int main() {
	list<int> list;

	list.insertAtFront(list.getHead()->next, 4);
	list.insert(1, 6);
	list.insert(2, 9);

	cout << list.getSize() << endl;
	list.printReverse(list.getHead()->next);

	return 0;
}

template <class T>
list<T>::listNode::listNode(T newItem) { 
	data = newItem;
	next = NULL;
}

template <class T>
list<T>::~list() {
	//remove all list
	listNode * temp = head->next;
	while (temp != NULL) {
		delete head;
		head = temp;
		temp = temp->next;
	}
	delete head;
}

template <class T>
void list<T>::insertAtFront(listNode * &curr, T d) {
	listNode * temp = new listNode(d);
	temp->next = curr;
	curr = temp;
	size++;
}

template <class T>
void list<T>::insert(int k, T d) {
	listNode * temp = new listNode(d);
	listNode * p = Find(head, k - 1);	
	temp->next = p->next;
	p->next = temp;
	size++;
}

template <class T>
list<T>::listNode *list<T>:: getHead() {
	return head;
}