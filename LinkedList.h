#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList {
public:
	struct Node {
		T data;
		Node* prev;
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
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	void FindAll(vector<Node*>& outData, const T& value) const;
	void InsertBefore(Node* node, const T& data);
	void InsertAfter(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);
	bool operator==(const LinkedList<T>& rhs);
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
	Node* head = list.head;

	for (unsigned int i = 0; i < list.nodeCount; i++) {
		AddTail(head->data);
		head = head->next;
	}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
	nodeCount = 0;
	Node* head = rhs.head;

	Clear();
	for (unsigned int i = 0; i < rhs.nodeCount; i++) {
		AddTail(head->data);
		head = head->next;
	}
	return *this;
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
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
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
	
	if (nodeCount == 0) {
		//cout << "addhead if empty list";
		head = newNode;
		tail = newNode;
		newNode->prev = nullptr;
		newNode->next = nullptr;
	}
	else {
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	nodeCount++;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data) {
	Node* newNode = new Node;
	newNode->data = data;

	if (nodeCount == 0) {
		//cout << "addhead if empty list";
		head = newNode;
		tail = newNode;
		tail->prev = nullptr;
		tail->next = nullptr;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	nodeCount++;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
	for (int i = ((int)(count) - 1); i >= 0; i--) {
		AddHead(data[i]);
		//cout << "added head " << nodeCount << endl;
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
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
	Node* temp = tail;

	while (temp != nullptr) {
		cout << temp->data << endl;
		temp = temp->prev;
	}
}

template <typename T>
void LinkedList<T>::Clear() {
	Node* temp = head;

	while (temp != nullptr) {
		temp = temp->next;
		delete head;
		head = temp;
	}

	nodeCount = 0;
	head = nullptr;
	tail = nullptr;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
	Node* findNode = head;

	if (index > nodeCount) {
		throw out_of_range("Index out of range");
	}
	else {
		unsigned int count = 0;

		while (count != index) {
			findNode = findNode->next;
			count++;
		}
	}
	return findNode;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
	Node* findNode = head;

	if (index > nodeCount) {
		throw out_of_range("Index out of range");
	}
	else {
		unsigned int count = 0;

		while (count != index) {
			findNode = findNode->next;
			count++;
		}
	}

	return findNode;
}

template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const {
	if (index >= nodeCount) {
		throw out_of_range("Index out of range");
	}

	return GetNode(index)->data;
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
	if (index >= nodeCount) {
		throw out_of_range("Index out of range");
	}

	return GetNode(index)->data;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
	Node* findNode = head;
	//T nodeData = findNode->data;

	while (findNode != nullptr) {
		if (findNode->data == data) {
			return findNode;
		}
		else {
			findNode = findNode->next;
		}
	}
	return nullptr;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
	Node* findNode = head;
	//T nodeData = findNode->data;

	while (findNode != nullptr) {
		if (findNode->data == data) {
			return findNode;
		}
		else {
			findNode = findNode->next;
		}
	}
	return nullptr;
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
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
	nodeCount++;
	Node* temp = new Node;

	if (node == GetNode(0)) {
		temp->next = node;
		temp->prev = nullptr;
		node->prev = temp;
	}
	else {
		temp->data = data;
		temp->prev = nullptr;
		temp->next = nullptr;

		temp->next = node;
		temp->prev = node->prev;
		node->prev->next = temp;
		node->prev = temp;
	}
}

template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
	nodeCount++;
	Node* temp = new Node;

	if (node == GetNode(nodeCount - 1)) {
		temp->next = node->next;
		temp->prev = node;
		node->next = temp;
	}
	else {
		temp->data = data;
		temp->prev = nullptr;
		temp->next = nullptr;

		temp->next = node->next;
		temp->prev = node;
		node->next->prev = temp;
		node->next = temp;
	}
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
	if (index > nodeCount || index < 0) {
		throw out_of_range("Index out of range");
	}
	else if (index == 0) {
		AddHead(data);
	}
	else if (index == nodeCount) {
		AddTail(data);
	}
	else {
		Node* temp = GetNode(index);
		InsertBefore(temp, data);
	}
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) {
	bool equal;
	Node* compare = head;

	if (nodeCount == rhs.NodeCount()) {
		while (compare != nullptr) {
			for (unsigned int i = 0; i < nodeCount; i++) {
				if (compare->data == rhs.GetNode(i)->data) {
					equal = true;
				}
				else {
					equal = false;
				}
				compare = compare->next;
			}
		}
	}
	else {
		equal = false;
	}
	return equal;
}

template <typename T>
bool LinkedList<T>::RemoveHead() {
	bool deleted;
	Node* temp = head;

	if (nodeCount == 1) {
		Clear();
	}
	else if (temp != nullptr) {
		temp->next->prev = nullptr;
		temp = temp->next;
		delete head;
		head = temp;
		deleted = true;
		nodeCount--;
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

	if (nodeCount == 1) {
		Clear();
	}
	else if (temp != nullptr) {
		temp->prev->next = nullptr;
		temp = temp->prev;
		delete tail;
		tail = temp;
		deleted = true;
		nodeCount--;
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
		if (nodeCount == 1) {
			Clear();
		}
		else if (deleteMe == head) {
			deleteMe->next->prev = nullptr;
			head = deleteMe->next;
			delete deleteMe;
			deleted = true;
			nodeCount--;
		}
		else if (deleteMe == tail) {
			deleteMe->prev->next = nullptr;
			tail = deleteMe->prev;
			delete deleteMe;
			deleted = true;
			nodeCount--;
		}
		else {
			deleteMe->prev->next = deleteMe->next;
			deleteMe->next->prev = deleteMe->prev;
			delete deleteMe;
			deleted = true;
			nodeCount--;
		}
	}
	return deleted;
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data) {
	int count = 0;
	Node* temp = head;
	Node* temp2 = temp;

	while (temp != nullptr) {
		if (temp->data == data) {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			temp2 = temp->next;
			delete temp;
			temp = temp2;
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