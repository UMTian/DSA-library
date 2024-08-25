#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class array {
private:
    int capacity;
    int pointer;
public:
    int* arr; 
    array(int size) {
        capacity = size;
        arr = new int[capacity];
        pointer = 0;  
    }

    // Function to insert element at the end of an array
    void insert_at_end(int value) {
        if (pointer >= capacity) {
            cout << "Array is at full capacity! Unable to insert element." << endl;
            return;
        }
        arr[pointer++] = value; // Increment top after assigning value
        cout << value << " inserted at the end of the array." << endl;
    }

    // Function to search for an element in an array
    int search_element(int target) {
        for (int i = 0; i < pointer; ++i) {
            if (arr[i] == target) {
                cout << target << " found at position " << i << " in the array." << endl;
                return i;
            }
        }
        cout << target << " not found in the array." << endl;
        return -1;
    }

    // Function to find the maximum value in an array
    int find_max() {
        if (pointer == 0) {
            cout << "Array is empty." << endl;
            return -1;
        }

        int max_val = arr[0];
        for (int i = 1; i < pointer; ++i) {
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }

        cout << "Maximum value in the array: " << max_val << endl;
        return max_val;
    }

    // Function to find the minimum value in an array
    int find_min() {
        if (pointer == -1) {
            cout << "Array is empty." << endl;
            return -1;
        }

        int min_val = arr[0];
        for (int i = 1; i < pointer; ++i) {
            if (arr[i] < min_val) {
                min_val = arr[i];
            }
        }

        cout << "Minimum value in the array: " << min_val << endl;
        return min_val;
    }

	int binary_search(int target) {
        int low = 0;
        int high = pointer - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                cout << target << " found at position " << mid << " in the array (using binary search)." << endl;
                return mid;
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << target << " not found in the array (using binary search)." << endl;
        return -1;
    }

    // Function to perform insertion sort on an array
    void insertion_sort() {
        for (int i = 1; i < pointer; ++i) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }

            arr[j + 1] = key;
        }

        cout << "Array sorted using insertion sort." << endl;
    }

    // Function to perform selection sort on an array
    void selection_sort() {
        for (int i = 0; i < pointer - 1; ++i) {
            int min_index = i;

            for (int j = i + 1; j < pointer; ++j) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }

            // Swap the found minimum element with the first element
            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;
        }

        cout << "Array sorted using selection sort." << endl;
    }
	bool is_sorted() {
        for (int i = 0; i < pointer - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                cout << "Array is not sorted." << endl;
                return false;
            }
        }

        cout << "Array is sorted in non-decreasing order." << endl;
        return true;
    }
    void display() {
    cout << "The array goes as: \n";
    for (int i = 0; i < pointer; i++) {
        cout << "[" << arr[i] << "]";
    }
    cout << endl;
}

};
class Node {
	public:
		int data;
	    Node* next;
	    Node(int value) {
	        data = value;
	        next = NULL;
	    }
};
class DoublyNode {
	public:
	    int data;
	    DoublyNode* prev;
	    DoublyNode* next;
	    DoublyNode(int value){
			data = value;
			prev = NULL;
			next = NULL;
		}
};
class doubly_linked_list {
	private:
	    DoublyNode* head;
	    DoublyNode* tail;
	    int capacity;
	public:
	    doubly_linked_list(int cap) {
	        head = NULL;
	        tail = NULL;
	        capacity = cap;
	    }
	    void insert_at_end(int data) {
	        if (count() < capacity) {
	            DoublyNode* newNode = new DoublyNode(data);
	            if (isEmpty()) {
	                head = tail = newNode;
	            } else {
	                tail->next = newNode;
	                newNode->prev = tail;
	                tail = newNode;
	            }
	        } else {
	            cout << "Doubly Linked List is at full capacity! Unable to add element.\n";
	        }
	    }
	    bool isEmpty() {
	        return head == NULL;
	    }
	    int count() {
	        DoublyNode* temp = head;
	        int count = 0;
	        while (temp != NULL) {
	            count++;
	            temp = temp->next;
	        }
	        return count;
	    }
	    void display_forward() {
	        DoublyNode* temp = head;
	        cout << "Doubly Linked List (Forward): ";
	        while (temp != NULL) {
	            cout << "[" << temp->data << "] ";
	            temp = temp->next;
	        }
	        cout << endl;
	    }
	    void display_backward() {
	        DoublyNode* temp = tail;
	        cout << "Doubly Linked List (Backward): ";
	        while (temp != NULL) {
	            cout << "[" << temp->data << "] ";
	            temp = temp->prev;
	        }
	        cout << endl;
	    }
};
class circular_linked_list {
	private:
	    Node* head;
	    Node* tail;
	    int capacity;
	public:
	    circular_linked_list(int cap) {
	        head = NULL;
	        tail = NULL;
	        capacity = cap;
	    }
	    void insert_at_end(int data) {
	        if (count() < capacity) {
	            Node* newNode = new Node(data);
	            if (isEmpty()) {
	                head = tail = newNode;
	                newNode->next = head;
	            } else {
	                tail->next = newNode;
	                tail = newNode;
	                newNode->next = head;
	            }
	        } else {
	            cout << "Circular Linked List is at full capacity! Unable to add element.\n";
	        }
	    }
	    bool isEmpty() {
	        return head == NULL;
	    }
	    int count() {
	        Node* temp = head;
	        int count = 0;
	        while (temp != NULL) {
	            count++;
	            temp = temp->next;
	        }
	        return count;
	    }
	    void display() {
	        Node* temp = head;
	        cout << "Circular Linked List: ";
	        if (!isEmpty()) {
	            do {
	                cout << "[" << temp->data << "] ";
	                temp = temp->next;
	            } while (temp != head);
	        }
	        delete temp;
	        cout << endl;
	    }
};
class singly_linked_list {
	private:
	    Node* head;
	    int capacity;
	
	public:
	    singly_linked_list(int cap) {
	        head = NULL;
	        capacity = cap;
	    }
	    void insert_at_end(int data) {
	        if (count() < capacity) {
	            Node* newNode = new Node(data);
	            if (isEmpty()) {
	                head = newNode;
	            } else {
	                Node* temp = head;
	                while (temp->next != NULL) {
	                    temp = temp->next;
	                }
	                temp->next = newNode;
	            }
	        } else {
	            cout << "Singly Linked List is at full capacity! Unable to add element.\n";
	        }
	    }
	
	    bool isEmpty() {
	        return head == NULL;
	    }
	
	    int count() {
	        Node* temp = head;
	        int count = 0;
	        while (temp != NULL) {
	            count++;
	            temp = temp->next;
	        }
	        return count;
	    }
	
	    void display() {
	        Node* temp = head;
	        cout << "Singly Linked List: ";
	        while (temp != NULL) {
	            cout << "[" << temp->data << "] ";
	            temp = temp->next;
	        }
	        cout << endl;
	    }
};
class array_stack {
	private:
	    int* stack;
	    int top;
	    int capacity;
	public:
	    array_stack(int size) {
	    	top = -1;
	    	capacity = size;
	        stack = new int[capacity];
	    }
	    ~array_stack() {
	        delete[] stack;
	    }
	    void push(int data) {
	        if (isFull()) {
	            cout << "Stack is full!" << endl;
	        } else {
	            top++;
	            stack[top] = data;
	            cout << data << " pushed to stack!" << endl;
	        }
	    }
	    int pop() {
	        if (isEmpty()) {
	            cout << "Stack is empty!" << endl;
	            return 0;
	        } else {
	            int popped_value = stack[top];
	            top--;
	            return popped_value;
	        }
	    }
	    bool isEmpty() {
	        return top == -1;
	        
	    }
	    bool isFull() {
	        return top == capacity - 1;
	    }
	    int getTop() {
	        if (isEmpty()) {
	            cout << "Stack is empty!" << endl;
	            return 0;
	        } else {
	            return stack[top];
	        }
	    }
};
class array_queue {
	private:
	    int* queue;
	    int front;
	    int rear;
	    int capacity;
	public:
	    array_queue(int size) {
	    	front = -1;
	    	rear = -1;
	    	capacity = size;
	        queue = new int[capacity];
	    }
	    ~array_queue() {
	        delete[] queue;
	    }
	    void enqueue(int data) {
	        if (isFull()) {
	            cout << "Queue is full!" << endl;
	        } else {
	            if (isEmpty()) {
	                front = rear = 0;
	            } else {
	                rear = (rear + 1) % capacity;
	            }
	            queue[rear] = data;
	            cout << data << " enqueued to queue!" << endl;
	        }
	    }
	    int dequeue() {
	        if (isEmpty()) {
	            cout << "Queue is empty!" << endl;
	            return 0;
	        } else {
	            int dequeued_value = queue[front];
	            if (front == rear) {
	                front = rear = -1;
	            } else {
	                front = (front + 1) % capacity;
	            }
	            return dequeued_value;
	        }
	    }
	    bool isEmpty() {
	        return front == -1 && rear == -1;
	    }
	    bool isFull() {
	        return (rear + 1) % capacity == front;
	    }
	    int getFront() {
	        if (isEmpty()) {
	            cout << "Queue is empty!" << endl;
	            return 0;
	        } else {
	            return queue[front];
	        }
	    }
};
class list_stack{
	private:
	    Node* top;
	    int capacity;
	    int counter;
	public:
	    list_stack(int cap) {
	        top = NULL;
	        capacity = cap;
	        counter = 0;
	    }
	    void push(int data) {
	        if (isFull()) {
	            cout << "Stack is full!" << endl;
	        } else {
	            Node* new_Node = new Node(data);
	            new_Node->next = top;
	            top = new_Node;
	            cout << data << " pushed to stack!" << endl;
	            counter++;
	        }
	    }
	    int pop() {
	        if (isEmpty()) {
	            cout << "Stack is empty!" << endl;
	            return 0;
	        } else {
	            int popped_value = top->data;
	            Node* temp = top;
	            top = top->next;
	            delete temp;
	            counter--;
	            return popped_value;
	        }
	    }
	    bool isEmpty() {
	        return top == NULL;
	    }
	    bool isFull() {
	        return counter == capacity;
	    }
	    int getTop() {
	        if (isEmpty()) {
	            cout << "Stack is empty!" << endl;
	            return 0;
	        } else {
	            return top->data;
	        }
	    }
	    void display() {
	    	Node* temp = top;
	    	cout << "The stack goes as: \n";
	    	while (temp!=NULL){
	    		cout << "[" << temp->data << "]";
	    		temp = temp->next;
			}
			delete temp;
			cout << endl;
		}
};
class list_queue {
	private:
	    Node* front;
	    Node* rear;
	    int capacity;
	public:
	    list_queue(int size){
	    	front = NULL;
	    	rear = NULL;
	    	capacity = size;
		}
		int count(){
			Node* temp = front;
			int count = 0;
			while (temp!=NULL){
				count++;
				temp = temp->next;
			}
			delete temp;
			return count;
		}
	    void enqueue(int data) {
	        Node* newNode = new Node(data);
		    if (!isFull()){
				if (isEmpty()) {
		            front = rear = newNode;
		        } else {
		            rear->next = newNode;
		            rear = newNode;
		        }
		    } else {
		    	cout << "Queue if full! Unable to add element!\n";
			}
	    }
	    void dequeue() {
	        if (!isEmpty()) {
	            Node* temp = front;
	            front = front->next;
	            delete temp;
	        } else {
	            cout << "Queue is empty! Unable to remove element.\n";
	        }
	    }
	    bool isEmpty(){
	        return front == NULL;
	    }
	    bool isFull(){
	    	return count() == capacity;
		}
	    int getFront() {
	        if (!isEmpty()) {
	            return front->data;
	        } else {
	            cout << "Queue is empty.\n";
	            return -1;
	        }
	    }
	    void display() {
	        Node* temp = front;
	        cout << "The queue goes as: \n";
	        while (temp != NULL) {
	            cout << "[" << temp->data << "]";
	            temp = temp->next;
	        }
	        cout << endl;
	        delete temp;
	    }
	    void reverse() {
		    Node* prev = NULL;
		    Node* current = front;
		    Node* next = NULL;
		    while (current != NULL) {
		        next = current->next;
		        current->next = prev;
		        prev = current;
		        current = next;
		    }
		    rear = front;
		    front = prev;
		}
};
class circular_queue {
	private:
	    Node* front;
	    Node* rear;
	    int capacity;
	public:
	    circular_queue(int size) {
	        front = NULL;
	        rear = NULL;
	        capacity = size;
	    }
	    ~circular_queue() {
	        Node* temp = front;
	        while (temp != NULL) {
	            Node* nextNode = temp->next;
	            delete temp;
	            temp = nextNode;
	        }
	    }
	    void enqueue(int data) {
	        Node* newNode = new Node(data);
	        if (!isFull()) {
	            if (isEmpty()) {
	                front = rear = newNode;
	                rear->next = front;
	            } else {
	                rear->next = newNode;
	                rear = newNode;
	                rear->next = front;
	            }
	            cout << data << " enqueued to circular queue!" << endl;
	        } else {
	            cout << "Circular Queue is full! Unable to add element!\n";
	        }
	    }
	    void dequeue() {
	        if (!isEmpty()) {
	            Node* temp = front;
	            front = front->next;
	            delete temp;
	        } else {
	            cout << "Circular Queue is empty! Unable to remove element.\n";
	        }
	    }
	    bool isEmpty() {
	        return front == NULL;
	    }
	    bool isFull() {
	        return count() == capacity;
	    }
	    int getFront() {
	        if (!isEmpty()) {
	            return front->data;
	        } else {
	            cout << "Circular Queue is empty.\n";
	            return -1;
	        }
	    }
	    void display() {
	        Node* temp = front;
	        cout << "Circular Queue: ";
	        if (!isEmpty()) {
	            do {
	                cout << "[" << temp->data << "] ";
	                temp = temp->next;
	            } while (temp != front);
	        }
	        cout << endl;
	    }
	    int count() {
	        Node* temp = front;
	        int count = 0;
	        while (temp != NULL) {
	            count++;
	            temp = temp->next;
	        }
	        return count;
	    }
};
class priority_queue {
	private:
	    Node* front;
	    Node* rear;
	    int capacity;
	public:
	    priority_queue(int cap) {
	        front = NULL;
	        rear = NULL;
	        capacity = cap;
	    }
	    ~priority_queue() {
	        Node* temp = front;
	        while (temp != NULL) {
	            Node* nextNode = temp->next;
	            delete temp;
	            temp = nextNode;
	        }
	    }
	    void enqueue(int data, int priority) {
	        if (isFull()) {
	            cout << "Priority Queue is full! Unable to enqueue element.\n";
	            return;
	        }
	        Node* newNode = new Node(data);
	        newNode->data = data;
	        newNode->next = NULL;
	        if (isEmpty() || priority > front->data) {
	            newNode->next = front;
	            front = newNode;
	            if (rear == NULL) {
	                rear = front;
	            }
	        } else {
	            Node* current = front;
	            while (current->next != NULL && priority <= current->next->data) {
	                current = current->next;
	            }
	            newNode->next = current->next;
	            current->next = newNode;
	        }
	        cout << data << " enqueued with priority " << priority << " to priority queue!" << endl;
	    }
	    void dequeue() {
	        if (!isEmpty()) {
	            Node* temp = front;
	            front = front->next;
	            delete temp;
	            if (front == NULL) {
	                rear = NULL;
	            }
	        } else {
	            cout << "Priority Queue is empty! Unable to remove element.\n";
	        }
	    }
	    bool isEmpty() {
	        return front == NULL;
	    }
	    bool isFull() {
	        return count() == capacity;
	    }
	    int getFront() {
	        if (!isEmpty()) {
	            return front->data;
	        } else {
	            cout << "Priority Queue is empty.\n";
	            return -1;
	        }
	    }
	    void display() {
	        Node* temp = front;
	        cout << "Priority Queue: ";
	        while (temp != NULL) {
	            cout << "[" << temp->data << "] ";
	            temp = temp->next;
	        }
	        cout << endl;
	    }
	    int count() {
	        Node* temp = front;
	        int count = 0;
	        while (temp != NULL) {
	            count++;
	            temp = temp->next;
	        }
	        return count;
	    }
};
