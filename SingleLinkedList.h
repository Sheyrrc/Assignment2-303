#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
using namespace std;

#include <stdexcept>

template <typename Item_Type>
struct Node {
    Item_Type item;
    Node* next;
};

template <typename Item_Type>
class Single_Linked_List {
private:
    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    size_t num_items;

public:
    Single_Linked_List();
    ~Single_Linked_List();

    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    bool pop_front();
    bool pop_back();
    Item_Type front() const;
    Item_Type back() const;
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
};

#endif // SINGLELINKEDLIST_H
