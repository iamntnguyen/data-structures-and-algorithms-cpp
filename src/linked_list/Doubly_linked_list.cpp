// doubly linked list DLL có 3 thành phần là dữ liệu, con trỏ đến nút tiếp theo
// và 1 con trỏ đến nút trước đó

// cấu trúc này cho phép duyệt theo 2 chiều thuận, nghịch của danh sách

// 1. data : dữ liệu
// 2. prev : nút trước đó
// 3. next : nút kế tiếp

#include <iostream>

class Node {
 public:
  int data;
  Node* prev;
  Node* next;

  Node(int value) {
    data = value;
    prev = nullptr;
    next = nullptr;
  }
};

class DoublyLinkedList {
 private:
  Node* head;
  Node* tail;

 public:
  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

  // Thêm nút vào cuối danh sách
  void append(int value) {
    Node* newNode = new Node(value);
    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
  }

  // In danh sách từ đầu đến cuối
  void displayForward() {
    Node* current = head;
    while (current) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }

  // In danh sách từ cuối đến đầu
  void displayBackward() {
    Node* current = tail;
    while (current) {
      std::cout << current->data << " ";
      current = current->prev;
    }
    std::cout << std::endl;
  }

  void deleteList() {
    Node* current = head;
    Node* nextNode;
    while (current) {
      nextNode = current->next;
      delete current;
      current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
  }

  void deleteListValue(int value) {
    Node* current = head;
    while (current) {
      if (current->data == value) {
        if (current->prev) {
          current->prev->next = current->next;
        } else {
          head = current->next;  // Update head if needed
        }
        if (current->next) {
          current->next->prev = current->prev;
        } else {
          tail = current->prev;  // Update tail if needed
        }
        delete current;
        return;
      }
      current = current->next;
    }
  }

  void insertAfter(Node* prevNode, int value) {
    if (!prevNode) return;

    Node* newNode = new Node(value);
    newNode->next = prevNode->next;
    newNode->prev = prevNode;

    if (prevNode->next) {
      prevNode->next->prev = newNode;
    } else {
      tail = newNode;
    }

    prevNode->next = newNode;
  }

  Node* getHead() { return head; }
  Node* getTail() { return tail; }
};

int main() {
  DoublyLinkedList dll;
  dll.append(10);
  dll.append(20);
  dll.append(30);

  std::cout << "Doubly Linked List (Forward): ";
  dll.displayForward();

  std::cout << "Doubly Linked List (Backward): ";
  dll.displayBackward();

  std::cout << "After inserting 25 after head:" << std::endl;
  Node* head = dll.getHead();
  dll.insertAfter(head, 25);
  dll.displayForward();  // hien thi lai danh sach

  std::cout << "After deleting value 20:" << std::endl;
  dll.deleteListValue(20);
  dll.displayForward();  // hien thi lai danh sach

  //   dll.deleteList();  // xoa toan bo danh sach
  return 0;
}