#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*template <typename T>
class LinkedList {
public:
	struct Node {
		T data;
		Node* previous;
		Node* next;
	};

	LinkedList();
	LinkedList(const LinkedList<T>& list);
	LinkedList<T>& operator=(const LinkedList<T>& rhs);
	~LinkedList();
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	unsigned int NodeCount() const;
	void PrintForward() const;	
	void PrintReverse() const;
	void Clear();
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	void FindAll(vector<Node*>& outData, const T& value) const;
	bool RemoveHead();
	bool RemoveTail();
	bool RemoveAt(unsigned int index);
	unsigned int Remove(const T& data);
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;


private:
	unsigned int nodeCount;
	Node* head;
	Node* tail;
};

template <typename T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
	nodeCount = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
	nodeCount = 0;

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	nodeCount = 0;

	for (unsigned int i = 0; i < nodeCount; i++) {

	}
}

template <typename T>
LinkedList<T>::~LinkedList() {
	Clear();
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
	return head;
}

template <typename T>
const typename LinkedList<T>:: Node* LinkedList<T>::Head() const {
	return head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
	return tail;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
	return tail;
}

template <typename T>
void LinkedList<T>::AddHead(const T& data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->previous = nullptr;
	newNode->next = nullptr;

	if (nodeCount == 0) {
		//cout << "addhead if empty list";
		head = newNode;
		tail = newNode;
		head->previous = nullptr;
		head->next = nullptr;
	}
	else {
		head->previous = newNode;
		newNode->next = head;
		head = newNode;
	}
	nodeCount++;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->previous = nullptr;
	newNode->next = nullptr;

	if (nodeCount == 0) {
		//cout << "addhead if empty list";
		head = newNode;
		tail = newNode;
		tail->previous = nullptr;
		tail->next = nullptr;
	}
	else {
		tail->next = newNode;
		newNode->previous = tail;
		tail = newNode;
	}
	nodeCount++;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
	nodeCount = count;

	for (unsigned int i = (count - 1); i >= 0; i--) {
		AddHead(data[i]);
		cout << "added head " << nodeCount << endl;
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
	nodeCount = count;

	for (unsigned int i = 0; i < count; i++) {
		AddTail(data[i]);
	}
}

template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
	return nodeCount;
}

template <typename T>
void LinkedList<T>::PrintForward() const {
	Node* temp = head;

	while (temp != nullptr) {
		cout << temp->data << endl;
		temp = temp->next;
	}
}

template <typename T>
void LinkedList<T>::PrintReverse() const {
	Node* temp = new Node;
	temp = tail;

	while (temp != nullptr) {
		cout << temp->data << endl;
		temp = temp->previous;
	}
}

template <typename T>
void LinkedList<T>::Clear() {
	Node* start = head;
	Node* temp;

	while (start != nullptr) {
		temp = start->next;
		delete start;
		start = temp;
	}
	nodeCount = 0;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
	if (index > nodeCounter) {
		throw out_of_range("Index out of range");
	}

	Node* foundNode = head;
	unsigned int count = 0;

	while (count != index) {
		foundNode = foundNode->next;
		count++;
	}

	return foundNode;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
	if (index > nodeCounter) {
		throw out_of_range("Index out of range");
	}

	Node* findNode = head;
	unsigned int count = 0;

	while (count != index) {
		findNode = findNode->next;
		count++;
	}

	return findNode;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
	Node* findNode = head;
	bool found = false;

	while (found == false) {
		int nodeData = findNode->data;
		if (nodeData == data) {
			found = true;
		}
		else {
			while (findNode != nullptr) {
				findNode = findNode->next;
				nodeData = findNode->data;
				if (nodeData == data) {
					found = true;
				}
			}
			findNode = nullptr;
		}
	}
	return findNode;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
	Node* findNode = head;
	bool found = false;

	while (found == false) {
		int nodeData = findNode->data;
		if (nodeData == data) {
			found = true;
		}
		else {
			while (findNode != nullptr) {
				findNode = findNode->next;
				nodeData = findNode->data;
				if (nodeData == data) {
					found = true;
				}
			}
			findNode = nullptr;
		}
	}
	return findNode;
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
	Node* findNode = head; 

	for (unsigned int i = 0; i < nodeCount; i++) {
		int nodeData = findNode->data;
		if (nodeData == value) {
			outData.push_back(findNode);
		}
		findNode = findNode->next;
	}
}

template <typename T>
bool LinkedList<T>::RemoveHead() {
	bool deleted;
	Node* temp = head;

	if (temp != nullptr) {
		temp->next->prev = nullptr;
		temp = temp->next;
		delete head;
		deleted = true;
	}
	else {
		deleted = false;
	}
	return deleted;
}

template <typename T>
bool LinkedList<T>::RemoveTail() {
	bool deleted;
	Node* temp = tail;

	if (temp != nullptr) {
		temp->prev->next = nullptr;
		temp = temp->prev;
		delete tail;
		deleted = true;
	}
	else {
		deleted = false;
	}
	return deleted;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
	bool deleted;
	if (index >= nodeCount) {
		deleted = false;
	}
	else {
		Node* deleteMe = GetNode(index);
		if (deleteMe == head) {
			deleteMe->next->prev = nullptr;
			delete deleteMe;
			deleted = true;
		}
		else if (deleteMe == tail) {
			deleteMe->prev->next = nullptr;
			delete deleteMe;
			deleted = true;
		}
		else {
			deleteMe->prev->next = deleteMe->next;
			deleteMe->next->prev = deleteMe->prev;
			delete deleteMe;
			deleted = true;
		}
	}
	return deleted;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data) {
	int count = 0;
	Node* temp = head;

	while (temp != nullptr) {
		if (temp->data == data) {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp = temp->next;
			delete temp->prev;
			count++;
		}
		else {
			temp = temp->next;
		}
	}
	return count;
}

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
	if (node != nullptr) {
		cout << node->data << endl;
		PrintForwardRecursive(node->next);
	}
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
	if (node != nullptr) {
		cout << node->data << endl;
		PrintReverseRecursive(node->prev);
	}
}
*/