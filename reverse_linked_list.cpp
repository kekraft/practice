#include <iostream>

using namespace std;

class Node {
  public:
  	int data;
  	Node* next;
};

class List {
  public:
  	List() { head = NULL;};
  	~List(){};
  	void addNode(int data);
  	void reverse();
  	void print();

  private:
  	Node* head;
};

// Adding a node to a linked list
void List::addNode(int data){
	Node* tmp = new Node();
	tmp->data = data;
	tmp->next = NULL;

	if (head == NULL){
		head = tmp;
		// cout << "Added head" << endl;
	} else {
		Node* cur = head;
		while (cur != NULL){
			if (cur->next == NULL){
				cur->next = tmp;	
				// cout << "input new node " << data << endl;
				break;
			}
			// cout << "Advancing" << endl;
			cur = cur->next; 
		}
		//cur->next = tmp;
		
	}
}

void List::print(){
	if (head == NULL){
		cout << "Empty list." << endl;
	} else {
		Node* cur = head;
		unsigned i = 1;
		while (cur != NULL){
			cout << cur->data;
			cur = cur->next;
			if (cur != NULL) cout << ", ";
			if (i % 5 == 0) cout << endl;
			i++;
		}
	    cout << endl;
	}
}

void List::reverse(){
	Node* n1 = head;
	Node* n2 = NULL;
	Node* n3 = NULL;

	// head shift, two pointer changes, update the 3 tmp nodes
	while (n1 != NULL){
		head = n1; // update head (move it down the list)
		cout << "Head is now: "; 
		(head == NULL) ? cout << "null" << endl : cout << head->data << endl;
		n2 = n1->next; 
		(n2 == NULL) ? cout << "N2 is now: null" << endl : cout << "N2 is now: " << n2->data << endl;
		n1->next = n3;
		(n1 == NULL || n1->next == NULL) ? cout << "N1s next ptr is now null" << endl : cout << "N1s next ptr is now " << n1->next->data << endl;
		n3 = n1;
		(n3 == NULL) ? cout << "N3 is now: null" << endl : cout << "N3 is now: " << n1->data << endl;
		n1 = n2;
		(n2 == NULL) ? cout << "N1 is now: null" << endl : cout << "N1 is now: " << n2->data << endl;
		cout << "\n\n"; 
	}
}

int main(){
	cout << "Creating linked list..." << endl;

	List* list = new List();
	for (unsigned i= 0; i < 100; i+=5){
		list->addNode(i);
		cout << "Added node " << i << endl;
	}

	cout << "Original list: " << endl;
	list->print();

	list->reverse();

	cout << "Reversed list: " << endl;
	list->print();

	delete list;
}