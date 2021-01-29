#include <iostream>
using namespace std;

class Stack {
public:
	int *A;
	int top = -1;
	int asize;
	Stack() {}
	Stack(int n) { A = new int[n]; asize = n; }
	void Push(int x) {
		if (isFull()) { cout << "Error: no space on stack" << endl; return; }
		top++;
		A[top] = x;
	}
	bool isFull() {
		if (top >= asize - 1) return true;
		else return false;
		// this is the same as    return top>= asize-1 ? true : false; 
	}
	bool isEmpty() {
		if (top < 0) return true;
		else return false;
		// this is the same as    return top < 0 ? true : false; 
	}
	void Pop()
	{
		if (isEmpty()) {
			cout << "No element to pop" << endl; return;
		}
		top--;
	}
	void Print()
	{
		if (isEmpty()) cout << "Nothing to print" << endl;
		for (int i = top; i >= 0; i--)
			cout << A[i] << " ";
		cout << endl;
	}
};

class Node {
public:
	int data;
	Node * next;
	Node() {}
	Node(int x) { data = x; next = nullptr; }
};

class dynamicStack {
public:
	Node *top;
	dynamicStack() { top = nullptr; }
	
	void Push(int x) {
		Node * node = new Node(x);
		node->next = top;
		top = node;
	}
	void Pop() {
		Node *temp = top;
		if (!temp) { cout << "nothing to pop" << endl; }
		top = top->next;
		delete temp;
	}
	void Print() {
		Node *temp = top;
		if (!temp) { cout << "Nothing to print" << endl; return; }
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};
int main()
{
	// Stack * stack = new Stack(5);
	dynamicStack * stack = new dynamicStack();
	stack->Push(5);			stack->Print();	// 5
	stack->Push(10);		stack->Print();	// 10 5
	stack->Push(15);		stack->Print();	// 15 10 5
	stack->Push(20);		stack->Print();	// 20 15 10 5
	stack->Push(25);		stack->Print();	// 25 20 15 10 5
	stack->Push(30);		stack->Print(); // 30 25 20 15 10 5
	stack->Pop();			stack->Print(); // 20 15 10 5
	stack->Pop();			stack->Print(); // 15 10 5
	stack->Pop();			stack->Print(); // 10 5
	stack->Pop();			stack->Print(); // 5
	stack->Pop();			stack->Print(); // Nothing to print
	stack->Pop();
	stack->Pop();
	getchar();

}