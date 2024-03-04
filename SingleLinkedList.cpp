#include "SingleLinkedList.h"
#include <stdexcept>
using namespace std;

template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (head) {
        Node<Item_Type>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node<Item_Type>* newNode = new Node<Item_Type>{ item, head };
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    num_items++;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* newNode = new Node<Item_Type>{ item, nullptr };
    if (tail) {
        tail->next = newNode;
    }
    else {
        head = newNode;
    }
    tail = newNode;
    num_items++;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::pop_front() {
    if (head == nullptr) {
        return false;
    }
    Node<Item_Type>* temp = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    num_items--;
    return true;
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::pop_back() {
    if (head == nullptr) {
        return false;
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    }
    else {
        Node<Item_Type>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
    return true;
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (head) {
        return head->item;
    }
    throw out_of_range("List is empty.");
}

template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (tail) {
        return tail->item;
    }
    throw std::out_of_range("List is empty.");
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {
        push_back(item);
    }
    else if (index == 0) {
        push_front(item);
    }
    else {
        Node<Item_Type>* current = head;
        for (size_t i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node<Item_Type>* newNode = new Node<Item_Type>{ item, current->next };
        current->next = newNode;
        if (newNode->next == nullptr) {
            tail = newNode;
        }
        num_items++;
    }
}

template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        return pop_front();
    }
    Node<Item_Type>* current = head;
    for (size_t i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node<Item_Type>* nodeToRemove = current->next;
    current->next = nodeToRemove->next;
    if (nodeToRemove == tail) {
        tail = current;
    }
    delete nodeToRemove;
    num_items--;
    return true;
}

template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node<Item_Type>* current = head;
    size_t index = 0;
    while (current) {
        if (current->item == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items; // Return size of the list if item is not found
}
