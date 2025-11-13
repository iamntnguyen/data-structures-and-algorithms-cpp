#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class SinglyLinkedList {
 private:
  Node* head;

 public:
  SinglyLinkedList() { head = nullptr; }

  void insertAtHead(int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }

  void random_number(int n) {
    for (int i = 0; i < n; i++) {
      int num = rand() % 100 + 1;
      insertAtHead(num);
    }
  }

  bool search_in_linked_list(Node* node, int data) {
    Node* current = node;
    while (current != nullptr) {
      if (current->data == data) {
        return true;
      }
      current = current->next;
    }
    return false;
  }
  void print() {
    if (head == nullptr) {
      cout << "List is empty.\n";
      return;
    }

    Node* temp = head;
    while (temp != nullptr) {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << "\n";
  }
};

int main() {
  srand(time(0));

  SinglyLinkedList list;
  Node* head = nullptr;
  int n = 10;

  list.random_number(n);
  list.print();

  cout << "print search in linked list: ";
  list.search_in_linked_list(head, 25) ? cout << "found" : cout << "not found\n";
}
