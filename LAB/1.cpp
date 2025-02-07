#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAtPosition(int data, int position) {
        if (position < 0) return;
        Node* newNode = new Node(data);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr || position < 0) return;
        Node* temp = head;
        if (position == 0) {
            head = head->next;
            delete temp;
            return;
        }
        Node* prev = nullptr;
        for (int i = 0; i < position && temp != nullptr; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        prev->next = temp->next;
        delete temp;
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList ll;
    int choice, value, position, n;

    cout << "Enter the number of elements to insert: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        cout << "Insert at (1: Head, 2: Tail, 3: Position): ";
        cin >> choice;

        if (choice == 1) {
            ll.insertAtHead(value);
        } else if (choice == 2) {
            ll.insertAtTail(value);
        } else if (choice == 3) {
            cout << "Enter position (0 is first as it is head): ";
            cin >> position;
            ll.insertAtPosition(value, position);
        } else {
            cout << "Invalid choice! Skipping...\n";
        }
    }

    cout << "Final Linked List: ";
    ll.printList();

    cout << "Do you want to delete a node? (1: Yes, 0: No): ";
    cin >> choice;
    if (choice == 1) {
        cout << "Enter position to delete: ";
        cin >> position;
        ll.deleteAtPosition(position);
        cout << "Linked List after deletion: ";
        ll.printList();
    }

    return 0;
}