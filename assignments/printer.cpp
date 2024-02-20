#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string data) {
        this->data = data;
        this->next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void append(string data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->next = head;
        }
    }

    void remove(string data) {
        if (head == nullptr) {
            return;
        }
        if (head->data == data) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                temp->next = head->next;
                Node* to_delete = head;
                head = head->next;
                delete to_delete;
            }
        } else {
            Node* prev = head;
            Node* current = head->next;
            while (current != head && current->data != data) {
                prev = current;
                current = current->next;
            }
            if (current != head) {
                prev->next = current->next;
                delete current;
            } else {
                cout << "Node not found" << endl;
            }
        }
    }

    void printList() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << temp->data << endl; // Print last node's data
    }

    Node* getHead() {
        return head;
    }
};

void roundRobinScheduling(CircularLinkedList& users) {
    Node* currentUser =  users.getHead();
    if (currentUser == nullptr) {
        cout << "No users in the list." << endl;
        return;
    }
    int timeSlice = 3;
    while (true) {
        cout << "Executing printing task for user " << currentUser->data << endl;
        timeSlice -= 1;
        if (timeSlice == 0) {
            timeSlice = 3;  
            cout << "Time slice expired for user " << currentUser->data << endl;
            Node* nextUser = currentUser->next;
            users.remove(currentUser->data);
            if (users.getHead() == nullptr)
                break;
            currentUser = nextUser;
        } else {
            currentUser = currentUser->next;
        }
    }
}

int main() {
    CircularLinkedList usersList;
    usersList.append("User A");
    usersList.append("User B");
    usersList.append("User C");
    usersList.append("User D");

    roundRobinScheduling(usersList);

    return 0;
}