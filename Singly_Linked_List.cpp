#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pob pop_back

class Node {
public:
    ll data;
    Node *next;

    Node(ll data) {
        this->data = data;
        next = NULL;
    }
};

void print_linked_list(Node *head) {
    Node *tmp = head;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int size(Node *head) {
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

void delete_node(Node *head, int pos) {
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    delete deleteNode;
}

void delete_head(Node *&head) {
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void insert(Node *head, int pos, int val) {
    Node *newNode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void insert_head(Node *&head, int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_tail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;

    int choice, pos, val;
    while (true) {
        cout << "\n1. Insert at position\n2. Insert at head\n3. Insert at tail\n4. Delete node at position\n5. Delete head\n6. Print linked list\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter position and value: ";
            cin >> pos >> val;
            if (head == NULL && pos != 0) {
                cout << "Invalid Index. List is empty; you can only insert at position 0." << endl;
            } else if (pos > size(head)) {
                cout << "Invalid Index" << endl;
            } else if (pos == 0) {
                insert_head(head, val);
                if (tail == NULL) tail = head;
            } else if (pos == size(head)) {
                insert_tail(head, tail, val);
            } else {
                insert(head, pos, val);
            }
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            insert_head(head, val);
            if (tail == NULL) tail = head;
        } else if (choice == 3) {
            cout << "Enter value: ";
            cin >> val;
            insert_tail(head, tail, val);
        } else if (choice == 4) {
            cout << "Enter position: ";
            cin >> pos;
            if (head == NULL) {
                cout << "List is empty." << endl;
            } else if (pos < 0 || pos >= size(head)) {
                cout << "Invalid Index" << endl;
            } else if (pos == 0) {
                delete_head(head);
                if (head == NULL) tail = NULL;
            } else {
                delete_node(head, pos);
            }
        } else if (choice == 5) {
            if (head == NULL) {
                cout << "List is empty." << endl;
            } else {
                delete_head(head);
                if (head == NULL) tail = NULL;
            }
        } else if (choice == 6) {
            if (head == NULL) {
                cout << "List is empty." << endl;
            } else {
                print_linked_list(head);
                cout << "Tail-> " << tail->data << endl;
            }
        } else if (choice == 7) {
            return 0;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
