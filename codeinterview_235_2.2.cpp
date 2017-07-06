#include <iostream>

using namespace std;

const int listSize = 100;
int k = 0;

typedef struct node {
	int data;
	struct node *next;
}Node;


int recursiveSolution(Node* p , Node* first){
	if (p->next == first)
		return 1;
	int ret = recursiveSolution(p->next, first);
	if (ret < k - 1)
		return ret + 1;
	else if (ret > k - 1)
		return ret;
	else
		cout << p->data << endl;

}

// 뒤에서 k번째 원소
int main() {

	Node* first = (Node*)malloc(sizeof(Node));
	Node *front, *end;

	first->data = 0;
	front = end = first;

	for (int i = 1; i < listSize; i++) {
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->data = i;
		
		end->next = newnode;
		end = newnode;
		end->next = first;
	}

	cin >> k;

	Node* result = first;

	for (int i = 0; i < listSize - k; i++) {
		result = result->next;
	}

	cout << result->data << endl;

	recursiveSolution(front, first);

	return 0;
}