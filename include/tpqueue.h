// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
  struct Node {
    T d;
    Node* n;
    explicit Node(const T& v) {
      d = v;
      n = nullptr;
    }
  };
  Node* h;

 public:
  TPQueue() {
    h = nullptr;
  }
  ~TPQueue() {
    while (h != nullptr) {
      Node* t = h;
      h = h->n;
      delete t;
    }
  }
  void push(const T& v) {
    Node* nn = new Node(v);
    if (h == nullptr) {
      h = nn;
      return;
    }
    if (v.prior > h->d.prior) {
      nn->n = h;
      h = nn;
      return;
    }
    Node* c = h;
    while (c->n != nullptr && c->n->d.prior >= v.prior) {
      c = c->n;
    }
    nn->n = c->n;
    c->n = nn;
  }
  T pop() {
    Node* t = h;
    T v = h->d;
    h = h->n;
    delete t;
    return v;
  }
};
struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
