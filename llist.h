#ifndef LLIST_H
#define LLIST_H
#include "link.h"

template <typename T>
class LList {
  private:
    Link<T>* head;    // Pointer to list head
    Link<T>* tail;    // Pointer to last element
    Link<T>* fence;   // Last element on left side
    int leftcnt;      // Size of left partition
    int rightcnt;     // Size of right partition

    void init() {
        fence = tail = head = new Link<T>();
        leftcnt = rightcnt = 0;
    }

    void removeall() {
        while (head != nullptr) {
            fence = head;
            head = head->next;
            delete fence;
        }
    }

  public:
    LList() { init(); }
    ~LList() { removeall(); }

    void clear() { removeall(); init(); }
    void setStart() { fence = head; rightcnt += leftcnt; leftcnt = 0; }
    void setEnd() { fence = tail; leftcnt += rightcnt; rightcnt = 0; }
    void next() {
        if (fence != tail) {
            fence = fence->next;
            rightcnt--;
            leftcnt++;
        }
    }
    void prev();
    int leftLength() const { return leftcnt; }
    int rightLength() const { return rightcnt; }
    bool setPos(int pos);
    bool getValue(T& it) const;
    bool insert(const T& item);
    bool append(const T& item);
    bool remove(T& it);
    void print() const;
};

#include "llist.cpp"
#endif
