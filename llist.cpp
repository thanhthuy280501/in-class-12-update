#include "llist.h"
#include <iostream>
using namespace std;

template <typename T>
void LList<T>::prev() {
    Link<T>* temp = head;
    if (fence == head) return;
    while (temp->next != fence) temp = temp->next;
    fence = temp;
    leftcnt--;
    rightcnt++;
}

template <typename T>
bool LList<T>::setPos(int pos) {
    if (pos < 0 || pos > leftcnt + rightcnt) return false;
    rightcnt = rightcnt + leftcnt - pos;
    leftcnt = pos;
    fence = head;
    for (int i = 0; i < pos; i++) fence = fence->next;
    return true;
}

template <typename T>
bool LList<T>::getValue(T& it) const {
    if (rightcnt == 0) return false;
    it = fence->next->element;
    return true;
}

template <typename T>
bool LList<T>::insert(const T& item) {
    fence->next = new Link<T>(item, fence->next);
    if (tail == fence) tail = fence->next;
    rightcnt++;
    return true;
}

template <typename T>
bool LList<T>::append(const T& item) {
    tail = tail->next = new Link<T>(item, nullptr);
    rightcnt++;
    return true;
}

template <typename T>
bool LList<T>::remove(T& it) {
    if (fence->next == nullptr) return false;
    it = fence->next->element;
    Link<T>* ltemp = fence->next;
    fence->next = ltemp->next;
    if (tail == ltemp) tail = fence;
    delete ltemp;
    rightcnt--;
    return true;
}

template <typename T>
void LList<T>::print() const {
    Link<T>* temp = head;
    cout << "< ";
    while (temp != fence) {
        cout << temp->next->element << " ";
        temp = temp->next;
    }
    cout << "| ";
    while (temp->next != nullptr) {
        cout << temp->next->element << " ";
        temp = temp->next;
    }
    cout << ">\n";
}
