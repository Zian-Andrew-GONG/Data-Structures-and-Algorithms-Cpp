#pragma once
#include "list.hpp"

template <typename Object>
class Stack {
 public:
  Stack() : list() {}
  ~Stack() {}
  Stack(const Stack& rhs) { list = rhs.list; }
  Stack& operator=(const Stack& rhs) {
    Stack copy = rhs;
    std::swap(*this, copy);
    return *this;
  }
  Stack(Stack&& rhs) : list{rhs.list} {}
  Stack& operator=(Stack&& rhs) {
    std::swap(list, rhs.list);
    return *this;
  }

  void push(const Object& x) { list.push_back(x); }
  void push(Object&& x) { list.push_back(x); }
  void pop() { list.pop_back(); }
  Object& top() { list.back(); }
  const Object& top() const { list.back(); }

 private:
  List<Object> list;
};