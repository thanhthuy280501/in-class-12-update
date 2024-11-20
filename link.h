#ifndef LINK_H
#define LINK_H

template <typename T>
class Link {
  public:
    friend class LList<T>;  // Allow LList access

    Link(const T& elemval, Link<T>* nextval = nullptr)
        : element(elemval), next(nextval) {}

    Link(Link<T>* nextval = nullptr) : next(nextval) {}

  private:
    T element;        // Element value
    Link<T>* next;    // Pointer to the next node
};

#endif
