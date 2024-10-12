#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Node {
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_normal(Node *head) {
    Node *tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_reverse(Node *tail) {
    Node *tmp = tail;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void insert_tail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int size(Node *head) {
    Node *tmp = head;
    int cnt = 0;
    while (tmp != NULL) {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}

void delete_at_position(Node *head, int pos) {
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
    }
    Node *deleteNode = tmp->next;
    tmp->next = tmp->next->next;
    tmp->next->prev = tmp;
    delete deleteNode;
}

void delete_tail(Node *&head, Node *&tail) {
    Node *deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;
    if (tail == NULL) {
        head = NULL;
        return;
    }
    tail->next = NULL;
}

void delete_head(Node *&head, Node *&tail) {
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
    if (head == NULL) {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}

void insert_at_position(Node *head, int pos, int val) {
    Node *newNode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++) {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;    
    tmp->next = newNode;          
    newNode->next->prev = newNode;
    newNode->prev = tmp;          
}

void insert_head(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int choice, pos, val;

    while (true) {
        cout << "\n1. Insert at position\n2. Insert at head\n3. Insert at tail\n4. Delete node at position\n5. Delete head\n6. Delete tail\n7. Print linked list\n8. Print reverse\n9. Exit\n";
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
                insert_head(head, tail, val);
            } else if (pos == size(head)) {
                insert_tail(head, tail, val);
            } else {
                insert_at_position(head, pos, val);
            }
        } else if (choice == 2) {
            cout << "Enter value: ";
            cin >> val;
            insert_head(head, tail, val);
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
                delete_head(head, tail);
            } else {
                delete_at_position(head, pos);
            }
        } else if (choice == 5) {
            if (head == NULL) {
                cout << "List is empty." << endl;
            } else {
                delete_head(head, tail);
            }
        } else if (choice == 6) {
            if (tail == NULL) {
                cout << "List is empty." << endl;
            } else {
                delete_tail(head, tail);
            }
        } else if (choice == 7) {
            if (head == NULL) {
                cout << "List is empty." << endl;
            } else {
                print_normal(head);
            }
        } else if (choice == 8) {
            if (tail == NULL) {
                cout << "List is empty." << endl;
            } else {
                print_reverse(tail);
            }
        } else if (choice == 9) {
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }
    return 0;
}
